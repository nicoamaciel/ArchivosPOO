#ifndef CLASEFECHA_H_INCLUDED
#define CLASEFECHA_H_INCLUDED

#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;



class Fecha{
private:
    int dia, mes, anio;


public:
    Fecha(int d=0, int m=0, int a=0){
        dia=d;
        mes=m;
        anio=a;
    }

    void Mostrar();
    void Cargar();

    //Gets
    int getDia(){return dia;}
    int getMes(){return mes;}
    int getAnio(){return anio;}
    //Sets
    void setDia(int d){dia=d;}
    void setMes(int m){
        if (m>=1 && m<=12){
        mes=m;
        }
    }
    void setAnio(int a){anio=a;}


    ~Fecha(){};

};

void Fecha::Mostrar(){
    //cout <<this<<endl;
    cout << this->dia << "/" << this->mes << "/" << this->anio << endl;
}

void Fecha::Cargar(){
    int d;

    cout << "DIA: ";
    cin >> d;
    setDia(d);
    cout << "MES: ";
    cin >> d;
    setMes(d);
    cout << "ANIO: ";
    cin >> d;
    setAnio(d);
}

//FinClaseFecha


#endif // CLASEFECHA_H_INCLUDED
