//
// Created by carlo on 11/6/2025.
//

#include "Fecha.h"
#include <iostream>
using namespace std;

Fecha::Fecha() : dia(0), mes(0), anio(0){}
Fecha::Fecha(int dia, int mes, int anio) {
    if (esFecha(dia, mes, anio)) {
        this->dia = dia;
        this->mes = mes;
        this->anio = anio;
    } else {
        cout << "Fecha invalida. Ingrese una fecha valida" << endl;
    }
}

int Fecha::getDia() const{ return dia; }
int Fecha::setDia(int dia) { this->dia = dia; }

int Fecha::getMes() const { return mes; }
int Fecha::setMes(int mes) { this->mes = mes; }

int Fecha::getAnio() const { return anio; }
int Fecha::setAnio(int anio) { this->anio = anio; }

void Fecha::mostrarFecha() const {
    cout << dia << "/" << mes << "/" << anio << endl;
}

bool Fecha::esFecha(int dia, int mes, int anio) const {
    if (anio < 1 || mes < 1 || mes > 12 || dia < 1) {
        return false;
    }

    int diaPorMes[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    if (mes == 2 && (anio%4 == 0 && anio % 100 != 0) || (anio % 400 == 0)) {
        return dia <= 29;
    }
    return dia <= diaPorMes[mes-1];
}





