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
void menuCliente(Matriz*,Nodo*,string,string);

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

void menuCliente(Matriz* cubo,Nodo *usuario,string empresa,string depto){
    int opcion;
    system("cls");
    system("color 07");
    cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"------------------------------------------- MENU DE "<<usuario->nombre<< " ----------------------------------------------"<<endl;
    cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"1. Agregar un nuevo activo."<<endl;
    cout<<"2. Eliminar un activo"<<endl;
    cout<<"3. Modificar un activo."<<endl;
    cout<<"4. Rentar un activo."<<endl;
    cout<<"5. Ver activos rentados."<<endl;
    cout<<"6. Ver mis activos rentados"<<endl;
    cout<<"7. Devolver un activo rentado"<<endl;
    cout<<"8. Cerrar sesion."<<endl;
    cout<<"Ingrese una de las opciones disponibles:"<<endl;
    cin>>opcion;
    switch (opcion){
    case 1:
    {
        system("cls");
        system("color 07");
        cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
        cout<<"------------------------------------------- CREACION DE UN NUEVO ACTIVO -----------------------------------------------"<<endl;
        cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
        cout<<"Ingrese el nombre de su nuevo activo:"<<endl;
        string nombre="";
        while(nombre=="")
        {getline(cin,nombre);}
        cout<<"Ingrese una pequenia descripcion de su nuevo activo:"<<endl;
        string descripcion;
        getline(cin,descripcion);
        try {
            string nuevoID=id(15);
            usuario->arbolPersonal=cubo->insertarNodo(usuario->arbolPersonal,nuevoID,nombre,descripcion);
            system("color 02");
            cout<<"El activo se ha guardado correctamente, su ID es: "<<nuevoID<<endl;
            system("pause");
            menuCliente(cubo,usuario,empresa,depto);
            break;
        } catch (exception ex) {
            system("cls");
            system("color c0");
            cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
            cout<<"-------------------------------------------------- ERROR CRITICO! -----------------------------------------------------"<<endl;
            cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
            cout<<"Se ha producido un error al ingresar los datos, intente de nuevo o pruebe reiniciando la aplicacion."<<endl;
            system("pause");
            menuCliente(cubo,usuario,empresa,depto);
            break;
        }
        break;
    }
    case 2:

    {   if(usuario->arbolPersonal!=nullptr){
        system("cls");
        cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
        cout<<"-------------------------------------------------- ELIMINAR ACTIVO ----------------------------------------------------"<<endl;
        cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
        cout<<"A continuacion se muestran sus activos, escoja el que desea eliminar e ingrese su ID para continuar:"<<endl;
        string idAEliminar;
        cubo->inOrden(usuario->arbolPersonal);
        cout<<"Si desea cancelar la operacion, ingrese 0."<<endl;
        cin>>idAEliminar;
        if(idAEliminar!="0")
        {
            try {
                cubo->eliminarnodoAVL(usuario->arbolPersonal,idAEliminar);
                system("cls");
                system("color 02");
                cout<<"El dato se ha eliminado correctamente."<<endl;
                system("pause");
                menuCliente(cubo,usuario,empresa,depto);
                break;
            } catch (exception ex) {
                system("cls");
                system("color c0");
                cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
                cout<<"-------------------------------------------------- ERROR CRITICO! -----------------------------------------------------"<<endl;
                cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
                cout<<"Se ha producido un error al eliminar los datos, intente de nuevo o pruebe reiniciando la aplicacion."<<endl;
                cout<<"*** CONSEJO: puede seleccionar el ID correspondiente, pulsar Ctrl+C para copiar y luego pulsar Ctrl+V para pegar y evitar estas fallas. ***"<<endl;
                system("pause");
                menuCliente(cubo,usuario,empresa,depto);
                break;
            }
        }else{
            menuCliente(cubo,usuario,empresa,depto);
            break;
        }

        }else{
            system("cls");
            system("color 60");
            cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
            cout<<"--------------------------------------------------- SIN ACTIVOS! ------------------------------------------------------"<<endl;
            cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
            cout<<"Esta cuenta todavia no cuenta con activos."<<endl;
            system("pause");
            menuCliente(cubo,usuario,empresa,depto);
        }
        break;}
    case 3:
        if(usuario->arbolPersonal!=nullptr){
                system("cls");
                cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
                cout<<"-------------------------------------------------- MODIFICAR ACTIVO ---------------------------------------------------"<<endl;
                cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
                cout<<"A continuacion se muestran sus activos, escoja el que desea modificar e ingrese su ID para continuar:"<<endl;
                string idAModificar="";
                cubo->inOrden(usuario->arbolPersonal);
                cout<<"Si desea cancelar la operacion, ingrese 0."<<endl;
                while(idAModificar=="")
                {cin>>idAModificar;}
                if(idAModificar!="0")
                {
                    try {
                        string nuevaDesc="";
                        cout<<"Ingrese una nueva descripcion para el activo a modificar: ";
                        while(nuevaDesc==""){
                            getline(cin,nuevaDesc);
                        }
                        cubo->modificarNodoAVL(usuario->arbolPersonal,idAModificar,nuevaDesc);
                        system("color 02");
                        cout<<"ID del activo modificado: "<<idAModificar<<" || Nueva descripcion: "<<nuevaDesc<<endl;
                        cout<<"Verifique que el activo haya sido modificado correctamente, en caso de no ser asi, verifique que haya imgresado correctamente su ID."<<endl;
                        system("pause");
                        menuCliente(cubo,usuario,empresa,depto);
                        break;
                    } catch (exception ex) {
                        system("cls");
                        system("color c0");
                        cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
                        cout<<"-------------------------------------------------- ERROR CRITICO! -----------------------------------------------------"<<endl;
                        cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
                        cout<<"Se ha producido un error al eliminar los datos, intente de nuevo o pruebe reiniciando la aplicacion."<<endl;
                        cout<<"*** CONSEJO: puede seleccionar el ID correspondiente, pulsar Ctrl+C para copiar y luego pulsar Ctrl+V para pegar y evitar estas fallas. ***"<<endl;
                        system("pause");
                        menuCliente(cubo,usuario,empresa,depto);
                        break;
                    }
                }else{
                    menuCliente(cubo,usuario,empresa,depto);
                    break;
                }

                }else{
                    system("cls");
                    system("color 60");
                    cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
                    cout<<"--------------------------------------------------- SIN ACTIVOS! ------------------------------------------------------"<<endl;
                    cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
                    cout<<"Esta cuenta todavia no cuenta con activos para modificar."<<endl;
                    system("pause");
                    menuCliente(cubo,usuario,empresa,depto);
                    break;
                }
                break;
    case 4:
    {system("cls");
        string idARentar="";
        cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
        cout<<"-------------------------------------------------- RENTAR UN ACTIVO ---------------------------------------------------"<<endl;
        cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
        cout<<"A continuacion se muestran los activos que se encuentran disponibles para su renta. Ingrese el ID del activo que desea para continuar:"<<endl;
        cubo->listarActivos(cubo,usuario);
        cout<<"Ingrese un ID para seleccionar ese activo y rentarlo, si desea cancelar, escriba 0:";
        while(idARentar==""){
            getline(cin,idARentar);
        }
        if(idARentar=="0"){
            menuCliente(cubo,usuario,empresa,depto);
            break;
        }else{
            int tiempo;
            cout<<"Por cuanto tiempo desea rentar este activo?";
            while(tiempo==0){
                cin>>tiempo;
            }try {
                if(cubo->rentarActivo(cubo,idARentar,tiempo)){
                    insertarNodoLista(id(15),idARentar,usuario->nombre,empresa,depto,tiempo);
                    system("cls");
                    system("color 02");
                    cout<<"El activo ha sido rentado exitosamente."<<endl;
                    graficarLista(tipoRecorrido);
                    system("pause");
                    menuCliente(cubo,usuario,empresa,depto);
                    break;
                }
} catch (exception ex) {
                system("cls");
                system("color c0");
                cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
                cout<<"-------------------------------------------------- ERROR CRITICO! -----------------------------------------------------"<<endl;
                cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
                cout<<"Se ha producido un error al rentar un activo, intente de nuevo o pruebe reiniciando la aplicacion."<<endl;
                cout<<"*** CONSEJO: puede seleccionar el ID correspondiente, pulsar Ctrl+C para copiar y luego pulsar Ctrl+V para pegar y evitar estas fallas. ***"<<endl;
                system("pause");
                menuCliente(cubo,usuario,empresa,depto);
                break;

}
        }
        system("pause");}
        break;
    case 5:
        break;
    case 6:
        break;
    case 7:

    case 8:
        menuPrincipal(cubo);
        break;
    default:
        menuCliente(cubo,usuario,empresa,depto);
        break;
    }
}

void loginAdmin(Matriz *matriz){
    system("cls");
    system("color 07");
    cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"------------------------------------------- INICIANDO COMO ADMINISTRADOR ----------------------------------------------"<<endl;
    cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
    string usr="",psw;
    cout<<"Por favor, identifiquese para continuar: "<<endl;
    cout<<"Usuario:";
    while(usr=="")
    {getline(cin,usr);}
    cout<<endl<<"Contrasenia:";
    getline(cin,psw);
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
    string psw,empresa,depto;
    system("cls");
    system("color 07");
    cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"--------------------------------------------- INICIANDO COMO TRABAJADOR -----------------------------------------------"<<endl;
    cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
    matriz->recorrerXY();
    cout<<"Por favor, inicie sesion para continuar: \n";
    cout<<"Usuario:\n";
    string usr="";
    while(usr=="")
    {getline(cin,usr);}
    cout<<endl<<"Contrasenia:";
    getline(cin,psw);
    cout<<"Empresa:";
    getline(cin,empresa);
    cout<<endl<<"Departamento:";
    getline(cin,depto);
    if(matriz->buscarEmpleado(matriz,usr,psw,empresa,depto)){
        Nodo* sesion=matriz->localizarEmpleado(matriz,usr,psw,empresa,depto);
        system("cls");
        system("color 02");
        cout<<"Bienvenido, "<<usr<<endl;
        system("pause");
        menuCliente(matriz,sesion,empresa,depto);
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

        string usuario="",empresa,departamento,password;
        cout<<"Ingrese el nombre del nuevo usuario:"<<endl;
        while(usuario=="")
        {getline(cin,usuario);}
        cout<<"Ingrese la contrasenia del nuevo usuario:"<<endl;
        getline(cin,password);
        cout<<"Ingrese la empresa a la que pertenece el nuevo usuario:"<<endl;
        getline(cin,empresa);
        cout<<"Ingrese el departamento de la sucursal de la empresa en la que trabajara el nuevo usuario:"<<endl;
        getline(cin,departamento);
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

    /*nodoAVL *arbol=nullptr;
    arbol=insertarNodo(arbol,id(15));
    arbol=insertarNodo(arbol,id(15));
    arbol=insertarNodo(arbol,id(15));
    arbol=insertarNodo(arbol,id(15));
    arbol=insertarNodo(arbol,id(15));
    arbol=insertarNodo(arbol,id(15));
    arbol=insertarNodo(arbol,id(15));*/



    //graficarLista(tipoRecorrido);


    /*imprimirArbol(arbol,0);
    cout<<endl;*/



    /*crearNodosGrafico(arbol);
    armarAVL(arbol,arbol);
    dot+="}";
    cout<<dot;

    graficarAVL();*/

    menuPrincipal(cubo);



    return 0;
}
