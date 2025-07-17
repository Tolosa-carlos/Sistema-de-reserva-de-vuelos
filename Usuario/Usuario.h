//
// Created by carlo on 11/6/2025.
//

#ifndef USUARIO_H
#define USUARIO_H
#include <string>
using namespace std;


class Usuario {
private:
    int idUsuario, edad;
    string nombre, apellido, mail;

public:
    Usuario();

    void ingresarDatos();

    int getId() const;
    void setId(int id);

    string getNombre() const;
    void setNombre(const string &nombre);

    string getApellido() const;
    void setApellido(const string &apellido);

    string getMail() const;
    void setMail(const string &mail);

    int getEdad() const;
    void setEdad(int edad);

};



#endif //USUARIO_H
