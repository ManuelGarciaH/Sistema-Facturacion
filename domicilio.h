#ifndef DOMICILIO_H_INCLUDED
#define DOMICILIO_H_INCLUDED
#define TAMANIO_COLONIA 30
#define TAMANIO_CALLE 30
#define TAMANIO_CIUDAD 30
#define TAMANIO_ESTADO 30
#define TAMANIO_PAIS 30

class Domicilio{
    private:
        char colonia[TAMANIO_COLONIA+1];
        char calle[TAMANIO_CALLE+1];
        char ciudad[TAMANIO_CIUDAD+1];
        char estado[TAMANIO_ESTADO+1];
        char pais[TAMANIO_PAIS+1];
        int numero;
        int codigoPostal;
    public:
        Domicilio(char* c, char* ca, char* ci, char* e, char* p, int n, int cP){
            setColonia(c);
            setCalle(ca);
            setCiudad(ci);
            setEstado(e);
            setPais(p);
            setNumero(n);
            setCodigoPostal(cP);
        }

        void setColonia(char* c){
            strcpy(this->colonia, c);
        }
        char* getColonia(){
            return this->colonia;
        }

        void setCalle(char* ca){
            strcpy(this->calle, ca);
        }
        char* getCalle(){
            return this->calle;
        }

        void setCiudad(char* ci){
            strcpy(this->ciudad, ci);
        }
        char* getCiudad(){
            return this->ciudad;
        }

        void setEstado(char* e){
            strcpy(this->estado, e);
        }
        char* getEstado(){
            return this->estado;
        }

        void setPais(char* p){
            strcpy(this->pais, p);
        }
        char* getPais(){
            return this->pais;
        }

        void setNumero(int n){
            this->numero=n;
        }
        int getNumero(){
            return this->numero;
        }

        void setCodigoPostal(int cP){
            this->codigoPostal=cP;
        }
        int getCodigoPostal(){
            return this->codigoPostal;
        }

};

Domicilio* capturarDomicilio();
void imprimirDomicilioEmisor(Domicilio &domicilioEmisor);
void imprimirDomicilioReceptor(Domicilio &domicilioReceptor);

Domicilio* capturarDomicilio(){
    char colonia[TAMANIO_COLONIA+1], calle[TAMANIO_CALLE+1], ciudad[TAMANIO_CIUDAD+1];
    char estado[TAMANIO_ESTADO+1], pais[TAMANIO_PAIS+1];
    int numero, codigoPostal;

    cout << "País: ";
    cin.getline(pais, TAMANIO_PAIS+1);
    cout << "Estado: ";
    cin.getline(estado, TAMANIO_ESTADO+1);
    cout << "Ciudad: ";
    cin.getline(ciudad, TAMANIO_CIUDAD+1);
    cout << "Colonia: ";
    cin.getline(colonia, TAMANIO_COLONIA+1);
    cout << "Calle: ";
    cin.getline(calle, TAMANIO_CALLE+1);
    cout << "Numero: ";
    cin >> numero;
    cout << "Codigo postal: ";
    cin >> codigoPostal;

    return new Domicilio(colonia, calle, ciudad, estado, pais, numero, codigoPostal);
}

void imprimirDomicilioEmisor(Domicilio &domicilioEmisor){
    cout << domicilioEmisor.getPais() << endl;
    cout << domicilioEmisor.getEstado() << endl;
    cout << domicilioEmisor.getCiudad() << endl;
    cout << domicilioEmisor.getColonia() << endl;
    cout << domicilioEmisor.getCalle() << endl;
    cout << domicilioEmisor.getNumero() << endl;
    cout << domicilioEmisor.getCodigoPostal() << endl;
}

void imprimirDomicilioReceptor(Domicilio &domicilioReceptor){
    cout << domicilioReceptor.getPais() << endl;
    cout << domicilioReceptor.getEstado() << endl;
    cout << domicilioReceptor.getCiudad() << endl;
    cout << domicilioReceptor.getColonia() << endl;
    cout << domicilioReceptor.getCalle() << endl;
    cout << domicilioReceptor.getNumero() << endl;
    cout << domicilioReceptor.getCodigoPostal() << endl;
}

#endif // DOMICILIO_H_INCLUDED
