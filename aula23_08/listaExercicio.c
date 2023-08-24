#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>


	//estrutura do NÓ
	//estrutura das informações a serem armazenadas
	//no NÓ da lista
	struct Embaixador{
		char nome[50];
		char ra[8];
		char nomeCurso[50];
		
		struct Embaixador *proximo;
		
	};
		
	FILE *pFile = NULL;
		
		
	//define i nó inicial da lista
	struct Embaixador *inicio = NULL;
	
	//função para carregar o arquivo de embaixadores
	void leEmbaixadores(){
		
		
		char nome[50];
		
		//Tentar abrir o arquivo
		pFile = fopen("embaixadores.txt", "r");
		
		if(pFile != NULL){
			//Enquanto houver dados:
			while(fscanf(pFile, "%s", nome)!=EOF){
				
				//colocar na lista encadeada	
				
				//Algoritmo de inserção no inicio
				//Criar um novo nó
				struct Embaixador *novo = malloc(sizeof(struct Embaixador)); // struct Embaixador *novo = (struct Embaixador*)malloc(sizeof(struct Embaixador));
				
				//colocar os dados lidos no novo nó
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
