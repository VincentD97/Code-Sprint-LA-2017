#include <iostream>
#include <string>
#include <cctype>

using namespace std;

#define type long long

int main() {
    type t;
    cin >> t;
    type results[t];
    type dx[8] = {0, 0, -1 ,1, 1, 1, -1, -1};
    type dy[8] = {-1, 1, 0, 0, 1, -1, 1, -1};
    
    for (type i = 0; i < t; i++) {
        type m, n;
        cin >> m >> n;
        type k;
        cin >> k;
        type candy[m + 2][n + 2];
        memset(candy, 0, sizeof(candy));
        for (type j = 0; j < k; j++) {
            type x, y;
            cin >> x >> y;
            candy[x][y] = -1;   // toothpaste
            for (int s = 0; s < 8; s++)
                candy[x + dx[s]][y + dy[s]]++;
        }
        type sum = 0;
        for (type j = 1; j <= m; j++)
            for (type s = 1; s <= n; s++)
                if (candy[j][s] > 0)
                    sum += candy[j][s];
        results[i] = sum;
    }
    
    for (type i = 0; i < t; i++)
        cout << results[i] << endl;
}
