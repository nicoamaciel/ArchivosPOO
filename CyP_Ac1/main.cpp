#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

#include "cyp.h"

/*
1 - Agregar una función global que busque un registro de país a partir de su código.
La función debe poder devolver si el registro existe o no.

2 - Agregar una función global que permita agregar un registro de País al archivo de países.

3 - Agregar una función global que permita listar todos los países del archivo de países.

4 - Agregar una función global que permita listar todos las ciudades y su población que pertenezcan
a un país cuyo código se ingresa previamente por teclado.
Mostrar la capital del país, si se tiene registro de ella, al final de todo.

5 - Agregar una función global que permita listar todos los países con su nombre y superficie.
 Además, indicar qué porcentaje representa esa superficie sobre el total mundial.



*/

//Prototipo1
bool buscarCodigo (char *cod);



int main()
{

    Pais obj;
    Ciudad reg;
    int opcion;
    int opcionCiudades;
    bool grabo, punto1;
    char cod[4];

    while(true){
    system("cls");
    cout << endl << "====MENU ACTIVIDAD 1====";
    cout << endl << "         1 - PUNTO 1: ";
    cout << endl << "         2 - PUNTO 2: ";
    cout << endl << "         3 - PUNTO 3: ";
    cout << endl << "         4 - PUNTO 4: ";
    cout << endl << "         5 - PUNTO 5: ";
    cout << endl << "========================";
    cout << endl << "OPCION O CERO PARA SALIR: ";
    cin >>opcion;
    system("cls");
        switch(opcion){

        case 1:

            cout << "Ingres codigo de pais a buscar: " << endl;
            cin >>cod;

            punto1 = buscarCodigo(cod);
            if(punto1==true){cout << "Existe";}
            else{ cout << "No existe";}

        break;
        case 2:
            obj.cargar();
            grabo = obj.grabarDisco(obj);
            if(grabo==1){cout << "Archivo grabado";}
            else{cout<<"error al grabar";}
        break;
        case 3:
            obj.leerDisco();
        break;
        case 4:
            system("cls");
            cout << endl << "====MENU CIUDADES====";
            cout << endl << "         1 - INGRESAR CIUDAD: ";
            cout << endl << "         2 - LISTAR CIUDADES: ";
            cout << endl << "         3 - PUNTO 3: ";
            cout << endl << "         4 - PUNTO 4: ";
            cout << endl << "         5 - PUNTO 5: ";
            cout << endl << "========================";
            cout << endl << "OPCION O CERO PARA SALIR: ";
            cin >>opcionCiudades;
            system("cls");
            switch(opcionCiudades){
                case 1:
                    reg.Cargar();
                break;
                case 2:
                    reg.Mostrar();
                break;


            }
        break;
        case 5:

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

        cout<<endl;
        system("pause");


    }

    return 0;
}




bool buscarCodigo (char *cod){
Pais aux;
const char *comp = cod;
const char *comp2;
int ret;
int pos;

FILE *pB=fopen("pais.dat","rb");
if(pB==NULL){return false;}


    while(fread(&aux,sizeof(Pais),1,pB)==1){
        comp2=aux.getCodigo();
        cout << endl;
        ret = strcmp(comp2,comp);
        if(ret==0){
            cout << "Registrado" << endl;
            return true;

        }

    }
    fclose(pB);

    /*comp2 = aux.getCodigo();
    cout << comp << endl;
    cout << comp2 << endl;
    fclose(p);
    ret = strcmp(comp,comp2);
    if(ret==0){
    return true;
    fclose(p);
    }
    else{
    return false;
    fclose(p);
    }


    }*/
}

