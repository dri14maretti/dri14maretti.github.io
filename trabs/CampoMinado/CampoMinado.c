#include <stdlib.h>
#include<stdio.h>
#include<math.h>
#include<locale.h>
#include <time.h>


  typedef enum {true,false} bool;
  char visual[10][10], gabarito[10][10];
  int i, j, jogadas;
  bool verifica;
  char rep;


void inicializa (){
int i, j;


  for (i = 0; i <= 9; i++){
   for (j = 0; j <= 9; j++){
      visual[i][j] = '?';
      gabarito[i][j] = ' ';
    }
  }
}

void imprime() {
int i, j;
   printf("    ");
   for (j = 1; j <= 10; j++){
         printf(" %d  ",j);
   }

   printf("\n");

   for (i = 0; i <= 9; i++){
     for (j = 0; j <= 9; j++){
       if ((i <= 9) && (j == 0)) {
         printf(" ");
       }
       fflush(stdin);
       if ((j == 0) && (i < 9)){
         printf("%d  [%2c]", i + 1 ,visual[i][j] );

       }
         else if ((j == 0) && (i == 9)){
             printf("%d [%2c]", i + 1 ,visual[i][j] );
         }
         else if ((j > 0) && (j <= 8)) {
             fflush(stdin);
             printf("[%2c]", visual[i][j]);
         }
         else if (j == 9) {
             fflush(stdin);
             printf("[%2c]\n", visual[i][j]);
         }

      }
  }
  };


void sorteia (){
int i, j, linha, coluna, ver;
  srand(time(NULL));

  for (i = 0; i <= 9; i++){
    linha = rand() % 10;
    coluna = rand() % 10;
    gabarito[linha][coluna] = '*';
  }

  for (i = 0; i <= 9; i++){
    for (j = 0; j <= 9; j++){
      if (gabarito[i][j] == '*'){
          ver = ver + 1;
  }
      else {
        ver = ver;
      }
    }
  }

   if(ver < 10){
        linha = rand() % 10;
        coluna = rand() % 10;
        gabarito[linha][coluna] = '*';
      }
}

bool tembomba (int i, int j){

    if (gabarito[i-1][j-1] == '*'){
      return (true);
    }
     else{
        if (visual[i-1][j-1] == '?'){
        visual[i-1][j-1] = gabarito [i-1][j-1];
        jogadas = jogadas + 1;
        return(false);
     }
    }

}

int numeroDeBombas (int linha, int coluna){
    int cont = 0; //contador de bombas

    linha = linha - 1;
    coluna = coluna - 1;

    if ((gabarito[linha][coluna + 1] == '*') && (coluna + 1 >= 0)){
        cont = cont + 1;
    }
    if ((gabarito[linha][coluna - 1] == '*') && (coluna - 1 >= 0)){
        cont = cont + 1;
    }
    if ((gabarito[linha + 1][coluna] == '*') && (linha + 1 >= 0) && (coluna >= 0)){
        cont = cont + 1;
    }
    if ((gabarito[linha - 1][coluna - 1] == '*') && (coluna - 1 >= 0) && (linha - 1 >= 0)){
        cont = cont + 1;
    }
    if ((gabarito[linha + 1][coluna + 1] == '*') && (coluna + 1 >= 0) && (linha + 1 >= 0)){
        cont = cont + 1;
    }
    if ((gabarito[linha + 1][coluna - 1] == '*') && (coluna - 1 >= 0) && (linha + 1 >= 0)){
        cont = cont + 1;
    }
    if ((gabarito[linha - 1][coluna + 1] == '*') && (coluna + 1 >= 0) && (linha - 1 >= 0)){
        cont = cont + 1;
    }
    if ((gabarito[linha - 1][coluna] == '*') && (linha - 1 >= 0)){
        cont = cont + 1;
    }

    switch (cont){
        case 0 :
            visual[linha][coluna] = '0';
            break;

        case 1 :
            visual[linha][coluna] = '1';
            break;

        case 2 :
            visual[linha][coluna] = '2';
            break;

        case 3 :
            visual[linha][coluna] = '3';
            break;

        case 4 :
            visual[linha][coluna] = '4';
            break;

        case 5 :
            visual[linha][coluna] = '5';
            break;

        case 6 :
            visual[linha][coluna] = '6';
            break;

        case 7 :
            visual[linha][coluna] = '7';
            break;

        case 8 :
            visual[linha][coluna] = '8';
            break;

return 0;



    }


};

int main(){
 int k, n;
 rep = 's';

 printf("\n-----------------------------------------------------------|\n");
 printf(" 1 - Digite um numero de linha e coluna por vez [1,10]     |\n");
 printf(" 2 - Aperte enter apos digita-los                          |\n");
 printf(" 3 - Nao escolha a mesma casa mais de uma vez              |\n");
 printf(" 4 - Nao digite um numero de linha ou coluna nao existente |\n");
 printf(" 5 - Caso perca e quiser jogar novamente, digite 's'       |\n");
 printf(" 6 - Para encerrar o programa apos perder, digite 'n'      |\n");
 printf(" 7 - Digite a linha, aperte enter.                         |\n");
 printf(" 8 - Digite a coluna, aperte enter.                        |\n");
 printf(" 9 - Digite 0 na linha caso queira marcar uma bomba        |\n");
 printf("-----------------------------------------------------------|\n\n");

 while (rep == 's'){
    jogadas = 0;

    verifica = false;

    inicializa();

    sorteia();


 while ((verifica == false) && (jogadas < 90)){

    imprime();

    printf("\njogadas = %d\n", jogadas);
    printf("digite linha: ");
    fflush(stdin);
    scanf("%d", &i);
    printf("digite coluna: ");
    fflush(stdin);
    scanf("%d", &j);
    printf("\n");

    if (((i >=1) && (i <= 10)) && ((j >= 1) && (j <= 10))){
    verifica = tembomba(i, j);
    numeroDeBombas (i, j);

    }
    if (j == 1313){
        jogadas = 90;
    }

    if ((i == 0) || (j == 0)){
        printf("\n - Digite a linha da bomba : ");
        scanf("%d", &k);
        printf("\n - Digite a coluna da bomba : ");
        scanf("%d", &n);

        visual[k - 1][n - 1] = 'b';
    }


 }

 if (jogadas == 90){
    printf("\n----------------------------------\n");
    printf("    COMEU A BRUNA MARQUEZINE!    \n");
    printf("----------------------------------\n");
    printf("Deseja jogar novamente? ( )\b\b");
    getchar();
    rep = getchar();
    printf("\n\n");
 }
 else{
    printf("\n------------------\n");
    printf("     SE FODEU!    \n");
    printf("--------------------\n");
    printf("Deseja jogar novamente? ( )\b\b");
    getchar();
    rep = getchar();
    printf("\n\n");

    }
 }

   system("pause");
   return 0;


}
