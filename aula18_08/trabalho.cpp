#include <stdio.h>
#include <string.h>

int main(){
	
	FILE *pFile;
	char nome[50];
	char compNome[50];
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
	
	
	
	// C
	
	printf("Digite o nome que deseja verificar: ");
	gets(compNome);
	
	while(fscanf(pFile, "%s", nome) != NULL){
			if(strcmp(nome, compNome) == 0){
				printf("Nome encontrado %s", compNome);
				
			}
			else{
				printf("Nome não existe!");
			}
		}
		
		fclose(pFile);
		
		
		
}
