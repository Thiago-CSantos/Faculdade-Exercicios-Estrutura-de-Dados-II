#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

// Implementação dos algoritmos de percurso em profundidade

struct No{
	int dado;
	struct No *esquerda;
	struct No *direita;	
};

struct No* raiz = NULL;

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

/**
	inserir um valor em uma Arvore Binaria Busca
	input: valor a ser inserido
	output: 1 -se foi possivel
			0 se não foi
**/

int insere( struct No** raiz, int valor){
	//vereficar se a raiz está vazia
	if((*raiz)==NULL){
		//então o valor deve ficar nesta
		//raiz
		(*raiz) = malloc(sizeof(struct No));
		
		// então o valor deve ficar nesta
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

int main(){
	//inserção de trez valores
	insere(&raiz, 2);
	insere(&raiz, 1);
	insere(&raiz, 3);
	
	preOrdem(raiz);
	
}
