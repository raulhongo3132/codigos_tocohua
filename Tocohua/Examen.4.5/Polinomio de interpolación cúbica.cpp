#include <iostream>
#include <string>
#include <locale>
#include <math.h>
#include <stdlib.h>

using namespace std;

int main() {
    float x1, y1, x2, y2, x3, y3, x4, y4, a, b, c, d;
    char N[]="";
    int i, j, k, n;
    string g;
    setlocale(LC_ALL,"");

    cout<<"\n\t\tPrograma que calcula el modelo de interpolación cúbica e interpola diferentes valores.\n";

    do {
        cout<<"\n\t\tIngrese el valor de x1: ";
        cin>>g;
        x1=atof(g.c_str());
        cout<<"\n\t\tIngrese el valor de y1: ";
        cin>>g;
        y1=atof(g.c_str());
        cout<<"\n\t\tIngrese el valor de x2: ";
        cin>>g;
        x2=atof(g.c_str());
        cout<<"\n\t\tIngrese el valor de y2: ";
        cin>>g;
        y2=atof(g.c_str());
        cout<<"\n\t\tIngrese el valor de x3: ";
        cin>>g;
        x3=atof(g.c_str());
        cout<<"\n\t\tIngrese el valor de y3: ";
        cin>>g;
        y3=atof(g.c_str());
        cout<<"\n\t\tIngrese el valor de x4: ";
        cin>>g;
        x4=atof(g.c_str());
        cout<<"\n\t\tIngrese el valor de y4: ";
        cin>>g;
        y4=atof(g.c_str());

        if(x1==x2||x2==x3||x3==x4||x1==x3||x1==x4||x2==x4) {
            cout<<"\n\t\tNo es posible encontrar el modelo de interpolación cúbica.";
            continue;
        }
        if(y1==y2&&y2==y3&&y3==y4) {
            cout<<"\n\t\tEl modelo de interpolación cúbica es constante.\n\t\ty = "<<y1;
            return 0;
        }
    } while(x1==x2||x2==x3||x3==x4||x1==x3||x1==x4||x2==x4);

    float matriz[4][5] = {
        {x1*x1*x1,x1*x1,x1,1,y1},
        {x2*x2*x2,x2*x2,x2,1,y2},
        {x3*x3*x3,x3*x3,x3,1,y3},
        {x4*x4*x4,x4*x4,x4,1,y4}
    };

    for(i=0;i<4;i++) {
        float coef=matriz[i][i];
        for(j=0;j<5;j++) {
            matriz[i][j]/=coef;
        }
        for(k=0;k<4;k++) {
            if(k!=i) {
                coef=matriz[k][i];
                for(j=0;j<5;j++) {
                    matriz[k][j]-=coef*matriz[i][j];
                }
            }
        }
    }

    a=matriz[0][4];
    b=matriz[1][4];
    c=matriz[2][4];
    d=matriz[3][4];

    cout<<"\n\t\tEl modelo de interpolación cúbica es: y = "<<a<<"x^3 + "<<b<<"x^2 + "<<c<<"x + "<<d<<"\n";

	double aa, bb, cc;
	cout<<endl<<endl<<"\t\t\tf(x)=a*x^3+b*x^2+c*x+d"<<endl;
	cout<<endl<<"\t\ten un intervalo cerrado [a,b], por el método de Simpson 3/8.";
	cout<<endl<<"\t\t================================================================================="<<endl;
	do{
		cout<<endl<<"\t\tIngrese el valor del límite inferior: ";
		cin>>aa;
		cout<<endl<<"\t\tIngrese el valor del límite superior: ";
		cin>>bb;
		if(aa>=bb){
			cout<<endl<<"\t\tEl límire superior debe ser mayor al inferior.";
		}
	}while(aa>=bb);
	do{
		cout<<endl<<"\t\tIngrese el números de rectangulos a dividir el intervalo: ";
		cin>>N;
		n=atoi(N);
		if(n<5 || n%3!=0){
			cout<<endl<<"\t\tValor inválido, ingrese un valor mayor a 5 y multiplo natural de 3.";
		}
	}while(n<5 || n%3!=0);
	double y[n+1], a1=0, a2=0, a3=0, a4=0, total, h;
	cc=aa;
	h=(bb-aa)/n;
	
	cout<<endl<<endl<<"\t\t=================================================================================";
	cout<<endl<<"\t\tn\t\tX\t\ta1\t\ta2\t\ta3\t\ta4";
	cout<<endl<<"\t\t=================================================================================";
	for(i=0; i<=n; i++){
		y[i]=a*pow(cc,3)+b*pow(cc,2)+c*cc+d;
		if(i==0 || i==n){
			a1=a1+(y[i]);
			cout<<endl<<"\t\t"<<i+1<<"\t\t"<<c<<"\t\t"<<y[i]<<"\t\t"<<0<<"\t\t"<<0<<"\t\t"<<0;
		}else if(i>0 and i<n and i%3==1){
			a2=a2+(y[i]);
			cout<<endl<<"\t\t"<<i+1<<"\t\t"<<c<<"\t\t"<<0<<"\t\t"<<y[i]<<"\t\t"<<0<<"\t\t"<<0;
		}else if(i>0 and i<n and i%3==2){
			a3=a3+(y[i]);
			cout<<endl<<"\t\t"<<i+1<<"\t\t"<<c<<"\t\t"<<0<<"\t\t"<<0<<"\t\t"<<y[i]<<"\t\t"<<0;
		}else{
			a4=a4+(y[i]);
			cout<<endl<<"\t\t"<<i+1<<"\t\t"<<c<<"\t\t"<<0<<"\t\t"<<0<<"\t\t"<<0<<"\t\t"<<y[i];
		}
		c=c+h;
	}
	a1=(3.0/8.0)*h*a1;
	a2=(9.0/8.0)*h*a2;
	a3=(9.0/8.0)*h*a3;
	a4=(3.0/4.0)*h*a4;
	total=a1+a2+a3+a4;
	float guardar=total;
	cout<<endl<<"\t\t=================================================================================";
	cout<<endl<<endl<<"\t\tLos resultados son: ";
	cout<<endl<<endl<<"\t\ta1= "<<a1;
	cout<<endl<<"\t\ta2= "<<a2;
	cout<<endl<<"\t\ta3= "<<a3;
	cout<<endl<<"\t\ta3= "<<a4;
	cout<<endl<<"\t\tDiferencia de áreas= "<<total;
	
	c=a;
	a1=0;
	a2=0;
	a3=0;
	a4=0;
	total=0;
	
	cout<<endl<<endl<<"\t\t=================================================================================";
	cout<<endl<<"\t\tn\t\tX\t\ta1\t\ta2\t\ta3\t\ta4";
	cout<<endl<<"\t\t=================================================================================";
	for(i=0; i<=n; i++){
		y[i]=a*pow(cc,3)+b*pow(cc,2)+c*cc+d;
		if(i==0 || i==n){
			a1=a1+fabs(y[i]);
			cout<<endl<<"\t\t"<<i+1<<"\t\t"<<c<<"\t\t"<<fabs(y[i])<<"\t\t"<<0<<"\t\t"<<0<<"\t\t"<<0;
		}else if(i>0 and i<n and i%3==1){
			a2=a2+fabs(y[i]);
			cout<<endl<<"\t\t"<<i+1<<"\t\t"<<c<<"\t\t"<<0<<"\t\t"<<fabs(y[i])<<"\t\t"<<0<<"\t\t"<<0;
		}else if(i>0 and i<n and i%3==2){
			a3=a3+fabs(y[i]);
			cout<<endl<<"\t\t"<<i+1<<"\t\t"<<c<<"\t\t"<<0<<"\t\t"<<0<<"\t\t"<<fabs(y[i])<<"\t\t"<<0;
		}else{
			a4=a4+fabs(y[i]);
			cout<<endl<<"\t\t"<<i+1<<"\t\t"<<c<<"\t\t"<<0<<"\t\t"<<0<<"\t\t"<<0<<"\t\t"<<fabs(y[i]);
		}
		c=c+h;
	}
	a1=(3.0/8.0)*h*a1;
	a2=(9.0/8.0)*h*a2;
	a3=(9.0/8.0)*h*a3;
	a4=(3.0/4.0)*h*a4;
	total=a1+a2+a3+a4;
	cout<<endl<<"\t\t=================================================================================";
	cout<<endl<<endl<<"\t\tLos resultados son: ";
	cout<<endl<<endl<<"\t\ta1= "<<a1;
	cout<<endl<<"\t\ta2= "<<a2;
	cout<<endl<<"\t\ta3= "<<a3;
	cout<<endl<<"\t\ta4= "<<a4;
	cout<<endl<<"\t\tÁrea real= "<<total;
	cout<<endl<<endl<<"\t\t=================================================================================";
	cout<<endl<<endl<<"\t\tResumen: ";
	cout<<endl<<"\t\tDiferencia de áreas= "<<guardar;
	cout<<endl<<"\t\tÁrea real= "<<total;
	cout<<endl<<endl<<"\t\t=================================================================================";
	
    
    return 0;
}

