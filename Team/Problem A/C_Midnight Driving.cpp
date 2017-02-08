#include <iostream>

using namespace std;

#define type long long

int main() {
    type t;
    cin >> t;
    type results[t];
    for (type i = 0; i < t; i++)
        results[i] = -1;
    for (type i = 0; i < t; i++) {
        type length, numtraffic, speedlim;
        cin >> length >> numtraffic >> speedlim;
        type pos[numtraffic], period[numtraffic];
        for (type j = 0; j < numtraffic; j++)
            cin >> pos[j] >> period[j];
        type speed;
        for (speed = speedlim; speed > 0; speed--) {
            bool flag = true;
            for (type j = 0; j < numtraffic; j++)
                if ( ((pos[j] / speed) / period[j]) % 2 ) {
                    flag = false;
                    break;
                }
            if (flag) {
                results[i] = speed;
                break;
            }
        }
        
    }
    
    for (type i = 0; i < t; i++)
        cout << results[i] << endl;
    
        
    
}
