#include <iostream>

using namespace std;

int main () {
    int i;
    
        int numero;
        cin >> numero;
        char *romanos[] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
        int arabicos[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
        // acha a quantidade de elementos no array
        int indice = (sizeof(arabicos) / sizeof(arabicos[0])) - 1;
        while (numero > 0) {
            if (numero >= arabicos[indice]) {
                cout << romanos[indice];
                numero -= arabicos[indice];
            } else {
                indice--;
            }
        }
        cout << endl;
        return 0;
}