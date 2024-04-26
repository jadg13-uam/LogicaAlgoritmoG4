/*Leer x cantidad de numeros e imprimir
la suma de dichos numeros*/
#include <iostream>

using namespace std;

#define MAX 5

// Variables globales
int nums[MAX];
int pos = 0;

void agregarNum(int num);
int sumar(int suma, int elemAct);

void agregarNum(int num)
{
    if (pos < MAX)
    {
        nums[pos] = num;
        pos++;
    }
    else
    {
        cout << "No hay espacio para almacenar " << num << endl;
    }
}

int sumar(int suma, int elemAct)
{
    if (elemAct == -1)
    {
        return suma;
    }

    suma =  suma + nums[elemAct];
    //elemAct--;
    sumar(suma, elemAct - 1);
}

void menu()
{
    int op, num, suma = 0;
    cout <<"Elementos guardados: "<< pos << endl;
    cout << "1. Ingresar numero. \n";
    cout << "2. Sumar. \n";
    cout << "3. Salir. \n";
    cout << "Digite su opcion: ";
    cin >> op;
    switch (op)
    {
    case 1:
        cout << "Agregar numero.\n";
        cout << "Dime un numero: ";
        cin >> num;
        agregarNum(num);
        for(int i = 0; i<pos; i++) cout << nums[i] << endl;
        break;
    case 2:
        cout << "Sumar: " << endl;
         for(int i = 0; i<pos; i++) cout << nums[i] << endl;
        cout << "La suma es " << sumar(suma, pos - 1) << endl;
        break;
    case 3:
        cout << "Salir" << endl;
        break;
    default:
        cout << "Opcion invalida...";
        break;
    }
    if (op != 3)
    {
        menu();
    }
}

main()
{
    menu();
}
