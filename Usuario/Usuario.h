//
// Created by carlo on 11/6/2025.
//

#ifndef USUARIO_H
#define USUARIO_H
#include <string>
using namespace std;


class Usuario {
private:
    int idUsuario;
    string nombre;
    string apellido;
    string mail;
public:
    Usuario();
    Usuario(int id, string &nombre,string &apellido, string &mail);

    int getId() const;
    string getNombre() const;
    void setNombre(string &nombre);
    string getApellido();
    void setApellido(string &apellido);
    string getMail() const;
    void setMail(string &mail);
    void mostrarDatosUsuario();
    void consultarReservas() const;

};



#endif //USUARIO_H
