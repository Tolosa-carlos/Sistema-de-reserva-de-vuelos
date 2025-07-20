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

    do {
        cout << "1) Consultar vuelos disponibles" << endl;
        cout << "2) Ver asientos disponibles" << endl;
        cout << "3) Realizar una reserva" << endl;
        cout << "4) Cambiar datos de usuario" << endl;
        cout << "5) Consultar reservas" << endl;
        cout << "6) Cancelar reserva" << endl;
        cout << "7) Buscar vuelos" << endl;
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
            case 5:
                //consultarReservas();
                break;
            case 6:
                //cancelarReserva();
                break;
            case 7:
                //buscarVuelos();
                break;
            case 0:
                cout << "Volviendo al menu principal..." << endl;
                break;
            default:
                cout << "Opcion invalida" << endl;
        }
    }while (opcUsuario != 0);
}

void mostrarMenuAdmin() {
    vector<Vuelo> vuelos;
    int opcAdmin;
    do {
        cout << "1) Ver lista de vuelos" << endl;
        cout << "2) Agregar nuevo vuelo" << endl;
        cout << "3) Modificar vuelo" << endl;
        cout << "4) Eliminar vuelo" << endl;
        cout << "5) Consultar reservas por vuelo" << endl; //Que muestre todos los usuarios que reservaron un vuelo X
        cout << "0) Volver al menu principal" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcAdmin;

        switch (opcAdmin) {
            case 1:
                if (vuelos.empty()) {
                    cout << "No hay vuelos disponibles." << endl;
                }else {
                    mostrarVuelos(vuelos);
                }
                break;
            case 2:
                break;
        }
    }while (opcAdmin != 0);
}