#ifndef PAIS_H
#define PAIS_H

#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

class Ciudad
{
    private:
        int _ID;
        char _nombre[35];
        char _idpais[4];
        int _poblacion;

    public:
        //Gets
        int getID(){
        return _ID;
        }
        char *getIDPais(){
        return _idpais;
        }
        char *getNombre(){
        return _nombre;
        }
        int getPoblacion(){
        return _poblacion;
        }
        //Sets

        void setID(int id){
        _ID=id;
        }
        void setIDPais(const char *idPais){
            strcpy(_idpais,idPais);
        }
        void setNombre(const char *nombre){
            strcpy(_nombre,nombre);
        }
        void setPoblacion(int poblacion){
            _poblacion = poblacion;
        }
        void cargar();
        void mostrar();
        bool grabarCiudad(Ciudad);
        bool leerCiudad();

}; //findeSets


void Ciudad::cargar(){
        int id;
        char nombre[35];
        char idpais[4];
        int poblacion;

        cout << "Ingresar ID: ";
        cin >> id;
        setID(id);
        cout << "Ingresar nombre: ";
        cin >>nombre;
        setNombre(nombre);
        cout << "Ingresar id pais: ";
        cin >> idpais;
        setIDPais(idpais);
        cout << "Ingresar poblacion: ";
        cin >> poblacion;
        setPoblacion(poblacion);
}

void Ciudad::mostrar(){

        cout << "ID: " << getID() << endl;
        cout << "Nombre: " << getNombre() << endl;
        cout << "Pais: " << getIDPais() << endl;
        cout << "Poblacion: " << getPoblacion() << endl;

}


class Pais{
    private:
        char _codigo[4];
        char _nombre[45];
        char _continente[20];
        float _superficie;
        int _poblacion;
        short _independencia;
        float _expectativaDeVida;
        int _capital;
    public:

        //Gets
        const char *getCodigo(){
        return _codigo;
        }

        const char *getNombre(){
        return _nombre;
        }
        char *getContinente(){
        return _continente;
        }
        float getSuperficie(){
        return _superficie;
        }
        int getPoblacion(){
        return _poblacion;
        }
        short getIndependencia(){
        return _independencia;
        }
        float getExpectativaDeVida(){
        return _expectativaDeVida;
        }
        int getIDCapital(){
        return _capital;
        }


        //Sets
        void setCodigo(const char *cod){
        strcpy(_codigo,cod);
        }

        void setNombre(const char *nomb){
        strcpy(_nombre,nomb);
        }
        void setContinente(const char *continente){
        strcpy(_continente,continente);
        }
        void setSuperficie(float super){
        _superficie=super;
        }
        void setPoblacion(int pobla){
        _poblacion=pobla;
        }
        void setIndependencia(short inde){
        _independencia=inde;
        }
        void setExpectativaDeVida(float expec){
        _expectativaDeVida=expec;
        }
        void setIDCapital(int capital){
        _capital=capital;
        }



        void mostrar();
        void cargar();
        bool grabarDisco(Pais);
        void leerDisco();
};


void Pais::cargar(){
    float coma;
    int entero;
    short s;

    cout << "Ingresar codigo: ";//char
    cin>>_codigo;
    cout << "Ingresar nombre: ";//char
    cin>>_nombre;
    cout << "Ingresar continente: ";//char
    cin>>_continente;
    cout << "Ingresar superficie: ";//float
    cin >>coma;
    setSuperficie(coma);
    cout << "Ingresar poblacion: ";//int
    cin>>entero;
    setPoblacion(entero);
    cout << "Ingresar independencia: ";//short
    cin>>s;
    setIndependencia(s);
    cout << "Ingresar expectativaDeVida: ";//float
    cin>>coma;
    setExpectativaDeVida(coma);
    cout << "Ingresar capital: ";//int
    cin>>entero;
    setIDCapital(entero);

}


void Pais::mostrar(){
    cout << endl << "------------------" << endl;
    cout << "Ingresar codigo: "<< getCodigo() <<endl;

    cout << "Ingresar nombre: " << getNombre() <<endl;
    cout << "Continente: "<< getContinente() <<endl;
    cout << "Superficie: "<< getSuperficie()<<endl;
    cout << "Poblacion: " << getPoblacion() <<endl;
    cout << "Independencia: " << getIndependencia() << endl;
    cout << "ExpectativaDeVida: " << getExpectativaDeVida() << endl;
    cout << "Capital: " << getIDCapital() << endl;

}

bool Pais::grabarDisco(Pais aux){
FILE *pPais=fopen("pais.dat","ab");
    if(pPais==NULL){
        return false;
    }
    bool guardo = fwrite(&aux, sizeof(Pais),1,pPais);
    fclose(pPais);
    return guardo;

}

void Pais::leerDisco(){
FILE *pPais=fopen("pais.dat","rb");
Pais aux;
    if(pPais==NULL){
     cout << "ERROR";
    }
    while(fread(&aux, sizeof(Pais),1,pPais)==1){

        aux.mostrar();
    }
    cout << endl;
    fclose(pPais);
}





#endif // PAIS_H
