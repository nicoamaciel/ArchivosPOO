#ifndef CLASEEXAMEN_H_INCLUDED
#define CLASEEXAMEN_H_INCLUDED

#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

#include "claseFecha.h"

class Examen{
private:
    int _legajo;
    int _codMateria;
    float _calificacion; //0 - 10
    char _tipoExamen; //('P' - Parcial o 'F' - Final)
    Fecha _fecha;

public:

///Gets
int getLegajo(){return _legajo;}
int getcodMateria(){return _codMateria;}
float getCalificacion(){return _calificacion;}
char getTipoExamen(){return _tipoExamen;}


///Sets

void setLegajo(int legajo){_legajo=legajo;}
void setcodMateria(int codMateria){_codMateria=codMateria;}
void setCalificacion(float calificacion){_calificacion=calificacion;}
void setTipoExamen(char tipoExa){_tipoExamen=tipoExa;}


void cargar();
void mostrar();
bool guardarArchivo(Examen);
void listarRegistros();



};

void Examen::cargar(){

int lega;
int cod;
float calif;
char exa;


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
cout<<endl;
_fecha.Cargar();

}

void Examen::mostrar(){

cout << endl << "Legajo: " << getLegajo();
cout << endl << "Codigo de materia: " << getcodMateria();
cout << endl << "Calificacion: " << getCalificacion();
cout << endl << "Tipo de examen: " << getTipoExamen();
cout << endl << "Fecha: ";
_fecha.Mostrar();

}

bool Examen::guardarArchivo(Examen aux){
FILE *pGrabar = fopen("Examenes.dat", "ab");
if (pGrabar==NULL){return false;}

bool guardo = fwrite(&aux, sizeof(Examen),1,pGrabar);
fclose(pGrabar);
return guardo;


}


void Examen::listarRegistros(){
Examen aux;
FILE *pLeer = fopen("Examenes.dat", "rb");
if (pLeer==NULL){cout << "Error al leer";}

while (fread(&aux, sizeof(Examen),1,pLeer)==1){
     aux.mostrar();
     cout << endl;

     }
fclose(pLeer);

}






#endif // CLASEEXAMEN_H_INCLUDED
