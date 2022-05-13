#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

#include "clase.h"

int main()
{
    Pais obj;
    Ciudad obj2;

    int opcion;
    while(true){
            system("cls");
            cout << "-----MENU-----" ;
            cout << endl << "1 - CARGAR PAISES: ";
            cout << endl << "2 - CARGAR CIUDADES: ";
            cout << endl << "3 - GRABAR DISCO PAISES: ";
            cout << endl << "4 - GRABAR DISCO CIUDAD: ";
            cout << endl << "5 - LEER DISCO PAISES: ";
            cout << endl << "6 - LEER DISCO CIUDAD: ";
            cout << endl << "Opcion: " << endl;
            cin >>opcion;
            system("cls");
        switch(opcion){
            case 1:
                obj.cargar();
            break;
            case 2:
                obj2.cargar();
            break;
            case 3:
                     if(obj.grabarDisco(obj)==1){
                    cout << "Archivo cargado";
                    }
                    else{
                        cout << "error";
                    }
            break;
            case 4:

            break;
            case 5:
                    obj.leerDisco();//Paises
            break;
            case 6:
                    obj2.mostrar();
            break;
            case 0: return 0;
            break;

            }

        cout << endl;
        system("pause");
    }







    return 0;
}
