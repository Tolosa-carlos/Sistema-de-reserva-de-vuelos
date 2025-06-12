//
// Created by carlo on 11/6/2025.
//

#include "Vuelo.h"
#include <iostream>
using namespace std;

Vuelo::Vuelo() : numVuelo(0), aerolinea(""), origenVuelo(""), destinoVuelo(""), fechaLlegada(), fechaSalida(){}
Vuelo::Vuelo(int numVuelo, string &aerolinea, string &origen, string &destino, Fecha salida, Fecha llegada) {
    this->numVuelo = numVuelo;
    this->aerolinea = aerolinea;
    origenVuelo = origen;
    destinoVuelo = destino;
    fechaSalida = salida;
    fechaLlegada = llegada;
}

int Vuelo::getNumVuelo() const { return numVuelo; }

string Vuelo::getAerolinea() const { return aerolinea; }
void Vuelo::setAerolinea(string &aerolinea) { this->aerolinea = aerolinea; }

string Vuelo::getOrigenVuelo() const { return origenVuelo; }
void Vuelo::setOrigenVuelo(string &origen) { origenVuelo = origen; }

string Vuelo::getDestinoVuelo() const { return destinoVuelo; }
void Vuelo::setDestinoVuelo(string &destino) { destinoVuelo = destino; }

Fecha Vuelo::getFechaSalida() const { return fechaSalida; }
Fecha Vuelo::setFechaSalida(Fecha salida) { fechaSalida = salida; }

Fecha Vuelo::getFechaLlegada() const { return fechaLlegada; }
Fecha Vuelo::setFechaLlegada(Fecha llegada) { fechaLlegada = llegada; }

void Vuelo::mostrarVuelo() const {
    cout << "---------------- Datos del vuelo ----------------" << endl;
    cout << "Número de vuelo: " << numVuelo << endl;
    cout << "Aerolinea: " << aerolinea << endl;
    cout << "Origen: " << origenVuelo << endl;
    cout << "Destino: " << destinoVuelo << endl;
    cout << "Fecha de salida: "; fechaSalida.mostrarFecha() << endl;
    cout << "Fecha de llegada: ", fechaLlegada.mostrarFecha() << endl;
}











