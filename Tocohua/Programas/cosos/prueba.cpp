#include <iostream>
using namespace std;

int main(){
    int c;
    float largo, ancho, radio, altura;
    char op;
    cout<<"Valverde Palacios Raul Miguel"<<endl<<"Ingenieria en Sistemas Computacionales"<<endl<<"Ing. Rene Tocohua Rojas"<<endl<<"Tecnologico  Nacional de Mexico"<<endl<<"Instituto Tecnológico de Iztapalapa"<<endl<<"231080023"<<endl;
    do{
        c=0;
        cout<<endl<<"M E N U"<<endl;
        cout<<"A) El area y el perimetro de un cuadrilatero"<<endl;
        cout<<"B) El volumen de un cilindro recto"<<endl;
        cout<<"C) Finalizar el programa"<<endl;
        cin>>op;
        switch(op){
        case 'a':
        case 'A':
            do{
                cout<<"Dime el largo del cuadrilatero (m): ";
                cin>>largo;
                cout<<"Dime el ancho del cuadrilatero (m): ";
                cin>>ancho;
                if(largo<0 || ancho<0){
                    cout<<"Datos invalidos."<<endl<<"Escriba valores superiores a 0."<<endl;
                }
                else{
                        if (largo==ancho){
                        cout<<"El area del cuadrado es: "<<ancho*largo<<" metros cuadrados."<<endl;
                        cout<<"El perimetro del cuadrado es: "<<ancho*4<<" metros."<<endl;
                        }
                        else{
                            cout<<"El area del rectangulo es: "<<ancho*largo<<" metros cuadrados."<<endl;
                            cout<<"El perimetro del rectangulo es: "<<(ancho*2)+(largo*2)<<" metros."<<endl;
                        }
                    break;
                    }

            }while(true);
            break;
        case 'b':
        case 'B':
            do{
                cout<<"Dime el radio del cilindro recto (cm): ";
                cin>>radio;
                cout<<"Dime la altura del cilindro recto (cm): ";
                cin>>altura;
                if (radio<=1 || altura<=1){
                    cout<<"Los datos ingresados no son validos."<<endl;
                    c=c+1;
                    if(c>=2){
                        cout<<"Usted ha superado el numero de intentos, el programa finalizara."<<endl;
                        c=3;
                    }
                }
                else{
                    cout<<"El volumen del cilindro es: "<<(3.1416*radio*radio)*altura<<" centimetros cubicos."<<endl;
                    c=2;
                }
            }while(c<2);
            break;
        case 'c':
        case 'C':
            c=3;
            break;
        default:
            cout<<"Los datos ingresados no son validos."<<endl;
            break;
        }
    }while(c<3);
    cout<<"Adios";
    return 0;
}
