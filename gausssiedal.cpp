#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main()
{
    int n, maxIterations;
    double tolerance;

    cout << "Enter the number of equations: ";
    cin >> n;

    vector<vector<double>> a(n, vector<double>(n));
    vector<double> b(n), x(n, 0), prev_x(n, 0);

    cout << "Enter the coefficients of the equations:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Row " << i + 1 << ": ";
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }

    cout << "Enter the constant terms:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    cout << "Enter the maximum number of iterations: ";
    cin >> maxIterations;

    cout << "Enter the tolerance (e.g., 0.001): ";
    cin >> tolerance;

    // Gauss-Seidel Iteration
    for (int iter = 1; iter <= maxIterations; iter++)
    {
        bool done = true;

        for (int i = 0; i < n; i++)
        {
            double sum = b[i];
            for (int j = 0; j < n; j++)
            {
                if (j != i)
                    sum -= a[i][j] * x[j];
            }
            double xi_new = sum / a[i][i];

            if (fabs(xi_new - x[i]) > tolerance)
                done = false;

            x[i] = xi_new;
        }

        // Print current iteration
        cout << "Iteration " << iter << ": ";
        for (int i = 0; i < n; i++)
        {
            cout << "x" << i + 1 << " = " << x[i] << "  ";
        }
        cout << endl;

        if (done)
            break;
    }

    // Final 
    cout << "\nFinal Solution:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "x" << i + 1 << " = " << x[i] << endl;
    }

    return 0;
}
