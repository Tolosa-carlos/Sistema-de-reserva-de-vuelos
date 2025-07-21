//
// Created by carlo on 11/6/2025.
//

#include "Fecha.h"
#include <iostream>
using namespace std;

Fecha::Fecha(int d, int m, int a) : dia(d), mes(m), anio(a){}

Fecha::Fecha() : dia(1), mes(1), anio(2000){}

int Fecha::getDia() const { return dia; }
void Fecha::setDia(int d) { this->dia = d; }

int Fecha::getMes() const { return mes; }
void Fecha::setMes(int m) { this->mes = m; }

int Fecha::getAnio() const { return anio; }
void Fecha::setAnio(int a) { this->anio = a; }

void Fecha::ingresarFecha() {
    cout << "Dia: ";
    cin >> dia;

    cout << "Mes: ";
    cin >> mes;

    cout << "Anio: ";
    cin >> anio;

}

void Fecha::mostrarFecha() const {
    cout << dia << "/" << mes << "/" << anio;
}





