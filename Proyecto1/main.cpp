#include <QCoreApplication>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "matriz.h"
#include "windows.h"
#define _CRT_SECURE_NO_DEPRECATE


using namespace std;
void menuPrincipal(Matriz*);

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
        menuPrincipal(matriz);
    }else{
        system("cls");
        system("color c0");
        cout<<"Credenciales incorrectas, intente de nuevo"<<endl;
        system("pause");
        menuPrincipal(matriz);
    }
}

void loginTrabajador(Matriz *matriz){
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
    if(matriz->buscarEmpleado(usr,psw,empresa,depto)){
        system("cls");
        system("color 02");
        cout<<"Bienvenido, "<<usr<<endl;
        system("pause");
        menuPrincipal(matriz);
    }else{
        system("cls");
        system("color c0");
        cout<<"Lo sentimos, pero "<<usr<<" no se ha encontrado dentro de los usuarios registrados"<<endl;
        system("pause");
        menuPrincipal(matriz);
    }
}

void menuPrincipal(Matriz *cubo)
{
    int opcion;
    //system("cls");
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

void menuAdmin(){

}




int main()
{srand(time(NULL));
    Matriz *cubo=new Matriz();

    cubo->insertarElemento("Mynor", 1, "MAX", "Guatemala","mynor1");
    cubo->insertarElemento("Susan", 2, "hp", "Jutiapa","susan2");
    cubo->insertarElemento("Susel", 3, "hp", "Jalapa","susel3");
    cubo->insertarElemento("Roxana", 4, "Walmart", "Jalapa","roxana4");
    cubo->insertarElemento("Andrea", 5, "Walmart", "Jalapa","andrea5");
    cubo->insertarElemento("Andrea", 9, "Walmart", "Jalapa","Andre9");
    cubo->insertarElemento("Sebas", 6, "Walmart", "Jalapa","sebas6");
    cubo->insertarElemento("Andres", 7, "hp", "Guatemala","andres7");
    cubo->insertarElemento("Willy", 8, "MAX", "Jalapa","willy7");

    cubo->recorrerXY();

    menuPrincipal(cubo);



    return 0;
}
