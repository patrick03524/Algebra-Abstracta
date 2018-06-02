#ifndef RSA_BLOCKS_H
#define RSA_BLOCKS_H
#include "Func.h"

class RSA_Blocks
{
    public:
        RSA_Blocks(int bits);
        RSA_Blocks(ZZ,ZZ);
        string RSA_Cifrado(string);
        string RSA_Descifrado(string);
        ZZ Resto_Chino(ZZ);
        void impr_claves();
    private:
        ZZ d;
        ZZ e;
        ZZ N;
        ZZ p;
        ZZ q;
        ZZ phi_N;
        string alfabeto = "abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ._-0123456789";
};

#endif // RSA_BLOCKS_H
