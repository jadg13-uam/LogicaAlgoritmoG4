#include <iostream>
#include <string.h>
#include "variables.h"
using namespace std;

CITY cities[MAX_REG];
int pos = 0;

//funciones 

void addCity(CITY *city);
CITY findCity(int id);
int findPos(int id);
void updateCity(CITY *city, int id);
void destroyCity(int id);

void pedirDato();
void mostrarTodo();
int menu();
void principal();

void addCity(CITY *city){
    cities[pos] = *city;
    pos++;
}

CITY findCity(int id){
    CITY city;
    for(int i =0; i<pos; i++){
        if(cities[i].id == id){
            return cities[i];
        }
    }
    return city;
}

int findPos(int id){
    for(int i = 0; i < pos; i++){
        if(cities[i].id == id) return i;
    }
    return -1;
}

void updateCity(CITY *city, int id){
    int position = findPos(id);
    strcpy(cities[position].name, city->name);
    strcpy(cities[position].description, city->description);
}

void destroyCity(int id){
    int position = findPos(id);
    for(int i = position; i<pos-1; i++){
        cities[i] = cities[i+1];
    }
    CITY c;
    cities[pos-1] = c;
    pos--;
}

int menu(){
    int op;
    cout << "Menu\n";
    cout << "1. Agregar \n";
    cout << "2. Editar \n";
    cout << "3. Eliminar\n";
    cout << "4. Mostrar Todos \n";
    cout << "5. Buscar \n";
    cout << "6. Salir\n";
    cout << "Opción: ";
    cin >> op;
    return op;
}

void principal(){
    int op;
    do{
        op = menu();
        switch(op){
            case 1:
                pedirDato();
                break;
            case 4:
                mostrarTodo();
                break;
            case 6:
                cout << "Adios tierno...\n";
                break;
            default:
                cout << "Deberías de leer más. Solo hay 6 opciones. \n";
                break;
        }
    }while(op != 6);
}

void pedirDato(){
    CITY city;
    cout << "Datos de la Ciudad" << endl;
    cout << "ID: ";
    cin >> city.id;
    cout << "NOMBRE: ";
    scanf(" %[^\n]", city.name);
    cout << "DESCRIPCION: ";
    scanf(" %[^\n]", city.description);
    addCity(&city);
}

void mostrarTodo(){
    cout << "Mostrar Registros\n";
    for(int i =0; i < pos; i++){
        cout << cities[i].id << endl;
        cout << cities[i].name << endl;
        cout << cities[i].description << endl;
    }
}