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
        cout << "4) Cambiar datos del usuario" << endl;
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
                if (usuario.getId().empty()) {
                    cout << "Por favor ingrese sus datos: " << endl;
                    //usuario.ingresarDatos();
                }

                do {
                    cout << "Seleccione un vuelo (1 - " << vuelos.size() << "): ";
                    cin >> opcVuelo;
                    cin.ignore();

                    if (opcVuelo <= 0 || opcVuelo > vuelos.size()) {
                        cout << "Opcion invalida. Intente nuevamente." << endl;
                    }

                    Vuelo &vueloSeleccionado = vuelos[opcVuelo - 1];
                    cout << "Cuantos pasajes desea reservar? ";
                    cin >> cantPasajes;
                    cin.ignore();
                    cout << endl;
                    vector<string> asientos(cantPasajes);

                    for (int i = 0; i < cantPasajes; i++) {
                        vueloSeleccionado.mostrarAsientos();
                        string codigo;
                        cout << "Seleccione el asiento #" << i + 1 << "(Ejemplo: B2): ";
                        cin >> codigo;
                        cout << endl;

                        if (!codigo.empty()){ codigo[0] = toupper(codigo[0]); }
                        if (vueloSeleccionado.reservarAsiento(codigo)) {
                            cout << "Asiento #" << codigo << " reservado con exito." << endl;
                            asientos[i] = codigo;
                        }else {
                            cout << "Asiento invalido u ocupado. Intente nuevamente: " << endl;
                            i--;
                        }
                    }

                    cout << "--------------- Resumen de la reserva ----------------" << endl;
                    cout << " - DNI: " << usuario.getId() << endl;
                    cout << " - Nombre: " << usuario.getNombre()<< endl;
                    cout << " - Apellido: " << usuario.getApellido() << endl;
                    cout << " - Edad: " << usuario. getEdad() << endl;
                    cout << " - Email: " << usuario.getMail() << endl;
                    vueloSeleccionado.mostrarVuelo();
                    cout << " - Asientos reservados: " << endl;
                    for (int i = 0; i < cantPasajes; i++) {
                        cout <<"    + " << asientos[i] << endl;;
                    }
                    cout << "Reserva de vuelo completada con exito." << endl;

                }while (opcVuelo < 1 || opcVuelo > vuelos.size());

                break;
            case 4:
                usuario.ingresarDatos();
                break;
            case 0:
                cout << "Volviendo al menu principal..." << endl;
                break;
            default:
                cout << "Opcion invalida" << endl;
        }
    }while (opcUsuario != 0);
}
