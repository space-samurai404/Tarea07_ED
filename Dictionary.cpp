// Dictionary.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>
#include "Dictionary.h"
#include "UnsortedListDictionary.h"
#include <stdexcept>
#include "BSTree.h"
#include "BSTDictionary.h"
#include "AVLTree.h"
#include "ArrayList.h"

using std::runtime_error;
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::exception;
int main()
{
    BSTDictionary<int, string> d1;
    BSTDictionary<int, string> d2;
    int op;
    int opd;
    int k;
    int n;
    bool menu;
    string v;
    cout << "Contenido de diccionario 1:" << endl;
    d1.print();
    cout << "Contenido de diccionario 2:" << endl;
    d2.print();
    
    menu = true;
    while (menu) {
        cout << "-----Menu-----" << endl;
        cout << "1). Mostrar el contenido de la matriz" << endl;
        cout << "2). insert" << endl;
        cout << "3). getValue" << endl;
        cout << "4). setValue" << endl;
        cout << "5). contains" << endl;
        cout << "6). clear" << endl;
        cout << "7). getKeys" << endl;
        cout << "8). getValues" << endl;
        cout << "9). update" << endl;
        cout << "10).zip" << endl;
        cout << "13) Salir." << endl;
        cin >> op;

        switch (op) {
        case 1:
            cout << "Contenido de diccionario 1:" << endl;
            d1.print();
            cout << "Contenido de diccionario 2:" << endl;
            d2.print();
            break;

        case 2:
            cout << "En cual diccionario desea hacer el insert" << endl << "1. d1" << endl << "2. d2" << endl;
            cin >> opd;
            cout << "¿Cual es su llave k?" << endl;
            cin >> k;
            cout << "¿Cual es su valor v?" << endl;
            cin >> v;

            if (opd == 1) {
                d1.insert(k, v);
            }
            if (opd == 2) {
                d2.insert(k, v);
            }
            break;

        case 3:
            cout << "En cual diccionario desea hacer el remove" << endl << "1. d1" << endl << "2. d2" << endl;
            cin >> opd;
            cout << "¿Cual es su llave k?" << endl;
            cin >> k;

            if (opd == 1) {
                cout << "Elemento removido: " << d1.remove(k) << endl;
            }
            if (opd == 2) {
                cout << "Elemento removido: " << d2.remove(k) << endl;
            }
            break;

        case 4:
            cout << "En cual diccionario desea hacer el getValue" << endl << "1. d1" << endl << "2. d2" << endl;
            cin >> opd;
            cout << "¿Cual es su llave k?" << endl;
            cin >> k;

            if (opd == 1) {
                cout << "Valor de diccionario 1: " << d1.getValue(k) << endl;
            }
            if (opd == 2) {
                cout << "Valor de diccionario 1: " << d2.getValue(k) << endl;
            }
            break;

        case 5:
            cout << "En cual diccionario desea hacer el setValue" << endl << "1. d1" << endl << "2. d2" << endl;
            cin >> opd;
            cout << "¿Cual es su llave k?" << endl;
            cin >> k;
            cout << "¿Cual es su valor v?" << endl;
            cin >> v;

            if (opd == 1) {
                d1.setValue(k, v);
            }
            if (opd == 2) {
                d2.setValue(k, v);
            }
            break;

        case 6:
            cout << "En cual diccionario desea hacer el contains" << endl << "1. d1" << endl << "2. d2" << endl;
            cin >> opd;
            cout << "¿Cual es su llave k?" << endl;
            cin >> k;
      

            if (opd == 1) {
                if (d1.contains(k)) {
                    cout << "El diccionario 1 si contiene el elemento" << endl;
                }
                else {
                    cout << "El diccionario 1 no contiene el elemento" << endl;
                }
            }
            if (opd == 2) {
                if (d2.contains(k)) {
                    cout << "El diccionario 2 si contiene el elemento" << endl;
                }
                else {
                    cout << "El diccionario 2 no contiene el elemento" << endl;
                }
            }
            break;

        case 7:
            cout << "En cual diccionario desea hacer el clear" << endl << "1. d1" << endl << "2. d2" << endl;
            cin >> opd;

            if (opd == 1) {
                d1.clear();
            }
            if (opd == 2) {
                d2.clear();
            }
            break;

        case 8:
            cout << "En cual diccionario desea hacer el getKeys" << endl << "1. d1" << endl << "2. d2" << endl;
            cin >> opd;

            if (opd == 1) {
                d1.getKeys()->print();
            }
            if (opd == 2) {
                d2.getKeys()->print();
            }
            break;

        case 9:
            cout << "En cual diccionario desea hacer el getValues" << endl << "1. d1" << endl << "2. d2" << endl;
            cin >> opd;

            if (opd == 1) {
                d1.getValues()->print();
            }
            if (opd == 2) {
                d2.getValues()->print();
            }
            break;

        case 10:
            cout << "En cual diccionario desea hacer el update" << endl << "1. d1" << endl << "2. d2" << endl;
            cin >> opd;

            if (opd == 1) {
                d1.update(d2);
            }
            if (opd == 2) {
                d2.update(d1);
            }
            break;

        case 11:
            cout << "En cual diccionario desea hacer el zip" << endl << "1. d1" << endl << "2. d2" << endl;
            cin >> opd;
            cout << "¿Cuantos elementos desea ingresar en keys?" << endl;
            cin >> n;
            ArrayList<int> keys(n);
            ArrayList<string> values(n);
            cout << "Ingrese las llaves:" << endl;
            for (int i = 0; i < n; i++) {
                
                cin >> k;
                keys.append(k);
            }
            cout << "Ingrese los valores:" << endl;
            for (int i = 0; i < n; i++) {
                cin >> v;
                values.append(v);
            }
            if (opd == 1) {
                d1.zip(&keys, &values);
            }
            if (opd == 2) {
                d2.zip(&keys, &values);
            }
            break;

        case 12:
            menu = false;
            break;
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
