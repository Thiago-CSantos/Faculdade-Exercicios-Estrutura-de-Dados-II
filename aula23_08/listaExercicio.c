#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>


	//estrutura do N�
	//estrutura das informa��es a serem armazenadas
	//no N� da lista
	struct Embaixador{
		char nome[50];
		char ra[8];
		char nomeCurso[50];
		
		struct Embaixador *proximo;
		
	};
		
	FILE *pFile = NULL;
		
		
	//define i n� inicial da lista
	struct Embaixador *inicio = NULL;
	
	//fun��o para carregar o arquivo de embaixadores
	void leEmbaixadores(){
		
		
		char nome[50];
		
		//Tentar abrir o arquivo
		pFile = fopen("embaixadores.txt", "r");
		
		if(pFile != NULL){
			//Enquanto houver dados:
			while(fscanf(pFile, "%s", nome)!=EOF){
				
				//colocar na lista encadeada	
				
				//Algoritmo de inser��o no inicio
				//Criar um novo n�
				struct Embaixador *novo = malloc(sizeof(struct Embaixador)); // struct Embaixador *novo = (struct Embaixador*)malloc(sizeof(struct Embaixador));
				
				//colocar os dados lidos no novo n�
				strcpy(novo->nome, nome);
				
				// -> Ler o nome, ra, curso
				fscanf(pFile,"%s", novo->ra);
				fscanf(pFile,"%s", novo->nomeCurso);
				novo->proximo=inicio;
				inicio=novo;
			}
		}
		
		//fechar o arquivo
		fclose(pFile);
	}


int main(){
	
	leEmbaixadores();
	
}
