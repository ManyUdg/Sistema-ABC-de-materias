#ifndef MATERIAS_H_INCLUDED

#define MATERIAS_H_INCLUDED
#define TAMANIO_NOMBRE_MATERIA 25
#define TAMANIO_ACRONIMO_MATERIA 5
#define TAMANIO_NOMBRE_PROFESOR 25
#define TAMANIO_DIAS 3
#define C_0 0
#define C_100 100
#define NOMBRE_ARCHIVO_TXT "Materias.txt"
#define DELIMITADOR_CAMPOS ","
#define DELIMITADOR_REGISTROS '\n'

class Materia{
    private:
        char nombre[TAMANIO_NOMBRE_MATERIA+1];
        char acronimoMateria[TAMANIO_ACRONIMO_MATERIA+1];
        char nombreProfesor[TAMANIO_NOMBRE_PROFESOR+1];
        char diasDeLaSemana[TAMANIO_DIAS+1];
        int horaInicio;
        int horaFin;
    public:
        Materia(char* n, char* aM, char* nP, char* dDLS, int hI, int hF){
            strcpy(this->nombre, n);
            strcpy(this->acronimoMateria, aM);
            strcpy(this->nombreProfesor, nP);
            strcpy(this->diasDeLaSemana, dDLS);
            this->horaInicio=hI;
            this->horaFin=hF;
        }
        void setNombre(char* n){
            strcpy(this->nombre, n);
        }

        void setAcronimoMateria(char* aM){
            strcpy(this->acronimoMateria, aM);
        }

        void setNombreProfesor(char* nP){
            strcpy(this->nombreProfesor, nP);
        }

        void setDiasDeLaSemana(char* dDLS){
            strcpy(this->diasDeLaSemana, dDLS);
        }

        void setHoraInicio(int hI){
            this->horaInicio=hI;
        }

        void setHoraFin(int hF){
            this->horaFin=hF;
        }

        char* getNombre(){
            return nombre;
        }

        char* getAcronimoMateria(){
            return acronimoMateria;
        }

        char* getNombreProfesor(){
            return nombreProfesor;
        }

        char* getDiasDeLaSemana(){
            return diasDeLaSemana;
        }

        int getHoraInicio(){
            return horaInicio;
        }

        int getHoraFin(){
            return horaFin;
        }
};

int maxMaterias, cantidadMaterias;
Materia** materias;

void darAltaMateria();
void modificarMateria(int indice);
void listarMaterias();
void espacios(int longitudPalabra, int limite);
void consultarMateria();
bool registroMateriasTieneDatos(int indice);
void mostrarMateria(int indice);
void darBajaMateria();
void copiarProximoObjetoMateria(int indice);
void cambiarDatosMateria();
void buscarMaterias();
void cerrarMaterias();
void guardarMaterias();
void cargarArchivo();

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
    if(cantidadMaterias!=C_0){
        cout << "---------------------------------------------------------------------------------\n";
        cout << "Acrónimo|Nombre\t\t\t|Profesor\t\t|Días\t|Inicio\t|Fin\t|" << endl;
        cout << "---------------------------------------------------------------------------------\n";
        for(int i=0; i<cantidadMaterias; i++){
            cout << materias[i]->getAcronimoMateria() << "\t|";
            cout << materias[i]->getNombre();
            espacios(strlen(materias[i]->getNombre()), TAMANIO_NOMBRE_MATERIA-1);
            cout << materias[i]->getNombreProfesor();
            espacios(strlen(materias[i]->getNombreProfesor()), TAMANIO_NOMBRE_PROFESOR-2);
            cout << materias[i]->getDiasDeLaSemana() << "\t|";
            cout << materias[i]->getHoraInicio() << "\t|";
            cout << materias[i]->getHoraFin() << "\t|";
            cout << "\n---------------------------------------------------------------------------------\n";
        }

    }else{
        cout << "Registro de materia vacio" << endl;
    }
}

void consultarMateria(){
    int i;
    cout << "*****CONSULTAR UNA MATERIA*****" << endl;
    if(cantidadMaterias!=C_0){
        cout << "Indica el numero de registro a consultar (1 a " << cantidadMaterias << "): ";
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
    if(cantidadMaterias!=C_0){
        cout << endl;
        cout << "Indica el numero de registro a eliminar (1 a " << cantidadMaterias << "): ";
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

void cambiarDatosMateria(){
    int i;
    if(cantidadMaterias!=C_0){
        cout << "***CAMBIO DE DATOS DE UNA MATERIA***" << endl;
        cout << "Indica el numero de registro a modificar-> ";
        cin >> i;
        i--;
        cout << endl;
        if(registroMateriasTieneDatos(i)){
            mostrarMateria(i);
            modificarMateria(i);
        }
    }else{
        cout << "Registro de materias vacio" << endl;
    }

}

void buscarMaterias(){
    char claveBuscada[TAMANIO_ACRONIMO_MATERIA];
    int cantidadMateriasEncontradas=0;
    cout << "***BUSQUEDAS DE MATERIAS***" << endl;
    cout << "Ingresa la clave de la materia que quieres buscar-> ";
    cin.get();
    cin.getline(claveBuscada, TAMANIO_ACRONIMO_MATERIA+1);
    for(int i=0; i<cantidadMaterias; i++){
        if(!strcmp(claveBuscada, materias[i]->getAcronimoMateria())){
            mostrarMateria(i);
            cout << endl;
            cantidadMateriasEncontradas++;
        }
    }
    if(cantidadMateriasEncontradas){
        cout << "Se encontraron un total de " << cantidadMateriasEncontradas << endl;
    }else{
        cout << "No se encontró algún registro con el acronimo <" << claveBuscada << ">\n";
    }
}

void cerrarMaterias(){
    cout << "Cerrando programa..." << endl;
}

void guardarMaterias(){
    ofstream archivo;
    if(cantidadMaterias!=C_0){
        archivo.open(NOMBRE_ARCHIVO_TXT);
        if(archivo.is_open()){
            archivo << cantidadMaterias << DELIMITADOR_CAMPOS;
            for(int i=0; i<cantidadMaterias; i++){
                archivo << materias[i]->getNombre() << DELIMITADOR_CAMPOS;
                archivo << materias[i]->getAcronimoMateria() << DELIMITADOR_CAMPOS;
                archivo << materias[i]->getNombreProfesor() << DELIMITADOR_CAMPOS;
                archivo << materias[i]->getDiasDeLaSemana() << DELIMITADOR_CAMPOS;
                archivo << materias[i]->getHoraInicio() << DELIMITADOR_CAMPOS;
                archivo << materias[i]->getHoraFin() << DELIMITADOR_REGISTROS;
            }
            archivo.close();
            cout << "Datos guardados con exito" << endl;
        }else{
            cout << "Error al abrir archivo" << endl;
        }
    }else{
        cout << "Registro de materias vacio" << endl;
    }
}

void cargarArchivo(){
    ifstream archivo;
    string cadena, subCadena;
    char subCadenaChar[C_100];
    char separador;
    char vacio[] = "";
    int posInicio, posFinal;
    Materia** tmp;
    archivo.open(NOMBRE_ARCHIVO_TXT);
    if(archivo.is_open()){
        archivo >> cantidadMaterias;
        archivo >> separador;
        if(cantidadMaterias>maxMaterias){
            tmp=new Materia*[maxMaterias=cantidadMaterias+1];
            delete[]materias;
            materias=tmp;
        }
        for(int i=0;i<cantidadMaterias; i++){
            materias[i]= new Materia(vacio, vacio, vacio, vacio, 0, 0);
            getline(archivo, cadena, DELIMITADOR_REGISTROS);
            posInicio=0;
            posFinal=cadena.find_first_of(DELIMITADOR_CAMPOS, posInicio);
            subCadena=cadena.substr(posInicio, posFinal);
            materias[i]->setNombre(convertirStringAChar(subCadena, subCadenaChar));

            posInicio=posFinal+1;
            posFinal=cadena.find_first_of(DELIMITADOR_CAMPOS, posInicio);
            subCadena=cadena.substr(posInicio, posFinal-posInicio);
            materias[i]->setAcronimoMateria(convertirStringAChar(subCadena, subCadenaChar));

            posInicio=posFinal+1;
            posFinal=cadena.find_first_of(DELIMITADOR_CAMPOS, posInicio);
            subCadena=cadena.substr(posInicio, posFinal-posInicio);
            materias[i]->setNombreProfesor(convertirStringAChar(subCadena, subCadenaChar));

            posInicio=posFinal+1;
            posFinal=cadena.find_first_of(DELIMITADOR_CAMPOS, posInicio);
            subCadena=cadena.substr(posInicio, posFinal-posInicio);
            materias[i]->setDiasDeLaSemana(convertirStringAChar(subCadena, subCadenaChar));

            posInicio=posFinal+1;
            posFinal=cadena.find_first_of(DELIMITADOR_CAMPOS, posInicio);
            subCadena=cadena.substr(posInicio, posFinal-posInicio);
            materias[i]->setHoraInicio(convertirCadenaAEntero(subCadena));

            posInicio=posFinal+1;
            posFinal=cadena.find_first_of(DELIMITADOR_CAMPOS, posInicio);
            subCadena=cadena.substr(posInicio, posFinal-posInicio);
            materias[i]->setHoraFin(convertirCadenaAEntero(subCadena));
        }
        archivo.close();
    }else{
        cout << "Error al abrir el archivo" << endl;
        cout << "Presione enter para continuar..." << endl;
        cin.get();
    }
}

#endif // MATERIAS_H_INCLUDED
