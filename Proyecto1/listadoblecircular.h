#ifndef LISTADOBLECIRCULAR_H
#define LISTADOBLECIRCULAR_H

#include <iostream>
using namespace std;
int contadorNodos=0;

struct nodoLista{
    string dato;
    string auxGrafico;
    nodoLista *siguiente;
    nodoLista *anterior;
}*primero,*ultimo;

void insertarNodoLista(string valor){
    nodoLista *nuevo=new nodoLista();
    nuevo->dato=valor;
    nuevo->auxGrafico="Nodo"+to_string(contadorNodos);
    contadorNodos++;

    if(primero==nullptr){
        primero=nuevo;
        ultimo=nuevo;
        primero->siguiente=primero;
        primero->anterior=ultimo;
    }else{
        if(valor>ultimo->dato){
            ultimo->siguiente=nuevo;
            nuevo->anterior=ultimo;
            nuevo->siguiente=primero;
            ultimo=nuevo;
            primero->anterior=ultimo;
        }else{
            nodoLista *aux=ultimo;
            do{
                aux=aux->anterior;
                if(valor>aux->dato){
                    nodoLista *aux2=aux->siguiente;
                    aux->siguiente=nuevo;
                    nuevo->anterior=aux;
                    nuevo->siguiente=aux2;
                    aux2->anterior=nuevo;
                }else if(aux==primero){
                    if(valor<aux->dato){
                        primero->anterior=nuevo;
                        nuevo->siguiente=primero;
                        nuevo->anterior=ultimo;
                        primero=nuevo;
                        ultimo->siguiente=primero;
                    }
                }
            }while(aux!=ultimo);
        }
    }
}

void recorrerLista(int recorrido){
    if(primero!=nullptr)
    {
        if(recorrido==0){//ascendente
            nodoLista *aux=primero;
            do{
                cout<<aux->dato<<" -> ";
                aux=aux->siguiente;
            }while(aux!=primero);
        }else{
            nodoLista *aux=ultimo;
            do{
                cout<<aux->dato<<" -> ";
                aux=aux->anterior;
            }while(aux!=ultimo);
        }
    }
}

void graficarLista(int recorrido){
    string dot="digraph Lista{\n"
            "rankdir=LR\n"
            "node[shape=record]\n";
    if(primero!=nullptr)
    {
        if(recorrido==0){//ascendente
            nodoLista *aux=primero;
            do{
                dot+=aux->auxGrafico+"[label=\""+aux->dato+"\"]"+"\n";
                aux=aux->siguiente;
            }while(aux!=primero);
        }else{
            nodoLista *aux=ultimo;
            do{
                dot+=aux->auxGrafico+"[label=\""+aux->dato+"\"]"+"\n";
                aux=aux->anterior;
            }while(aux!=ultimo);
        }
        if(recorrido==0){//ascendente
            nodoLista *aux=primero;
            do{
                dot+=aux->auxGrafico+"->"+aux->siguiente->auxGrafico+"[dir=both]"+"\n";
                aux=aux->siguiente;
            }while(aux!=primero);
        }else{
            nodoLista *aux=ultimo;
            do{
                dot+=aux->auxGrafico+"->"+aux->anterior->auxGrafico+"[dir=both]"+"\n";
                aux=aux->anterior;
            }while(aux!=ultimo);
        }

        dot+="}";
        FILE * file;
        file=fopen("listaCircular.dot","w+");
        fprintf(file,dot.c_str());
        fclose(file);

        system("dot.exe -Tpng listaCircular.dot -o listaCircular.png");
        system("start listaCircular.png");
    }
}

#endif // LISTADOBLECIRCULAR_H
