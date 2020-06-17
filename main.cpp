#include <iostream>

using namespace std;


void primeNumbers(){
    cout<<"NUMEROS PRIMOS"<<endl;
}
void egomaniacNumber(){
    cout<<"NUMERO EGÓLATRA"<<endl;
}
void magicNumber(){
    cout<<"NUMERO MAGICO"<<endl;
}
void IMC(){
    cout<<"INDICE DE MASA CORPORAL"<<endl;
}
void sumOfDigits(){
    cout<<"SUMA DE DIGITOS"<<endl;
}
void calcFibonacci(){
    cout<<"unaa secuencia de palabas Fibonacci "<<endl;
}
void testString(){
    cout<<"PRUEBA CADENA "<<endl;
}
void stop()
{
    cout << "Pulsa una ENTER para continuar...";
    getwchar();
    getwchar();
}

void mainMenu(){
    char option;
    string mainMenu = "\n<<<<MENU PRINCIPAL>>>>\n\n"
                     "1. Numero Primo\n"
                     "2. Numero Ególatra\n"
                     "3. Numero Magico\n"
                     "4. Indice de masa corporal (IMC)\n"
                     "5. Suma de digitos\n"
                     "6. Serie de Fibonnaci\n"
                     "7. Test Cadena\n\n"
                     "Digite Opcion ([s/S]-Salir).... ";
    do{
        cout<<mainMenu<<endl;
        cin>>option;
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
                cout << "OPCION NO VALIDA"<<endl;
                stop();
                break;
        }

    }while( toupper(option) != 'S' );
}

int main() {
    mainMenu();
    return EXIT_SUCCESS;
}
