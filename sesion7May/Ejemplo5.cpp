#include<iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int num, cont = 0;
    int i = 1;
    cout << "Dime un numero:";
    cin >> num;
    while ( i <= num)
    {
        if (num % i == 0 )
        {
            cont++;
        }
        i++;
    }
    if (cont == 2)
    {
        cout << "El numero es primo" << endl;
    } else
    {
        cout << "El numero no es primo" << endl;
    }
    return 0;
}
