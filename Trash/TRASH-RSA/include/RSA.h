#ifndef RSA_H
#define RSA_H
#include "Func2.h"



class RSA
{
    public:
        RSA();
        RSA(int,int);
        int RSA_Encriptacion(int);
        int RSA_Desencriptacion(int);
        int clave_publica_e;
        int get_phi(){return phi_n;}
        string alfabeto="ABCDEFGHIJKLMNOPQRSTUVWXYZ.,-_()abcdefghijklmnopqrstuvwxyz 0123456789";
    private:

        int numero_p;
        int numero_q;
        int numero_n;
        int phi_n;
        int clave_privada_d;

};

#endif // RSA_H
