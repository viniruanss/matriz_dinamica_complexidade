#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

/* ===== Vetores ===== */

int *aloca_vetor(int n) {
    int *v = malloc(n * sizeof(int));
    if (!v) {
        printf("Erro ao alocar vetor.\n");
        exit(1);
    }
    return v;
}

void preenche_vetor_manual(int n, int v[n]) {
    for (int i = 0; i < n; i++) {
        printf("v[%d] = ", i);
        scanf("%d", &v[i]);
    }
}

void preenche_vetor_aleatorio(int n, int v[n]) {
    for (int i = 0; i < n; i++) {
        v[i] = rand() % 100; /* valores de 0 a 99 */
    }
}

void imprime_vetor(int n, int v[n]) {
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

/* ===== Matrizes 2D ===== */

/* aloca uma matriz n x n no heap. O chamador atribui o retorno a um
   ponteiro VLA (int (*m)[n] = aloca_matriz(n);), o que permite usar
   m[i][j] normalmente nas funções que a recebem. */
void *aloca_matriz(int n) {
    void *m = malloc(n * sizeof(int[n]));
    if (!m) {
        printf("Erro ao alocar matriz.\n");
        exit(1);
    }
    return m;
}

void preenche_matriz_manual(int n, int m[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("m[%d][%d] = ", i, j);
            scanf("%d", &m[i][j]);
        }
    }
}

void preenche_matriz_aleatoria(int n, int m[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            m[i][j] = rand() % 100;
        }
    }
}

void imprime_matriz(int n, int m[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%4d", m[i][j]);
        }
        printf("\n");
    }
}

/* ===== Arranjos 3D (func 3) ===== */

/*atribua a "int (*a)[n][n] = aloca_matriz3d(n);" */
void *aloca_matriz3d(int n) {
    void *a = malloc(n * sizeof(int[n][n]));
    if (!a) {
        printf("Erro ao alocar arranjo 3D.\n");
        exit(1);
    }
    return a;
}

void preenche_matriz3d_manual(int n, int a[n][n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                printf("a[%d][%d][%d] = ", i, j, k);
                scanf("%d", &a[i][j][k]);
            }
        }
    }
}

void preenche_matriz3d_aleatoria(int n, int a[n][n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                a[i][j][k] = rand() % 100;
            }
        }
    }
}

void imprime_matriz3d(int n, int a[n][n][n]) {
    for (int i = 0; i < n; i++) {
        printf("Camada %d:\n", i);
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                printf("%4d", a[i][j][k]);
            }
            printf("\n");
        }
    }
}
int pergunta_modo_preenche(void) {
    int opc;
    printf("Como deseja preencher o(s) arranjo(s)?\n");
    printf("1 - Manualmente\n");
    printf("2 - Automaticamente (valores aleatorios)\n");
    printf("Opcao: ");
    scanf("%d", &opc);
    return opc == 1;
}
