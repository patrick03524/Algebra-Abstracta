#include <iostream>
#include <string.h>

using namespace std;

string alfabeto = "abcdefghijklmnopqrstuvwxyz ";

string voltear_mensaje(string mensaje){
    int len=alfabeto.size();
    string mensaje_encrip;
    for(unsigned int i= 0; i<mensaje.size(); i++){
        ///if(alfabeto[len-1-alfabeto.find(mensaje[i])]=='/32'){mensaje_encrip+='_'; break;}
        mensaje_encrip+=alfabeto[len-1-alfabeto.find(mensaje[i])]; ///concatenar append
    }
    return mensaje_encrip;
}


int main()
{
    /*cout << "Hello world!" << endl;
    std::string name( 1000 , 'x');
    cout << name;*/
    string str1;
	cout <<"Ingrese el mensaje :";
	getline(cin,str1); ///Sobrecarga de Getline en un string
	cout <<str1<<endl;
    cout <<"El mensaje invertido es :"<<endl;
    cout <<voltear_mensaje(str1)<<endl;

    return 0;
}

