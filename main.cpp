#include <iostream>
#include <math.h>
#define G 9.81
#define pi 3.141617
using namespace std;

struct Do{ //Estas son las caracteristicas del disparo ofensivo
    float d = 800;
    float Ho = 100;
    float Xo = 0;
    float Yo = Ho;
    float d0 = 0.05*d;
};

struct Dd{ //Estas son las caracteristicas del disparo defensivo
    float d = 800;
    float Hd = 200;
    float Xd = d;
    float Yd = Hd;
    float d0 = 0.025*d;
};



int main()
{
    Do disparoO;
    Dd disparoD;
    int Voo;
    cout << "Ingrese Vo desde la cual quiere probar: " << endl;
    cin >> Voo;

    return 0;
}













