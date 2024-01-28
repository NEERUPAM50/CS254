#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

void print(const vector<vector<int>>& matrix, int start_row, int start_column, int end_row, int end_column) {
    for (int i = start_row; i <= end_row; i++) {
        for (int j = start_column; j <= end_column; j++) {
            cout << setw(10) << matrix[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

void addMatrix(const vector<vector<int>>& A, const vector<vector<int>>& B, vector<vector<int>>& C, int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
}

vector<vector<int>> multiplyMatrix(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();

    if (n == 1) {
        vector<vector<int>> C(1, vector<int>(1, A[0][0] * B[0][0]));
        return C;
    }

    int splitIndex = n / 2;

    vector<vector<int>> A11(splitIndex, vector<int>(splitIndex));
    vector<vector<int>> A12(splitIndex, vector<int>(splitIndex));
    vector<vector<int>> A21(splitIndex, vector<int>(splitIndex));
    vector<vector<int>> A22(splitIndex, vector<int>(splitIndex));

    vector<vector<int>> B11(splitIndex, vector<int>(splitIndex));
    vector<vector<int>> B12(splitIndex, vector<int>(splitIndex));
    vector<vector<int>> B21(splitIndex, vector<int>(splitIndex));
    vector<vector<int>> B22(splitIndex, vector<int>(splitIndex));

    vector<vector<int>> C11(splitIndex, vector<int>(splitIndex));
    vector<vector<int>> C12(splitIndex, vector<int>(splitIndex));
    vector<vector<int>> C21(splitIndex, vector<int>(splitIndex));
    vector<vector<int>> C22(splitIndex, vector<int>(splitIndex));

    for (int i = 0; i < splitIndex; i++)
        for (int j = 0; j < splitIndex; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + splitIndex];
            A21[i][j] = A[i + splitIndex][j];
            A22[i][j] = A[i + splitIndex][j + splitIndex];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + splitIndex];
            B21[i][j] = B[i + splitIndex][j];
            B22[i][j] = B[i + splitIndex][j + splitIndex];
        }

    vector<vector<int>> P1 = multiplyMatrix(A11, B11);
    vector<vector<int>> P2 = multiplyMatrix(A12, B21);
    vector<vector<int>> P3 = multiplyMatrix(A11, B12);
    vector<vector<int>> P4 = multiplyMatrix(A12, B22);
    vector<vector<int>> P5 = multiplyMatrix(A22, B21);
    vector<vector<int>> P6 = multiplyMatrix(A21, B11);
    vector<vector<int>> P7 = multiplyMatrix(A21, B12);

    addMatrix(P1, P2, C11, splitIndex);
    addMatrix(P3, P4, C12, splitIndex);
    addMatrix(P5, P6, C21, splitIndex);
    addMatrix(P6, P7, C22, splitIndex);

    vector<vector<int>> C(n, vector<int>(n));
    for (int i = 0; i < splitIndex; i++)
        for (int j = 0; j < splitIndex; j++) {
            C[i][j] = C11[i][j];
            C[i][j + splitIndex] = C12[i][j];
            C[i + splitIndex][j] = C21[i][j];
            C[i + splitIndex][j + splitIndex] = C22[i][j];
        }

    return C;
}

void scanMatrix(vector<vector<int>>& matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        vector<int> row;
        for (int j = 0; j < cols; j++) {
            int value;
            cin >> value;
            row.push_back(value);
        }
        matrix.push_back(row);
    }
}

int main() {
    freopen("input1.txt", "r", stdin);
    freopen("output1.txt", "w", stdout);

    int ROW_1, COL_1, ROW_2, COL_2;
    cin >> ROW_1 >> COL_1 >> ROW_2 >> COL_2;

    vector<vector<int>> matrix_A;
    vector<vector<int>> matrix_B;

    scanMatrix(matrix_A, ROW_1, COL_1);
    print(matrix_A, 0, 0, ROW_1 - 1, COL_1 - 1);

    scanMatrix(matrix_B, ROW_2, COL_2);
    print(matrix_B, 0, 0, ROW_2 - 1, COL_2 - 1);

    vector<vector<int>> result_matrix = multiplyMatrix(matrix_A, matrix_B);
    print(result_matrix, 0, 0, ROW_1 - 1, COL_2 - 1);

    return 0;
}
