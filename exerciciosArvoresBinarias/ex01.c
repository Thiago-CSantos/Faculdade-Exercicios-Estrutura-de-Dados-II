#include <stdio.h>
#include <stdlib.h>
#include <conio.h> 

struct No{
	int dado;
	struct No *esquerda;
	struct No *direita;
};

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
		
		if(valor>(*raiz)->dado){
			insere(&((*raiz)->direita), valor);
		}
		else if(valor<(*raiz)->dado){
			insere(&((*raiz)->esquerda), valor);
		}
		else{
			return 0;
		}
		
	}
}

void preOrdem(struct No *raiz){
	if(raiz!=NULL){
		printf("%d\n", raiz->dado);
		
		preOrdem(raiz->esquerda);
		preOrdem(raiz->direita);
	}
}

struct No *ultimoNoEsquerda(struct No *raiz){
	if(raiz == NULL){
		return NULL;
	}
	
	while(raiz->esquerda != NULL){
		raiz = raiz->esquerda;
	}
	
	return raiz;
}

struct No *ultimoNoDireita(struct No *raiz){
	if(raiz == NULL){
		return NULL;
	}
	
	while(raiz->direita != NULL){
		raiz = raiz->direita;
	}
	
	return raiz;
}

int main(){
	struct No * raiz = NULL;
	insere(&raiz, 7);
	insere(&raiz, 5);
	insere(&raiz, 12);
	insere(&raiz, 4);
	insere(&raiz, 6);
	
	preOrdem(raiz);
	
	printf("Ultimo No a esquerda\n");
	struct No *ultimoEsquerda = ultimoNoEsquerda(raiz);
	
	if (ultimoEsquerda != NULL) {
        printf("O ultimo no mais a esquerda tem valor: %d\n", ultimoEsquerda->dado);
    } else {
        printf("A arvore esta vazia.\n");
    }
    printf("Ultimo No a direita\n");
	struct No *ultimoDireita = ultimoNoDireita(raiz);
	
	if (ultimoDireita != NULL) {
        printf("O ultimo no mais a direita tem valor: %d\n", ultimoDireita->dado);
    } else {
        printf("A arvore esta vazia.\n");
    }
    
    
}
