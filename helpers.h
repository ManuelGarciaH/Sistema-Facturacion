#ifndef HELPERS_H_INCLUDED
#define HELPERS_H_INCLUDED
#include <sstream>
#include <cstring>
#ifdef _WIN32
    #define CLEAR "cls"
#elif defined(unix)
    #define CLEAR "clear"
#else
    #error "S0 no soportado para limpiar pantalla"
#endif

using namespace std;

void pausa(){
    cin.get();
    cout << "Presione enter para continuar...";
    cin.get();
}

void pausaDespuesDeGetline(){
    cout << "Presione enter para continuar...";
    cin.get();
}

void espacios(int longitudPalabra, int limite){
    while(longitudPalabra<limite){
        cout << "\t";
        longitudPalabra=longitudPalabra+8;
    }
    cout << "|";
}

char* convertirEnteroACadena(int entero, char* cadena){
    stringstream conversor;
    conversor << entero;
    conversor >> cadena;
    return cadena;
}

int convertirCadenaAEntero(string cadena){
    int entero;
    stringstream conversor;
    conversor << cadena;
    conversor >> entero;
    return entero;
}

char* convertirStringAChar(string cadenaString, char* cadenaChar){
    strcpy(cadenaChar, cadenaString.c_str());
    return cadenaChar;
}

#endif // HELPERS_H_INCLUDED
