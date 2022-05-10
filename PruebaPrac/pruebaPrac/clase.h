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

        bool leerDeDisco(int);
        bool grabarEnDisco();
        void cargar();
        void mostrar();


};


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

    class Fecha{
    private:
        int dia, mes, anio;
    public:
        //gets()
        //sets()
        void Cargar();
        void Mostrar();
};




    class Museo{
    private:
        int _numero;
        int _especialidad, _anio;
        char _nombre[45];
        int _dniDirector;
        bool _estado;
    public:
        //gets()

        //sets()
        bool leerDeDisco(int);
        bool grabarEnDisco();
        void Cargar();
        void Mostrar();
};

class Contrato{
    private:
        int _dniEmpleado;
        int _numeroMuseo;
        int _tipoContrato;
        Fecha fecha_contrato;
        bool _estado;
    public:
        //gets()
        //sets()
        bool leerDeDisco(int);
        bool grabarEnDisco();
        void Cargar();
        void Mostrar();
};



#endif // CLASE_H_INCLUDED
