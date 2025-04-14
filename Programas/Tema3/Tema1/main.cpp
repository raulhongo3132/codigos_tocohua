#import <iostream>
#include <locale.h>
#include <math.h>
using namespace std;
int main(){
	float a11, a12, a13, a21, a22, a23, a31, a32, a33;
	float b1, b2, b3;
	float detA, detAx1, detAx2, detAx3, x1, x2, x3;
	float a, b, c, d, mc1, mc2, mc3, mc4;
	float r11, r12, r13, r1, r21, r22, r23, r2, r31, r32, r33, r3;
	float t;
	int salir=0;
	float pe1, pe2, pe3;
	setlocale(LC_ALL,"");
	cout<<endl<<"=================================================================================="<<endl;
	cout<<endl<<"\t\tDeterminante 3x3";
	cout<<endl<<"\t\t5. Valverde Palacios Raúl Miguel";
	cout<<endl<<"\t\t6. 231080023";
	cout<<endl<<"\t\tIngeniería en Sistemas Computacionales";
	cout<<endl<<"\t\tIng. Rene Tocohua Rojas";
	cout<<endl<<"\t\tTecnológico  Nacional de México";
	cout<<endl<<"\t\tInstituto Tecnólogico de Iztapalapa";
	cout<<endl<<endl<<"=================================================================================="<<endl;
	
	do{
		cout<<endl<<endl<<"\t\tPrograma que resuelve un sstema lineal de 3 ecuaciones con 3 incognitas....";
		cout<<endl<<endl<<"\t\tA partir de la forma estandar por el método de determinantes"<<endl<<endl;
		
		cout<<endl<<endl<<"=================================================================================="<<endl;
		LineInicio:
		cout<<endl<<endl<<"\t\tLa forma estandar de 3x3 es:";
		cout<<endl<<endl<<"\t\ta11x1 + a12x2 + a13x3 = b1 --- (1)";
		cout<<endl<<endl<<"\t\ta21x1 + a22x2 + a23x3 = b2 --- (2)";
		cout<<endl<<endl<<"\t\ta31x1 + a22x2 + a33x3 = b3 --- (3)";
		cout<<endl<<endl;
		cout<<endl<<"Para la ecuación #1: ";
		cout<<endl<<"Ingrese el valor de a11: ";
		cin>>a11;
		cout<<endl<<"Ingrese el valor de a12: ";
		cin>>a12;
		cout<<endl<<"Ingrese el valor de a13: ";
		cin>>a13;
		cout<<endl<<"Ingrese el valor de b1: ";
		cin>>b1;
		cout<<endl<<"Para la ecuación #2: ";
		cout<<endl<<"Ingrese el valor de a21: ";
		cin>>a21;
		cout<<endl<<"Ingrese el valor de a22: ";
		cin>>a22;
		cout<<endl<<"Ingrese el valor de a23: ";
		cin>>a23;
		cout<<endl<<"Ingrese el valor de b2: ";
		cin>>b2;
		cout<<endl<<"Para la ecuación #3: ";
		cout<<endl<<"Ingrese el valor de a31: ";
		cin>>a31;
		cout<<endl<<"Ingrese el valor de a32: ";
		cin>>a32;
		cout<<endl<<"Ingrese el valor de a33: ";
		cin>>a33;
		cout<<endl<<"Ingrese el valor de b3: ";
		cin>>b3;	
		
		cout<<endl<<endl<<"El sistemas de ecuaciones es: ";
		cout<<endl<<"\t\t"<<a11<<"x1 + "<<a12<<"x2 + "<<a13<<"x3 = "<<b1<<" --- (1)";
		cout<<endl<<"\t\t"<<a21<<"x1 + "<<a22<<"x2 + "<<a23<<"x3 = "<<b2<<" --- (2)";
		cout<<endl<<"\t\t"<<a31<<"x1 + "<<a32<<"x2 + "<<a33<<"x3 = "<<b3<<" --- (3)";
		
		detA=(a11*a22*a33+a21*a32*a13+a31*a12*a23)-(a31*a22*a13+a11*a32*a23+a21*a12*a33);
		if(detA==0){
			a=min(fabs(a11),fabs(a21));
			mc1=min(fabs(a),fabs(a31));
			b=min(fabs(a12),fabs(a22));
			mc2=min(fabs(b),fabs(a32));
			c=min(fabs(a13),fabs(a23));
			mc3=min(fabs(c),fabs(a33));
			d=min(fabs(b1),fabs(b2));
			mc4=min(fabs(d),fabs(b3));
			
			r11=fabs(a11)/mc1;
			r21=fabs(a21)/mc1;
			r31=fabs(a31)/mc1;
			
			r12=fabs(a12)/mc2;
			r22=fabs(a22)/mc2;
			r32=fabs(a32)/mc2;
			
			r13=fabs(a13)/mc3;
			r23=fabs(a23)/mc3;
			r33=fabs(a33)/mc3;
			
			r1=fabs(b1)/mc4;
			r2=fabs(b2)/mc4;
			r3=fabs(b3)/mc4;
			
			pe1=(r11-r12+r13-r1);
			pe2=(r21-r22+r23-r2);
			pe3=(r31-r32+r33-r3);
			
			cout<<endl<<endl<<r11<<endl<<r12<<endl<<r13<<endl<<r1;
			cout<<endl<<endl<<r11-r12<<endl<<r13-r1;
			cout<<endl<<endl<<r21<<endl<<r22<<endl<<r23<<endl<<r2;
			cout<<endl<<endl<<r21-r22<<endl<<r23-r2;
			cout<<endl<<endl<<r31<<endl<<r32<<endl<<r33<<endl<<r3;
			cout<<endl<<endl<<pe1<<endl<<pe2<<endl<<pe3;
			if(pe1==0&&pe2==0&&pe3==0){
				cout<<endl<<endl<<"Existen soluciones infinitas para este sistema de ecuaciones.";
				cout<<endl<<endl<<"Ingrese un valor para el parametro t: ";
				cin>>t;
				x1 = a11 * t + b1;  // Ejemplo de solución para x1
			    x2 = a12 * t + b2;  // Ejemplo de solución para x2
			    x3 = a13 * t + b3;  // Ejemplo de solución para x3
			
			    cout << "Las soluciones del sistema son:" << endl;
			    cout << "x1 = " << x1 << endl;
			    cout << "x2 = " << x2 << endl;
			    cout << "x3 = " << x3 << endl;
			}
		}else{
			detAx1=(b1*a22*a33+b2*a32*a13+b3*a12*a23)-(b3*a22*a13+b1*a32*a23+b2*a12*a33);
			detAx2=(a11*b2*a33+a21*b3*a13+a31*b1*a23)-(a31*b2*a13+a11*b3*a23+a21*b1*a33);
			detAx3=(a11*a22*b3+a21*a32*b1+a31*a12*b2)-(a31*a22*b1+a11*a32*b2+a21*a12*b3);
			x1=detAx1/detA;
			x2=detAx2/detA;
			x3=detAx3/detA;
			cout<<endl<<endl<<"La solución del sistema es única y es: ";
			cout<<endl<<endl<<"x1= "<<x1;
			cout<<endl<<endl<<"x2= "<<x2;
			cout<<endl<<endl<<"x3= "<<x3;
		}
		cout<<endl<<endl<<"Si desea continuar presione 0";
		cout<<endl<<endl<<"Si desea salir presione 1"<<endl;
		cin>>salir;
	}while(salir==0);
	cout<<endl<<endl<<"Adios"<<endl;
	return 0;
}
