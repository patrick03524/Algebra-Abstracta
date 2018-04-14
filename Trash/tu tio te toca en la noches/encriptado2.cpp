#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include "Proceso.h"

using namespace std;

class Proceso
{
private:
	string mensaje;
	string alfabeto= "abcdefghijklmnopqrstuvwxyz";
	unsigned int n_len;
	unsigned int n;
public:
	Proceso(unsigned int, unsigned int, string);
	string encriptacion();
	void desencriptacion(string);
	
};
Proceso::Proceso(unsigned int n_cuadrados, unsigned int n_len_cuadrado, string mensaje1)
{
	n=n_cuadrados;
	n_len=n_len_cuadrado;
	mensaje=mensaje1;
}
string Proceso::encriptacion()
{
	string mensaje_encriptado1;
	unsigned int cont=0;
	for(int i = 0; i<n_len; i++){
		for(int j = 0; j<n_len; j++){
			///mensaje_encriptado.insert(mensaje_encriptado.begin()+i+n_len-i, mensaje[j*n_len+n_len-i]);
			mensaje_encriptado1.insert(mensaje_encriptado1.begin()+(j*n_len)+n_len-i, mensaje[cont]);
			cont++;
		}
	}
	cout << mensaje_encriptado1<<endl;
	
}
void Proceso::desencriptacion(string)
{
	
}

int main(int argc, char *argv[]) {
	
	/*ifstream fichero("texto.txt");
	ofstream fichero_temporal("textotemp.txt");
	if(!fichero || !fichero_temporal){
	cout << "Error al abrir el archivo!" << endl;
}
	string mensaje, contenido;
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
	///Proceso p(4,5,"Hola como estas yo me llamo ");
	///p.encriptacion();
	/*string prueba = "Hola como estas yo me llamo nipples";
	///prueba[1]='p';
	cout <<prueba[1]<<" - "<<prueba[4]<<" - "<<prueba[9]<<endl;
	string mensaje_encriptado1;
	unsigned int cont=0, n_len=5;
	for(int i = 0; i<n_len; i++){
	for(int j = 0; j<n_len; j++){
	///mensaje_encriptado.insert(mensaje_encriptado.begin()+i+n_len-i, mensaje[j*n_len+n_len-i]);
	mensaje_encriptado1.insert(mensaje_encriptado1.begin()+(j*n_len)+n_len-i, prueba[cont]);
	cont++;
}
}
	cout << mensaje_encriptado1<<endl;
	*/
	return 0;
}

