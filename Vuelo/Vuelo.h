//
// Created by carlo on 11/6/2025.
//

#ifndef VUELO_H
#define VUELO_H
#include <string>

#include "../Fecha/Fecha.h"
using namespace std;

class Vuelo {
private:
    int numVuelo;
    string aerolinea;
    string origenVuelo;
    string destinoVuelo;
    Fecha fechaSalida;
    Fecha fechaLlegada;
    //Asiento asiento;
public:
    Vuelo();
    Vuelo(int numVuelo, string &aerolinea, string &origen, string &destino, Fecha salida, Fecha llegada);
    int getNumVuelo() const;
    string getAerolinea() const;
    void setAerolinea(string &aerolinea);
    string getOrigenVuelo() const;
    void setOrigenVuelo(string &origen);
    string getDestinoVuelo() const;
    void setDestinoVuelo(string &destino);
    Fecha getFechaSalida() const;
    Fecha setFechaSalida(Fecha salida);
    Fecha getFechaLlegada() const;
    Fecha setFechaLlegada(Fecha llegada);
    void mostrarVuelo() const;
};



#endif //VUELO_H
