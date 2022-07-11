#include "producto.h"
#include "domicilio.h"
#ifndef FACTURA_H_INCLUDED
#define FACTURA_H_INCLUDED
#define TAMANIO_NOMBRE_EMISOR 50
#define TAMANIO_NOMBRE_RECEPTOR 50
#define TAMANIO_TIPO_PERSONA_EMISOR 20
#define TAMANIO_RFC_EMISOR 25
#define TAMANIO_RFC_RECEPTOR 25
#define TAMANIO_TIPO_PERSONA_RECEPTOR 20
#define TAMANIO_HORA 10
#define TAMANIO_NUMERO_FOLIO 15
#define TAMANIO_RFC_MORAL 12
#define TAMANIO_RFC_FISCAL 13
#define PRODUCTOS_MAXIMOS 5
#define FACTURAS_MAXIMAS 20

#define TAMANIO_MORALES 25
#define TAMANIO_FISCALES 25
#define MAX_MORALES 2
#define MAX_FISCALES 5

#define C_0 0
#define C_1 1
#define C_2 2
#define C_3 3
#define C_4 4
#define C_5 5



class Factura{
    private:
        char nombreEmisor[TAMANIO_NOMBRE_EMISOR+1];
        char RFCEmisor[TAMANIO_RFC_EMISOR+1];
        char tipoPersonaEmisor[TAMANIO_TIPO_PERSONA_EMISOR+1];
        char nombreReceptor[TAMANIO_NOMBRE_RECEPTOR+1];
        char RFCReceptor[TAMANIO_RFC_RECEPTOR+1];
        char tipoPersonaReceptor[TAMANIO_TIPO_PERSONA_RECEPTOR+1];
        char hora[TAMANIO_HORA+1];
        char numeroFolio[TAMANIO_HORA+1];
        float subTotal;
        float total;
        float IVATotal;
        Producto *productos[PRODUCTOS_MAXIMOS];
        int cantidadProductos;
        Domicilio *domicilioEmisor, *domicilioReceptor;
    public:
        Factura(char* nE, char* rE, char* tPE, char* nR, char* rR, char* tPR,
                char* h, char* nF, float sT, float t, float iT){
            setNombreEmisor(nE);
            setRFCEmisor(rE);
            setTipoPersonaEmisor(tPE);
            setNombreReceptor(nR);
            setRFCReceptor(rR);
            setTipoPersonaReceptor(tPR);
            setHora(h);
            setNumeroFolio(nF);
            setSubTotal(sT);
            setTotal(t);
            setIVATotal(iT);
            cantidadProductos=0;
        }

        void setNombreEmisor(char* nE){
            strcpy(this->nombreEmisor, nE);
        }
        char* getNombreEmisor(){
            return this->nombreEmisor;
        }

        void setRFCEmisor(char* rE){
            strcpy(this->RFCEmisor, rE);
        }
        char* getRFCEmisor(){
            return this->RFCEmisor;
        }

        void setTipoPersonaEmisor(char* tPE){
            strcpy(this->tipoPersonaEmisor, tPE);
        }
        char* getEmisorFiscal(){
            return this->tipoPersonaEmisor;
        }

        void setNombreReceptor(char* nR){
            strcpy(this->nombreReceptor, nR);
        }
        char* getNombreRecptor(){
            return this->nombreReceptor;
        }

        void setRFCReceptor(char* rR){
            strcpy(this->RFCReceptor, rR);
        }
        char* getRFCReceptor(){
            return this->RFCReceptor;
        }

        void setTipoPersonaReceptor(char* tPR){
            strcpy(this->tipoPersonaReceptor, tPR);
        }
        char* getTipoPersonaReceptor(){
            return this->tipoPersonaReceptor;
        }

        void setHora(char* h){
            strcpy(this->hora, h);
        }
        char* getHora(){
            return this->hora;
        }

        void setNumeroFolio(char* nF){
            strcpy(this->numeroFolio, nF);
        }
        char* getNumeroFolio(){
            return this->numeroFolio;
        }

        void setSubTotal(float sT){
            subTotal=sT;
        }
        float getSubTotal(){
            return subTotal;
        }

        void setTotal(float t){
            total=t;
        }
        float getTotal(){
            return total;
        }

        void setIVATotal(float iT){
            IVATotal=iT;
        }
        float getIVATotal(){
            return IVATotal;
        }

        void setProducto(Producto* producto){
            productos[cantidadProductos]=producto;
            aumentarCantidadProductos();
        }

        void getProducto(int indice){
            imprimirProducto(*productos[indice]);
        }


        void aumentarCantidadProductos(){
            cantidadProductos++;
        }
        int getCantidadProductos(){
            return cantidadProductos;
        }

        void setDomicilioEmisor(Domicilio* dE){
            domicilioEmisor=dE;
        }

        void setDomicilioReceptor(Domicilio* dR){
            domicilioReceptor=dR;
        }

        void getDomicilioEmisor(){
            imprimirDomicilioEmisor(*domicilioEmisor);
        }
        void getDomicilioReceptor(){
            imprimirDomicilioReceptor(*domicilioReceptor);
        }
};

int cantidadFacturas=0;
Factura *facturas[FACTURAS_MAXIMAS];

char morales[TAMANIO_MORALES][MAX_MORALES];
char fiscales[TAMANIO_FISCALES][MAX_FISCALES];

void crearFactura();
void inicializarArreglosMoralesFiscales();
void registrarDatosEmisor();
void registrarDatosReceptor();
void registrarDatosAdicionales();
int validarRFC(int longitud);
void escogerMoralOFiscal(int tipoPersona, bool guardarEmisor);
void registrarProducto();
void registrarDomicilioEmisor();
void registrarDomicilioReceptor();

void crearFactura(){
    char vacio[]="";
    inicializarArreglosMoralesFiscales();
    facturas[cantidadFacturas]=new Factura(vacio, vacio, vacio, vacio, vacio,
                                           vacio, vacio, vacio, 0.0, 0.0, 0.0);
    cin.get();
    registrarDatosEmisor();
    cin.get();
    registrarDomicilioEmisor();

    registrarDatosReceptor();
    cin.get();
    registrarDomicilioReceptor();

    registrarProducto();


    cantidadFacturas++;

}

void inicializarArreglosMoralesFiscales(){
    strcpy(morales[C_0], "Regimen General");
    strcpy(morales[C_1], "Sin Fines de Lucro");
    strcpy(fiscales[C_0], "Asalariados");
    strcpy(fiscales[C_1], "Honorarios");
    strcpy(fiscales[C_2], "Arrendamientos de Inmuebles");
    strcpy(fiscales[C_3], "Actividades Empresariales");
    strcpy(fiscales[C_4], "Incorporacion Fiscal");
}

void registrarDatosEmisor(){
    char nombreEmisor[TAMANIO_NOMBRE_EMISOR+1], RFCEmisor[TAMANIO_RFC_EMISOR+1];
    int tipoPersona;
    cout << "***DATOS DEL EMISOR***" << endl;
    cout << "Nombre: ";
    cin.getline(nombreEmisor, TAMANIO_NOMBRE_EMISOR+1);
    do{
        cout << "RFC: ";
        cin.getline(RFCEmisor, TAMANIO_RFC_EMISOR+1);
        tipoPersona=validarRFC(strlen(RFCEmisor));
    }while(!tipoPersona);
    escogerMoralOFiscal(tipoPersona, true);
    facturas[cantidadFacturas]->setNombreEmisor(nombreEmisor);
    facturas[cantidadFacturas]->setRFCEmisor(RFCEmisor);

}

int validarRFC(int longitud){
    int tipoPersona;
    if(longitud==TAMANIO_RFC_MORAL){
        tipoPersona=1;
    }else if(longitud==TAMANIO_RFC_FISCAL){
        tipoPersona=2;
    }else{
        cout << "RFC no valido" << endl;
        pausaDespuesDeGetline();
        tipoPersona=0;
    }
    return tipoPersona;
}

void escogerMoralOFiscal(int tipoPersona, bool guardarEmisor){
    int opcion;
    if(tipoPersona==C_1){
        do{
            cout << "***PERSONAS MORALES***" << endl;
            cout << "¿Que tipo se personas morales es?" << endl;
            cout << "1)Régimen General" << endl;
            cout << "2)Sin Fines De Lucro" << endl;
            cout << "-> ";
            cin >> opcion;
            if(opcion!=C_1 && opcion!=C_2){
                cout << "Opción no valida" << endl;
            }
        }while(opcion!=C_1 && opcion!=C_2);
        if(guardarEmisor){
            facturas[cantidadFacturas]->setTipoPersonaEmisor(morales[opcion-1]);
        }else{
            facturas[cantidadFacturas]->setTipoPersonaReceptor(morales[opcion-1]);
        }
    }else{
        do{
            cout << "***PERSONAS FISCALES***" << endl;
            cout << "¿Que tipo se personas fiscales es?" << endl;
            cout << "1)Persona Asalariada" << endl;
            cout << "2)Honorarios" << endl;
            cout << "3)Arrendamiento de Inmuebles" << endl;
            cout << "4)Incorporación Fiscal" << endl;
            cout << "5)Actividades Empresariales" << endl;
            cout << "-> ";
            cin >> opcion;
            if(opcion<C_1 || opcion>C_5){
                cout << "Opción no valida" << endl;
            }
        }while(opcion<C_1 || opcion>C_5);
        if(guardarEmisor){
            facturas[cantidadFacturas]->setTipoPersonaEmisor(fiscales[opcion-1]);
        }else{
            facturas[cantidadFacturas]->setTipoPersonaReceptor(fiscales[opcion-1]);
        }
    }
}

void registrarDatosReceptor(){
    char nombreReceptor[TAMANIO_NOMBRE_RECEPTOR+1], RFCReceptor[TAMANIO_RFC_RECEPTOR+1];
    int tipoPersona;
    cout << "***DATOS DEL RECEPTOR***" << endl;
    cout << "Nombre: ";
    cin.getline(nombreReceptor, TAMANIO_NOMBRE_RECEPTOR+1);
    do{
        cout << "RFC: ";
        cin.getline(RFCReceptor, TAMANIO_RFC_RECEPTOR+1);
        tipoPersona=validarRFC(strlen(RFCReceptor));
    }while(!tipoPersona);
    escogerMoralOFiscal(tipoPersona, false);
    facturas[cantidadFacturas]->setNombreReceptor(nombreReceptor);
    facturas[cantidadFacturas]->setRFCReceptor(RFCReceptor);
}

void registrarProducto(){
    int opcion;
    do{
        facturas[cantidadFacturas]->setProducto(capturarProducto());
        cout << "quieres capturar otro producto? 1)Si  Otro numero)No \n-> ";
        cin >> opcion;
        if(facturas[cantidadFacturas]->getCantidadProductos()==3){
            cout << "Limite de productos alcanzados" << endl;
        }
        system(CLEAR);
    }while(opcion==C_1 && facturas[cantidadFacturas]->getCantidadProductos()!=3);
    //facturas[cantidadFacturas]->getProducto(0);
    //facturas[cantidadFacturas]->getProducto(1);
}

void registrarDomicilioEmisor(){
    int opcion;
    facturas[cantidadFacturas]->setDomicilioEmisor(capturarDomicilio());
    //facturas[cantidadFacturas]->getDomicilioEmisor();
    pausa();
}
void registrarDomicilioReceptor(){
    int opcion;
    facturas[cantidadFacturas]->setDomicilioReceptor(capturarDomicilio());
    //facturas[cantidadFacturas]->getDomicilioReceptor();
    pausa();
}

#endif // FACTURA_H_INCLUDED
