#ifndef PRODUCTO_H_INCLUDED
#define PRODUCTO_H_INCLUDED
#define TAMANIO_DESCRIPCION_PRODUCTO 80

class Producto{
    private:
        char descripcion[TAMANIO_DESCRIPCION_PRODUCTO+1];
        float importe;
        float precioUnitario;
        int cantidad;
        int clave;
    public:
        Producto(char* d, float i, float pU, int c, int cl){
            setDescripcion(d);
            setImporte(i);
            setPrecioUnitario(pU);
            setCantidad(c);
            setClave(cl);
        }

        void setDescripcion(char* d){
            strcpy(this->descripcion, d);
        }
        char* getDescripcion(){
            return this->descripcion;
        }

        void setImporte(float i){
            this->importe=i;
        }
        float getImporte(){
            return this->importe;
        }

        void setPrecioUnitario(float pU){
            this->precioUnitario=pU;
        }
        float getPrecioUnitario(){
            return this->precioUnitario;
        }

        void setCantidad(int c){
            this->cantidad=c;
        }
        int getCantidad(){
            return this->cantidad;
        }

        void setClave(int cl){
            this->clave=cl;
        }
        int getClave(){
            return this->clave;
        }

};


#endif // PRODUCTO_H_INCLUDED
