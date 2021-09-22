#include <iostream>
#include <vector>

/*
Ejemplos: 
 8 2 5 1 5 7 9 5 7 9 -1
 output:
 5 7 9

 6 2 5 1 8 6 5 1 8 6 5 4 -1
 output:
 1 8 6 5
*/

/*
funcion que devuelve un vector con el bucle encontrado 
*/
std::vector<int> buscarbucle(std::vector<int> v) {
    std::vector<int> rpta;

    bool vacio = true;
    for (int i = 1; i < v.size(); i++) {
        bool encontrado = false;
        int j;
        for (j = 0; j < i; j++) { 
            if (v[i] == v[j]) { //posible bucle encontrado
                encontrado = true;
                break;
            }
        }
        if (encontrado&&vacio) { //asegurando que nuestro vector rpta este vacio y tengamos un bucle
            int bucleiter=0;
            for (int k = j; k < i; k++) {
                if (v[k] == v[i + bucleiter]) {
                    rpta.push_back(v[k]);
                    bucleiter++;
                    vacio = false;
                }
                else {
                    rpta.clear();
                    vacio = true;
                }
            }
        }
    }
    return rpta;
}

int main() {
    std::vector<int> v;
    std::vector<int> rpta;
    int end=0;
    while (end != -1) {
        std::cin >> end;
        v.push_back(end);
    }
    rpta = buscarbucle(v);
    for (int i : rpta) {
        std::cout << i << " ";
    }
}
