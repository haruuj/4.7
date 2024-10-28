#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double calculateLn(double x, double eps, int& termCount) {
    double sum = 0.0;
    double term = x - 1;
    termCount = 1;
    sum += term;

    while (fabs(term) > eps) {
        term *= -((x - 1) * termCount) / (termCount + 1);
        sum += term;
        termCount++;
    }

    return sum;
}

int main() {
    double xStart, xEnd, dx, eps;
    cout << " x1= ";
    cin >> xStart;
    cout << " x2= ";
    cin >> xEnd;
    cout << " dx= ";
    cin >> dx;
    cout << "eps= ";
    cin >> eps;
    cout << "\n--------------------------------------------\n";
    cout << "|     x     |   ln(x)   |  summ  | number of add-ins |\n";
    cout << "--------------------------------------------\n";
    for (double x = xStart; x <= xEnd; x += dx) {
        if (x <= 0 || x > 2) {
            cout << "| " << setw(9) << x << " |   invalid value   |\n";
            continue;
        }

        int termCount = 0;
        double sum = calculateLn(x, eps, termCount);
        double actualLn = log(x);
        cout << "| " << setw(9) << x
            << " | " << setw(9) << actualLn
            << " | " << setw(9) << sum
            << " | " << setw(9) << termCount << " |\n";
    }

    cout << "--------------------------------------------\n";

    return 0;
}