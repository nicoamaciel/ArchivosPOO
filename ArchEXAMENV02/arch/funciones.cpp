#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;
#include "claseExamen.h"


void cargarRegistro(){

Examen aux;
aux.cargar();
bool guardo = aux.guardarArchivo(aux);
if (guardo==1){
    cout << "Archivo guardado con exito! ";
}else{
cout << "error al guardar! ";
}


}



void listarRegistros(){
Examen aux;
FILE *pLeer = fopen("Examenes.dat", "rb");
if (pLeer==NULL){cout << "Error al leer";}


cout << endl << "                 LISTADO DE EXAMENES ";
cout << endl << " LEGAJO " << "   COD MATERIA " << "   CALIFIACION " << "   TIPO DE EXAMEN " << "  FECHA " << endl;
cout << endl << " --------------------------------------------------------------- ";
while (fread(&aux, sizeof(Examen),1,pLeer)==1){

cout << endl << " " << aux.getLegajo() << "        " << aux.getcodMateria() << "            " << aux.getCalificacion() << "               " << aux.getTipoExamen() << "               " << aux.getDia() << "/" <<aux.getMes() << "/" <<aux.getAnio()  <<endl;

}
cout << endl << " --------------------------------------------------------------- ";

fclose(pLeer);

}


int buscarParcial(int leg, int mat){
Examen aux;
FILE *pParcial = fopen("Examenes.dat", "rb");
if (pParcial==NULL){cout << "Error al leer";}

char comp='p';
char comp2;
int maxNota=0;
while (fread(&aux, sizeof(Examen),1,pParcial)==1){
     if(aux.getLegajo()==leg && aux.getcodMateria()==mat){
                comp2 = aux.getTipoExamen();
                if (comp==comp2){
                    if(aux.getCalificacion()>maxNota)
                    {
                    maxNota=aux.getCalificacion();
                    }

                }
                else{maxNota=-1;}
            }
        }
     cout << endl;
 fclose(pParcial);
 return maxNota;///Retornar cuando finaliza el ciclo despues de cerrar archivo.






}

