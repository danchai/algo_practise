// =====================================================================================
// 
//       Filename:  373A.cc
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

int main()
{
  freopen("a.sample.in", "r", stdin);
  int k;
  int cnt[10];

  while (scanf("%d", &k) != EOF) {
    int tmp;
    char row[5];
    bzero(cnt, sizeof(cnt));
    for (int i = 0; i < 4; i ++) {
      scanf("%s", row);
      for (int j = 0; j < 4; j ++) {
        tmp = row[j] - '0';
        if (tmp > 0 && tmp < 10) cnt[tmp] ++;
      }
    }
    bool win = true;
    for (int i = 0; i < 10; i ++) {
      if (cnt[i] > k * 2) win = false;
    }
    printf("%s\n", win ? "YES" : "NO");
  }

  return 0;
}
