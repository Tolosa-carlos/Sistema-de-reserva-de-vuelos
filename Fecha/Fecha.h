//
// Created by carlo on 11/6/2025.
//

#ifndef FECHA_H
#define FECHA_H



class Fecha {
private:
    int dia;
    int mes;
    int anio;
public:
    Fecha();
    Fecha(int dia, int mes, int anio);
    int getDia() const;
    int setDia(int dia);
    int getMes() const;
    int setMes(int mes);
    int getAnio() const;
    int setAnio(int anio);
    void mostrarFecha() const;
    bool esFecha(int dia, int mes, int anio) const;
};



#endif //FECHA_H
