#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

void primeNumbers(int numeroFinal){
    int contador;
    int i;
    int primo;
    int final = numeroFinal;

    for (i = final; i > 0; i--) {
        primo = 1;
        contador = 2;
        while (contador <= i / 2 && primo) {
            if (i % contador == 0)
                primo = 0;
            contador++;
        }
        if (primo)
            printf("%d ", i);
    }
    printf("NUMEROS PRIMOS");
}

int egomaniac(int number, int sum, int size) {
    sum += pow(number % 10, size);
    return number > 0 ? egomaniac(number / 10, sum, size) : sum;
}
/////////////////////////RUN  IMC/////////////////
char* maleIMC(double weight,double height,double imc){
    if (imc < 17 ){
        return ("Desnutricion");
    }
    if (imc > 17 &&  imc <= 20){
        return ("Bajo Peso");
    }
    if (imc > 20 &&  imc <= 25){
        return ("Normal");
    }
    if (imc > 25 &&  imc <= 30 ){
        return ("Sobrepeso");
    }
    if (imc > 30 &&  imc <= 35 ){
        return ("Obesidad");
    }
    if (imc > 35 &&  imc <= 40 ){
        return ("Obesidad Marcada");
    }
    if (imc > 40 ){
        return ("Obesidad Morbida");
    }
    return "Error";
}
char* femaleIMC(double weight,double height,double imc){
    if (imc < 16 ){
        return ("Desnutricion");
    }
    if (imc > 16 &&  imc <= 20){
        return ("Bajo Peso");
    }
    if (imc > 20 &&  imc <= 24){
        return ("Normal");
    }
    if (imc > 24 &&  imc <= 29 ){
        return ("Sobrepeso");
    }
    if (imc > 29 &&  imc <= 34 ){
        return ("Obesidad");
    }
    if (imc > 34 &&  imc <= 39 ){
        return ("Obesidad Marcada");
    }
    if (imc > 39 ){
        return ("Obesidad Morbida");
    }
    return "Error";
}
int validateIMC(char num[]){
    int i = 0,j = 0;
    char caracter[1]=".";
    char resultante[100];
    while (num[i] != '\0')
    {
        if (caracter[0] != num[i])
        {
            resultante[j] = num[i];
            j++;
        }
        i++;
    }

    for (int a = 0; a < strlen(resultante); a++){
        if(!isdigit(resultante[a]) ) {
            return 0;
        }
    }
    return 1;
}

void IMC(){
    printf("\n\n------------------- INICIO INDICE DE MASA CORPORAL (IMC) ---------------------\n\n");
    double imc;
    char weight[10],height[10],gender[10];
    printf("-------------- [INDICE DE MASA CORPORAL] --------------\n"
           "\n¿CUAL ES TU GENERO?"
           "\nOPCIONES:  (digita el numero 1 o el numero 2 segun tu opcion)"
           "\n1)  Masculino"
           "\n2)  Femenino\n");
    getchar();
    scanf("%s",&gender);
    if (strcmp(gender,"1")==0|| strcmp(gender,"2")==0) {
        printf("DIGITA TU PESO en (kilogramos)[SI VAS AGREGAR DECIMALES USA (.) PARA HACERLO][EL CARACTER (,) NO SIRVE]\n");
        scanf("%s", &weight);
        if (validateIMC(weight)==1){
            printf("DIGITA TU ALTURA en (centimetros)[SI VAS AGREGAR DECIMALES USA (.) PARA HACERLO][EL CARACTER (,) NO SIRVE]\n");
            scanf("%s", &height);
            if (validateIMC(height)==1) {
                double newWeight = atof(weight);
                double newHeight = atof(height);
                int newGender = atof(gender);
                imc = (newWeight) / (pow((newHeight/ 100), 2));
                switch (newGender) {
                    case 1 :
                        printf("\n--------DATOS DEL ANALISIS--------"
                               "\nGenero: MASCULINO "
                               "\nPeso: %lf kg"
                               "\nAltura: %lf cm"
                               "\nCALCULO IMC: %lf"
                               "\nESTADO SENGUN IMC: %s\n", newWeight, newHeight,imc,maleIMC(newWeight, newHeight, imc));
                        break;
                    case 2 :
                        printf("\n--------DATOS DEL ANALISIS--------"
                               "\nGenero: FEMENINO "
                               "\nPeso: %lf kg"
                               "\nAltura: %lf cm"
                               "\nCALCULO IMC: %lf"
                               "\nESTADO SENGUN IMC: %s\n", newWeight, newHeight,imc,femaleIMC(newWeight, newHeight, imc));
                        break;
                }
            } else{
                printf("OPCION NO VALIDA --> HAS DIGITADO UNA ALTURA ERRONEA\n");
            }

        } else{
            printf("OPCION NO VALIDA --> HAS DIGITADO UN PESO ERRONEO\n");
        }
    } else {
        printf("OPCION NO VALIDA --> EL MENU SOLO PERMITE la opcion 1 o 2\n");
    }
    printf("------------------------------------------------------\n"
           "\n-------------------  FIN INDICE DE MASA CORPORAL (IMC) ---------------------\n\n");
}
/////////////////////////END  IMC/////////////////
//////// Puntos 3 y 5

//Validacion Ingreso de solo numeros
int validateNumbers(char option[]){
    for(int i=0; i<strlen(option); i++){
        if(!isdigit(option[i])){
            printf("\nError!!!, Ingrese solo Numeros\nVuelva a Intentarlo\n");
            getchar();
            return 0;
        }
    }
    return 1;
}

//Inicio punto 3
int ascenOrder(int digits[], int size){
    int auxOrder,numberAscen = 0,aux = 0;

    for(int i=0;i<size;i++){
        for(int j=0;j<size-1;j++){
            for(int j=0;j<size-1;j++){
                if(digits[j]>digits[j+1]){
                    auxOrder=digits[j];
                    digits[j]=digits[j+1];
                    digits[j+1]=auxOrder;
                }
            }
        }
    }

    for (int i = 0;i < size; i++){
        aux = digits[i];

        if (aux != 0){
            while (aux > 0){
                numberAscen *= 10;
                aux /= 10;
            }
            numberAscen += digits[i];
        }else{
            numberAscen *= 10;
        }
    }
    return numberAscen;
}

int descenOrder(int digits[], int size){
    int auxOrder,numberDescen = 0,aux = 0;

    for(int i=0;i<size;i++){
        for(int j=0;j<size-1;j++){
            for(int j=0;j<size-1;j++){
                if(digits[j]<digits[j+1]){
                    auxOrder=digits[j];
                    digits[j]=digits[j+1];
                    digits[j+1]=auxOrder;
                }
            }
        }
    }


    for (int i = 0;i < size; i++){
        aux = digits[i];

        if (aux != 0){
            while (aux > 0){
                numberDescen *= 10;
                aux /= 10;
            }
            numberDescen += digits[i];
        }else{
            numberDescen *= 10;
        }
    }
    return numberDescen;
}

void magicNumber(){
    int number,originalNumber;
    char validate[5];

    printf("\n----------->  Numero Magico \n");
    do{
        printf("\nIngrese el numero: " );
        scanf("%s",validate);
        number=validateNumbers(validate);
    }while(number == 0);

    if(number !=0 ){
        originalNumber = atoi(validate);
        int digits[10],aux=0,size,temp=originalNumber;
        while(temp!=0){
            digits[aux] = temp%10;
            temp = temp/10;
            aux++;
        }
        size = aux;
        if( (descenOrder(digits,size) - ascenOrder(digits,size)) == originalNumber){
            printf("El numero %i SI es Magico\n",originalNumber);
        }else{
            printf("El numero %i NO es Magico\n",originalNumber);
        }
    }
}
//Fin Punto 3
//Inicio Punto 5
int processDigiExcl(int less,int higher,int exclude,int *sumNoExcl,int *sumNumExc){
    int num=0,digito=0,contExc=0,suma=0;

    for(int i=less;i<=higher;i++){
        num = i;
        while(num != 0){
            digito = num%10;
            num = num / 10;

            if(digito == exclude){
                contExc++;
            }else{
                suma += digito;
            }
        }
    }
    *sumNumExc = contExc;
    *sumNoExcl = suma;
    return 0;
}

void readDigits(){
    int lessVal,highVal,exclVal;
    char validLess[5],validHigher[5],validExcl[5];

    printf("\n----------->  Digitos Excluidos\n");
    do{
        printf("\nIngrese el MENOR numero del rango: ");
        scanf("%s",&validLess);
        lessVal = validateNumbers(validLess);
    }while(lessVal == 0);

    do{
        printf("\nIngrese el MAYOR numero del rango: ");
        scanf("%s",&validHigher);
        highVal = validateNumbers(validHigher);
    }while(highVal == 0);

    do{
        printf("\nIngrese el Digito a EXCLUIR del rango: ");
        scanf("%s",&validExcl);
        exclVal = validateNumbers(validExcl);
    }while(exclVal == 0);


    if(lessVal!=0 && highVal!=0 && exclVal!=0){

        int lessNumber = atoi(validLess), higherNumber = atoi(validHigher), excludeNumber = atoi(validExcl);
        int sumNoExcl,sumNumExc;

        if(lessNumber >= higherNumber){
            printf("\nERROR!!!... El Nº Menor es Mayor o Igual, que el Mayor del Rango: (%i >= %i)\n",lessNumber,higherNumber);
        }else{
            processDigiExcl(lessNumber,higherNumber,excludeNumber,&sumNoExcl,&sumNumExc);
            printf("\nRango de Numeros [%i - %i]\t Digito A Excluir (%i)\nSuma Digitos NO EXCLUIDOS: %i, Cantidad Digitos EXCLUIDOS: %i\n",lessNumber,higherNumber,excludeNumber,sumNoExcl,sumNumExc);
        }
    }
}
//Fin Punto 5

//// Fin Puntos 3 y 5

char *fibonacci(int number, char *chain) {
    number == 1 || number == 0 ? number == 1 ? strcat(chain, "1") : strcat(chain, "0") : *fibonacci(number - 1, chain) +*fibonacci(number - 2, chain);
    return chain;
}
void testString(){
    char prue[] = {'O', 'O', 'X', 'X', 'O', 'X', 'X', 'O', 'O', 'O'};
    int contador = 0;
    int total = 0;
    int VectorSuma[sizeof(prue) - 1];

    for (int i = 0; i <= sizeof(prue) - 1; ++i) {
        contador++;
        if (prue[i] == 'O') {
            VectorSuma[i] = contador;
        } else if (prue[i] == 'X')
            contador = 0;
        VectorSuma[i] = contador;
    }
    for (int j = 0; j <= sizeof(prue) - 1; ++j) {
        printf("%d ", VectorSuma[j]);
        total = total + VectorSuma[j];
    }
    printf("\n------El total de la calificacion es: %d------\n", total);
    printf("PRUEBA CADENA ");
}
void stop()
{
    printf("\nPulsa ENTER para continuar...");
    getchar();
    getchar();
}

void mainMenu(){
    char option[10];
    char *mainMenu = "\n<<<<MENU PRINCIPAL>>>>\n\n"
                     "1. Numero Primo\n"
                     "2. Numero Ególatra\n"
                     "3. Numero Magico\n"
                     "4. Indice de masa corporal (IMC)\n"
                     "5. Suma de digitos\n"
                     "6. Serie de Fibonnaci\n"
                     "7. Test Cadena\n\n"
                     "8. SALIR\n\n";
    do{
        printf( mainMenu );
        long number;
        int isBits = 0, isBits2 = 0, cont = 0;
        char *aux, cnumber[100], fchain[1000][1000]={""},pattern[100]="";
        scanf("%s",&option);
        fflush(stdin);

        if (strcmp(option,"1")==0){
            int numP1;
            printf("Digite el numero limite !\n");
            scanf("%i", &numP1);
            if (numP1>0){
                primeNumbers(numP1);
            }
            else{
                printf("Error tiene que Digitar un Numero mayor a 1");
            }
            stop();
        } else if (strcmp(option,"2")==0){
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

        } else if (strcmp(option,"3")==0){
            magicNumber();
            stop();
        }
        else if (strcmp(option,"4")==0){
            IMC();
            stop();
        }
        else if (strcmp(option,"5")==0){
            readDigits();
            stop();
        }
        else if (strcmp(option,"6")==0){
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
                            int a = strlen(fibonacci(number, fchain));
                            int b = strlen(pattern);
                            char buffer[100] = "";
                            char *chain = fibonacci(number, fchain);
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
        }
        else if (strcmp(option,"7")==0){
            testString();
            stop();
        }
        else if (strcmp(option,"8")==0){
            exit (0);
        } else{
            printf("INVALIDO --> ESCOGISTE UNA OPCION QUE NO ESTA EN EL MENU");
            stop();
        }


    }while( 9!=10 );
}

int main() {
    mainMenu();
    return 0;
}
