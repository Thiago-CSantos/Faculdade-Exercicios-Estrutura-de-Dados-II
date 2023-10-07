#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

// Implementa��o dos algoritmos de percurso em profundidade

struct No{
	int dado;
	struct No *esquerda;
	struct No *direita;	
};

struct No* raiz = NULL;

void preOrdem(struct No* raiz){
	
	//se houver elemento na �rvore
	if(raiz!= NULL){
		//Passo-1 imprima os dados da raiz
		printf("\n%d", raiz->dado);
		getch();
		//Passo-2 chame o processo pr�-ordem para esquerda
		preOrdem(raiz->esquerda);
		//Passo-3 chame o processo pr�-ordem para a direita
		preOrdem(raiz->direita);
	}
	
}

void inOrdem(struct No *raiz){
	if(raiz!=NULL){
		//esquerda
		inOrdem(raiz->esquerda);
		//volta para raiz e imprimi
		printf("\n%d", raiz->dado);
		//direita
		inOrdem(raiz->direita);
	}
}

void posOrdem(struct No * raiz){
	
	if(raiz!=NULL){
		posOrdem(raiz->esquerda);
	
		posOrdem(raiz->direita);
	
		printf("\nvalo:%d", raiz->dado);
	}
}

/**
	inserir um valor em uma Arvore Binaria Busca
	input: valor a ser inserido
	output: 1 -se foi possivel
			0 se n�o foi
**/

int insere( struct No** raiz, int valor){
	//vereficar se a raiz est� vazia
	if((*raiz)==NULL){
		//ent�o o valor deve ficar nesta
		//raiz
		(*raiz) = malloc(sizeof(struct No));
		
		// ent�o o valor deve ficar nesta
		//raiz
		if((*raiz)!=NULL){
			(*raiz)->dado = valor;
		
			(*raiz)->esquerda = NULL;
			(*raiz)->direita = NULL;
			return 1;
		}
		else{
			return 0;
		}
		
	}
	else{
		
		if(valor>(*raiz)){
			insere(&((*raiz)->direita), valor);
		}
		else if(valor<(*raiz)){
			insere(&((*raiz)->esquerda), valor);
		}
		else{
			return 0;
		}
		
	}
}

/* EX-1
	fazer uma fun��o para dado um valor retornar o n�
	que o contem, se ele estiver na arvore
	caso ele n�o esteja, retorne NULL
*/
struct No* ex1(struct No*raiz, int valor){
		if(raiz!=NULL){
			// vereficar se o valor est� na raiz
			if(raiz->dado == valor){
				return raiz;
			}
			// verefica se o valor � maior ent�o vai para maio
			else{
				if(valor<raiz->dado){
					return ex1(raiz->esquerda,valor);
				}
				else{
					return ex1(raiz->direita,valor);
				}
			}
		}
		
}


/* EX-2
fazer a impress�o da arvore em ordem descendente
*/
void ex2(struct No* raiz){
	if(raiz!=NULL){
		ex2(raiz->direita);
		printf("%d\n", raiz->dado);
		ex2(raiz->esquerda);
		
	}
}

int main(){
	struct No *a;
	//inser��o de trez valores
	insere(&raiz, 7);
	insere(&raiz, 5);
	insere(&raiz, 12);
	insere(&raiz, 4);
	insere(&raiz, 6);
	
//	printf("\npreOrdem\n");
//	preOrdem(raiz);
//	printf("\nposOrdem\n");
//	posOrdem(raiz);
	printf("\ninOrdem");
	inOrdem(raiz);
	
	printf("\nex1:\n");
	if(ex1(raiz, 5) == NULL){
		printf("valor n�o encontrado");
	}
	else{
		printf("valor encontrado");
	}
	
	printf("\nex2:\n");
	ex2(raiz);
}
