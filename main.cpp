#include <iostream>
#include <clocale>
#include "helpers.h"
#include "usuario.h"
#include "factura.h"

#define USUARIOS_MAXIMOS 3

#define USUARIO "ManuelG"
#define CLAVE "manuelgarcia10"
#define PUESTO "Supervisor"

#define USUARIO2 "Diosito"
#define CLAVE2 "jesucristo01"
#define PUESTO2 "Jefe de empresa"

#define USUARIO3 "AntonioH"
#define CLAVE3 "antoniohuerta32"
#define PUESTO3 "Empleado"

using namespace std;

typedef enum {CREAR=1, MOSTRAR, ENVIAR, ELIMINAR, CERRAR_SESION} opcionesMenuPrincipal;
Usuario *usuarios[USUARIOS_MAXIMOS];
int indiceUsuarioAccedido;

int menuFacturas();
void salirDeMenu();
void inicializar();
void menuInicial();
void iniciarSesion();
void cerrarSesion();
void validarUsuarioOpcionCrear();
void validarUsuarioOpcionMostrar();
void validarUsuarioOpcionEnviar();
void validarUsuarioOpcionEliminar();

int main()
{
    int opcion;
    setlocale(LC_ALL ,"");
    inicializar();
    menuInicial();
    if(indiceUsuarioAccedido>=C_0){
        do{
            system(CLEAR);
            opcion=menuFacturas();
            system(CLEAR);
            switch(opcion){
                case CREAR:         validarUsuarioOpcionCrear();    break;
                case MOSTRAR:       validarUsuarioOpcionMostrar();  break;
                case ENVIAR:        validarUsuarioOpcionEnviar();   break;
                case ELIMINAR:      validarUsuarioOpcionEliminar(); break;
                case CERRAR_SESION: cerrarSesion();                 break;
                default:            cout << "Opción no valida" << endl;
            }
            if(opcion!=CERRAR_SESION){
                pausa();
            }
        }while(indiceUsuarioAccedido>=C_0);
    }
    cout << "Cerrando Programa..." << endl;
    return 0;
}

int menuFacturas(){
    int opcion;
    cout << "1) Crear factura" << endl;
    cout << "2) Mostrar factura" << endl;
    cout << "3) Enviar factura" << endl;
    cout << "4) Eliminar factura" << endl;
    cout << "5) Cerrar del sistema" << endl;
    cout << "-> ";
    cin >> opcion;
    return opcion;
}

void menuInicial(){
    int opcion;
    cout << "1)Iniciar sesion" << endl;
    cout << "Otro) Salir" << endl;
    cout << "-> ";
    cin  >> opcion;
    system(CLEAR);
    if(opcion==C_1){
        cin.ignore();
        iniciarSesion();
    }else{
        indiceUsuarioAccedido=-1;
    }

}

void salirDeMenu(){
    cout << "Cerrando programa" << endl;
}

void inicializar(){
    usuarios[C_0]=new Usuario((char*)USUARIO, (char*)CLAVE, (char*)PUESTO, C_0);
    usuarios[C_1]=new Usuario((char*)USUARIO2, (char*)CLAVE2, (char*)PUESTO2, C_0);
    usuarios[C_2]=new Usuario((char*)USUARIO3, (char*)CLAVE3, (char*)PUESTO3, C_0);

}

void iniciarSesion(){
    char usuario[TAMANIO_NOMBRE_USUARIO+1], clave[TAMANIO_CLAVE_USUARIO+1];
    int cantidadIntentos;
    bool accesoConcedido;
    cantidadIntentos=3;
    do{
        accesoConcedido=false;
        cout << "Usuario: ";
        cin.getline(usuario, TAMANIO_NOMBRE_USUARIO+1);
        cout << "Contraseña: ";
        cin.getline(clave, TAMANIO_CLAVE_USUARIO+1);
        for(int i=0; i<USUARIOS_MAXIMOS && !accesoConcedido; i++){
            if(!strcmpi(usuario, usuarios[i]->getNombre())
               && !strcmpi(clave, usuarios[i]->getClave())){
                accesoConcedido=true;
                indiceUsuarioAccedido=i;
            }else{
                accesoConcedido=false;
            }
        }
        if(accesoConcedido){
            cout << "Acceso concedido, bienvenido" << endl;
            pausaDespuesDeGetline();
            system(CLEAR);
        }else{
            cout << "Error, usuario y/o contraseña no validos" << endl;
            cout << "Intentos restantes " << cantidadIntentos-1 << endl;
            pausaDespuesDeGetline();
            system(CLEAR);
            cantidadIntentos--;
            if(cantidadIntentos==C_0){
                cout << "Limite de intentos alcanzado, inicio de sesión bloqueado\n";
                indiceUsuarioAccedido=-1;
            }
        }
    }while(!accesoConcedido && cantidadIntentos!=C_0);
}

void cerrarSesion(){
    cout << "Cerrando sesion de " << usuarios[indiceUsuarioAccedido]->getNombre() << endl;
    pausa();
    system(CLEAR);
    indiceUsuarioAccedido=-1;
    menuInicial();
}

void validarUsuarioOpcionCrear(){
    if(indiceUsuarioAccedido!=C_0){
        crearFactura();
    }else{
        cout << "Su tipo de usuario no tiene permitido usar esta opción" << endl;
    }
}

void validarUsuarioOpcionMostrar(){
    if(indiceUsuarioAccedido!=C_2){
        cout << "Mostrar factura" << endl;
    }else{
        cout << "Su tipo de usuario no tiene permitido usar esta opción" << endl;
    }
}

void validarUsuarioOpcionEnviar(){
    if(indiceUsuarioAccedido!=C_0){
        cout << "Enviar factura" << endl;
    }else{
        cout << "Su tipo de usuario no tiene permitido usar esta opción" << endl;
    }
}

void validarUsuarioOpcionEliminar(){
    if(indiceUsuarioAccedido!=C_2){
        cout << "Eliminar factura" << endl;
    }else{
        cout << "Su tipo de usuario no tiene permitido usar esta opción" << endl;
    }
}
