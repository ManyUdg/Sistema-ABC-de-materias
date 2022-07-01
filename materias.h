#ifndef MATERIAS_H_INCLUDED
#define MATERIAS_H_INCLUDED
#define TAMANIO_NOMBRE_MATERIA 25
#define TAMANIO_ACRONIMO_MATERIA 5
#define TAMANIO_NOMBRE_PROFESOR 25
#define TAMANIO_DIAS 3

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


#endif // MATERIAS_H_INCLUDED
