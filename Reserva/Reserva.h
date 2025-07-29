//
// Created by carlo on 21/7/2025.
//

#ifndef RESERVA_H
#define RESERVA_H
#include "../Usuario/Usuario.h"
#include <vector>
using namespace std;

class Reserva{
private:
    Usuario usuario;
    int numVuelo;
    vector<string> asientos;
public:
    Reserva(const Usuario &usuario, const vector<string> &asientos);
    Usuario getUsuario() const;
    vector<string> getAsientos() const;

    void mostrarReserva() const;
};
#endif //RESERVA_H
