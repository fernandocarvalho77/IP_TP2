//
//  libmotorista.h
//  IP_TP2
//

#define MAXMOTORISTAS 1000

typedef struct motorista{
	int idmotorista;
	char nome[100];
	char apelido[50];
	int nif;
	int tlf;
} motorista;

int inseremotorista(int, char[], char[], int, int);
void alteramotorista(void);
void eliminamotorista(void);
void listamotorista(void);

int inseremotorista(int idmotorista, char nome[], char apelido[], int nif, int tlf){
	FILE *ficheiro;
	
	ficheiro = fopen("motoristabd.txt", "a+");
	if(ficheiro == NULL)
	{
		ficheiro = fopen("motoristabd.txt", "w");
	}
	
	fprintf(ficheiro, "%i, %s, %s, %i, %i\n", idmotorista, nome, apelido, nif, tlf);
	fclose(ficheiro);
	return 0;
}

void listamotorista(){
	FILE *ficheiro;
	int i = 0, j = 0;
	
	ficheiro = fopen("motoristabd.txt", "r");
	if(ficheiro == NULL)
	{
		printf("Houve uma problemazeco na leitura do ficheiro!");
	}
	else {
		i = linhasficheiro(ficheiro);
		
		if (i > 0) {
			motorista motoristas[i];
			
			for (j = 0; j < i; j++) {
				fscanf(ficheiro, "%i, %[^,], %[^,], %i, %i\n", &motoristas[j].idmotorista, motoristas[j].nome, motoristas[j].apelido, &motoristas[j].nif, &motoristas[j].tlf);
			}
			
			int tamanhoarray = sizeof(motoristas)/sizeof(motoristas[0]);
			
			if (tamanhoarray > 0) {
				printf("\nregisto, idmotorista, nome, apelido, nif, tlf\n");
				for (int x = 0; x < tamanhoarray; x++) {
					printf("%i, %i, %s, %s, %i, %i,\n", x, motoristas[x].idmotorista, motoristas[x].nome, motoristas[x].apelido, motoristas[x].nif, motoristas[x].tlf);
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

void eliminamotorista(){
	FILE *ficheiro;
	int i = 0, j = 0, registo = 0;
	char confirma = ' ';
	
	ficheiro = fopen("motoristabd.txt", "r");
	if(ficheiro == NULL)
	{
		printf("Houve uma problemazeco na leitura do ficheiro!");
	}
	else {
		i = linhasficheiro(ficheiro);
		
		if (i > 0) {
			motorista motoristas[i];
			
			for (j = 0; j < i; j++) {
				fscanf(ficheiro, "%i, %[^,], %[^,], %i, %i\n", &motoristas[j].idmotorista, motoristas[j].nome, motoristas[j].apelido, &motoristas[j].nif, &motoristas[j].tlf);
			}
			
			int tamanhoarray = sizeof(motoristas)/sizeof(motoristas[0]);
			
			if (tamanhoarray > 0) {
				printf("\nregisto, idmotorista, nome, apelido, nif, tlf\n");
				for (int x = 0; x < tamanhoarray; x++) {
					printf("%i, %i, %s, %s, %i, %i\n", x, motoristas[x].idmotorista, motoristas[x].nome, motoristas[x].apelido, motoristas[x].nif, motoristas[x].tlf);
				}
			}
			else {
				printf("Não há registos para mostrar!");
			}
			
			printf("\nInsira o numero do registo a eliminar: ");
			scanf("%i", &registo);
			
			if (registo >= tamanhoarray || registo < 0) {
				printf("\nOops, esse registo nao existe.");
			}
			else {
				printf("%i, %i, %s, %s, %i, %i\n", registo, motoristas[registo].idmotorista, motoristas[registo].nome, motoristas[registo].apelido, motoristas[registo].nif, motoristas[registo].tlf);
				
				printf("\nDeseja realmente eliminar o registo? (s/n): ");
				scanf(" %c", &confirma);
				
				if (confirma == 's' || confirma == 'S') {
					
					j = 0;
					for (i = 0; i < tamanhoarray; i++) {
						if (registo == i) {
							continue;
						}
						motoristas[j] = motoristas[i];
						j++;
					}
					tamanhoarray--;
					
					fclose(ficheiro);
					
					ficheiro = fopen("motoristabd.txt", "w");
					
					for (j = 0; j < tamanhoarray; j++) {
						fprintf(ficheiro, "%i, %s, %s, %i, %i\n", motoristas[j].idmotorista, motoristas[j].nome, motoristas[j].apelido, motoristas[j].nif, motoristas[j].tlf);
					}
					
					printf("O registo com o id %i foi eliminado!", registo);
					
				}
				else
				{
					printf("Record não 'terminated'");
				}
			}
		}
		else
		{
			printf("Não há nada registado no ficheiro!");
		}
	}
	
	fclose(ficheiro);
}

void alteramotorista(){
	FILE *ficheiro;
	int i = 0, j = 0, registo = 0, opcaotipomotorista = 0;;
	char confirma = ' ';
	
	ficheiro = fopen("motoristabd.txt", "r");
	if(ficheiro == NULL)
	{
		printf("Houve uma problemazeco na leitura do ficheiro!");
	}
	else {
		i = linhasficheiro(ficheiro);
		
		if (i > 0) {
			motorista motoristas[i];
			
			for (j = 0; j < i; j++) {
				fscanf(ficheiro, "%i, %[^,], %[^,], %i, %i\n", &motoristas[j].idmotorista, motoristas[j].nome, motoristas[j].apelido, &motoristas[j].nif, &motoristas[j].tlf);
			}

			int tamanhoarray = sizeof(motoristas)/sizeof(motoristas[0]);

			if (tamanhoarray > 0) {
				printf("\nregisto, idmotorista, nome, apelido, nif, tlf\n");
				for (int x = 0; x < tamanhoarray; x++) {
					printf("%i, %i, %s, %s, %i, %i\n", x, motoristas[x].idmotorista, motoristas[x].nome, motoristas[x].apelido, motoristas[x].nif, motoristas[x].tlf);
				}
			}
			else {
				printf("Não há registos para mostrar!");
			}

			printf("\nInsira o id do registo a alterar: ");
			scanf("%i", &registo);

			if (registo >= tamanhoarray || registo < 0) {
				printf("\nOops, esse registo nao existe.");
			}
			else {
				printf("%i, %i, %s, %s, %i, %i\n", registo, motoristas[registo].idmotorista, motoristas[registo].nome, motoristas[registo].apelido, motoristas[registo].nif, motoristas[registo].tlf);
				
				printf("\nDeseja realmente alterar o registo? (s/n): ");
				scanf(" %c", &confirma);
				
				if (confirma == 's' || confirma == 'S') {
					
					printf("\nIDMotorista: ");
					scanf("%i", &motoristas[registo].idmotorista);
					printf("\nNome: ");
					gets(motoristas[registo].nome);
					printf("\nApelido: ");
					gets(motoristas[registo].apelido);
					printf("\nNIF: ");
					scanf("%i", &motoristas[registo].nif);
					printf("\nNumero de telefone: ");
					scanf("%i", &motoristas[registo].tlf);
					
					fclose(ficheiro);
					
					ficheiro = fopen("motoristabd.txt", "w");
					
					for (j = 0; j < tamanhoarray; j++) {
						fprintf(ficheiro, "%i, %s, %s, %i, %i\n", motoristas[j].idmotorista, motoristas[j].nome, motoristas[j].apelido, motoristas[j].nif, motoristas[j].tlf);
					}
					
					printf("O registo com o id %i foi alterado!", registo);
					
				}
				else
				{
					printf("Record não 'terminated'");
				}
			}
		}
		else
		{
			printf("Não há nada registado no ficheiro!");
		}
	}

	fclose(ficheiro);
}

