#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
int larva = 0, sais = 1, algas = 0, jogadas = 0;
char tanque [25][50];
typedef enum {false, true} bool;

void inicializa(){
    int i, j, cont;
    for(i = 0; i < 25; i++){
        for(j = 0; j < 50; j++){
            tanque[i][j] = ' ';
        }
    }
    while(cont < 2){     //Triangulo de 3 linhas
        i = rand() % 25;
        j = rand() % 50;
        if((i != 0) && (i != 24) && (j < 48) && (j > 1)){
            if((tanque[i][j] == ' ') && (tanque[i-1][j] == ' ') && (tanque[i][j+1] == ' ') && (tanque[i][j-1] == ' ') &&
               (tanque[i+1][j] == ' ') && (tanque[i+1][j+1] == ' ') && (tanque[i+1][j+2] == ' ') && (tanque[i+1][j-1] == ' ') &&
               (tanque[i+1][j-1] == ' ')){

                tanque[i][j] = ':';
                tanque[i-1][j] = ':';
                tanque[i][j + 1] = ':';
                tanque[i][j - 1] = ':';
                tanque[i+1][j] = ':';
                tanque[i+1][j + 1] = ':';
                tanque[i+1][j + 2] = ':';
                tanque[i+1][j - 1] = ':';
                tanque[i+1][j - 2] = ':';
                cont++;
            }
        }
    }
    cont = 0;
    while(cont < 3){ //Triangulo de 2 linhas
        i = rand() % 25;
        j = rand() % 50;
        if((i != 0) && (j != 0) && (j != 49)){
            if((tanque[i][j] == ' ') && (tanque[i-1][j] == ' ') && (tanque[i][j+1] == ' ') && (tanque[i][j-1] == ' ')){

                tanque[i][j] = ':';
                tanque[i-1][j] = ':';
                tanque[i][j + 1] = ':';
                tanque[i][j - 1] = ':';
                cont++;
            }
        }
    }

    cont = 0;
    while(cont < 10){
        i = rand() % 25;
        j = rand() % 50;
        if(tanque[i][j] == ' '){
            tanque[i][j] = '@';
            cont++;
        }
    }

    cont = 0;
    while(cont < 5){
        i = rand() % 25;
        j = rand() % 50;
        if(tanque[i][j] == ' '){
            tanque[i][j] = 'y';
            cont++;
        }
    }

    cont = 0;
    while(cont < 3){
        i = rand() % 25;
        j = rand() % 50;
        if(tanque[i][j] == ' '){
            tanque[i][j] = 'x';
            cont++;
        }
    }
}
void imprime(){
    int i, j;
    printf("     ");
    for(j = 0; j < 50; j++){
        printf("%d  ", j);
    }
    printf("\n");

    for(i = 0; i < 25; i++){
        for(j = 0; j < 50; j++){
            if ((j == 0) && (i < 10)){
                printf("[%d]  %c  ", i, tanque[i][j]);
            }
            if ((j == 0) && (i >= 10)){
                printf("[%d] %c  ", i, tanque[i][j]);
            }
            if ((j > 0) && (j < 10)){
                printf("%c  ", tanque[i][j]);
            }
            if ((j >= 10) && (j < 49)){
                printf("%c   ", tanque[i][j]);
            }
            if(j == 49){
                printf("%c \n", tanque[i][j]);
            }
        }
    }


}
void cultivar(){
    int i, j;
    char op;
    bool conf = false;
    if(algas > 0){
        while(conf == false){
            printf("Linha para cultivo : ");
            scanf("%d", &i);
            printf("Coluna para cultivo : ");
            scanf("%d", &j);
            if(tanque[i][j] == ' '){
                tanque[i][j] = 'y';
                algas--;
                jogadas++;
                conf = true;
            }
            else{
                printf("\n|A posicao escolhida nao esta vazia|\n");
                op = ' ';
                while((op != 's') && (op != 'n')){
                    printf("Deseja cancelar o cultivo?\ns - sim\nn - nao\n( )\b\b");   //Caso nao se tenha mais posi��es vazias, serve p/ o jogador n�o ficar preso na opcao
                    scanf(" %c", &op);
                    switch (op){
                        case 's' :
                            conf = true;
                        break;

                        case 'n' :
                            conf = false;
                        break;

                        default :
                            printf("Opcao Invalida\n");
                        break;
                    }
                }
            }
        }
    }
    else{
        printf("\n|Nao ha algas suficientes|\n\n");
    }
}
void fertilizar(){
    int i, j;
    char op;
    bool conf = false, conf2 = true; //Conf serve para conferir se a posicao selecionada esta correta.
    if(sais > 0){
        while(conf == false){
            printf("Linha para fertilizacao : ");
            scanf("%d", &i);
            printf("Coluna para fertilizacao : ");
            scanf("%d", &j);
            if(tanque[i][j] == 'y'){
                tanque[i][j] = 'Y';
                jogadas++;
                sais--;
                conf = true;
            }
            else{
                printf("\n|A posicao selecionada nao contem uma alga|\n");
                op = ' ';
                while((op != 's') && (op != 'n')){
                    printf("Deseja cancelar a fertilizacao?\ns - sim\nn - nao\n( )\b\b");
                    scanf(" %c", &op);
                    switch (op){
                        case 's' :
                            conf = true;
                        break;

                        case 'n' :
                            conf = false;
                        break;

                        default :
                            printf("Opcao Invalida\n");
                        break;
                    }
                }
            }
        }
    }
    else{
        printf("\n|Nao ha sais suficientes|\n\n");
    }
}
void mover(){
    int i, j, movi, movj;
    bool conf = false, conf2 = true;
    char op, m;
    while (conf == false){
        printf("Linha do peixe que se deseja mover : ");
        scanf("%d", &i);
        printf("Coluna do peixe que se deseja mover : ");
        scanf("%d", &j);
        if((tanque[i][j] == '-') || (tanque[i][j] == 'x') || (tanque[i][j] == 'X')){ //Verifica se eh peixe
            conf2 = true;
            while(conf2 == true){
                printf("\nMover para :      E    N    R \n");
                printf("                       ^   \n");
                printf("                  O <     > L \n");
                printf("                       v    \n");
                printf("                  A    S    C \n");
                printf("( )\b\b");
                scanf(" %c", &m);
                switch(m) {                                    //Escolhendo p/ onde mover o peixe
                case 'E' :
                    if((i - 1 >= 0) && (j - 1 >= 0)){ //Verifica se a posicao escolhida existe
                        movi = -1;
                        movj = -1;
                        conf2 = false;
                    }
                    else {
                        printf("\n|Impossivel mover para a localidade desejada|\n");
                        movi = 0;
                        movj = 0;
                        conf2 = true;
                    }
                break;

                case 'N':
                    if((i - 1 >= 0) && (j>= 0)){
                        movi = -1;
                        movj = 0;
                        conf2 = false;
                    }
                    else {
                        printf("\n|Impossivel mover para a localidade desejada|\n");
                        movi = 0;
                        movj = 0;
                        conf2 = true;
                    }
                break;

                case 'R' :
                    if((i - 1 >= 0) && (j + 1 < 50)){
                       movi = -1;
                       movj = 1;
                       conf2 = false;
                    }
                    else {
                        printf("\n|Impossivel mover para a localidade desejada|\n");
                        movi = 0;
                        movj = 0;
                        conf2 = true;
                    }
                break;

                case 'O' :
                    if (j - 1 >= 0){
                        movi = 0;
                        movj = -1;
                        conf2 = false;
                    }
                    else {
                        printf("\n|Impossivel mover para a localidade desejada|\n");
                        movi = 0;
                        movj = 0;
                        conf2 = true;
                    }
                break;

                case 'L' :
                    if(j + 1 < 50){
                        movi = 0;
                        movj = 1;
                        conf2 = false;
                    }
                    else {
                        printf("\n|Impossivel mover para a localidade desejada|\n");
                        movi = 0;
                        movj = 0;
                        conf2 = true;
                    }
                break;

                case 'A' :
                    if((i + 1 < 25) && (j - 1 >= 0)){
                        movi = 1;
                        movj = -1;
                        conf2 = false;
                    }
                    else {
                        printf("\n|Impossivel mover para a localidade desejada|\n");
                        movi = 0;
                        movj = 0;
                        conf2 = true;
                    }
                break;

                case 'S' :
                    if(i+1 < 25){
                        movi = 1;
                        movj = 0;
                        conf2 = false;
                    }
                    else {
                        printf("\n|Impossivel mover para a localidade desejada|\n");
                        movi = 0;
                        movj = 0;
                        conf2 = true;
                    }
                break;

                case 'C' :
                    if((i+1 < 25) && (j+1 < 50)){
                        movi = 1;
                        movj = 1;
                        conf2 = false;
                    }
                    else {
                        printf("\n|Impossivel mover para a localidade desejada|\n");
                        movi = 0;
                        movj = 0;
                        conf2 = true;
                    }
                break;

                default :
                    printf("\n|Opcao escolhida nao existe|\n");
                    conf2 = true;
                }

            }
            if(tanque[i+movi][j+movj] == ' '){     //Verifica se o espa�o p onde se quer mover est� vazio
                if(tanque[i][j] == '-'){
                    tanque[i+movi][j+movj] = tanque[i][j];
                    tanque[i][j] = ' ';
                    conf = true;
                    jogadas++;
                }
                if(tanque[i][j] == 'x'){
                    tanque[i+movi][j+movj] = tanque[i][j];
                    tanque[i][j] = ' ';
                    conf = true;
                    jogadas++;
                }
                if(tanque[i][j] == 'X'){
                    if((tanque[i+movi][j+movj-1] == 'x') || (tanque[i+movi][j+movj+1] == 'x')){
                        tanque[i+movi][j+movj] = '-';
                        tanque[i][j] = ' ';
                        conf = true;
                        jogadas++;
                        sais = sais + 2;
                        larva++;
                    }
                    else{
                        tanque[i+movi][j+movj] = tanque[i][j];
                        tanque[i][j] = ' ';
                        conf = true;
                        jogadas++;

                    }
                }
            }
            if((tanque[i+movi][j+movj] == '@') || (tanque[i+movi][j+movj] == ':')){
                tanque[i][j] = ' ';
                printf("\n|Parabens Corno, Peixe Morto|\n\n");
                conf = true;
                jogadas++;
            }
            if((tanque[i+movi][j+movj] == 'y')){
                switch(tanque[i][j]){
                    case '-' :
                        tanque[i+movi][j+movi] = 'x';
                    break;

                    case 'x' :
                        tanque[i+movi][j+movj] = 'X';
                    break;

                    case 'X' :
                        tanque[i+movi][j+movj] = 'X';
                    break;
                }
                tanque[i][j] = ' ';
                jogadas++;
                conf = true;
            }
            if((tanque[i+movi][j+movj] == 'Y')){
                switch(tanque[i][j]){
                    case '-' :
                        tanque[i+movi][j+movi] = 'x';
                    break;

                    case 'x' :
                        tanque[i+movi][j+movj] = 'X';
                    break;

                    case 'X' :
                        tanque[i+movi][j+movj] = 'X';
                    break;
                }
                tanque[i][j] = ' ';
                jogadas++;
                conf = true;
                algas++;
                printf("\n\n|*Obteve 1 Alga*|\n");
            }
        }
        else{
            printf("|Nao ha peixe na posicao escolhida|\n\n");
            conf = false;
            op = ' ';
            while((op != 's') && (op != 'n')){
                printf("Deseja cancelar a operacao?\ns - sim\nn - nao\n( )\b\b");
                scanf(" %c", &op);
                switch (op){
                    case 's' :
                        conf = true;
                    break;

                    case 'n' :
                        conf = false;
                    break;

                    default :
                        printf("Opcao Invalida\n");
                    break;
                }
            }
        }
    }
}
void quebrar(){
    int i, j, sort;
    bool conf = false;
    char op;
    while(conf == false){
        printf("Linha da concha que se deseja quebrar :");
        scanf("%d", &i);
        printf("Coluna da concha que se deseja quebrar :");
        scanf("%d", &j);
        if(tanque[i][j] == '@'){
            sort = abs(rand() % 101);
            if((sort >= 0) && (sort < 25)){
                sais++;
                printf("\n\n|*Obtido 1 sal mineral*|\n\n");
            }
            if((sort >= 25) && (sort < 50)){
                larva++;
                printf("\n\n|*Obtida 1 larva*|\n\n");
            }
            if((sort >= 50) && (sort < 75)){
                algas++;
                printf("\n\n|*Obtida 1 alga*|\n\n");
            }
            if((sort >= 75) && (sort < 85)){
                sais = sais + 2;
                printf("\n\n|*Obtidos 2 sais minerais*|\n\n");
            }
            if((sort >= 85) && (sort < 95)){
                larva = larva + 2;
                printf("\n\n|*Obtidas 2 larvas*|\n\n");
            }
            if((sort >= 95) && (sort < 100)){
                algas = algas + 2;
                printf("\n\n|*Obtidas 2 algas*|\n\n");
            }
            conf = true;
            tanque[i][j] = ' ';
            jogadas++;
        }
        else{
            printf("\n|*Nao ha conchas nesta posicao*|\n\n");
            op = ' ';
            while((op != 'n') && (op != 's')){
                printf("Deseja cancelar a operacao?\ns - sim\nn - nao\n( )\b\b");
                scanf(" %c", &op);
                switch (op){
                    case 's':
                        conf = true;
                    break;

                    case 'n' :
                        conf = false;
                    break;

                    default :
                        printf("Opcao invalida\n");
                    break;
                }
            }
        }

    }
}
void pescar(){
    int i, j;
    bool conf = false;
    char op;
    if(larva > 0){
        while(conf == false){
            printf("Digite a linha do peixe que sera pescado : ");
            scanf("%d", &i);
            printf("Digite a coluna do peixe que sera pescado : ");
            scanf("%d", &j);
            if((tanque[i][j] == 'x') || (tanque[i][j] == 'X')){
                switch (tanque[i][j]){
                    case 'x' :
                        sais++;
                        printf("\n|*1 sal obtido|\n\n");
                    break;

                    case 'X' :
                        sais = sais + 2;
                        larva++;
                        printf("\n|*Dois sais e uma larva obtidos*|\n\n");
                    break;
                }
                tanque[i][j] = ' ';
                larva--;
                conf = true;
                jogadas++;
            }
            else{
                printf("\n|A posi��o selecionada n�o cont�m nenhum peixe|\n");
                op = ' ';
                while((op != 's') && (op != 'n')){
                    printf("Deseja cancelar a fertilizacao?\ns - sim\nn - nao\n( )\b\b");
                    scanf(" %c", &op);
                    switch (op){
                        case 's' :
                            conf = true;
                        break;

                        case 'n' :
                            conf = false;
                        break;

                        default :
                            printf("Opcao Invalida\n");
                        break;
                    }
                }
            }
        }
    }
    else{
        printf("\n|Nao ha larvas suficientes|\n\n");
    }
}
void noite(){
    int i, j, sort, conti, contj;
    bool conf = false;
    for(i = 0; i < 25; i++){
        for(j = 0; j < 50; j++){
            if(tanque[i][j] == '-'){                            //Crescer o '-'
                sort = rand() % 10;
                if((sort >= 0) && (sort < 3)){
                    tanque[i][j] = 'x';
                }
            }
            if(tanque[i][j] == 'y'){                                //Crescer o y
                sort = rand() % 2;
                if(sort == 1){
                    tanque[i][j] = 'Y';
                }
            }
            if(tanque[i][j] == '@'){                                           //Tirar tudo de volta do '@'
                for(conti = i-1; conti <= i+1; conti++){
                    for(contj = j-1; contj <= j+1; contj++){
                        if((tanque[conti][contj] != ':') && (tanque[conti][contj] != '@')){
                            tanque[conti][contj] = ' ';
                        }
                    }
                }
            }
        }
    }
    sort = rand() % 1250;   //Sortear o '@'
    if(sort == 0){
        while(conf == false){
            i = rand() % 25;
            j = rand() % 50;
            if(tanque[i][j] == ' '){
                tanque[i][j] = '@';
                conf = true;
            }
        }
    }
    jogadas = 0;
}

int main (int argc, char *argv[]){
    srand(time(NULL));
    inicializa();
    char op = ' ';
    while (op != 's'){
        imprime();
        printf("\nAlgas = %d, Sais = %d, Larvas = %d", algas, sais, larva);
        printf("\n(c)ultivar / (f)ertilizar / (m)over / (q)uebrar / (p)escar / (n)oite / (s)air \n Opcao %d : ( )\b\b", jogadas + 1);
        scanf(" %c", &op);
        printf("\n");
        switch(op) {
            case 'c' :
                cultivar();
                break;
            case 'f' :
                fertilizar();
                break;
            case 'm' :
                mover();
                break;
            case 'q' :
                quebrar();
                break;
            case 'p' :
                pescar();
                break;
            case 'n' :
                noite();
                break;
            case 's' :
                break;
            default :
                printf("\nOpcao invalida\n");

        }
        if (jogadas >= 7){
            imprime();
            printf("\n\n");
            noite();
        }
    }

system ("pause");
return 0;
}