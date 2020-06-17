//
// Created by Kenni on 05/06/2020.
//

#include "matriz.h"
#include <algorithm>

int contadorNodo=0;

int compararSinMayus(std::string entrada1, std::string entrada2) {
   //convert s1 and s2 into lower case strings
   transform(entrada1.begin(), entrada1.end(), entrada1.begin(), ::tolower);
   transform(entrada2.begin(), entrada2.end(), entrada2.begin(), ::tolower);
   if(entrada1.compare(entrada2) == 0)
      return 1; //Son iguales
   return 0;
}

Nodo* Matriz::crearEmpresa(std::string empresa) {
    Nodo* emp;
    emp = new Nodo(empresa, -1);

    Nodo* aux = cabecera;
    while (aux->abajo != nullptr) {
        aux = aux->abajo;
    }
    aux->abajo = emp;
    emp->arriba = aux;
    return emp;
}

Nodo* Matriz::crearDepartamento(std::string departamento) {
    Nodo* depto;
    depto = new Nodo(departamento, -1);

    Nodo* aux = cabecera;
    while (aux->siguiente != nullptr) {
        aux = aux->siguiente;
    }
    aux->siguiente = depto;
    depto->anterior = aux;
    return depto;
}

Nodo* Matriz::buscarDepto(std::string departamento, Nodo* inicio) {
    Nodo* aux = inicio;
    while (aux != nullptr) {
        if (compararSinMayus(aux->nombre,departamento)) {
            return aux;
        }
        aux = aux->siguiente;
    }
    return nullptr;
}

Nodo* Matriz::buscarEmpresa(std::string empresa, Nodo* inicio) {
    Nodo* aux = inicio;
    while (aux != nullptr) {
        if (compararSinMayus(aux->nombre,empresa)) {
            return aux;
        }
        aux = aux->abajo;
    }
    return nullptr;
}

//Inserta un nodo dentro de la matriz cúbica dispersa
void Matriz::insertarElemento(std::string usuario, std::string empresa, std::string departamento,std::string password) {

    Nodo* NodoUsr;
    Nodo* NodoDepto;
    Nodo* NodoEmpresa;

    NodoUsr = new Nodo(usuario, password);
    NodoDepto = buscarDepto(departamento, cabecera);
    NodoEmpresa = buscarEmpresa(empresa, cabecera);


    //REVISA SI EXISTEN LOS ENCABEZADOS
    if (NodoEmpresa == nullptr) {
        NodoEmpresa = crearEmpresa(empresa);
    }
    if (NodoDepto == nullptr) {
        NodoDepto = crearDepartamento(departamento);
    }

    //INSERTAR NODO DEPARTAMENTO
        //INSERTANDO AL INICIO
    if (NodoDepto->abajo == nullptr) {
        NodoDepto->abajo = NodoUsr;
        NodoUsr->arriba = NodoDepto;
    }   //INSERTANDO AL FINAL
    else if(NodoEmpresa->abajo== nullptr){
        Nodo *aux=NodoDepto->abajo;
        while(aux->abajo!= nullptr){
            aux=aux->abajo;
        }
        if(!verificarEmpresa(empresa,aux,NodoUsr)){
            aux->abajo=NodoUsr;
            NodoUsr->arriba=aux;
        }
    } //INSERTAR EN MEDIO
    else{
        Nodo *aux=NodoDepto;
        do {
            aux=aux->abajo;
            if (!verificarEmpresa(empresa,aux,NodoUsr)){
                Nodo *auxEmpresa=aux->anterior;
                while (auxEmpresa->anterior!= nullptr){
                    auxEmpresa=auxEmpresa->anterior;
                }
                while (auxEmpresa->arriba!= nullptr){
                    if(auxEmpresa->nombre==empresa){
                        NodoUsr->abajo=aux;
                        NodoUsr->arriba=aux->arriba;

                        aux->arriba->abajo=NodoUsr;
                        aux->arriba=NodoUsr;

                        break;
                    }
                    auxEmpresa=auxEmpresa->arriba;
                }
            }
        }while (aux->abajo!= nullptr && NodoUsr->arriba== nullptr);
        if (NodoUsr->arriba== nullptr && NodoUsr->adelante== nullptr){
            aux->abajo=NodoUsr;
            NodoUsr->arriba=aux;
        }
    }

    if(NodoUsr->adelante!= nullptr){
        return;
    }
    //INSERTAR EN NODO EMPRESA
        //INSERTANDO AL INICIO
    if(NodoEmpresa->siguiente== nullptr){
        NodoEmpresa->siguiente=NodoUsr;
        NodoUsr->anterior=NodoEmpresa;
    }else if(NodoDepto->siguiente==nullptr){
        Nodo *aux=NodoEmpresa->siguiente;
        while(aux->siguiente!= nullptr){
            aux=aux->siguiente;
        }
        if(!verificarDepto(departamento,aux,NodoUsr)){
            aux->siguiente=NodoUsr;
            NodoUsr->anterior=aux;
        }
    }else{
        Nodo *aux=NodoEmpresa;
        do {
            aux=aux->siguiente;
            if(!verificarDepto(departamento,aux,NodoUsr)){
                Nodo *auxDepto=aux->arriba;
                while (auxDepto->arriba!= nullptr){
                    auxDepto=auxDepto->arriba;
                }
                while (auxDepto->anterior!= nullptr){
                    if(auxDepto->nombre==departamento){
                        NodoUsr->siguiente=aux;
                        NodoUsr->anterior=aux->anterior;

                        aux->anterior->siguiente=NodoUsr;
                        aux->anterior=NodoUsr;

                        break;
                    }
                    auxDepto=auxDepto->anterior;
                }
            }
        }while (aux->siguiente!= nullptr && NodoUsr->anterior== nullptr);
        if(NodoUsr->anterior== nullptr && NodoUsr->adelante== nullptr){
            aux->siguiente=NodoUsr;
            NodoUsr->anterior=aux;
        }
    }



}

bool Matriz::verificarEmpresa(std::string empresa, Nodo* inicio, Nodo* usr) {
    Nodo* auxEmp = inicio->anterior;
    while (auxEmp->anterior != nullptr) {
        auxEmp = auxEmp->anterior;
    }
    if (auxEmp->nombre == empresa) {
        while (inicio->atras!= nullptr){
            if(inicio->atras->nombre==usr->nombre)
            {
                std::cout<<"Ya existe un usuario con el mismo nombre:"<<usr->nombre<< " dentro de la sucursal de esta empresa."<<std::endl;
                break;
            }else{
                inicio=inicio->atras;
            }
        }
        inicio->atras=usr;
        usr->adelante=inicio;

        return true;
    }
    return false;
}

bool Matriz::verificarDepto(std::string departamento, Nodo* inicio, Nodo* usr) {
    Nodo* auxDepto = inicio->arriba;
    while (auxDepto->arriba != nullptr) {
        auxDepto = auxDepto->arriba;
    }
    if (auxDepto->nombre == departamento) {
        while (inicio->atras!= nullptr){
            if(inicio->atras->nombre==usr->nombre)
            {
                std::cout<<"Ya existe un usuario con el mismo nombre:"<<usr->nombre<< " dentro de la sucursal de esta empresa."<<std::endl;
                break;
            }else{
                inicio=inicio->atras;
            }
        }
        inicio->atras=usr;
        usr->adelante=inicio;

        return true;
    }
    return false;
}

bool Matriz::buscarEmpleado(Matriz *matriz,std::string usuario, std::string password,std::string empresa,std::string departamento){
    if(matriz->buscarEmpresa(empresa,matriz->cabecera)!= nullptr){
        if(matriz->buscarDepto(departamento,matriz->cabecera)!= nullptr){
            Nodo *tempEmpresa=buscarEmpresa(empresa,cabecera);
            Nodo *tempDepto=buscarDepto(departamento,cabecera);
            while (tempEmpresa!=tempDepto){
                if(tempEmpresa->siguiente!=nullptr){
                    tempEmpresa=tempEmpresa->siguiente;
                }
                if(tempEmpresa==tempDepto){
                    break;
                }
                if(tempDepto->abajo!= nullptr){
                tempDepto=tempDepto->abajo;
                }
                if(tempEmpresa->siguiente==nullptr && tempDepto->siguiente==nullptr){
                    break;
                }
            }do{
              //  std::cout<<tempEmpresa->nombre<<", contrasenia: "<<tempEmpresa->password<<"->";
                if(tempEmpresa->nombre==usuario && tempEmpresa->password==password){
                    return true;
                }
                tempEmpresa=tempEmpresa->atras;
            }while (tempEmpresa!= nullptr);
        }else{
            return false;
        }
    }else{
        return false;
    }
    return false;

}

Nodo* Matriz::localizarEmpleado(Matriz *matriz,std::string usuario, std::string password,std::string empresa,std::string departamento){
    if(matriz->buscarEmpresa(empresa,matriz->cabecera)!= nullptr){
        if(matriz->buscarDepto(departamento,matriz->cabecera)!= nullptr){
            Nodo *tempEmpresa=buscarEmpresa(empresa,cabecera);
            Nodo *tempDepto=buscarDepto(departamento,cabecera);
            while (tempEmpresa!=tempDepto){
                if(tempEmpresa->siguiente!=nullptr){
                    tempEmpresa=tempEmpresa->siguiente;
                }
                if(tempEmpresa==tempDepto){
                    break;
                }
                if(tempDepto->abajo!= nullptr){
                tempDepto=tempDepto->abajo;
                }
                if(tempEmpresa->siguiente==nullptr && tempDepto->siguiente==nullptr){
                    break;
                }
            }do{
              //  std::cout<<tempEmpresa->nombre<<", contrasenia: "<<tempEmpresa->password<<"->";
                if(tempEmpresa->nombre==usuario && tempEmpresa->password==password){
                    return tempEmpresa;
                }
                tempEmpresa=tempEmpresa->atras;
            }while (tempEmpresa!= nullptr);
        }else{
            return nullptr;
        }
    }else{
        return nullptr;
    }
    return nullptr;

}

void Matriz::recorrerXY() {
    std::cout << "Imprimiendo..."<<std::endl;
    Nodo* x = cabecera;
    Nodo* y = x;
    std::cout<<"Imprimiendo departamentos:"<<std::endl;
    while (x->siguiente != nullptr) {
        x=x->siguiente;
        std::cout<<x->nombre<<std::endl;
    }
    std::cout<<"Imprimiendo empresas:"<<std::endl;
    while (y->abajo != nullptr) {
        y=y->abajo;
        std::cout<<y->nombre<<std::endl;
    }
}

nodoAVL* Matriz::rotarDerecha(nodoAVL* y){
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
}

nodoAVL* Matriz::rotarIzquierda(nodoAVL *x){
    nodoAVL *y = x->derecha;
    nodoAVL *T2 = y->izquierda;
    y->izquierda = x;
    x->derecha = T2;
    x->altura = maximo(altura(x->izquierda), altura(x->derecha)) +1;
    y->altura = maximo(altura(y->izquierda), altura(y->derecha)) +1;
    return y;
}

nodoAVL* Matriz::insertarNodo(nodoAVL *nodo, string ID,string activo,string desc){
    if (nodo == nullptr)
    {
        nodo=new nodoAVL(ID,contadorNodo,activo,desc);
        contadorNodo++;
        return nodo;
    }
    if (ID > nodo->ID)
    {
        nodo->izquierda = insertarNodo(nodo->izquierda, ID,activo,desc);
        contadorNodo++;
    }
    else if (ID < nodo->ID)
    {
        nodo->derecha = insertarNodo(nodo->derecha, ID,activo,desc);
        contadorNodo++;
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
}

nodoAVL* Matriz::valorMinimo(nodoAVL *nodo){
    nodoAVL *aux = nodo;
    while (aux->izquierda != nullptr)
    {
        aux = aux->izquierda;
    }
    return aux;
}

nodoAVL* Matriz::eliminarnodoAVL(nodoAVL *raiz, string ID){
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
}

void Matriz::imprimirArbol(nodoAVL *nodo, int contador){
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
}

string Matriz::crearNodosGrafico(nodoAVL *nodo){
    string dot="";
    if(nodo==NULL){
        return dot;
    }else{
    dot+=crearNodosGrafico(nodo->derecha);
    if(nodo->rentado){
        dot+=nodo->auxGrafico+" [style=filled color=gray label=\"ID: "+nodo->ID+" \\l Activo: "+nodo->activo+"\\l Descripcion: "+ nodo->descripcion+ "\\l Estado: Rentado\"]\n";
    }else
    {
        dot+=nodo->auxGrafico+" [label=\"ID: "+nodo->ID+" \\l Activo: "+nodo->activo+"\\l Descripcion:"+ nodo->descripcion+ "\\l Estado: Sin rentar\"]\n";
    }
    dot+=crearNodosGrafico(nodo->izquierda);
    }
    return dot;
}

string Matriz::armarAVL(nodoAVL *nodo, nodoAVL *padre){
    string dot="";
    if(nodo==NULL){
        return dot;
    }else{
        dot+=armarAVL(nodo->derecha,nodo);
        if(nodo!=padre)
        {
            dot+=padre->auxGrafico+" -> "+nodo->auxGrafico+"\n";
        }
        dot+=armarAVL(nodo->izquierda,nodo);
    }
    return dot;
}

void Matriz::graficarAVL(nodoAVL* arbol){
    string dot="digraph AVL{\n";
    dot+=crearNodosGrafico(arbol);
    dot+=armarAVL(arbol,arbol);
    dot+="}";
    cout<<dot<<endl;
    system("pause");
    FILE * file;
    file=fopen("avl.dot","w+");
    fprintf(file,dot.c_str());
    fclose(file);

    system("dot.exe -Tpng -Gdpi=350 avl.dot -o avl.png");
    system("start avl.png");
}

int Matriz::altura(nodoAVL *nodo){
    if (nodo == nullptr)
      return 0;
    return nodo->altura;
}

int Matriz::maximo(int a, int b){
    if(a>b){
        return a;
    }else{
        return b;
    }
}

int Matriz::obtenerFE(nodoAVL *aux){
    if (aux == nullptr)
    {
        return 0;
    }else
    {
     return altura(aux->izquierda) - altura(aux->derecha);
    }
}

void Matriz::inOrden(nodoAVL *arbol){
    if(arbol==nullptr){
        return;
    }else{
        inOrden(arbol->izquierda);
       cout<<"-->"<<"ID: "<<arbol->ID<<" || Nombre: "<<arbol->activo<<" || Descripcion: "<<arbol->descripcion<<endl;
        inOrden(arbol->derecha);
    }
}

void Matriz::inOrdenParaRenta(nodoAVL *arbol){
    if(arbol==nullptr){
        return;
    }else{
        inOrdenParaRenta(arbol->izquierda);
        if(!arbol->rentado)
        {cout<<"-->"<<"ID: "<<arbol->ID<<" || Nombre: "<<arbol->activo<<" || Descripcion: "<<arbol->descripcion<<endl;}
        inOrdenParaRenta(arbol->derecha);
    }
}

void Matriz::preOrden(nodoAVL *arbol){
    if(arbol==nullptr){
        return;
    }else{
       // cout<<arbol->dato<<" - ";
        preOrden(arbol->izquierda);
        preOrden(arbol->derecha);
    }
}

void Matriz::postOrden(nodoAVL *arbol){
    if(arbol==nullptr){
        return;
    }else{
        postOrden(arbol->izquierda);
        postOrden(arbol->derecha);
        //cout<<arbol->dato<<" - ";

    }
}

nodoAVL* Matriz::modificarNodoAVL(nodoAVL *arbol, string id_, string descripcion){
    if(arbol==nullptr){
        return arbol;
    }else{
        modificarNodoAVL(arbol->izquierda,id_,descripcion);
        if(arbol->ID==id_){
            arbol->descripcion=descripcion;
            return nullptr;
        }modificarNodoAVL(arbol->derecha,id_,descripcion);

    }
    return arbol;
}

bool Matriz::buscarID(nodoAVL* arbol,string clave,string tiempo){
    if(arbol==nullptr){
        return false;
    }else if(arbol->ID==clave){
        arbol->rentado=true;
        arbol->diasRenta=tiempo;
        return true;
    }else if(clave>arbol->ID){
        return buscarID(arbol->izquierda,clave,tiempo);
    }else{
        return buscarID(arbol->derecha,clave,tiempo);
    }

}

bool Matriz::rentarActivo(Matriz* matriz,string idRentador,string tiempo){
    Nodo* aux1=matriz->cabecera->abajo; //ESTE GUIARA POR FILA
    Nodo* aux2=aux1->siguiente; //ESTE IRA NODO POR NODO EN PROFUNDIDAD
    Nodo* aux3=aux2; //ESTE GUIA A LOS PRIMEROS NODOS DE CADA SUCURSAL

    while(aux1!=nullptr){
        while(aux3!=nullptr)
        {
            while(aux2!=nullptr)
            {
                if(buscarID(aux2->arbolPersonal,idRentador,tiempo)){
                    return true;
                    break;
                }
                aux2=aux2->atras;
            }
            aux3=aux3->siguiente;
            aux2=aux3;
        }
        aux1=aux1->abajo;
        if(aux1)
        {aux3=aux1->siguiente;}
    }return false;
}

void Matriz::listarActivos(Matriz *matriz, Nodo *usuarioActual){
    Nodo* aux1=matriz->cabecera->abajo; //ESTE GUIARA POR FILA
    Nodo* aux2=aux1->siguiente; //ESTE IRA NODO POR NODO EN PROFUNDIDAD
    Nodo* aux3=aux2; //ESTE GUIA A LOS PRIMEROS NODOS DE CADA SUCURSAL
    while(aux1!=nullptr){
        while(aux3!=nullptr)
        {
            while(aux2!=nullptr)
            {
                if(aux2!=usuarioActual){
                    matriz->inOrdenParaRenta(aux2->arbolPersonal);
                }
                aux2=aux2->atras;
            }
            aux3=aux3->siguiente;
            aux2=aux3;
        }
        aux1=aux1->abajo;
        if(aux1)
        {aux3=aux1->siguiente;}
    }

}
