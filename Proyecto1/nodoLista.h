#ifndef NODOLISTA_H
#define NODOLISTA_H

struct nodoLista{
    int valor;
    nodoLista* anterior;
    nodoLista* siguiente;

    nodoLista(int valor){
        this->valor=valor;
        this->anterior=nullptr;
        this->siguiente=nullptr;
    }
};


#endif // NODOLISTA_H
