#ifndef HUFFMAN_HPP
#define HUFFMAN_HPP
#include <string>
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>

using namespace std;

typedef struct DADOS DADOS;
typedef struct ARVORE ARVORE;

struct DADOS{
	string palavra;
	float valor;
	string cod;
};

struct ARVORE{
	DADOS item;
	ARVORE *filho_direito, *filho_esquerdo, *pai;
};

void Juntanos(vector<ARVORE*> &vetor_arvore);
void InsertionSort(vector <ARVORE*> &vetor_arvore);

#endif

