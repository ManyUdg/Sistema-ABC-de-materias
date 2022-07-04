#include <iostream>
#include <clocale>
#include <cstring>
#include <fstream>
#include <sstream>

#include "helpers.h"
#include "materias.h"

#define MAX_MATERIAS 3

using namespace std;

typedef enum {ALTA=1, BAJA, CONSULTA, CAMBIO, LISTADO, BUSQUEDA, GUARDADO, SALIDA} opcionesMenuPrincipal;

void inicializar();
int elegirOpcionMenu();

int main(){
    int opcion;
    setlocale(LC_ALL, "");
    inicializar();
    do{
        system(CLEAR);
        opcion=elegirOpcionMenu();
        system(CLEAR);
        switch(opcion){
            case ALTA:      darAltaMateria();       break;
            case BAJA:      darBajaMateria();       break;
            case CONSULTA:  consultarMateria();     break;
            case CAMBIO:    cambiarDatosMateria();  break;
            case LISTADO:   listarMaterias();       break;
            case BUSQUEDA:  buscarMaterias();       break;
            case GUARDADO:  guardarMaterias();      break;
            case SALIDA:    cerrarMaterias();       break;
            default:    cout << "Opción no valida" << endl;
        }
        if(opcion!=SALIDA){
            pausa();
        }
    }while(opcion!=SALIDA);
    return 0;
}

void inicializar(){
    maxMaterias=MAX_MATERIAS;
    materias= new Materia*[maxMaterias];
    cantidadMaterias=0;
    cargarArchivo();
}

int elegirOpcionMenu(){
    int opcion;
    cout << "REGISTRO DE MATERIAS" << endl;
    cout << "1) Alta de materia" << endl;
    cout << "2) Baja de materia" << endl;
    cout << "3) Consulta de materia" << endl;
    cout << "4) Modificación de materia" << endl;
    cout << "5) Listado de materia" << endl;
    cout << "6) Busqueda de materia" << endl;
    cout << "7) Guardar" << endl;
    cout << "8) Salir" << endl;
    cin >> opcion;
    return opcion;
}
