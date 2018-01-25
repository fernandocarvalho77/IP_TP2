//
//  libveiculo.h
//  IP_TP2
//

#define MAXVEICULOS 1000

// Estrutura que permite guardar a informação de cada veiculo
typedef struct veiculo{
	int idveiculo;
	char tipoveiculo[50];
	char marca[50];
	char modelo[50];
	char matricula[8];
	int datamatricula;
	float custopkm;
	float valorreservacombustivel;
	float consumomedio;
} veiculo;

// Estrutura que permite guardar a informação de cada tipo de veiculo
typedef struct tipoveiculo {
	char descricao[50];
} tipoveiculo;

// Inicialização da estrutura "tipoveiculo"
tipoveiculo tipoveiculos[7] = {"Ambulancia de Socorro", "Ambulancia de Transporte de Doentes", "Ambulancia de Cuidados Intensivos", "Veiculo Urbano de Combate a Incendios", "Veiculo Rural de Combate a Incendios", "Veiculo Florestal de Combate a Incendios", "Veiculo Ligeiro de Combate a Incendios"};

// Declaracao de funcoes
int insereveiculo(int, char[], char[], char[], char[], int, float, float, float);
void alteraveiculo(void);
void eliminaveiculo(void);
void listaveiculo(void);

// Funcao do tipo inteiro que permite registar os dados dos veiculos no ficheiro através de parametros
int insereveiculo(int idveiculo, char tipoveiculo[], char marca[], char modelo[], char matricula[], int datamatricula, float custopkm, float valorreservacombustivel, float consumomedio){
	FILE *ficheiro;
	
	ficheiro = fopen("veiculobd.txt", "a+");
	if(ficheiro == NULL)
	{
		ficheiro = fopen("veiculobd.txt", "w");
	}
	
	fprintf(ficheiro, "%i, %s, %s, %s, %s, %i, %f, %f, %f\n", idveiculo, tipoveiculo, marca, modelo, matricula, datamatricula, custopkm, valorreservacombustivel, consumomedio);
	fclose(ficheiro);
	return 0;
}

// Funcao do tipo void que permite listar os veiculos
void listaveiculo(){
	FILE *ficheiro;
	int i = 0, j = 0;
	
	ficheiro = fopen("veiculobd.txt", "r");
	if(ficheiro == NULL)
	{
		printf("Houve uma problemazeco na leitura do ficheiro!");
	}
	else {
		// Obtem o numero de linhas no ficheiro
		i = linhasficheiro(ficheiro);
		
		if (i > 0) {
			// Cria uma array do tipo "veiculo" usando o valor do numero de linhas existente no ficheiro
			veiculo veiculos[i];
			
			// Le os dados do ficheiro e preence a array com os mesmos
			for (j = 0; j < i; j++) {
				fscanf(ficheiro, "%i, %[^,], %[^,], %[^,], %[^,], %i, %f, %f, %f\n", &veiculos[j].idveiculo, veiculos[j].tipoveiculo, veiculos[j].marca, veiculos[j].modelo, veiculos[j].matricula, &veiculos[j].datamatricula, &veiculos[j].custopkm, &veiculos[j].valorreservacombustivel, &veiculos[j].consumomedio);
			}
			
			// Obtem o valor da array "veiculos" (numero de registos)
			int tamanhoarray = sizeof(veiculos)/sizeof(veiculos[0]);
			
			// Mostra no ecra os dados da array "veiculos"
			if (tamanhoarray > 0) {
				printf("\nregisto, idveiculo, tipoveiculo, marca, modelo, matricula, datamatricula, custopkm, valorreservacombustivel, consumomedio\n");
				for (int x = 0; x < tamanhoarray; x++) {
					printf("%i, %i, %s, %s, %s, %s, %i, %.2f, %.2f, %.2f\n", x, veiculos[x].idveiculo, veiculos[x].tipoveiculo, veiculos[x].marca, veiculos[x].modelo, veiculos[x].matricula, veiculos[x].datamatricula, veiculos[x].custopkm, veiculos[x].valorreservacombustivel, veiculos[x].consumomedio);
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

// Funcao do tipo void que permite eliminar um registo
void eliminaveiculo(){
	FILE *ficheiro;
	int i = 0, j = 0, registo = 0;
	char confirma = ' ';
	
	ficheiro = fopen("veiculobd.txt", "r");
	if(ficheiro == NULL)
	{
		printf("Houve uma problemazeco na leitura do ficheiro!");
	}
	else {
		i = linhasficheiro(ficheiro);
		
		if (i > 0) {
			veiculo veiculos[i];
			
			for (j = 0; j < i; j++) {
				fscanf(ficheiro, "%i, %[^,], %[^,], %[^,], %[^,], %i, %f, %f, %f\n", &veiculos[j].idveiculo, veiculos[j].tipoveiculo, veiculos[j].marca, veiculos[j].modelo, veiculos[j].matricula, &veiculos[j].datamatricula, &veiculos[j].custopkm, &veiculos[j].valorreservacombustivel, &veiculos[j].consumomedio);
			}
			
			int tamanhoarray = sizeof(veiculos)/sizeof(veiculos[0]);
			
			if (tamanhoarray > 0) {
				printf("\nregisto, idveiculo, tipoveiculo, marca, modelo, matricula, datamatricula, custopkm, valorreservacombustivel, consumomedio\n");
				for (int x = 0; x < tamanhoarray; x++) {
					printf("%i, %i, %s, %s, %s, %s, %i, %.2f, %.2f, %.2f\n", x, veiculos[x].idveiculo, veiculos[x].tipoveiculo, veiculos[x].marca, veiculos[x].modelo, veiculos[x].matricula, veiculos[x].datamatricula, veiculos[x].custopkm, veiculos[x].valorreservacombustivel, veiculos[x].consumomedio);
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
				
				printf("\n%i, %i, %s, %s, %s, %s, %i, %.2f, %.2f, %.2f\n", registo, veiculos[registo].idveiculo, veiculos[registo].tipoveiculo, veiculos[registo].marca, veiculos[registo].modelo, veiculos[registo].matricula, veiculos[registo].datamatricula, veiculos[registo].custopkm, veiculos[registo].valorreservacombustivel, veiculos[registo].consumomedio);
				
				printf("\nDeseja realmente eliminar o registo? (s/n): ");
				scanf(" %c", &confirma);
				
				if (confirma == 's' || confirma == 'S') {
					// Bloco que permite eliminar o registo selecionado da array "veiculos"
					// ao encontrar o registo com o valor selecionado, copia o elemento seguinte da array para esse elemento, "eliminando" o elemento selecionado
					// finaliza com a redução do tamanho da array
					j = 0;
					for (i = 0; i < tamanhoarray; i++) {
						if (registo == i) {
							continue;
						}
						veiculos[j] = veiculos[i];
						j++;
					}
					tamanhoarray--;
					
					// Fecha o ficheiro
					fclose(ficheiro);
					
					// Recria o ficheiro
					ficheiro = fopen("veiculobd.txt", "w");
					
					// Regista novamente os dados da array em ficheiro já sem o registo selecionado
					for (j = 0; j < tamanhoarray; j++) {
						fprintf(ficheiro, "%i, %s, %s, %s, %s, %i, %f, %f, %f\n", veiculos[j].idveiculo, veiculos[j].tipoveiculo, veiculos[j].marca, veiculos[j].modelo, veiculos[j].matricula, veiculos[j].datamatricula, veiculos[j].custopkm, veiculos[j].valorreservacombustivel, veiculos[j].consumomedio);
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

// Funcao para alterar os valores de um dado veiculo
void alteraveiculo(){
	FILE *ficheiro;
	int i = 0, j = 0, registo = 0, opcaotipoveiculo = 0;;
	char confirma = ' ';
	
	ficheiro = fopen("veiculobd.txt", "r");
	if(ficheiro == NULL)
	{
		printf("Houve uma problemazeco na leitura do ficheiro!");
	}
	else {
		i = linhasficheiro(ficheiro);
		
		if (i > 0) {
			veiculo veiculos[i];
			
			for (j = 0; j < i; j++) {
				fscanf(ficheiro, "%i, %[^,], %[^,], %[^,], %[^,], %i, %f, %f, %f\n", &veiculos[j].idveiculo, veiculos[j].tipoveiculo, veiculos[j].marca, veiculos[j].modelo, veiculos[j].matricula, &veiculos[j].datamatricula, &veiculos[j].custopkm, &veiculos[j].valorreservacombustivel, &veiculos[j].consumomedio);
			}
			
			int tamanhoarray = sizeof(veiculos)/sizeof(veiculos[0]);
			
			if (tamanhoarray > 0) {
				printf("\nid idveiculo tipoveiculo marca modelo matricula datamatricula custopkm valorreservacombustivel consumomedio\n");
				for (int x = 0; x < tamanhoarray; x++) {
					printf("%i, %i, %s, %s, %s, %s, %i, %.2f, %.2f, %.2f\n", x, veiculos[x].idveiculo, veiculos[x].tipoveiculo, veiculos[x].marca, veiculos[x].modelo, veiculos[x].matricula, veiculos[x].datamatricula, veiculos[x].custopkm, veiculos[x].valorreservacombustivel, veiculos[x].consumomedio);
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
				
				printf("\n%i, %i, %s, %s, %s, %s, %i, %.2f, %.2f, %.2f\n", registo, veiculos[registo].idveiculo, veiculos[registo].tipoveiculo, veiculos[registo].marca, veiculos[registo].modelo, veiculos[registo].matricula, veiculos[registo].datamatricula, veiculos[registo].custopkm, veiculos[registo].valorreservacombustivel, veiculos[registo].consumomedio);
				
				printf("\nDeseja realmente alterar o registo? (s/n): ");
				scanf(" %c", &confirma);
				
				if (confirma == 's' || confirma == 'S') {
					// Volta a pedir os dados do veiculo para o registo selecionado
					printf("\nID: ");
					scanf("%i", &veiculos[registo].idveiculo);
					printf("\nTipo de veiculo: ");
					int numelementos = sizeof(tipoveiculos)/sizeof(tipoveiculos[0]);
					for (int x = 0; x < numelementos; x++) {
						printf("[%i] %s", x, tipoveiculos[x].descricao);
					}
					printf("\nSelecione o tipo de veiculo: ");
					scanf("%i", &opcaotipoveiculo);
					if (opcaotipoveiculo <= numelementos) {
						int tamanhodestino = sizeof(tipoveiculos[opcaotipoveiculo].descricao);
						strncpy(veiculos[registo].tipoveiculo, tipoveiculos[opcaotipoveiculo].descricao, tamanhodestino);
						printf("Tipo de veiculo: %s",tipoveiculos[opcaotipoveiculo].descricao);
					}
					printf("\nMarca: ");
					scanf("%s", veiculos[registo].marca);
					printf("\nModelo: ");
					scanf("%s", veiculos[registo].modelo);
					printf("\nMatricula (xx-xx-xx): ");
					scanf("%s", veiculos[registo].matricula);
					printf("\nData da matricula (ddmmaaaa): ");
					scanf("%i", &veiculos[registo].datamatricula);
					printf("\nCusto por Km: ");
					scanf("%f", &veiculos[registo].custopkm);
					printf("\nValor da reserva de combustivel: ");
					scanf("%f", &veiculos[registo].valorreservacombustivel);
					printf("\nConsumo medio: ");
					scanf("%f", &veiculos[registo].consumomedio);
					
					// Fecha ficheiro
					fclose(ficheiro);
					
					// Regista novamente os dados da array em ficheiro já sem com o registo atualizado
					ficheiro = fopen("veiculobd.txt", "w");
					
					for (j = 0; j < tamanhoarray; j++) {
						fprintf(ficheiro, "%i, %s, %s, %s, %s, %i, %f, %f, %f\n", veiculos[j].idveiculo, veiculos[j].tipoveiculo, veiculos[j].marca, veiculos[j].modelo, veiculos[j].matricula, veiculos[j].datamatricula, veiculos[j].custopkm, veiculos[j].valorreservacombustivel, veiculos[j].consumomedio);
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


