#ifndef MATRIZ_H
#define MATRIZ_H
#include "nodo.h"


class Matriz {
public:
    Nodo* cabecera;
    Matriz(){
        cabecera=new Nodo("admin","admin1234");
    }
    void insertarElemento(std::string nombre,std::string empresa,std::string departamento,std::string password);
    Nodo* crearEmpresa(std::string empresa);
    Nodo* crearDepartamento(std::string departamento);
    Nodo* buscarEmpresa(std::string empresa, Nodo* inicio);
    Nodo* buscarDepto(std::string departamento, Nodo* inicio);
    Nodo* localizarEmpleado(Matriz* ,std::string usuario,std::string password,std::string empresa,std::string departamento);
    nodoAVL* rotarDerecha(nodoAVL*);
    nodoAVL* rotarIzquierda(nodoAVL*);
    nodoAVL* insertarNodo(nodoAVL*,string,string,string);
    nodoAVL* valorMinimo(nodoAVL*);
    nodoAVL* eliminarnodoAVL(nodoAVL*,string);
    nodoAVL* modificarNodoAVL(nodoAVL* arbol,string id_,string descripcion);
    void listarActivos(Matriz*,Nodo* usuarioActual);
    void inOrden(nodoAVL*);
    void inOrdenParaRenta(nodoAVL*);
    void preOrden(nodoAVL*);
    void postOrden(nodoAVL*);
    int altura(nodoAVL* nodo);
    int maximo(int a,int b);
    int obtenerFE(nodoAVL* aux);
    void imprimirArbol(nodoAVL*,int);
    string crearNodosGrafico(nodoAVL*);
    string armarAVL(nodoAVL*,nodoAVL*);
    void graficarAVL(nodoAVL*);
    nodoAVL* buscarID(nodoAVL* arbol,string clave);
    bool rentarActivo(Matriz* matriz,string idRentado,int tiempo);
    bool verificarEmpresa(std::string empresa, Nodo* inicio, Nodo* usr);
    bool verificarDepto(std::string depto, Nodo* inicio, Nodo* usr);
    void listarEmpleados(std::string depto,std::string empresa);
    bool buscarEmpleado(Matriz* ,std::string usuario,std::string password,std::string empresa,std::string departamento);
    void recorrerXY();

};

#endif // MATRIZ_H
