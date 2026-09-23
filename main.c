#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matriz.h"
#include "funcoes.h"

const char *INTEGRANTES[6] = {
    "Andressa",
    "Gabriel",
    "Kauê",
    "Thiago",
    "Vitoria",
    "Vinicius"
};

void imprime_integrantes(void) {
    printf("Integrantes do grupo:\n");
    for (int i = 0; i < 6; i++) {
        printf(" - %s\n", INTEGRANTES[i]);
    }
    printf("\n");
}
/* func 1 */
void opcao_funcao1(void) {
    int n, k;
    printf("Digite n (tamanho do vetor principal): ");
    scanf("%d", &n);
    printf("Digite k (tamanho do vetor de buscados): ");
    scanf("%d", &k);

    int *vetor = aloca_vetor(n);
    int *buscados = aloca_vetor(k);
    int modo = pergunta_modo_preenche();
    /* laço de preeenchimento de vetores*/
    if (modo) {
        printf("Preenchendo vetor principal:\n");
        preenche_vetor_manual(n, vetor);
        printf("Preenchendo vetor de buscados:\n");
        preenche_vetor_manual(k, buscados);
    } else {
        preenche_vetor_aleatorio(n, vetor);
        preenche_vetor_aleatorio(k, buscados);
    }

    printf("Vetor principal: ");
    imprime_vetor(n, vetor);
    printf("Vetor de buscados: ");
    imprime_vetor(k, buscados);

    int resultado = contagem_ocorrencias(n, vetor, k, buscados);
    printf("Resultado: %d\n", resultado);

    free(vetor);
    free(buscados);
}
/* func 2 */
void opcao_funcao2(void) {
    int n;
    printf("Digite n (dimensao da matriz n x n): ");
    scanf("%d", &n);

    int (*m)[n] = aloca_matriz(n);

    int modo = pergunta_modo_preenche();
    if (modo) preenche_matriz_manual(n, m);
    else preenche_matriz_aleatoria(n, m);

    printf("Matriz:\n");
    imprime_matriz(n, m);

    int resultado = analise_pares_triangular(n, m);
    printf("Resultado: %d\n", resultado);

    free(m);
}
/* func 3 */
void opcao_funcao3(void) {
    int n;
    printf("Digite n (dimensao dos arranjos n x n x n): ");
    scanf("%d", &n);

    int (*a)[n][n] = aloca_matriz3d(n);
    int (*b)[n][n] = aloca_matriz3d(n);
    int modo = pergunta_modo_preenche();
    if (modo) {
        printf("Preenchendo arranjo A:\n");
        preenche_matriz3d_manual(n, a);
        printf("Preenchendo arranjo B:\n");
        preenche_matriz3d_manual(n, b);
    } else {
        preenche_matriz3d_aleatoria(n, a);
        preenche_matriz3d_aleatoria(n, b);
    }

    printf("Arranjo A:\n");
    imprime_matriz3d(n, a);
    printf("Arranjo B:\n");
    imprime_matriz3d(n, b);

    int resultado = compara_matrizes_3d(n, a, b);
    printf("Resultado: %d\n", resultado);

    free(a);
    free(b);
}
/* func 4 */
void opcao_funcao4(void) {
    int n;
    printf("Digite n (tamanho do vetor): ");
    scanf("%d", &n);

    int *v = aloca_vetor(n);

    int modo = pergunta_modo_preenche();
    if (modo) preenche_vetor_manual(n, v);
    else preenche_vetor_aleatorio(n, v);

    printf("Vetor: ");
    imprime_vetor(n, v);

    long long resultado = processar_vetor(n, v);
    printf("Resultado: %lld\n", resultado);

    free(v);
}

static int compara_int(const void *x, const void *y) {
    int a = *(const int *) x, b = *(const int *) y;
    return (a > b) - (a < b);
}
/* func 5 */
void opcao_funcao5(void) {
    int n;
    printf("Digite n (tamanho dos vetores A e B): ");
    scanf("%d", &n);

    int *a = aloca_vetor(n);
    int *b = aloca_vetor(n);

    int modo = pergunta_modo_preenche();
    if (modo) {
        printf("Preenchendo vetor A (nao ordenado):\n");
        preenche_vetor_manual(n, a);
        printf("Preenchendo vetor B:\n");
        preenche_vetor_manual(n, b);
    } else {
        preenche_vetor_aleatorio(n, a);
        preenche_vetor_aleatorio(n, b);
    }
    /* a busca binaria exige B ordenado, entao ordenamos nos dois modos */
    qsort(b, n, sizeof(int), compara_int);

    printf("Vetor A: ");
    imprime_vetor(n, a);
    printf("Vetor B: ");
    imprime_vetor(n, b);

    int resultado = contagem_presentes(n, a, b);
    printf("Resultado: %d\n", resultado);

    free(a);
    free(b);
}
int main(void) {
    srand((unsigned int) time(NULL));
    imprime_integrantes();

    int opcao;
    do {
        printf("===== MENU =====\n");
        printf("1 - Contagem de Ocorrencias Distintas\n");
        printf("2 - Analise de Pares em Matriz Triangular\n");
        printf("3 - Comparacao de Matrizes Tridimensionais\n");
        printf("4 - Analise de Casos Assimetricos (processar_vetor)\n");
        printf("5 - Contagem de Elementos Presentes em Vetor Ordenado\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: opcao_funcao1(); break;
            case 2: opcao_funcao2(); break;
            case 3: opcao_funcao3(); break;
            case 4: opcao_funcao4(); break;
            case 5: opcao_funcao5(); break;
            case 0: printf("Encerrando...\n"); break;
            default: printf("Opcao invalida.\n");
        }
        printf("\n");
    } while (opcao != 0);

    return 0; }
