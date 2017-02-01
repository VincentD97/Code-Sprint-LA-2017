#include <iostream>

using namespace std;

#define type long long
#define ModN 10007
#define MaxSteps (type)(1e6)

type A[MaxSteps + 1][3][3];
/*
 A[n] is the matrix of A^n where
      / 0 1 0 \
 A =  | 0 0 1 |
      \ 1 1 1 /
 */
bool known[MaxSteps + 1];

void setup();
void MatMult(type n1, type n2, type n); // A[n] = A[n1] * A[n2]
void calcAn(type n);

int main() {
    setup();
    type t;
    cin >> t;
    type results[t];
    for (int i = 0; i < t; i++) {
        type n;
        cin >> n;
        type totalways = 1;
        for (int j = 0; j < n; j++) {
            type steps;
            cin >> steps;
            type ways;
            if (steps == 1)
                ways = 1;
            else if (steps == 2)
                ways = 2;
            else {
                steps -= 2;
                calcAn(steps);
                ways = (A[steps][2][0] + A[steps][2][1] + A[steps][2][2] * 2) % ModN;
            }
            totalways = (totalways * ways) % ModN;
        }
        results[i] = totalways;
    }
    
    for (int i = 0; i < t; i++)
        cout << results[i] << endl;
    
    
}

inline void setup() {
    memset(known, false, sizeof(MaxSteps));
    A[1][0][0] = A[1][0][2] = A[1][1][0] = A[1][1][1] = 0;
    A[1][0][1] = A[1][1][2] = A[1][2][0] = A[1][2][1] = A[1][2][2] = 1;
    known[1] = true;
}

void MatMult(type n1, type n2, type n) {
    type ans[3][3]; // without this array, errors occur when n1 == n or n2 == n
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) {
            type tmp = 0;
            for (int k = 0; k < 3; k++)
                tmp = (tmp + A[n1][i][k] * A[n2][k][j]) % ModN;
            ans[i][j] = tmp;
        }
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            A[n][i][j] = ans[i][j];
}

void calcAn(type n) {
    if (known[n])
        return;
    known[n] = true;
    type half = n / 2;
    calcAn(half);
    MatMult(half, half, n);
    if (n % 2)
        MatMult(1, n, n);
    return;
}
