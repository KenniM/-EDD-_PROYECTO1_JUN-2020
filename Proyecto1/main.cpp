#include <QCoreApplication>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "listadoblecircular.h"
#include "matriz.h"
#include "windows.h"
#define _CRT_SECURE_NO_DEPRECATE


using namespace std;
int tipoRecorrido=0;
void menuPrincipal(Matriz*);
void menuAdmin(Matriz*);

string id(int limite){
    int tamanio=limite;
    string temp="";
    for(int i=0;i<tamanio;i++){
        int random=rand() % 3;
        if(random==0){
            char actual=rand() % 10+48;
            temp+=actual;
        }else if(random==1){
            char actual=rand() % 26+65;
            temp+=actual;
        }else{
            char actual=rand() % 26+97;
            temp+=actual;
        }
    }
    return temp;
}

void loginAdmin(Matriz *matriz){
    system("cls");
    cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"------------------------------------------- INICIANDO COMO ADMINISTRADOR ----------------------------------------------"<<endl;
    cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
    string usr,psw;
    cout<<"Por favor, identifiquese para continuar: "<<endl;
    cout<<"Usuario:";
    cin>>usr;
    cout<<endl<<"Contrasenia:";
    cin>>psw;
    if(matriz->cabecera->nombre==usr && matriz->cabecera->password==psw){

        system("cls");
        system("color 02");
        cout<<"Bienvenido, "<<usr<<endl;
        system("pause");
        menuAdmin(matriz);
    }else{
        system("cls");
        system("color c0");
        cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
        cout<<"--------------------------------------------- CREDENCIALES INCORRECTAS ------------------------------------------------"<<endl;
        cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
        cout<<"Esta cuenta no pertenece al administrador, intente de nuevo"<<endl;
        system("pause");
        menuPrincipal(matriz);
    }
}

void loginTrabajador(Matriz *matriz){
    system("cls");
    cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"--------------------------------------------- INICIANDO COMO TRABAJADOR -----------------------------------------------"<<endl;
    cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
    matriz->recorrerXY();
    string usr,psw,empresa,depto;
    cout<<"Por favor, inicie sesion para continuar: "<<endl;
    cout<<"Usuario:";
    cin>>usr;
    cout<<endl<<"Contrasenia:";
    cin>>psw;
    cout<<"Empresa:";
    cin>>empresa;
    cout<<endl<<"Departamento:";
    cin>>depto;
    if(matriz->buscarEmpleado(matriz,usr,psw,empresa,depto)){
        //POSIBLE INSERCION DE NODOS DENTRO DE LOS AVL DE CADA USUARIO?
       /* Nodo* sesion=matriz->localizarEmpleado(matriz,usr,psw,empresa,depto);
        nodoAVL* activoNuevo=new nodoAVL(id(15),contadorNodos);
        sesion->arbolPersonal=matriz->insertarNodo(activoNuevo,activoNuevo->ID)*/
        system("cls");
        system("color 02");
        cout<<"Bienvenido, "<<usr<<endl;
        system("pause");
        menuPrincipal(matriz);
    }else{
        system("cls");
        system("color c0");
        cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
        cout<<"--------------------------------------------- CREDENCIALES INCORRECTAS ------------------------------------------------"<<endl;
        cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
        cout<<"Lo sentimos, pero "<<usr<<" no se ha encontrado con los datos proporcionados. Intente de nuevo"<<endl;
        system("pause");
        menuPrincipal(matriz);
    }
}

void menuPrincipal(Matriz *cubo)
{
    int opcion;
    system("cls");
    system("color 07");
    cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"------------------------------------------------- INICIO DE SESION ----------------------------------------------------"<<endl;
    cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"1. Iniciar como Administrador."<<endl;
    cout<<"2. Iniciar como Trabajador."<<endl;
    cout<<"3. Salir."<<endl;
    cout<<"Ingrese una opcion para continuar:"<<endl;
    cin>>opcion;
    switch (opcion) {
    case 1:
        loginAdmin(cubo);
    case 2:
        loginTrabajador(cubo);
    case 3:
        exit(0);
    default:
        menuPrincipal(cubo);
    }

}

void menuAdmin(Matriz *cubo){
    int opcion;
    system("cls");
    system("color 07");
    cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"----------------------------------------------- MENU DE ADMINISTRADOR -------------------------------------------------"<<endl;
    cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"1. Registrar usuario."<<endl;
    cout<<"2. Generar reporte de la matriz dispersa (primer cara)."<<endl;
    cout<<"3. Generar reporte de usuarios de una sucursal (profundidad del cubo para un solo nodo)."<<endl;
    cout<<"4. Generar reporte activos disponibles en un departamento"<<endl;
    cout<<"5. Generar reporte de activos disponibles en una empresa."<<endl;
    cout<<"6. Generar reporte de transacciones."<<endl;
    cout<<"7. Generar reporte de activos de un usuario."<<endl;
    cout<<"8. Generar reporte de activos rentados por un usuario."<<endl;
    cout<<"9. Configurar el ordenamiento de las transacciones."<<endl;
    cout<<"10. Salir al menu principal"<<endl;
    cout<<"Seleccione una de las opciones anteriores para continuar:"<<endl;
    cin>>opcion;

    switch (opcion) {
    case 1:
    {
        system("cls");
        system("color 07");
        cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
        cout<<"----------------------------------------------- CREAR UN NUEVO USUARIO ------------------------------------------------"<<endl;
        cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;

        string usuario,empresa,departamento,password;
        cout<<"Ingrese el nombre del nuevo usuario:"<<endl;
        cin>>usuario;
        cout<<"Ingrese la contrasenia del nuevo usuario:"<<endl;
        cin>>password;
        cout<<"Ingrese la empresa a la que pertenece el nuevo usuario:"<<endl;
        cin>>empresa;
        cout<<"Ingrese el departamento de la sucursal de la empresa en la que trabajara el nuevo usuario:"<<endl;
        cin>>departamento;
        try {
            cubo->insertarElemento(usuario,empresa,departamento,password);
            system("cls");
            system("color 02");
            cout<<"Se han guardado los datos correctamente."<<endl;
            system("pause");
            menuAdmin(cubo);
            break;
        } catch (exception ex) {
            system("cls");
            system("color c0");
            cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
            cout<<"-------------------------------------------------- ERROR CRITICO! -----------------------------------------------------"<<endl;
            cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
            cout<<"Se ha producido un error al ingresar los datos, intente de nuevo o pruebe reiniciando la aplicacion."<<endl;
            system("pause");
            menuAdmin(cubo);
            break;
        }

        break;
    }
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        break;
    case 6:
        break;
    case 7:
        break;
    case 8:
        break;
    case 9:
    { system("cls");
        system("color 07");
        cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
        cout<<"---------------------------------------------- CONFIGURAR TRANSACCIONES -----------------------------------------------"<<endl;
        cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
        cout<<"Ingrese una de las dos opciones para ordenar la lista de transacciones, esto se podra ver al momento de generar el reporte correspondiente:"<<endl;
        cout<<"0. Ordenamiento ascendente."<<endl;
        cout<<"1. Ordenamiento descendente."<<endl;
        cout<<"Ingrese una opcion para continuar"<<endl;
        int opcionR;
        cin>>opcionR;
        switch (opcionR) {
        case 0:
            system("cls");
            system("color 02");
            tipoRecorrido=0;
            cout<<"Se ha configurado la lista de transacciones en orden ascendente."<<endl;
            system("pause");
            menuAdmin(cubo);
            break;
        case 1:
            system("cls");
            system("color 02");
            tipoRecorrido=1;
            cout<<"Se ha configurado la lista de transacciones en orden descendente."<<endl;
            system("pause");
            menuAdmin(cubo);
            break;
        }
        break;
    }
    case 10:
        menuPrincipal(cubo);
        break;
    }
}




int main()
{srand(time(NULL));
    Matriz *cubo=new Matriz();
    nodoLista *lista=new nodoLista();

    cubo->insertarElemento("Mynor", "MAX", "Guatemala","mynor1");
    cubo->insertarElemento("Susan", "hp", "Jutiapa","susan2");
    cubo->insertarElemento("Susel", "hp", "Jalapa","susel3");
    cubo->insertarElemento("Roxana", "Walmart", "Jalapa","roxana4");
    cubo->insertarElemento("Andrea", "Walmart", "Jalapa","andrea5");
    cubo->insertarElemento("Sebas", "Walmart", "Jalapa","sebas6");
    cubo->insertarElemento("Andres", "hp", "Guatemala","andres7");
    cubo->insertarElemento("Willy", "MAX", "Jalapa","willy7");

    cubo->recorrerXY();

    /*nodoAVL *arbol=nullptr;
    arbol=insertarNodo(arbol,id(15));
    arbol=insertarNodo(arbol,id(15));
    arbol=insertarNodo(arbol,id(15));
    arbol=insertarNodo(arbol,id(15));
    arbol=insertarNodo(arbol,id(15));
    arbol=insertarNodo(arbol,id(15));
    arbol=insertarNodo(arbol,id(15));*/



    //graficarLista(tipoRecorrido);
    system("pause");
    cout<<endl;

    /*imprimirArbol(arbol,0);
    cout<<endl;*/

    system("pause");

    /*crearNodosGrafico(arbol);
    armarAVL(arbol,arbol);
    dot+="}";
    cout<<dot;

    graficarAVL();*/

    menuPrincipal(cubo);



    return 0;
}
