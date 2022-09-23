#include "huffman.hpp"

//InsertionSort para ordem minhas palavras das mais recorrentes para as menos recorrentes.
void InsertionSort(vector <ARVORE*> &vetor_arvore){
    ARVORE *aux;
    int j;

    for(long unsigned int i = 1; i < vetor_arvore.size(); i++){
        aux = vetor_arvore[i];
        j = i - 1;

        while(j >= 0 && aux -> item.valor > vetor_arvore[j]->item.valor){
            vetor_arvore[j + 1] = vetor_arvore[j];
            j = j - 1;
        }
        vetor_arvore[j + 1] = aux;
    }
}

//Uni meus nos em uma unica posição no vector
void Juntanos(vector<ARVORE*> &vetor_arvore){

    ARVORE *aux_filho_esquerdo, *aux_filho_direito, *aux;

    InsertionSort(vetor_arvore);

    while(vetor_arvore.size() != 1){
        aux_filho_esquerdo = vetor_arvore[vetor_arvore.size() - 1];
        aux_filho_direito = vetor_arvore[vetor_arvore.size() - 2];

        vetor_arvore.pop_back();
        vetor_arvore.pop_back();

        aux = new ARVORE;
        aux -> item.valor = aux_filho_esquerdo -> item.valor + aux_filho_direito -> item.valor;

        aux -> filho_esquerdo = aux_filho_esquerdo;
        aux -> filho_direito = aux_filho_direito;

        aux -> filho_direito -> pai = aux;
        aux -> filho_esquerdo -> pai = aux;
        vetor_arvore.push_back(aux);

        InsertionSort(vetor_arvore);
    }
        vetor_arvore[0] -> pai = NULL;
}
