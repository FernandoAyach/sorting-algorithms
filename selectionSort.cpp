#include <stdio.h>
#include <stdlib.h>

//Seleciona o menor valor e coloca na posição atual
void selectionSort(int n, int *v) {
    int i, j, aux, m; // Declaração de variáveis

    for(i = 0; i < n - 1; i++) {  // Loop para percorrer os elementos a serem ordenados
        m = i;  // Assume que a posição i é a menor

        for(j = i + 1; j < n; j++) {  // Comparações do valores à direita com o atual
            if(v[j] < v[i]) m = j;  // Se achar um menor, substitui o indice
        }
        //Troca as variáveis do menor com a atual
        aux = v[i]; 
        v[i] = v[m];
        v[m] = aux;
    }
}

int main() {
    int n, *v;
    scanf("%d", &n);
    v = (int *) calloc(n, sizeof(int));
    for(int i = 0; i < n; i++) scanf("%d", &v[i]);
    for(int i = 0; i < n; i++) printf("%d%c", v[i], " \n"[i == n - 1]);

    selectionSort(n, v);

    for(int i = 0; i < n; i++) printf("%d%c", v[i], " \n"[i == n - 1]);
}