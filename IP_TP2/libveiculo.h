//
//  libveiculo.h
//  IP_TP2
//
//  Created by Fernando Carvalho on 22/01/18.
//  Copyright © 2018 FC. All rights reserved.
//

#include "libcomum.h"

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
veiculo listaveiculo(void);

int insereveiculo(int idveiculo, int tipoveiculo, char marca[], char modelo[], char matricula[], int datamatricula, float custopkm, float valorreservacombustivel, float consumomedio){
	FILE *ficheiro;
	
	ficheiro = fopen("veiculobd.txt", "a+");
	if(ficheiro == NULL)
	{
		ficheiro = fopen("veiculobd.txt", "w");
	}
	
	fprintf(ficheiro, "%i %i %s %s %s %i %.2f %.2f %.2f\n", idveiculo, tipoveiculo, marca, modelo, matricula, datamatricula, custopkm, valorreservacombustivel, consumomedio);
	fclose(ficheiro);
	return 0;
}

void listaveiculo(){
	FILE *ficheiro;
	veiculo veiculos[10000];
	int ch = 0, i = 0;
	
	ficheiro = fopen("veiculobd.txt", "r");
	if(ficheiro == NULL)
	{
		printf("Houve uma problemazeco na leitura do ficheiro!");
		exit(1);
	}
	
	while(!feof(ficheiro))
	{
		ch = fgetc(ficheiro);
		if(ch == '\n')
		{
			i++;
		}
	}
	
		for (int j = 0; j < i; j++) {
			fscanf(ficheiro, "%i %i %s %s %s %i %f %f %f\n", &veiculos[j].idveiculo, &veiculos[j].tipoveiculo, veiculos[j].marca, veiculos[j].modelo, veiculos[j].matricula, &veiculos[j].datamatricula, &veiculos[j].custopkm, &veiculos[j].valorreservacombustivel, &veiculos[j].consumomedio);
		}
	

	return veiculos;
}

