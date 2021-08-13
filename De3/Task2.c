
#include <bits/stdc++.h>
//#include <algorithm>

using namespace std;

int solution(string s) {
    vector<string> subStr;

    for (int i = 0; i < s.size(); i++) {
        for (int j = 1; j <= s.size() - i; j++) {
            subStr.push_back(s.substr(i, j));
        }
    }

    map<string, int> table;
    for (auto s : subStr) {
        table[s]++;
    }

    vector<string> tempList;
    for (auto s: table) {
        if (s.second == 1) {
            tempList.push_back(s.first);
        }
    }

    int ans = INT_MAX;

    for (int i = 0; i < tempList.size(); i++) {
        string tmp = tempList.at(i);
        int length = tmp.length();
        ans = min(ans, length);

    }

    return ans == INT_MAX ? 0 : ans;
}

int main() {

    string S = "aabbbabaaa";
    string S1 = "zyzyzyz";
    cout << solution(S1);
    return 0;
}

