#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define true 1
#define false 0

// state 1 = x
// state 2 = y
// state 3 = z
// state 4 = v

int teste(char *str, int aux, int state){

    if(strlen(str) != aux){
        //INICIO
        if(state == 0){
            if(str[aux] == 'x'){
                aux++;
                state = 1;
                teste(str, aux, state);
            }else if(str[aux] == 'z'){
                aux++;
                state = 3;
                teste(str, aux, state);
            }else{
                return false;
            }
        }

        //STATE 1

        else if(state == 1){
            if(str[aux] == 'x'){
                aux++;
                teste(str, aux, state);
            }else if(str[aux] == 'y'){
                aux++;
                state = 2;
                teste(str, aux, state);
            }else if(str[aux] == 'z'){
                aux++;
                state = 3;
                teste(str, aux, state);
            }else if(str[aux] == 'v'){
                aux++;
                state = 4;
                teste(str, aux, state);
            }else{
                return false;
            }
        }

        //STATE 2
        else if (state == 2){
            if(str[aux] == 'y'){
                aux++;
                teste(str, aux, state);
            }else{
                return false;
            }
        }

        //STATE 3
        else if(state == 3){
            if(str[aux] == 'z'){
                aux++;
                teste(str, aux, state);
            }else if(str[aux] == 'v'){
                aux++;
                state = 4;
                teste(str, aux, state);
            }else{
                return false;
            }
        }

        //STATE 4
        else if(state == 4){
            if(str[aux] != '\0'){
                return false;
            }
        }

    }else{
        return true;
    }
}

int main(){

    int ctrl;

    do{
        system("cls");
        int aux = 0, state = 0;
        char str[10]; char c;
        int pos;
        do{
            system("cls");
            printf("Digite uma palavra com no maximo 6 letras utilizando 'x', 'z', 'v' e 'y':\n");
            scanf("%s",&str);
        }while(strlen(str) > 6);

        int result = teste(str, aux, state);
        if(result == true){
            printf("\nPalvavra aceita pela linguagem.\n");
        }else{
            printf("\nNao e palvavra aceita pela linguagem\n");
        }
        printf("\n");
        //MENU

        do{
            printf("[1]CONTINUAR\n[2]SAIR\nDIGITE: ");
            scanf("%d",&ctrl);
            printf("\n");
        }while(ctrl != 1 && ctrl != 2);

    }while(ctrl == 1);

}

