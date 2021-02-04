#ifndef Serie_h
#define Serie_h
#include <iostream>
#include <string>
#include "Episodio.h"
#include <stdio.h>
using namespace std;

//clase Serie
class Serie {
    public:
    //metodos constructores
        Serie();
        Serie(string, string, int, string, double, int); // con parametros

        //metodo destructor 
        ~Serie();

        //metodos set para actualizar los valores
        void setId(string);
        void setTitulo(string);
        void setDuracion(int);
        void setGenero(string);
        void setCalificacion(double);
        void setCantidadEpisodios(int);

        //metodos get para regresar los valores
        string getId();
        string getNombre();
        int getDuracion();
        string getGenero();
        double getCalificacion();
        int getCantidadEpisodios();

        //composición
        void setEpisodio(int, Episodio); //metodo set para un episodio
        Episodio getEpisodio(int); //metodo get para los episodios
        void calculaCalificacionPromedio(); //calcula la calificación promedio en base a los episodios
        void imprimir(); //imprime la serie con sus episodios
        void imprimir(double); //imprime la serie con sus episodios que cumplan con el parámetro

    private:
        //atributos de la serie
        string id, nombre, genero;
        int duracion, cantEpisodios;
        double calificacionPromedio;
        Episodio arrEpisodios[5]; //arreglo con los episodios de una serie

};

    //metodo constructor que inicializa todo en nulo
    Serie::Serie() {
        id = "";
        nombre = "";
        genero = "";
        duracion = 0;
        calificacionPromedio = 0;
        cantEpisodios = 0;
    }

    //metodo constructor que inicializa todo con parámetros
    Serie::Serie(string _id, string _nombre, int _duracion, string _genero, double _calificacion, int _cantidad) {
        id = _id;
        nombre = _nombre;
        genero = _genero;
        duracion = _duracion;
        calificacionPromedio = _calificacion;
        cantEpisodios = _cantidad;
    }

    //metodo destructor
    Serie::~Serie() { }

    //método para actualizar el id
    void Serie::setId(string _id) {
        id = _id;
    }

    //método para actualizar el titulo
    void Serie::setTitulo(string _nombre) {
        nombre = _nombre;
    }

    //método para actualizar la duración
    void Serie::setDuracion(int _duracion) {
        duracion = _duracion;
    }

    //método para actualizar el genero
    void Serie::setGenero(string _genero) {
        genero = _genero;
    }

    //método para actualizar la califiación
    void Serie::setCalificacion(double _calificacion) {
        calificacionPromedio = _calificacion;
    }

    //método para actualizar la cantidad de episodios
    void Serie::setCantidadEpisodios(int _cantidad) { 
        cantEpisodios = _cantidad;
    }

    //métodos que regresan los atributos

    string Serie::getId() { return id; }

    string Serie::getNombre() { return nombre; }

    int Serie::getDuracion() { return duracion; }

    string Serie::getGenero() { return genero; }

    double Serie::getCalificacion() { return calificacionPromedio; }
    
    int Serie::getCantidadEpisodios() { return cantEpisodios; }



    // Composición

    //método que cambia algún episodio de una serie, recibe la posición y Episodio. valida que esté dentro del rango
    void Serie::setEpisodio(int numEpisodio, Episodio _episodio) {
        if ((numEpisodio <= 4) && (numEpisodio >= 0)) {
            arrEpisodios[numEpisodio] = _episodio;
        }
    }
    
    //método que regresa algún episodio de una serie, recibe la posición y Episodio. valida que esté dentro del rango.
    Episodio Serie::getEpisodio(int numEpisodio) {
        
        if (numEpisodio >= 0 && numEpisodio <= 4) {  
            return arrEpisodios[numEpisodio];
        }
        else {
            return arrEpisodios[0]; //si no está en el rango, se regresa el primer episodio del arreglo
        }
    }

    //calcula la calificación promedio de una serie en base a sus episodios
    void Serie::calculaCalificacionPromedio() {
        double suma = 0;
        
        //si sí existen episodios, se calcula la calificación promedio
        if (cantEpisodios > 0) {

            //se recorre todo el arreglo de episodios y se guarda la calificación en una suma
            for (int i = 0; i < cantEpisodios; i++) {
                suma += arrEpisodios[i].getCalificacion();
            }
            calificacionPromedio = suma/cantEpisodios; //se calcula el promedio dividiendo de la serie la suma entre la cantidad de episodios
        }

        //si no existen episodios, la calificación promedio es 0
        else {
            calificacionPromedio = 0;
        }
    }

    //imprime los atributos de una serie e imprime los episodios
    void Serie::imprimir() {
        cout << id << ", " << nombre << ", " << genero << ", " << duracion << ", " << cantEpisodios << ", " << calificacionPromedio << endl;
        for (int i = 0; i < cantEpisodios; i++) {
            arrEpisodios[i].imprimir();
        }
    }

    //se imprimen las series que tengan episodios que cumplan con la calificación del parámetro recibido
    
    void Serie::imprimir(double _calificacion) {

        //primero se recorren todos los episodios de la serie y se van comparando las calificaciones
        for (int i = 0; i < cantEpisodios; i++) {

            //si tiene algún episodio con la calificación, se imprime la serie y los episodios que cuenten con la calificación determinada
            if (arrEpisodios[i].getCalificacion() == _calificacion) {
                cout << id << ", " << nombre << ", " << genero << ", " << duracion << ", " << cantEpisodios << ", " << calificacionPromedio << endl;
                for (int j = 0; j < cantEpisodios; j++) {
                    if (arrEpisodios[j].getCalificacion() == _calificacion) //se imprimen todos los episodios que cuenten con la calificación
                        arrEpisodios[j].imprimir();
                }
                cout << endl;

                //si una serie cuenta con algún episodio con la calificación, ya se debieron haber imprimido todos los episodios que cumplan
                //entonces no hay necesidad de revisar el siguiente episodio de la misma serie
                break; 
            }    

        }
    }

#endif /* Serie_h */