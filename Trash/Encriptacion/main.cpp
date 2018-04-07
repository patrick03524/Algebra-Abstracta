#include <iostream>
#include <string.h>
using namespace std;
char alfabeto[27]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','\0'};

char encriptar_letra(char *alfabeto_volteado, char letra, int tam){
	for (int i=0; i<tam; i++){
		if(letra == alfabeto[i])
			return *alfabeto_volteado;
		alfabeto_volteado++;
	}
}
/*
void encriptar_mensaje(char mensaje[], char *res, int total, char alfabeto_volteado[]){
	for (int i=0; i < total ; i++){
		*res=encriptar_letra(alfabeto_volteado,mensaje[i],26);
		res++;
	}
}*/

int main(int argc, char *argv[]) {
	char alfabeto_volteado[27];
	for (int i=0; i < 27; i++){
		alfabeto_volteado[i] = alfabeto[26-i];
	}

	char stringquequieropedir[30];
	cout <<"Ingrese el mensaje :";
	cin.getline(stringquequieropedir,30,'\n');
	cout <<stringquequieropedir<<endl;

	string resultado;
	/*encriptar_mensaje(stringquequieropedir,resultado,stringquequieropedir.size(),alfabeto_volteado);
	*/
	for (int i = 0; i < 30; i++){
		resultado.push_back(encriptar_letra(alfabeto_volteado,stringquequieropedir[i],30));
	}
	cout <<resultado<<endl;

	return 0;
}
