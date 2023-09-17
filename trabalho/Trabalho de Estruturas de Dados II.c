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

struct Carrinho{
	struct Produto *produtos;
	int quantidade;
};

FILE *pFile = NULL;

// 1-Listar todos os produtos.
void listar_todos_produtos(){
	
	// define o nó inicial da lista
	struct Produto *inicio=NULL;
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
	// define o nó inicial da lista
	struct Produto *inicio=NULL;
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

//3 – Adicionar produtos em carrinho de compra.
void addCarrinho(int codigoC, int quantidadeC){
    
    struct Produto *inicio=NULL;  
    int codigo;
    
    pFile = fopen("estoque.txt", "r+");
    
    if(pFile!=NULL){
        struct Produto *novo = (struct Produto*)malloc(sizeof(struct Produto));
        struct Carrinho carrinhoCompra;
        // ler o arquivo e mostra-lo
        while(fscanf(pFile, "%d ", &codigo) != EOF){
            
            novo->codigo=codigo;
                
            fscanf(pFile, "%s ", novo->descricao);
            fscanf(pFile, "%s ", novo->categoria);
            fscanf(pFile, "%d ", &novo->quantidadeEstoque);
            fscanf(pFile, "%f ", &novo->precoUnitario);
            
            novo->proximo = inicio;
            inicio = novo;

            if (inicio->codigo == codigoC){
                printf("\n");
                printf("%d", inicio->codigo);
                printf(" %s", inicio->descricao);
                printf(" %s", inicio->categoria);
                printf(" %d ", inicio->quantidadeEstoque);
                printf(" %f ", inicio->precoUnitario);
                
                if(quantidadeC <= inicio->quantidadeEstoque){
                    // inicio->quantidadeEstoque = inicio->quantidadeEstoque - quantidadeC;
                    printf("q%d ", inicio->quantidadeEstoque);

                    carrinhoCompra.quantidade = carrinhoCompra.quantidade + quantidadeC;
                    printf("aqui - %d", carrinhoCompra.quantidade);

                    if(carrinhoCompra.quantidade > inicio->quantidadeEstoque){
                        printf("Quantidade indisponivel");
                    }

                    carrinhoCompra.produtos = inicio;

                    printf("\n%d", carrinhoCompra.produtos->quantidadeEstoque);


                } 
                else{
                    printf("Quantidade indisponivel");
                }
                
            }
          
        }

        fclose(pFile);
    }
}


//4 – Visualizar carrinho de compra.
void visualizar_carrinho(){
	
	struct Carrinho *carrinhoCompra;
	int i=0;
	for(i=0; i<5; i++){
		printf("\n%d", carrinhoCompra[i].produtos->codigo); 
	}
	
}

int main(){
	
	//listar_todos_produtos();
	//listar_produtos_categoria("alimenticio");
	addCarrinho(1,5);
	addCarrinho(1,5);
	visualizar_carrinho();
}
