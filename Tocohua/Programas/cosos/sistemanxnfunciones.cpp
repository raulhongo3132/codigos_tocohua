#include <iostream>
#include <locale.h>
#include <stdlib.h>
using namespace std;

float determinante(float A[30][30], int n);

int main() {
    int n, i, j;
    char N[]=""; // Espacio suficiente para la entrada
    float detA;

    setlocale(LC_ALL, "");
    do {
        cout<<endl<<endl<<"\t\tIngrese el orden o tamaño de la matriz A n x n: ";
        cin>>N;
        n=atoi(N);
        if(n>30 or n<3){
            cout<<endl<<endl<<"\t\tValor inválido";
        }
    }while(n>30 or n<3);

    float a[30][30], b[30];
    cout<<endl<<endl;
    for(i=0;i<n;i++){
        for (j=0;j<n;j++){
            cout<<"Dime el valor de a"<<i+1<<j+1<<": ";
            cin >> a[i][j];
        }
        cout<<"Dime el valor de b"<<i+1<<": ";
        cin>>b[i];
    }
    
    cout<<endl<<endl;
    for(i=0;i<n;i++){
        cout<<"	|";
        for(j=0;j<n;j++){
            cout<<" "<<a[i][j]<<" ";
        }
        cout<<"|	"<<b[i]<<endl;
    }

    detA=determinante(a, n);
    cout<<endl<<endl<<"\t\tDeterminante: "<<detA<<endl;
    cout<<endl<<endl;
	for(i=0;i<n;i++){
        cout<<"	|";
        for(j=0;j<n;j++){
            cout<<" "<<a[i][j]<<" ";
        }
        cout<<"|	"<<b[i]<<endl;
    }
    return 0;
}

float determinante(float A[30][30], int n){
    int i, j, k;
    float pivote, inverso, factor, det = 1;
    
    for(i=0;i<n;i++){
        pivote=A[i][i];
        for(j=i+1;j<n;j++){
            inverso=-1*A[j][i];
            factor=inverso/pivote;
            for(k=0;k < n;k++){
                A[j][k]=A[j][k]+A[i][k]*factor;
            }
        }
    }
    
    for(i= 0;i<n;i++){
        det=det*A[i][i];
    }
    return det;
}

