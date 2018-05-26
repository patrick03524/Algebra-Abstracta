#ifndef RSA_BLOCKS_H
#define RSA_BLOCKS_H
#include "Func.h"

class RSA_Blocks
{
    public:
        RSA_Blocks(int);
        RSA_Blocks(ZZ,ZZ);
        string RSA_Cifrado(string);
        string RSA_Descifrado(string);
        ///bool test_primalidad(ZZ);
        ///ZZ Resto_chino(ZZ);

    private:
        ZZ d;
        ZZ e;
        ZZ N;
        ZZ p;
        ZZ q;
        ZZ phi_n;
        ///string alfabeto="ABCDEFGHIJKLMNOPQRSTUVWXYZ.,-_()abcdefghijklmnopqrstuvwxyz 0123456789";
        string alfabeto = "abcdefghijklmnopqrstuvwxyz( )ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
};

#endif // RSA_BLOCKS_H
