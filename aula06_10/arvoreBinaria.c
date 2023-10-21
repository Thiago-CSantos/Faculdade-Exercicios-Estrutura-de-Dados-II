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


// fun��o de inser��o

struct No* antecessor(struct No* raiz){
	
	
	if(raiz != NULL){
		// v� para os antecessores
		raiz=raiz->esquerda;
		if(raiz->esquerda !=NULL){
				//procurar o NO mais a direita
			while(raiz->direita!= NULL){
				raiz=raiz->direita;			
			}
			return raiz;
		}
	}
	return NULL;
}


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

/* EX-1
	fazer uma fun��o para dado um valor retornar o n�
	que o contem, se ele estiver na arvore
	caso ele n�o esteja, retorne NULL
*/
struct No* buscar(struct No*raiz, int valor){
		if(raiz!=NULL){
			// vereficar se o valor est� na raiz
			if(raiz->dado == valor){
				return raiz;
			}
			// verefica se o valor � maior ent�o vai para maio
			else{
				if(valor<raiz->dado){
					return buscar(raiz->esquerda,valor);
				}
				else{
					return buscar(raiz->direita,valor);
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

//fun��o que avalia se um N� � folha
int eh_folha(struct No*raiz){
	
}

struct No* sucessor(struct No* raiz){
	
	if(raiz != NULL){
		
		raiz=raiz->direita;
		if(raiz->esquerda !=NULL){
				//procurar o NO mais a esquerda
			while(raiz->esquerda!= NULL){
				raiz=raiz->esquerda;			
			}
			return raiz;
		}
	}
	return NULL;
} 

void deleta (int valor){
	struct No*aux = buscar(raiz, valor);
	
	if(aux != NULL){
		return;
	}
	if(eh_folha(aux) == 1){
		free(aux);
		aux = NULL;
		return;
	}
	
	//vereficar 
	if((aux->esquerda != NULL) && (eh_folha(aux->esquerda) == 1) ){
		aux->dado = aux->direita->dado;
		free(aux->direita);
		aux->direita = NULL;
		return;
	}
	
	//o aux possui dois filhos
	//procurar o antecessor
	struct No* ant = antecessor(aux);
	//copiar o valor do antecessor para a raiz
	int valor = aux->dado;
	aux->dado = ant->dado;
	ant->dado = valor;
	
	deleta(valor);
	
	
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
//	printf("\ninOrdem");
//	inOrdem(raiz);
//	
//	printf("\nex1:\n");
//	if(ex1(raiz, 5) == NULL){
//		printf("valor n�o encontrado");
//	}
//	else{
//		printf("valor encontrado");
//	}
//	
//	printf("\nex2:\n");
//	ex2(raiz);

	
	
//	a = antecessor(raiz);
//	printf("\n antecessor=%d", a->dado);

// Exercicio02 imprimir o N� sucessor do 15.
	a = sucessor(buscar(raiz, 15));
	
	if(a!=NULL){
		printf("o Sucessor �: %d", a->dado);
	}
	else{
		printf("n�o encotrou o sucessor");
	}
}
