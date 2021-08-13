
#include <bits/stdc++.h>
//#include <algorithm>

using namespace std;

string solution(string A[], string B[], string P) {

    int N = 3;

    map<string, string> table;

    for (int i = 0; i < N; i++) {
        if (B[i].find(P) != string::npos) {
            string tmp1 = A[i];
            string tmp2 = B[i];
            table.insert({tmp1, tmp2});
//            table.insert(pair<string, string>(tmp1, tmp2));
        }
    }

    string ans;

    if (table.empty()) {
        ans = "NO CONTACT";
    } else {
        ans = table.begin()->first;
    }

    map<string, string>::iterator it;
//    for (it = table.begin(); it != table.end(); it++) {
//        cout << it->first << " " << it->second << endl;
//    }

    return ans;
}

int main() {

    string A[] = {"adam", "eva", "lep"};
    string B[] = {"121212121", "111111111", "444555666"};
    string P = "112";

    string ans = solution(A, B, P);

    cout << ans;
    return 0;
}
