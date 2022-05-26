/***
Ejercicio 3
- Hacer un método a la clase Examen llamada GuardarEnDisco que grabe el
registro que contiene un archivo llamado "examenes.dat". El registro debe
añadirse al final del archivo (modo de apertura append).

- Hacer una función global llamada ListarExamenes que liste todos los
registros del archivo "examenes.dat".

- Hacer una función global llamada BuscarMejorNota que reciba una materia y
un legajo y devuelva la mejora nota que obtuvo ese estudiante en un examen
parcial de dicha materia. Si el estudiante no registra exámenes parciales para esa materia debe devolver -1.

***/



#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;
#include "claseExamen.h"




int main(){
    int opcion;
    Examen aux;
    bool ver;

    while(true){
    system("cls");
    cout << endl << "====MENU ACTIVIDAD EXAMEN====";
    cout << endl << "         1 - GRABAR DISCO: ";
    cout << endl << "         2 - LEER DISCO: ";
    cout << endl << "         3 - PUNTO 3: ";
    cout << endl << "         4 - PUNTO 4: ";
    cout << endl << "         5 - PUNTO 5: ";
    cout << endl << "========================";
    cout << endl << "OPCION O CERO PARA SALIR: ";
    cin >>opcion;
    system("cls");
        switch(opcion){

        case 1:
            aux.cargar();
            ver = aux.guardarArchivo(aux);
            system("pause");
        break;
        case 2:

            aux.listarRegistros();
            system("pause");
        break;
        case 3:
           system("cls");
        break;
        case 4:
          system("cls");
        break;
        case 5:
          system("cls");


        break;

        case 0:
            if(opcion==0){
                char realmente;
                cout << "Realmente desea salir: S/N: ";
                cin >> realmente;
                if(realmente=='s' || realmente=='S'){
                return 0;
                }
            }
        break;

        }



    }


return 0;
}




