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

//int maximo(int a, int b);

/*int altura(nodoAVL *nodo) {
  if (nodo == nullptr)
    return 0;
  return nodo->altura;
}*/

/*int maximo(int a, int b) {
    if(a>b){
        return a;
    }else{
        return b;
    }
}*/

/*nodoAVL *nuevoNodo(string ID) {
  nodoAVL *nodo = new nodoAVL();

  return nodo;
}*/

/*nodoAVL *rotarDerecha(nodoAVL *y) {
  if(y)
  {
      nodoAVL *x = y->izquierda;
      nodoAVL *T2 = x->derecha;
      x->derecha = y;
      y->izquierda = T2;
      y->altura = maximo(altura(y->izquierda), altura(y->derecha)) +1;
      x->altura = maximo(altura(x->izquierda), altura(x->derecha)) +1;
      return x;
  }
  return nullptr;
}*/

/*nodoAVL *rotarIzquierda(nodoAVL *x) {
  nodoAVL *y = x->derecha;
  nodoAVL *T2 = y->izquierda;
  y->izquierda = x;
  x->derecha = T2;
  x->altura = maximo(altura(x->izquierda), altura(x->derecha)) +1;
  y->altura = maximo(altura(y->izquierda), altura(y->derecha)) +1;
  return y;
}*/

/*int obtenerFE(nodoAVL *aux) {
  if (aux == nullptr)
  {
      return 0;
  }else
  {
   return altura(aux->izquierda) - altura(aux->derecha);
  }
}*/

/*nodoAVL *insertarNodo(nodoAVL *nodo, string ID) {
  if (nodo == nullptr)
  {
      return (nuevoNodo(ID));
  }
  if (ID > nodo->ID)
  {
      nodo->izquierda = insertarNodo(nodo->izquierda, ID);
  }
  else if (ID < nodo->ID)
  {
      nodo->derecha = insertarNodo(nodo->derecha, ID);
  }
  else
  {
      return nodo;
  }

  nodo->altura = 1 + maximo(altura(nodo->izquierda), altura(nodo->derecha));
  int FE = obtenerFE(nodo);
  if (FE > 1) {
    if (ID > nodo->izquierda->ID) {
      return rotarDerecha(nodo);
    } else if (ID < nodo->izquierda->ID) {
      nodo->izquierda = rotarIzquierda(nodo->izquierda);
      return rotarDerecha(nodo);
    }
  }
  if (FE < -1) {
    if (ID < nodo->derecha->ID) {
      return rotarIzquierda(nodo);
    } else if (ID > nodo->derecha->ID) {
      nodo->izquierda = rotarDerecha(nodo->izquierda);
      return rotarIzquierda(nodo);
    }
  }
  return nodo;
}*/

/*nodoAVL *valorMinimo(nodoAVL *nodo) {
  nodoAVL *aux = nodo;
  while (aux->izquierda != nullptr)
  {
      aux = aux->izquierda;
  }
  return aux;
}*/

/*nodoAVL *eliminarnodoAVL(nodoAVL *raiz, string ID) {
  if (raiz == nullptr)
  {
      return raiz;
  }
  if (ID > raiz->ID)
  {
      raiz->izquierda = eliminarnodoAVL(raiz->izquierda, ID);
  }
  else if (ID < raiz->ID)
  {
      raiz->derecha = eliminarnodoAVL(raiz->derecha, ID);
  }
  else {
    if ((raiz->izquierda == nullptr) || (raiz->derecha == nullptr)) {
      nodoAVL *temp;
      if(raiz->izquierda){
          temp=raiz->izquierda;
      }else{
          temp=raiz->derecha;
      }
      if (temp == nullptr) {
        temp = raiz;
        raiz = nullptr;
      } else
        *raiz = *temp;
      delete temp;
    } else {
      nodoAVL *temp = valorMinimo(raiz->derecha);
      raiz->ID = temp->ID;
      raiz->derecha = eliminarnodoAVL(raiz->derecha,temp->ID);
    }
  }

  if (raiz == nullptr)
  {
      return raiz;
  }
  raiz->altura = 1 + maximo(altura(raiz->izquierda),altura(raiz->derecha));
  int FE = obtenerFE(raiz);
  if (FE > 1) {
    if (obtenerFE(raiz->izquierda) >= 0) {
      return rotarDerecha(raiz);
    } else {
      raiz->izquierda = rotarIzquierda(raiz->izquierda);
      return rotarDerecha(raiz);
    }
  }
  if (FE < -1) {
    if (obtenerFE(raiz->derecha) <= 0) {
      return rotarIzquierda(raiz);
    } else {
      raiz->derecha = rotarDerecha(raiz->derecha);
      return rotarIzquierda(raiz);
    }
  }
  return raiz;
}*/

/*void imprimirArbol(nodoAVL* nodo,int contador){
    if(nodo==NULL){
        return;
    }else{
        imprimirArbol(nodo->derecha,contador+1);
        for(int i=0;i<contador;i++){
            cout<<"   ";
        }
        cout<<nodo->ID<<endl;
        imprimirArbol(nodo->izquierda,contador+1);
    }
}*/

/*void crearNodosGrafico(nodoAVL *nodo){
    if(nodo==NULL){
        return;
    }else{
    crearNodosGrafico(nodo->derecha);
    dot+=nodo->auxGrafico+" [label=\""+nodo->ID+"\"]\n";
    crearNodosGrafico(nodo->izquierda);
    }

}*/

/*void armarAVL(nodoAVL* nodo,nodoAVL* padre){
    if(nodo==NULL){
        return;
    }else{
        armarAVL(nodo->derecha,nodo);
        if(nodo!=padre)
        {
            dot+=padre->auxGrafico+" -> "+nodo->auxGrafico+"\n";
        }
        armarAVL(nodo->izquierda,nodo);
    }
}*/


/*void graficarAVL(){
    FILE * file;
    file=fopen("avl.dot","w+");
    fprintf(file,dot.c_str());
    fclose(file);

    system("dot.exe -Tpng avl.dot -o avl.png");
    system("start avl.png");
}*/



#endif // NODOAVL_H
