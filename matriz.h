#ifndef MATRIZ_H
#define MATRIZ_H

/* ===== Vetores (arranjos 1D) ===== */
int  *aloca_vetor(int n);
void  preenche_vetor_manual(int n, int v[n]);
void  preenche_vetor_aleatorio(int n, int v[n]);
void  imprime_vetor(int n, int v[n]);

/* ===== Matrizes (arranjos 2D, n x n) ===== */
/* Retorna void* (malloc de n*sizeof(int[n])); atribua a "int (*m)[n] = aloca_matriz(n);" */
void *aloca_matriz(int n);
void preenche_matriz_manual(int n, int m[n][n]);
void preenche_matriz_aleatoria(int n, int m[n][n]);
void imprime_matriz(int n, int m[n][n]);

/* ===== Arranjos 3D (n x n x n) — usados na func 3 ===== */
/* Retorna void*; atribua a "int (*a)[n][n] = aloca_matriz3d(n);" */
void *aloca_matriz3d(int n);
void preenche_matriz3d_manual(int n, int a[n][n][n]);
void preenche_matriz3d_aleatoria(int n, int a[n][n][n]);
void imprime_matriz3d(int n, int a[n][n][n]);

/* Pergunta ao usuário se quer preencher manual ou aleatório. Retorna 1 = manual, 0 = aleatório */
int pergunta_modo_preenche(void);

#endif
