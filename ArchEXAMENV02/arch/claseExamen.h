#ifndef CLASEEXAMEN_H_INCLUDED
#define CLASEEXAMEN_H_INCLUDED

#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;


class Examen{
private:
    int _legajo;
    int _codMateria;
    float _calificacion; //0 - 10
    char _tipoExamen; //('P' - Parcial o 'F' - Final)
    int dia, mes, anio;

public:

///Gets
int getLegajo(){return _legajo;}
int getcodMateria(){return _codMateria;}
float getCalificacion(){return _calificacion;}
char getTipoExamen(){return _tipoExamen;}
int getDia(){return dia;}
int getMes(){return mes;}
int getAnio(){return anio;}


///Sets

void setLegajo(int legajo){_legajo=legajo;}
void setcodMateria(int codMateria){_codMateria=codMateria;}
void setCalificacion(float calificacion){_calificacion=calificacion;}
void setTipoExamen(char tipoExa){_tipoExamen=tipoExa;}
void setDia(int d){dia=d;}
    void setMes(int m){
        if (m>=1 && m<=12){
        mes=m;
        }
    }
void setAnio(int a){anio=a;}

void cargar();
bool guardarArchivo(Examen);




};

void Examen::cargar(){

int lega;
int cod;
float calif;
char exa;
///Seteo de fecha
int di;
int ms;
int an;

cout << endl << "Cargar legajo: ";
cin >> lega;
setLegajo(lega);
cout << endl << "Cargar codigo de materia: ";
cin >> cod;
setcodMateria(cod);
cout << endl << "Cargar calificacion (0-10): ";
cin >> calif;
setCalificacion(calif);
cout << endl << "Cargar tipo de examen ('P' - Parcial o 'F' - Final) :  ";
cin >> exa;
setTipoExamen(exa);
cout << endl << "Cargar fecha: ";
cout << endl << "Dia: ";
cin >> di;
setDia(di);
cout << endl << "Mes: ";
cin >> ms;
setMes(ms);
cout << endl << "Anio: ";
cin >> an;
setAnio(an);
}


bool Examen::guardarArchivo(Examen aux){
FILE *pGrabar = fopen("Examenes.dat", "ab");
if (pGrabar==NULL){return false;}

bool guardo = fwrite(&aux, sizeof(Examen),1,pGrabar);
fclose(pGrabar);
return guardo;


}

/// Funicones globales
void cargarRegistro();
void listarRegistros();
int buscarParcial(int leg, int mat);






#endif // CLASEEXAMEN_H_INCLUDED
