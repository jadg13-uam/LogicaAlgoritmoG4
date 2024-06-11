/*
Diseña un programa que solicite al usuario ingresar dos matrices y
luego realice la multiplicación de matrices. Asegúrate de que las
dimensiones de las matrices sean compatibles para la multiplicación y
muestra la matriz resultante.

*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Declarar variables para las matrices y sus dimensiones
    int filas1, columnas1, filas2, columnas2;

    // Solicitar al usuario las dimensiones de la primera matriz
    cout << "--> Ingrese el número de filas de la primera matriz: ";
    cin >> filas1;
    cout << "--> Ingrese el número de columnas de la primera matriz: ";
    cin >> columnas1;

    // Crear la primera matriz e ingresar sus elementos
    vector<std::vector<int> > matriz1(filas1, vector<int>(columnas1));
    cout << "--> Ingrese los elementos de la primera matriz:" << endl;
    for (int i = 0; i < filas1; ++i) {
        for (int j = 0; j < columnas1; ++j) {
            cout << "Elemento [" << i << "][" << j << "]: ";
            cin >> matriz1[i][j];
        }
    }

    // Solicitar al usuario las dimensiones de la segunda matriz
    cout << "--> Ingrese el número de filas de la segunda matriz: ";
    cin >> filas2;
    cout << "--> Ingrese el número de columnas de la segunda matriz: ";
    cin >> columnas2;

    // Verificar si las dimensiones de las matrices son compatibles para la multiplicación
    if (columnas1 != filas2) {
        cout << "Las dimensiones de las matrices no son compatibles para la multiplicación." << endl;
        return 1;
    }

    // Crear la segunda matriz e ingresar sus elementos
    vector<vector<int> > matriz2(filas2, vector<int>(columnas2));
    cout << "--> Ingrese los elementos de la segunda matriz:" << endl;
    for (int i = 0; i < filas2; ++i) {
        for (int j = 0; j < columnas2; ++j) {
            cout << "Elemento [" << i << "][" << j << "]: ";
            cin >> matriz2[i][j];
        }
    }

    // Realizar la multiplicación de matrices
    vector<vector<int> > resultado(filas1, vector<int>(columnas2));
    for (int i = 0; i < filas1; ++i) {
        for (int j = 0; j < columnas2; ++j) {
            for (int k = 0; k < columnas1; ++k) {
                resultado[i][j] += matriz1[i][k] * matriz2[k][j];
            }
        }
    }

    // Mostrar la matriz resultante
    cout << "--> La matriz resultante de la multiplicación es:" << endl;

    for (int i = 0; i < filas1; ++i) {
        for (int j = 0; j < columnas2; ++j) {
            cout << resultado[i][j] << ", ";
        }
        cout << endl;
    }

    return 0;
}

