#include <iostream>
#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

#include "clase.h"



int main()
{
    Empleado obj, aux;
    int opcion;
    bool retornoArchivo;


    while (true){
    system("cls");
    cout << "-------MENU------" << endl;
    cout << "1 - CARGAR" << endl;
    cout << "2 - MOSTRAR" << endl;
    cout << "3 - GRABAR ARCHIVO" << endl;
    cout << "4 - LEER ARCHIVO" << endl;
    cout << "OPCION: " << endl;
    cin >> opcion;
    system("cls");
        switch(opcion){
            case 1:
                obj.cargar();
            break;
            case 2:
                obj.mostrar();
            break;
            case 3:
                obj.grabarEnDisco(obj);

            break;
            case 4:
                obj.leerDeDisco();
            break;
            case 0: return 0;
            break;
        }
         cout<<endl;
         system("pause");


    }
    return 0;
}
///MOVER DE LAB2
