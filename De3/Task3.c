
#include <bits/stdc++.h>

using namespace std;
bool ans = false;

void DFS(vector<int> map[], int v, int N, int cnt, int visited[], int parent[]) {
    visited[v] = 1;
    if (cnt == N && parent[1] == v) {
        ans = true;
        return;
    }
    for (int i = 0; i < map[v].size(); i++) {
        int tmp = map[v].at(i);
        if (!visited[tmp]) {
            DFS(map, tmp, N, cnt + 1, visited, parent);
        }
    }
}

bool solution(int A[], int B[]) {

    int N = 4;
    int cnt = 1;
    vector<int> map[N + 1];
    int visited[N + 1];
    int parent[N + 1];

    memset(visited, 0, sizeof(visited));
    memset(parent, -1, sizeof(parent));

    for (int i = 0; i < N; i++) {
        map[A[i]].push_back(B[i]);
        parent[B[i]] = A[i];
    }

    DFS(map, 1, N, cnt, visited, parent);
    return ans;
}

int main() {
    int N = 3;
    int A[] = {1, 2, 3, 4};
    int B[] = {2, 1, 4, 3};

    ans = solution(A, B);

    cout << ans;
    return 0;
}

