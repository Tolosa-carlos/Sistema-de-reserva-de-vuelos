//
// Created by carlo on 11/6/2025.
//

#ifndef FECHA_H
#define FECHA_H



class Fecha {
private:
    int dia, mes, anio;

public:
    Fecha(int dia, int mes, int anio);

    int getDia() const;
    void setDia(int d);

    int getMes() const;
    void setMes(int m);

    int getAnio() const;
    void setAnio(int a);

    void mostrarFecha() const;
};



#endif //FECHA_H
