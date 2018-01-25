//
//  libcomum.h
//  IP_TP2
//

int linhasficheiro(FILE*);
// Funcao do tipo inteiro que devolve o numero de linhas do ficheiro
int linhasficheiro(FILE *ficheiro){
	int i = 0, ml = 0;
	
	//	Enquanto não encontrar o final do ficheiro le todos os caracteres individualmente até encontrar o caractere de mudança de linha "\n"
	while(!feof(ficheiro))
	{
		ml = fgetc(ficheiro);
		if(ml == '\n')
		{
			i++;
		}
	}
	// Aponta para o inicio do ficheiro
	rewind(ficheiro);
	
	return i;
}


