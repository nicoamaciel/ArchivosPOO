# include<iostream>
# include<cstdlib>
# include<cstring>

using namespace std;

class Fecha{
private:///Solo es accesible desde dentro de la clase
    int dia, mes, anio; ///Propiedades de la clase ENCAPSULAMIENTO


public:///Accesible dentro y fuera de la clase
    Fecha(int d=0, int m=0, int a=0){///Constructor x valores por omision
        dia=d;
        mes=m;
        anio=a;
    }

    void Mostrar();
    void Cargar();

    //Gets
    int getDia(){return dia;} //Realizar Get y Set con todas la propiedades siempre
    int getMes(){return mes;}
    int getAnio(){return anio;}
    //Sets
    void setDia(int d){dia=d;} //Set --> para realizar validaciones
    void setMes(int m){
        if (m>=1 && m<=12){
        mes=m;
        }
    }
    void setAnio(int a){anio=a;}


    ~Fecha(){}; ///Destructor -->> En memoria dinamica devuelve dicha memoria

};

void Fecha::Mostrar(){
    //cout <<this<<endl;
    cout << this->dia << "/" << this->mes << "/" << this->anio << endl;
}

void Fecha::Cargar(){
    int d;

    cout << "DIA: ";
    cin >> d;
    setDia(d);
    cout << "MES: ";
    cin >> d;
    setMes(d);
    cout << "ANIO: ";
    cin >> d;
    setAnio(d);
}

//FinClaseFEcha

class Alumno{
private:
    int legajo;
    char nombre[25], apellido[25];
    char email[25];
    int codigoCarrera;
    Fecha fechaNacimiento;
    public:
        void Cargar();
        void Mostrar();

};


void Alumno::Cargar(){
    cout << "Legajo: ";
    cin >> legajo;
    cout << "Nombre: ";
    cin >> nombre;
    cout << "Apellido: ";
    cin >> apellido;
    cout << "Email: ";
    cin >> email;
    cout << "Codigo de carrera: ";
    cin >> codigoCarrera;
    fechaNacimiento.Cargar(); //Cargar de claseFecha
}

    void Alumno::Mostrar(){
    cout << "Legajo: ";
    cout <<  legajo<<endl;
    cout << "Nombre: ";
    cout << nombre<<endl;
    cout << "Apellido: ";
    cout << apellido<<endl;
    cout << "Email: ";
    cout << email<<endl;
    cout << "Codigo de carrera: ";
    cout << codigoCarrera<< endl;
    fechaNacimiento.Mostrar(); ///Mostrar de claseFecha
    }
///PROTOTIPOS
int grabarRegistro(Alumno aux);
void leerRegistro();
///


int main(){
    Alumno alu;
    int opc;

    while(true){
        system("cls");
        cout << "-----MENU ALUMNOS-----"<<endl;
        cout << "1. AGREGAR REGISTRO"<<endl;
        cout << "2. MOSTRAR REGISTRO"<<endl;
        cout << "0. FIN DEL PROGRAMA"<<endl;
        cout << "OPCION: "<<endl;
        cin >>opc;
        system("cls");
        switch(opc){
            case 1: alu.Cargar();
                    if(grabarRegistro(alu)==1) cout<<"REGISTRO AGREGADO";
                    else cout << "NO SE PUDO AGREGAR EL REGISTRO";
                    break;
            case 2: leerRegistro();
                    break;
            case 0: return 0;
                    break;
        }
        cout<<endl;
        system("pause");
    /*alu.Cargar();
    alu.Mostrar();
    grabarRegistro(alu);//recibe objeto alumnos cargardos - mandamos datos a guarbar
    leerRegistro();*/

    //cout << sizeof(Alumno) << endl;  //Tamaño de variable o tipo de dato ->> en bytes
    //cout << sizeof alu;
    }


    cout << endl;
    return 0;
}

int grabarRegistro(Alumno aux){
    FILE *pAlu; //p de puntero
    pAlu=fopen("nicolas.ganoBoca", "ab");
    if(pAlu==NULL){///si la apertura no pudo hacerse el valor que devuelve es null
        cout << "ERROR DE ARCHIVO"<<endl;
        system("PAUSE");
        return -1;
    }


    int escribio=fwrite(&aux, sizeof aux, 1, pAlu);//Necesitamos direccion de aux y tamaño sizeof
    fclose(pAlu); //Cerrar el puntero pAlu
    return escribio;
}
void leerRegistro(){
    FILE *pAlu;
    Alumno aux;
    pAlu=fopen("nicolas.ganoBoca", "rb");
    if(pAlu==NULL){///si la apertura no pudo hacerse el valor que devuelve es null
        cout << "ERROR DE ARCHIVO"<<endl;
        system("PAUSE");
        return;
    }
    /*fread(&aux,sizeof aux, 1, pAlu); //Lee desde pAlu y multiplica por el tamño de aux
    aux.Mostrar();
    cout << endl;
    fread(&aux,sizeof aux, 1, pAlu);
    aux.Mostrar();*/

    while(fread(&aux,sizeof aux, 1, pAlu)==1){//lista todo el archivo sabiendo lo que devuelve fread
        aux.Mostrar();
        cout << endl;
    }


    fclose(pAlu); //Cerrar el puntero pAlu


}
