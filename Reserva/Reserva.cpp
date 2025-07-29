//
// Created by carlo on 21/7/2025.
//

#include "Reserva.h"
#include <iostream>
using namespace std;

Reserva::Reserva(const Usuario &usuario, const vector<string> &asientos) : usuario(usuario), asientos(asientos){}

Usuario Reserva::getUsuario() const { return usuario; }

vector<string> Reserva::getAsientos() const { return asientos; }

void Reserva::mostrarReserva() const {
    cout << "- Vuelo: " << numVuelo
        << " | Asientos: ";
    for (const auto &asiento : asientos) {
        cout << asiento << " - ";
    }
    cout << endl;
}



