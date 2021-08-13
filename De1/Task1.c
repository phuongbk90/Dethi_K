#include <stdio.h>
#include <string.h>
#include <limits.h>

#define MAX_N 100001

int min(int a, int b) {
    return a > b ? b : a;
}

int solution(int A[], int N) {
    int num[5] = {0};
    int sum[5] = {0};

    int ret = INT_MAX;
    int is_same = 1;

    for (int i = 0; i < N; i++) {
        if (A[i] != A[0]) {
            is_same = 0;
        }
    }
    if (is_same) {
        return 0;
    }

    for (int i = 0; i < N; i++) {
        if (A[i] == 1) {
            num[1]++;
        } else if (A[i] == 2) {
            num[2]++;
        } else if (A[i] == 3) {
            num[3]++;
        } else {
            num[4]++;
        }
    }
    if (num[1]) {
        sum[1] = num[2] + 2 * num[3] + 3 * num[4];
    }
    if (num[2]) {
        sum[2] = num[1] + num[3] + 2 * num[4];
    }
    if (num[3]) {
        sum[3] = 2 * num[1] + num[2] + num[3];
    }
    if (num[4]) {
        sum[4] = 3 * num[1] + 2 * num[2] + num[3];
    }

    for (int i = 1; i <= 4; i++) {
        if (num[i]) {
            ret = min(ret, sum[i]);
        }
    }

    return ret;
}

int main() {
    int A[] = {3, 3, 3};
    int N = sizeof(A) / sizeof(A[0]);
    int ret = solution(A, N);
    printf("ret: %d\n", ret);

    return 0;
}

