#include <bits/stdc++.h>

#define pii pair<int, int>
#define F first
#define S second
#define mp make_pair

#define v vector

using namespace std;

int n, m, cur = 0;
v<int> cows(100001), comp(100001, -1);
v<pii> edges[100001]; // edges[i].F = node to, edges[i].S = height

void dfs(int node, int x) {
    if (comp[node] == cur) return;
    comp[node] = cur;
    for (pii edge : edges[node]) {
        if (edge.S >= x) dfs(edge.F, x);
    }
}

bool check(int x) {
    for (int i = 1; i <= n; i++) comp[i] = -1;
    
    for (int i = 1; i <= n; i++) {
        if (comp[i] < 0) {
            dfs(i, x); cur++;
        }
    }
    
    for (int i = 1; i <= n; i++) {
        if (comp[cows[i]] != comp[i]) return false;
    }
    return true;
}

int main() {
    cin >> n >> m;
    
    for (int i = 1; i <= n; i++) cin >> cows[i];
    for (int i = 1; i <= m; i++) {
        int a, b, h; 
        cin >> a >> b >> h;
        
        edges[a].push_back(mp(b, h));
        edges[b].push_back(mp(a, h));
    }
    
    int l = 1, r = 1000000001;
    while (l != r) {
        int mid = (l + r + 1) / 2;
        
        if (check(mid)) l = mid;
        else            r = mid - 1;
    }
    
    if (r > 1000000000) cout << "-1\n";
    else                cout << r << '\n';
}
