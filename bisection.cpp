#include <iostream>
#include <cmath>
using namespace std;

double f(double x)
{
    return pow(x, 3) - x - 11; // Example function: f(x) = x^2 - 4
}

int main()
{

    double a, b, c;

    int max_interations, iterations = 0;

    cout << "Enter the value of a and b (a<b): ";

    cin >> a >> b;
    cout << "Enter the maximum number of iterations: ";
    cin >> max_interations;

    if (f(a) * f(b) > 0)
    {
        cout << "The function has the same sign at a and b. Bisection method cannot be applied." << endl;
        return 1;
    }

    while ((b - a) / 2.0 > 0.00001 && iterations < max_interations)
    {
        c = (a + b) / 2.0;

        if (f(c) == 0.0)
            break;
        else if (f(c) * f(a) < 0)
            b = c;
        else
            a = c;

        iterations++;
    }

    cout << "the root is: " << fixed;
    cout.precision(3);
    cout << (a + b) / 2.0 << endl;
    return 0;
}