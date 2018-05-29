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
    void EstablecerPadre(Nodo &n);
    void EstablecerSiguiente(Nodo &n);
    void EstablecerHoja(bool estado);

    bool EstaVacio() const;
    bool EstaLleno();
    int ObtenerNumElementos();
    int ObtenerNumPunteros();
    Tipo ObtenerElemento(int indice);


//private:
    int numElementos;
    int numPunteros;
    int capacidadElementos;
    bool esHoja;

    Tipo *elementos;
    Nodo **punteros;
    Nodo *padre;
    Nodo *siguiente;

    void Ordenar();
    bool operator<(const Nodo &n) const;
    bool operator>(const Nodo &n) const;
    bool operator<=(const Nodo &n) const;
    bool operator>=(const Nodo &n) const;
    bool operator==(const Nodo &n) const;
    bool operator!=(const Nodo &n) const;
};

//----------------------------------------------------------------------------------------------------------------------
//Metodos para buen funcionamiento
template<typename Tipo>
Nodo<Tipo>::Nodo(int tamanio) : numElementos(0), numPunteros(0), capacidadElementos(tamanio), esHoja(true),{
    elementos = new Tipo[tamanio];
    punteros = new Nodo*[tamanio];
    padre = NULL;
    siguiente = NULL;

    for(int i = 0; i < tamanio ; ++i){
        punteros[i] = NULL;
    }
}

template<typename Tipo>
Nodo<Tipo>::Nodo(const Nodo<Tipo> &n) : numElementos(0) , numPunteros(0) , capacidadElementos(0) , esHoja(true), elementos(NULL), punteros(NULL), padre(NULL), siguiente(NULL){
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
    padre = n.padre;
    siguiente = n.siguiente;

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

//----------------------------------------------------------------------------------------------------------------------
//Metodos de manejo
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
bool Nodo<Tipo>::AgregarPuntero(Nodo<Tipo> *&n) {
    if(numPunteros < capacidadElementos){
        punteros[numPunteros] = n;
        n->EstablecerPadre(*this);
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

    if(punteros[indice] != NULL){
        punteros[indice]->Vaciar();
        delete punteros[indice];
    }
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
    padre = NULL;
    siguiente = NULL;
}

template<typename Tipo>
void Nodo<Tipo>::EstablecerPadre(Nodo &n) {
    padre = &n;
}

template<typename Tipo>
void Nodo<Tipo>::EstablecerSiguiente(Nodo &n) {
    siguiente = n.siguiente;
}

template<typename Tipo>
void Nodo<Tipo>::EstablecerHoja(bool estado) {
    esHoja = estado;
}

//----------------------------------------------------------------------------------------------------------------------
//Metodos de consulta

template<typename Tipo>
bool Nodo<Tipo>::EstaLleno() {
    return numElementos == capacidadElementos;
}

template<typename Tipo>
bool Nodo<Tipo>::EstaVacio() const {
    return numElementos == 0 && numPunteros == 0;
}

template<typename Tipo>
int Nodo<Tipo>::ObtenerNumElementos() {
    return numElementos;
}

template<typename Tipo>
int Nodo<Tipo>::ObtenerNumPunteros() {
    return numPunteros;
}

template<typename Tipo>
Tipo Nodo<Tipo>::ObtenerElemento(int indice) {
    return elementos[indice];
}

//----------------------------------------------------------------------------------------------------------------------
//Metodos de ultileria
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
bool Nodo<Tipo>::operator<(const Nodo &n) const {
    return (elementos[numElementos] < n.elementos[0]);
}

template<typename Tipo>
bool Nodo<Tipo>::operator>(const Nodo &n) const {
    return elementos[0] > n.elementos[numElementos];
}

template<typename Tipo>
bool Nodo<Tipo>::operator<=(const Nodo &n) const {
    return ! (n < *this);
}

template<typename Tipo>
bool Nodo<Tipo>::operator>=(const Nodo &n) const {
    return ! (*this < n);
}

template<typename Tipo>
bool Nodo<Tipo>::operator==(const Nodo &n) const {
    if(capacidadElementos != n.capacidadElementos)
        return false;

    if(esHoja != n.esHoja)
        return false;

    if(numElementos != n.numElementos)
        return false;

    if(numPunteros != n.numPunteros)
        return false;

    for(int i = 0; i < numElementos; i++)
        if(elementos[i] != n.elementos[i])
            return false;

    for(int i = 0; i < numPunteros; i++)
        if(punteros[i] != n.punteros[i])
            return false;

    return true;
}

template<typename Tipo>
bool Nodo<Tipo>::operator!=(const Nodo &n) const {
    return ! (*this == n);
}

//----------------------------------------------------------------------------------------------------------------------
//Metodos amigos
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

#endif //PROYECTO_ARBOLINB_NODO_H
