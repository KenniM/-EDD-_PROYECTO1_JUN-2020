#include <QCoreApplication>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "matriz.h"
#include "nodoAVL.h"
#include "windows.h"
#define _CRT_SECURE_NO_DEPRECATE


using namespace std;

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

int main()
{srand(time(NULL));
    Matriz *cubo=new Matriz();
    int opcion;

    cubo->insertarElemento("Mynor","MAX", "Guatemala","mynor1");
    cubo->insertarElemento("Susan", "hp", "Jutiapa","susan2");
    cubo->insertarElemento("Susel", "hp", "Jalapa","susel3");
    cubo->insertarElemento("Roxana", "Walmart", "Jalapa","roxana4");
    cubo->insertarElemento("Andrea",  "Walmart", "Jalapa","andrea5");
    cubo->insertarElemento("Kenni",  "Glovo", "Guatemala","ken1");
    cubo->insertarElemento("Sebas", "Walmart", "Jalapa","sebas6");
    cubo->insertarElemento("Andres", "hp", "Guatemala","andres7");
    cubo->insertarElemento("Willy", "MAX", "Jalapa","willy7");

    cubo->recorrerXY();

    nodoAVL *arbol=nullptr;
    arbol=insertarNodo(arbol,id(15));
    arbol=insertarNodo(arbol,id(15));
    arbol=insertarNodo(arbol,id(15));
    arbol=insertarNodo(arbol,id(15));
    arbol=insertarNodo(arbol,id(15));
    arbol=insertarNodo(arbol,id(15));
    arbol=insertarNodo(arbol,id(15));

    imprimirArbol(arbol,0);
    cout<<endl;

    crearNodosGrafico(arbol);
    armarAVL(arbol,arbol);
    dot+="}";
    cout<<dot;

    /*while (true) {

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
        {
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
            if(cubo->cabecera->nombre==usr && cubo->cabecera->password==psw){
                system("cls");
                system("color 02");
                cout<<"Bienvenido, "<<usr<<endl;
                system("pause");
                system("cls");
                system("color 07");
                cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
                cout<<"---------------------------------------------- MENU DE ADMINISTRACION -------------------------------------------------"<<endl;
                cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
                cout<<"1. Crear nuevo usuario."<<endl;
                cout<<"2. Generar reporte de Matriz Dispersa."<<endl; //MOSTRARÁ SOLAMENTE CABECERAS Y PRIMEROS USUARIOS DE CADA SUCURSAL (X,Y)
                cout<<"3. Generar listado de usuarios de una sucursal."<<endl; //MOSTRARÁ LA PROFUNDIDAD DE UNA SUCURSAL (Z)
                cout<<"4. Reporte de Activos disponibles en un Departamento."<<endl;
                cout<<"5. Reporte de Activos disponibles en una Empresa."<<endl;
                cout<<"6. Reporte de Transacciones."<<endl;
                cout<<"7. Reporte de Activos por Usuario."<<endl;
                cout<<"8. Activos rentados por un usuario."<<endl;
                cout<<"9. Configurar orden de Transacciones."<<endl;
                cout<<"10. Regresar al Menu Principal."<<endl;
                cout<<"Ingrese una opcion para continuar:"<<endl;
                cin>>opcion;
                switch (opcion) {
                    case 1:
                {
                    system("cls");
                    cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
                    cout<<"-------------------------------------------- REGISTRANDO A UN TRABAJADOR -----------------------------------------------"<<endl;
                    cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
                    string usr,psw,empresa,depto;
                    cout<<"Por favor, ingrese los datos necesarios para continuar: "<<endl;
                    cout<<"Usuario:";
                    cin>>usr;
                    cout<<endl<<"Contrasenia:";
                    cin>>psw;
                    cout<<"Empresa:";
                    cin>>empresa;
                    cout<<endl<<"Departamento:";
                    cin>>depto;
                    if(!cubo->localizarEmpleado(usr,empresa,depto)){
                       cubo->insertarElemento(usr,empresa,depto,psw);
                    }else{
                        cout<<"Ya existe un usuario registrado dentro de la sucursal de: "<<empresa<<" en el departamento de "<<depto<<endl;
                    }

                    cubo->listarEmpleados(depto,empresa);
                    cubo->recorrerXY();
                    system("pause");
                    break;
                }
                    case 2:

                    break;
                    case 3:
                    ;
                case 4:
                    ;
                case 5:
                    ;
                case 6:
                    ;
                case 7:
                    ;
                case 8:
                    ;
                case 9:
                    ;
                case 10:
                break;
                default:
                    ;
                }
            }else{
                system("cls");
                system("color c0");
                cout<<"Credenciales incorrectas, intente de nuevo"<<endl;
                system("pause");
            }

            break;
        }
        case 2:
        {
            system("cls");
            cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
            cout<<"--------------------------------------------- INICIANDO COMO TRABAJADOR -----------------------------------------------"<<endl;
            cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
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
            if(cubo->buscarEmpleado(usr,psw,empresa,depto)){
                system("cls");
                system("color 02");
                cout<<"Bienvenido, "<<usr<<endl;
                system("pause");
            }else{
                system("cls");
                system("color c0");
                cout<<"Lo sentimos, pero "<<usr<<" no se ha encontrado dentro de los usuarios registrados"<<endl;
                system("pause");
            }
            break;
        }
        case 3:
            exit(0);
            break;
        default:
            break;
        }
    }*/






    return 0;
}
