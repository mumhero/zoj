#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vii;

int max_sum(const vii &m, int y1, int y2)
{
    int f = m[0][y2] - (y1==0 ? 0 : m[0][y1-1]);
    int r = f;
    for (int i = 1; i < m.size(); ++i) {
        int num = m[i][y2] - (y1==0 ? 0 : m[i][y1-1]);
        f = max(f+num, num);
        r = max(f, r);
    }
    return r;
}

int main()
{
    int N;
    scanf("%d", &N);

    vii m(N, vi(N, 0));
    for (int i = 0; i < N; ++i) {
        int sum = 0;
        for (int j = 0; j < N; ++j) {
            int x;
            scanf("%d", &x);
            sum += x;
            m[i][j] = sum;
        }
    }

    int r = INT_MIN;
    for (int y1 = 0; y1 < N; ++y1) {
        for (int y2 = y1; y2 < N; ++y2) {
            r = max(max_sum(m, y1, y2), r);
        }
    }

    printf("%d\n", r);
}

