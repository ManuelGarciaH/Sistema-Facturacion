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
void imprimirDomicilioEmisorReceptor(Domicilio &dE, Domicilio &dR);

Domicilio* capturarDomicilio(){
    char colonia[TAMANIO_COLONIA+1], calle[TAMANIO_CALLE+1], ciudad[TAMANIO_CIUDAD+1];
    char estado[TAMANIO_ESTADO+1], pais[TAMANIO_PAIS+1];
    int numero, codigoPostal;

    cout << "Pa�s: ";
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

void imprimirDomicilioEmisorReceptor(Domicilio &dE, Domicilio &dR){
    int tamanioColumna=39;
    char cadena[10];
    cout << "\n|---------------------------------------------------------------------------------------|"<<endl;
    cout << "|PA�S   |" << dE.getPais();
    espacios(strlen(dE.getPais()), tamanioColumna);
    cout << dR.getPais();
    espacios(strlen(dR.getPais()), tamanioColumna);

    cout << "\n|---------------------------------------------------------------------------------------|"<<endl;
    cout << "|ESTADO |" << dE.getEstado();
    espacios(strlen(dE.getEstado()), tamanioColumna);
    cout << dR.getEstado();
    espacios(strlen(dR.getEstado()), tamanioColumna);

    cout << "\n|---------------------------------------------------------------------------------------|"<<endl;
    cout << "|CIUDAD |" << dE.getCiudad();
    espacios(strlen(dE.getCiudad()), tamanioColumna);
    cout << dR.getCiudad();
    espacios(strlen(dR.getCiudad()), tamanioColumna);

    cout << "\n|---------------------------------------------------------------------------------------|"<<endl;
    cout << "|COLONIA|" << dE.getColonia();
    espacios(strlen(dE.getColonia()), tamanioColumna);
    cout << dR.getColonia();
    espacios(strlen(dR.getColonia()), tamanioColumna);

    cout << "\n|---------------------------------------------------------------------------------------|"<<endl;
    cout << "|CALLE  |" << dE.getCalle();
    espacios(strlen(dE.getCalle()), tamanioColumna);
    cout << dR.getCalle();
    espacios(strlen(dR.getCalle()), tamanioColumna);

    cout << "\n|---------------------------------------------------------------------------------------|"<<endl;
    cout << "|NUMERO |" << dE.getNumero();
    espacios(strlen(convertirEnteroACadena(dE.getNumero(), cadena)), tamanioColumna);
    cout << dR.getNumero();
    espacios(strlen(convertirEnteroACadena(dR.getNumero(), cadena)), tamanioColumna);

    cout << "\n|---------------------------------------------------------------------------------------|"<<endl;
    cout << "|CP     |" << dE.getCodigoPostal();
    espacios(strlen(convertirEnteroACadena(dE.getCodigoPostal(), cadena)), tamanioColumna);
    cout << dR.getCodigoPostal();
    espacios(strlen(convertirEnteroACadena(dR.getCodigoPostal(), cadena)), tamanioColumna);
}
#endif // DOMICILIO_H_INCLUDED
