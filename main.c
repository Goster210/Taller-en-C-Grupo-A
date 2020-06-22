#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

void primeNumbers(){
    printf("NUMEROS PRIMOS");
}
int egomaniac(int number, int sum, int size) {
    sum += pow(number % 10, size);
    return number > 0 ? egomaniac(number / 10, sum, size) : sum;
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
char *fibonacci(int n, char *x) {
    n == 1 || n == 0 ? n == 1 ? strcat(x, "1") : strcat(x, "0") : *fibonacci(n - 1, x) +*fibonacci(n - 2, x);
    return x;
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
        long number;
        int isBits = 0, isBits2 = 0, cont = 0;
        char *aux, cnumber[100], x[1000][1000]={""},pattern[100]="";
        scanf("%c",&option);
        fflush(stdin);
        switch(option){
            case '1' :
                primeNumbers();
                stop();
                break;
            case '2' :
                printf("\n\n-------------------INICIO NUMERO EGOLATRA---------------------\n\n");
                printf("Digite el numero que desea saber si es o no egolatra: ");
                getchar();
                if (fgets(cnumber, sizeof(cnumber), stdin)) {
                    number = strtol(cnumber, &aux,10);
                    if (aux == cnumber || *aux != '\n') {
                        printf("\nDebe digitar un numero entero positivo.\nNo se aceptan cadenas de caracteres ni numeros decimales.\n");
                    } else {
                        printf(number >= 0 ? number != egomaniac(number, 0, floor(log10(labs(number))) + 1) && number!=0
                                              ? "\nEl numero %ld no es egolatra\n" : "\nEl numero %ld si es egolatra\n"
                                            : "\nEl numero debe ser un entero positivo\n", number);
                    }
                }

                printf("\n--------------------FIN NUMERO EGOLATRA-----------------------\n");
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
                printf("\n\n-------------------INICIO FIBONACCI DE BITS---------------------\n\n");
                printf("Digite el numero n para la serie :");
                getchar();
                if (fgets(cnumber, sizeof(cnumber), stdin)) {
                    number = strtol(cnumber, &aux, 10);
                    if (aux == cnumber || *aux != '\n') {
                        printf("\nDebe digitar un numero entero positivo.\nNo se aceptan cadenas de caracteres ni numeros decimales.");
                    } else {
                        if (number >= 0) {
                            printf("\nDigite el patron de bits a buscar: ");
                            scanf("%s", pattern);
                            char buffer1[100] = "";
                            char buffer2[100] = "";
                            char buffer3[100] = "";

                            for (int i = 0; i < strlen(pattern); i++) {
                                isBits += strcmp(strncpy(buffer1, &pattern[i], 1), "0") == 0 ||
                                          strcmp(strncpy(buffer1, &pattern[i], 1), "1") == 0 ? 1 : 0;
                                isBits2 += (i + 2 <= strlen(pattern) &&
                                            strcmp(strncpy(buffer2, &pattern[i], 2), "00") == 0) ||
                                           (i + 3 <= strlen(pattern) &&
                                            strcmp(strncpy(buffer3, &pattern[i], 3), "111") == 0)
                                           ? 1 : 0;
                            }
                            if (isBits == strlen(pattern) && isBits2 == 0) {
                                int a = strlen(fibonacci(number, x));
                                int b = strlen(pattern);
                                char buffer[100] = "";
                                char *chain = fibonacci(number, x);
                                for (int i = 0; i < a; i++) {
                                    if (i * b + b <= a && strcmp(strncpy(buffer, &chain[i * b], b), pattern) == 0) {
                                        cont++;
                                    }
                                }
                                printf("\nEl patrón de bits %s se encuentra %d veces en f(n) para n = %ld", pattern,cont,number);
                            } else {
                                printf(isBits2 != 0 ? "\nEl patrón de bits %s se encuentra 0 veces en f(n) para n = %ld" : "\nEl patron digitado no corresponde a un patron de bits (0,1)", pattern, number);
                            }

                        } else {
                            printf("\nEl numero n debe ser positivo\n");
                        }
                    }
                }
                printf("\n\n-------------------FIN FIBONACCI DE BITS---------------------\n");
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
