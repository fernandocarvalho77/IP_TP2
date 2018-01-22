//
//  libveiculo.h
//  IP_TP2
//
//  Created by Fernando Carvalho on 22/01/18.
//  Copyright © 2018 FC. All rights reserved.
//

#ifndef libveiculo_h
#define libveiculo_h
#include "libcomum.h"

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

int insereveiculo(void);
int alteraveiculo(int);
int eliminaveiculo(int);
int listaveiculo(void);

int insereveiculo(){
	int i = testaficheirodb("veiculobd.txt");
	
	if (i == 0) {
		printf("ficheiro criado");
	} else {
		printf("ficheiro já existe");
	}
	return 0;
}

#endif /* libveiculo_h */
