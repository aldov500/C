#include <iostream>
#include <windows.h>

using namespace std;

string cambiarMayusculas(string palabra);

bool buscarMesValido(string mes);

string calcularSignoZodiacal(int dia, string mes);

void menuInicial();

const string meses[12] = {"ENERO","FEBRERO","MARZO","ABRIL","MAYO","JUNIO","JULIO","AGOSTO","SEPTIEMBRE","OCTUBRE","NOVIMIEBRE","DICIEMBRE"};

int main()
{
    // Calcular el signo zodiacal de una persona

    while(true){
        menuInicial();
        Sleep(10);
    }


/*
 Aries (21 de marzo-20 de abril)
Tauro (21 de abril- 21 de mayo)
Géminis (22 de mayo-21 de junio)
Cáncer (22 de junio-22 de julio)
Leo (23 de julio-23 de agosto)
Virgo (24 de agosto-23 de septiembre)
Libra (24 de septiembre-23 de octubre)
Escorpión (24 de octubre-22 de noviembre)
Sagitario (23 de noviembre-21 de diciembre)
Capricornio (22 de diciembre-20 de enero)
Acuario (21 de enero-18 de febrero)
Piscis (19 de febrero-20 de marzo)
*/

    return 0;
}

void menuInicial(){
    int dia = 1;
    string mes = "Enero";

    cout<< "Ingrese el dia y mes de nacimiento [9 Mayo]:" <<endl;
    cin>> dia >> mes;

    if(dia>31 || dia<1){
        cout<< "El dia es incorrecto" <<endl;;
        dia = 1;
        mes = "Enero";
    } else if(buscarMesValido(mes) == false) {
        cout<< "El mes no existe" <<endl;
        dia = 1;
        mes = "Enero";
    }else{
        cout << calcularSignoZodiacal(dia,mes);
    }
}

string calcularSignoZodiacal(int dia, string mes){
    return "Hello, World";
}

bool buscarMesValido(string mes){
    bool encontrado = false;
    for(string i: meses){
        if(i == mes){
            encontrado = true;
        }
    }
    return encontrado;
}

string cambiarMayusculas(string palabra){
    string palabra_mayuscula = "";
    for(int i=0; i>palabra.length(); i++){
        palabra_mayuscula = toupper(palabra[i]);
    }
    return palabra_mayuscula;
}
