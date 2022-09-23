#ifndef FILA_HPP
#define FILA_HPP
#include "huffman.hpp"

typedef struct Fila_Data Fila_Data;
typedef struct Fila_Block Fila_Block;
typedef struct Fila Fila;

struct Fila_Data{
    ARVORE* val;
};

struct Fila_Block{
    Fila_Data data;
    Fila_Block *prox;
};

struct Fila{
    Fila_Block *prim;
    Fila_Block *ult;
};

void CriaFila(Fila *f);
void Enfileira(Fila *f, Fila_Data value);
void Desenfileira(Fila *f, Fila_Data *value);
bool FilaVazia(Fila *f);

void PrintLargura(ARVORE **t);
void GeraCod(ARVORE **t);
string BuscaPalavraCod(ARVORE **t, string palavra_aux);
void JogaCodVetor(ARVORE **t, vector<string> &texto, vector<string> &vetor_salva);


bool Letra_1carac(string content);
string TratamentoString(string palavra);

#endif