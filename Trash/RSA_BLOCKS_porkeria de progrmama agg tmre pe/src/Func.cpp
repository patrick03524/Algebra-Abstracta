#include "Func.h"
ZZ modulo(ZZ a,ZZ b)
{
    ZZ q=a/b;
    ZZ r=a-q*b;
    if(r<0)
        r+=b;
    return r;
}

ZZ euclides(ZZ a, ZZ b)
{
    ZZ res=modulo(a,b);
    while(res!=0)
    {
        ///cout<< a << "=" << a/b << "(" << b << ")" << "+" << res << endl;
        a=b;
        b=res;
        res=modulo(a,b);
    }
    ///cout<< a << "=" << a/b << "(" << b << ")" << "+" << res << endl;
    return b;
}
ZZ extendido(ZZ a, ZZ b)
{
    ZZ r1 = a, r2 = b;
    ZZ x1 = to_ZZ(1), x2 = to_ZZ(0);
    ZZ y1 = to_ZZ(0), y2 = to_ZZ(1);

    ZZ q , r , x , y;

    while(r2>0){
        q = r1/r2;

        r = r1 - q*r2;
        r1 = r2;
        r2 = r;

        x = x1 - q*x2;
        x1 = x2;
        x2 = x;
    }
    return x1;
}
ZZ inversa(ZZ a, ZZ b)
{
    ZZ x = extendido(a,b);
    if(x<0)
    {
        return modulo(x,b);
    }
    return x;
}
ZZ multiplicacion_modular(ZZ a, ZZ b,ZZ mod)
{
    return modulo((modulo(a, mod) * modulo(b,mod)), mod);
}
ZZ exponenciacion_modular(ZZ a, ZZ b, ZZ mod)
{
    ZZ resultado = (ZZ)1;
    ///ZZ i = modulo(a,mod);
    while(b>0){
        if((b&1)==1){
            resultado = multiplicacion_modular(resultado,a, mod);
            ///resultado = modulo(resultado*i, mod);
        }
        a = multiplicacion_modular(a, a, mod);
        ///i = modulo(a*a, mod);
        b >>= 1;
        ///i = i * 2;
    }
    return resultado;
}
int modulo_int(int a,int b)
{
    int q=a/b;
    int r=a-q*b;
    if(r<0)
        r+=b;
    return r;
}

int euclides_int(int a, int b)
{
    int res=modulo_int(a,b);
    while(res!=0)
    {
        ///cout<< a << "=" << a/b << "(" << b << ")" << "+" << res << endl;
        a=b;
        b=res;
        res=modulo_int(a,b);
    }
    ///cout<< a << "=" << a/b << "(" << b << ")" << "+" << res << endl;
    return b;
}
int extendido_int(int a, int b)
{
    int r1 = a, r2 = b;
    int x1 = 1, x2 = 0;
    int y1 = 0, y2 = 1;

    int q , r , x , y;

    while(r2>0){
        q = r1/r2;

        r = r1 - q*r2;
        r1 = r2;
        r2 = r;

        x = x1 - q*x2;
        x1 = x2;
        x2 = x;
    }
    return x1;
}
int inversa_int(int a, int b)
{
    if(a<0){
        return modulo_int(a,b);
    }
    else{
        return a;
    }

}
int multiplicacion_modular_int(int a, int b,int mod)
{
    return modulo_int((modulo_int(a, mod) * modulo_int(b,mod)), mod);
}
int exponenciacion_modular_int(int a, int b, int mod)
{
    int resultado = 1;
    ///int i = modulo(a,mod);
    while(b != 0){
        if(b&1){
            resultado = multiplicacion_modular_int(resultado,a, mod);
            ///resultado = modulo(resultado*i, mod);
        }
        a = multiplicacion_modular_int(a, a, mod);
        ///i = modulo(a*a, mod);
        b = b/2;
        ///i = i * 2;
    }
    return resultado;
}
string zz_To_String(ZZ z) {
    stringstream a;
    a << z;
    return a.str();
}

ZZ string_To_ZZ(string str){
    ZZ number(INIT_VAL, str.c_str());
    return number;
}

vector<bool> ZZtoBinary(ZZ num){
    vector<bool> binario;
    while(num>0){
        binario.push_back(to_int(modulo(num,to_ZZ(2))));
        num=num>>1;
    }
    return binario;
}

ZZ exponenciacion_modularMod(ZZ n, ZZ m, ZZ mod){
    n=modulo(n,mod);
    vector<bool> b=ZZtoBinary(m);
    ZZ d=to_ZZ(1);
	for(int i=b.size();i>0;i--){
        d=modulo(d*d,mod);
        if(b[i-1]==1)
            d=modulo(d*n,mod);
	}
	return d;
}
ZZ generar_Aleatorio(){
    ZZ numero_aleatorio  = (ZZ)rand();
    return numero_aleatorio;
}
ZZ generar_Aleatorio_Max(ZZ max){
    ZZ numero_aleatorio=1+(ZZ)rand()%(max-1);
    return numero_aleatorio;
}
int generar_Aleatorio_int()
{
    int numero_aleatorio  = rand();
    return numero_aleatorio;
}
int generar_Aleatorio_Max_int(int max)
{
    int numero_aleatorio=1+rand()%(max-1);
    return numero_aleatorio;
}
ZZ my_generar_Aleatorios(int bits_in_use)
{
    string num;
    for(int i = 0; i < bits_in_use; i++){
        num+=zz_To_String(generar_Aleatorio_Max(to_ZZ(10)));
    }
    ZZ result;
    result = string_To_ZZ(num);
    return result;
}
bool comprobar_primo(ZZ num)    ///Agg Tmre gg D:
{
    int fact = 2;
    if (num <= 2){return false;}
    for (ZZ i = to_ZZ(2); i < num; i+=1){
        if(modulo(num,i)==0){fact++;}
    }
    if(fact==2){return true;}
    else return false;
}
ZZ phi_euler(ZZ m, ZZ n)
{
    return ((m-1)*(n-1));
}
ZZ phi_euler_chidori(ZZ n)
{
    ZZ result = to_ZZ(0);
    for (ZZ i = to_ZZ(1); i< n; i++){
        if(euclides(i,n)==1){result++;}
    }
    return result;
}
/*
///Funciones para aleatorios ##############################################################################
ZZ convertir_decimal(vector <bool> a, int bits_num)
{
    ZZ num;
    num = 0;
    int e = 0;
    for(int i = bits_num - 1; i >= 0; i--)
    {
        if(a[i])
        {
            num += power2_ZZ(e);
        }
        else
            num += to_ZZ(0);
        e += 1;
    }
    return num;
}

void rotar_derecha(vector <bool> &vec, int indice, int elementos, int vueltas)
{
    bool temp;
    bool ultimo = vec[indice + elementos - 1];
    for(int j = vueltas; j > 0; j--)
    {
        for(int i = elementos + indice - 1; i > indice; i--)
        {
            temp = vec[i];
            vec[i] = vec[i - 1];
            vec[i - 1] = temp;
        }
    }
    vec[indice] = ultimo ^ vec[rand()%(elementos-1)];
}
void rotar_izquierda(vector <bool> &vec, int indice, int elementos, int vueltas)
{
    bool temp;
    bool primero = vec[indice];
    for(int j = vueltas; j > 0; j--)
    {
        for(int i = indice; i < indice + elementos - 1; i++)
        {
            temp = vec[i];
            vec[i] = vec[i + 1];
            vec[i + 1] = temp;
        }
    }
    vec[indice + elementos - 1] = primero ^ vec[rand()%(elementos - 1)];
}
vector<bool> ga(int bits_seed, int bits_num, int particiones, int vueltas)
{
    vector <bool> a;
    for(int i = 0; i < bits_seed; i++)
    {
        a.push_back(modulo_int(rand(),2));
    }
    int s = 0;
    for(int i = bits_seed; i < bits_num; i++)
    {
        a.push_back(a[s] ^ a[s+1]);
        s++;
    }
    int elementos_pedazo = bits_num/particiones;
    int indice = 0;
    int cont_particiones = 0;
    while(cont_particiones < particiones - 1)
    {
        if(cont_particiones%2 == 0)
        {
            rotar_izquierda(a, indice, elementos_pedazo, vueltas);
        }
        else
            rotar_derecha(a, indice, elementos_pedazo, vueltas);
        indice += elementos_pedazo;
        cont_particiones++;
    }
    if(cont_particiones%2 == 0)
    {
        rotar_izquierda(a, indice, bits_num - ((particiones - 1) * elementos_pedazo), vueltas);
    }
    else
        rotar_derecha(a, indice, bits_num - ((particiones - 1) * elementos_pedazo), vueltas);

    return a;
}

vector<bool> permutar56(vector<bool> bits){
    vector<bool> respuesta;
    int tabla_predefinida[56] = {57,49,41,33,25,17,9,1,57,50,42,34,26,18,10,2,59,57,43,35,27,19,11,3,60,52,44,36,63,55,47,39,31,23,15,7,62,54,46,38,30,22,14,6,61,53,45,37,29,21,13,5,28,20,12,4};
    for(int i = 0; i < 56; i++){
        respuesta.push_back(bits[tabla_predefinida[i]-1]);
    }
    return respuesta;
}

vector<bool> permutar48(vector<bool> bits){
    vector<bool> respuesta;
    int tabla_predefinida[48] = {14,17,11,24,1,5,3,28,15,6,21,10,23,19,12,4,26,8,16,7,27,20,13,2,41,52,31,37,47,55,30,40,51,41,33,48,44,49,39,56,34,53,46,42,50,36,29,32};
    for(int i = 0; i < 48; i++){
        respuesta.push_back(bits[tabla_predefinida[i]-1]);
    }
    return respuesta;
}

vector<bool> rotarizquierda(vector<bool> num, int vueltas)
{
    bool temp;
    for(int j = vueltas; j > 0; j--)
    {
        for(int i = 0; i < num.size() - 1; i++)
        {
            temp = num[i];
            num[i] = num[i + 1];
            num[i + 1] = temp;
        }
    }
    return num;
}

vector<bool> partir(vector<bool> numero,int posicion, int numeros){
    vector <bool> resultado;
    for(int i = 0; i < numeros; i++){
        resultado.push_back(numero[posicion]);
        posicion++;
    }
    return resultado;
}

vector<bool> unir(vector<bool> A, vector<bool> B){
    vector<bool>C;
    for(int i = 0; i < A.size(); i++){
        C.push_back(A[i]);
    }
    for(int j = 0; j < B.size(); j++){
        C.push_back(B[j]);
    }
    return C;
}

ZZ des(int bits){
    vector<bool> digitos = ga(11,bits,3,3);
    int vueltas[] = {1,1,2,2,2,2,2,2,1,2,2,2,2,2,2,1};
    vector<bool> actual;
    for(int j = 0; j < bits; j+=64){
        vector<bool> temp;
        temp = (permutar56(partir(digitos,j,64)));
        actual = unir(actual,temp);
    }
    for(int k = 0; k < 16; k++){
        vector<bool> num_56bits;
        vector<bool> num_48bits;
        for(int l = 0; l < actual.size(); l+=56){
            vector<bool> c = rotarizquierda(partir(actual,l,28),vueltas[k]);
            vector<bool> d = rotarizquierda(partir(actual,l+28,28),vueltas[k]);
            num_56bits = unir(num_56bits, unir(c,d));
            num_48bits = unir(num_48bits,permutar48(unir(c,d)));
        }
        if(num_48bits[num_48bits.size()-1] == 0)
            num_48bits[num_48bits.size()-1] = 1;
        ZZ resultado = convertir_decimal(num_48bits,num_48bits.size());
        if(ProbPrime(resultado,10)){
            return resultado;
        }
        actual = num_56bits;
    }
    return des(bits);
}*/

int rdtsc() ///rand de ciclos utilizados por procesador desde el inicio
{
    __asm__ __volatile__("rdtsc");
}

