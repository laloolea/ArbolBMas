//
// Created by Eduardo Gonzalez Olea on 5/26/18.
//

#ifndef PROYECTO_ARBOLINB_ARBOLBMAS_H
#define PROYECTO_ARBOLINB_ARBOLBMAS_H

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
    
    
};
#endif //PROYECTO_ARBOLINB_ARBOLBMAS_H
