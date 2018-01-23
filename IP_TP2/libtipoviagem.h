//
//  libtipoviagem.h
//  IP_TP2
//
//  Created by Fernando Carvalho on 22/01/18.
//  Copyright © 2018 FC. All rights reserved.
//

#include "libcomum.h"

typedef struct tipoviagem{
	int idtipoviagem;
	char descricao[100];
}tipoviagem, *ptrtipoviagem;

int inseretipoviagem(int, char[], char[], int, int);
int alteratipoviagem(int);
int eliminatipoviagem(int);
veiculo listatipoviagem(void);

int inseretipoviagem(int idtipoviagem, char nome[], char apelido[], int nif, int tlf){
	FILE *ficheiro;
	
	ficheiro = fopen("tipoviagembd.txt", "a+");
	if(ficheiro == NULL)
	{
		ficheiro = fopen("tipoviagembd.txt", "w");
	}
	
	fprintf(ficheiro, "%i %s %s %s %i %i\n", idtipoviagem, nome, apelido, nif, tlf);
	fclose(ficheiro);
	return 0;
}

void listatipoviagem(){
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
	
//		for (int j = 0; j < i; j++) {
//			fscanf(ficheiro, "%i %i %s %s %s %i %f %f %f\n", &veiculos[j].idveiculo, &veiculos[j].tipoveiculo, veiculos[j].marca, veiculos[j].modelo, veiculos[j].matricula, &veiculos[j].datamatricula, &veiculos[j].custopkm, &veiculos[j].valorreservacombustivel, &veiculos[j].consumomedio);
//		}
	

	return veiculos;
}

