#include <iostream>
#include <cmath>
using namespace std;

// f(x) = x^3 - x - 11
double f(double x)
{
    return x * x * x - x - 11;
}

int main()
{
    double a, b, c;
    int maxIterations;
    double tolerance;

    cout << "Enter the initial guesses a and b (a < b): ";
    cin >> a >> b;

    cout << "Enter the maximum number of iterations: ";
    cin >> maxIterations;

    cout << "Enter the tolerance (e.g., 0.0001): ";
    cin >> tolerance;

    // Check if f(a) and f(b) have opposite signs
    if (f(a) * f(b) > 0)
    {
        cout << "Invalid interval: f(a) and f(b) must have opposite signs." << endl;
        return 1;
    }

    // Iterative process
    for (int i = 1; i <= maxIterations; i++)
    {
        // Regula Falsi formula
        c = (a * f(b) - b * f(a)) / (f(b) - f(a));

        cout << "Iteration " << i << ": c = " << c << ", f(c) = " << f(c) << endl;

        if (fabs(f(c)) < tolerance)
        {
            break;
        }

        if (f(a) * f(c) < 0)
        {
            b = c;
        }
        else
        {
            a = c;
        }
    }

    cout << "\nApproximate root is: " << c << endl;
    return 0;
}
