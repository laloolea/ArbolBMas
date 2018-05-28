#include <iostream>
#include "Nodo.h"

using namespace std;

int main() {
    Nodo<int> prueba(5);
    Nodo<int> *aux;

    prueba.AgregarElemento(7);
    prueba.AgregarElemento(5);
    prueba.AgregarElemento(3);
    prueba.AgregarElemento(8);
    prueba.AgregarElemento(10);

    cout << prueba << endl;
    Nodo<int> pruebita = prueba;
    cout << "Imprimiendo copia: " << endl;
    cout << pruebita;

    cout << "\nEliminando elemento 7 del nodo original..." << endl;
    prueba.EliminarElemento(7);

    cout << "\nOriginal..." << endl;
    cout << prueba;
    cout << "\nCopia..." << endl;
    cout << pruebita;

    cout << "\nVaciando copia..." << endl;
    pruebita.Vaciar();
    cout << "\nOriginal..." << endl;
    cout << prueba;
    cout << "\nCopia..." << endl;
    cout << pruebita;

    aux = new Nodo<int>(5);

    aux->AgregarElemento(15);
    aux->AgregarElemento(11);
    aux->AgregarElemento(13);
    aux->AgregarElemento(12);
    aux->AgregarElemento(14);

    cout << "\nImprimiendo pruebita...\n" << *aux << endl << endl;

    cout << "Imprimiendo nodo Prueba ya con su puntero 1: " << endl;

    prueba.AgregarPuntero(aux);

    cout << prueba << endl << *prueba.punteros[0];

    cout << "\nEliminando Puntero de prueba..." << endl;

    cout << prueba.EliminarPuntero(0) << endl;

    cout << "\nALKSDBFAS" << endl;

    cout << prueba << endl << *prueba.punteros[0];

    return 0;
}

/* MAIN DE PRUEBA PARA NODO

*/