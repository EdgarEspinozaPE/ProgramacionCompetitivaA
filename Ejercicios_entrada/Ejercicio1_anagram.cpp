#include <iostream>
/*
Ejemplo
hola aloh
output 1

computo
otupcon
output 0
*/


//Funcion booleana para determinar si 2 palabras son anagramas
bool isanagram(std::string p1, std::string p2) {
    bool isanagram = true;
    int i = 0;
    if (p1.size() != p2.size()) //descarte rapidpo tamaño distinto
        return false;
    else {
        while (isanagram && i < p1.size()) {
            if (p1[i] != p2[p2.size() - i - 1]) { //comparando cada item
                isanagram = false;
                break;
            }
            i++;
        }
        return isanagram;
    }
}

int main() {
    std::string p1;
    std::string p2;
    std::cin >> p1;
    std::cin >> p2;
    std::cout << isanagram(p1, p2);
}