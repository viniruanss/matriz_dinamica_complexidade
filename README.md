# Projeto AV01 — Complexidade e Computabilidade de Algoritmo

Trabalho da disciplina de Complexidade e Computabilidade de Algoritmo (UNIPÊ,
Prof. Herriotr). O programa implementa, em C, um menu com 5 funções sobre
vetores e matrizes alocados dinamicamente.

## Integrantes

- Andressa
- Gabriel
- Kauê
- Thiago
- Vitoria
- Vinicius

## Funcionalidades

O programa exibe um menu e o usuário escolhe qual função executar. Para cada
uma, é possível preencher os arranjos manualmente ou de forma aleatória.

1. **Contagem de Ocorrências Distintas** — para cada elemento de um vetor de
   busca, conta quantas vezes ele aparece no vetor principal.
2. **Análise de Pares em Matriz Triangular** — percorre a diagonal principal
   e a metade superior de uma matriz `n x n`, comparando cada elemento com
   seu oposto na metade inferior.
3. **Comparação de Matrizes Tridimensionais** — soma todos os elementos de
   dois arranjos `n x n x n` e compara os totais.
4. **Análise de Casos Assimétricos** — percorre um vetor somando o valor
   quando ele é par, ou o fatorial do valor quando é ímpar.
5. **Contagem de Elementos Presentes em Vetor Ordenado** — usa busca binária
   para contar quantos elementos de um vetor A aparecem em um vetor B
   ordenado.

## Estrutura do projeto

| Arquivo | Conteúdo |
|---|---|
| `main.c` | Menu principal e as rotinas de cada opção. |
| `funcoes.c` / `funcoes.h` | As 5 funções pedidas no projeto. |
| `matriz.c` / `matriz.h` | Alocação, preenchimento e impressão de vetores, matrizes e arranjos 3D. |

Vetores, matrizes e arranjos 3D são alocados dinamicamente com `malloc` e
acessados por meio de VLAs (Variable Length Arrays), conforme exigido pelo
enunciado — a dimensão `n` é sempre declarada antes do arranjo no parâmetro
da função, por exemplo `int (*m)[n]`.

## Como compilar

É necessário um compilador com suporte a C99 (VLAs).

```bash
gcc -std=c99 -Wall -Wextra -o programa main.c funcoes.c matriz.c
```

## Como executar

```bash
./programa
```

O programa exibe os integrantes do grupo, depois o menu:

```
===== MENU =====
1 - Contagem de Ocorrencias Distintas
2 - Analise de Pares em Matriz Triangular
3 - Comparacao de Matrizes Tridimensionais
4 - Analise de Casos Assimetricos (processar_vetor)
5 - Contagem de Elementos Presentes em Vetor Ordenado
0 - Sair
```

Ao escolher uma opção, o programa pede o tamanho do(s) arranjo(s), pergunta
se o preenchimento será manual ou aleatório, imprime o arranjo criado e só
então mostra o resultado da função.
