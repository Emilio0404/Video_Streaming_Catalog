#ifndef Episodio_h
#define Episodio_h
#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

//clase Episodio para los episodios de las series
class Episodio {
    public:
        
        //metodos constructores
        Episodio();
        Episodio(string, int, double);
        
        //metodos set para cambiar los valores
        void setTitulo(string);
        void setTemporada(int);
        void setCalificacion(double);

        //metodos para regresar los valores
        string getTitulo();
        int getTemporada();
        double getCalificacion();
        
        //metodo para imprimir el resultado
        void imprimir();

    private:
        string titulo; //titulo del capitulo
        int temporada; //numero de temporada
        double calificacion; //calificacion
        
};

//metodo constructor que inicializa todo en nulo
Episodio::Episodio() {
    titulo = "";
    temporada = 0;
    calificacion = 0.0;
}

//metodo constructor con parametros 
Episodio::Episodio(string _titulo, int _temporada, double _calificacion) {
    titulo = _titulo;
    temporada = _temporada;
    calificacion = _calificacion;
}

//metodo set para el titulo
void Episodio::setTitulo(string _titulo) {
    titulo = _titulo;
}

//metodo set para la temporada
void Episodio::setTemporada(int _temporada) {
    temporada = _temporada;
}

//metodo set para la calificacion
void Episodio::setCalificacion(double _calificacion) {
    calificacion = _calificacion;
}

//metodos que regresan los valores
string Episodio::getTitulo() { return titulo; }
int Episodio::getTemporada() { return temporada; }
double Episodio::getCalificacion() { return calificacion; }

//metodo que imprime los valores separados por comas
void Episodio::imprimir() {
    cout << titulo << ", " << temporada << ", " << calificacion << endl;
}

#endif /* Episodio_h */