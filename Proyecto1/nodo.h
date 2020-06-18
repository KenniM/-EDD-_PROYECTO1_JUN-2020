#ifndef NODO_H
#define NODO_H
#include "AVL.h"
#include <iostream>
class Nodo {
public:
    Nodo* siguiente, * anterior, * arriba, * abajo, * adelante, * atras;
    std::string nombre;
    std::string password;
    std::string auxGrafico;
    int numero;
    nodoAVL* arbolPersonal;

    Nodo(std::string nombre_, int numero_) {
        siguiente = nullptr;
        anterior = nullptr;
        arriba = nullptr;
        abajo = nullptr;
        adelante = nullptr;
        atras = nullptr;
        arbolPersonal=nullptr;
        nombre = nombre_;
        numero = numero_;
        auxGrafico="Nodo"+nombre+nombre;
    }
    Nodo(std::string nombre_, std::string password_) {
        siguiente = nullptr;
        anterior = nullptr;
        arriba = nullptr;
        abajo = nullptr;
        adelante = nullptr;
        atras = nullptr;
        arbolPersonal=nullptr;
        nombre = nombre_;
        password=password_;
        auxGrafico="Nodo"+nombre+password;
    }

};


#endif // NODO_H
