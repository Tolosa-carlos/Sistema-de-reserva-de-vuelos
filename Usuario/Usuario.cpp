//
// Created by carlo on 11/6/2025.
//

#include "Usuario.h"
#include <iostream>
using namespace std;

Usuario::Usuario() : idUsuario(0), nombre(""),apellido(""), mail(""){}
Usuario::Usuario(int id, string &nombre,string &apellido, string &mail) : idUsuario(id), nombre(nombre),apellido(apellido), mail(mail){}

int Usuario::getId() const { return idUsuario; }

string Usuario::getNombre() const { return nombre; }
void Usuario::setNombre(string &nombre) { this->nombre = nombre; }

string Usuario::getApellido() { return apellido; }
void Usuario::setApellido(string &apellido) { this->apellido = apellido; }

string Usuario::getMail() const { return mail; }
void Usuario::setMail(string &mail) { this->mail = mail; }

void Usuario::mostrarDatosUsuario() {
    cout << "Id: " << idUsuario << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Apellido: " << apellido << endl;
    cout << "Mail: " << mail << endl;
}

void Usuario::consultarReservas() const {

}






