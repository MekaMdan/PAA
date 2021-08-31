#include<stdio.h>
#include<stdlib.h>

int binarySearch(int vetor[], int tam, int valor){
    int r = -1;
    int inicio = 0, fim = tam - 1;

    while(inicio<=fim){
        int meio = (inicio+fim)/2;

        if(valor==vetor[meio]){
            r = meio;
            fim = meio-1;
        }else if(valor<vetor[meio]){
            fim = meio -1;
        }else{
            inicio = meio+1;
        }
    }

    return r;
}

void merg(int vetor[], int inicio, int meio, int fim){
    int i,j,atual;
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
}

/*
 *
 */
void mergSort(int vetor[], int inicio, int fim){
    if(inicio<fim){
        int meio = (inicio+(fim-1))/2;

        mergSort(vetor, inicio, meio);
        mergSort(vetor, meio+1, fim);

        merg(vetor, inicio, meio, fim);
    }
}

void MostraArray(int a[], int size){
    int i;
    for (i=0;i<size;i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main(){
    int N,Q,valor;

    // Ler N(tamanho do array) e Q(numero de queries)
    scanf("%d %d", &N,&Q);
    
    int a[100000];
    int i;

    mergSort(a,0,N-1);   

    // Le o array
    for(i=0;i<N;i++){
        scanf("%d", &a[i]);
    }
 
    // Le a query
    for(i=0;i<Q;i++){
        scanf("%d", &valor);
        printf("%d\n",binarySearch(a, N ,valor));
    }

    return 0;
}