#include <iostream>
#include <string>
#include <locale>
#include <stdlib.h>

using namespace std;

int main() {
    float x1, y1, x2, y2, m=0, b;
    char N[]="";
    string g;
    setlocale(LC_ALL,"");

    cout<<endl<<endl<<"\t\tPrograma que calcula el modelo de interpolación lineal e interpola diferentes valores.";
    cout<<endl<<endl;

    do {
        cout<<endl<<"\t\tIngrese el valor de x1: ";
        cin>>g;
        x1=atof(g.c_str());
        cout<<endl<<"\t\tIngrese el valor de y1: ";
        cin>>g;
        y1=atof(g.c_str());
        cout<<endl<<"\t\tIngrese el valor de x2: ";
        cin>>g;
        x2=atof(g.c_str());
        cout<<endl<<"\t\tIngrese el valor de y2: ";
        cin>>g;
        y2=atof(g.c_str());

        if(x1==x2) {
            cout<<endl<<"\t\tNo es posible encontrar el modelo de interpolación lineal.";
        }
    } while(x1==x2);

    m=(y2-y1)/(x2-x1);
    b=-m*x1+y1;

    cout<<endl<<"\t\tEl modelo de interpolación lineal es: y = "<<m<<"x";
    if(b>0) {
        cout<<" + "<<b;
    } else if(b<0) {
        cout<<" - "<<-b;
    }

    int i, n;
    do {
        cout<<endl<<endl<<"\t\tDigame cuantos datos desea interpolar: ";
        cin>>N;
        n=atoi(N);
    } while(n<=1);

    float X[n+2], Y[n+2];
    if(x1<x2) {
        X[0]=x1;
        Y[0]=y1;
        X[n+1]=x2;
        Y[n+1]=y2;
    } else {
        X[0]=x2;
        Y[0]=y2;
        X[n+1]=x1;
        Y[n+1]=y1;
    }

    float x;
    bool vf;
    for(i=1; i<=n; i++) {
        do {
            vf=true;
            cout<<endl<<"\t\tIngrese el valor de x"<<i<<" a interpolar: ";
            cin>>g;
            x=atof(g.c_str());

            if(x<=X[0] || x>=X[n+1]) {
                cout<<endl<<"\t\tEste valor no se puede interpolar, no se encuentra entre "<<X[0]<<" y "<<X[n+1]<<". Vuelve a intentarlo.";
                vf=false;
            } else {
                for(int j=0; j<i; j++) {
                    if(x==X[j]) {
                        cout<<endl<<"\t\tEl valor que ingresaste ya existe. Forma parte de los datos.";
                        vf=false;
                        break;
                    }
                }
            }
            if(vf) X[i]=x;
        } while(!vf);
        Y[i]=m*X[i]+b;
    }

    cout<<endl<<"\t\tLos valores de la tabla sin ordenar son:"<<endl;
    cout<<endl<<"\t\tx\t|\ty"<<endl<<"\t\t===================";
    for(i=0; i<=n+1; i++) {
        cout<<endl<<"\t\t"<<X[i]<<"\t|\t"<<Y[i];
    }

    float auxx, auxy;
    for(i=0; i<=n; i++) {
        for(int j=0; j<n+1-i; j++) {
            if(X[j]>X[j+1]) {
                auxx=X[j];
                auxy=Y[j];
                X[j]=X[j+1];
                Y[j]=Y[j+1];
                X[j+1]=auxx;
                Y[j+1]=auxy;
            }
        }
    }

    cout<<endl<<"\t\tLos valores de la tabla (ya ordenada) son:"<<endl;
    cout<<endl<<"\t\tx\t|\ty"<<endl<<"\t\t===================";
    for(i=0; i<=n+1; i++) {
        cout<<endl<<"\t\t"<<X[i]<<"\t|\t"<<Y[i];
    }

    return 0;
}

