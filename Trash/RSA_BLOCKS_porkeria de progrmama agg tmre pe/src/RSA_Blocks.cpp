#include "RSA_Blocks.h"

RSA_Blocks::RSA_Blocks(int bits){
    /*ZZ P;
    P = my_generar_Aleatorios(bits);
    while(!comprobar_primo(p)){
        P = my_generar_Aleatorios(bits);
    }
    ZZ Q;
    Q= my_generar_Aleatorios(bits);
    while(!comprobar_primo(p)){
        Q = my_generar_Aleatorios(bits);
    }
    this -> p = P;
    ///cout <<"P: "<<p<<endl;
    this -> q = Q;
    ///cout <<"Q: "<<q<<endl;
    this -> N = P * Q;
    ///cout <<"N: "<<N<<endl;
    this -> phi_N = phi_euler(p,q);
    ///cout <<" PHI-N :"<<phi_N<<endl;
    ZZ E = my_generar_Aleatorios(bits);
    ///cout <<" E :"<<e<<endl;
    while(E > phi_N || (euclides(E, phi_N) != 1))
    {
        E = my_generar_Aleatorios(bits);
    }
    this -> e = E;
    this -> d = inversa(e, phi_N);
    ///cout <<" D :"<<d<<endl;*/
    ZZ P = des(bits);
    ZZ Q = des(bits);
    this -> p = P;
    this -> q = Q;
    N = P * Q;
    ZZ phi_N;
    phi_N = (P - 1) * (Q - 1);
    ZZ e;
    e = des(bits);
    while(e > phi_N || (euclides(e, phi_N) != 1))
    {
        e = des(bits);
    }
    this -> e = e;
    this -> d = inversa(e, phi_N);
}
RSA_Blocks::RSA_Blocks(ZZ a, ZZ b){
    this -> e = a;
    this -> N = b;
    this -> phi_N = phi_euler_chidori(N);
    this -> d = inversa(e, phi_N);
}

string RSA_Blocks::RSA_Cifrado(string mensaje){
    string result;
    for(int i = 0; i < mensaje.size(); i++){
        ZZ pos = to_ZZ(alfabeto.find(mensaje[i])); ///posicion del num
        string treat_num = zz_To_String(to_ZZ(alfabeto.find(alfabeto[alfabeto.size()-1]))); ///string del tamaño de la ultima letra del alfabeto
        int num_pos = zz_To_String(pos).size(); ///tamaño de la posicion como string
        if(num_pos < treat_num.size()){
            result += "0";  ///Rellena de 0 si falta aun
            num_pos++;      ///Aumenta la posicion desplaza
        }
        result += zz_To_String(pos);    ///añade bloque a bloque
    }
    ZZ temp = to_ZZ(result.size());     ///temp tamaño de result
    ZZ N_1 = to_ZZ(zz_To_String(N).size()-1);   ///tamaño de N como string -1
    while(modulo(temp,N_1) != 0){   ///minetras no llege al final
        int pos = alfabeto.find("M");  ///Rellenar al final
        result += zz_To_String(to_ZZ(pos)); ///Aumenta al string final
        temp = to_ZZ(result.size());        ///actualiza el tamaño de result
    }
    string result2;  ///resultado final
    for(int j = 0; j < result.size();){
        int temp = 0;       ///temp que comprueba si aun le falta a
        string temp_str;
        while(temp < to_int(N_1)){
            temp_str += result[j];  ///va a aumentando y almacenando en el temporal
            temp++;
            j++;
        }
        ZZ temp_2 = exponenciacion_modularMod(string_To_ZZ(temp_str),e,N);     ///la exponenciacion en cada bloque
        ZZ conta = to_ZZ(zz_To_String(temp_2).size());
        while(conta < zz_To_String(N).size()){  ///comprueba que aun le falta
            result2 += "0"; ///rellarna de 0
            conta++;
        }
        result2 += zz_To_String(temp_2); ///concantena
    }
    return result2;
}

string RSA_Blocks::RSA_Descifrado(string mensaje_encriptado){
    string resultado;
    int num = (zz_To_String(N).size()); ///tamañp de n
    for(int i = 0; i < mensaje_encriptado.size();){
        int a = 0;      ///num para comprobar tamanhos
        string temp;    ///temp de bloques
        while(a < num){
            a++;
            temp += mensaje_encriptado[i]; ///aumenta y guarda en temp
            i++;
        }
        ZZ valor = Resto_Chino(string_To_ZZ(temp)); ///Aplica el Resto Chino
        int x = zz_To_String(valor).size();
        while(x < zz_To_String(N).size()-1){
            resultado += "0";   ///en cada bloque aumenta el 0
            x++;
        }
        resultado += zz_To_String(valor); ///concantena bloques
    }
    string result2 = zz_To_String(to_ZZ(alfabeto.size()-1)); ///ultima posicion string del alfabeto
    string resultado_final;
    for(int j = 0; j < resultado.size();){
        int s = 0;
        string tempi;   ///Segun la letra más significativa
        while(s < result2.size()){
            tempi += resultado[j];
            s++;
            j++;
        }
        resultado_final += alfabeto[to_int(string_To_ZZ(tempi))];
    }
    while(resultado_final[resultado_final.size()-1] == 'M'){ ///Elimina los "M" del mensaje final
        resultado_final.erase(resultado_final.size()-1);
    }
    return resultado_final;
}

ZZ RSA_Blocks::Resto_Chino(ZZ num){     ///algoritmo exponenciación rápida binaria – Teorema Chino del Resto
    ZZ d1 = modulo(d,p-1);
    ZZ d2 = modulo(d,q-1);
    ZZ D1 = modulo(num,p);
    D1 = exponenciacion_modular(D1,d1,p);
    ZZ D2 = modulo(num,q);
    D2 = exponenciacion_modular(D2,d2,q);
    ZZ P = p*q;
    ZZ P1 = P/p;
    ZZ P2 = P/q;
    ZZ Q1 = inversa(P1,p);
    ZZ Q2 = inversa(P2,q);
    ZZ resultado = modulo(D1 * P1 * Q1,P);
    resultado += modulo(D2 * P2 * Q2,P);
    resultado = modulo(resultado,P);
    return resultado;
}

void RSA_Blocks::impr_claves(){
    cout << "CLAVE PUBLICA" << endl;
    cout << "E: " << this -> e << endl;
    cout << "N: " << this -> N << endl;
    ofstream guardarClaves;
    guardarClaves.open("Claves.txt");
    guardarClaves << "Clave Pública"<<endl;
    guardarClaves << "e: " << e << endl;
    guardarClaves << "N: " << N << endl;
    guardarClaves.close();
}
