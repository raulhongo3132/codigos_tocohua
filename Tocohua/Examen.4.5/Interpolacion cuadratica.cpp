#include <iostream>
#include <math.h>
#include <locale.h>
#include <stdlib.h>
#include <string>

using namespace std;

int main(){
    float x1, y1, x2, y2, x3, y3, a, b, c;
    char N[]="";
    string g;
    setlocale(LC_ALL,"");
    cout<<endl<<endl<<"\t\tPrograma que calcula el modelo de interpolación cuadrática e interpola diferentes valores.";
    cout<<endl<<endl;

    do{
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
        cout<<endl<<"\t\tIngrese el valor de x3: ";
        cin>>g;
        x3=atof(g.c_str());
        cout<<endl<<"\t\tIngrese el valor de y3: ";
        cin>>g;
        y3=atof(g.c_str());

        if(x1==x2 || x2==x3 || x1==x3){
            cout<<endl<<"\t\tNo es posible encontrar el modelo de interpolación cuadrática.";
        }else if(y1==y2 && y2==y3){
            cout<<endl<<"\t\tEl modelo de interpolación cuadrática es constante.";
            cout<<endl<<"\t\ty = "<<y1;
            return 0;
        }
    }while(x1==x2 || x2==x3 || x1==x3);

    a=((y3-y1)/((x3-x1)*(x3-x2)))-((y2-y1)/((x2-x1)*(x3-x2)));
    b=(y2-y1)/(x2-x1)-a*(x1+x2);
    c=y1-a*x1*x1-b*x1;

    cout<<endl<<"\t\tEl modelo de interpolación cuadrática es: y = "<<a<<"x^2";
    if(b>0){
        cout<<" + "<<b<<"x";
    }else if(b<0){
        cout<<" - "<<-b<<"x";
    }
    if(c>0){
        cout<<" + "<<c;
    }else if(c<0){
        cout<<" - "<<-c;
    }

    int n;
    do{
        cout<<endl<<endl<<"\t\tDígame cuántos datos desea interpolar: ";
        cin>>N;
        n=atoi(N);
    }while(n<=1);

    float X[n+3], Y[n+3];
    X[0]=x1; Y[0]=y1;
    X[1]=x2; Y[1]=y2;
    X[n+2]=x3; Y[n+2]=y3;

    float x;
    bool vf;
    for(int i=2; i<n+2; i++){
        do{
            vf=true;
            cout<<endl<<"\t\tIngrese el valor de x"<<i-1<<" a interpolar: ";
            cin>>g;
            x=atof(g.c_str());
            if(x<X[0] || x>X[n+2]){
                cout<<endl<<"\t\tEste valor no se puede interpolar, no se encuentra entre "<<X[0]<<" y "<<X[n+2]<<". Vuelve a intentarlo.";
            }else{
                for(int j=0; j<i; j++){
                    if(x==X[j]){
                        cout<<endl<<"\t\tEl valor que ingresaste ya existe. Forma parte de los datos.";
                        vf=false;
                        break;
                    }
                }
            }
            if(vf) X[i]=x;
        }while((x<X[0] || x>X[n+2]) || !vf);
    }

    cout<<endl<<"\t\tLos valores de la tabla sin ordenar son:"<<endl;
    cout<<endl<<"\t\tx\t|\ty"<<endl<<"\t\t===================";
    for(int i=0; i<n+3; i++){
        Y[i]=a*pow(X[i],2)+b*X[i]+c;
        cout<<endl<<"\t\t"<<X[i]<<"\t|\t"<<Y[i];
    }

    float auxx, auxy;
    for(int i=0; i<n+2; i++){
        for(int j=0; j<n+2; j++){
            if(X[j]>X[j+1]){
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
    for(int i=0; i<n+3; i++){
        cout<<endl<<"\t\t"<<X[i]<<"\t|\t"<<Y[i];
    }

    return 0;
}

