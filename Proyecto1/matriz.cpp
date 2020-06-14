//
// Created by Kenni on 05/06/2020.
//

#include "nodo.h"
#include "matriz.h"
#include <algorithm>

int compararSinMayus(std::string entrada1, std::string entrada2) {
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
                system("pause");
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

void Matriz::listarEmpleados(std::string depto, std::string empresa) {
    if(buscarEmpresa(empresa,cabecera)!= nullptr){
        if(buscarDepto(depto,cabecera)!= nullptr){
            Nodo *tempEmpresa=buscarEmpresa(empresa,cabecera);
            Nodo *tempDepto=buscarDepto(depto,cabecera);
            std::cout<<"Mostrando los empleados de la empresa: "<<empresa<<", ubicada en el departamento de: "<<depto<<std::endl;
            while (tempEmpresa!=tempDepto){
                if(tempEmpresa->siguiente!=nullptr){
                    tempEmpresa=tempEmpresa->siguiente;
                }
                if(tempDepto->abajo!= nullptr){
                tempDepto=tempDepto->abajo;
                }
            }do{
                std::cout<<tempEmpresa->nombre<<"->";
                tempEmpresa=tempEmpresa->atras;
            }while (tempEmpresa!= nullptr);
        }else{
            std::cout<<"No se ha encontrado el departamento indicado"<<std::endl;
        }
    }else{
        std::cout<<"No se ha encontrado la empresa indicada"<<std::endl;
    }
}

bool Matriz::localizarEmpleado(std::string usuario,std::string empresa,std::string departamento){
    Nodo *aux1=cabecera; //ESTE AUXILIAR NAVEGA POR DEPARTAMENTOS
    Nodo *aux2=aux1;     //ESTE AUXILIAR NAVEGA POR LOS USUARIOS DE ARRIBA HACIA ABAJO, LUEGO AVANZA AL DEPTO. SIGUIENTE
    Nodo *aux3=aux1;     //ESTE AUXILIAR NAVEGA POR LAS EMPRESAS
    std::string empTemp,empDepto;

        while (aux1->siguiente!=nullptr) {
            aux1=aux1->siguiente;
            aux2=aux1;
            while (aux2->abajo!=nullptr) {
                aux2=aux2->abajo;
                if(aux3->abajo!=nullptr){
                    aux3=aux3->abajo;
                }
                if(aux2->nombre==usuario && aux3->nombre==empresa && aux1->nombre==departamento){
                    return true;
                }
                while (aux2->atras!=nullptr) {
                    aux2=aux2->atras;
                    if(aux2->nombre==usuario && aux3->nombre==empresa && aux1->nombre==departamento){
                        return true;
                    }
                }
            }aux3=cabecera->abajo;
        }
        return false;
}

bool Matriz::buscarEmpleado(std::string usuario, std::string password,std::string empresa,std::string departamento){
    Nodo *aux1=cabecera; //ESTE AUXILIAR NAVEGA POR DEPARTAMENTOS
    Nodo *aux2=aux1;     //ESTE AUXILIAR NAVEGA POR LOS USUARIOS DE ARRIBA HACIA ABAJO, LUEGO AVANZA AL DEPTO. SIGUIENTE
    Nodo *aux3=aux1;     //ESTE AUXILIAR NAVEGA POR LAS EMPRESAS
    std::string empTemp,empDepto;

        while (aux1->siguiente!=nullptr) {
            aux1=aux1->siguiente;
            aux2=aux1;
            while (aux2->abajo!=nullptr) {
                aux2=aux2->abajo;
                if(aux3->abajo!=nullptr){
                    aux3=aux3->abajo;
                }
                if(aux2->nombre==usuario && aux2->password==password && aux3->nombre==empresa && aux1->nombre==departamento){
                    return true;
                }
                while (aux2->atras!=nullptr) {
                    aux2=aux2->atras;
                    if(aux2->nombre==usuario && aux2->password==password && aux3->nombre==empresa && aux1->nombre==departamento){
                        return true;
                    }
                }
            }aux3=cabecera->abajo;
        }
        return false;

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

void Matriz::graficarMatriz(){

}


