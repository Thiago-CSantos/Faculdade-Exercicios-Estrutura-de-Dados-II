#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

struct Produto{
	int codigo;
	char descricao[100];
	char categoria[100];
	int quantidadeEstoque;
	float precoUnitario;
	
	struct Produto *proximo;
};

FILE *pFile = NULL;
// define o nó inicial da lista
struct Produto *inicio=NULL;

// 1-Listar todos os produtos.
void listar_todos_produtos(){
	
	struct Produto *novo = (struct Produto*)malloc(sizeof(struct Produto));
	
	int codigo;
	pFile = fopen("estoque.txt", "r");
	
	if(pFile != NULL){
		
		while(fscanf(pFile, "%d ", &codigo) != EOF){
				
			novo->codigo=codigo;
				
			fscanf(pFile, "%s ", novo->descricao);
			fscanf(pFile, "%s ", novo->categoria);
			fscanf(pFile, "%d ", &novo->quantidadeEstoque);
			fscanf(pFile, "%f ", &novo->precoUnitario);
			
			novo->proximo=inicio;
			inicio=novo;
			
			if(inicio->quantidadeEstoque>0){
				printf("\n");
				printf("%d", inicio->codigo);	
				printf(" %s", inicio->descricao);
				printf(" %s", inicio->categoria);
				printf(" %d ", inicio->quantidadeEstoque);
				printf(" %f ", inicio->precoUnitario);
			}	
		}	
		fclose(pFile);

	}
	else{
		printf("Erro ao abrir o arquivo de estoque->\n");
	}
	
}


//2 – Buscar produto de acordo com categoria.
void listar_produtos_categoria(char categorias[100]){
	struct Produto *novo = (struct Produto*)malloc(sizeof(struct Produto));
	int codigo;
	pFile = fopen("estoque.txt", "r");
	
	if(pFile != NULL){
		
		while(fscanf(pFile, "%d ", &codigo) != EOF){
				
			novo->codigo=codigo;
				
			fscanf(pFile, "%s ", novo->descricao);
			fscanf(pFile, "%s ", novo->categoria);
			fscanf(pFile, "%d ", &novo->quantidadeEstoque);
			fscanf(pFile, "%f ", &novo->precoUnitario);
			
			novo->proximo=inicio;
			inicio=novo;
			
			if(strcmp(categorias, inicio->categoria)==0){
				printf("\n");
				printf("%d", inicio->codigo);	
				printf(" %s", inicio->descricao);
				printf(" %s", inicio->categoria);
				printf(" %d ", inicio->quantidadeEstoque);
				printf(" %f ", inicio->precoUnitario);
			}	
		}	
		fclose(pFile);

	}
	else{
		printf("Erro ao abrir o arquivo de estoque->\n");
	}
}


int main(){
	
	//listar_todos_produtos();
	listar_produtos_categoria("alimenticio");
}
