#include <iostream>
#include <string>
#include <locale>
#include <math.h>
#include <stdlib.h>

using namespace std;

int main() {
    float x1, y1, x2, y2, x3, y3, x4, y4, a, b, c, d;
    string g;
    setlocale(LC_ALL, "");

    cout << "\n\t\tPrograma que calcula el modelo de interpolación cúbica e interpola diferentes valores.\n";

    // Ingreso de valores y verificación de puntos repetidos y valores constantes
    bool puntos_repetidos;
    do {
        puntos_repetidos = false;
        cout << "\n\t\tIngrese el valor de x1: ";
        cin >> g;
        x1 = atof(g.c_str());
        cout << "\n\t\tIngrese el valor de y1: ";
        cin >> g;
        y1 = atof(g.c_str());
        cout << "\n\t\tIngrese el valor de x2: ";
        cin >> g;
        x2 = atof(g.c_str());
        cout << "\n\t\tIngrese el valor de y2: ";
        cin >> g;
        y2 = atof(g.c_str());
        cout << "\n\t\tIngrese el valor de x3: ";
        cin >> g;
        x3 = atof(g.c_str());
        cout << "\n\t\tIngrese el valor de y3: ";
        cin >> g;
        y3 = atof(g.c_str());
        cout << "\n\t\tIngrese el valor de x4: ";
        cin >> g;
        x4 = atof(g.c_str());
        cout << "\n\t\tIngrese el valor de y4: ";
        cin >> g;
        y4 = atof(g.c_str());

        if (x1 == x2 || x2 == x3 || x3 == x4 || x1 == x3 || x1 == x4 || x2 == x4) {
            cout << "\n\t\tNo es posible encontrar el modelo de interpolación cúbica debido a puntos x repetidos.";
            puntos_repetidos = true;
        } else if (y1 == y2 && y2 == y3 && y3 == y4) {
            cout << "\n\t\tEl modelo de interpolación cúbica es constante.\n\t\ty = " << y1;
            return 0;
        }
    } while (puntos_repetidos);

    // Matriz aumentada para el sistema de ecuaciones
    float matriz[4][5] = {
        {pow(x1, 3), pow(x1, 2), x1, 1, y1},
        {pow(x2, 3), pow(x2, 2), x2, 1, y2},
        {pow(x3, 3), pow(x3, 2), x3, 1, y3},
        {pow(x4, 3), pow(x4, 2), x4, 1, y4}
    };

    // Método de Gauss-Jordan
    for (int i = 0; i < 4; i++) {
        float coef = matriz[i][i];
        for (int j = 0; j < 5; j++) {
            matriz[i][j] /= coef;
        }
        for (int k = 0; k < 4; k++) {
            if (k != i) {
                coef = matriz[k][i];
                for (int j = 0; j < 5; j++) {
                    matriz[k][j] -= coef * matriz[i][j];
                }
            }
        }
    }

    // Obtener los coeficientes del polinomio cúbico
    a = matriz[0][4];
    b = matriz[1][4];
    c = matriz[2][4];
    d = matriz[3][4];

    cout << "\n\t\tEl modelo de interpolación cúbica es: y = " << a << "x^3 + " << b << "x^2 + " << c << "x + " << d << "\n";

    // Ingreso de nuevos valores a interpolar
    int n;
    do {
        cout << "\n\t\tDígame cuántos datos desea interpolar: ";
        cin >> g;
        n = atoi(g.c_str());
    } while (n <= 1);

    float X[n + 4], Y[n + 4];
    X[0] = x1; Y[0] = y1;
    X[1] = x2; Y[1] = y2;
    X[2] = x3; Y[2] = y3;
    X[n + 3] = x4; Y[n + 3] = y4;

    int j;
    float x;
    bool vf;
    for (int i = 3; i < n + 3; i++) {
        do {
            vf = true;
            cout << "\n\t\tIngrese el valor de x" << i - 2 << " a interpolar: ";
            cin >> g;
            x = atof(g.c_str());
            if (x < X[0] || x > X[n + 3]) {
                cout << "\n\t\tEste valor no se puede interpolar, no se encuentra entre " << X[0] << " y " << X[n + 3] << ". Vuelve a intentarlo.";
            } else {
                for (j = 0; j < i; j++) {
                    if (x == X[j]) {
                        cout << "\n\t\tEl valor que ingresaste ya existe. Forma parte de los datos.";
                        vf = false;
                    }
                }
            }
            if (vf) X[i] = x;
        } while (x < X[0] || x > X[n + 3] || !vf);
    }

    // Calcular valores interpolados
    cout << "\n\t\tLos valores de la tabla sin ordenar son:\n\t\tx\t|\ty\n\t\t===================";
    for (int i = 0; i < n + 4; i++) {
        Y[i] = a * pow(X[i], 3) + b * pow(X[i], 2) + c * X[i] + d;
        cout << "\n\t\t" << X[i] << "\t|\t" << Y[i];
    }

    // Ordenar los valores
    float auxx, auxy;
    for (int i = 0; i < n + 3; i++) {
        for (int j = 0; j < n + 3; j++) {
            if (X[j] > X[j + 1]) {
                auxx = X[j];
                auxy = Y[j];
                X[j] = X[j + 1];
                Y[j] = Y[j + 1];
                X[j + 1] = auxx;
                Y[j + 1] = auxy;
            }
        }
    }

    // Imprimir valores ordenados
    cout << "\n\t\tLos valores de la tabla (ya ordenada) son:\n\t\tx\t|\ty\n\t\t===================";
    for (int i = 0; i < n + 4; i++) {
        cout << "\n\t\t" << X[i] << "\t|\t" << Y[i];
    }

    return 0;
}

