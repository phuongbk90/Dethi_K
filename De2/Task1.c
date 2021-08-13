#include <stdio.h>
#include <string.h>
#include <limits.h>

#define MAX_N 100001

int sum_num(int N) {
    int ret = 0;
    while (N) {
        ret += N % 10;
        N /= 10;
    }

    return ret;
}

int solution(int N) {
    int ans = -1;
    int sum_N = sum_num(N);
    int sum_M = 2 * sum_N;

    while (++N) {
        if (sum_num(N) == sum_M) {
            ans = N;
            break;
        }
    }

    return ans;
}

int main() {
    int N = 10;
    int K = 5;
    int ans = solution(99);
    printf("ans: %d\n", ans);

    return 0;
}

