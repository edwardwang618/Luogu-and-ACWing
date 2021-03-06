#include <iostream>
using namespace std;

const int N = 24;

int op[8][7] = {
    {0, 2, 6, 11, 15, 20, 22},
    {1, 3, 8, 12, 17, 21, 23},
    {10, 9, 8, 7, 6, 5, 4},
    {19, 18, 17, 16, 15, 14, 13},
    {23, 21, 17, 12, 8, 3, 1},
    {22, 20, 15, 11, 6, 2, 0},
    {13, 14, 15, 16, 17, 18, 19},
    {4, 5, 6, 7, 8, 9, 10}
};

int oppo[8] = {5, 4, 7, 6, 1, 0, 3, 2};
int center[8] = {6, 7, 8, 11, 12, 15, 16, 17};

int q[N];
int path[100];

int f() {
    int cnt[4] = {0};
    for (int i = 0; i < 8; i++) cnt[q[center[i]]]++;

    int s = 0;
    for (int i = 1; i <= 3; i++) s = max(cnt[i], s);

    return 8 - s;
}

void operate(int x) {
    int t = q[op[x][0]];
    for (int i = 0; i < 6; i++) q[op[x][i]] = q[op[x][i + 1]];
    q[op[x][6]] = t;
}

bool dfs(int depth, int max_depth, int last) {
    int h = f();
    if (depth + h > max_depth) return false;
    if (!h) return true;

    for (int i = 0; i < 8; i++) {
        if (last == oppo[i]) continue;
        operate(i);
        path[depth] = i;
        if (dfs(depth + 1, max_depth, i)) return true;
        operate(oppo[i]);
    }

    return false;
}

int main() {
    while (cin >> q[0], q[0]) {
        for (int i = 1; i < N; i++) cin >> q[i];

        int max_depth = 0;
        while (!dfs(0, max_depth, -1)) max_depth++;

        if (!max_depth) cout << "No moves needed" << endl;
        else {
            for (int i = 0; i < max_depth; i++) printf("%c", path[i] + 'A');
            cout << endl;
        }

        printf("%d\n", q[center[0]]);
    }

    return 0;
}