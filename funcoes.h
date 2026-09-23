#ifndef FUNCOES_H
#define FUNCOES_H

/* func 1: Contagem de Ocorrências Distintas */
int contagem_ocorrencias(int n, int vetor[n], int k, int buscados[k]);

/* func 2: Análise de Pares em Matriz Triangular */
int analise_pares_triangular(int n, int m[n][n]);

/* func 3: Comparação de Matrizes Tridimensionais */
int compara_matrizes_3d(int n, int a[n][n][n], int b[n][n][n]);

/* func 4: Análise de Casos Assimétricos no Condicional */
long long processar_vetor(int n, int v[n]);

/* func 5: Contagem de Elementos Presentes em Vetor Ordenado */
int busca_binaria(int n, int b[n], int chave);
int contagem_presentes(int n, int a[n], int b[n]);

#endif
