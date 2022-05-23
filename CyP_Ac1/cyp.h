#ifndef CYP_H_INCLUDED
#define CYP_H_INCLUDED

#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

class Pais{
    private:
        char _codigo[4];
        char _codigo2[3];
        char _nombre[45];
        char _continente[20];
        float _superficie;
        int _poblacion;
        short _independencia;
        float _expectativaDeVida;
        int _capital;
    public:

        //Gets
        char *getCodigo(){return _codigo;}
        char *getCodigo2(){return _codigo2;}
        char *getNombre(){return _nombre;}
        char *getContinente(){return _continente;}
        float getSuperficie(){return _superficie;}
        int getPoblacion(){return _poblacion;}
        short getIndependencia(){return _independencia;}
        float getExpectativaDeVida(){return _expectativaDeVida;}
        int getIDCapital(){return _capital;}

        //Sets
        void setCodigo(const char *cod){strcpy(_codigo, cod);}
        void setCodigo2(const char *cod2){strcpy(_codigo2,cod2);}
        void setNombre(const char *nom){strcpy(_nombre,nom);}
        void setContinente(const char *cont){strcpy(_continente,cont);}
        void setSuperficie(float superficie){_superficie=superficie;}
        void setPoblacion(int pobla){_poblacion=pobla;}
        void setIndependencia(short inde){_independencia=inde;}
        void setExpectativaDeVida(float expec){_expectativaDeVida=expec;}
        void setIDCapital(int cap){_capital=cap;}


        void cargar();
        void mostrar();
        bool grabarDisco(Pais aux);
        void leerDisco();
};


void Pais::cargar(){
char cha[4];
char cha1[3];
char cha2[45];
char cha3[20];
float flo;
int in;
short nuevo;

cout << endl << "Cargar codigo: ";
cin >> cha;
setCodigo(cha);
cout << endl << "Cargar codigo2 : ";
cin >> cha1;
setCodigo2(cha1);
cout << endl << "Cargar nombre: ";
cin >> cha2;
setNombre(cha1);
cout << endl << "Cargar continente: ";
cin >> cha3;
setContinente(cha3);
cout << endl << "Cargar superficie: ";
cin >> flo;
setSuperficie(flo);
cout << endl << "Cargar poblacion: ";
cin >> in;
setPoblacion(in);
cout << endl << "Cargar independencia: ";
cin >> nuevo;
setIndependencia(nuevo);
cout << endl << "Cargar expectiva de vida: ";
cin >> flo;
setExpectativaDeVida(flo);
cout << endl << "Cargar id capital: ";
cin >> in;
setIDCapital(in);
}

void Pais::mostrar(){

cout << endl << "Codigo: " << getCodigo();
cout << endl << "Codigo2: " << getCodigo2();
cout << endl << "Nombre: " << getNombre();
cout << endl << "Continente: " << getContinente();
cout << endl << "Superficie: " << getSuperficie();
cout << endl << "Poblacion: " << getPoblacion();
cout << endl << "Independencia: " << getIndependencia();
cout << endl << "Expectativa de vida: " << getExpectativaDeVida();
cout << endl << "Id capital: " << getIDCapital();
cout << endl;

}

bool Pais::grabarDisco(Pais aux){

FILE *pPais = fopen ("pais.dat","ab");
    if(pPais== NULL){
        return false;
    }
    bool escribio=fwrite(&aux, sizeof (Pais), 1, pPais);//Necesitamos direccion de aux y tamaño sizeof
        fclose(pPais); //Cerrar el puntero pAlu
        return escribio;

}

void Pais::leerDisco(){
FILE *pP = fopen ("pais.dat","rb");
Pais aux;
    if(pP == NULL){
        cout << endl << "Error en lectura";
    }

    while(fread(&aux, sizeof (Pais),1, pP)==1){
       aux.mostrar();
    }

    fclose(pP);
    cout << endl;


}






class Ciudad
{
    private:
    int _ID;
    char _nombre[35];
    char _idpais[4];
    int _poblacion;


    public:
    //gets
    int getID(){return _ID;}
    char *getIDPais(){return _idpais;}
    char *getNombre(){return _nombre;}
    int getPoblacion(){return _poblacion;}

    //sets
    void setID(int id){_ID=id;}
    void setNombre(const char *nomb){strcpy(_nombre,nomb);}
    void setIDPais(const char *idpais){strcpy(_idpais,idpais);}
    void setPoblacion(int pobla){_poblacion=pobla;}
    void Cargar();
    void Mostrar();
    bool grabarDisco();
    bool leerDisco();
};


void Ciudad::Cargar(){

int idd;
char nom[35];
char pais[4];
int pobla;


cout << "Cargar Id: ";
cin >> idd;
setID(idd);
cout << "Cargar Nombre: ";
cin >> nom;
setNombre(nom);
cout << "Cargar id pais: ";
cin >> pais;
setIDPais(pais);
cout << "Cargar poblacion: ";
cin >> pobla;
setPoblacion(pobla);

}

void Ciudad::Mostrar(){

cout << "Id: " << getID() <<endl;
cout << "Nombre: " << getNombre() <<endl;
cout << "id pais: " << getIDPais() <<endl;
cout << "Cargar poblacion: " << getPoblacion() <<endl;

}





#endif // CYP_H_INCLUDED
