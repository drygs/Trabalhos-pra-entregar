#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <ctime>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <unistd.h>
#include <fstream>
#include <random>

using namespace std;


string numeroEmVermelho(int destaque) {
    return "\033[31m" + to_string(destaque) + "\033[0m";
}

void showNumbersGrid(const vector<string>& vetorcolorido, int columns) {
    const int fixedWidth = 3;

    for (int i = 1; i < vetorcolorido.size(); i++) {
        cout << setw(fixedWidth) << setfill(' ') << right << vetorcolorido[i] << " ";

        if ((i + 1) % columns == 0) {
            cout << endl;
        }
    }
}




int main() {
    int manualAutomatico;
    int ciclo = 1;
    int bingoNumeros = 1;
    int cicloBingo = 1;
    int sorteioAnterior = 0;
    int anterior = 0;
    const int fixedWidth = 3;
    int numerosCartoes = 1;
    string blue = "\033[1;34m";
    string resetColor = "\033[0m";
    int arraycartão[100];
    int contador;

    srand(time(0));

    for (int i = 0; i < ciclo; i++) {
        system("clear || cls");

        cout << blue << "\nEscolha a opção:\n\n1 - Sorteio Manual \n2 - Sorteio Automático\n3 - Gerar Cartões\n4 - Sair\n" << resetColor << endl;
        cin >> manualAutomatico;
        system("clear || cls");

        if (manualAutomatico == 1 || manualAutomatico == 2 || manualAutomatico == 3) {
            cout << blue << "Escolha a quantidade de números (75, 90, 100): " << resetColor << endl;
            cin >> bingoNumeros;

            int arraycartão[bingoNumeros];

            if(bingoNumeros == 100){
                bingoNumeros = 101;
            }
            else if(bingoNumeros == 90){
                bingoNumeros = 91;
            }
            else if(bingoNumeros == 75){
                bingoNumeros = 76;
            }else{
                cout << blue << "Escolha uma opção disponivel" << resetColor << endl; 
            }



        } else {
            system("clear || cls");
        }

        system("clear || cls");

        vector<int> meusNumeros(bingoNumeros);
        iota(meusNumeros.begin(), meusNumeros.end(), 0);
        vector<string> vetorColorido;

        for (const auto& destaque : meusNumeros) {
            string tabela = (destaque == sorteioAnterior) ? numeroEmVermelho(destaque) : to_string(destaque);
            vetorColorido.push_back(tabela);
        }

        for (int j = 0; j < cicloBingo; j++) {
            cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n" << endl;
            showNumbersGrid(vetorColorido, 20);
            cout << "\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n" << endl;

            if (manualAutomatico == 3 || manualAutomatico == 4) {
                system("cls || clear");
            }

            int nSorteado = rand() % bingoNumeros;
            int nSelecionado = meusNumeros[nSorteado];

            if (manualAutomatico == 1) {
                if (meusNumeros[nSorteado] != 0) {
                    anterior = sorteioAnterior;
                    cout << "Sorteio anterior..: " << anterior << endl;
                    cout << "Sorteado..........: " << vetorColorido[nSorteado] << endl;
                    sorteioAnterior = nSelecionado;
                    cicloBingo++;
                    cout << "Pressione ENTER para sortear a próxima bola" << endl;
                    vetorColorido[nSorteado] = numeroEmVermelho(nSorteado);
                    meusNumeros[nSorteado] = 0;
                    cin.ignore();
                    system("cls || clear");
                } else {
                    cicloBingo++;
                    system("cls || clear");
                }
            } else if (manualAutomatico == 2) {
                if (meusNumeros[nSorteado] != 0) {
                    anterior = sorteioAnterior;
                    cout << blue << "Sorteio anterior..: " << anterior << resetColor << endl;
                    cout << blue << "Sorteado..........: " << vetorColorido[nSorteado] << resetColor << endl;
                    sorteioAnterior = nSelecionado;
                    vetorColorido[nSorteado] = numeroEmVermelho(nSorteado);
                    meusNumeros[nSorteado] = 0;
                    sleep(1);
                    cicloBingo++;
                    system("cls || clear");
                } else {
                    cicloBingo++;
                    system("cls || clear");
                }
            } else if (manualAutomatico == 3) {

                cout << blue << "Quantos cartoes pertende gerar? " << resetColor << endl;
                cin >> numerosCartoes;

                for(int i = 1; i < bingoNumeros; i++){
                    arraycartão[i] = i;
                }
                
                random_device rd;
                mt19937 g(rd());
                shuffle(arraycartão, arraycartão + bingoNumeros, g);

                for (int i = 1; i <= numerosCartoes; i++) {
                    for(int j = 0;j <= 24; j++) {
                        random_device rd;
                        mt19937 g(rd());
                        shuffle(arraycartão, arraycartão + bingoNumeros, g);
                    }
                    ofstream file("cartao" + to_string(i) + ".txt");
                    if (file.is_open()) {

                        file << setw(2) << right << arraycartão[1] << " " << arraycartão[2] << " " << arraycartão[3] << " " << arraycartão[4] << " " << arraycartão[5] <<"\n"
                             << arraycartão[6] << " " << arraycartão[7] << " " << arraycartão[8] << " " << arraycartão[9] << " " << arraycartão[10] << "\n"
                             << arraycartão[11] << " " <<  arraycartão[12] << " X " << arraycartão[13] << " " << arraycartão[14] <<"\n"
                             << arraycartão[15] << " " << arraycartão[16] << " " << arraycartão[17] << " " << arraycartão[18] << " " << arraycartão[20]<<"\n"
                             << arraycartão[21] << " " <<  arraycartão[22] << " " << arraycartão[23] << " " << arraycartão[24] << " " << arraycartão[25] << endl;
                        file.close();
                    } else {
                        cout << blue << "Erro ao abrir o arquivo para o cartão " << resetColor << i << endl;
                    }
                }
                bingoNumeros++;
            } else if (manualAutomatico == 4) {
                break;
            } else {
                cout << blue << "Escolha uma opção válida." << resetColor << endl;
                ciclo++;
            }
        }
    }
    return 0;
}
