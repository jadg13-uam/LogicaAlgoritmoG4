#include <iostream>
using namespace std;

main() {
    int num;
    cout << "ingresar un numero: ";
    cin >> num;
    int i = 0;

    while (i <= 12) {
        int resultado = i*num;
        cout << num << " * " << i << " = " << resultado << endl;
        i++;
    }

}