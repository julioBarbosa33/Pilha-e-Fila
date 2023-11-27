#include <stdio.h>
#define N 5

struct TipoNodo{
    int codigo; 
    char nome[10];
    float numero; 
};
typedef struct TipoNodo TipoNodo;

int Menu(); 
int Inserir(TipoNodo LL[], int IA, int FA, int *IL, int *FL, TipoNodo infoNodo); 
int MostrarFila(TipoNodo LL[], int IA, int FA, int IL, int FL);
int RemoverFila(TipoNodo LL[], int IA, int FA, int *IL, int *FL, TipoNodo infoNodo);
int qtdFila(int IA, int FA, int IL, int FL);
int MostrarPrimeiroFila(TipoNodo LL[], int IA);
int MostrarUltimoFila(TipoNodo LL[], int FL);

int main()
{
    TipoNodo LL[N], infoNodo; 
    int opcao, IA=0, FA=N-1, IL=-1, FL=-1;
    int K=0;
    do{
        opcao = Menu(); 
        switch (opcao){
            case 1: 
                printf("\n Inserindo um novo nó\n"); 
                printf("\n Código do nó: "); 
                scanf("%d", &infoNodo.codigo);
                printf("\n Nome do nó: "); 
                scanf("%s", infoNodo.nome);
                printf("\n Número do nó: "); 
                scanf("%f", &infoNodo.numero); 
                if(Inserir(LL, IA, FA , &IL, &FL, infoNodo))
                    printf("\n Lista cheia, não foi possível inserir\n");
                else
                    printf("\n Nó inserido com sucesso \n"); 
                break;   
                
            case 2: 
                printf("\n Mostrar lista\n"); 
                MostrarFila(LL, IA, FA, IL, FL); 
                break;
                
            case 3: 
                printf("\n Item removido da fila\n"); 
                RemoverFila(LL, IA, FA, &IL, &FL, infoNodo); 
                break;
	
            case 4:
                printf("\n Quantidade de elementos na fila\n");
                qtdFila(IA, IL, FA, FL);
                break; 
            
            case 5:
                printf("\n Primeiro elemento da fila \n");
                MostrarPrimeiroFila(LL, IA);
                break;

            case 6:
                printf("\n> Ultimo elemento da fila\n");
                MostrarUltimoFila(LL, FL);
                break;
                
            case 0:
                printf("\n Tchau \n"); 
                break; 
                
            default: 
                printf("\n Errou a opção, tente novamente \n");
                break; 
        }
    } while (opcao != 0); 
}

int Menu(){
    int opcao; 
     printf("*********** M E N U ************\n");
    printf("[1] Inserir novo nó\n");
    printf("[2] Mostrar fila\n");
    printf("[3] Remover da fila\n");
    printf("[4] Quantidade da fila\n");
    printf("[0] Sair\n");
    printf("********************************\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);
    return opcao;
}
int Inserir(TipoNodo LL[], int IA, int FA, int *IL, int *FL, TipoNodo infoNodo) 
{
    if (IA == *IL && FA == *FL)
        return 1; 
    else
    {
        if(*IL == -1) 
            *IL = *FL = IA;
        else if (*IL > IA)
            *IL = *IL-1;
        else
        {
            for(int i=*FL; i>=*IL; i--)
                LL[i+1] = LL[i]; 
            *FL = *FL+1; 
        }
        LL[*IL] = infoNodo;
        return 0; 
    }    
}

int MostrarFila(TipoNodo LL[], int IA, int FA, int IL, int FL)
{
    
    for(int i=IA; i<=FA; i++){
        if(i>=IL && i<=FL)
            printf("%4d - %s - %8.2f\n", LL[i].codigo, LL[i].nome, LL[i].numero); 
    
        else 
            printf("--- --- ---\n"); 
    }
    return 0; 
}

int RemoverFila(TipoNodo LL[], int IA, int FA, int *IL, int *FL, TipoNodo infoNodo)
{
    for (int i = *FL; i >= *IL; i--)
        LL[i - 1] = LL[i];
    *FL = *FL - 1;
    return 0;
}

int qtdFila(int IA, int FA, int IL, int FL){
    int x=0;

    for(int i=IA; i<=FA; i++){
        if(i>=IL && i<=FL){
        x++;
        }
    }
    printf("%d\n",x);
}

int MostrarPrimeiroFila(TipoNodo LL[], int IA){
    printf("%4d - %8.2f - %s\n",LL[IA].codigo, LL[IA].numero, LL[IA].nome);
}

 

int MostrarUltimoFila(TipoNodo LL[], int FL){
    printf("%4d - %8.2f - %s\n",LL[FL].codigo, LL[FL].numero, LL[FL].nome);
}