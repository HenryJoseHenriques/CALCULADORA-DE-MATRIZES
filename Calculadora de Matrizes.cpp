/*Você vai fazer uma calculadora de matrizes 2x2 de inteiros:
-Na primeira tela, vc terá as seguintes opções: 1-Preencher matriz A e B; 2 -
Gerar matriz A e B randômicas;
-Após isso, as matrizes devem aparecer na tela
junto a opção de continuar;
-Na próxima tela, um menu com as operações devem
aparecer, sendo elas (1 - soma, 2 - subtração, 3 - multiplicação, 4 -
"Divisão"(multiplica (1/N)), 5 - calculo do determinante, 6 - Elevar os números
de ambas as matrizes ao quadrado);
-Após o jogador escolhar a operação, uma tela com a matrizes A e B devem
aparacer junto ao resultado da operação escolhida.
-Além disso, deve ser gerado um vetor com a soma de todos os elementos da linha
da matriz A e um vetor com a soma todos os elementos da coluna da matriz B*/

#include <iostream>
#include <time.h>
using namespace std;

#define TAM 3

int main() {

  srand(time(NULL));

  // Declaração das matrizes A e B
  double A[TAM][TAM] = {};
  double B[TAM][TAM] = {};
  double C[TAM][TAM] = {};

  // Menu inicial
  int Options;
  cout << "Calculadora de Matrizes inteiras 3x3."
       << "\n";
  cout << "1-Preencher matriz A e B."
       << "\n";
  cout << "2-Gerar matriz A e B randômicas."
       << "\n";
  do {
    cout << "Escolha uma opção: ";
    cin >> Options;
    cout << "\n";
    if (Options <= 0 || Options > 2)
      cout << "Opção inválida, digite novamente: "
           << "\n";
  } while (Options <= 0 || Options > 2);

  system("clear");

  // Preenchimento das matrizes A e B conforme a escolha do jogador
  switch (Options) {
  case 1:
    for (int i = 0; i < TAM; i++)
      for (int j = 0; j < TAM; j++) {
        cout << "Preencha a Matriz A na posição [" << i << "][" << j << "]: ";
        cin >> A[i][j];
        system("clear");
      }

    system("clear");

    for (int i = 0; i < TAM; i++)
      for (int j = 0; j < TAM; j++) {
        cout << "Preencha a Matriz B na posição [" << i << "][" << j << "]: ";
        cin >> B[i][j];
        system("clear");
      }

    break;

  case 2:

    for (int i = 0; i < TAM; i++)
      for (int j = 0; j < TAM; j++) {
        A[i][j] = rand() % 9 + 1;
      }

    for (int i = 0; i < TAM; i++)
      for (int j = 0; j < TAM; j++) {
        B[i][j] = rand() % 9 + 1;
      }

    break;
  }

  system("clear");

  cout << "Matriz A: "
       << "\n";
  for (int i = 0; i < TAM; i++) {
    for (int j = 0; j < TAM; j++)
      cout << A[i][j] << "\t";

    cout << "\n";
  }

  cout << "\n";

  cout << "Matriz B: "
       << "\n";
  for (int i = 0; i < TAM; i++) {
    for (int j = 0; j < TAM; j++)
      cout << B[i][j] << "\t";

    cout << "\n";
  }

  cout << "\n";

  // Menu de operações
  cout << "Escolha uma operação:"
       << "\n";
  cout << "1-Soma"
       << "\n";
  cout << "2-Subtração"
       << "\n";
  cout << "3-Multiplicação"
       << "\n";
  cout << "4-Elevar todos os elementos ao quadrado"
       << "\n";
  cout << "5-Transpor a Matriz A e B e exibir na tela"
       << "\n";
  int Options2;
  do {
    cin >> Options2;
    if (Options2 <= 0 || Options2 > 6)
      cout << "Opção inválida, digite novamente: ";
  } while (Options2 <= 0 || Options2 > 6);

    system("clear");
  
  switch (Options2) {
  case 1:
    for (int i = 0; i < TAM; i++)
      for (int j = 0; j < TAM; j++)
        C[i][j] = A[i][j] + B[i][j];

    break;

  case 2:
    for (int i = 0; i < TAM; i++)
      for (int j = 0; j < TAM; j++)
        C[i][j] = A[i][j] - B[i][j];
    break;

  case 3:
    cout << "Escolha uma opção: \n";
    cout << "1-Multiplica A por B \n";
    cout << "2-Multillicar A e B por um número \n";
    int Options3;
    do {
      cin >> Options3;
      if (Options3 <= 0 || Options3 > 2)
        cout << "opção inválida, digite novamente: \n";
    } while (Options3 <= 0 || Options3 > 2);

    switch (Options3) {

    case 1:
      for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
          C[i][j] += A[i][j] * B[i][j];
      break;

    case 2:
      cout << "Escolha um número para ser multiplicado pelos elementos da "
              "Matriz A e B: ";
      int N;
      cin >> N;
      for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
          A[i][j] = A[i][j] * N;

      for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
          B[i][j] = B[i][j] * N;
      break;
    }
    break;
    
  case 4:
    for (int i = 0; i < TAM; i++)
      for (int j = 0; j < TAM; j++)
        A[i][j] = A[i][j] * A[i][j];

    for (int i = 0; i < TAM; i++)
      for (int j = 0; j < TAM; j++)
        B[i][j] = B[i][j] * B[i][j];
    break;

  case 5:
    for (int i = 0; i < TAM; i++)
      for (int j = 0; j < TAM; j++)
        A[j][i] = A[i][j];

    for (int i = 0; i < TAM; i++)
      for (int j = 0; j < TAM; j++)
        B[j][i] = B[i][j];
    break;
  }

  cout << "Segue o resultado das operações: "
       << "\n";
  cout << "Matriz A: \n";
  for (int i = 0; i < TAM; i++) {
    for (int j = 0; j < TAM; j++)
      cout << A[i][j] << "\t";
    cout << "\n";
  }

  cout << "\n";

  cout << "Matriz B: \n";
  for (int i = 0; i < TAM; i++) {
    for (int j = 0; j < TAM; j++)
      cout << B[i][j] << "\t";
    cout << "\n";
  }

  cout << "\n";

  cout << "Matriz C: \n";
  for (int i = 0; i < TAM; i++) {
    for (int j = 0; j < TAM; j++)
      cout << C[i][j] << "\t";
    cout << "\n";
  }
}