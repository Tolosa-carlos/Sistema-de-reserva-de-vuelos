#include <iostream>
#include <vector>
#include <fstream>
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

void guardarReservaCSV(const Usuario& usuario, const Vuelo& vuelo, const vector<string>& asientos);

int main() {

    vector<Vuelo> vuelos = {
        Vuelo(101, "Aerolineas Argentinas", "Buenos Aires", "Cordoba", Fecha(20, 7, 2025), Fecha(20, 7, 2025)),
        Vuelo(102, "LATAM", "Mendoza", "Salta", Fecha(21, 7, 2025), Fecha(21, 7, 2025)),
        Vuelo(103, "Flybondi", "Rosario", "Iguazu", Fecha(22, 7, 2025), Fecha(22, 7, 2025))
    };

    Usuario usuario;
    cout << "--------------- Sistema de Gestion de Vuelos ---------------" << endl;
    usuario.ingresarDatos();

    int opcVuelo;

    char opc;
    do {
        do {
            mostrarVuelos(vuelos);
            cout << "Seleccione un vuelo (1 - " << vuelos.size() << "): ";
            cin >> opcVuelo;
            cin.ignore();

            if (opcVuelo < 1 || opcVuelo > vuelos.size()) {
                cout << "Opcion invalida.";
            }

            Vuelo& vueloSeleccionado = vuelos[opcVuelo - 1];
            int cantPasajes;
            cout << "Cuantos pasajes desea comprar? ";
            cin >> cantPasajes;
            cin.ignore();

            vector<string> asientos(cantPasajes);

            for (int i = 0; i < cantPasajes; i++) {
                vueloSeleccionado.mostrarAsientos();
                string codigo;
                cout << "Seleccione el asiento #" << i + 1 << "(Ejemplo: B2): ";
                cin >> codigo;
                if (!codigo.empty()) { codigo[0] = toupper(codigo[0]); }

                if (vueloSeleccionado.reservarAsiento(codigo)) {
                    cout << "Asiento " << codigo << " reservado con exito." << endl;
                    asientos[i] = codigo;
                }else {
                    cout << "Asiento invalido u ocupado. Intente de nuevo: ";
                    --i;
                }
            }

            guardarReservaCSV(usuario, vueloSeleccionado, asientos);

            vueloSeleccionado.mostrarAsientos();

            cout << "--------------- Resumen de la reserva ----------------" << endl;
            cout << " - DNI: " << usuario.getId() << endl;
            cout << " - Nombre: " << toupper(usuario.getNombre()[0]) << endl;
            cout << " - Apellido: " << toupper(usuario.getApellido()[0]) << endl;
            cout << " - Edad: " << usuario. getEdad() << endl;
            cout << " - Email: " << usuario.getMail() << endl;
            vueloSeleccionado.mostrarVuelo();
            cout << " - Asientos reservados: " << endl;
            for (int i = 0; i < cantPasajes; i++) {
                cout <<"    + " << asientos[i] << endl;;
            }

            cout << "Reserva de vuelo completada con exito." << endl;

        }while (opcVuelo < 1 || opcVuelo > vuelos.size());

        cout << "Desea realizar otra reserva? (S/N): ";
        cin >> opc;
        opc = toupper(opc);

    }while (opc != 'N');
    return 0;
}