#include <iostream>
#include <string.h>
#include "variables.h"
#include <fstream>
#include <cstdlib>
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
void editar();
void eliminar();
void buscarCiudad();
void showData(CITY &city);
int menu();
void principal();


//manejo de archivos
int loadCities();
void writeFile(const CITY &city);

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
    pos = loadCities();
    do{
        op = menu();
        switch(op){
            case 1:
                pedirDato();
                break;
            case 2:
                editar();
                break;
            case 3:
                eliminar();
                break;
            case 4:
                mostrarTodo();
                break;
            case 5:
                buscarCiudad();
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
    if(findPos(city.id)!=-1){
        cout << "Registro ya existe..." << endl;
        return;
    }
    cout << "NOMBRE: ";
    scanf(" %[^\n]", city.name);
    cout << "DESCRIPCION: ";
    scanf(" %[^\n]", city.description);
    addCity(&city);
    writeFile(city);
}

void mostrarTodo(){
    cout << "Mostrar Registros\n";
    for(int i =0; i < pos; i++){
        showData(cities[i]);
    }
}

void editar(){
    CITY city;
    int id;
    cout << "ID: ";
    cin >>id;
    if(findPos(id)==-1){
        cout << "Registro no existe..." << endl;
        return;
    }
    city = findCity(id);
    cout << "Nombre: " ;
    scanf(" %[^\n]", city.name);
    cout << "Descripcion: ";
    scanf(" %[^\n]", city.description);
    updateCity(&city, id);
    cout << "Registro actualizado...\n";
}

void eliminar() {
    int id = 0;
    if(pos == 0){
        cout << "No hay nada que eliminar\n";
        return;
    }
    cout << "ID de ciudad a eliminar: ";
    cin >> id;
    if(findPos(id)==-1){
        cout << "Registro no existe..." << endl;
        return;
    }
    destroyCity(id);

    cout << "Ciudad eliminada\n";
}

void buscarCiudad() {
    int id = 0;
    cout << "ID de ciudad a buscar: ";
    cin >> id;
    if(findPos(id)==-1){
        cout << "Registro no existe..." << endl;
        return;
    }

    CITY city = findCity(id);
    int x = findPos(id);

    cout << "\nCiudad #" << x+1 << ":\n";
    showData(city);
    
}

void showData(CITY &city){
    cout << "ID: " << city.id << endl;
    cout << "Nombre: " << city.name << endl;
    cout << "Descripcion: " << city.description << endl;
}

int loadCities(){
    ifstream archivo("cities.txt");
    if(archivo.fail()){
        return 0;
    }
    int i = 0;
    while(archivo >> cities[i].id){
        archivo.ignore();
        archivo.getline(cities[i].name, 30);
        archivo.getline(cities[i].description, 100);
        i++;
    }
    archivo.close();
    return i;
}
void writeFile(const CITY &city){
    ofstream archivo;

    archivo.open("cities.txt", ios::app);

    if(archivo.fail()){
        cout << "No se puede abrir archivo" << endl;
        exit(1);
    }
    
    archivo << city.id << endl;
    archivo << city.name << endl;
    archivo << city.description << endl;
    archivo.close();

}
