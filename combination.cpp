#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)
int i, j, k;

long c_permutation(int n, int min) {
  if (n == min) {
    return n;
  } else {
    return n * c_permutation(n - 1, min);
  }
}

long combination(int n, int r) {
  if (n < r)
    return 0;
  else
    return (long)(c_permutation(n, n - r + 1) / c_permutation(r, 1));
}
