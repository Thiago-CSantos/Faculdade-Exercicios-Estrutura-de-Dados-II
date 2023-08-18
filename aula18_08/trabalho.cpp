#include <stdio.h>

int main(){
	
	FILE *pFile;
	char nome[50];
	int i,j;
	
	// a. ler um arquivo de nomes de pessoas;
	
	pFile=fopen("C:\\Users\\android\\Desktop\\arquivoTeste.txt", "r+");
	
	if(pFile != NULL){
		
		while(fgets(nome, sizeof(nome), pFile) != NULL){
			printf("%s", nome);
		}
		
	}
	
	fclose(pFile);
	
	// b. Adicionar um nome no arquivo;
	
	pFile=fopen("C:\\Users\\android\\Desktop\\arquivoTeste.txt", "a");
	
	if(pFile!=NULL){
		
		printf("Escreva um nome: ");
		gets(nome);
		fprintf(pFile,"%s\n",nome);
		
	}
	
	fclose(pFile);
	
	
}
