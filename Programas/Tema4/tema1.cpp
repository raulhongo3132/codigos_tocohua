#include <iostream>
#include <math.h>
using namespace std;
int main(){
	int j;
	float x[45001], y[45001], xi, xf, h;
	cout<<"Ingrese el valor inicial de x: ";
	cin>>xi;
	cout<<"Ingrese el valor final de x: ";
	cin>>xf;
	h=(xf-xi)/(45000.0);
	for(j=1; j<=45001;j++){
		x[j]=xi;
		y[j]=0.25*pow(x[j],5)-2*pow(x[j],3)+4.5*pow(x[j],2)+2*x[j]-6;
		xi=xi+h;
		cout<<"\t"<<j<<"\t"<<x[j]<<"\t"<<y[j]<<endl;
	}
	
	return 0;
}
