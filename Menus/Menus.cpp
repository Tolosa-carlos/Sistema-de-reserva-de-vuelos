//
// Created by carlo on 19/7/2025.
//

#include "Menus.h"
#include "../Usuario/Usuario.h"
#include "../Vuelo/Vuelo.h"
#include <iostream>
using namespace std;


void mostrarMenuUsuario(vector<Vuelo> &vuelos) {
    Usuario usuario;

    int opcUsuario;
    int opcVuelo;
    int cantPasajes;
    do {
        cout << "1) Consultar vuelos disponibles" << endl;
        cout << "2) Ver asientos disponibles" << endl;
        cout << "3) Realizar una reserva" << endl;
        cout << "4) Cambiar datos de usuario" << endl;
        cout << "0) Volver al menu principal" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcUsuario;

        switch (opcUsuario) {
            case 1:
                mostrarVuelos(vuelos);
                break;
            case 2:
                consultarAsientosDisponibles(vuelos);
                break;
            case 3:
                reservarVuelo(usuario, vuelos);
                break;
            case 4:
                usuario.ingresarDatos();
                reservarVuelo(usuario, vuelos);
                break;
            case 0:
                cout << "Volviendo al menu principal..." << endl;
                break;
            default:
                cout << "Opcion invalida" << endl;
        }
    }while (opcUsuario != 0);
}
