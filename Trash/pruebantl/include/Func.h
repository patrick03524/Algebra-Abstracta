#ifndef FUNC_H
#define FUNC_H

#include <iostream>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <vector>
#include <NTL/ZZ.h>

using namespace std;
using namespace NTL;

ZZ modulo(ZZ,ZZ);
ZZ euclides(ZZ, ZZ);
ZZ extendido(ZZ,ZZ);
ZZ inversa(ZZ,ZZ);
ZZ generar_Aleatorio();
ZZ generar_Aleatorio_Max(ZZ);
bool comprobar_primo(ZZ);
ZZ multiplicacion_modular(ZZ,ZZ,ZZ);
ZZ exponenciacion_modular(ZZ,ZZ,ZZ);
ZZ phi_euler(ZZ,ZZ);
ZZ phi_euler_chidori(ZZ);
void descomposicion_primos(ZZ);

vector<ZZ> Criba_Erathostenes(ZZ,ZZ);
/*ZZ Resto_chino(ZZ);
bool Criba_Erathostenes(ZZ);
*/

#endif // FUNC_H
