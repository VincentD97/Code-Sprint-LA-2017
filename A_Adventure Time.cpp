#include <iostream>
#include <string>
#include <cctype>

using namespace std;

#define type long long

int main() {
    type n;
    cin >> n;
    bool results[n];    // true for good
    for (type i = 0; i < n; i++) {
        string str;
        cin >> str;
        bool occur[26] = {false};
        type l = (type) str.length();
        bool good = true;
        for (type j = 0; j < l; j++) {
            char ch = tolower(str[j]);
            if (!isdigit(ch) && !occur[ch - 'a']) {
                occur[ch - 'a'] = true;
                good = !good;
            }
        }
        results[i] = good;
    }
    
    for (type i = 0; i < n; i++)
        if (results[i])
            cout << "INVITE TO PARTY\n";
        else
            cout << "TRASH TALK THE USER\n";
}
