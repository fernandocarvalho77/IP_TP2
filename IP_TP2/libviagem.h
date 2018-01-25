//
//  libviagem.h
//  IP_TP2
//

#define MAXVIAGENS 10000

typedef struct viagem{
	char tipoviagem[50];
	int data;
	int hora;
	char veiculo[100];
	char motorista[100];
	float distancia;
	float custo;
} viagem;

typedef struct tipoviagem {
	char descricao[50];
} tipoviagem;

tipoviagem tipoviagens[2] = {"Saude", "Combate a incendio"};

int insereviagem(char[], int, int, char[], char[], float, float);
void alteraviagem(void);
void eliminaviagem(void);
void listaviagem(void);

int insereviagem(char tipoviagem[], int data, int hora, char veiculo[], char motorista[], float distancia, float custo){
	FILE *ficheiro;
	
	ficheiro = fopen("viagembd.txt", "a+");
	if(ficheiro == NULL)
	{
		ficheiro = fopen("viagembd.txt", "w");
	}
	
	fprintf(ficheiro, "%s, %i, %i, %s, %s, %f, %f\n", tipoviagem, data, hora, veiculo, motorista, distancia, custo);
	fclose(ficheiro);
	return 0;
}

void listaviagem(){
	FILE *ficheiro;
	int i = 0, j = 0;

	ficheiro = fopen("viagembd.txt", "r");
	if(ficheiro == NULL)
	{
		printf("Houve uma problemazeco na leitura do ficheiro!");
	}
	else {
		i = linhasficheiro(ficheiro);

		if (i > 0) {
			viagem viagens[i];

			for (j = 0; j < i; j++) {
				fscanf(ficheiro, "%[^,], %i, %i, %[^,], %[^,], %f, %f\n", viagens[j].tipoviagem, &viagens[j].data, &viagens[j].hora, viagens[j].veiculo, viagens[j].motorista, &viagens[j].distancia, &viagens[j].custo);
			}

			int tamanhoarray = sizeof(viagens)/sizeof(viagens[0]);

			if (tamanhoarray > 0) {
				printf("\nregisto, tipo de viagem, data, hora, Veiculo, motorista, distancia, custo\n");
				for (int x = 0; x < tamanhoarray; x++) {
					printf("%i, %s, %i, %i, %s, %s, %.2f, %.2f\n", x, viagens[x].tipoviagem, viagens[x].data, viagens[x].hora, viagens[x].veiculo, viagens[x].motorista, viagens[x].distancia, viagens[x].custo);
				}
			}
			else{
				printf("Não há registos para mostrar!");
			}
		}
		else{
			printf("Não há nada registado no ficheiro!");
		}
	}

	fclose(ficheiro);
}

