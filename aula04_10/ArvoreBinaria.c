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

int main(){
	//inser��o de trez valores
	insere(&raiz, 2);
	insere(&raiz, 1);
	insere(&raiz, 3);
	
	preOrdem(raiz);
	
}
