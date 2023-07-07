#ifndef FORCA_H
#define FORCA_H

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <random>
#include <cstring>
#include <cctype>
using std::cout;
using std::cin;
using std::endl;
using std::strcmp;
using std::random_device;
using std::mt19937;
using std::uniform_int_distribution;
using std::strcpy;
using std::memset;
using std::tolower;
using std::strlen;
using std::ifstream;
using std::right;

#ifdef _WIN32
	void limparTela() {
        system("cls");
    }
#else
	void limparTela() {
        system("clear");
    }
#endif

struct Categoria
{
    char nome[20];
    char palavras[10][20];
};

void Desenhar(int);
void LerArquivo(const char[], Categoria[], int, int);
Categoria GerarCategoriaPalavra(Categoria[]);
void PlayGame();

#endif // FORCA