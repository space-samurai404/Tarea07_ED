// Dictionary.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>
#include "Dictionary.h"
#include "UnsortedListDictionary.h"
#include <stdexcept>
#include "BSTree.h"
#include "AVLTree.h"

using std::runtime_error;
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::exception;
int main()
{

    srand(time(0));
    AVLTree<int>* arbolito = new AVLTree<int>();

    for (int i = 0; i < 10; i++)
    {
        try
        {
            arbolito->insert(rand() % 100);
        }

        catch (runtime_error& e)
        {
            cout << e.what() << endl;
        }

    }
    arbolito->print();
    srand(time(0));
    AVLTree<int>* avl = new AVLTree<int>();
    BSTree<int>* bst = new BSTree<int>();
    for (int i = 0; i < 1000; i++) {
        try {
            int r = rand();
            avl->insert(i);
            bst->insert(i);
        }
        catch (runtime_error& e) {
            cout << e.what() << endl;
        }
    }

   
}

//int dicrionary() {
//    Dictionary<string, string>* elementos;
//    elementos = new UnsortedListDictionary<string, string>();
//    elementos->insert("H", "hidrogeno");
//    elementos->insert("He", "helio");
//    elementos->insert("C", "carbono");
//    elementos->print();
//
//    try {
//        elementos->insert("H", "Hagua");
//    }
//    catch (exception& e) {
//        cout << e.what() << endl;
//    }
//}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
