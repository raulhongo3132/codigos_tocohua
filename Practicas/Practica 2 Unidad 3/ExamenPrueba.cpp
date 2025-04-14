#include <iostream>
#include <locale.h>
#include <string>
#include <stdlib.h>
#include <math.h>

using namespace std;

void cabecera();
void crearMatriz(float a[50][50], float b[50], int &z);
void imprimirSistemaEcuaciones(float a[50][50], float b[50], int z);
void jacobi(float a[50][50], float b[50], int z);

int main() {
    setlocale(LC_ALL, "");
    cabecera();

    float a[50][50];
    float b[50];    
    int z;

    crearMatriz(a, b, z);
    imprimirSistemaEcuaciones(a, b, z);
    jacobi(a, b, z);

    return 0;
}

void cabecera() {
    cout << endl << endl << "\t\tPrograma que resuelve un sistema de ecuaciones lineales de orden hasta 50x50, ";
    cout << endl << "\t\ta partir de la forma general estandar: ";
    cout << endl << "\t\ta11x1 + a12x2 + ... = b1  --- ( 1 )";
    cout << endl << "\t\ta21x1 + a22x2 + ... = b2  --- ( 2 )";
    cout << endl << "\t\t...\n";
    cout << endl << "\t\tpor el método de Jacobi." << endl;
}

void crearMatriz(float a[50][50], float b[50], int &z) {
    string g;

    do {
        cout << endl << "\t\tDime el tamaño de la ecuación (desde 2x2 hasta 50x50): ";
        cin >> z;
        if (z < 2 || z > 50) {
            cout << endl << "\t\tValor inválido. Vuelve a intentarlo.";
        }
    } while (z < 2 || z > 50);

    for (int i = 0; i < z; i++) {
        cout << endl << "\t\tPara la ecuación #" << i + 1 << ": ";
        float x = 0;
        for (int j = 0; j <= z; j++) {
            if (j < z) {
                cout << endl << "\t\tDime el valor de a" << i + 1 << j + 1 << ": ";
                cin >> g;
                a[i][j] = atof(g.c_str());
            } else {
                cout << endl << "\t\tDime el valor de b" << i + 1 << ": ";
                cin >> g;
                b[i] = atof(g.c_str());
            }
            if (j < z) {
                if (j != i) {
                    x += fabs(a[i][j]);
                }
            }
        }
        
        if (x >= fabs(a[i][i])) {
            cout << endl << endl << "\t\tLa ecuación no está en diagonal fuerte";
            i--;
        }
    }
}

void imprimirSistemaEcuaciones(float a[50][50], float b[50], int z) {
    cout << endl << "\t\tEl sistema de ecuaciones es: ";
    for (int i = 0; i < z; i++) {
        cout << endl << "\t\t";
        for (int j = 0; j <= z; j++) {
            if (j == 0) {
                cout << a[i][j] << " a" << i + 1 << j + 1 << " ";
            } else if (j < z) {
                if (a[i][j] >= 0) {
                    cout << "+ " << a[i][j] << " a" << i + 1 << j + 1 << " ";
                } else {
                    cout << "- " << fabs(a[i][j]) << " a" << i + 1 << j + 1 << " ";
                }
            } else {
                cout << "= " << b[i] << " b" << i + 1;
            }
        }
    }
}

void jacobi(float a[50][50], float b[50], int z) {
    float x1[50] = {0}, xdf[50] = {0}, y, ex[50] = {0}, algo;
    string g;

    for (int i = 0; i < z; i++) {
        cout << endl << "\t\tDime el valor para x" << i + 1 << ": ";
        cin >> g;
        x1[i] = atof(g.c_str());
    }

    do {
        cout << endl << "\t\tDime el valor para la tolerancia: ";
        cin >> g;
        y = atof(g.c_str());
        if (y >= 1 || y <= 0) {
            cout << endl << "\t\tLa tolerancia debe ser menor a 1. ";
        }
    } while (y >= 1 || y <= 0);

    int iteraciones = 0;
    do {
        algo = 0;
        for (int i = 0; i < z; i++) {
            xdf[i] = b[i];
            for (int j = 0; j < z; j++) {
                if (j != i) {
                    xdf[i] -= a[i][j] * x1[j];
                }
            }
            xdf[i] /= a[i][i];
        }

        cout << endl << "\t\tIteración " << iteraciones + 1 << ": ";
        cout << endl << "\t\tValores actuales: ";
        for (int i = 0; i < z; i++) {
            ex[i] = fabs(xdf[i] - x1[i]);
            x1[i] = xdf[i];
            cout << "x" << i + 1 << " = " << xdf[i] << "   ";
        }
        cout << endl;

        for (int i = 0; i < z; i++) {
            algo = max(algo, ex[i]);
        }
        iteraciones++;
    } while (algo > y);
    
    cout << endl << "\t\tResumen de los resultados finales: ";
    cout << endl << "\t\t--------------------------------------";
    for (int i = 0; i < z; i++) {
        cout << endl << "\t\tx" << i + 1 << " = " << xdf[i];
    }
    cout << endl << "\t\t--------------------------------------";
    cout << endl << "\t\tTotal de iteraciones: " << iteraciones << endl;
}


