#include <stdio.h>
#include <stdlib.h>

// Mostra o array na tela
void MostraArray(int a[], int size){
    int i;
    for (i=0;i<size;i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}

/*
 * 
 */
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


// Le o string e chama o procedimento de merge
int main(){
    int a[100001];
    //int i = 0;
    // int n;
    //int a[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    int size = 0;//sizeof(a)/sizeof(a[0]);
    do {
        scanf("%d", &a[size]);
        size++;
    } while (getchar() != '\n' && size < 100001); 
    //while( scanf("%d",&n) != EOF ) { a[i++] = n ;  }
    mergSort(a,0,size - 1);
    MostraArray(a, size);
    return 0;
}