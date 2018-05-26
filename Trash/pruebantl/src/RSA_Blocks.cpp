#include "RSA_Blocks.h"

RSA_Blocks::RSA_Blocks(int bits)
{
    ZZ lim = (ZZ)(2 ^ bits);
    p = generar_Aleatorio_Max(lim);
    while(!comprobar_primo(p)){
        ///cout <<"NEL ";
        p = generar_Aleatorio_Max(lim);
    }
    cout <<"P: "<<p<<endl;
    q = generar_Aleatorio_Max(lim);
    while(!comprobar_primo(q)){
        ///cout <<"NEL ";
        q = generar_Aleatorio_Max(lim);
    }
    cout <<"Q: "<<q<<endl;
    N = p * q;
    cout <<" N : "<<N<<endl;
    phi_n = phi_euler(p, q);
    cout <<" PHI-N :"<<phi_n<<endl;
    e = generar_Aleatorio_Max(phi_n);
    while(euclides(e, phi_n)!=1 ){
        e = generar_Aleatorio_Max(phi_n);
    }
    cout <<" E :"<<e<<endl;
    d = inversa(e, phi_n);
    cout <<" D :"<<d<<endl;
    cout <<"-----RSA-------"<<endl;
    cout <<"Clave publica : <"<<e<<", "<<N<<">"<<endl;
    cout <<"Clave privado : <"<<d<<", "<<N<<">"<<endl;
}
RSA_Blocks::RSA_Blocks(ZZ a,ZZ b)
{
    e = a;
    N = b;
}
string RSA_Blocks::RSA_Cifrado(string mensaje_original)
{
    /*ifstream fichero("texto.txt");
    ofstream fichero_temporal("textotemp.txt");
    if(!fichero || !fichero_temporal){
        cout << "Error al abrir el archivo!" << endl;
    }
    string men, contenido;
    while(getline(fichero, contenido))
    {
        mensaje+= contenido;
        ///encriptacion();
        ///mensaje+= '\n'; saltos de linea
    }
    fichero_temporal << mensaje << endl;
    cout << mensaje <<endl;
    fichero.close();
    fichero_temporal.close();
    remove("texto.txt");
    rename("textotemp.txt", "texto.txt");*/

}
string RSA_Blocks::RSA_Descifrado(string mensaje_encriptado)
{

}
