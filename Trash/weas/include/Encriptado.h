#ifndef ENCRIPTADO_H
#define ENCRIPTADO_H
#include <iostream>
#include <string.h>

using namespace std;

class Encriptado
{
    private:
        string alfabeto;
        unsigned int len;
    public:
        Encriptado();
        string encrip_mensa(string);

};

#endif // ENCRIPTADO_H
