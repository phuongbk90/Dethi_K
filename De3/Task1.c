#include <stdio.h>
#include <string.h>
#include <limits.h>

#define MAX_N 100001

int solution(int N, int K) {
    int ret = -1;
    int cnt = 0;

    if ((N * (N + 1) / 2 < K)) {
        return ret;
    }

    for (int i = N; i >= 1; i--) {
        if (K == 0) {
            break;
        }
        if (K >= i) {
            K -= i;
            cnt++;
        }
    }

    if (K > 0) {
        ret = -1;
    }

    if (cnt > 0) {
        ret = cnt;
    }

    return ret;
}

int main() {
    int N = 10;
    int K = 5;
    int ret = solution(N, K);
    printf("ret: %d\n", ret);

    return 0;
}

