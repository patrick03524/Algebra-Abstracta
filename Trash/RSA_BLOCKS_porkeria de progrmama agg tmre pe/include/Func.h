#ifndef FUNC_H
#define FUNC_H

#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <NTL/ZZ.h>
#include <fstream>
#include <sstream>

using namespace std;
using namespace NTL;

ZZ modulo(ZZ a, ZZ n);
ZZ euclides(ZZ a, ZZ b);
ZZ extendido(ZZ a, ZZ b);
ZZ inversa(ZZ a, ZZ alfabeto);
ZZ multiplicacion_modular(ZZ,ZZ,ZZ);
ZZ exponenciacion_modular(ZZ,ZZ,ZZ);

int modulo_int(int,int);
int euclides_int(int, int);
int extendido_int(int,int);
int inversa_int(int,int);
int multiplicacion_modular_int(int,int,int);
int exponenciacion_modular_int(int,int,int);

string zz_To_String(ZZ);
ZZ string_To_ZZ(string);

ZZ exponenciacion_modularMod(ZZ n, ZZ m, ZZ mod);
int generar_Aleatorio_int();
int generar_Aleatorio_Max_int(int);
ZZ my_generar_Aleatorios(int);
bool comprobar_primo(ZZ);

ZZ phi_euler(ZZ,ZZ);
ZZ phi_euler_chidori(ZZ);
///vector<ZZ> Criba_Erathostenes(ZZ,ZZ);

///Funciones para aleatorios
ZZ convertir_decimal(vector <bool> a, int bits_num);
void rotar_derecha(vector <bool> &vec, int indice, int elementos, int vueltas);
void rotar_izquierda(vector <bool> &vec, int indice, int elementos, int vueltas);
vector<bool> ga(int bits_seed, int bits_num, int particiones, int vueltas);
ZZ des(int bits);
int rdtsc();

#endif // FUNC_H
