#include <stdio.h>
#include <stdlib.h>

// Rearranja um vetor[p..q-1] e um vetor[q..r-1], ambos ordenados crescentemente,
// Em um vetor w[p..r-1] ordenado
void intercala(int p, int q, int r, int *v) {
    // Declaração de variáveis: i como iterador do primeiro intervalo
    // j como iterador do segundo e k como iterador do resultante
    // w é o vetor resultante
    int i = p, j = q, k = 0, *w;
    w = (int *) calloc(r, sizeof(int));

    // Enquanto um dos vetores não tiver acabado, posiciona o menor de
    // entre as duas posições do vetores no vetor resultante
    while(i < q && j < r) {
        if(v[i] < v[j]) {
            w[k] = v[i];  //  Se o valor de i for menor, coloca ele
            i++;
        } else {
            w[k] = v[j];  // Senão, coloca o de j
            j++;
        }

        k++;  // Incrementa o numero de elementos de w
    }
    // A partir daqui, algum vetor acabou, então devemos despejar o resto do que sobrou

    while(i < q) { // Se o vetor [p..q-1] que sobrou, coloca o resto dele em w
        w[k] = v[i];
        i++;
        k++;
    }

    while(j < r) { // Se o vetor [q..r-1] que sobrou, coloca o resto dele em w
        w[k] = v[j];
        j++;
        k++;
    }

    //Atualiza o vetor original
    for(i = p; i < r; i++) v[i] = w[i - p];
}

//Divide o vetor ao meio até ficar um elemento
void mergeSort(int p, int r, int *v) {
    int q;

    if(p < r - 1) { // Se há mais de um elemento
        q = (p + r) / 2; // Divide no meio
        mergeSort(p, q, v); // Continua a divisão na parte esquerda
        mergeSort(q, r, v); // Continua a divisao na parte direita
        intercala(p, q, r, v); // Junta de forma ordenada
    }
}

int main() {
    int n, *v;
    scanf("%d", &n);
    v = (int *) calloc(n, sizeof(int));
    for(int i = 0; i < n; i++) scanf("%d", &v[i]);
    for(int i = 0; i < n; i++) printf("%d%c", v[i], " \n"[i == n - 1]);

    mergeSort(0, n, v);

    for(int i = 0; i < n; i++) printf("%d%c", v[i], " \n"[i == n - 1]);
}