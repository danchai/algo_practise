// =====================================================================================
// 
//       Filename:  373C.cc
//    Description:  
//       Compiler:  g++
//         Author:  Tengwei Cai (twcai), tengweicai@gmail.com
// 
// =====================================================================================

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

#define bzero(a,b) memset((a), 0, (b))
#define SZ 500001

int kgr[SZ];

bool cmp(int a, int b) {
  return a > b;
}

int main()
{
  freopen("c.sample.in", "r", stdin);
  int n;

  while (scanf("%d", &n) != EOF) {
    for (int i = 0; i < n; i ++) {
      scanf("%d", &kgr[i]);
    }

    sort(kgr, kgr + n, cmp);

    int mid = n / 2;
    int be = 0;
    int se = n / 2;
    int ret = n;
    while (be < mid && se < n) {
      if (kgr[be] >= kgr[se] * 2) {
        ret --;
        be ++;
        se ++;
      } else {
        se ++;
      }
    }
    printf("%d\n", ret);
  }

  return 0;
}
