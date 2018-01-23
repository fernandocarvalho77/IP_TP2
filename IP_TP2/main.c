//
//  main.c
//  IP_TP2
//
//  Created by Fernando Carvalho on 16/01/18.
//  Copyright © 2018 FC. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libveiculo.h"

void menu(void);
void menuveiculos(void);
void menuviaturas(void);
void menumotoristas(void);
void menuviagens(void);
void menuestatistica(void);

void registaveiculo(void);
void listaveiculos(void);

struct tipoveiculo{
	int id;
	char descricao[100];
};


struct viagem{
	int id;
	int tipoviagem;
	int data;
	int hora;
	int veiculo;
	int motorista;
	float distancia;
	float custo;
};

struct tipoviagem{
	int id;
	char descricao[100];
};

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
			case 'A':
				registaveiculo();
				break;
			case 'B':
				break;
			case 'C':
				break;
			case 'd':;
			case 'D':listaveiculos();
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
			case 'A':
				break;
			case 'B':
				break;
			case 'C':
				break;
			case 'D':
				break;
			case 'q':;
			case 'Q': return;
			default:
				printf("Opcao errada, que tal escolher uma das apresentadas, obrigado!");
				break;
		};
	} while (opcao != 'q' || opcao != 'Q');
}

void menuviagens(){
	char opcao = ' ';
	
	do {
		printf("\nMenu Viagens");
		printf("\nOpcoes");
		printf("\nA - Inserir");
		printf("\nB - Listar");
		printf("\nC - Tipo de Viagem");
		printf("\nQ - <- Menu anterior\n");
		scanf(" %c", &opcao);
		
		switch (opcao){
			case 'A':
				break;
			case 'B':
				break;
			case 'C':
				break;
			case 'q':;
			case 'Q': return;
			default:
				printf("Opcao errada, que tal escolher uma das apresentadas, obrigado!");
				break;
		};
	} while (opcao != 'q' || opcao != 'Q');
}

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

void registaveiculo(){
	char opcao = ' ';
	veiculo veiculos[1000];
	int i = 0;
	
	do {
		printf("\nID: ");
		scanf("%d", &veiculos[i].idveiculo);
		printf("\nTipo de veiculo: ");
		scanf("%d", &veiculos[i].tipoveiculo);
		printf("\nMarca: ");
		scanf("%s", veiculos[i].marca);
		printf("\nModelo: ");
		scanf("%s", veiculos[i].modelo);
		printf("\nMatricula (xx-xx-xx): ");
		scanf("%s", veiculos[i].matricula);
		printf("\nData da matricula (ddmmaaaa): ");
		scanf("%d", &veiculos[i].datamatricula);
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
		for (int j = 0; j < i; j++) {
			int resultado = insereveiculo(veiculos[j].idveiculo, veiculos[j].tipoveiculo, veiculos[j].marca, veiculos[j].modelo, veiculos[j].matricula, veiculos[j].datamatricula, veiculos[j].custopkm, veiculos[j].valorreservacombustivel, veiculos[j].consumomedio);
			if (resultado != 0) {
				printf("\nProblema no registo do veiculo %d", veiculos[j].idveiculo);
			}
		}
	}
	return;
}

void listaveiculos(){
//	veiculo lista[1000] = listaveiculo();
	
//	for (int i = 0; sizeof(lista) ; i++) {
//		printf("%i %i %s %s %s %i %.2f %.2f %.2f\n", lista[i].idveiculo, lista[i].tipoveiculo, lista[i].marca, lista[i].modelo, lista[i].matricula, lista[i].datamatricula, lista[i].custopkm, lista[i].valorreservacombustivel, lista[i].consumomedio);
//	}
}

int main() {
	menu();
	return 0;
}
