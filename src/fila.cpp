#include "fila.hpp"

//Estruta para criar minha fila
void CriaFila(Fila *f){
    f -> prim = new Fila_Block;
    f -> ult = f -> prim;
    f -> ult -> prox = NULL;
}

//Enfileira
void Enfileira(Fila *f, Fila_Data value){
    f -> ult -> prox = new Fila_Block;
    f -> ult = f -> ult -> prox;
    f -> ult -> data = value;
    f -> ult -> prox = NULL;
}

//Desenfileira
void Desenfileira(Fila *f, Fila_Data *value){
    Fila_Block *aux;

    if (f -> prim == f -> ult || f == NULL || f -> prim -> prox == NULL){
        cout << "Fila vazia!" << endl;
        return;
    }

    aux = f -> prim -> prox;
    f -> prim -> prox = aux -> prox;
    if (f -> prim -> prox == NULL){

        f -> ult = f -> prim;

    }
    value -> val = aux -> data.val;
    free(aux);
}

//Verfica se minha fila está vazia
bool FilaVazia(Fila *f){
    if (f -> prim == f -> ult || f -> prim -> prox == NULL || f == NULL){
        return true;
    }
    return false;
}

//Printa minha árvore em largura
void PrintLargura(ARVORE **t){
    if (*t == NULL){
        return;
    }

    Fila FilaA;
    CriaFila(&FilaA);
    Fila_Data aux, filho;
    aux.val = *t;
    Enfileira(&FilaA, aux);
    int cont = 0;

    while(!FilaVazia(&FilaA)){
        Desenfileira(&FilaA, &aux);
        //Imprimi árvore
        cout << aux.val -> item.cod << endl;
        
        if (aux.val -> filho_esquerdo != NULL){
            filho.val = aux.val -> filho_esquerdo;
            Enfileira(&FilaA, filho);
        }

        if (aux.val -> filho_direito != NULL){
            filho.val = aux.val -> filho_direito;
            Enfileira(&FilaA, filho);
        }

        cont++;
    }
}

//Gera o código para cada nó/palavra
void GeraCod(ARVORE **t){
    if (*t == NULL){
        return;
    }

    Fila FilaA;
    CriaFila(&FilaA);
    Fila_Data aux, filho;
    aux.val = *t;
    Enfileira(&FilaA, aux);
    int cont = 0;

    while(!FilaVazia(&FilaA)){

        Desenfileira(&FilaA, &aux);
        
        if (aux.val -> filho_esquerdo != NULL){

            aux.val -> filho_esquerdo -> item.cod = aux.val-> filho_esquerdo->pai->item.cod;
            aux.val -> filho_esquerdo -> item.cod = aux.val -> filho_esquerdo->item.cod + "0";

            filho.val = aux.val -> filho_esquerdo;
            Enfileira(&FilaA, filho);
        }

        if (aux.val -> filho_direito != NULL){

            aux.val -> filho_direito -> item.cod = aux.val->filho_direito->pai->item.cod;
            aux.val -> filho_direito -> item.cod = aux.val -> filho_direito->item.cod + "1";

            filho.val = aux.val -> filho_direito;
            Enfileira(&FilaA, filho);
        }

        cont++;
    }
}

//Busca palavra e retorna seu respectivo código
string BuscaPalavraCod(ARVORE **t, string palavra_aux){

    Fila FilaA;
    CriaFila(&FilaA);
    Fila_Data aux, filho;
    aux.val = *t;
    Enfileira(&FilaA, aux);
    int cont = 0;

    while(!FilaVazia(&FilaA)){

        Desenfileira(&FilaA, &aux);

        if(aux.val -> item.palavra == palavra_aux){
            return aux.val -> item.cod;
        }
        
        if (aux.val -> filho_esquerdo != NULL){

            filho.val = aux.val -> filho_esquerdo;
            Enfileira(&FilaA, filho);
        }

        if (aux.val -> filho_direito != NULL){

            filho.val = aux.val -> filho_direito;
            Enfileira(&FilaA, filho);
        }

        cont++;
    }
    return "a";
}

//Jogar o código no vector final
void JogaCodVetor(ARVORE **t, vector<string> &texto, vector<string> &vetor_salva){
    string aux;

    while(!texto.empty()){
        aux = BuscaPalavraCod(t,texto[0]);
        vetor_salva.push_back(aux);
        texto.erase(texto.begin());
    }
}

//Retira palavras com um caractere ou seja indesejavéis
bool Letra_1carac(string content){
    if (content.size() == 1){
        return false;
    }
    return true;
}

//Trata o meu texto retirando acentuação e afins
string TratamentoString(string palavra){
    string aux;

        for(long unsigned int i = 0; i < palavra.size(); i++){
            if (palavra[i] != '.' && palavra[i] != ',' && palavra[i] != '/' && palavra[i] != ';' && palavra[i] != ':' && palavra[i] != '!' && 
            palavra[i] != '"' && palavra[i] != '\'' && palavra[i] != '[' && palavra[i] != ']' && palavra[i] != '{' && palavra[i] != '}' && 
            palavra[i] != '(' && palavra[i] != ')' && palavra[i] != '/' && palavra[i] != '|' && palavra[i] != '\\' && 
            palavra[i] != '*' && palavra[i] != '-' && palavra[i] != '+' && palavra[i] != '?' && palavra[i] != '.' && palavra[i] != '\n'){
            palavra[i] = tolower(palavra[i]);
            aux += palavra[i];
            }
        }
        return aux;
}