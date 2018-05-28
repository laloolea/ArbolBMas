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

template<typename Tipo>
ArbolBMas<Tipo>::ArbolBMas () {

}

template<typename Tipo>
ArbolBMas<Tipo>::ArbolBMas (const ArbolBMas<Tipo> &a) {
    *this= a;
}

template<typename Tipo>
ArbolBMas<Tipo> &ArbolBMas<Tipo>::operator= (const ArbolBMas<Tipo> &a) {
    return <#initializer#>;
}

template<typename Tipo>
ArbolBMas<Tipo>::~ArbolBMas () {
    Vaciar();
}

template<typename Tipo>
void ArbolBMas<Tipo>::Vaciar () {
    raiz->Vaciar ();
}

template<typename Tipo>
bool ArbolBMas<Tipo>::EstaVacio () {
    return raiz== NULL;
}


#endif //PROYECTO_ARBOLINB_ARBOLB_H
