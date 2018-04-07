#include <iostream>
#include <string.h>
#include "Encriptado.h"
using namespace std;
/*
string alfabeto = "abcdefghijklmnopqrstuvwxyz";
unsigned int len = alfabeto.size();

string encrip_mensa(string mensaje){
    string mensaje_encrip;
    for(unsigned int i= 0; i<mensaje.size(); i++){
        mensaje_encrip+=alfabeto[len-1-alfabeto.find(mensaje[i])]; ///concatenar append
    }
    return mensaje_encrip;
}
*/

int main()
{
    /*cout << "Hello world!" << endl;
    std::string name( 1000 , 'x');
    cout << name;*/
    string str1;
	cout <<"Ingrese el mensaje :";
	getline(cin,str1); ///Sobrecarga de Getline en un string
	cout <<str1<<endl;

	Encriptado e;
	e.encrip_mensa(str1);

    ///cout <<encrip_mensa(str1)<<endl;

    return 0;
}
