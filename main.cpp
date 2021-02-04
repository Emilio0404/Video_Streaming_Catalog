//  main.cpp
//  SituacionProblemaFinal - caso 1 - Avance 1  - y caso 2 - Avance 2 
//
//  Created by Ma. Guadalupe Roque on 12/11/20.
//  Copyright © 2020 Invitado. All rights reserved.
//
// ********************************************* DETALLE IMPORTANTE -********************************************************************

//. el método imprimir de la clase Serie (version anterior )despliega los atributos en el siguiente orden:
// cout << id << ", " << titulo << ", " <<  duracion << ", " << genero << ", " << cantidad << ", " <<  calificacion << endl;
// tambien va a imprimir todos los epido

// método imprimir( ) de Episodio
// cout << titulo << ", " <<  temporada << ", " <<  calificacion << endl;

// ********************************************* DETALLE IMPORTANTE -********************************************************************


#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

//se incluyen todas las clases
#include "Serie.h"
#include "Episodio.h"
#include "Series.h"



int main() {
   
    Series negocio; //objeto negocio para la clase series
    
    int iOpcion; //input del usuario
  
    cin >> iOpcion;
    
    // leer todas las series desde el archivo
    negocio.leerArchivo();
    
    switch (iOpcion) {
        case 1:
             negocio.setSerie(0,  negocio.getSerie(5)); //se actualiza el elemento 0 con el 5
             negocio.getSerie(5).imprimir(); //imprime la serie 5
             negocio.getSerie(0).imprimir(); //imprime la serie 0
             negocio.calculaCalPromedioSerie(); //no despliega solo actualiza el promedio
             negocio.reporteTodasSeries(); //reporta todas las series
            break;
        case 2:
            // Retorna la cantiadad de series que tenemos en existencia
            cout << negocio.getCantidadSeries() << endl; //imprime la cantidad de series
            negocio.consultaEpisodiosConCalificacion(9.5); //imprime los episodios con calificacion 9.5
            break;
        case 3:
            //
            negocio.reporteConCalificacion(4.5); //reporta las series que tiene 4.5 de calificacion
            break;
            
        case 4:
            // Calcula la calificación promedio de todas las serie en base a sus episodios y despliega su titulo y su calificación promedio
               negocio.calculaCalPromedioSerie(); //no despliega solo actualiza el atributo calificacion
               negocio.reporteConCalificacion(0); //imprime todas las series con calificacion 0
            break;
        case 5:
            // Reporte de Series que tienen cierto genero
               negocio.reporteGenero("Ciencia ficcion");
            break;
    }
   
    return 0;
}

