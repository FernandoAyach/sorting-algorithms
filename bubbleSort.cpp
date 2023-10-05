#include <stdio.h>
#include <stdlib.h>

//Trocas sucessivas
void bubbleSort(int n, int *v) {
    int aux;

    for(int i = n - 1; i > 0; i--) {  // Limite superior das trocas
        for(int j = 0; j < i; j++) {  // Loop pelos elementos a serem de fato ordenados
            if(v[j] > v[j + 1]) { // Troca de variáveis
                aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
            }
        }
    }
}

int main() {
    int n, *v;
    scanf("%d", &n);
    v = (int *) calloc(n, sizeof(int));
    for(int i = 0; i < n; i++) scanf("%d", &v[i]);
    for(int i = 0; i < n; i++) printf("%d%c", v[i], " \n"[i == n - 1]);

    bubbleSort(n, v);

    for(int i = 0; i < n; i++) printf("%d%c", v[i], " \n"[i == n - 1]);
}