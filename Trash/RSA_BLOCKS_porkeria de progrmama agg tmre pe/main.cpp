#include "RSA_Blocks.h"


int main()
{
    ///srand(rdtsc());
    srand(time(NULL));
    int x = 1024; ///Numero de Bits
    cout <<"Generando claves..."<<endl;
    RSA_Blocks A(x);
    A.impr_claves();

    ifstream ficheroEntrada;

    string mensaje;
    ficheroEntrada.open ("Mensaje.txt");
    getline(ficheroEntrada,mensaje);
    cout <<"MENSAJE ORIGINAL = "<<mensaje<<endl;

    ofstream Encriptacion;
    Encriptacion.open("Encriptado.txt");
    string encriptado = A.RSA_Cifrado(mensaje);
    cout <<"MENSAJE ENCRIPTADO = "<<encriptado<<endl;
    Encriptacion << encriptado;
    cout <<"Encriptacion con Exito..............................."<<endl;

    string desencriptado = A.RSA_Descifrado(encriptado);
    cout <<"MENSAJE DESENCRIPTADO = "<<desencriptado<<endl;
    ofstream Desencriptacion;
    Desencriptacion.open("Desencriptado.txt");
    Desencriptacion << desencriptado;
    cout <<"Desencriptacion con Exito............................."<<endl;

    Encriptacion.close();
    ficheroEntrada.close();
    Desencriptacion.close();

    /*ifstream ficheroEntrada;
    ifstream C1;
    ifstream C2;
    ofstream Encriptacion;
    ofstream Desencriptacion;
    C1.open("clave_e.txt");
    C2.open("clave_n.txt");
    string clave_e,clave_n;
    string mensaje, encriptado, desencriptado;
    getline(C1,clave_e);
    getline(C2,clave_n);
    ZZ e, n;
    e = string_To_ZZ(clave_e);
    n = string_To_ZZ(clave_n);

    RSA_Blocks B(e,n);
    ficheroEntrada.open ("Mensaje.txt");
    getline(ficheroEntrada,mensaje);
    encriptado = B.RSA_Cifrado(mensaje);
    cout <<"MENSAJE ENCRIPTADO = "<<encriptado<<endl;
    Encriptacion << encriptado;
    cout <<"Encriptacion con Exito..............................."<<endl;

    desencriptado = B.RSA_Descifrado(encriptado);
    cout <<"MENSAJE DESENCRIPTADO = "<<desencriptado<<endl;
    Desencriptacion << desencriptado;
    cout <<"Desencriptacion con Exito............................."<<endl;

    C1.close();
    C2.close();
    ficheroEntrada.close();
    Encriptacion.close();
    Desencriptacion.close();*/


    return 0;
}
