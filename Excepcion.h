//
// Created by Brayan Durazo on 5/26/18.
//

#ifndef PROYECTO_ARBOLINB_EXCEPCION_H
#define PROYECTO_ARBOLINB_EXCEPCION_H

#include <iostream>

class Excepcion {
public:
    /**
     * @brief Constructor de la clase Excepcion
     * @param _msn El mensaje que representa el objetivo de esta excepci&oacute;n.
     */
    Excepcion(std::string _msn) : msn(_msn){}

    /**
     * @brief Da a conocer el mensaje que describe el motivo por el cual la excepci&oacute; fue lanzada.
     * @return El mensaje correspondiente de la excepci&oacute;n.
     */
    std::string QuePaso() const { return msn; }

private:
    std::string msn;
};

#endif //PROYECTO_ARBOLINB_EXCEPCION_H
