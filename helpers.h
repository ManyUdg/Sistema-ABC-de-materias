#ifndef HELPERS_H_INCLUDED
#define HELPERS_H_INCLUDED
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
    cout << "Presione enter para continuar..." << endl;
    cin.get();
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
