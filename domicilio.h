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


#endif // DOMICILIO_H_INCLUDED
