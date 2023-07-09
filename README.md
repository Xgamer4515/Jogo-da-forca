# Jogo da Forca
Este é um jogo da forca em C++ onde você deve adivinhar uma palavra escolhida aleatoriamente de diferentes categorias. O objetivo do jogo é descobrir a palavra antes que o desenho do enforcado esteja completo.

## Compilação e execução

Certifique-se de ter um compilador C++ instalado em sua máquina. Para compilar o programa, execute o seguinte comando:

g++ -o jogo_da_forca main.cpp

Isso irá gerar o arquivo executável jogo_da_forca. Agora, execute o programa com o seguinte comando:

./jogo_da_forca

## Regras do jogo

1. O jogo irá escolher uma palavra aleatoriamente de uma das categorias disponíveis.
2. Você deve adivinhar a palavra digitando letras uma de cada vez.
3. Se a letra digitada estiver presente na palavra, ela será revelada na posição correta.
4. Se a letra digitada não estiver presente na palavra, você perderá uma tentativa e o desenho do enforcado será incrementado.
5. O jogo termina quando todas as letras da palavra forem adivinhadas ou quando o desenho do enforcado estiver completo.

## Categorias de palavras

O jogo lê as palavras de um arquivo chamado categoria.txt. O arquivo contém 6 categorias diferentes, com 10 palavras em cada categoria. Certifique-se de fornecer um arquivo categoria.txt válido para o jogo funcionar corretamente.

## Limpar a tela
O programa inclui uma função limparTela() para limpar a tela do console. Essa função utiliza comandos específicos para sistemas operacionais Windows e Linux. Certifique-se de ajustar essa função de acordo com o seu sistema operacional, se necessário.

## Continuar ou sair

Após terminar uma rodada do jogo, o programa perguntará se você deseja continuar jogando. Digite 'S' ou 's' para continuar ou 'N' ou 'n' para sair do programa.

Espero que isso ajude a criar um README útil para o código do jogo da forca!
