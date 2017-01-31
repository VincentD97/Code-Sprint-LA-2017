#include <iostream>

using namespace std;

#define type long long

int main() {
    type n;
    cin >> n;
    type left[n], right[n];
    char character[n];
    for (type i = 0; i < n; i++)
        cin >> left[i] >> right[i] >> character[i];
    
    type num[4];
    char result[4];
    cin >> num[0] >> num[1] >> num[2] >> num[3];
    bool need[4] = {true, true, true, true};
    
    for (type i = n - 1; i >= 0; i--) {
        type l = left[i], r = right[i], c = character[i];
        for (type j = 0; j < 4; j++)
            if (need[j] && num[j] >= l && num[j] <= r) {
                result[j] = c;
                need[j] = false;
            }
    }
    
    for (type i = 0; i < 4; i++)
        (need[i]) ? cout << "a " : cout << result[i] << " ";
    cout << endl;
}
