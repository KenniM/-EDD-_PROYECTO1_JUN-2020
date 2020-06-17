#ifndef LISTADOBLECIRCULAR_H
#define LISTADOBLECIRCULAR_H
#include <ctime>

#include <iostream>
using namespace std;
int contadorNodos=0;

struct nodoLista{
    string ID;
    string rentador;
    string empresaRentador;
    string deptoRentaodr;
    string auxGrafico;
    char* fechaRenta;
    nodoLista *siguiente;
    nodoLista *anterior;
}*primero,*ultimo;

void insertarNodoLista(string id_,string idRentador,string empresa,string depto){
    nodoLista *nuevo=new nodoLista();
    nuevo->ID=id_;
    nuevo->rentador=idRentador;
    nuevo->auxGrafico="Nodo"+to_string(contadorNodos);
    contadorNodos++;
    nuevo->empresaRentador=empresa;
    nuevo->deptoRentaodr=depto;
    time_t fechaActual=time(0);
    nuevo->fechaRenta=ctime(&fechaActual);

    if(primero==nullptr){
        primero=nuevo;
        ultimo=nuevo;
        primero->siguiente=primero;
        primero->anterior=ultimo;
    }else{
        if(id_>ultimo->ID){
            ultimo->siguiente=nuevo;
            nuevo->anterior=ultimo;
            nuevo->siguiente=primero;
            ultimo=nuevo;
            primero->anterior=ultimo;
        }else{
            nodoLista *aux=ultimo;
            do{
                aux=aux->anterior;
                if(id_>aux->ID){
                    nodoLista *aux2=aux->siguiente;
                    aux->siguiente=nuevo;
                    nuevo->anterior=aux;
                    nuevo->siguiente=aux2;
                    aux2->anterior=nuevo;
                }else if(aux==primero){
                    if(id_<aux->ID){
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
                cout<<aux->ID<<" -> ";
                aux=aux->siguiente;
            }while(aux!=primero);
        }else{
            nodoLista *aux=ultimo;
            do{
                cout<<aux->ID<<" -> ";
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
                dot+=aux->auxGrafico+"[label=\""+aux->ID+"\"]"+"\n";
                aux=aux->siguiente;
            }while(aux!=primero);
        }else{
            nodoLista *aux=ultimo;
            do{
                dot+=aux->auxGrafico+"[label=\""+aux->ID+"\"]"+"\n";
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
