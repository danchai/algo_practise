// =====================================================================================
// 
//       Filename:  370C.cc
//    Description:  
//       Compiler:  g++
//         Author:  Tengwei Cai (twcai), tengweicai@gmail.com
// 
// =====================================================================================

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

#define bzero(a,b) memset((a), 0, (b))

struct Pair {
  int color;
  int count;

  Pair() : color(0), count(0) {}
  Pair(int color, int count) : color(color), count(count) {}
};

bool decr(Pair a, Pair b) {
  return a.count == b.count ? a.count < b.color : a.count > b.count;
}

int main()
{
  //freopen("c.sample.in", "r", stdin);
  int n, m, c;
  map <int, int> mittens;

  while (scanf("%d %d", &n, &m) != EOF) {
    mittens.clear();
    for (int i = 0; i < n; i++) {
      scanf("%d", &c);
      assert(c > 0 && c <= 100);
      mittens[c] ++;
    }

    vector <Pair> left, right;
    left.clear();
    for (map <int, int>::iterator it = mittens.begin(); it != mittens.end(); it ++) {
      left.push_back(Pair(it->first, it->second));
    }
    sort(left.begin(), left.end(), decr);
    // move the most frequent mittens to the right
    right = left;
    right.erase(right.begin());
    right.push_back(left[0]);


    if (left[0].count > n / 2) {
      printf("%d\n", (n - left[0].count) * 2);
    } else {
      printf("%d\n", n);
    }

    vector <Pair>::iterator lit = left.begin();
    vector <Pair>::iterator rit = right.begin();
    for(int i = 0; i < n; i ++) {
      printf("%d %d\n", lit->color, rit->color);
      if (--(lit->count) == 0) lit ++;
      if (--(rit->count) == 0) rit ++;
    }
  }
  return 0;
}

// -------- Samples --------
// 18 5
// 1 1 1 1 1 1 1 1 2 2 2 2 3 3 4 4 5 5
// 6 3
// 1 3 2 2 1 1
// 4 2
// 1 2 1 1
// 2 2
// 1 2
// 7 3
// 1 3 1 3 2 2 1
