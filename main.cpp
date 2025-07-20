#include <iostream>
#include <vector>
#include <fstream>
#include "Usuario/Usuario.h"
#include "Vuelo/Vuelo.h"
#include "Fecha/Fecha.h"
#include "Menus/Menus.h"
using namespace std;


void guardarReservaCSV(const Usuario& usuario, const Vuelo& vuelo, const vector<string>& asientos);

int main() {

    vector<Vuelo> vuelos = {
        Vuelo(101, "Aerolineas Argentinas", "Buenos Aires", "Cordoba", Fecha(20, 7, 2025), Fecha(20, 7, 2025)),
        Vuelo(102, "LATAM", "Mendoza", "Salta", Fecha(21, 7, 2025), Fecha(21, 7, 2025)),
        Vuelo(103, "Flybondi", "Rosario", "Iguazu", Fecha(22, 7, 2025), Fecha(22, 7, 2025))
    };

    int opcPrincipal;
    do {
        cout << "---------------- Bienvenido al Sistema de Gestion de Vuelos ----------------" << endl;
        cout << "1. Administrador" << endl;
        cout << "2. Usuario" << endl;
        cout << "0. Salir del programa" << endl;
        cout << "Selecione una opcion: ";
        cin >> opcPrincipal;

        switch (opcPrincipal) {
            case 1:
                mostrarMenuAdmin();
                break;
            case 2:
                mostrarMenuUsuario(vuelos);
                break;
            case 0:
                cout << "Gracias por usar el sistema" << endl;
                break;
            default:
                cout << "Opcion invalida. Intente nuevamente" << endl;
        }
    }while (opcPrincipal != 0);
    return 0;
}