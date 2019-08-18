#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)
int i, j, k;

vector<pair<string, int>> stringvec_runlength(vector<string> src_string_vector) {
    vector<pair<string, int>> result;
    string string_being_compressed;
    int string_count;
    REP(i, src_string_vector.size()) {
        if (i == 0) {
            string_count = 1, string_being_compressed = src_string_vector[i];
        } else if (string_being_compressed == src_string_vector[i]) {
            string_count++;
        } else {
            result.push_back(make_pair(string_being_compressed, string_count));
            string_being_compressed = src_string_vector[i];
            string_count = 1;
        }
    }
    result.push_back(make_pair(string_being_compressed, string_count));
    return result;
}

int main() {
    int N;
    cin >> N;

    vector<string> S(N);

    REP(i, N) {
        cin >> S[i];
    }

    vector<pair<string, int>> runlength_string = stringvec_runlength(S);

    REP(i, runlength_string.size()) {
        cout << runlength_string[i].first << " " << runlength_string[i].second << endl;
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
