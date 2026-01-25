#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#define MAX 80;

struct st_nome {
	char n[80];
	struct st_nome *prox;
};

typedef struct st_nome celula;

celula *cria_cabeca(void);
celula *cria_corpo(char n[80]);
void insere_ordem(char n[80],celula *p_ini);
void imprime_lista(celula *p_ini);
//void encerra_lista(celula *p_ini);

int main(){
	
	celula *p_ini = cria_cabeca();
	int seletor;
	char n[80];
	
	
	do { 
		
	printf("\n Lista de Nomes \n");
	printf("1.Adicionar um Nome\n");
	printf("2.Ver toda a Lista\n");
	//printf("3.Sair da Lista\n");
	printf("Escolha uma opcao: ");
	scanf("%d",&seletor);
	getchar();
	
	switch(seletor) {
		
		case 1:
		printf("\nDigite o nome a ser inserido: \n");
		fgets(n,80,stdin);
		
		insere_ordem(n,p_ini);
		
		break;
		
		case 2:
		imprime_lista(p_ini);
		break;
		
		//case 3:
		//encerra_lista(p_ini);
		//break;
	}
	
	}while(seletor != 4);
	

}

celula *cria_cabeca(){
	
	celula *start;
	
	start = (celula*) malloc (sizeof(celula));
	start->prox = NULL;
	return start;
}

celula *cria_corpo(char n[80]){
	
	celula *p = (celula*) malloc (sizeof(celula));
	if (p == NULL){
		printf("\nERRO");
		exit(1);
	}
	strcpy(p->n, n);
	p->prox = NULL;
	
	return p;
}

void insere_ordem(char n[80],celula *p_ini){
	
	celula *p = NULL;
	cria_corpo(n);
	
	celula *atual = p_ini->prox;
	celula *atras = p_ini;
	
	    if(p_ini->prox == NULL){
        p_ini->prox = p;
        printf("adicionado com sucesso");
        return;
    }

	
	while((atual != NULL) && (strcmp(p->n,n)) >= 0) {
		atras = atual;
		atual = atual->prox;
	}
	
	atras->prox = p;
	p->prox = atual;
	return;
}

void imprime_lista(celula *p_ini){
  
    printf("\n-Lista de nomes-");
    printf("====================");

    celula* atual = p_ini->prox;

    while(atual != NULL){
        printf("%s/n",atual->n);
        atual = atual->prox;
    }
    printf("====================");
}


