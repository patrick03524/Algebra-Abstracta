#include "Affin.h"

Affin::Affin()
{
    clave_b=generar_Aleatorio_Max(alfabeto.length()-1);
    /*int temp1=generar_Aleatorio();
    while(euclides(temp1,alfabeto.length()!= 1)){
        temp1=generar_Aleatorio();
    }
    clave_a = temp1;
    */
    clave_a = 997;
    inversa_a=inversa(clave_a, alfabeto.length());
    cout <<"ALFABETO LEN :"<<alfabeto.length()<<endl;
    cout <<"Clave A: "<<clave_a<<endl;
    cout <<"Clave B: "<<clave_b<<endl;
    cout <<"Inversa A :"<<inversa_a<<endl;
}
Affin::Affin(int c1, int c2)
{
    clave_a = c1;
    clave_b = c2;
    inversa_a=inversa(clave_a, alfabeto.length());
    cout <<"ALFABETO LEN :"<<alfabeto.length()<<endl;
    cout <<"Clave A: "<<clave_a<<endl;
    cout <<"Clave B: "<<clave_b<<endl;
    cout <<"Inversa A :"<<inversa_a<<endl;
}

string Affin::Affin_Encriptacion(string mensaje)
{
    string mensaje_cifrado;
    int pos;
    for(int i=0;i<mensaje.length();i++){
        pos = alfabeto.find(mensaje[i]);
        pos *= clave_a;
        pos += clave_b;
        pos = modulo(pos,alfabeto.length());
        mensaje_cifrado+=alfabeto[pos];
    }
    return mensaje_cifrado;
}
string Affin::Affin_Desencriptacion(string mensaje_Encriptado)
{
    string mensaje_Descifrado;
    int pos;
    for(int i=0;i<mensaje_Encriptado.length();i++){
        pos = alfabeto.find(mensaje_Encriptado[i]);
        pos -= clave_b;
        if(pos<0){
            pos = alfabeto.length()+pos;
        }
        pos = pos*inversa_a;
        pos = modulo(pos,alfabeto.length());
        mensaje_Descifrado+=alfabeto[pos];
    }
    return mensaje_Descifrado;
}
