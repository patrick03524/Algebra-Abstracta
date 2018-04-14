#ifndef PROCESO_H
#define PROCESO_H
#include <iostream>
#include <string.h>

using namespace std;

class Proceso
{
    private:
        string mensaje;
        string alfabeto= "abcdefghijklmnopqrstuvwxyz";
        unsigned int n_len;
        unsigned int n;
    public:
        Proceso(unsigned int, unsigned int, string);
        string encriptacion();
        void desencriptacion(string);

};

#endif // PROCESO_H
