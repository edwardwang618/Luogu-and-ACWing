#include <iostream>
#include <cstring>
using namespace std;

const int N = 1010, mod = 1e9 + 7;
int n, m;
int f[N], g[N];

int main() {
    cin >> n >> m;
    for (int i = 0; i <= m; i++) g[i] = 1;

    for (int i = 1; i <= n; i++) {
        int v, w;
        cin >> v >> w;
        for (int j = m; j >= v; j--) {
            int maxv = max(f[j], f[j - v] + w);
            int cnt = 0;
            if (maxv == f[j]) cnt += g[j];
            if (maxv == f[j - v] + w) cnt += g[j - v];
            g[j] = cnt % mod;
            f[j] = maxv;
        }
    }

    cout << g[m] << endl;

    return 0;
}