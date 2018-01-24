//
//  libveiculo.h
//  IP_TP2
//
//  Created by Fernando Carvalho on 22/01/18.
//  Copyright © 2018 FC. All rights reserved.
//

#include "libcomum.h"
#define MAXVEICULOS 1000

typedef struct veiculo{
	int idveiculo;
	int tipoveiculo;
	char marca[50];
	char modelo[50];
	char matricula[9];
	int datamatricula;
	float custopkm;
	float valorreservacombustivel;
	float consumomedio;
} veiculo, *ptrveiculo;

int insereveiculo(int, int, char[], char[], char[], int, float, float, float);
int alteraveiculo(int);
int eliminaveiculo(int);
void listaveiculo(void);
//void listaveiculo(void);

int insereveiculo(int idveiculo, int tipoveiculo, char marca[], char modelo[], char matricula[], int datamatricula, float custopkm, float valorreservacombustivel, float consumomedio){
	FILE *ficheiro;
	
	ficheiro = fopen("veiculobd.txt", "a+");
	if(ficheiro == NULL)
	{
		ficheiro = fopen("veiculobd.txt", "w");
	}
	
	fprintf(ficheiro, "%i %i %s %s %s %i %f %f %f\n", idveiculo, tipoveiculo, marca, modelo, matricula, datamatricula, custopkm, valorreservacombustivel, consumomedio);
	fclose(ficheiro);
	return 0;
}

void listaveiculo(){
	FILE *ficheiro;
	int i = 0, j = 0;
	
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
				fscanf(ficheiro, "%i %i %s %s %s %i %f %f %f\n", &veiculos[j].idveiculo, &veiculos[j].tipoveiculo, veiculos[j].marca, veiculos[j].modelo, veiculos[j].matricula, &veiculos[j].datamatricula, &veiculos[j].custopkm, &veiculos[j].valorreservacombustivel, &veiculos[j].consumomedio);
			}
			
			unsigned long tamanhoarray = sizeof(veiculos)/sizeof(veiculos[0]);
			
			if (tamanhoarray > 0) {
				printf("\nidveiculo tipoveiculo marca modelo matricula datamatricula custopkm valorreservacombustivel consumomedio\n");
				for (int x = 0; x < tamanhoarray; x++) {
					printf("%i %i %s %s %s %i %.2f %.2f %.2f\n", veiculos[x].idveiculo, veiculos[x].tipoveiculo, veiculos[x].marca, veiculos[x].modelo, veiculos[x].matricula, veiculos[x].datamatricula, veiculos[x].custopkm, veiculos[x].valorreservacombustivel, veiculos[x].consumomedio);
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

