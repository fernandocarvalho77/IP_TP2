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

void menu(void);
void menuveiculos(void);
void menuviaturas(void);
void menumotoristas(void);
void menuviagens(void);
void menuestatistica(void);

struct veiculo{
	int id;
	int tipoveiculo;
	char marca[50];
	char modelo[50];
	char matricula[8];
	int datamatricula[8];
	float custopkm;
	float valorreservacombustivel;
	float consumomedio;
};

struct tipoveiculo{
	int id;
	char descricao[100];
};

struct motorista{
	int id;
	char nome[100];
	char apelido[50];
	int nif;
	int tlf;
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

int main() {
	menu();
	return 0;
}
