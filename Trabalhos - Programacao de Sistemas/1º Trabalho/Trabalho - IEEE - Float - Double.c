#include <stdio.h>
#include <stdlib.h>

#define Tdouble 0
#define Tfloat 1

typedef struct{
    unsigned long long int f:52;
    unsigned long long int E:11;
    unsigned long long int s:1;
} dIEEE;

typedef struct {
    unsigned long int f:23;
    unsigned long int E:8;
    unsigned long int s:1;
}fIEEE;

typedef struct{
    int type;
    void *data;
}real;

real novo_real(double x, int t){
    real r;
    r.type = t;
    if(t==Tdouble){
        double *pt_data;
        pt_data = (double *) malloc(sizeof(double));
        *pt_data = x;
        r.data = (void *) pt_data;
    }else if(t==Tfloat){
        float *pt_data;
        pt_data = (float *) malloc(sizeof(float));
        *pt_data = (float)x;
        r.data = (void *) pt_data;
    }
    return r;
};

void exclui_real(real *x){
    if(x->data!=NULL){
        free(x->data);
        x->data=NULL;
    }
}

real sqrtNR(real A){
/*
A função sqrtNR recebe um valor real e retorna o valor real da raiz quadrada de A calculado 
com o método de Newton Raphson. 
A função deve analisar se o valor A é representado como Tfloat ou Tdouble.
    - Caso o tipo de A seja Tfloat, o retorno deverá ser do tipo Tfloat
    - Caso o tipo de A seja Tdouble, o retorno deverá ser do tipo Tdouble
Se o tipo não for Tdouble nem Tfloat, o comportamento é indefinido (ou seja, não se sabe o que será retornado) 
*/
    int contador_iteracoes = 0;
    
	// Constantes para raiz quadrada de 2 com precisão dupla e simples
    const double sqrt_double = 1.4142135623730950488016887;
    const float sqrt_float = (float) sqrt_double;

    if (A.type == Tfloat) { // Verifica se o tipo armazenado em A é float
        float valor_original = *((float *) A.data); // Recupera o valor float armazenado

        if (valor_original == 0.0f || valor_original == 1.0f) { // Casos em que a raiz é o próprio número
            return novo_real(valor_original, A.type);
        }
        
		// A union é usada para manipular diretamente os bits do float.
		// O objetivo é obter uma boa estimativa inicial da raiz quadrada, que depois será refinada com o método de Newton-Raphson.
        union ValorFloat{
            float x;
            fIEEE bits;
        }; 
        
        union ValorFloat x0, x1;
        
        x0.x = valor_original;
        int impar = !(x0.bits.E & 1); 
        x0.bits.E = (x0.bits.E >> 1) + 0x3F;
        x0.bits.f >>= 1;

        if (impar) {
            x0.x *= sqrt_float;
        }
		
		printf("\nEstimativa Inicial - Float: %.15f", x0.x);
		
        x1.x = x0.x;
        
		// Iteração usando o método de Newton-Raphson para refinamento.
        do {
        	x0.x = x1.x;
            x1.x = (x1.x + valor_original / x1.x);
            x1.bits.E--;
            contador_iteracoes++;
        } while (x0.x != x1.x); // Repete até convergir
        
		printf("\nQuantidade de iteracoes - Metodo de Newton-Raphson: %d\n", contador_iteracoes);
    	return novo_real(x1.x, A.type);
    	
    	
    } else if (A.type == Tdouble) { // Verifica se o tipo armazenado em A é double
        double valor_original = *((double *) A.data); // Recupera o valor double armazenado

        if (valor_original == 0.0 || valor_original == 1.0) { // Casos em que a raiz é o próprio número
            return novo_real(valor_original, A.type);
        }

		// A union é usada para manipular diretamente os bits do double.
		// O objetivo é obter uma boa estimativa inicial da raiz quadrada, que depois será refinada com o método de Newton-Raphson.
        union ValorDouble{
            double x;
            dIEEE bits;
        }; 
        
        union ValorDouble x0, x1;
		
		x0.x = valor_original;
        int impar = !(x0.bits.E & 1);
        x0.bits.E = (x0.bits.E >> 1) + 0x1FF;
        x0.bits.f >>= 1;

        if (impar) {
            x0.x *= sqrt_double;
        }
        
		printf("\nEstimativa Inicial - Double: %.15lf", x0.x);
		
		x1.x = x0.x;

		// Iteração usando o método de Newton-Raphson para refinamento.
        do {
        	x0.x = x1.x;
            x1.x = (x1.x + valor_original / x1.x);
            x1.bits.E--;
            contador_iteracoes++;
        } while (x0.x != x1.x); // Repete até convergir
        
    	printf("\nQuantidade de iteracoes - Metodo de Newton-Raphson: %d\n", contador_iteracoes);
    	return novo_real(x1.x, A.type);
    	
    	
    } else {
    	printf("\nAviso: tipo desconhecido em sqrtNR\n");
    	return novo_real(0.0, Tdouble); // retorna 0.0 com tipo Tdouble (Comportamento indefinido)
	}
}

void change_to_Tdouble(real *A){
/*
A função change_to_Tdouble deve converter o tipo de dado do valor real para Tdouble;
Caso o o tipo de A não seja Tfloat, nada deve ser feito.
*/
	if (A->type == Tfloat) { // Se o tipo de A não for Tfloat, não faz nada
		float valor = *((float*) A->data); // Salva o valor do tipo Tfloat
		double valor_double = (double) valor; // Converte para double
		double *novo_ponteiro_double = (double *) malloc(sizeof(double)); // Aloca memória para um double
		*novo_ponteiro_double = valor_double; // Referencia o valor pelo ponteiro
		free(A->data); // Libera a memória alocada anteriomente
		A->data = novo_ponteiro_double; // Salva o novo ponteiro em A
		A->type = Tdouble;	// Salva o real A com o tipo Tdouble
	}
}

void change_to_Tfloat(real *A){
/*
A função change_to_Tfloat deve converter o tipo de dado do valor real para Tfloat;
Caso o tipo de A não seja Tdouble, nada deve ser feito.
*/
   	if (A->type == Tdouble) { // Se o tipo de A não for Tdouble, não faz nada
	    double valor = *((double*) A->data); // Salva o valor do tipo Tdouble
	    float valor_float = (float) valor; // Converte para float
	    float *novo_ponteiro_float = (float *) malloc(sizeof(float)); // Aloca memória para um float
	    *novo_ponteiro_float = valor_float; // Referencia o valor pelo ponteiro
	    free(A->data); // Libera a memória alocada anteriormente
	    A->data = novo_ponteiro_float; // Salva o novo ponteiro em A
	    A->type = Tfloat; // Salva o real A com o tipo Tfloat
    }
}

double real_to_double(real A){
/*
A função real_to_double retorna um valor double a partir de um real;
*/
    if(A.type == Tfloat){
        change_to_Tdouble(&A);
    }
    return * ((double*) A.data);
}


float real_to_float(real A){
/*
A função real_to_float retorna um valor float a partir de um real;
*/
    if(A.type == Tdouble){
        change_to_Tfloat(&A);
    }
    return * ((float*) A.data);
}


int main() {
	
    // TESTE 1: sqrtNR com valor 13.125
    
    double x = 13.125;

    real r1, r2;
    r1 = novo_real(x, Tfloat);
    r2 = novo_real(x, Tdouble);
    
    fIEEE *as_float;
    dIEEE *as_double;
    
    printf("\n===== TESTE 1: sqrt(13.125) =====\n");
    
    real sqrtR1 = sqrtNR(r1); // essa chamada da função deve retornar um valor real com type == Tfloat, pois r1.type == Tfloat 
    float sqrt_xF = real_to_float(sqrtR1);
    printf("Float sqrt(%lf):%.15f\n", x, sqrt_xF);
    
    real sqrtR2 = sqrtNR(r2); // essa chamada da função deve retornar um valor real com type == Tdouble, pois r2.type == Tdouble
    double sqrt_xD = real_to_double(sqrtR2);
    printf("Double sqrt(%lf):%.15lf\n", x, sqrt_xD);
 
    as_float = (fIEEE*)r1.data;
    as_double = (dIEEE*)r2.data;
    
    printf("\nIEEE 754 - Float 13.125 -- Sinal: %x  Mantissa: %x  Expoente: %x\n", as_float->s, as_float->f, as_float->E);
    printf("IEEE 754 - Double 13.125 -- Sinal: %llx  Mantissa: %llx  Expoente: %llx\n", as_double->s, as_double->f, as_double->E);
    
    exclui_real(&r1);
    exclui_real(&r2);
	exclui_real(&sqrtR1);
	exclui_real(&sqrtR2);
	

    // TESTE 2: real_to_float com real Tdouble
    
	printf("\n===== TESTE 2: Conversao de double para float =====\n");
	
    double valor_double = 42.123456789;
    real r3 = novo_real(valor_double, Tdouble);
    float convertido_para_float = real_to_float(r3);
    
    printf("\nOriginal (double): %.15lf\n", valor_double);
    printf("Convertido (float): %.15f\n", convertido_para_float);
	
	
    // TESTE 3: real_to_double com real Tfloat
	
	printf("\n===== TESTE 3: Conversao de float para double =====\n");
	
    float valor_float = 42.123456f;
    real r4 = novo_real(valor_float, Tfloat);
    double convertido_para_double = real_to_double(r4);
    
    printf("\nOriginal (float): %.15f\n", valor_float);
    printf("Convertido (double): %.15lf\n", convertido_para_double);


    // TESTE 4: sqrtNR com valor 125.0
    
    double y = 125.0;
	
	real r5, r6;
    r5 = novo_real(y, Tfloat);
    r6 = novo_real(y, Tdouble);
	
	fIEEE *as_float2;
    dIEEE *as_double2;
    
    printf("\n===== TESTE 4: sqrt(125.0) =====\n");
    
    real sqrtR5 = sqrtNR(r5);
    float raizF = real_to_float(sqrtR5);
    printf("Float sqrt(%lf): %.15f\n", y, raizF);
    
	real sqrtR6 = sqrtNR(r6);
    double raizD = real_to_double(sqrtR6);
    printf("Double sqrt(%lf): %.15lf\n", y, raizD);
    
    as_float2 = (fIEEE*)r5.data;
    as_double2 = (dIEEE*)r6.data;
    
    printf("\nIEEE 754 - Float 125.0 -- Sinal: %x  Mantissa: %x  Expoente: %x\n", as_float2->s, as_float2->f, as_float2->E);
    printf("IEEE 754 - Double 125.0 -- Sinal: %llx  Mantissa: %llx  Expoente: %llx\n",as_double2->s, as_double2->f, as_double2->E);
    
    exclui_real(&r5);
    exclui_real(&r6);
    exclui_real(&sqrtR5);
    exclui_real(&sqrtR6);
	
    return 0;
}
