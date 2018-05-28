//
// Created by Brayan Durazo on 5/26/18.
//

#ifndef PROYECTO_ARBOLINB_NODO_H
#define PROYECTO_ARBOLINB_NODO_H


template <typename Tipo>
class Nodo;

template <typename Tipo>
std::ostream& operator<<(std::ostream & salida, const Nodo<Tipo>& n);

template <typename Tipo>
class Nodo{
    friend std::ostream & operator<< <>(std::ostream & salida, const Nodo<Tipo> &n);
public:
    Nodo(int tamanio = 3);
    Nodo(const Nodo<Tipo> &n);
    Nodo<Tipo>& operator=(const Nodo<Tipo> &n);
    ~Nodo();

    bool AgregarElemento(Tipo _valor);
    bool EliminarElemento(Tipo _valor);

    bool AgregarPuntero(Nodo *&n);
    bool EliminarPuntero(int indice);

    void Vaciar();
    bool EstaVacio() const;
    bool EstaLleno();

//private:
    int numElementos;
    int numPunteros;
    int capacidadElementos;
    bool esHoja;

    Tipo *elementos;
    Nodo **punteros;

    void Ordenar();
};

template<typename Tipo>
std::ostream &operator<<(std::ostream &salida , const Nodo<Tipo> &n) {
    if(n.EstaVacio()){
        return salida << "El nodo se encuentra deshabitado.";
    }

    for (int i = 0; i < n.numElementos; i ++) {
        salida << n.elementos[i] << " , ";
    }

    salida << "\b\b\b  ";
    return salida;
}

template<typename Tipo>
Nodo<Tipo>::Nodo(int tamanio) : numElementos(0), numPunteros(0), capacidadElementos(tamanio),esHoja(true){
    elementos = new Tipo[tamanio];
    punteros = new Nodo*[tamanio];

    for(int i = 0; i < tamanio ; ++i){
        punteros[i] = NULL;
    }
}

template<typename Tipo>
Nodo<Tipo>::Nodo(const Nodo<Tipo> &n) : numElementos(0) , numPunteros(0) , capacidadElementos(0) , esHoja(true),
elementos(NULL), punteros(NULL){
    *this = n;
}

template<typename Tipo>
Nodo<Tipo> &Nodo<Tipo>::operator=(const Nodo<Tipo> &n) {
    if(this == &n) return *this;

    if(!EstaVacio())
        Vaciar();

    numElementos = 0;
    numPunteros = n.numPunteros;
    capacidadElementos = n.capacidadElementos;
    elementos = new Tipo[n.capacidadElementos];
    punteros = new Nodo*[n.capacidadElementos];
    capacidadElementos = n.capacidadElementos;

    for(int i = 0; i < n.numElementos; ++i){
        AgregarElemento(n.elementos[i]);
    }
    for(int i = 0; i < n.numPunteros; ++i){
        AgregarPuntero(n.punteros[i]);
    }

    return *this;
}

template<typename Tipo>
Nodo<Tipo>::~Nodo() {
    Vaciar();
}

template<typename Tipo>
bool Nodo<Tipo>::AgregarElemento(Tipo _valor) {
    if(!EstaLleno()){
        elementos[numElementos++] = _valor;
        Ordenar();
        return true;
    }else
        return false;
}

template<typename Tipo>
bool Nodo<Tipo>::EliminarElemento(Tipo _valor) {
    bool encontrado = false;
    for(int i = 0; i < capacidadElementos; ++i){
        if(elementos[i] == _valor){
            encontrado = true;
            for(int j = i; j < capacidadElementos -1; j++)
                elementos[j] = elementos[j + 1];
            numElementos--;
            break;
        }
    }

    return encontrado;
}

template<typename Tipo>
bool Nodo<Tipo>::EstaLleno() {
    return numElementos == capacidadElementos;
}

template<typename Tipo>
void Nodo<Tipo>::Ordenar() {
    Tipo aux;
    for(int i = 0 ; i < numElementos ; i++)
        for(int j = 0 ; j < numElementos - 1 ; j++)
            if(elementos[j] > elementos[j+1]){
                aux = elementos[j];
                elementos[j] = elementos[j+1];
                elementos[j+1] = aux;
            }
}

template<typename Tipo>
bool Nodo<Tipo>::EstaVacio() const {
    return numElementos == 0 && numPunteros == 0;
}

template<typename Tipo>
bool Nodo<Tipo>::AgregarPuntero(Nodo<Tipo> *&n) {
    if(numPunteros < capacidadElementos){
        punteros[numPunteros] = n;
        numPunteros++;
        return true;
    }else
        return false;
}

template<typename Tipo>
bool Nodo<Tipo>::EliminarPuntero(int indice) {
    if(punteros[indice] == NULL)
        return true;

    if(indice < 0 || indice >= numPunteros)
        return false;

    delete [] punteros[indice];
    punteros[indice] = NULL;
    numPunteros--;
    return true;
}

template<typename Tipo>
void Nodo<Tipo>::Vaciar() {
    if(EstaVacio())
        return;

    delete [] elementos;
    elementos = NULL;

    for(int i = 0; i < numPunteros; ++i){
        punteros[i]->Vaciar();
        EliminarPuntero(i);
    }

    delete [] punteros;
    punteros = NULL;

    numElementos = 0;
    numPunteros = 0;
    capacidadElementos = 0;
    esHoja = true;
}


#endif //PROYECTO_ARBOLINB_NODO_H
