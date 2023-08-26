#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>
#include <locale.h>


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
//	Imrpime os embaixadores do arquivo e que já estão na lista
	void  listarEmbaixadores(){
		//obter um nó auxiliar
		struct Embaixador *aux = inicio;
		
		//enquanto houver elemento na lista 
		while(aux!= NULL){
			printf("%s:", aux->nome);
			printf("%s-", aux->nomeCurso);
			printf("%s\n", aux->ra);
			//atualiza aux passsando para o proximo elemento
			aux=aux->proximo;
		}
	}
	
	void substituirEmbaixador(){
		char nomeCurso[50];
		
		printf("Digite o curso que deseja substituir: ");
		scanf("%s", nomeCurso);
		
		struct Embaixador *aux = inicio;
		int encontrou = 0;
		
		//enquanto houver elemento na lista 
		while(aux!= NULL){
			if(strcmp(aux->nomeCurso, nomeCurso)==0){
				
				printf("Nome do novo embaixador do curso: ");
				scanf("%s",aux->nomeCurso);
				printf("RA: ");
				scanf("%s", aux->ra);
				encontrou = 1;
				break; //encerra a busca se encontrar os dados a serem alterados
			}
			aux = aux->proximo;
		}
		if(!encontrou){
			printf("Não encontrado");
		}
	}
	
	void atulizarLista(){
		
		pFile = fopen("embaixadores.txt", "w");
		
		struct Embaixador *aux = inicio;
		
		if(pFile != NULL){
			while(aux!=NULL){
				fprintf(pFile,"%s\n%s\n%s\n", aux->nome, aux->ra, aux->nomeCurso);
			}
		}
		fclose(pFile);
	}


int main(){
	setlocale(LC_ALL, "Portuguese");
	
	int escolha = 0;
	leEmbaixadores();
	
	printf("Escolha:\n 1-listar Embaixadores");
	scanf("%d", &escolha);
	
	switch(escolha){
		case 1:
			listarEmbaixadores();
			break;
		default:
			printf("Teste");
			break;
	}
	substituirEmbaixador();
	atulizarLista();
}





