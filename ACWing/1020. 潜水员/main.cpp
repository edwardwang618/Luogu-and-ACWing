#include <iostream>
#include <cstring>
using namespace std;

const int N = 25, M = 80;

// n是氧需要的量，m是氮需要的量，K是气缸个数
int n, m, K;
int f[N][M];

int main() {
    cin >> n >> m >> K;

    memset(f, 0x3f, sizeof f);
        
    f[0][0] = 0;
    while (K--) {
        // 分别是氧、氮容量和气缸重量
        int v1, v2, w;
        cin >> v1 >> v2 >> w;

        for (int i = n; i >= 0; i--)
            for (int j = m; j >= 0; j--)
                f[i][j] = min(f[i][j], f[max(i - v1, 0)][max(j - v2, 0)] + w);
    }

    cout << f[n][m] << endl;

    return 0;
}