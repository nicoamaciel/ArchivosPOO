/***
La administración provincial necesita realizar un análisis sobre los empleados de los distintos tipos de empresas.
Tiene, entre otros, el siguiente archivo en su sistema
Empresas.dat
Número de empresa (Número entero. No se repite en el archivo. Es único para cada empresa)
Nombre (char[30])
Cantidad de empleados
Categoría (1 a 80)
Número de municipio al que pertenece (1 a 135)
Estado (bool)
A partir de la información contenida en el archivo, hacer un programa para resolver los siguientes puntos
1- Calcular e informar la cantidad de empresas de cada municipio.
2- Informar los nombres de las empresas con más de 200 empleados.
3- Calcular e informar la categoría de empresa con más empleados
Diseñar la clase necesaria, y hacer un menú con opciones para la ejecución de cada punto.
Cada punto debe resolverse por separado en una función.
***/

#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;


class empleados{
private:
    int _numeroEmpresa;
    char _nombre[30];
    int _cantEmpleados;
    int _categoria;
    int _numeroMunicipio;
    bool _estado;
public:
    ///gets
        int getnumeroEmpresa(){
        return _numeroEmpresa;
        }
        const char *getnombre(){
        return _nombre;
        }

        int getcantEmpleados(){
        return _cantEmpleados;
        }

        int getcategoria(){
        return _categoria;
        }

        int getnumMunicipio(){
        return _numeroMunicipio;
        }

        bool getestado(){
        return _estado;
        }

    ///sets
        void setnumeroEmpresa( int numEmpre){
            _numeroEmpresa=numEmpre;
        }
        void setnombre( const char *nomb){
            strcpy(_nombre,nomb);
        }

        void setcantEmpleados( int cantEmpleados){
            _cantEmpleados=cantEmpleados;
        }

        void setcategoria( int catego){
            _categoria=catego;
        }

        void setnumMunicipio( int numMunicipio){
            _numeroMunicipio=numMunicipio;
        }

        void setestado(bool estado){
            _estado=estado;
        }

        void cargar();
        void mostrar();


};

    void empleados::cargar(){
    int n;
    bool estado;
    char nom[30];

    cout << "Cargar numero de empresa: ";
    cin >> n;
    setnumeroEmpresa(n);
    cout << "Cargar nombre de empresa: ";
    cin >> nom;
    setnombre(nom);
    cout << "Cargar cantidad de empleados: ";
    cin >> n;
    setcantEmpleados(n);
    cout << "Cargar categoria: ";
    cin >> n;
    setcategoria(n);
    cout << "Cargar numero de municipio: ";
    cin >> n;
    setcategoria(n);
    cout << "Cargar estado: ";
    cin >> estado;
    setestado(estado);

    }


    void empleados::mostrar(){

    cout << endl << "------------" << endl;
    cout << "Numero de empresa: " << getnumeroEmpresa() << endl;
    cout << "Nombre de empresa: "<< getnombre() << endl;
    cout << "Cantidad de empleados: "<< getcantEmpleados() << endl;
    cout << "Categoria: "<< getcategoria() << endl;
    cout << "Numero de municipio: "<< getcategoria() << endl;
    cout << "Estado: "<< getestado() << endl;

    }

    ///PROTOTIPO
    void grabarArchivo(empleados aux);
    void leerRegistro();


int main () {
    empleados obj;
    int opcion;


    system("cls");
    cout << "-------MENU-----" << endl;
    cout << "1 - Cantidad de empresas de cada municipio: " << endl;
    cout << "2 - Nombres de las empresas con mas de 200 empleados: "<< endl;
    cout << "3 - Categoria de empresa con mas empleados: "<< endl;
    cout << "----------------" << endl;
    cout << "Opcion: ";
    cin >> opcion;
    system("cls");

    switch(opcion){
        case 1:

                obj.cargar();
                obj.mostrar();
                grabarArchivo(obj);

        break;
        case 2:
        break;

    }

return 0;
}
//Fuera del Main
void grabarArchivo(empleados aux){
        FILE *pEmp;
        pEmp=fopen("Empresa.dat","wb");//Escribir
        if(pEmp==NULL){
            cout << "ERROR DE ARCHIVOS" << endl;
            system("pause");
        }
        fwrite(&aux, sizeof aux, 1, pEmp);
        fclose(pEmp);

    }

void leerRegistro(){
    FILE *pEmp;
    empleados aux;
    pEmp=fopen("Empresa.dat","rb");//Leer
        if(pEmp==NULL){
            cout << "ERROR DE ARCHIVOS" << endl;
            system("pause");
        }

        fread(&aux, sizeof aux, 1, pEmp);
        fclose(pEmp);

        aux.mostrar();
    }


