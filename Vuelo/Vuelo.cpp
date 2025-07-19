//
// Created by carlo on 11/6/2025.
//

#include "Vuelo.h"
#include <iostream>
#include <iomanip>
using namespace std;

Vuelo::Vuelo(int numVuelo, string aerolinea, string origen, string destino, Fecha salida, Fecha llegada) : numVuelo(numVuelo), aerolinea(aerolinea), origen(origen), destino(destino), fechaSalida(salida), fechaLlegada(llegada){
    char fila = 'A';
    for (int i = 0; i < FILAS ; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            asientos[i][j] = fila + to_string(j + 1);
        }
        fila++;
    }
}

int Vuelo::getNumVuelo() const { return numVuelo; }
void Vuelo::setNumVuelo(int n) { this->numVuelo = numVuelo; }

string Vuelo::getAerolinea() const { return aerolinea; }
void Vuelo::setAerolinea(const string &aerolinea) { this->aerolinea = aerolinea; }

string Vuelo::getOrigenVuelo() const { return origen; }
void Vuelo::setOrigenVuelo(const string &origen) { this->origen = origen; }

string Vuelo::getDestinoVuelo() const { return destino; }
void Vuelo::setDestinoVuelo(const string &destino) { this->destino = destino; }

Fecha Vuelo::getFechaSalida() const { return fechaSalida; }
void Vuelo::setFechaSalida(const Fecha &salida) { fechaSalida = salida; }

Fecha Vuelo::getFechaLlegada() const { return fechaLlegada; }
void Vuelo::setFechaLlegada(const Fecha &llegada) { fechaLlegada = llegada; }

void Vuelo::mostrarVuelo() const {
    cout << " Vuelo: " << numVuelo << " - " << aerolinea << " | " << origen << " -> " << destino << " | ";
    fechaSalida.mostrarFecha();
    cout << " - ";
    fechaLlegada.mostrarFecha();
    cout << endl;
}

void Vuelo::mostrarAsientos() const {
    cout << "Asientos disponibles: " << endl;
    for (int i = 0; i < FILAS ; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            cout << "[" << setw(2) << asientos[i][j] << "]";
        }
        cout << endl;
    }
}

bool Vuelo::reservarAsiento(string codigo) {
    for (int i = 0; i < FILAS ; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            if (asientos[i][j] == codigo) {
                asientos[i][j] = " X ";
                return true;
            }
        }
    }
    return false;
}

void mostrarVuelos (const vector<Vuelo> &vuelos){
    cout << "--------------- Vuelos disponibles ---------------" << endl;
    for (size_t i = 0; i < vuelos.size(); i++) {
        cout << i + 1 << ". ";
        vuelos[i].mostrarVuelo();
        cout << endl;
    }
}


void consultarAsientosDisponibles(const vector<Vuelo> &vuelos) {
    int opc;
    do {
        mostrarVuelos(vuelos);
        cout << "Seleccione un vuelo: ";
        cin >> opc;
        if (opc >= 1 && opc <= vuelos.size()) {
            vuelos[opc - 1].mostrarAsientos();
        }else {
            cout << "Opcion invalida";
        }
    }while (opc < 1 || opc > vuelos.size());

}




















