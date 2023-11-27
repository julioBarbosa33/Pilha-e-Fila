#include <stdio.h> 
#include <stdlib.h> 

 

struct TipoNodo 

{ 

    int info; 

    struct TipoNodo *elo; 

}; 

 

typedef struct TipoNodo TipoNodo; 

 

int menu(void); 

int inserirInicioPilha(TipoNodo **ponteiroLista, int dados); 

int Desempilha(TipoNodo **ponteiroLista); 

void Quantidadeelementos(TipoNodo *ponteiroLista); 

void MostrarTopo(TipoNodo *ponteiroLista); 

void mostrarPilha(TipoNodo *ponteiroLista); 

 

int main() 

{ 

    TipoNodo *ponteiroLista; 

    int dados, op, sucesso, lista, quant; 

    ponteiroLista = NULL;  

    do 

    { 

        op = menu(); 

        switch (op) 

        { 

        case 1: 

            printf("Digite um número: \n"); 

            scanf("%d", &dados); 

            sucesso = inserirInicioPilha(&ponteiroLista, dados); 

            if (sucesso == 0) 

                printf("\nTudo certo!!!\n"); 

            else 

                printf("\nErro!!!\n\n"); 

            break; 

        case 2: 

            Desempilha(&ponteiroLista); 

            printf("Apagado com sucesso! \n\n"); 

            break; 

        case 3: 

            printf("A quantidade de elementos é: \n"); 

            Quantidadeelementos(ponteiroLista); 

            break; 

 

        case 4: 

            printf("O primeiro elemento é: \n"); 

            MostrarTopo(ponteiroLista); 

            break; 

        case 5: 

            printf("A pilha é: \n"); 

            mostrarPilha(ponteiroLista); 

            break; 

        default: 

            if (op != 0) 

            { 

                printf("\nOpção inválida animal!\n"); 

            } 

        } 

    } while (op != 0); 

} 

 

int menu() 

{ 

    int op; 

    printf("\n\nMenu\n"); 

    printf("[1] Empilhar\n"); 

    printf("[2] Desempilhar\n"); 

    printf("[3] Quantidade de elementos\n"); 

    printf("[4] Mostrar quem é o topo\n"); 

    printf("[5]Mostrar pilha\n"); 

    printf("_____________________________\n"); 

    printf("Escolha a opção:\n"); 

    scanf("%d", &op); 

    return op; 

} 

 

int inserirInicioPilha(TipoNodo **ponteiroLista, int dados) 

{ 

    TipoNodo *ponteiroNovo = (TipoNodo *)malloc(sizeof(TipoNodo)); 

    if (ponteiroNovo == NULL) 

        return 1; 

    else 

    { 

        ponteiroNovo->info = dados; 

        ponteiroNovo->elo = *ponteiroLista; 

        *ponteiroLista = ponteiroNovo; 

        return 0; 

    } 

} 

 

int Desempilha(TipoNodo **ponteiroLista) 

{ 

    if (ponteiroLista == NULL) 

    { 

        printf("A pilha está vazia!\n"); 

        return 1; 

    } 

    else 

    { 

        TipoNodo *ponteiroNovo = *ponteiroLista; 

        *ponteiroLista = ponteiroNovo->elo; 

        ponteiroLista = NULL; 

        int dados; 

        dados = ponteiroNovo->info; 

        free(ponteiroNovo); 

        return dados; 

    } 

} 

 

void Quantidadeelementos(TipoNodo *ponteiroLista) 

{ 

    TipoNodo *ponteiroAux; 

    int quant = 0; 

    for (ponteiroAux = ponteiroLista; ponteiroAux != NULL; ponteiroAux = ponteiroAux->elo) 

    { 

        quant++; 

    } 

    printf("%d", quant); 

} 

void MostrarTopo(TipoNodo *ponteiroLista) 

{ 

    printf("%d\t", ponteiroLista->info); 

} 

 

void mostrarPilha(TipoNodo *ponteiroLista) 

{ 

    TipoNodo *ponteiroAux; 

    for (ponteiroAux = ponteiroLista; ponteiroAux != NULL; ponteiroAux = ponteiroAux->elo) 

        printf("%d\t", ponteiroAux->info); 

} 