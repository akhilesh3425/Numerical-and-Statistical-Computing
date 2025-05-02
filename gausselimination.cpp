#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of equations: ";
    cin >> n;

    vector<vector<double>> mat(n, vector<double>(n + 1));
    vector<double> x(n);

    // Input augmented matrix
    cout << "Enter the augmented matrix (coefficients and constants):" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Equation " << i + 1 << ": ";
        for (int j = 0; j <= n; j++)
        {
            cin >> mat[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        // Make the diagonal element 1
        if (mat[i][i] == 0)
        {
            cout << "Mathematical Error: Division by zero." << endl;
            return -1;
        }
        for (int j = i + 1; j < n; j++)
        {
            double ratio = mat[j][i] / mat[i][i];
            for (int k = 0; k <= n; k++)
            {
                mat[j][k] -= ratio * mat[i][k];
            }
        }
    }

    for (int i = n - 1; i >= 0; i--)
    {
        x[i] = mat[i][n];
        for (int j = i + 1; j < n; j++)
        {
            x[i] -= mat[i][j] * x[j];
        }
        x[i] /= mat[i][i];
    }

    cout << "\nSolution:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "x" << i + 1 << " = " << x[i] << endl;
    }

    return 0;
}
