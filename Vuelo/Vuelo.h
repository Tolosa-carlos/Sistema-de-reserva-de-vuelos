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
    Fecha fecha;
};



#endif //VUELO_H
