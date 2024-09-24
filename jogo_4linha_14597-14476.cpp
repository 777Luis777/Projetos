#include <iostream>
#include <string>
#include <cmath>
#include <stdio.h> /* printf, scanf, puts, NULL */


using namespace std;

const int colunas = 8; // numero de colunas do tabuleiro
const int linhas = 6; // numero de linhas do tabuleiro

void iniciojogo() { //função que inicia o jogo pergunta ao utilizador se pretende jogar ou siar
    cout << "***** BEM VINDO AO JOGO 4 EM LINHA *****\n" << endl;
    cout << "O que quer fazer\n\n1 - Iniciar o jogo\n0 - Fechar" << endl;
}

void mostrartabuleiro(string tabuleiro[colunas][linhas]) { // funcao que mostra o tabuleiro direito com as linhas e as colunas( foi reutilizada do ex 12)
    cout << "\n     * TABULEIRO *" << endl << endl;

    for (int y = linhas - 1; y >= 0; y--) {
        for (int x = 0; x < colunas; x++) {
            if (x > 0) cout << " | ";
            if (tabuleiro[x][y] != "") {
                cout << tabuleiro[x][y];
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }
    cout << "-------------------------------" << endl;
    for (int x = 0; x < colunas; x++) {
        if (x > 0) cout << "| ";
        cout << " " << x;
    }
    cout << endl << endl;
}

void pedirelemento(string tabuleiro[colunas][linhas], bool& jogador1) { // funcao que insere os elementos no tabuleiro ( tamberm reutilizada do ex 12)
    int coluna, linha;                                                  // troca os jogadores e verifica se a coluna que a jogador quer inserir esta livre
    string elemento = (jogador1) ? "X" : "O";
    string jogador = (jogador1) ? "Jogador 1" : "Jogador 2";
    bool encontroulivre = false;


    cout << "\n\n" << jogador << ", onde queres jogar (0 / 1 / 2 / 3 / 4 / 5 / 6 / 7)? : ";
    cin >> coluna;

    if (coluna < 0 || coluna >= colunas) {
        cout << "\nColuna inválida. Por favor, escolha uma coluna entre 0 e " << colunas - 1 << endl;
        return;
    }

    for (int i = 0; i < linhas; i++) {
        if (tabuleiro[coluna][i] == "") {
            tabuleiro[coluna][i] = elemento;
            encontroulivre = true;
            break;
        }
    }
      if (!encontroulivre) {
        cout << "\n\nA coluna [" << coluna  << "] esta cheia" << endl;
        return;
        }

    // Alternar o jogador
    jogador1 = !jogador1;
}
bool tabuleirocheio(string tabuleiro[colunas][linhas]) { // verifica se o tabuleiro esta cheio
    for (int x = 0; x < colunas; x++) {
        for (int y = 0; y < linhas; y++) {
            if (tabuleiro[x][y] == "") {
                return false;
            }
        }
    }
    return true;
}
bool alguemganhou (string tabuleiro[colunas][linhas]) { // verifica se alguem ganhou e todas as probabilidades possiveis
    int jogador1_vitorias = 0;
    int jogador2_vitorias = 0;


    for (int y = 0; y < linhas; y++) {
        for (int x = 0; x < colunas - 3; x++) {
            if (tabuleiro[x][y] == tabuleiro[x+1][y] && tabuleiro[x+1][y] == tabuleiro[x+2][y] && tabuleiro[x+2][y] == tabuleiro[x+3][y] && tabuleiro[x][y] != "") {
                if (tabuleiro[x][y] == "X") {
                    jogador1_vitorias++;
                } else {
                    jogador2_vitorias++;
                }
            }
        }
    }


    for (int y = 0; y < linhas - 3; y++) {
        for (int x = 0; x < colunas; x++) {
            if (tabuleiro[x][y] == tabuleiro[x][y+1] && tabuleiro[x][y+1] == tabuleiro[x][y+2] && tabuleiro[x][y+2] == tabuleiro[x][y+3] && tabuleiro[x][y] != "") {
                if (tabuleiro[x][y] == "X") {
                    jogador1_vitorias++;
                } else {
                    jogador2_vitorias++;
                }
            }
        }
    }


    for (int y = 0; y < linhas - 3; y++) {
        for (int x = 0; x < colunas - 3; x++) {
            if (tabuleiro[x][y] == tabuleiro[x+1][y+1] && tabuleiro[x+1][y+1] == tabuleiro[x+2][y+2] && tabuleiro[x+2][y+2] == tabuleiro[x+3][y+3] && tabuleiro[x][y] != "") {
                if (tabuleiro[x][y] == "X") {
                    jogador1_vitorias++;
                } else {
                    jogador2_vitorias++;
                }
            }
        }
    }

    for (int y = 0; y < linhas - 3; y++) {
        for (int x = 3; x < colunas; x++) {
            if (tabuleiro[x][y] == tabuleiro[x-1][y+1] && tabuleiro[x-1][y+1] == tabuleiro[x-2][y+2] && tabuleiro[x-2][y+2] == tabuleiro[x-3][y+3] && tabuleiro[x][y] != "") {
                if (tabuleiro[x][y] == "X") {
                    jogador1_vitorias++;
                } else {
                    jogador2_vitorias++;
                }
            }
        }
    }


    if (jogador1_vitorias > 0) {
        return true;
    } else if (jogador2_vitorias > 0) {
        return true;
    } else {
        return false;
    }
}
bool terminoujogo(string tabuleiro[colunas][linhas]) { // verifica as funções alguem ganhou e tabuleirocheio para ver se o jogo acabou ou não
    if (alguemganhou(tabuleiro) || tabuleirocheio(tabuleiro)) {
        return true;
    }
    return false;
}

int main() {
    string tabuleiro [colunas][linhas];
    bool jogador1 = true;
    bool terminoujogo = false;

    iniciojogo();
    int escolha;
    cin >> escolha;
    system("cls");
    cout << "O jogador 1 e o X\nO jogador 2 e a O" << endl;
        do {//ciclo para chamar as variaveis
                mostrartabuleiro(tabuleiro);
                pedirelemento(tabuleiro, jogador1);

            if (alguemganhou(tabuleiro)) {
                cout << "\nParabens, ganhaste queres um balao   :)\n" << endl;
                break;
            } else if (tabuleirocheio(tabuleiro)) {
                cout << "O jogo terminou empatado.";
                break;
            }
    } while (!terminoujogo);

    return 0;
}
