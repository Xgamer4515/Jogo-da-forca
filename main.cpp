#include "forca.cpp"

int main()
{
    PlayGame();

    char resp = 'S';
    cout << "Deseja continuar (S/N)? ";
    cin >> resp;

    while (resp != 'N' && resp != 'n')
    {
        PlayGame();
        cout << "Deseja continuar (S/N)? ";
        cin >> resp;
        limparTela();
    }

    cout << "\n\nObrigado por jogar o jogo da forca!\n";
    cout << "By: Samuel Silva Santos\n";
    return 0;
}