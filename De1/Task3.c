#include <stdio.h>
#include <string.h>

#define MAX_N 100001

int solution(char S[]) {
    int A[MAX_N];
    int sum = 0;
    int cnt = 0;
//    int ret = 0;
    int N = strlen(S);

    for (int i = 0; i < N; i++) {
        A[i] = S[i] - '0';
        sum += A[i];
    }
    if (sum % 3 == 0) {
        cnt++;
    }
    for (int i = 0; i < N; i++) {
        int new_sum = sum - A[i];

        for (int j = 0; j <= 9; j++) {
            if (A[i] != j) {
                if ((new_sum + j) % 3 == 0) {
                    cnt++;
                }
            }
        }
        printf("%d\n", cnt);
    }

    return cnt;
}

int main() {
    char S[] = "0081";
    int ret = solution(S);

    printf("Ret = %d \n", ret);

    return 0;
}
