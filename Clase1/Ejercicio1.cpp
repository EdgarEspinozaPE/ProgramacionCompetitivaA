#include <bits/stdc++.h>
/*
Ejemplos:
5 4 8 8 10
output: 80
56 8 123 19 12 79
output: 9717
*/

/*
Funcion que recibe el tamaño de la entrada y va identificando
los 2 numeros maximos.
*/
void maxproduct(int n) {
    int max1 = 0;
    int max2 = 0;
    for (int i = 0; i < n; i++) {
        int temp;
        std::cin >> temp;
        if (temp > max1) { //mayor numero ingresado
            max2 = max1;
            max1 = temp;
        }
        else if (temp > max2) //segundo mayor numero
            max2 = temp;
    }
    std::cout << max1 * max2;
}

int main()
{
    int n;
    std::cin >> n;
    maxproduct(n);
}
