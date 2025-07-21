//
// Created by carlo on 11/6/2025.
//

#include "Vuelo.h"
#include "../Usuario/Usuario.h"
#include <iostream>
#include <iomanip>
using namespace std;

Vuelo::Vuelo(int numVuelo, string aerolinea, string origen, string destino, Fecha salida, Fecha llegada) : numVuelo(numVuelo), aerolinea(aerolinea), origen(origen), destino(destino), fechaSalida(salida), fechaLlegada(llegada){
    char fila = 'A';
    for (int i = 0; i < FILAS ; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            asientos[i][j] = fila + to_string(j + 1);
        }
        fila++;
    }
}

int Vuelo::getNumVuelo() const { return numVuelo; }
void Vuelo::setNumVuelo(int n) { this->numVuelo = numVuelo; }

string Vuelo::getAerolinea() const { return aerolinea; }
void Vuelo::setAerolinea(const string &aerolinea) { this->aerolinea = aerolinea; }

string Vuelo::getOrigenVuelo() const { return origen; }
void Vuelo::setOrigenVuelo(const string &origen) { this->origen = origen; }

string Vuelo::getDestinoVuelo() const { return destino; }
void Vuelo::setDestinoVuelo(const string &destino) { this->destino = destino; }

Fecha Vuelo::getFechaSalida() const { return fechaSalida; }
void Vuelo::setFechaSalida(const Fecha &salida) { fechaSalida = salida; }

Fecha Vuelo::getFechaLlegada() const { return fechaLlegada; }
void Vuelo::setFechaLlegada(const Fecha &llegada) { fechaLlegada = llegada; }

void Vuelo::mostrarVuelo() const {
    cout << " Vuelo: " << numVuelo << " - " << aerolinea << " | " << origen << " -> " << destino << " | ";
    fechaSalida.mostrarFecha();
    cout << " - ";
    fechaLlegada.mostrarFecha();
    cout << endl;
}

void Vuelo::mostrarAsientos() const {
    cout << "Asientos disponibles: " << endl;
    for (int i = 0; i < FILAS ; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            cout << "[" << setw(2) << asientos[i][j] << "]";
        }
        cout << endl;
    }
}

bool Vuelo::reservarAsiento(string codigo) {
    for (int i = 0; i < FILAS ; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            if (asientos[i][j] == codigo) {
                asientos[i][j] = " X ";
                return true;
            }
        }
    }
    return false;
}

void reservarVuelo(Usuario &usuario, vector<Vuelo> &vuelos) {
    int opcVuelo, cantPasajes;

    if (usuario.getId().empty()) {
        cout << "Por favor ingrese sus datos: " << endl;
        usuario.ingresarDatos();
    }

    do {
        cout << "Seleccione un vuelo (1 - " << vuelos.size() << "): ";
        cin >> opcVuelo;
        cin.ignore();

        while (opcVuelo < 1 || opcVuelo > vuelos.size()) {
            cout << "Opcion invalida. Intente nuevamente." << endl;
            cout << "Seleccione un vuelo (1 - " << vuelos.size() << "): ";
            cin >> opcVuelo;
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

}

void mostrarVuelos (const vector<Vuelo> &vuelos){
    cout << "--------------- Vuelos disponibles ---------------" << endl;
    for (size_t i = 0; i < vuelos.size(); i++) {
        cout << i + 1 << ". ";
        vuelos[i].mostrarVuelo();
        cout << endl;
    }
}

void consultarAsientosDisponibles(const vector<Vuelo> &vuelos) {
    int opc;
    do {
        cout << "Seleccione un vuelo: ";
        cin >> opc;
        if (opc >= 1 && opc <= vuelos.size()) {
            vuelos[opc - 1].mostrarAsientos();
        }else {
            cout << "Opcion invalida";
        }
    }while (opc < 1 || opc > vuelos.size());

}

void agregarVuelo(vector<Vuelo> &vuelos) {
    int numVuelo;
    string aerolinea, origen, destino;
    Fecha fechaSalida, fechaLlegada;

    cout << "- Numero de vuelo: ";
    cin >> numVuelo;
    cin.ignore();

    cout << "- Aerolinea: ";
    cin >> aerolinea;
    cin.ignore();

    cout << "- Origen: ";
    cin >> origen;
    cin.ignore();

    cout << "- Destino: ";
    cin >> destino;
    cin.ignore();

    cout << "- Fecha de salida: ";
    fechaSalida.ingresarFecha();

    cout << "- Fecha de llegada: ";
    fechaLlegada.ingresarFecha();

    Vuelo nuevoVuelo(numVuelo, aerolinea, origen, destino, fechaSalida, fechaLlegada);
    vuelos.push_back(nuevoVuelo);

    cout << "Vuelo agregado con exito" << endl;

}

void modificarVuelo(vector<Vuelo> &vuelos) {
    int numVueloABuscar, opc;
    string temporal;
    Fecha fecha;
    bool encontrado = false;

    cout << "Ingrese el numero del vuelo a modificar: ";
    cin >> numVueloABuscar;

    for (Vuelo &vuelo : vuelos) {
        if (vuelo.getNumVuelo() == numVueloABuscar) {
            encontrado = true;
            do {
                cout << "Seleccione el valor a modificar: ";
                cout << "1) Numero de vuelo" << endl;
                cout << "2) Aerolinea" << endl;
                cout << "3) Origen" << endl;
                cout << "4) Destino" << endl;
                cout << "5) Fecha de salida" << endl;
                cout << "6) Fecha de llegada" << endl;
                cout << "0) Volver al menu principal" << endl;
                cin >> opc;

                switch (opc) {
                    case 1:
                        int numVuelo;
                        cout << "Num de vuelo actual: " << numVuelo << endl;
                        cout << "Ingrese el nuevo numero de vuelo: ";
                        cin >> numVuelo;
                        vuelo.setNumVuelo(numVuelo);
                        cout << "Cambio realizado con exito" << endl;
                        break;
                    case 2:
                        cout << "Aerolinea actual: " << vuelo.getAerolinea() << endl;
                        cout << "Ingrese la nueva aerolinea: ";
                        cin >> temporal;
                        cin.ignore();
                        vuelo.setAerolinea(temporal);
                        cout << "Cambio realizado con exito" << endl;
                        break;
                    case 3:
                        cout << "Origen actual del vuelo: " << vuelo.getOrigenVuelo() << endl;
                        cout << "Ingrese el nuevo lugar de origen: ";
                        cin >> temporal;
                        cin.ignore();
                        vuelo.setOrigenVuelo(temporal);
                        cout << "Cambio realizado con exito" << endl;
                        break;
                    case 4:
                        cout << "Origen actual del vuelo: " << vuelo.getDestinoVuelo() << endl;
                        cout << "Ingrese el nuevo lugar de destino: ";
                        cin >> temporal;
                        cin.ignore();
                        vuelo.setDestinoVuelo(temporal);
                        cout << "Cambio realizado con exito" << endl;
                        break;
                    case 5:
                        cout << "Fecha de salida actual: ";
                        vuelo.getFechaSalida().mostrarFecha();
                        cout << "Ingrese la nueva fecha de salida: ";
                        fecha.ingresarFecha();
                        vuelo.setFechaSalida(fecha);
                        cout << "Cambio realizado con exito" << endl;
                        break;
                    case 6:
                        cout << "Fecha de llegada actual: ";
                        vuelo.getFechaLlegada().mostrarFecha();
                        cout << "Ingrese la nueva fecha de llegada: ";
                        fecha.ingresarFecha();
                        vuelo.setFechaLlegada(fecha);
                        cout << "Cambio realizado con exito" << endl;
                        break;
                    case 0:
                        cout << "Volviendo al menu principal..." << endl;
                        break;
                    default:
                        cout << "Opcion invalida" << endl;
                }
            }while (opc != 0);
            break;
        }
        if (!encontrado) {
            cout << "No se encontro un vuelo con ese numero." << endl;
        }
    }
}



















