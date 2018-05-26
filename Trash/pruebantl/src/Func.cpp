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
    ZZ x1 = (ZZ)1, x2 = (ZZ)0;
    ZZ y1 = (ZZ)0, y2 = (ZZ)1;

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
    if(a<0){
        return modulo(a,b);
    }
    else{
        return a;
    }

}
ZZ generar_Aleatorio(){
    ZZ numero_aleatorio  = (ZZ)rand();
    return numero_aleatorio;
}
ZZ generar_Aleatorio_Max(ZZ max){
    ZZ numero_aleatorio=1+(ZZ)rand()%(max-1);  ///Numeros entre 1-1000
    return numero_aleatorio;
}
bool comprobar_primo(ZZ num)
{
    ZZ fact = (ZZ)2;
    if (num == 1){return 0;}
    for (ZZ i = (ZZ)2; i < num; i++){
        if(modulo(num,i)==0){fact++;}
    }
    if (fact == 2){return 1;}
    else{return 0;}
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
ZZ phi_euler(ZZ m, ZZ n)
{
    return ((m-1)*(n-1));
}
ZZ phi_euler_chidori(ZZ n)
{
    ZZ result = (ZZ)0;
    for (ZZ i = (ZZ)1; i< n; i++){
        if(euclides(i,n)==1){result++;}
    }
    return result;
}
vector<ZZ> Criba_Erathostenes(ZZ menor,ZZ mayor)
{
    vector<ZZ> resultado;
    if(modulo(menor,(ZZ)2)==1){
        for(ZZ inicio = menor; inicio <= mayor; inicio+=2){
            resultado.push_back(inicio);
        }
    }
    else {
        for(ZZ inicio = menor+1; inicio <= mayor; inicio+=2){
            resultado.push_back(inicio);
        }
    }
    for(unsigned int i = 0; i < resultado.size(); i++){
        if(modulo(resultado[i],3)==3){resultado.erase(resultado.begin()+i;}
        if(modulo(resultado[i],5)==5){resultado.erase(resultado.begin()+i;}
    }
}

