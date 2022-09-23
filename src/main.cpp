#include "fila.hpp"
#include "huffman.hpp"

int main(){

    unordered_map<string, float> Hash;
    vector<string> VETOR_PALAVRAS;
    vector<string> VETOR_FINAL;
    string palavra;

    ifstream arq;
    arq.open("Texto.txt");
    if(arq.is_open()){
        while(!arq.eof()){
            getline(arq, palavra, ' ');
            if(Letra_1carac(palavra)){
                palavra = TratamentoString(palavra);
                VETOR_PALAVRAS.push_back(palavra);
            }
        }
    }

    for(long unsigned int i = 0; i < VETOR_PALAVRAS.size(); i++){
        auto busca = Hash.find(VETOR_PALAVRAS[i]);
        if(busca != Hash.end()){
            busca -> second++;
        }else{
            Hash.emplace(VETOR_PALAVRAS[i], 1);
        }
    }

    float maior = 0;
    float menor = 10000;

    for (auto &item: Hash){
         if(maior < item.second){
            maior = item.second;       
         }

         if(menor > item.second){
            menor = item.second;
         }
     }

    vector<ARVORE*> vetor_arvore;
    ARVORE *aux;

    for (auto &I: Hash){
        I.second = I.second / (maior - menor);
        aux = new ARVORE;
        aux -> item.palavra = I.first;
        aux -> item.valor = I.second;
        aux -> item.cod = "NULL";
        aux -> filho_esquerdo = NULL;
        aux -> filho_direito = NULL;
        vetor_arvore.push_back(aux);
     }

    Juntanos(vetor_arvore);
    GeraCod(&vetor_arvore[0]);
    PrintLargura(&vetor_arvore[0]);
    JogaCodVetor(&vetor_arvore[0], VETOR_PALAVRAS, VETOR_FINAL);

    FILE *myfile;
    myfile = fopen("Compactado.bin", "wb");
    if(myfile != NULL){
        fwrite(&VETOR_FINAL, sizeof(string), VETOR_FINAL.size(), myfile);
    }

    return 0;
}