#include <iostream>
using namespace std;

#include "difderivative.h"
#include "runge.h"
#include "alignment.h"

void output(double *res, int num)
{
    for (int i = 0; i < num; i++) {
        cout << res[i] << " ";
    }
    cout << endl;
}

int main()
{
    double x[6] = {1, 2, 3, 4, 5, 6};
    double y[6] = {0.571, 0.889, 1.091, 1.231, 1.333, 1.412};
    double step = 1;
    int num = 6;
    double *res = nullptr;

    int choose = 0;
    while (choose != 9) {
        cout << "\nChoose method:\n";
        cout << "\tLeft Different Derivative....1\n";
        cout << "\tRight Different Derivative...2\n";
        cout << "\tCentre Different Derivative..3\n";
        cout << "\tLeft Runge...................4\n";
        cout << "\tRight Runge..................5\n";
        cout << "\tLeft Alignment...............6\n";
        cout << "\tRight Alignment..............7\n";
        cout << "\tSecond Differential..........8\n";
        cout << "\tExit.........................9\n";
        cin >> choose;

        if (choose == 1) {
            res = LeftDifDerivative(y, num, step);
            output(res, num);
            delete[] res;
        }

        if (choose == 2) {
            res = RightDifDerivative(y, num, step);
            output(res, num);
            delete[] res;
        }

        if (choose == 3) {
            res = CentreDifDerivative(y, num, step);
            output(res, num);
            delete[] res;
        }

        if (choose == 4) {
            res = LeftRunge(y, num, step);
            output(res, num);
            delete[] res;
        }

        if (choose == 5) {
            res = RightRunge(y, num, step);
            output(res, num);
            delete[] res;
        }

        if (choose == 6) {
            res = LeftAlignment(x, y, num);
            output(res, num);
            delete[] res;
        }

        if (choose == 7) {
            res = RightAlignment(x, y, num);
            output(res, num);
            delete[] res;
        }

        if (choose == 8) {
            res = SecondDifferential(y, num, step);
            output(res, num);
            delete[] res;
        }
    }
    return 0;
}


