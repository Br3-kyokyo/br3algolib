#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)
int i, j, k;

vector<pair<char, int>> string_runlength(string s) {

    vector<pair<char, int>> result;

    char cur;
    int count = 1;
    REP(k, s.length()) {
        if (k == 0) {
            cur = s[k];
        }
        if (s[k] == cur) {
            count++;
        } else {
            result.push_back(make_pair(cur, count));
            cur = s[k];
            count = 1;
        }
    }
    result.push_back(make_pair(cur, count));

    return result;
}

int main() {

    string S;
    cin >> S;

    sort(S.begin(), S.end());
    vector<pair<char, int>> S_runlength = string_runlength(S);

    REP(i, S_runlength.size()) {
        cout << S_runlength[i].first << " " << S_runlength[i].second << endl;
    }
}

// testcase
//
// 5
// aaaaaaaaaa
// aaaaaaaaaa
// aaaaaaaaaa
// bbbbbbbbbb
// bbbbbbbbbb

// runlength compress
// if(i==0) memo first value
// else if(A[i] is equal to memorized value) count++
// else add compress result to result vector, and initialize memo and count
