// =====================================================================================
// 
//       Filename:  373B.cc
//    Description:  
//       Compiler:  g++
//         Author:  Tengwei Cai (twcai), tengweicai@gmail.com
// 
// =====================================================================================

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

#define bzero(a,b) memset((a), 0, (b))

typedef unsigned long long ULL;

int s(ULL n) {
  int ret = 0;
  do {
    n /= 10;
    ret ++;
  } while (n > 0);
  return ret;
}

ULL max_dig(int cnt) {
  ULL ret = 1;
  for (int i = 0; i < cnt; i ++) {
    ret *= 10;
  }
  return ret - 1;
}

int main()
{
  freopen("b.sample.in", "r", stdin);
  ULL w, m, k;
  while (cin >> w >> m >> k) {
    w /= k;
    ULL ret = 0;
    ULL smax;
    int sv;
    while (w > 0) {
      sv = s(m);
      smax = max_dig(sv);
      if ((smax - m + 1) * sv > w) {
        ret += w / sv;
        w = 0;
      } else {
        ret += smax - m + 1;
        w -= (smax - m + 1) * sv;
        m = smax + 1;
      }
    }
    cout << ret << endl;
  }

  return 0;
}
