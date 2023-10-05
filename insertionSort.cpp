#include <stdio.h>
#include <stdlib.h>

//Insere o valor na posição ideal, em relação à esquerda
void insertionSort(int n, int *v) {
    int i, j, x; // Declaração de variáveis

    for(i = 1; i < n; i++) { // Loop por cada posição a ser ordenada
        x = v[i]; // Valor que queremos posicionar

        for(j = i - 1; j >= 0 && v[j] > x; j--) { // Verificação do valor com todas as posições à esquerda
            v[j + 1] = v[j]; // Se o valor à esquerda for maior, copia este na posição a frente
        }
        v[j + 1] = x;  // Insere o valor em sua posição ideal
    }
}

int main() {
    int n, *v;
    scanf("%d", &n);
    v = (int *) calloc(n, sizeof(int));
    for(int i = 0; i < n; i++) scanf("%d", &v[i]);
    for(int i = 0; i < n; i++) printf("%d%c", v[i], " \n"[i == n - 1]);

    insertionSort(n, v);

    for(int i = 0; i < n; i++) printf("%d%c", v[i], " \n"[i == n - 1]);
}