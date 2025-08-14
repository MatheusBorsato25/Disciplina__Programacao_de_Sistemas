#include "include\tprotulo.h"
#include "include\fila.h"
#include <stdio.h>
#include <string.h>  // para usar a fun��o strcmp() que compara duas strings
#include <stdlib.h>  // para usar a fun��o exit() que interrompe (aborta) a execu��o do programa.

typedef unsigned char Tpixel; // tipo Tpixel para valores em [0, 255]

typedef struct TPpgm { /// descritor para imagens tipo PGM
    char tipo[3]; /// "P1", "P2", "P3"
    int w;     // largura da imagem em pixels (TC - Total de pixels em cada coluna da imagem)
    int h;     // altura da imagem em pixel   (TL - Total de pixels em cada linha da imagem )
    int max;   // valor de brilho m�ximo registrado na imagem (use 255 sempre)
    int pixlen;   // total de pixels (em todas as bandas) da imagem
    Tpixel *pix; // ponteiro para o reticulado (matriz) da imagem alocada como um vetor.
} TPpgm;

// Inicializa todas as filas da hierárquica
void InicializaFilaHierarquica(struct fila_hierarquica *fh) {
	fh->filas = (struct fila *) malloc(sizeof(struct fila) * 256);
    for (int i = 0; i < 256; i++) {
        inicializa_fila(fh->filas + i);
    }
    printf("\n-----Inicializacao da Fila Hierarquica-----\n");
}

// Enfileira elemento M na fila
int EnfileiraFilaHierarquica(struct fila_hierarquica *fh, TPRotulo M, Tpixel nivel) {
    if (nivel < 0 || nivel >= 256) {
		return 0; // Nível inválido
	} else {
    	return enfileira(fh->filas + nivel, M);
	}
}

// Remove e retorna o primeiro elemento da fila não vazia de menor nível
int DesenfileiraHierarquica(struct fila_hierarquica *fh, TPRotulo *M) {
    for (int i = 0; i < 256; i++) {
        if (!fila_vazia(fh->filas + i)) {
            if (primeiro(fh->filas + i, M)) { // Salva o elemento em M.
                desenfileira(fh->filas + i);
                return 1;
            }
        }
    }
    return 0;  // todas as filas estão vazias.
}


void ImprimeDados(TPpgm *img) {
    if (img == NULL) {
        printf("Imagem nula.\n");
        return;
    }

    printf("\n\n==== Dados da Imagem ====\n");
    printf("Tipo: %s\n", img->tipo);
    printf("Largura: %d pixels\n", img->w);
    printf("Altura: %d pixels\n", img->h);
    printf("Brilho maximo: %d\n", img->max);
    printf("Total de pixels: %d\n", img->pixlen);
    printf("=========================\n");
}


void ReadPGM (const char *fname, TPpgm *img) {
    FILE *fd;

	printf("\n ..... (Abrindo ARQUIVO )--> %s.", fname);
    fd = fopen(fname, "r");  // modo "r" --> abrir somente para leitura
	if (!fd) {
        printf("\n ERRO: Incapaz de abrir arquivo: %s.\n\n", fname);
        exit(1);  // ERRO 1: arquivo inexistente ou não encontrado no caminho especificado.
    }


	printf("\n ..... (Abriu ARQUIVO )-->% s.", fname);
    fscanf (fd, "%s\n", img->tipo); // vetor de char ("P1", "P2", "P3")

	// Tratamento de comentários:
    char C[256];
	fgets (C, 255, fd); // lê a segunda linha
    while (C[0] == '#') {   // verifica se há uma linha de comentário
        fgets (C, 255, fd);  // lê a próxima linha
    }

    sscanf(C, "%d %d", &img->w, &img->h); // extrai largura e altura

    if (((strcmp(img->tipo, "P1") != 0))) { ///se a imagem não é binária (P1)...
        fscanf (fd, "%d", &img->max); /// valor de brilho máximo na imagem
    }

    // se a imagem é binária (P1) ou em escala de cinza (P2)
    img->pixlen = 1*(img->w * img->h);  //cada pixel tem 1 componente (valor de brilho)

    if (((strcmp(img->tipo, "P3")) == 0)) { // se a imagem é colorida
        img->pixlen = 3*(img->w * img->h); //cada pixel tem 3 componentes (R,G,B)
    }

	printf("\n ..... (Leu Cabecalho )-->%s.", fname);

	int paux;
    img->pix = (Tpixel*) malloc(sizeof(Tpixel) * (img->pixlen));
    if (!img->pix) {
        printf("\n Vetor de pixels não alocado...");
        exit(1);
    }

    for (int k=0; k<img->pixlen; k++){
        fscanf (fd, "%d", &paux);
        *(img->pix + k) = (Tpixel) paux;
	}

	printf("\n ..... (Leu ARQUIVO )--> %s.", fname);
   	fclose(fd);
}


Tpixel GetPixel(TPpgm *img, int L, int C){

    /// abstrair o vetor img->pData como uma matriz
    /// de dimensoes  (img->h x img->w)

    if ((L >= img->h) ||  (C >= img->w) || ( L < 0) || (C < 0)) {
        printf("\n%d %d", L, C);
        printf("\n ..... Coordenada de imagem esta fora dos limites da grade da imagem.");
        exit(0);
    }

    Tpixel K;
    K = *((img->pix) + L*img->w + C);

    return (K);
}


int PutPixel(TPpgm *img, int L, int C, Tpixel v){

    // abstrair o vetor img->pix como uma matriz
    // de dimensoes  (img->h x img->w)

    if ((L >= img->h) ||  (C >= img->w) || ( L < 0) || (C < 0)) {
        printf("\n ..... Escrita na coordenada de imagem esta fora dos limites da grade da imagem.");
        printf("\nlinha %d\n, coluna %d\n",L,C);
        exit(0);
    }

	*((img->pix) + L*img->w + C) = v;

    return (1);
}


int PutPixelRGB(TPpgm *img, int L, int C, Tpixel r, Tpixel g, Tpixel b){

    /// abstrair o vetor img->pData como uma matriz
    /// de dimensoes  (img->h x img->w)

    if ((L >= img->h) ||  (C >= img->w) || ( L < 0) || (C < 0)) {
        printf("\n ..... Escrita na aoordenada de imagem esta fora dos limites da grade da imagem.");
        exit(0);
    }

    *((img->pix) + 3*(L*img->w + C)) = r;
    *((img->pix) + 3*(L*img->w + C) + 1) = g;
    *((img->pix) + 3*(L*img->w + C) + 2) = b;

    return (1);
}


void RGBToGray(TPpgm *f, TPpgm *g){
    //input: f, uma imagem colorida (P3)
    //output: g, uma imagem em tom de cinza (P2)

    if(strcmp(f->tipo, "P3") != 0){
        printf("\n..... A Imagem de entrada deve ser colorida.\n");
        exit(1);
    }

    *g = *f;
    g->tipo[1] = '2'; // transforma o campo tipo de P3 para P2
    g->pixlen = f->pixlen/3;

    g->pix = (Tpixel*) malloc (sizeof(Tpixel) * g->pixlen);

    int k=0;
    Tpixel paux;
    for(int j = 0; j < f->pixlen; j+=3){
        paux = (Tpixel)(((int) f->pix[j] + (int) f->pix[j+1] + (int) f->pix[j+2])/3);
        g->pix[k] = paux;
        k++;
    }
}


void WritePGM(const char *fname, TPpgm *img) {

	FILE *fd;

	fd = fopen(fname, "w");  /// modo "w" --> abrir para escrita
    if (!fd) {
        printf("\n ERRO: Incapaz de abrir arquivo: %s.", fname);
        exit(1);
    }

	printf("\n ..... (ARQUIVO Aberto)-->%s.", fname);

	// Gravação de dados no arquivo:
    fprintf(fd, "%s\n", img->tipo); // assinatura PGM:  color "P3", cinza "P2" ou binario "P1"
    fprintf(fd,"%d %d\n", img->w, img->h); // largura e altura
    if (strcmp(img->tipo, "P1") != 0) {
        fprintf(fd,"%d\n", 255); // valor de brilho máximo na imagem (255)
    }

    /// gravar no arquivo os valores dos pixels da imagem computada
    for (int k = 0; k < img->pixlen; k++) {
        fprintf(fd,"%d\n", img->pix[k]);
    }

    fclose(fd);

    printf("\n ..... (ARQUIVO GRAVADO)-->%s.", fname);
}


void Gradiente(TPpgm *f, TPpgm *g) {
    // input: f imagem em tons de cinza ou binária
    // output: g imagem do gradiente da imagem com bordas duplas
    //          usando um elemento estruturante 3x3

    *g = *f; /// copia os campos da struct f para os campos correspondentes da struct g

    if (strcmp(g->tipo, "P3") == 0) { // se a imagem é colorida (tipo "P3"), ent�o não se aplica operadores morfológicos convencionais
      printf("\n ... Nao é possivel aplicar operador morfologico sobre dados de imagens coloridas.\n");
      printf("\n ... Tipo da imagem PGM = %s \n", g->tipo);
      exit(1);
    }

    g->pix = (Tpixel*)calloc(sizeof(Tpixel), (g->pixlen)); /// novo endereço para pixels da imagem g

    // gravar no arquivo os valores dos pixels da imagem computada
   	Tpixel mn, mx, paux, grad;
    for (int L = 1; L < g->h - 1; L++) {
        for (int C = 1; C < g->w - 1; C++) {
            mn = 255;
            mx = 0;
            for (int k = -1; k <= 1; k++) {
                for (int j = -1; j <= 1; j++) {
                    paux = GetPixel(f, L+k, C+j);
                    if(paux < mn) {
                        mn = paux;
                    } if (paux > mx) {
						mx = paux;
					}
                }
            }
            grad = mx - mn;
            PutPixel(g, L, C, grad);
        }
    }
}


TPRotulo* ReadMarkers(const char *fname, int *tm){
	// void ReadMarkers(const char *fname, TPmarker *M, int *tm){
    // lê do arquivo fname:
    //    1) total de marcadores e retorna em tm
    //    2) os dados de cada marcador e retorna no vetor M

	FILE *fd;
	fd = fopen(fname, "r");  /// modo "r" --> abrir para ler
    if (!fd) {
        printf("\n ERRO: Incapaz de abrir arquivo: %s.", fname);
        exit(1);
    }

	printf("\n ..... (ARQUIVO Aberto)--> %s\n", fname);

    fscanf(fd, "%d\n", tm); // quantidade de marcadores

   	TPRotulo *M = (TPRotulo*) malloc(sizeof(TPRotulo) * (*tm));
    for (int k=0; k<(*tm); k++){
    	int l, c, r;
    	fscanf(fd, "%d %d %d",&l, &c, &r);
    	M[k].L = l;
    	M[k].C = c;
    	M[k].rotulo = r;
    }

    fclose (fd);
    return M;
}


void ExibeMarcadores(TPRotulo *M, int tm) {
	printf("\nMarcadores (%d):\n", tm);
    for (int i = 0; i < tm; i++) {
        printf("Marcador %d -> Linha: %d, Coluna: %d, Rotulo: %d\n", i, M[i].L, M[i].C, M[i].rotulo);
    }
}


int *CriaImagemRotulo(int largura, int altura) {
    int *E = (int *) calloc(largura * altura, sizeof(int));
    if (E == NULL) {
        printf("Erro ao alocar a imagem de rótulos.\n");
        exit(1);
    }
    return E;
}


void EnfileiraTodosMarcadores(struct fila_hierarquica *fh, TPRotulo *M, int tm, TPpgm *imagemGradiente) {
    for (int i = 0; i < tm; i++) {
        TPRotulo marcador = M[i];
        int L = marcador.L;
        int C = marcador.C;
        int nivel = imagemGradiente->pix[L * imagemGradiente->w + C]; // Pega o valor do gradiente

        // Enfileira na fila hierárquica no nível correspondente
        EnfileiraFilaHierarquica(fh, marcador, nivel);
    }
}


void InicializaImagemRotulos(int *E, TPRotulo *M, int tm, int largura, int altura) {

    // Para cada marcador, define seu rótulo na posição correta
    for (int i = 0; i < tm; i++) {
        int L = M[i].L;
        int C = M[i].C;

        if (L >= 0 && L < altura && C >= 0 && C < largura) {
            E[L * largura + C] = M[i].rotulo;
        }
    }
}


void Watershed(struct fila_hierarquica *fh, int *E, TPpgm *imagemGradiente) {
    int largura = imagemGradiente->w;
    int altura = imagemGradiente->h;
    TPRotulo atual;
	int quantidade_iteracoes;
	
    while (DesenfileiraHierarquica(fh, &atual)) {
        int l = atual.L;
        int c = atual.C;
        int r = atual.rotulo;

        // Vizinho cima
        if (l - 1 >= 0) {
            int indice = (l - 1) * largura + c;
            if (E[indice] == 0){
                E[indice] = r;
                TPRotulo vizinho;
                vizinho.L = l - 1;
                vizinho.C = c;
                vizinho.rotulo = r;
                Tpixel nivel = imagemGradiente->pix[(l - 1) * largura + c];
                EnfileiraFilaHierarquica(fh, vizinho, nivel);
            }
        }

        // Vizinho baixo
        if (l + 1 < altura) {
            int indice = (l + 1) * largura + c;
            if (E[indice] == 0) {
                E[indice] = r;
                TPRotulo vizinho;
                vizinho.L = l + 1;
                vizinho.C = c;
                vizinho.rotulo = r;
        		Tpixel nivel = imagemGradiente->pix[(l + 1) * largura + c];
                EnfileiraFilaHierarquica(fh, vizinho, nivel);
            }
        }

        // Vizinho esquerda
        if (c - 1 >= 0) {
            int indice = l * largura + (c - 1);
            if (E[indice] == 0) {
                E[indice] = r;
                TPRotulo vizinho;
                vizinho.L = l;
                vizinho.C = c - 1;
                vizinho.rotulo = r;
                Tpixel nivel = imagemGradiente->pix[l * largura + (c - 1)];
                EnfileiraFilaHierarquica(fh, vizinho, nivel);
            }
        }

        // Vizinho direita
        if (c + 1 < largura) {
            int indice = l * largura + (c + 1);
            if (E[indice] == 0) {
                E[indice] = r;
                TPRotulo vizinho;
                vizinho.L = l;
                vizinho.C = c + 1;
                vizinho.rotulo = r;
                Tpixel nivel = imagemGradiente->pix[l * largura + (c + 1)];
                EnfileiraFilaHierarquica(fh, vizinho, nivel);
        	}
    	}
    	
    	// Vizinho cima-esquerda
        if (l - 1 >= 0 && c - 1 >= 0) {
            int indice = (l - 1) * largura + (c - 1);
            if (E[indice] == 0) {
                E[indice] = r;
                TPRotulo vizinho;
                vizinho.L = l - 1;
                vizinho.C = c - 1;
                vizinho.rotulo = r;
                Tpixel nivel = imagemGradiente->pix[(l - 1) * largura + (c - 1)];
                EnfileiraFilaHierarquica(fh, vizinho, nivel);
            }
        }

        // Vizinho cima-direita
        if (l - 1 >= 0 && c + 1 < largura) {
            int indice = (l - 1) * largura + (c + 1);
            if (E[indice] == 0) {
                E[indice] = r;
                TPRotulo vizinho;
                vizinho.L = l - 1;
                vizinho.C = c + 1;
                vizinho.rotulo = r;
                Tpixel nivel = imagemGradiente->pix[(l - 1) * largura + (c + 1)];
                EnfileiraFilaHierarquica(fh, vizinho, nivel);
            }
        }

        // Vizinho baixo-esquerda
        if (l + 1 < altura && c - 1 >= 0) {
            int indice = (l + 1) * largura + (c - 1);
            if (E[indice] == 0) {
                E[indice] = r;
                TPRotulo vizinho;
                vizinho.L = l + 1;
                vizinho.C = c - 1;
                vizinho.rotulo = r;
                Tpixel nivel = imagemGradiente->pix[(l + 1) * largura + (c - 1)];
                EnfileiraFilaHierarquica(fh, vizinho, nivel);
            }
        }

        // Vizinho baixo-direita
        if (l + 1 < altura && c + 1 < largura) {
            int indice = (l + 1) * largura + (c + 1);
            if (E[indice] == 0) {
                E[indice] = r;
                TPRotulo vizinho;
                vizinho.L = l + 1;
                vizinho.C = c + 1;
                vizinho.rotulo = r;
                Tpixel nivel = imagemGradiente->pix[(l + 1) * largura + (c + 1)];
                EnfileiraFilaHierarquica(fh, vizinho, nivel);
        	}
    	}
    	quantidade_iteracoes++;
    }
    printf("\nWatershed feito com sucesso!\n");
    printf("Quantidade de iteracoes: %d.\n", quantidade_iteracoes);
}


void VetorToImagemRotulo(int *vetorRotulos, TPpgm *imagemRotulos, int largura, int altura) {
    imagemRotulos->w = largura;
    imagemRotulos->h = altura;
    imagemRotulos->pixlen = largura * altura;
    strcpy(imagemRotulos->tipo, "P2");  // P2 = imagem em tons de cinza
    imagemRotulos->max = 255;

    imagemRotulos->pix = (Tpixel*) malloc(sizeof(Tpixel) * imagemRotulos->pixlen);

    for (int i = 0; i < imagemRotulos->pixlen; i++) {
        imagemRotulos->pix[i] = (Tpixel) vetorRotulos[i];
    }
}


void RegionColorMarkers(TPpgm *f, TPpgm *mk, TPpgm *cm){

    *cm = *f;
    if (strcmp(f->tipo, "P3") != 0) {
        cm->tipo[1] = '3';
        cm->pixlen = 3*f->pixlen;
        cm->pix = (Tpixel*)malloc(sizeof(Tpixel)*cm->pixlen);
        int p = 0;
        for (int k=0; k<f->pixlen; k++){ // ...copiar 3 vezes o mesmo pixel
            cm->pix[p] = cm->pix[p+1] = cm->pix[p+2] = f->pix[k];
            p +=3;
        }
    } else {
        cm->pix = (Tpixel*)malloc(sizeof(Tpixel)*cm->pixlen);
        memcpy(cm->pix, f->pix, (sizeof(Tpixel)*cm->pixlen));
    }

    Tpixel r, g, b;
    Tpixel lbl;   // valor do rótulo atual

    for (int l = 0; l < mk->h; l++) {
        for(int c = 0; c < mk->w; c++){
            lbl = GetPixel(mk, l, c);
            if (lbl != 0 && lbl != 255) {
	            switch (lbl) {
	                case 1:
	                    r=255; g=0; b=0; // vermelho
	                    break;
	                case 2:
	                    r=0; g=255; b=0;  // verde
	                    break;
	                case 3:
	                    r=0; g=0; b=255; // azul
	                    break;
	                case 4:
	                    r=255; g=127; b=0; // laranja
	                    break;
	                case 5:
	                    r=255; g=255; b=255; // branco
	                    break;
	                case 6:
	                    r=127; g=127; b=127; // cinza médio
	                	break;
	                case 7:
	                	r=255; g=255; b=0; // amarelo
	                	break;
	                case 8:
	                	r=255; g=0; b=127; // rosa
	                	break;
	                case 9:
	                	r=0; g=255; b=255; // ciano
	                default:
	                	r=255; g=255; b=255;
	                	break;
	            }
	        	PutPixelRGB(cm,l,c,r,g,b);
        	}
        }
    }
}

int main(int argc, char *argv[]) {
	
	// Nomes dos arquivos:
	const char *imagem = "Imagem_Trabalho.ppm";
	const char *nomeImagemCinza = "Imagens//Imagem_Trabalho_Cinza.pgm";
	const char *nomeImagemGradiente = "Imagens//Imagem_Trabalho_Gradiente.pgm";
	const char *nomeArquivoMarcadores = "ColorMarkers.txt";
	const char *nomeImagemFinal = "Imagens//Imagem_Watershed.ppm";
	
	TPpgm imagemColorida, imagemCinza, imagemGradiente, imagemRotulada, imagemFinal;
	
	// Leitura e escrita das imagem da colorida, em tons de cinza e do gradiente.
	ReadPGM(imagem, &imagemColorida);
	ImprimeDados(&imagemColorida);
	RGBToGray(&imagemColorida, &imagemCinza);
	ImprimeDados(&imagemCinza);
	WritePGM(nomeImagemCinza, &imagemCinza);
	Gradiente(&imagemCinza, &imagemGradiente);
	WritePGM(nomeImagemGradiente, &imagemGradiente);
	
	// Recuperação dos Marcadores
	int tm;
	TPRotulo *M = ReadMarkers(nomeArquivoMarcadores, &tm);
	ExibeMarcadores(M, tm);
	
	// Watershed
	struct fila_hierarquica fh;
	InicializaFilaHierarquica(&fh);
	EnfileiraTodosMarcadores(&fh, M, tm, &imagemGradiente);
	int* imagemRotulos = CriaImagemRotulo(imagemGradiente.w, imagemGradiente.h);
	InicializaImagemRotulos(imagemRotulos, M, tm, imagemGradiente.w, imagemGradiente.h);
	Watershed(&fh, imagemRotulos, &imagemGradiente);
	VetorToImagemRotulo(imagemRotulos, &imagemRotulada, imagemGradiente.w, imagemGradiente.h);
	RegionColorMarkers(&imagemCinza, &imagemRotulada, &imagemFinal);
	WritePGM(nomeImagemFinal, &imagemFinal);
	
	// Desalocação de Memória
	free(imagemColorida.pix);
	free(imagemCinza.pix);
	free(imagemGradiente.pix);
	free(imagemRotulada.pix);
	free(imagemFinal.pix);
	free(M);
	free(fh.filas);
	free(imagemRotulos);
}
