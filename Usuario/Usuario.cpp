//
// Created by carlo on 11/6/2025.
//

#include "Usuario.h"
#include <iostream>
#include <regex>
using namespace std;


Usuario::Usuario() : edad(0) {}

void Usuario::ingresarDatos() {
    string temporal;
    int edad, id;

    cout << "Ingrese su DNI:  ";
    cin >> id;
    setId(id);

    cout << "Ingrese su nombre:  ";
    cin >> temporal;
    setNombre(temporal);

    cout << "Ingrese su apellido:  ";
    cin >> temporal;
    setApellido(temporal);

    cout << "Ingrese su edad:  ";
    cin >> edad; setEdad(edad);


    cout << "Ingrese su correo electronico:  ";
    cin >> temporal;
    setMail(temporal);

    cout << endl;
}

int Usuario::getId() const { return idUsuario; }
void Usuario::setId(int id) { idUsuario = id; }

string Usuario::getNombre() const { return nombre; }
void Usuario::setNombre(const string &nombre) { this->nombre = nombre; }

string Usuario::getApellido() const { return apellido; }
void Usuario::setApellido(const string &apellido) { this->apellido = apellido; }

string Usuario::getMail() const { return mail; }
void Usuario::setMail(const string &mail) {
    regex formatoMail("^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$");
    if (regex_match(mail, formatoMail)) {
        this->mail = mail;
    }else {
        cout << "Email invalido." << endl;
    }
}

int Usuario::getEdad() const { return edad; }
void Usuario::setEdad(int edad) {
    if (edad > 0 && edad < 100) {
        this->edad = edad;
    } else {
        cout << "Edad inválida." << endl;
    };
}










