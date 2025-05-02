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
    double x0, x1, x2;
    int maxIterations;
    double tolerance;

    cout << "Enter two initial guesses x0 and x1: ";
    cin >> x0 >> x1;

    cout << "Enter the maximum number of iterations: ";
    cin >> maxIterations;

    cout << "Enter the tolerance (e.g., 0.0001): ";
    cin >> tolerance;

    // Iterative process
    for (int i = 1; i <= maxIterations; i++)
    {
        // Secant method formula
        x2 = x1 - (f(x1) * (x1 - x0)) / (f(x1) - f(x0));

        cout << "Iteration " << i << ": x2 = " << x2 << ", f(x2) = " << f(x2) << endl;

        if (fabs(f(x2)) < tolerance)
        {
            break;
        }

        x0 = x1;
        x1 = x2;
    }

    cout << "\nApproximate root is: " << x2 << endl;
    return 0;
}
