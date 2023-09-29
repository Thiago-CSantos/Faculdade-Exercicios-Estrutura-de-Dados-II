#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

// Implementação dos algoritmos de percurso em profundidade

struct No{
	int dado;
	struct No *esquerda;
	struct No *direita;	
};

void preOrdem(struct No* raiz){
	
	//se houver elemento na árvore
	if(raiz!= NULL){
		//Passo-1 imprima os dados da raiz
		printf("\n%d", raiz->dado);
		getch();
		//Passo-2 chame o processo pré-ordem para esquerda
		preOrdem(raiz->esquerda);
		//Passo-3 chame o processo pré-ordem para a direita
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
		
		printf("valor: ", raiz->dado);
	}
	
}

int main(){
	struct No* raiz = malloc(sizeof(struct No));
	raiz->dado = 1;
	
	raiz->esquerda = malloc(sizeof(struct No));
	raiz->esquerda->dado = 2;
	
	raiz->direita = malloc(sizeof(struct No));
	raiz->direita->dado = 3;
	
	// definir 2 e 3 como folhas
	raiz->esquerda->esquerda = NULL;
	raiz->esquerda->direita = NULL;
	
	raiz->direita->esquerda = NULL;
	raiz->direita->direita = NULL;
	
	//inOrdem(raiz);
	//preOrdem(raiz);
	posOrdem(raiz);
}
