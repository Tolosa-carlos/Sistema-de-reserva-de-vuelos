//
// Created by carlo on 11/6/2025.
//

#include "Vuelo.h"
#include "../Usuario/Usuario.h"
#include "../Reserva/Reserva.h"
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
    cout << " Vuelo: " << numVuelo
        << " - " << aerolinea
        << " | " << origen
        << " -> " << destino << " | ";
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

void Vuelo::agregarReserva(const Reserva &reserva) { reservas.push_back(reserva); }

vector<Reserva> Vuelo::getReserva() const { return reservas; }

void reservarVuelo(Usuario &usuario, vector<Vuelo> &vuelos, vector<Reserva> &reservas) {
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
        Reserva nuevaReserva(usuario, asientos);
        vueloSeleccionado.agregarReserva(nuevaReserva);
        reservas.push_back(nuevaReserva);
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
    getline(cin, aerolinea);

    cout << "- Origen: ";
    getline(cin, origen);

    cout << "- Destino: ";
    getline(cin, destino);

    cout << "- Fecha de salida: " << endl;
    fechaSalida.ingresarFecha();

    cout << "- Fecha de llegada: " << endl;
    fechaLlegada.ingresarFecha();

    Vuelo nuevoVuelo(numVuelo, aerolinea, origen, destino, fechaSalida, fechaLlegada);
    vuelos.push_back(nuevoVuelo);

    cout << "Vuelo agregado con exito" << endl;

}

bool buscarVuelo(vector<Vuelo> &vuelos, int numABuscar) {

    for (const Vuelo &vuelo : vuelos) {
        if (vuelo.getNumVuelo() == numABuscar) {
            return true;
        }
    }
    return false;
}

void buscarVuelos(vector<Vuelo> &vuelos) {
    string destino;
    cout << "Ingrese el destino del vuelo a buscar: ";
    cin >> destino;
    cin.ignore();
    destino[0] = toupper(destino[0]);
    bool encontrado = false;
    for (const Vuelo &vuelo : vuelos) {
        if (vuelo.getDestinoVuelo() == destino) {
            encontrado = true;
            vuelo.mostrarVuelo();
            encontrado = false;
        }
    }

    if (!encontrado) {
        cout << "No se encontraron vuelos con destino a " << destino << endl;
    }
}

void modificarVuelo(vector<Vuelo> &vuelos) {
    int numVueloABuscar, opc;
    string temporal;
    Fecha fecha;

    cout << "Ingrese el numero del vuelo a modificar: ";
    cin >> numVueloABuscar;

    if (buscarVuelo(vuelos, numVueloABuscar)) {
        for (Vuelo &vuelo : vuelos) {
            if (vuelo.getNumVuelo() == numVueloABuscar) {
                cout << "Vuelo a modificar: " << endl;
                vuelo.mostrarVuelo();
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
                vuelo.mostrarVuelo();
                break;
            }
        }
    }else {
        cout << "No se encontro un vuelo con ese numero." << endl;
    }
}

void eliminarVuelo(vector<Vuelo> &vuelos) {
    int numVueloABuscar;

    cout << "Ingrese el numero del vuelo a eliminar: ";
    cin >> numVueloABuscar;
    bool eliminado = false;
    if (buscarVuelo(vuelos, numVueloABuscar)) {
        for (auto i = vuelos.begin(); i != vuelos.end(); i++) {
            if (i->getNumVuelo() == numVueloABuscar) {
                vuelos.erase(i);
                eliminado = true;
                cout << "Vuelo eliminado correctamente." << endl;
                break;
            }
        }
    }

    if (!eliminado) {
        cout << "No se encontro ningun vuelo con el numero ingresado." << endl;
    }
}

void consultarReservasAdmin(const vector<Vuelo> &vuelos) {
    if (vuelos.empty()) {
        cout << "No hay vuelos cargados." << endl;
        return;
    }

    for (const Vuelo &vuelo : vuelos) {
        cout << "-------------- Reservas del vuelo: " << vuelo.getNumVuelo() << " --------------" << endl;

        vector<Reserva> reservas = vuelo.getReserva();
        if (reservas.empty()) {
            cout << "No hay reservas para este vuelo." << endl;
            continue;
        }

        int contador = 0;
        for (const Reserva &reserva : reservas) {
            Usuario usuario = reserva.getUsuario();
            cout << contador + 1 << ") " << usuario.getNombre() << " " << usuario.getApellido() << endl;
            cout << "- DNI: " << usuario.getId() << endl;
            cout << "- Mail: " << usuario.getMail() << endl;

            vector<string> asientos = reserva.getAsientos();
            cout << "Asientos: ";
            for (const string &asiento : asientos) {
                cout << asiento << " - ";
            }
            cout << endl;
        }
    }
}

void consultarReservasUser(const vector<Reserva> &reservas, const Usuario &usuario) {
    cout << "------------ Reservas realizadas ------------" << endl;
    int cont = 0;

    if (!reservas.empty()) {
        for (const auto &reserva : reservas) {
            if (reserva.getUsuario().getId() == usuario.getId()) {
                cout << cont++ << ") ";
                reserva.mostrarReserva();
                cout << endl;
            }
        }
    }else {
        cout << "No tiene reservas realizadas" << endl;
    }

}

void cancelarReserva(vector<Reserva> &reservas, const Usuario &usuario) {
    vector<int> indiceUser;
    cout << "------------- Cancelar reserva -------------" << endl;
    int cont = 0;

    for (size_t i = 0; i < reservas.size(); i++) {
        if (reservas[i].getUsuario().getId() == usuario.getId()) {
            cout << cont++ << ") ";
            reservas[i].mostrarReserva();
            cout << endl;
            indiceUser.push_back(i);
        }
    }

    if (indiceUser.empty()) {
        cout << "No tiene reservas para cancelar." << endl;
        return;
    }

    int opc;
    cout << "Ingrese el numero de la reserva que desee cancelar (0 para salir): ";
    cin >> opc;

    if (opc > 0 && opc <= static_cast<int>(indiceUser.size())) {
        int id = indiceUser[opc-1];
        reservas.erase(reservas.begin() + id);
        cout << "Reserva cancelada con exito." << endl;
    }else if (opc == 0) {
        cout << "Operacion cancelada." << endl;
    }else {
        cout << "Opcion invalida." << endl;
    }
}





















