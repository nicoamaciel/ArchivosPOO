#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

#include "actCyP.h"

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

//Prototipo
bool buscarCodigo (char *cod); //punto
void poblacionxciudad (char *pais);
void listarSuperficie ();


int main()
{
    //Pais
    Pais obj;
    int opcion;
    int opcionCiudades;
    bool grabo, punto1;
    char cod[4];

    //Ciudad
    Ciudad reg;
    bool guardo;
    char pais[4];


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
            cout << endl << "         3 - PUNTO 4: ";
            cout << endl << "========================";
            cout << endl << "OPCION O CERO PARA SALIR: ";
            cin >>opcionCiudades;
            system("cls");
            switch(opcionCiudades){
                case 1:
                    reg.Cargar();
                    guardo = reg.grabarDisco(reg);
                    if (guardo==1){ cout << "Archivo gaurdado " << endl;}
                    else{cout << "Archivo no guardado :( "; }
                break;
                case 2:
                    reg.leerDisco();
                break;
                case 3:
                    cout << "Ingrese id de pais: " << endl;
                    cin >> pais;
                    poblacionxciudad(pais);
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


}///finFunGlobalBUSCARCODIGO

void poblacionxciudad (char *pais){
Ciudad busq;

FILE *pBusqueda = fopen("ciudad.dat", "rb");
if(pBusqueda == NULL)
{
    cout << "Error de lectura";
}
const char *idPais=pais;
bool comp;

while (fread(&busq, sizeof(Ciudad), 1, pBusqueda)==1){
            comp = strcmp(busq.getIDPais(),idPais);
            if(comp==0){
                cout << endl << "Ciudad: " << busq.getNombre();
                cout << endl << "Poblacion: " << busq.getPoblacion();
                cout << endl << " ----------------------- ";
            }

    }
}///FinFunGlobalPOBLACIONXCIUDAD



void listarSuperficie (){

Pais aux;
FILE *pCinco = fopen("pais.dat","rb");
if(pCinco == NULL){
    cout << "ERROR EN LECTURA";
}

while(fread(&aux, sizeof(Pais), 1, pCinco)==1){

}




}



