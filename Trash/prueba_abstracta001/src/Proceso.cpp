#include "Proceso.h"
Proceso::Proceso(unsigned int n_cuadrados, unsigned int n_len_cuadrado, string mensaje1)
{
    n=n_cuadrados;
    n_len=n_len_cuadrado;
    mensaje=mensaje1;
}
string Proceso::encriptacion()
{
    string mensaje_encriptado1;

    for(int i = 0; i<n_len; i++){
        for(int j = 0; j<n_len; j++){
            mensaje_encriptado.insert(mensaje_encriptado.begin()+i+n_len-i, mensaje[j*n_len+n_len-i]);
        }
    }
    cout << mensaje_encriptado1<<endl;

}
void Proceso::desencriptacion(string)
{

}
