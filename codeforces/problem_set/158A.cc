// =====================================================================================
// 
//       Filename:  158A.cc
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

#define SZ 60

int sc[SZ];

int main()
{
    int n, k;
    while (scanf("%d %d", &n, &k) != EOF) {
        for (int i = 0; i < n; i ++) {
            scanf("%d", &sc[i]);
        }
        int cur = k - 1;
        if (sc[cur] > 0) {
            while (cur < (n - 1) && sc[cur] == sc[cur + 1]) {
                cur ++;
            }
        } else {
            while (cur >= 0 && sc[cur] == 0) {
                cur --;
            }
        }
        printf("%d\n", cur + 1);
    }
    return 0;
}
