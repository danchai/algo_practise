// =====================================================================================
// 
//       Filename:  370B.cc
//    Description:  Found the set with no subset out
//       Compiler:  g++
//         Author:  Tengwei Cai (twcai), tengweicai@gmail.com
// 
// =====================================================================================

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

typedef unsigned long long ULL;

#define bzero(a,b) memset((a), 0, (b))

struct Set128 {
  ULL a[2];

  Set128() {
    bzero(a, sizeof(a));
  }

  void clear();
  void set(int offset);
  bool equal(Set128 &s);
  bool child(Set128 &s);
};

int main()
{
  // freopen("b.sample.in", "r", stdin);
  int n, m, a;
  Set128 set[100];
  bool lose[100];

  while (scanf("%d", &n) != EOF) {
    for (int i = 0; i < n; i ++) {
      scanf("%d", &m);
      set[i].clear();
      for (int j = 0; j < m; j ++) {
        scanf("%d", &a);
        set[i].set(a);
      }
    }

    bzero(lose, sizeof(lose));
    for (int i = 0; i < n; i ++) {
      for (int j = i + 1; j < n; j ++) {
        if (set[i].equal(set[j])) {
          lose[i] = 1;
          lose[j] = 1;
        } else if (set[i].child(set[j])) {
          lose[j] = 1;
        } else if (!lose[i] && set[j].child(set[i])) {
          lose[i] = 1;
        }
      }
      printf("%s\n", lose[i] ? "NO" : "YES");
    }
    printf("\n");
  }
  return 0;
}

void Set128::clear() {
    bzero(a, sizeof(a));
}

void Set128::set(int offset) {
  if (offset <= 63) {
    a[0] |= (ULL)1 << (offset - 1);
  } else {
    a[1] |= (ULL)1 << (offset - 64);
  }
}

bool Set128::equal(Set128 &s) {
  return (a[0] == s.a[0] && a[1] == s.a[1]);
}

bool Set128::child(Set128 &s) {
  ULL t[2];
  t[0] = (a[0] | s.a[0]) ^ s.a[0];
  t[1] = (a[1] | s.a[1]) ^ s.a[1];
  return (t[0] == 0 && t[1] == 0);
}

// -------- Samples --------
// 3
// 1 1
// 3 2 4 1
// 2 10 11
// 2
// 1 1
// 1 1
// 3
// 1 66
// 2 63 66
// 2 2 66
