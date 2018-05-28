//
// Created by Brayan Durazo on 5/26/18.
//

#ifndef PROYECTO_ARBOLINB_ARBOLB_H
#define PROYECTO_ARBOLINB_ARBOLB_H

#include "Cola.h"
#include "Nodo.h"


template <typename Tipo>
class ArbolBMas{
public:
    ArbolBMas();
    ArbolBMas(const ArbolBMas<Tipo> &a);
    ArbolBMas<Tipo>& operator=(const ArbolBMas<Tipo> &a);
    ~ArbolBMas();


    void Vaciar();
    bool EstaVacio();

private:
    int grado;
    Nodo *raiz;
    Cola<Nodo*> hojas;
};


#endif //PROYECTO_ARBOLINB_ARBOLB_H
