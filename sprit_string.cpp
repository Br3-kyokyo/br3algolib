#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)
int i, j, k;

vector<string> sprit_string(string srcstr, string delim) {
  vector<string> result;

  string fragment = "";
  for (int i = 0; i < srcstr.length(); i++) {
    bool delimMatch = true;
    for (int j = 0; j < delim.length(); j++) {
      if (srcstr[i + j] != delim[j]) {
        delimMatch = false;
        break;
      }
    }

    if (delimMatch) {
      result.push_back(fragment);
      fragment = "";
      i += delim.length() - 1;
    } else {
      fragment.push_back(srcstr[i]);
    }
  }
  result.push_back(fragment);

  return result;
}

int main() {
  string S, delim;
  cin >> S >> delim;

  vector<string> splited_string = sprit_string(S, delim);

  REP(i, splited_string.size()) {
    cout << splited_string[i] << endl;
  }
}