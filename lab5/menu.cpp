#include "menu.h"
#include <iostream>
using namespace std;

double menu()
{
    int n = 0;
    cout << "Input n:\n";
    cin >> n;

    int m = 0;
    cout << "Input m:\n";
    cin >> m;

    double t = 0;
    cout << "Input parametr t:\n";
    cin >> t;

    int chin = 0;
    cout << "Choose internal formula to integrate:\n";
    cout << "Gauss.............1\n";
    cout << "Simpson...........2\n";
    cin >> chin;

    int chex = 0;
    cout << "Choose external formula to integrate:\n";
    cout << "Gauss.............1\n";
    cout << "Simpson...........2\n";
    cin >> chex;

    double res = Integrate(n, m, t, chin, chex);

    return res;
}
