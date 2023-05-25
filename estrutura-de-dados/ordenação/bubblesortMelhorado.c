#include <stdio.h>

void bubbleSort(int arr[], int n) {
    int i, j;
    int trocou;
    int limite = n -1;
    
    for (i = 0; i < n-1; i++) {
        trocou = 0;
        
        for (j = 0; j < limite; j++) {
            if (arr[j] > arr[j+1]) {
                // Realiza a troca de elementos
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                
                // Armazena a posição da troca
                trocou = j + 1;
            }
        }
        
        // Se não ocorreu nenhuma troca nesta iteração, o vetor está ordenado
        if (trocou == 0) {
            break;
        }
        
        // Atualiza o limite da próxima iteração para a última posição trocada
        // Isso evita comparar elementos já ordenados
        limite = trocou;
    }
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Array antes da ordenacao:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    
    bubbleSort(arr, n);
    
    printf("\n\nArray depois da ordenacao:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}