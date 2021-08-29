#include <stdio.h>
#include <stdlib.h>

void MostraArray(int a[], int size){
    int i;
    for (i=0;i<size;i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}

int merg(int vetor[], int inicio, int meio, int fim){
    int i,j,atual;
    int troca = 0;
    int tamE = meio - inicio + 1;
    int tamD = fim - meio;

    int D[tamD], E[tamE];

    for (i = 0; i<tamE;i++){
        E[i] = vetor[inicio+i];
    }

    for(j=0;j<tamD;j++){
        D[j] = vetor[meio+1+j];
        
    }

    i = 0;
    j = 0;
    atual = inicio;
    while(i<tamE && j<tamD){
        if(E[i]<=D[j]){
            vetor[atual] = E[i];
            i++;
        }else{
            vetor[atual] = D[j];
            j++;
            troca += tamE - i;
        }
        atual++;
    }

    while(i < tamE){
        vetor[atual] = E[i];
        i++;
        atual++;
    }

    while(j < tamD){
        vetor[atual] = D[j];
        j++;
        atual++;
    }
    return troca;
}

/*
 *
 */
int codesptb(int vetor[], int inicio, int fim){
    int trocas = 0;
    if(inicio<fim){
        int meio = ((inicio+(fim-1)))/2;

        trocas += codesptb(vetor, inicio, meio);
        trocas += codesptb(vetor, meio+1, fim);

        trocas += merg(vetor, inicio, meio, fim);
    }
    return trocas;
}

int main(){
    int vezes,i,qnt,size; // casos de teste
    int T[5];
    scanf("%d",&vezes);
    for(i=0;i<vezes;i++){
        scanf("%d",&qnt);
        size = 0;
        int a[qnt]; 
        do{
            scanf("%d", &a[size]);
            size++;
        }while(getchar() != '\n' && size < qnt);
        printf("%d\n",codesptb(a,0,size-1));
    } 
    return 0;
}