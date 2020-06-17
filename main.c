#include <stdio.h>
#include "ctype.h"

void primeNumbers(){
    printf("NUMEROS PRIMOS");
}
void egomaniacNumber(){
    printf("NUMERO EGÓLATRA");
}
void magicNumber(){
    printf("NUMERO MAGICO");
}
void IMC(){
    printf("INDICE DE MASA CORPORAL");

}
void sumOfDigits(){
    printf("SUMA DE DIGITOS");
}
void calcFibonacci(){
    printf("unaa secuencia de palabas Fibonacci ");
}
void testString(){
    printf("PRUEBA CADENA ");
}
void stop()
{
    printf("\nPulsa una ENTER para continuar...");
    getchar();
    getchar();
}

void mainMenu(){
    char option;
    char *mainMenu = "\n<<<<MENU PRINCIPAL>>>>\n\n"
                      "1. Numero Primo\n"
                      "2. Numero Ególatra\n"
                      "3. Numero Magico\n"
                      "4. Indice de masa corporal (IMC)\n"
                      "5. Suma de digitos\n"
                      "6. Serie de Fibonnaci\n"
                      "7. Test Cadena\n\n"
                      "Digite Opcion ([s/S]-Salir).... ";
    do{
        printf( mainMenu );
        scanf("%c",&option);
        fflush(stdin);
        switch(option){
            case '1' :
                primeNumbers();
                stop();
                break;
            case '2' :
                egomaniacNumber();
                stop();
                break;

            case '3' :
                magicNumber();
                stop();
                break;
            case '4':
                IMC();
                stop();
                break;

            case '5' :
                sumOfDigits();
                stop();
                break;

            case '6' :
                calcFibonacci();
                stop();
                break;

            case '7':
                testString();
                stop();
                break;
            case 's':
                break;
            case 'S':
                break;
            default:
                printf("OPCION NO VALIDA");
                stop();
                break;
        }

    }while( toupper(option) != 'S' );
}

int main() {
    mainMenu();
    return 0;
}
