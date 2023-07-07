#include "forca.h"

Categoria GerarCategoriaPalavra(Categoria c[])
{
    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<int> geradorPalavra(0, 10);
    uniform_int_distribution<int> geradorCategoria(0, 5);

    Categoria escolhida;

    int indiceCategoria = geradorCategoria(mt);
    int indicePalavra = geradorPalavra(mt);

    strcpy(escolhida.nome, c[indiceCategoria].nome);
    strcpy(escolhida.palavras[0], c[indiceCategoria].palavras[indicePalavra]);

    return escolhida;
}

void PlayGame()
{
    Categoria *categorias = new Categoria[6];
    LerArquivo("categoria.txt", categorias, 6, 10);
    Categoria escolhida = GerarCategoriaPalavra(categorias);

    int cena = 1;
    int tentativas = 7;
    char palavra[strlen(escolhida.palavras[0])];
    char letrasErradas[27] = {};
    char letra;

    memset(palavra, '_', strlen(escolhida.palavras[0]));
	
	limparTela();
	
    while ((tentativas != 0) && (strcmp(escolhida.palavras[0], palavra) != 0))
    {
        Desenhar(cena);
        cout << "Tema: " << escolhida.nome << endl;
        cout << "Palavra: " << palavra << endl;
        cout << "Tentativas: " << tentativas << endl;
        cout << "Digite uma letra: ";
        cin >> letra;

        letra = tolower(letra);

        bool contemLetra = false;

        for (int i = 0; i < strlen(palavra); ++i)
        {
            if (letra == escolhida.palavras[0][i])
            {
                contemLetra = true;
                palavra[i] = letra;
            }
        }

        if (contemLetra)
        {
            for (int i = 0; i < strlen(palavra); ++i)
            {
                if (letra == escolhida.palavras[0][i])
                    palavra[i] = letra;
            }
        }
        else
        {
            bool letraRepetida = false;

            for (int i = 0; i < strlen(letrasErradas); ++i)
            {
                if (letrasErradas[i] == letra)
                {
                    letraRepetida = true;
                    break;
                }
            }

            if (!letraRepetida)
            {
                letrasErradas[strlen(letrasErradas)] = letra;
                letrasErradas[strlen(letrasErradas) + 1] = '\0';
                cena++;
                tentativas--;
            }
        }

        limparTela();
    }

    if (tentativas == 0)
    {
        cout << "Você perdeu! A palavra correta era: "
             << escolhida.palavras[0] << endl << endl;
    }
    else
    {
        cout << "Parabéns! Você acertou a palavra!"
             << endl << endl;
    }

    delete[] categorias;
}

void LerArquivo(const char str[], Categoria c[], int qtdCategorias, int qtdPalavras)
{
    ifstream fin(str);
    char temp[20];

    for (int i = 0; i < qtdCategorias; ++i)
    {
        fin.getline(temp, 20);
        strcpy(c[i].nome, temp);

        for (int j = 0; j < qtdPalavras; ++j)
        {
            fin.getline(temp, 20);
            strcpy(c[i].palavras[j], temp);
        }
        
        fin.get();
    }

    fin.close();
}

void Desenhar(int cena)
{
	switch(cena)
	{
		case 1:
		{
			cout << "\t\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\n";
			cout << right; cout.width(9); cout << "\xBA";
			cout.width(8); cout << "\xBA\n";
			cout.width(10); cout << "\xBA\n";
			cout.width(10); cout << "\xBA\n";
			cout.width(10); cout << "\xBA\n";
			cout.width(10); cout << "\xBA\n";
			cout.width(17); cout << "\xCD\xCD\xCD\xBA\xCD\xCD\xCD\xCD\xCD\xCD\xCD\n";
			cout.width(6); cout << "\xBA";
			cout.width(16); cout << "\xBA\xCD\xCD\xCD\xCD\xCD\n";
			cout.width(6); cout << "\xBA";
			cout.width(16); cout << "\xBA\n";
			cout.width(23); cout << "\xBA\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBA\n\n";
			break;
		}
		case 2:
		{
			cout << "\t\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\n";
			cout << right; cout.width(9); cout << "\xBA";
			cout.width(8); cout << "\xBA\n";
			cout.width(9); cout << "\xBA";
			cout.width(8); cout << "\x4F\n";
			cout.width(10); cout << "\xBA\n";
			cout.width(10); cout << "\xBA\n";
			cout.width(10); cout << "\xBA\n";
			cout.width(17); cout << "\xCD\xCD\xCD\xBA\xCD\xCD\xCD\xCD\xCD\xCD\xCD\n";
			cout.width(6); cout << "\xBA";
			cout.width(16); cout << "\xBA\xCD\xCD\xCD\xCD\xCD\n";
			cout.width(6); cout << "\xBA";
			cout.width(16); cout << "\xBA\n";
			cout.width(23); cout << "\xBA\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBA\n\n";
			break;
		}
		case 3:
		{
			cout << "\t\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\n";
			cout << right; cout.width(9); cout << "\xBA";
			cout.width(8); cout << "\xBA\n";
			cout.width(9); cout << "\xBA";
			cout.width(8); cout << "\x4F\n";
			cout.width(9); cout << "\xBA";
			cout.width(8); cout << "\xB3\n";	
			cout.width(10); cout << "\xBA\n";
			cout.width(10); cout << "\xBA\n";
			cout.width(17); cout << "\xCD\xCD\xCD\xBA\xCD\xCD\xCD\xCD\xCD\xCD\xCD\n";
			cout.width(6); cout << "\xBA";
			cout.width(16); cout << "\xBA\xCD\xCD\xCD\xCD\xCD\n";
			cout.width(6); cout << "\xBA";
			cout.width(16); cout << "\xBA\n";
			cout.width(23); cout << "\xBA\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBA\n\n";
			break;		
		}
		case 4:
		{
			cout << "\t\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\n";
			cout << right; cout.width(9); cout << "\xBA";
			cout.width(8); cout << "\xBA\n";
			cout.width(9); cout << "\xBA";
			cout.width(8); cout << "\x4F\n";
			cout.width(9); cout << "\xBA";
			cout.width(8); cout << "\xB3\n";	
			cout.width(9); cout << "\xBA";
			cout.width(8); cout << "\xB3\n";
			cout.width(10); cout << "\xBA\n";
			cout.width(17); cout << "\xCD\xCD\xCD\xBA\xCD\xCD\xCD\xCD\xCD\xCD\xCD\n";
			cout.width(6); cout << "\xBA";
			cout.width(16); cout << "\xBA\xCD\xCD\xCD\xCD\xCD\n";
			cout.width(6); cout << "\xBA";
			cout.width(16); cout << "\xBA\n";
			cout.width(23); cout << "\xBA\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBA\n\n";
			break;		
		}
		case 5:	
		{
			cout << "\t\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\n";
			cout << right; cout.width(9); cout << "\xBA";
			cout.width(8); cout << "\xBA\n";
			cout.width(9); cout << "\xBA";
			cout.width(8); cout << "\x4F\n";
			cout.width(9); cout << "\xBA";
			cout.width(8); cout << "\x5C\xB3\n";	
			cout.width(9); cout << "\xBA";
			cout.width(8); cout << "\xB3\n";
			cout.width(10); cout << "\xBA\n";
			cout.width(17); cout << "\xCD\xCD\xCD\xBA\xCD\xCD\xCD\xCD\xCD\xCD\xCD\n";
			cout.width(6); cout << "\xBA";
			cout.width(16); cout << "\xBA\xCD\xCD\xCD\xCD\xCD\n";
			cout.width(6); cout << "\xBA";
			cout.width(16); cout << "\xBA\n";
			cout.width(23); cout << "\xBA\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBA\n\n";
			break;		
		}
		case 6:
		{
			cout << "\t\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\n";
			cout << right; cout.width(9); cout << "\xBA";
			cout.width(8); cout << "\xBA\n";
			cout.width(9); cout << "\xBA";
			cout.width(8); cout << "\x4F\n";
			cout.width(9); cout << "\xBA";
			cout.width(9); cout << "\x5C\xB3\x2F\n";
			cout.width(9); cout << "\xBA";
			cout.width(8); cout << "\xB3\n";
			cout.width(10); cout << "\xBA\n";
			cout.width(17); cout << "\xCD\xCD\xCD\xBA\xCD\xCD\xCD\xCD\xCD\xCD\xCD\n";
			cout.width(6); cout << "\xBA";
			cout.width(16); cout << "\xBA\xCD\xCD\xCD\xCD\xCD\n";
			cout.width(6); cout << "\xBA";
			cout.width(16); cout << "\xBA\n";
			cout.width(23); cout << "\xBA\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBA\n\n";
			break;
		}
		case 7:
		{
			cout << "\t\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\n";
			cout << right; cout.width(9); cout << "\xBA";
			cout.width(8); cout << "\xBA\n";
			cout.width(9); cout << "\xBA";
			cout.width(8); cout << "\x4F\n";
			cout.width(9); cout << "\xBA";
			cout.width(9); cout << "\x5C\xB3\x2F\n";
			cout.width(9); cout << "\xBA";
			cout.width(8); cout << "\xB3\n";
			cout.width(9); cout << "\xBA";
			cout.width(7); cout << "\x2F\n";
			cout.width(17); cout << "\xCD\xCD\xCD\xBA\xCD\xCD\xCD\xCD\xCD\xCD\xCD\n";
			cout.width(6); cout << "\xBA";
			cout.width(16); cout << "\xBA\xCD\xCD\xCD\xCD\xCD\n";
			cout.width(6); cout << "\xBA";
			cout.width(16); cout << "\xBA\n";
			cout.width(23); cout << "\xBA\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBA\n\n";
			break;	
		}
		case 8:
		{
			cout << "\t\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\n";
			cout << right; cout.width(9); cout << "\xBA";
			cout.width(8); cout << "\xBA\n";
			cout.width(9); cout << "\xBA";
			cout.width(8); cout << "\x4F\n";
			cout.width(9); cout << "\xBA";
			cout.width(9); cout << "\x5C\xB3\x2F\n";
			cout.width(9); cout << "\xBA";
			cout.width(8); cout << "\xB3\n";
			cout.width(9); cout << "\xBA";
			cout.width(9); cout << "\x2F \x5C\n";
			cout.width(17); cout << "\xCD\xCD\xCD\xBA\xCD\xCD\xCD\xCD\xCD\xCD\xCD\n";
			cout.width(6); cout << "\xBA";
			cout.width(16); cout << "\xBA\xCD\xCD\xCD\xCD\xCD\n";
			cout.width(6); cout << "\xBA";
			cout.width(16); cout << "\xBA\n";
			cout.width(23); cout << "\xBA\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBA\n\n";
			break;	
		}	
	}
}