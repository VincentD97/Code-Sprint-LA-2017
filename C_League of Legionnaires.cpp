#include <iostream>
#include <string>

using namespace std;

#define type long long

int main() {
    type t = 0;  // # of testcase;
    cin >> t;
    string results = "";
    for(int i = 0; i < t; i++) {
        type m, n, a, b;
        cin >> m >> n >> a >> b;
        char map[m + 1][n + 1];
        for (type j = 1; j <= m; j++)
            for (type k = 1; k <= n; k++)
                cin >> map[j][k];
        type x = a, y = b;   // current
        
        
        string route ="";
        char dir[4] = {'U', 'D', 'L', 'R'};
        type dx[4] = {-1, 1, 0, 0};
        type dy[4] = {0, 0, -1, 1};


        for (int j = 0; j < 4; j++) {
            type tmp_x = x + dx[j];
            type tmp_y = y + dy[j];
            if (map[tmp_x][tmp_y] == '#' && tmp_x >= 0 && tmp_x <= m && tmp_y >= 0 && tmp_y <= n) {
                route += dir[j];
                x = tmp_x; y = tmp_y;
                map[x][y] = '.';
                j = -1; // initialize i for searching next step
            }
        }
        results += route + "\n";
    }
    
    cout << results;
}
