//
// Created by Brayan Durazo on 5/26/18.
//

#ifndef PROYECTO_ARBOLINB_COLA_H
#define PROYECTO_ARBOLINB_COLA_H

#include <iostream>
#include "Excepcion.h"

template <typename Tipo>
class Cola;

template <typename Tipo>
std::ostream& operator<<(std::ostream & salida, const Cola<Tipo>& c);

template <typename Tipo>
class Cola{

    friend std::ostream & operator<< <>(std::ostream & salida, const Cola<Tipo> &c);

public:
    /**
     * @brief Constructo de la clase Cola default, asigna numero de elementos a 0, los puntero Primero y Ultimo en NULL.
     */
    Cola();
    /**
     * @brief Destrcutor, destruye la cola, vaciandola por completo.
     */
    ~Cola();
    /**
     * @brief Constructor copia de la clase cola
     * @param c, referencia constante de un objeto tipo Cola
     */
    Cola(const Cola& c);
    /**
     * @brief Sobre carga del operador igual, para ser utilizado entre instancias de esta clase.
     * @param p , referencia constante de un objeto tipo Cola
     * @return una nueva instancia de la clase Cola, que es una copia de la que se recibio en el parametro.
     */
    Cola &operator =(const Cola &p);

    /**
     * @brief Agrega un elemento a la cola, este se designara en el ultimo espacio, si está vacía la cola, se toma como primero y último
     * @param valor , es el valor que tendra el elemento agregado.
     */
    void AgregarElemento(Tipo valor);
    /**
     * @brief Elimina un elemento de la cola, el que este designado en el primer lugar (puntero Primero).
     * @return El valor que se encuentra en el elemento que se eliminará.
     */
    Tipo EliminarElemento();
    /**
     * @brief Elimina todos los elementos que se encuentran en la cola.
     */
    void Vaciar();
    /**
     * @brief Informa sobre el estado de la cola, específicamente si se encuentra vacia.
     * @return un booleano sobre si la pila está vacia
     */
    bool EstaVacia();
    /**
     * @brief Da a conocer sobre el valor que se encuentra en el primer elemento de la cola
     * @return el valor que tiene el elemento al que apunta Primero
     */
    Tipo obtenerPrimero();
    /**
     * @brief Da a conocer el numero de elementos que tiene la cola
     * @return el numero de elementos que tiene la cola
     */
    int obtenerTamanio();

private:

    /**
     * Estructura Elemento, que cuenta con un valor y un puntero a otro elemento.
     */
    struct Elemento{
        explicit Elemento(Tipo _valor, Elemento* _siguiente = NULL) : valor(_valor), siguiente(_siguiente){};

        Tipo valor;
        Elemento * siguiente;
    };

    int numElementos;
    Elemento *Primero;
    Elemento *Ultimo;
};

template<typename Tipo>
Cola<Tipo>::Cola() : numElementos(0), Primero(NULL), Ultimo(NULL){

}

template<typename Tipo>
Cola<Tipo>::~Cola() {
    Vaciar();
}

template<typename Tipo>
Cola<Tipo>::Cola(const Cola &c) : numElementos(0), Primero(NULL), Ultimo(NULL) {
    *this = c;
}

template<typename Tipo>
void Cola<Tipo>::AgregarElemento(Tipo valor) {
    Elemento * nuevo = new Elemento(valor);

    if(EstaVacia()){
        Primero = nuevo;
        Ultimo = nuevo;
    }else{
        Ultimo -> siguiente = nuevo;
        Ultimo = nuevo;
    }
    numElementos++;
}

template<typename Tipo>
Tipo Cola<Tipo>::EliminarElemento() {
    if(EstaVacia()){
        throw Excepcion("No se puede eliminar elemento, ya que la cola se encuentra vacia");
    }

    Elemento * aux = Primero;
    Primero = Primero->siguiente;

    Tipo valor = aux -> valor;
    delete aux;
    numElementos--;

    if(numElementos == 0)
        Ultimo = NULL;

    return valor;
}

template<typename Tipo>
bool Cola<Tipo>::EstaVacia(){
    if(numElementos == 0)
        return true;
    else
        return false;
}

template<typename Tipo>
Tipo Cola<Tipo>::obtenerPrimero() {
    if(EstaVacia()){
        throw Excepcion("La cola se cuentra vacia.");
    }
    return Primero -> valor;
}

template<typename Tipo>
int Cola<Tipo>::obtenerTamanio() {
    return numElementos;
}

template<typename Tipo>
void Cola<Tipo>::Vaciar() {
    while(!EstaVacia()){
        EliminarElemento();
    }
}

template<typename Tipo>
Cola<Tipo> &Cola<Tipo>::operator=(const Cola &c) {
    if(this == &c) return *this;

    Vaciar();

    for(Elemento *aux = c.Primero; numElementos <= c.numElementos; aux = aux -> siguiente){
        AgregarElemento(aux -> valor);
        if(aux -> siguiente == NULL)
            break;
    }

    return *this;
}

template<typename Tipo>
std::ostream &operator<<(std::ostream &salida, const Cola <Tipo> &c) {
    if(c.Primero == NULL || c.Ultimo == NULL){
        salida << "La cola esta vacia";
        return salida;
    }

    struct Cola<Tipo>::Elemento * auxiliar = c.Primero; //Se pone el especificador struct para indicarle al preporcesador que elemento es una estructura, dentro de la clase cola

    salida << "Primero -> ";
    while(auxiliar != NULL){
        salida << "[" << auxiliar -> valor << "] , ";
        auxiliar = auxiliar -> siguiente;
    }
    salida << "\b\b<- ultimo.";

    return salida << std::endl;
}



#endif //PROYECTO_ARBOLINB_COLA_H
