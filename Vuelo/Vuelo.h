//
// Created by carlo on 11/6/2025.
//

#ifndef VUELO_H
#define VUELO_H
#define FILAS 5
#define COLUMNAS 4
#include <string>
#include <vector>

#include "../Fecha/Fecha.h"
using namespace std;

class Vuelo {
private:
    string asientos[FILAS][COLUMNAS];
    int numVuelo;
    string aerolinea, origen, destino;
    Fecha fechaSalida, fechaLlegada;
public:
    Vuelo(int numVuelo, string aerolinea, string origen, string destino, Fecha salida, Fecha llegada);

    int getNumVuelo() const;
    void setNumVuelo(int n);

    string getAerolinea() const;
    void setAerolinea(const string &aerolinea);

    string getOrigenVuelo() const;
    void setOrigenVuelo(const string &origen);

    string getDestinoVuelo() const;
    void setDestinoVuelo(const string &destino);

    Fecha getFechaSalida() const;
    void setFechaSalida(const Fecha &salida);

    Fecha getFechaLlegada() const;
    void setFechaLlegada(const Fecha &llegada);

    void mostrarVuelo() const;
    void mostrarAsientos() const;

    bool reservarAsiento(string codigo);

};

void mostrarVuelos (const vector<Vuelo> &vuelos);
void consultarAsientosDisponibles(const vector<Vuelo> &vuelos);




#endif //VUELO_H
