#ifndef Series_h
#define Series_h
#include <iostream>
#include <string>
#include "Episodio.h"
#include "Serie.h"
#include <stdio.h>
#include<fstream>
#include<sstream>
using namespace std;

class Series {
    public:

        //metodos constructores
        Series();
        Series(int);

        //lee los archivos
        void leerArchivo();

        void reporteTodasSeries(); //ciclo 0 < cantidad. mostrar calificacion promedio de todas las series al final FALTAN

        //reportar series con calificacion que cumplen con el double
        void reporteConCalificacion(double);
        
        //reportar las series con el genero recibido por el string 
        void reporteGenero(string); 
        
        //calcular la calificacion promedido de todas las series en base a episodios llamando el método que ya teníamos
        void calculaCalPromedioSerie(); 
        
        //reporta la serie de la posición recibida
        Serie getSerie(int); 
        
        //se le manda un elemento de la clase serie para cambiar.
        void setSerie(int,Serie); 
        
        //retorna la cantidad de series
        int getCantidadSeries(); 

        //actualizar el valor de la cantidad de series
        void setCantidadSeries(int);
        
        //mostrar las series que tienen episodios con calificacion especifica.
        void consultaEpisodiosConCalificacion(double);
        
    private:
        Serie series[100]; //arreglo con todas las series
        int cantidadSeries; //cantidad de series dadas de alta
};

//metodo constructor
Series::Series() {
    int cantidadSeries = 0; //se inicializa la cantidad de series con 0
}

//metodo constructor con parámetros
Series::Series(int _cantidadSeries) {
    cantidadSeries = _cantidadSeries; //se incializa con el parámetro
}

//metodo para leer los archivos
void Series::leerArchivo() {
    string sId, sTitulo, sGenero, linea, dato;
    int iR;

    fstream lectura;

    lectura.open("C:\\Users\\emili\\Desktop\\OOP\\ProyectoIntegrador\\Series.csv", ios::in);;
    iR = 0;

    while (getline(lectura,linea)) {
        stringstream registro(linea);
        int columna = 0;
        while (getline(registro, dato, ',')) {
            switch (columna++) {
                case 0:
                    series[iR].setId(dato);
                    break;
                case 1:
                    series[iR].setTitulo(dato);
                    break;
                case 2:
                    series[iR].setDuracion(stoi(dato));
                    break;
                case 3:
                    series[iR].setGenero(dato);
                    break;  
                case 4:
                    series[iR].setCalificacion(stod(dato));
                case 5:
                    series[iR].setCantidadEpisodios(0);
            }
        }
    iR++;
    }
    cantidadSeries = iR; //se actualiza la cantidad de series
    lectura.close();

    //lectura de episodios

    Episodio ep;
    int cantEpisodios, iS;

    lectura.open("C:\\Users\\emili\\Desktop\\OOP\\ProyectoIntegrador\\Episodios.txt",ios::in);
    while (getline(lectura,linea)) {
        stringstream registro(linea);
        int columna = 0;
        while (getline(registro,dato,',')) {
            switch (columna++) {
                case 0:
                    iS = stoi(dato)-100;
                    break;
                case 1:
                    ep.setTitulo(dato);
                    break;
                case 2:
                    ep.setTemporada(stoi(dato));
                    break;
                case 3:
                    ep.setCalificacion(stod(dato));
                    break;  
            }
        }
    cantEpisodios = series[iS].getCantidadEpisodios();
    if (cantEpisodios < 5) {
        series[iS].setEpisodio(cantEpisodios, ep);
        series[iS].setCantidadEpisodios(cantEpisodios +1);
        }
    }
    lectura.close();
}

//reporta todas las series que están dadas de alta. reporta la calificación de la serie al final
void Series::reporteTodasSeries() {
    double suma = 0;

    cout << "ReporteSeries" << endl;
    for (int i = 0; i < cantidadSeries; i++) {
        series[i].imprimir();  //se imprime la serie
        suma += series[i].getCalificacion();  //se suman todas las calificaciones
        cout << endl;
    }

    cout <<"Promedio Series :" << suma/cantidadSeries; //se imprime el promedio


}

//reportar series con calificacion que cumplen con el double, se llama el metodo imprimir
void Series::reporteConCalificacion(double _calificacion) {
    cout << "ReporteSeriesConCalificacion:" << _calificacion << endl;
    for (int i = 0; i < cantidadSeries; i++) { //se recorren todas las series
        double calSerie = series[i].getCalificacion(); //se guarda la calificación actual de la serie

        //si la calificación guardada de la serie es igual al parámetro, se imprime
        if (calSerie == _calificacion) {
            series[i].imprimir();
            cout << endl;
        }

    }
}

//reporta las series con cierto genero
void Series::reporteGenero(string _genero) {
    cout << "ReporteGenero:Ciencia ficcion" << endl;

     //se recorren todas las series
    for (int i = 0; i < cantidadSeries; i++) {

        //si el genero es igual al parámetro, se imprime
        if (series[i].getGenero() == _genero) {
            series[i].imprimir();
            cout << endl;
        }
    }
}

//calcula la calificación promedio en base a los episodios con el metodo de la clase Serie
void Series::calculaCalPromedioSerie() {
    for (int i = 0; i < cantidadSeries; i++) {
        series[i].calculaCalificacionPromedio(); //se manda a llamar el método de la clase Serie para calcular el promedio de cada serie
    }
}

//Recibe un parámetro de entrada, si no existe regresa la serie 0
Serie Series::getSerie(int posicion) {
    if (posicion <= cantidadSeries && posicion >= 0)
        return series[posicion];
    else
        return series[0];
}

//validar que este en el rango. si sí existe se acualiza, si no no cambia nada
void Series::setSerie (int posicion, Serie _serie) {
    if (posicion <= cantidadSeries && posicion >= 0) {
        series[posicion] = _serie;
    }
}

//metodo para regresar cantidadSeries
int Series::getCantidadSeries() {
    return cantidadSeries;
}

//metodo para cambiar el valor cantidadSeries
void Series::setCantidadSeries(int _cantidad) {
    cantidadSeries = _cantidad;
}

//mostrar las series que tienen episodios con calificacion especifica. mostrar los episodios
void Series::consultaEpisodiosConCalificacion(double _calificacion) {
    cout << "ReporteEpisodiosConCalificacion:" << _calificacion << endl;

    //recorre todas las series
    for (int i = 0; i < cantidadSeries; i++) {
        series[i].imprimir(_calificacion); //se manda a llamar el método imprimir de la clase serie con calificación de parámetro
    }
}

#endif /* Serie_h */