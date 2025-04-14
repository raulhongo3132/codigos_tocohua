#include <cmath>
#include <iostream>
#include <locale.h>
#include <stdlib.h>
#include <string>

using namespace std;

int main() {
    setlocale(LC_ALL, "");
    string g;   
    int n, i;
    double sumax = 0, sumay = 0, sumaxy = 0, sumaxx = 0, ssx = 0, ssy = 0, spm = 0, mx, my, sx, sy, r, b0, b1;

    cout << endl << endl << "\t\tPrograma que calcula un modelo de regresión lineal.";
    cout << endl << "\t\tBasado en un conjunto de datos ";
    cout << endl << "\t\tde la forma (x1,y1), (x2,y2), ...";
    cout << endl << endl;

    do {
        cout << endl << "\t\tIndique el número de datos a ingresar: ";
        cin >> g;
        n = atoi(g.c_str());
        if (n < 4) {
            cout << endl << "\t\tDebe ser al menos 4.";
        }
    } while (n < 4);

    double x[n], y[n], xy[n], xx[n];

    for (i = 0; i < n; i++) {
        cout << endl << "\t\tIndique el valor de x" << i + 1 << ": ";
        cin >> g;
        x[i] = atof(g.c_str());
        cout << endl << "\t\tIndique el valor de y" << i + 1 << ": ";
        cin >> g;
        y[i] = atof(g.c_str());
        xy[i] = x[i] * y[i];
        xx[i] = x[i] * x[i];
        sumax += x[i];
        sumay += y[i];
        sumaxx += xx[i];
        sumaxy += xy[i];
    }

    mx = sumax / n;
    my = sumay / n;
    b1 = (sumaxy - n * mx * my) / (sumaxx - n * mx * mx);
    b0 = (my - b1 * mx);

    cout << endl << "\t\tLa información obtenida es:";
    cout << endl << "\t\tn\t\tx\t\ty\t\txy\t\tx^2";
    cout << endl << "\t\t===================================================================" << endl;
    for (i = 0; i < n; i++) {
        cout << endl << "\t\t" << i + 1 << "\t\t" << x[i] << "\t\t" << y[i] << "\t\t" << xy[i] << "\t\t" << xx[i];
    }

    cout << endl << "\t\tEl modelo de regresión lineal es:";
    if (b0 > 0) {
        cout << endl << "\t\t => y = " << b1 << "x + " << b0;
    } else if (b0 == 0) {
        cout << endl << "\t\t => y = " << b1 << "x";
    } else {
        cout << endl << "\t\t => y = " << b1 << "x " << b0;
    }

    for (i = 0; i < n; i++) {
        ssx += pow(x[i] - mx, 2);
        ssy += pow(y[i] - my, 2);
        spm += (x[i] - mx) * (y[i] - my);
    }
    sx = sqrt(ssx / (n - 1));
    sy = sqrt(ssy / (n - 1));
    r = spm / ((n - 1) * sx * sy);

    cout << endl << "\t\tMedia de x = " << mx;
    cout << endl << "\t\tMedia de y = " << my;
    cout << endl << "\t\tSuma de x = " << sumax;
    cout << endl << "\t\tSuma de y = " << sumay;
    cout << endl << "\t\tSuma del producto de x y y = " << sumaxy;
    cout << endl << "\t\tSuma del cuadrado de x = " << sumaxx;
    cout << endl << "\t\tDesviación de x = " << sx;
    cout << endl << "\t\tDesviación de y = " << sy;
    cout << endl << "\t\tLa correlación de Pearson r = " << r;

    return 0;
}

