//
//  libcomum.h
//  IP_TP2
//
//  Created by Fernando Carvalho on 22/01/18.
//  Copyright © 2018 FC. All rights reserved.
//

#ifndef libcomum_h
#define libcomum_h

int testaficheirodb(char[]);

int testaficheirodb(char nomeficheiro[]){
	FILE *ficheiro;

	ficheiro = fopen(nomeficheiro,"r");
	if(ficheiro == NULL){
		ficheiro = fopen(nomeficheiro, "ab+");
		fclose(ficheiro);
		return 1;
	} else {
		return 0;
	}
}

#endif /* libcomum_h */
