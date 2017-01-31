#include <iostream>
#include <vector>

using namespace std;

#define type long long

int main() {
    type t;  // # of testcase;
    cin >> t;
    type results[t];
    for (type i = 0; i < t; i++) {
        type m, n, linenum;
        cin >> m >> n;
        cin >> linenum;
        type x1, y1, x2, y2;
        type horlines = 0, verlines = 0;
        for (type j = 0; j < linenum; j++) {
            cin >> x1 >> y1 >> x2 >> y2;
            if (x1 == x2)
                verlines++;
            else
                horlines++;
        }
        results[i] = (horlines + 1) * (verlines + 1);
    }
    
    for (type i = 0; i < t; i++)
        cout << results[i] << endl;
}
