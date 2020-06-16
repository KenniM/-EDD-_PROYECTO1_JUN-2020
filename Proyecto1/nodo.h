#ifndef NODO_H
#define NODO_H
#include <iostream>

class Nodo {
public:
    Nodo* siguiente, * anterior, * arriba, * abajo, * adelante, * atras;
    std::string nombre;
    std::string password;
    int numero;

    Nodo(std::string nombre_, int numero_) {
        siguiente = nullptr;
        anterior = nullptr;
        arriba = nullptr;
        abajo = nullptr;
        adelante = nullptr;
        atras = nullptr;
        nombre = nombre_;
        numero = numero_;
    }
    Nodo(std::string nombre_, std::string password_) {
        siguiente = nullptr;
        anterior = nullptr;
        arriba = nullptr;
        abajo = nullptr;
        adelante = nullptr;
        atras = nullptr;
        nombre = nombre_;
        password=password_;
    }

};


#endif // NODO_H
