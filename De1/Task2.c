
#include <bits/stdc++.h>

using namespace std;

void DFS(vector<int> map[], int v, int N, int visited[]) {
    if (v == N) {
        visited[v] = 1;
        return;
    }

    if (!visited[v]) {
        visited[v] = 1;
        for (int i = 0; i < map[v].size(); i++) {
            if (map[v].at(i) == v + 1) {
                DFS(map, v + 1, N, visited);
            }
        }
    }
}

bool solution(int N, int A[], int B[]) {
    bool ans = false;
    //int K = 5;

    int K = 4;
    vector<int> map[N + 1];
    int visited[N + 1];
    memset(visited, 0, sizeof(visited));

    for (int i = 0; i < K; i++) {
        map[A[i]].push_back(B[i]);
        map[B[i]].push_back(A[i]);
    }

    DFS(map, 1, N, visited);

    if (visited[N]) {
        ans = true;
    }

    return ans;
}

int main() {

    bool ans = false;
    int N = 4;
    int A[] = {1, 2, 4, 4, 3};
    int B[] = {2, 3, 1, 3, 1};

    ans = solution(N, A, B);

    cout << ans;
    return 0;
}

