//
//  main.c
//  IP_TP2
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libcomum.h"
#include "libveiculo.h"
#include "libmotorista.h"
#include "libviagem.h"

// Declacao de funcoes
void menu(void);
void menuveiculos(void);
void menuviaturas(void);
void menumotoristas(void);
void menuviagens(void);
void menuestatistica(void);
void registaveiculo(void);
void registamotorista(void);
void registaviagem(void);

// Funcao do tipo void que mostra no ecra o menu principal
void menu(){
	char opcao = ' ';
	
	do {
		printf("\nGestao de Veiculos do Quartel de Bombeiros XTPOZ");
		printf("\nOpcoes");
		printf("\nA - Veiculos");
		printf("\nB - Motoristas");
		printf("\nC - Viagens");
		printf("\nD - Estatistica");
		printf("\nQ - Sai\n");
		scanf(" %c", &opcao);
		
		switch (opcao){
			case 'a':;
			case 'A':
				menuveiculos();
				break;
			case 'b':;
			case 'B':
				menumotoristas();
				break;
			case 'c':;
			case 'C':
				menuviagens();
				break;
			case 'd':;
			case 'D':
				menuestatistica();
				break;
			case 'q':;
			case 'Q': return;
			default:
				printf("Opcao errada, que tal escolher uma das apresentadas, obrigado!");
				break;
		};
	} while (opcao != 'q' || opcao != 'Q');
}

// Funcao do tipo void que mostra no ecra o menu de gestao dos veiculos
void menuveiculos(){
	char opcao = ' ';
	
	do {
		printf("\nMenu Veiculos");
		printf("\nOpcoes");
		printf("\nA - Inserir");
		printf("\nB - Alterar");
		printf("\nC - Apagar");
		printf("\nD - Listar");
		printf("\nE - Tipo de veiculos");
		printf("\nQ - <- Menu anterior\n");
		scanf(" %c", &opcao);
		
		switch (opcao){
			case 'a':;
			case 'A': registaveiculo();
				break;
			case 'b':;
			case 'B': alteraveiculo();
				break;
			case 'c':;
			case 'C': eliminaveiculo();
				break;
			case 'd':;
			case 'D': listaveiculo();
				break;
			case 'E':
				break;
			case 'q':;
			case 'Q': return;
			default:
				printf("Opcao errada, que tal escolher uma das apresentadas, obrigado!");
				break;
		};
	} while (opcao != 'q' || opcao != 'Q');
}

// Funcao do tipo void que mostra no ecra o menu de gestao dos motoristas
void menumotoristas(){
	char opcao = ' ';
	
	do {
		printf("\nMenu Motoristas");
		printf("\nOpcoes");
		printf("\nA - Inserir");
		printf("\nB - Alterar");
		printf("\nC - Apagar");
		printf("\nD - Listar");
		printf("\nQ - <- Menu anterior\n");
		scanf(" %c", &opcao);
		
		switch (opcao){
			case 'a':;
			case 'A': registamotorista();
				break;
			case 'b':;
				case 'B': alteramotorista();
				break;
			case 'c':;
			case 'C':eliminamotorista();
				break;
			case 'd':;
			case 'D':listamotorista();
				break;
			case 'q':;
			case 'Q': return;
			default:
				printf("Opcao errada, que tal escolher uma das apresentadas, obrigado!");
				break;
		};
	} while (opcao != 'q' || opcao != 'Q');
}

// Funcao do tipo void que mostra no ecra o menu de gestao de viagens
void menuviagens(){
	char opcao = ' ';
	
	do {
		printf("\nMenu Viagens");
		printf("\nOpcoes");
		printf("\nA - Inserir");
		printf("\nB - Listar");
		printf("\nQ - <- Menu anterior\n");
		scanf(" %c", &opcao);
		
		switch (opcao){
			case 'a':;
			case 'A': registaviagem();
				break;
			case 'b':;
			case 'B': listaviagem();
				break;
			case 'q':;
			case 'Q': return;
			default:
				printf("Opcao errada, que tal escolher uma das apresentadas, obrigado!");
				break;
		};
	} while (opcao != 'q' || opcao != 'Q');
}

// Funcao do tipo void que mostra no ecra o menu de gestao dos dados estatisticos
void menuestatistica(){
	char opcao = ' ';
	
	do {
		printf("\nMenu Estatistica");
		printf("\nOpcoes");
		printf("\nA - Numero total de viagens e Km (Veiculos e motoristas)");
		printf("\nB - Numero medio de Km por viagem (Veiculos)");
		printf("\nC - Custo medio por viagem (Veiculos)");
		printf("\nD - Distancia");
		printf("\nE - Viagens");
		printf("\nF - Viagens");
		printf("\nG - Estatistica");
		printf("\nQ - Sai\n");
		scanf(" %c", &opcao);
		
		switch (opcao){
			case 'A':
				break;
			case 'B':
				break;
			case 'C':
				break;
			case 'D':
				break;
			case 'E':
				break;
			case 'F':
				break;
			case 'G':
				break;
			case 'q':;
			case 'Q': return;
			default:
				printf("Opcao errada, que tal escolher uma das apresentadas, obrigado!");
				break;
		};
	} while (opcao != 'q' || opcao != 'Q');
}

// Funcao do tipo void que permite registar os veiculos
void registaveiculo(){
	// Declaracao de variaveis da funcao
	char opcao = ' ';
	veiculo veiculos[MAXVEICULOS];
	int i = 0, j = 0, x = 0, resultado = 0, opcaotipoveiculo = 0;
	
	do {
		printf("\nID: ");
		scanf("%i", &veiculos[i].idveiculo);
		// Bloco que permite a obtencao dos valores da estrutura tipoveiculos
		printf("\nTipo de veiculo: ");
		int numelementos = sizeof(tipoveiculos)/sizeof(tipoveiculos[0]);
		for (x = 0; x < numelementos; x++) {
			printf("[%i] %s", x, tipoveiculos[x].descricao);
		}
		printf("\nSelecione o tipo de veiculo: ");
		scanf("%i", &opcaotipoveiculo);
		if (opcaotipoveiculo <= numelementos) {
			int tamanhodestino = sizeof(tipoveiculos[opcaotipoveiculo].descricao);
			// Copia os dados do elemento "descricao" da array "tipoveiculos" para o elemento "tipoveiculo" da array "veiculos"
			strncpy(veiculos[i].tipoveiculo, tipoveiculos[opcaotipoveiculo].descricao, tamanhodestino);
			printf("Tipo de veiculo: %s",tipoveiculos[opcaotipoveiculo].descricao);
		}
		printf("\nMarca: ");
		scanf("%s", veiculos[i].marca);
		printf("\nModelo: ");
		scanf("%s", veiculos[i].modelo);
		printf("\nMatricula (xx-xx-xx): ");
		scanf("%s", veiculos[i].matricula);
		printf("\nData da matricula (ddmmaaaa): ");
		scanf("%i", &veiculos[i].datamatricula);
		printf("\nCusto por Km: ");
		scanf("%f", &veiculos[i].custopkm);
		printf("\nValor da reserva de combustivel: ");
		scanf("%f", &veiculos[i].valorreservacombustivel);
		printf("\nConsumo medio: ");
		scanf("%f", &veiculos[i].consumomedio);
		i++;
		printf("\nDeseja continuar a registar veiculos? (s/n): ");
		scanf(" %c", &opcao);
	} while (opcao != 'n');
	
	if (i > 0) {
		for (j = 0; j < i; j++) {
			//	Regista os valores da array veiculos em ficheiro usando a funcao "insereveiculo"
			resultado = insereveiculo(veiculos[j].idveiculo, veiculos[j].tipoveiculo, veiculos[j].marca, veiculos[j].modelo, veiculos[j].matricula, veiculos[j].datamatricula, veiculos[j].custopkm, veiculos[j].valorreservacombustivel, veiculos[j].consumomedio);
			
			if (resultado != 0) {
				printf("\nProblema no registo do veiculo %d", veiculos[j].idveiculo);
			}
		}
	}
	return;
}

// Funcao do tipo void que permite registar os motoristas
void registamotorista(){
	char opcao = ' ';
	motorista motoristas[MAXMOTORISTAS];
	int i = 0;
	int j = 0;
	int resultado = 0;
	
	do {
		printf("\nIDMotorista: ");
		scanf("%i", &motoristas[i].idmotorista);
		printf("\nNome: ");
		gets(motoristas[i].nome);
		printf("\nApelido: ");
		gets(motoristas[i].apelido);
		printf("\nNIF: ");
		scanf("%i", &motoristas[i].nif);
		printf("\nNumero de telefone: ");
		scanf("%i", &motoristas[i].tlf);
		
		i++;
		printf("\nDeseja continuar a registar motoristas? (s/n): ");
		scanf(" %c", &opcao);
	} while (opcao != 'n');
	
	if (i > 0) {
		for (j = 0; j < i; j++) {
			resultado = inseremotorista(motoristas[j].idmotorista,motoristas[j].nome,motoristas[j].apelido, motoristas[j].nif,motoristas[j].tlf);
			
			if (resultado != 0) {
				printf("\nProblema no registo do motorista %s", motoristas[j].nome);
			}
		}
	}
	return;
}

// Funcao do tipo void que permite registar as viagens
void registaviagem(){
	char opcao = ' ';
	viagem viagens[MAXVIAGENS];
	int i = 0, j = 0, x = 0, resultado = 0, opcaotipoviagem = 0;

	do {
		printf("\nTipo de viagem: ");
		int numelementos = sizeof(tipoviagens)/sizeof(tipoviagens[0]);
		for (x = 0; x < numelementos; x++) {
			printf("[%i] %s", x, tipoviagens[x].descricao);
		}
		printf("\nSelecione o tipo de viagem: ");
		scanf("%i", &opcaotipoviagem);
		if (opcaotipoviagem <= numelementos) {
			int tamanhodestino = sizeof(tipoviagens[opcaotipoviagem].descricao);
			strncpy(viagens[i].tipoviagem, tipoviagens[opcaotipoviagem].descricao, tamanhodestino);
			printf("Tipo de viagem: %s",tipoviagens[opcaotipoviagem].descricao);
		}
		printf("\nData (ddmmaaaa): ");
		scanf("%i", &viagens[i].data);
		printf("\nHora (hhmm): ");
		scanf("%i", &viagens[i].hora);
		printf("\nVeiculo : ");
		scanf("%s", viagens[i].veiculo);
		printf("\nMotorista: ");
		scanf("%s", viagens[i].motorista);
		printf("\nDistancia (km): ");
		scanf("%f", &viagens[i].distancia);
		printf("\nCusto (Euros): ");
		scanf("%f", &viagens[i].custo);
		i++;
		printf("\nDeseja continuar a registar viagens? (s/n): ");
		scanf(" %c", &opcao);
	} while (opcao != 'n');

	if (i > 0) {
		for (j = 0; j < i; j++) {
			resultado = insereviagem(viagens[j].tipoviagem, viagens[j].data, viagens[j].hora, viagens[j].veiculo, viagens[j].motorista, viagens[j].distancia, viagens[j].custo);

			if (resultado != 0) {
				printf("\nProblema no registo da viagem");
			}
		}
	}
	return;
}

// Funcao principal 
int main() {
	menu();
	return 0;
}
