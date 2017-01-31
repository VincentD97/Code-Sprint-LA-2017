#include <iostream>
using namespace std;

#define type long long

int main() {
    type t;  // # of testcase
    cin >> t;
    type results[t];
    for (type i = 0; i < t; i++) {
        type ans = 0;
        type p /* # of types */, n /* # of total flowers */;
        cin >> p >> n;
        for (type j = 0; j < p && n > 0; j++) {
            type beauty, max_num;
            cin >> beauty >> max_num;
            if (max_num > n)
                max_num = n;
            ans += beauty * max_num;
            n -= max_num;
        }
        results[i] = ans;
    }
    
    for (type i = 0; i < t; i++)
        cout << results[i] << endl;
}
