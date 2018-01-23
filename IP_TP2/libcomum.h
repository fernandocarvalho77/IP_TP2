//
//  libcomum.h
//  IP_TP2
//
//  Created by Fernando Carvalho on 22/01/18.
//  Copyright © 2018 FC. All rights reserved.
//

int testaficheiro(char[]);
int linhasficheiro(FILE*);

int testaficheiro(char nomeficheiro[]){
	FILE *ficheiro;

	ficheiro = fopen(nomeficheiro, "r");
	if(ficheiro == NULL){
		ficheiro = fopen(nomeficheiro, "w");
		fclose(ficheiro);
		return 0;
	} else {
		return 1;
	}
}

int linhasficheiro(FILE *ficheiro){
	int i = 0, ml = 0;
	
	while(!feof(ficheiro))
	{
		ml = fgetc(ficheiro);
		if(ml == '\n')
		{
			i++;
		}
	}
	rewind(ficheiro);
	
	return i;
}


