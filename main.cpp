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

void ImprimirResultados(int angle, int Vini, float x, float y, int t){
    cout << "Impacto con un angulo de " << angle << " grados" << endl;
    cout << "Impacto con velocidad inicial " << Vini << endl;
    cout << "Impacto con posicion x " << x << endl;
    cout << "Impacto con posicion y " << y << endl;
    cout << endl;
}

void DisparoOfensivo(Do disparoO, Dd disparoD, int Voo){
    int flag = 0;
    float x, y;
    float Vxo, Vyo;
    float Vini = 0;
    int t = 0;
    int angle = 0;
    for(Vini = Voo;;Vini+=5){
        for(angle = 0; angle < 90; angle++){
            Vxo = Vini*cos(angle*pi/180);
            Vyo = Vini*sin(angle*pi/180);
            x = 0.0;
            y = 0.0;
            for(t = 0;;t++){
                x = Vxo*t;
                y = disparoO.Yo + Vyo*t - (0.5*G*t*t);
                if(sqrt(pow((disparoD.Xd-x),2)+pow((disparoD.Yd-y),2)) < disparoO.d0){
                    if(y<0) y=0;
                    ImprimirResultados(angle,Vini,x,y,t);
                    flag += 1;
                    Vini += 50;
                    break;
                }
                if(y < 0) break;
            }
            if(flag == 3) break;
        }
        if(flag == 3) break;
    }
    if(flag != 3) cout << "No impacto ningun disparo";
}



int main()
{
    Do disparoO;
    Dd disparoD;
    int Voo;
    cout << "Ingrese Vo desde la cual quiere probar: " << endl;
    cin >> Voo;
    DisparoOfensivo(disparoO,disparoD,Voo);

    return 0;
}













