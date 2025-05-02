#include <iostream>
#include <cmath>
using namespace std;

// Example: f(x) = x^3 - x - 11
double f(double x)
{
    return x * x * x - x - 11;
}

// Derivative: f'(x) = 3x^2 - 1
double df(double x)
{
    return 3 * x * x - 1;
}

int main()
{
    double x0, x1;
    int maxIterations;
    double tolerance;

    // Input from the user
    cout << "Enter the initial guess: ";
    cin >> x0;

    cout << "Enter the maximum number of iterations: ";
    cin >> maxIterations;

    cout << "Enter the tolerance (e.g., 0.0001): ";
    cin >> tolerance;

    int iteration = 0;
    while (iteration < maxIterations)
    {
        double fx = f(x0);
        double dfx = df(x0);

        if (dfx == 0)
        {
            cout << "Mathematical error: derivative is zero." << endl;
            return 1;
        }

        x1 = x0 - fx / dfx;

        cout << "Iteration " << iteration + 1 << ": x = " << x1 << endl;

        if (fabs(x1 - x0) < tolerance)
        {
            break;
        }

        x0 = x1;
        iteration++;
    }

    cout << "\nApproximate root is: " << x1 << endl;
    return 0;
}
