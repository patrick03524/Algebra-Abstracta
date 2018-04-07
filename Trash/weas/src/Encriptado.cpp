#include "Encriptado.h"

Encriptado::Encriptado()
{
    string alfabeto = "abcdefghijklmnopqrstuvwxyz";

}
string Encriptado::encrip_mensa(string mensaje){
    string mensaje_encrip;
    for(unsigned int i= 0; i<mensaje.size(); i++){
        mensaje_encrip+=alfabeto[alfabeto.size()-1-alfabeto.find(mensaje[i])]; ///concatenar append
    }
    cout <<mensaje_encrip<<endl;
    return mensaje_encrip;

}


