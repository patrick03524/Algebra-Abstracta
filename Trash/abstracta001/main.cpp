#include <iostream>
#include <string.h>
using namespace std;
int mod(int a , int b){
	int q,r;
	q = a/b;
	r = a - (q*b);
	if (r<0){
		r=r+b;
	}
	return r;
}

class Encriptado
{
private:
	string alfabeto="abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ.,_-0123456789";
	string mensaje;
	unsigned int clave;
public:
	Encriptado(string, unsigned int);
	string encrip_mensa();
	string desencrip_mensa(string);

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
	int temp = mensaje_perm.size();
	while(mod(temp,clave-1)!=0){
        mensaje_perm+='|';
        temp++;
	}
	mensaje_perm+='|';

	string mensaje_encriptado;
	///int cont1=0;
	///int a = 2*(clave-1);
	unsigned int cont1=0, a=2*(clave-1), b=0;
	for(unsigned int i=0; i<clave;i++){
        mensaje_encriptado+=mensaje_perm[cont1];
        while(cont1<mensaje_perm.size()-1){
            cont1+=a;
            if(cont1<mensaje_perm.size() && a!=0){
                mensaje_encriptado+=mensaje_perm[cont1];
            }
            cont1+=b;
            if(cont1<mensaje_perm.size() && b!=0){
                mensaje_encriptado+=mensaje_perm[cont1];
            }
        }
        a-=2;
        b+=2;
        cont1=i;
	}
	///mensaje_encriptado+='-';
	/*int cont1=0;
	int a = 2*(clave-1);
	while(cont1<mensaje_perm.size()-1){
		mensaje_encriptado+=mensaje_perm[cont1];
		cont1+=a;
	}
	mensaje_encriptado+='-';
	cont1 = 1;
	while(cont1<mensaje_perm.size()-1){
		mensaje_encriptado+=mensaje_perm[cont1];
		cont1+=2*(clave-2);
	}*/
	return mensaje_encriptado;

}

string Encriptado::desencrip_mensa(string mensaje_encriptado){
    string mensaje_desencriptado;
    int a=2*(clave-1) , b=0 , cont1=0 , n=0;
    int len=mensaje_encriptado.size();
    for(int i = 0; i< len;i++)
        mensaje_desencriptado+="-";

    for(int i = 0; i<clave;i++){
        mensaje_desencriptado[cont1]=mensaje_encriptado[i];
        while(cont1<=len-1){
            cont1+=a;
            if(cont1<=len-1 && a!=0){
                n++;
                mensaje_desencriptado[cont1]=mensaje_encriptado[n];
                }
            cont1+=b;
            if(cont1<=len-1 && b!=0){
                n++;
                mensaje_desencriptado[cont1]=mensaje_encriptado[n];
                }

        }
        a-=2;b+=2;
        cont1=n;
        n++;
    }
    return mensaje_desencriptado;
}

int main() {

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
