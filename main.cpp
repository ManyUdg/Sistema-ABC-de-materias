#include <iostream>
#include <clocale>
#include <cstring>
#include "helpers.h"
#include "materias.h"

#define MAX_MATERIAS 3
#define C_0 0

using namespace std;

int maxMaterias, cantidadMaterias;
Materia** materias;
typedef enum {ALTA=1, BAJA, CONSULTA, CAMBIO, LISTADO, BUSQUEDA, GUARDADO, SALIDA} opcionesMenuPrincipal;

void inicializar();
int elegirOpcionMenu();
void pausa();
void darAltaMateria();
void modificarMateria(int indice);
void listarMaterias();
void espacios(int longitudPalabra, int limite);
void consultarMateria();
bool registroMateriasTieneDatos(int indice);
void mostrarMateria(int indice);
void darBajaMateria();
void copiarProximoObjetoMateria(int indice);

int main()
{
    int opcion;
    setlocale(LC_ALL, "");
    inicializar();
    do{
        system(CLEAR);
        opcion=elegirOpcionMenu();
        system(CLEAR);
        switch(opcion){
            case ALTA:      darAltaMateria();   break;
            case BAJA:      darBajaMateria();   break;
            case CONSULTA:  consultarMateria(); break;
            case CAMBIO:            break;
            case LISTADO:   listarMaterias();   break;
            case BUSQUEDA:          break;
            case GUARDADO:          break;
            case SALIDA:            break;
            default: cout << "Opción no valida" << endl;
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

void pausa(){
    cin.get();
    cout << "Presione enter para continuar..." << endl;
    cin.get();
}

void darAltaMateria(){
    char vacio[] = "";
    Materia** tmp;
    cout << "*****ALTA DE MATERIAS*****" << endl;
    if(cantidadMaterias==maxMaterias){
       tmp=new Materia*[maxMaterias=cantidadMaterias+1];
        for(int i=0; i<cantidadMaterias; i++){
            tmp[i]=materias[i];
        }
        delete[]materias;
        materias=tmp;
    }
    materias[cantidadMaterias]= new Materia(vacio, vacio, vacio, vacio, 0, 0);
    modificarMateria(cantidadMaterias);
    cantidadMaterias++;
}

void modificarMateria(int indice){
    char nombre[TAMANIO_NOMBRE_MATERIA+1], acronimoMateria[TAMANIO_ACRONIMO_MATERIA+1];
    char nombreProfesor[TAMANIO_NOMBRE_PROFESOR+1], diasDeLaSemana[TAMANIO_DIAS+1];
    int horaInicio, horaFin;
    cout << "Ingrese los datos del registro " << indice+1 << endl;
    cout << "Ingrese el nombre de la materia-> ";
    cin.get();
    cin.getline(nombre, TAMANIO_NOMBRE_MATERIA+1);
    cout << "Ingrese el acronimo de la materia-> ";
    cin.getline(acronimoMateria, TAMANIO_ACRONIMO_MATERIA+1);
    cout << "Ingrese el nombre del profesor-> ";
    cin.getline(nombreProfesor, TAMANIO_NOMBRE_PROFESOR+1);
    cout << "Ingrese los días de la semana-> ";
    cin.getline(diasDeLaSemana, TAMANIO_DIAS);
    cout << "Ingrese la hora de inicio-> ";
    cin >> horaInicio;
    cin.get();
    cout << "Ingrese la hora de fin-> ";
    cin >> horaFin;

    materias[indice]->setNombre(nombre);
    materias[indice]->setAcronimoMateria(acronimoMateria);
    materias[indice]->setNombreProfesor(nombreProfesor);
    materias[indice]->setDiasDeLaSemana(diasDeLaSemana);
    materias[indice]->setHoraInicio(horaInicio);
    materias[indice]->setHoraFin(horaFin);
}

void listarMaterias(){
    if(cantidadMaterias!=0){
        cout << "---------------------------------------------------------------------------------\n";
        cout << "Acrónimo|Nombre\t\t\t|Profesor\t\t|Días\t|Inicio\t|Fin\t|" << endl;
        cout << "---------------------------------------------------------------------------------\n";
        for(int i=0; i<cantidadMaterias; i++){
            cout << materias[i]->getAcronimoMateria() << "\t|";
            cout << materias[i]->getNombre();
            espacios(strlen(materias[i]->getNombre()), TAMANIO_NOMBRE_MATERIA-1);
            cout << materias[i]->getNombreProfesor();
            espacios(strlen(materias[i]->getNombreProfesor()), TAMANIO_NOMBRE_PROFESOR-1);
            cout << materias[i]->getDiasDeLaSemana() << "\t|";
            cout << materias[i]->getHoraInicio() << "\t|";
            cout << materias[i]->getHoraFin() << "\t|";
            cout << "\n---------------------------------------------------------------------------------\n";
        }

    }else{
        cout << "Registro de materia vacio" << endl;
    }
}

void espacios(int longitudPalabra, int limite){
    while(longitudPalabra<limite){
        cout << "\t";
        longitudPalabra=longitudPalabra+8;
    }
    cout << "|";
}

void consultarMateria(){
    int i;
    cout << "*****CONSULTAR UNA MATERIA*****" << endl;
    if(cantidadMaterias!=C_0){
        cout << "Indica el numero de registro a consultar (1 a " << maxMaterias << "): ";
        cin >> i;
        i--;
        cout << endl;
        if(registroMateriasTieneDatos(i)){
            mostrarMateria(i);
        }
    }else{
        cout << "Registro de materias vacio" << endl;
    }
}

bool registroMateriasTieneDatos(int indice){
    bool tieneDatos=false;
    if(indice<cantidadMaterias){
        if(materias[indice]->getHoraInicio()==C_0 || materias[indice]->getHoraFin()==C_0){
            cout << "\nRegistro vacío\n";
        }else{
            tieneDatos=true;
        }
    }else{
        cout << "\nNo existe ese registro\n";
    }
    return tieneDatos;
}

void mostrarMateria(int indice){
    cout << "Registro de materia " << indice+1 << endl;
    cout << "Nombre de la materia: " << materias[indice]->getNombre() << endl;
    cout << "Acronimo de la materia: " << materias[indice]->getAcronimoMateria() << endl;
    cout << "Nombre del profesor: " << materias[indice]->getNombreProfesor() << endl;
    cout << "Días de la semana: " << materias[indice]->getDiasDeLaSemana() << endl;
    cout << "Hora de inicio: " << materias[indice]->getHoraInicio() << endl;
    cout << "Hora de fin: " << materias[indice]->getHoraFin() << endl;
}

void darBajaMateria(){
    int i;
    char opcion;
    cout << "BAJA DE UNA MATERIA\n\n";
    if(cantidadMaterias!=0){
        cout << endl;
        cout << "Indica el numero de registro a eliminar (1 a " << maxMaterias << "): ";
        cin >> i;
        i--;
        cout << endl;
        if(registroMateriasTieneDatos(i)){
            mostrarMateria(i);
            cout << "\n¿Seguro que quieres eliminar el registro(S/N)?: ";
            cin.get();
            cin >> opcion;
            if(opcion=='S' || opcion=='s'){
                for(cantidadMaterias--; i<cantidadMaterias; i++){
                        copiarProximoObjetoMateria(i);
                }
                delete materias[i];
                maxMaterias--;
                cout << "Registro eliminado\n";
            }else{
                cout << "El registro no se ha eliminado\n";
            }
        }
    }else{
        cout << "Registro de materias vacio" << endl;
    }
}

void copiarProximoObjetoMateria(int indice){
    materias[indice]->setNombre(materias[indice+1]->getNombre());
    materias[indice]->setAcronimoMateria(materias[indice+1]->getAcronimoMateria());
    materias[indice]->setNombreProfesor(materias[indice+1]->getNombreProfesor());
    materias[indice]->setDiasDeLaSemana(materias[indice+1]->getDiasDeLaSemana());
    materias[indice]->setHoraInicio(materias[indice+1]->getHoraInicio());
    materias[indice]->setHoraFin(materias[indice+1]->getHoraFin());
}
