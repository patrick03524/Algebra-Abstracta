
#include <iostream>
#include <string.h>
using namespace std;
class Encriptado
{
private:
	string alfabeto="abcdefghijklmnopqrtusvwxyz ";
	string mensaje;
	unsigned int clave;
public:
	Encriptado(string, unsigned int);
	string encrip_mensa();
	
};

Encriptado::Encriptado(string mensaje1, unsigned int c1)
{
	mensaje=mensaje1;
	clave=c1;
	
}
string Encriptado::encrip_mensa(){
	
	string mensaje_perm;
	for(unsigned int i= 0; i<mensaje.size(); i++){
		mensaje_perm+=alfabeto[alfabeto.size()-1-alfabeto.find(mensaje[i])]; ///concatenar append
	}
	cout <<mensaje_perm<<endl;
	string mensaje_encriptado;
	int cont1=0;
	int a = 2*(clave-1);
	while(cont1<mensaje_perm.size()-1){
		mensaje_encriptado+=mensaje_perm[cont1];
		cont1+=a;
	}
	mensaje_encriptado+=' ';
	cont1 = 1;
	///a = 
	while(cont1<mensaje_perm.size()-1){
		mensaje_encriptado+=mensaje_perm[cont1];
		cont1+=2*(clave-2);
	}
	return mensaje_encriptado;
	
}

int main(int argc, char *argv[]) {
	
	string mensj,str1;
	cout <<"Ingrese el mensaje :";
	getline(cin,str1); ///Sobrecarga de Getline en un string
	cout <<str1<<endl;
	unsigned int clave;
	cout <<"Ingrese la clave : "; 
	cin >> clave;
	
	Encriptado e(str1, clave);
	mensj=e.encrip_mensa();
	
	cout <<mensj<<endl;
	return 0;
}

