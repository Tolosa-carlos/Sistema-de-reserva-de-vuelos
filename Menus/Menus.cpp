//
// Created by carlo on 19/7/2025.
//

#include "Menus.h"
#include "../Usuario/Usuario.h"
#include "../Vuelo/Vuelo.h"
#include <iostream>
using namespace std;


void mostrarMenuUsuario(vector<Vuelo> &vuelos, vector<Reserva> &reservas) {

    Usuario usuario;
    int opcUsuario;
    do {
        cout << "1) Consultar vuelos disponibles" << endl;  // Funciona
        cout << "2) Ver asientos disponibles" << endl; // Funciona
        cout << "3) Realizar una reserva" << endl; // Funciona
        cout << "4) Cambiar datos de usuario" << endl; // Funciona
        cout << "5) Consultar reservas" << endl; // Funciona
        cout << "6) Cancelar reserva" << endl; // No funciona
        cout << "7) Buscar vuelos" << endl; // Funciona
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
                reservarVuelo(usuario, vuelos, reservas);
                break;
            case 4:
                usuario.ingresarDatos();
                reservarVuelo(usuario, vuelos, reservas);
                break;
            case 5:
                consultarReservasUser(reservas,usuario);
                break;
            case 6:
                cancelarReserva(reservas,usuario);
                break;
            case 7:
                buscarVuelos(vuelos);
                break;
            case 0:
                cout << "Volviendo al menu principal..." << endl;
                break;
            default:
                cout << "Opcion invalida" << endl;
        }
    }while (opcUsuario != 0);
}

bool loginAdmin() {
    string user, password;
    cout << "--------------- Login Administrador ---------------" << endl;
    cout << "Usuario: ";
    cin >> user;
    cout << "Contrasenia: ";
    cin >> password;

    return (user == "admin" && password == "1234");
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
                agregarVuelo(vuelos);
                break;
            case 3:
                modificarVuelo(vuelos);
                break;
            case 4:
                eliminarVuelo(vuelos);
                break;
            case 5:
                consultarReservasAdmin(vuelos);
                break;
            case 0:
                cout << "Volviendo al menu principal..." << endl;
                break;
            default:
                cout << "Opcion invalida" << endl;
        }
    }while (opcAdmin != 0);
}
