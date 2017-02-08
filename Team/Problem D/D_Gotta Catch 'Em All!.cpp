#include <iostream>
#include <vector>

using namespace std;

#define type long long
#define N 100000

bool ispoke[N];
vector<type> edges[N];
bool visited[N];

type dfs(type s) {
    visited[s] = true;
    type maximum = 0;
    for (int i = 0; i < edges[s].size(); i++) {
        type next = edges[s][i];
        if (!visited[next])
            maximum = max(maximum, dfs(next));
    }
    return maximum + (int) ispoke[s];
}

int main() {
    type t;
    cin >> t;
    type results[t];

    for (type i = 0; i < t; i++) {
        memset(ispoke, false, sizeof(ispoke));
        memset(visited, false, sizeof(visited));
        type n, p, e;
        cin >> n >> p >> e;
        for (int j = 0; j < n; j++)
            edges[j] = vector<type>();
        
        for (int j = 0; j < p; j++) {
            type x;
            cin >> x;
            ispoke[x] = true;
        }
        for (int j = 0; j < e; j++) {
            type node1, node2;
            cin >> node1 >> node2;
            edges[node1].push_back(node2);
            edges[node2].push_back(node1);
        }
        results[i] = dfs(0);
    }
    
    for (type i = 0; i < t; i++)
        cout << results[i] << endl;
}
