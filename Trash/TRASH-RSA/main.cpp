#include "RSA.h"
#include "Func2.h"
/*
string Affin_Encriptacion(string mensaje, RSA r)
{
    string mensaje_cifrado;
    int pos;
    for(int i=0;i<mensaje.length();i++){
        pos = r.alfabeto.find(mensaje[i]);
        modulo(pos, r.alfabeto.length());
        pos = r.RSA_Encriptacion(pos);
        modulo(pos, r.alfabeto.length());
        mensaje_cifrado+=r.alfabeto[pos];
    }
    return mensaje_cifrado;
}
string Affin_Desencriptacion(string mensaje_Encriptado, RSA r)
{
    string mensaje_Descifrado;
    int pos;
    for(int i=0;i<mensaje_Encriptado.length();i++){
        pos = r.alfabeto.find(mensaje_Encriptado[i]);
        modulo(pos, r.alfabeto.length());
        pos = r.RSA_Desencriptacion(pos);
        modulo(pos, r.alfabeto.length());
        mensaje_Descifrado+=r.alfabeto[pos];
    }
    return mensaje_Descifrado;
}
*/
int main()
{
    srand(time(NULL));
    int mensaje = 24;
    cout <<mensaje<<endl;
    RSA my_rsa;
    int mensaje_e = my_rsa.RSA_Encriptacion(mensaje);
    cout <<mensaje_e<<endl;
    cout <<my_rsa.RSA_Desencriptacion(mensaje_e)<<endl;
    ///cout <<exponenciacion_modular(19,5,119)<<endl;
    ///cout <<exponenciacion_modular(66,77,119)<<endl;
    /*cout <<inversa(4039,my_rsa.get_phi())<<endl;
    descomposicion_primos(2809);
    cout <<phi_euler_chidori(2809)<<endl;*/
    /*string mensaje2 = "Hola como estas";
    string encriptado = Affin_Encriptacion(mensaje2);
    cout <<encriptado<<endl;
    cout <<Affin_Desencriptacion(encriptado, my_rsa)<<endl;*/

    return 0;
}
///'setso-anial-abstracto:v::Ana-Mario'
