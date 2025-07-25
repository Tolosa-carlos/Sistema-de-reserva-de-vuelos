//
// Created by carlo on 11/6/2025.
//

#include "Usuario.h"
#include "../Vuelo/Vuelo.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <regex>
#include <filesystem>
using namespace std;

Usuario::Usuario() : edad(0) {}

void Usuario::ingresarDatos() {
    string temporal;
    int edad;

    cout << "Ingrese su DNI:  ";
    cin >> temporal;
    setId(temporal);

    while (true) {
        cout << "Ingrese su nombre:  ";
        cin >> temporal;
        if (regex_match(temporal, regex("^[A-Za-z ]+$"))) {
            temporal[0] = toupper(temporal[0]);
            setNombre(temporal);
            break;
        } else {
            cout << "Nombre invalido." << endl;
        }
    }

    while (true) {
        cout << "Ingrese su apellido:  ";
        cin >> temporal;
        if (regex_match(temporal, regex("^[A-Za-z ]+$"))) {
            temporal[0] = toupper(temporal[0]);
            setApellido(temporal);
            break;
        } else {
            cout << "Apellido invalido." << endl;
        }
    }

    do {
        cout << "Ingrese su edad: ";
        cin >> temporal;

        if (regex_match(temporal, regex("^\\d+$"))) {
            edad = stoi(temporal);
            if (edad > 0 && edad <= 100) {
                setEdad(edad);
                break;
            } else {
                cout << "Edad invalida. Debe estar entre 1 y 100." << endl;
            }
        } else {
            cout << "Entrada invalida. Ingrese solo numeros." << endl;
        }
    } while (true);

    do {
        cout << "Ingrese su correo electronico:  ";
        cin >> temporal;
        regex formatoMail("^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$");
        if (regex_match(temporal, formatoMail)) {
            setMail(temporal);
            break;
        } else {
            cout << "Email invalido. Intente denuevo." << endl;
        }
    }while (true);
}

string Usuario::getId() const { return idUsuario; }
void Usuario::setId(string id) { idUsuario = id; }

string Usuario::getNombre() const { return nombre; }
void Usuario::setNombre(const string &nombre) { this->nombre = nombre; }

string Usuario::getApellido() const { return apellido; }
void Usuario::setApellido(const string &apellido) { this->apellido = apellido; }

string Usuario::getMail() const { return mail; }
void Usuario::setMail(const string &mail) { this->mail = mail; }

int Usuario::getEdad() const { return edad; }
void Usuario::setEdad(int edad) { this->edad = edad; }


void guardarReservaCSV(const Usuario& usuario, const Vuelo& vuelo, const vector<string>& asientos) {
    string nombreArchivo = "reservas.csv";
    bool archivoExiste = filesystem::exists(nombreArchivo);
    ofstream archivo(nombreArchivo, ios::app);


    if (!archivoExiste) {
        archivo << "DNI, Nombre, Apellido, Edad, Email, "
                << "NroVuelo, Aerolinea, Origen, Destino, "
                << "FechaSalida, FechaLlegada, Asientos\n";
    }

    if (archivo.is_open()) {
        archivo << usuario.getId() << ", "
                << usuario.getNombre() << " "
                << usuario.getApellido() << ", "
                << usuario.getEdad() << ", "
                << usuario.getMail() << ", "
                << vuelo.getNumVuelo() << ", "
                << vuelo.getAerolinea() << ", "
                << vuelo.getOrigenVuelo() << ", "
                << vuelo.getDestinoVuelo() << ", "
                << vuelo.getFechaSalida().getDia() << " / " << vuelo.getFechaSalida().getMes() << " / " << vuelo.getFechaSalida().getAnio() << ", "
                << vuelo.getFechaLlegada().getDia() << " / " << vuelo.getFechaLlegada().getMes() << " / " << vuelo.getFechaLlegada().getAnio() << ", ";


        for (size_t i = 0; i < asientos.size(); i++) {
            archivo << asientos[i];
            if (i < asientos.size() - 1) {
                archivo << " - ";
            }
        }

        archivo << "\n";
        archivo.close();
        cout << "Reserva guardada con exito." << endl;
    }else {
        cerr << "No se pudo abrir el archivo. \n";
    }


};






