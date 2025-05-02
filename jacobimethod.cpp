#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int n, maxIterations;
    double tolerance;

    cout << "Enter the number of equations: ";
    cin >> n;

    vector<vector<double>> a(n, vector<double>(n));
    vector<double> b(n), x(n, 0), prev_x(n, 0);

    // Input coefficient matrix
    cout << "Enter the coefficients of the equations:\n";
    for (int i = 0; i < n; i++) {
        cout << "Row " << i + 1 << ": ";
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    // Input constants
    cout << "Enter the constant terms:\n";
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    // Input max iterations and tolerance
    cout << "Enter the maximum number of iterations: ";
    cin >> maxIterations;

    cout << "Enter the tolerance (e.g., 0.001): ";
    cin >> tolerance;

    // Jacobi Iteration
    for (int iter = 1; iter <= maxIterations; iter++) {
        bool done = true;

        for (int i = 0; i < n; i++) {
            double sum = b[i];
            for (int j = 0; j < n; j++) {
                if (j != i) sum -= a[i][j] * prev_x[j];
            }
            x[i] = sum / a[i][i];
            if (fabs(x[i] - prev_x[i]) > tolerance) {
                done = false;
            }
        }

        // Update previous values
        prev_x = x;

        // Print current iteration
        cout << "Iteration " << iter << ": ";
        for (int i = 0; i < n; i++) {
            cout << "x" << i + 1 << " = " << x[i] << "  ";
        }
        cout << endl;

        if (done) break;
    }

    // Final 
    cout << "\nFinal Solution:\n";
    for (int i = 0; i < n; i++) {
        cout << "x" << i + 1 << " = " << x[i] << endl;
    }

    return 0;
}
