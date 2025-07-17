#include <iostream>
#include <vector>
#include "Usuario/Usuario.h"
#include "Vuelo/Vuelo.h"
#include "Fecha/Fecha.h"
using namespace std;

void mostrarVuelos( const vector<Vuelo> &vuelos) {
    cout << "Lista de vuelos disponibles: " << endl;
    for (size_t i = 0; i < vuelos.size(); i++) {
        cout << i + 1 << ". ";
        vuelos[i].mostrarVuelo();
    }
}

int main() {
    vector<Vuelo> vuelos = {
        Vuelo(101, "Aerolineas Argentinas", "Buenos Aires", "Cordoba", Fecha(20, 7, 2025), Fecha(20, 7, 2025)),
        Vuelo(102, "LATAM", "Mendoza", "Salta", Fecha(21, 7, 2025), Fecha(21, 7, 2025)),
        Vuelo(103, "Flybondi", "Rosario", "Iguazu", Fecha(22, 7, 2025), Fecha(22, 7, 2025))
    };

    Usuario usuario;
    cout << "--------------- Sistema de Gestion de Vuelos ---------------" << endl;
    usuario.ingresarDatos();

    int opc;
    do {
        mostrarVuelos(vuelos);
        cout << "Seleccione un vuelo (1 - " << vuelos.size() << "): ";
        cin >> opc;
        cin.ignore();

        if (opc < 1 || opc > vuelos.size()) {
            cout << "Opcion invalida.";
        }
    }while (opc < 1 || opc > vuelos.size());

    Vuelo& vueloSeleccionado = vuelos[opc - 1];
    int cantPasajes;
    cout << "Cuantos pasajes desea comprar? ";
    cin >> cantPasajes;
    cin.ignore();

    for (int i = 0; i < cantPasajes; i++) {
        vueloSeleccionado.mostrarAsientos();
        string codigo;
        cout << "Seleccione el asiento #" << i + 1 << "(Ejemplo: B2): ";
        cin >> codigo;
        if (!codigo.empty()) { codigo[0] = toupper(codigo[0]); }

        if (vueloSeleccionado.reservarAsiento(codigo)) {
            cout << "Asiento " << codigo << " reservado con exito." << endl;
        }else {
            cout << "Asiento invalido u ocupado. Intente de nuevo: ";
            --i;
        }
    }

    cout << "--------------- Resumen de la reserva ----------------" << endl;

    cout << "Reserva completada con exito." << endl;
    return 0;
}