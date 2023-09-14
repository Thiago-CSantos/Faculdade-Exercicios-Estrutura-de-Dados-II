#include <stdio.h>
#include <stdlib.h>

struct No{
	int valor;
	struct No *esquerda;
	struct No *direita;
};

int main(){
struct No *raiz = malloc(sizeof(struct No));	
raiz->valor=2;

raiz->direita = malloc(sizeof(struct No));
raiz->direita->valor=7;

raiz->esquerda = malloc(sizeof(struct No));
raiz->esquerda->valor1;

}
