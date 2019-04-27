#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define true 1
#define false 0

// state 0 = 'x' ou 'z'
// state 1 = 'x' -> 'x', 'z', 'v' ou final
// state 2 = 'y' -> 'y' ou final
// state 3 = 'z' -> 'z', 'v' ou final
// state 4 = 'v' -> final
// state 5 = final

int avaliar(char *str, int pos, int state){
    if(strlen(str) != pos){

        // STATE 0
        if(state == 0){
            if(str[pos] == 'x'){
                pos++;
                state = 1;
                avaliar(str, pos, state);
            }else if(str[pos] == 'z'){
                pos++;
                state = 3;
                avaliar(str, pos, state);
            }else{
                return false;
            }
        }

        // STATE 1
        else if(state == 1){
            if(str[pos] == 'x'){
                pos++;
                avaliar(str, pos, state);
            }else if(str[pos] == 'y'){
                pos++;
                state = 2;
                avaliar(str, pos, state);
            }else if(str[pos] == 'z'){
                pos++;
                state = 3;
                avaliar(str, pos, state);
            }else if(str[pos] == 'v'){
                pos++;
                state = 4;
                avaliar(str, pos, state);
            }else{
                return false;
            }
        }

        // STATE 2
        else if (state == 2){
            if(str[pos] == 'y'){
                pos++;
                avaliar(str, pos, state);
            }else{
                return false;
            }
        }

        // STATE 3
        else if(state == 3){
            if(str[pos] == 'z'){
                pos++;
                avaliar(str, pos, state);
            }else if(str[pos] == 'v'){
                pos++;
                state = 4;
                avaliar(str, pos, state);
            }else{
                return false;
            }
        }

        // STATE 4
        else if(state == 4){
            return false;
        }

    // STATE 5
    }else{
        return true;
    }
}

int main(){

    int ctrl_menu; // variavel q controla o menu

    do{
        system("cls");
        int pos = 0; // variavel q indica a posicao na string
        int state = 0;  // variavavel q indica o estado da palavra
        char str[10]; // variavel q recebe a palavra

        do{
            system("cls");
            printf("Digite uma palavra com no maximo 6 letras utilizando 'x', 'z', 'v' e 'y':\n");
            scanf("%s",&str);
        }while(strlen(str) > 6);

        int result = avaliar(str, pos, state); // variavel q recebe o resultado da palavra

        if(result == true){
            printf("\nPalvavra ACEITA pela Linguagem.\n");
        }else{
            printf("\nPalavra NAO ACEITA pela Linguagem\n");
        }

        //MENU
        do{
            printf("\n[1]CONTINUAR\n[2]SAIR\nDIGITE: ");
            scanf("%d",&ctrl_menu);
        }while(ctrl_menu != 1 && ctrl_menu != 2);

    }while(ctrl_menu == 1);

}
