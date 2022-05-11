#ifndef CLASE_H_INCLUDED
#define CLASE_H_INCLUDED

#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

class Empleado{
    private:
        int _dni;
        int _localidad; //(1 a 135)
        int _telefono;
        int _cargo; //(1 a 4)
        char _nombre[20];
        char _apellido[20];
        char _email[30];
    public:

        Empleado(int dni=0, int loca=0, int cargo=0, const char *nom="vacio", const char *ape="vacio", const char *ema="vacio"){
        _dni=dni;
        _localidad=loca;
        _cargo=cargo;
        strcpy(_nombre, nom);
        strcpy(_apellido, ape);
        strcpy(_email, ema);
        }

        //Gets
        int getDni(){
        return _dni;
        }
        int getLocalidad(){
        return _localidad;
        }
        int getTelefono(){
        return _telefono;
        }
        int getCargo(){
        return _cargo;
        }
        const char *getNombre(){
        return _nombre;
        }
        const char *getApellido(){
        return _apellido;
        }
        const char *getEmail(){
        return _email;
        }
        //Sets

        void setDni(int dni){
            _dni=dni;
        }
        void setLocalidad(int localidad){
            _localidad=localidad;
        }
        void setTelefono(int telefono){
            _telefono=telefono;
        }
        void setCargo(int cargo){
            _cargo=cargo;
        }
        void setNombre(const char *nombre){
            strcpy(_nombre, nombre);
        }
        void setApellido(const char *apellido){
            strcpy(_apellido, apellido);
        }
        void setEmail(const char *email){
            strcpy(_email, email);
        }

        void leerDeDisco();
        void grabarEnDisco(Empleado aux);
        void cargar();
        void mostrar();
        ~Empleado(){};


}; //FinDeClase Empleado


    void Empleado::cargar(){
    char nom[30];
    int n;

    cout << "-------------------" << endl;
    cout << "Cargar nombre: ";
    cin >> nom;
    setNombre(nom);
    cout << "Cargar apellido: ";
    cin >> nom;
    setApellido(nom);
    cout << "Cargar numero de dni: ";
    cin >> n;
    setDni(n);
    cout << "Cargar telefono: ";
    cin >> n;
    setTelefono(n);
    cout << "Cargar localidad (1 a 135): ";
    cin >> n;
    setLocalidad(n);
    cout << "Ingresar cargo (1 a 4): ";
    cin >> n;
    setCargo(n);
    cout << "Ingresas email: ";
    cin >> nom;
    setEmail(nom);
    }


    void Empleado::mostrar(){

    cout << "-------------------" << endl;
    cout << "Nombre: " << getNombre() << " Apellido: " << getApellido() << endl;
    cout << "Dni " << getDni() << endl;
    cout << "Telefono: " << getTelefono() << endl;
    cout << "Localidad: " << getLocalidad() << endl;
    cout << "Cargo: " << getCargo() << endl;
    cout << "Email: " << getEmail()<< endl;

    }

    void Empleado::grabarEnDisco(Empleado aux){
    FILE *pEmp;
    pEmp = fopen("Empleados.dat", "ab");//Escribir append - Apertura de un archivo binario para agregar registros (append). Si no existe lo crea.
        if (pEmp==NULL){
            cout << "ERROR DE ARCHIVOS" << endl;
            system("pause");
            //return false;
        }
        int escribio=fwrite(&aux, sizeof aux, 1, pEmp);
        fclose(pEmp);
    }




    void Empleado::leerDeDisco(){
    FILE *pEmp;
    Empleado aux;
    pEmp = fopen("Empleados.dat", "rb"); //LeerDeDisco
        if (pEmp==NULL){
            cout << "ERROR DE ARCHIVOS" << endl;
            system("pause");
            //return false;
        }

        while(fread(&aux,sizeof aux, 1, pEmp)==1){//lista todo el archivo sabiendo lo que devuelve fread
            aux.mostrar();
            }
        cout << endl;
        }





    ///COMIENZA CLASE FECHA

    class Fecha{
    private:
        int _dia, _mes, _anio;
    public:

        Fecha(int dia=0, int mes=0, int ani=0){
        _dia=dia;
        _mes=mes;
        _anio=ani;
        }



        //gets

        int getDia(){
            return _dia;
        }
        int getMes(){
            return _mes;
        }
        int getAnio(){
            return _anio;
        }
        //sets

        void setDia(int dia){
            if(dia>=1 && dia<=31){
            _dia=dia;
            }

        }
        void setMes(int mes){
            if(mes>=1 && mes<=12){
            _mes=mes;
            }

        }
        void setAnio(int anio){
            _anio=anio;
        }


        void Cargar();
        void Mostrar();

        ~Fecha(){};

}; //FinClaseFecha

void Fecha::Cargar(){
    int n;
    cout << "Dia: ";
    cin >> n;
    setDia(n);
    cout << "Mes: ";
    cin >> n;
    setMes(n);
    cout << "Anio: ";
    cin >> n;
    setAnio(n);
}
void Fecha::Mostrar(){
    cout << getDia() << "/" << getMes() << "/" << getAnio() << endl;
}


    class Museo{
    private:
        int _numero;
        int _especialidad/*1a8*/, _anio/*creacion*/;
        char _nombre[45];
        int _dniDirector;
        bool _estado;
    public:


        Museo(int num=0, int espe=0, int ani=0, const char *nom="Vacio", int dniDic=0, bool esta=false){
        _numero=num;
        _especialidad=espe;
        _anio=ani;
        strcpy(_nombre,nom);
        _dniDirector=dniDic;
        _estado=esta;
        }

        //gets
        int getNumero(){
        return _numero;
        }
        int getEspecialidad(){
        return _especialidad;
        }
        int getAnio(){
        return _anio;
        }
        const char *getNombre(){
        return _nombre;
        }
        int getDnidirector(){
        return _dniDirector;
        }
        bool getEstado(){
        return _estado;
        }

        //sets

        void setNumero(int num){
        _numero=num;
        }
        void setEspecialidad(int espe){
        _especialidad=espe;
        }
        void setAnio(int anio){
        _anio=anio;
        }
        void setNombre(const char *nom){
        strcpy(_nombre,nom);
        }
        void setDnidirector(int dniDirector){
        _dniDirector=dniDirector;
        }
        void getEstado(bool estado){
        _estado=estado;
        }

        bool leerDeDisco(int);
        bool grabarEnDisco();
        void Cargar();
        void Mostrar();

        ~Museo(){};

}; //FindeClaseMuseo

void Museo::Cargar(){
    int n;
    char nom[45];
    cout << "--------------------" << endl;
    cout << "Cargar numero de museo: ";
    cin  >>n;
    setNumero(n);
    cout << "Cargar especialidad (1 y 8): ";
    cin >>n;
    setEspecialidad(n);
    cout << "Cargar anio de creacion: ";
    cin>>n;
    setAnio(n);
    cout << "Cargar nombre :";
    cin >> nom;
    setNombre(nom);
    cout << "Ingresar DNI del Director: ";
    cin >> n;
    setDnidirector(n);
}

void Museo::Mostrar(){

    cout << "--------------------" << endl;
    cout << "Cargar numero de museo: " << getNumero() << endl;
    cout << "Cargar especialidad (1 y 8): " << getEspecialidad() << endl;
    cout << "Cargar anio de creacion: " << getAnio() <<endl;
    cout << "Cargar nombre :" << getNombre() <<endl;
    cout << "Ingresar DNI del Director: " << getDnidirector()<<endl;
}


class Contrato{
    private:
        int _dniEmpleado;
        int _numeroMuseo;
        int _tipoContrato;
        Fecha fecha_contrato;

    public:
        //gets
        int getDniempleado(){
        return _dniEmpleado;
        }
        int getNumeromuseo(){
        return _numeroMuseo;
        }
        int getTipocontrato(){
        return _tipoContrato;
        }
        Fecha getFechacontrato(){
        return fecha_contrato;
        }

        Contrato(int dniEm=0, int numMus=0, int tipo=0){
        _dniEmpleado=dniEm;
        _numeroMuseo=numMus;
        _tipoContrato=tipo;
        }

        //sets
        void setDniempleado(int dni ){
            _dniEmpleado=dni;
        }
        void setNumeromuseo(int numMuseo){
            _numeroMuseo=numMuseo;
        }
        void setTipocontrato(int tipoCon){
            _tipoContrato=tipoCon;
        }
        void setFechacontrato(Fecha fechaCont){
            fecha_contrato=fechaCont;
        }



        bool leerDeDisco(int);
        bool grabarEnDisco();
        void Cargar();
        void Mostrar();
        ~Contrato(){}
};

void Contrato::Cargar(){
int num;
Fecha fe;
cout << "Cargar DNI del empleado: ";
cin >> num;
setDniempleado(num);
cout << "Número de museo: ";
cin >> num;
setNumeromuseo(num);
cout << "Tipo de contrato (1: temporal; 2: permanente): ";
cin >> num;
setTipocontrato(num);
cout << "Fecha de contrato: ";
cout << endl;
fecha_contrato.Cargar();//CargarDeClaseFecha

}

void Contrato::Mostrar(){

cout << "DNI del empleado: " << getDniempleado()<< endl;
cout << "Número de museo: " << getNumeromuseo()<< endl;
cout << "Tipo de contrato (1: temporal; 2: permanente): " << getTipocontrato() << endl;
cout << "Fecha de contrato: ";
cout << endl;
fecha_contrato.Mostrar();//MostrarDeClaseFecha

}


#endif // CLASE_H_INCLUDED
