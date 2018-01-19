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

struct veiculo{
	int id;
	int tipoveiculo;
	char marca;
	char modelo;
	char matricula;
	int datamatricula;
	float custopkm;
	float valorreservacombustivel;
	float consumomedio;
};

struct tipoveiculo{
	int id;
	char descricao;
};

struct motorista{
	int id;
	char nome;
	char apelido;
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
	int descricao;
};

void menu(){
	char opcao = ' ';
	
	printf("\nGestao de Veiculos do Quartel de Bombeiros XTPOZ");
	printf("\nOpcoes");
	printf("\nA - Veiculos");
	printf("\nB - Motoristas");
	printf("\nC - Viagens");
	printf("\nD - Estatistica");
	printf("\nQ - Sai");
	scanf("%c", &opcao);
	
	do {
		switch (opcao){
		case 'A':
				break;
		case 'B':
				break;
		case 'C':
				break;
		case 'D':
				break;
		default:
				printf("Opcao errada, que tal escolher uma das apresentadas, obrigado!");
				break;
		};
		
	} while (opcao != 'q');
}

void menuveiculos(){
	char opcao = ' ';
	
	printf("\nMenu Veiculos");
	printf("\nOpcoes");
	printf("\nA - Inserir");
	printf("\nB - Alterar");
	printf("\nC - Apagar");
	printf("\nD - Listar");
	printf("\nE - Tipo de veiculos");
	printf("\nQ - <- Menu anterior");
	scanf("%c", &opcao);
	
	do {
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
			default:
				printf("Opcao errada, que tal escolher uma das apresentadas, obrigado!");
				break;
		};
		
	} while (opcao != 'q');
}

void menumotoristas(){
	char opcao = ' ';
	
	printf("\nMenu Motoristas");
	printf("\nOpcoes");
	printf("\nA - Inserir");
	printf("\nB - Alterar");
	printf("\nC - Apagar");
	printf("\nD - Listar");
	printf("\nQ - <- Menu anterior");
	scanf("%c", &opcao);
	
	do {
		switch (opcao){
			case 'A':
				
				break;
			case 'B':
				break;
			case 'C':
				break;
			case 'D':
				break;
			default:
				printf("Opcao errada, que tal escolher uma das apresentadas, obrigado!");
				break;
		};
		
	} while (opcao != 'q');
}

void menuviagens(){
	char opcao = ' ';
	
	printf("\nMenu Viagens");
	printf("\nOpcoes");
	printf("\nA - Inserir");
	printf("\nB - Listar");
	printf("\nC - Tipo de Viagem");
	printf("\nQ - <- Menu anterior");
	scanf("%c", &opcao);
	
	do {
		switch (opcao){
			case 'A':
				break;
			case 'B':
				break;
			case 'C':
				break;
			case 'D':
				break;
			default:
				printf("Opcao errada, que tal escolher uma das apresentadas, obrigado!");
				break;
		};
		
	} while (opcao != 'q');
}

void menuestatistica(){
	char opcao = ' ';
	
	printf("\nMenu Estatistica");
	printf("\nOpcoes");
	printf("\nA - Numero total de viagens e Km (Veiculos e motoristas)");
	printf("\nB - Numero medio de Km por viagem (Veiculos)");
	printf("\nC - Custo medio por viagem (Veiculos)");
	printf("\nC - Distancia");
	printf("\nC - Viagens");
	printf("\nC - Viagens");
	printf("\nD - Estatistica");
	printf("\nQ - Sai");
	scanf("%c", &opcao);
	
	do {
		switch (opcao){
			case 'A':				
				break;
			case 'B':
				break;
			case 'C':
				break;
			case 'D':
				break;
			default:
				printf("Opcao errada, que tal escolher uma das apresentadas, obrigado!");
				break;
		};
		
	} while (opcao != 'q');
}
int main(int argc, const char * argv[]) {
	// insert code here...
	printf("Hello, World!\n");
	return 0;
}
