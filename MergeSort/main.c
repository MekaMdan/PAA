#include <stdio.h>


// Pega o vetor, o inicio do vetor e o final
void mergSort(int array[], int inicio, int fim){
    int meio;
     
}

// Mostra o array na tela
void MostraArray(int a[], int size){
    int i;
    for (i=0;i<size;i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}

// Le o string e chama o procedimento de merge
int main(){
    int a[100001];
    int size = 0;
    do {
        scanf("%d", &a[size++]);
    } while (getchar() != '\n' && size < 100000);
    MostraArray(a,size);
    //merg(a,0,size - 1);
    return 0;
}