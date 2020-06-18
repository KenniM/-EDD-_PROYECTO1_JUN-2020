#ifndef NODOAVL_H
#define NODOAVL_H
#pragma once
#include <iostream>
using namespace std;

class nodoAVL {
public:
  string ID;
  string prestador;
  string empresaPrestador;
  string deptoPrestador;
  string auxGrafico;
  string activo;
  string descripcion;
  string diasRenta;
  bool rentado;
  nodoAVL *izquierda;
  nodoAVL *derecha;
  int altura;

  nodoAVL(std::string ID,int contadorNodo,string activo,string desc){
      this->ID = ID;
      auxGrafico="Nodo"+to_string(contadorNodo);
      this->activo=activo;
      this->descripcion=desc;
      this->rentado=false;
      this->diasRenta="";
      this->prestador="";
      this->empresaPrestador="";
      this->deptoPrestador="";
      izquierda = nullptr;
      derecha = nullptr;
      altura = 1;
  }
};
#endif // NODOAVL_H
