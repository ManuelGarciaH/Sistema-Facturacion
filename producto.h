#ifndef PRODUCTO_H_INCLUDED
//#include "helpers.h"
#define PRODUCTO_H_INCLUDED
#define TAMANIO_DESCRIPCION_PRODUCTO 15

#define TAMANIO_BASE_DE_DATOS_PRODUCTOS 3

class Producto{
    private:
        char descripcion[TAMANIO_DESCRIPCION_PRODUCTO+1];
        float importe;
        float precioUnitario;
        int clave;
    public:
        Producto(char* d, float i, float pU, int cl){
            setDescripcion(d);
            setImporte(i);
            setPrecioUnitario(pU);
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

        void setClave(int cl){
            this->clave=cl;
        }
        int getClave(){
            return this->clave;
        }

};

Producto *basedeDatosProductos[TAMANIO_BASE_DE_DATOS_PRODUCTOS];

void generarBaseDeDatos();
void capturarProducto(Producto& producto);


void generarBaseDeDatos(){
    char vacio[]="";
    for(int i=0; i<TAMANIO_BASE_DE_DATOS_PRODUCTOS; i++){
        basedeDatosProductos[i]=new Producto(vacio, 0.0, 0.0, 0);
    }
    basedeDatosProductos[0]->setDescripcion("Chaqueta");
    basedeDatosProductos[0]->setImporte(10.00);
    basedeDatosProductos[0]->setPrecioUnitario(5.00);
    basedeDatosProductos[0]->setClave(1);

    basedeDatosProductos[1]->setDescripcion("Camiseta");
    basedeDatosProductos[1]->setImporte(15.00);
    basedeDatosProductos[1]->setPrecioUnitario(7.00);
    basedeDatosProductos[1]->setClave(2);

    basedeDatosProductos[2]->setDescripcion("Pantalon");
    basedeDatosProductos[2]->setImporte(8.00);
    basedeDatosProductos[2]->setPrecioUnitario(4.00);
    basedeDatosProductos[2]->setClave(3);
}

void imprimirBaseDeDatos(){
    cout << "\t\t\t***BASE DE DATOS***" << endl;
    cout << "|---------------------------------------------------------------|" << endl;
    cout << "|Clave\t|Descripcion\t\t|Importe\t|Precio unitario|" << endl;
    cout << "|---------------------------------------------------------------|" << endl;
    for(int i=0; i<TAMANIO_BASE_DE_DATOS_PRODUCTOS; i++){
        cout << "|" << basedeDatosProductos[i]->getClave() << "\t|";
        cout << basedeDatosProductos[i]->getDescripcion();
        espacios(strlen(basedeDatosProductos[i]->getDescripcion()), TAMANIO_DESCRIPCION_PRODUCTO+4);
        cout << basedeDatosProductos[i]->getImporte() << "\t\t|";
        cout << basedeDatosProductos[i]->getPrecioUnitario() << "\t\t|" << endl;
        cout << "|---------------------------------------------------------------|" << endl;
    }
}

void capturarProducto(Producto& producto){
    int opcion;
    do{
        system(CLEAR);
        imprimirBaseDeDatos();
        cout << "Ingresa la clave del producto deseado" << endl << "-> ";
        cin >> opcion;
        opcion--;
        if(opcion >= 0 && opcion <= 2){
            producto.setClave(basedeDatosProductos[opcion]->getClave());
            producto.setDescripcion(basedeDatosProductos[opcion]->getDescripcion());
            producto.setImporte(basedeDatosProductos[opcion]->getImporte());
            producto.setPrecioUnitario(basedeDatosProductos[opcion]->getPrecioUnitario());
            cout << "Producto guardado" << endl;
            pausa();
        }else{
            cout << "Opción no valida" << endl;
            pausa();
        }
    }while(opcion < 0 || opcion > 2);
    //return producto;
}

void imprimirProducto(Producto& producto){
    cout << "|---------------------------------------------------------------|" << endl;
    cout << "|Clave\t|Descripcion\t\t|Importe\t|Precio unitario|" << endl;
    cout << "|---------------------------------------------------------------|" << endl;
    for(int i=0; i<TAMANIO_BASE_DE_DATOS_PRODUCTOS; i++){
        cout << "|" << producto.getClave() << "\t|";
        cout << producto.getDescripcion();
        espacios(strlen(producto.getDescripcion()), TAMANIO_DESCRIPCION_PRODUCTO+4);
        cout << producto.getImporte() << "\t\t|";
        cout << producto.getPrecioUnitario() << "\t\t|" << endl;
        cout << "|---------------------------------------------------------------|" << endl;
    }
}

#endif // PRODUCTO_H_INCLUDED
