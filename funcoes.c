#include "funcoes.h"

int contagem_ocorrencias(int n, int vetor[n], int k, int buscados[k]) {
    int total = 0;
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            if (vetor[j] == buscados[i]) {
                total++;
            }
        }
    }
    return total;
}

int analise_pares_triangular(int n, int m[n][n]) {
    int contador = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if ((m[i][j] + m[j][i]) % 5 == 0) {
                contador++;
            }
        }
    }
    return contador;
}

int compara_matrizes_3d(int n, int a[n][n][n], int b[n][n][n]) {
    long long soma_a = 0;
    long long soma_b = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                soma_a += a[i][j][k];
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                soma_b += b[i][j][k];
            }
        }
    }

    return soma_a >= soma_b;
}

/* fatoriais acima de 20! excedem 64 bits; o tipo unsigned garante overflow definido. */
long long processar_vetor(int n, int v[n]) {
    unsigned long long soma = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] % 2 == 0) {
            soma += v[i];
        } else {
            unsigned long long fatorial = 1;
            for (int f = 2; f <= v[i]; f++) {
                fatorial *= f;
            }
            soma += fatorial;
        }
    }
    return (long long) soma;
}

int busca_binaria(int n, int b[n], int chave) {
    int inicio = 0;
    int fim = n - 1;
    while (inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;
        if (b[meio] == chave) {
            return 1;
        }
        if (b[meio] < chave) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    return 0;
}

int contagem_presentes(int n, int a[n], int b[n]) {
    int total = 0;
    for (int i = 0; i < n; i++) {
        total += busca_binaria(n, b, a[i]);
    }
    return total;
}
