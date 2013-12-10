// =====================================================================================
// 
//       Filename:  c370_a.cc
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
  //freopen("a.sample.in", "r", stdin);

  int r1, c1, r2, c2;

  while (scanf("%d %d %d %d", &r1, &c1, &r2, &c2) != EOF) {
    // rock
    if (r1 == r2 || c1 == c2) {
      printf("1");
    } else {
      printf("2");
    }
    printf(" ");

    // bishop
    if (((r1 % 2 == c1 % 2) && (r2 % 2 == c2 % 2)) || ((r1 % 2 != c1 % 2) && (r2 % 2 != c2 % 2))) {
      if (abs(r2 - r1) == abs(c2 - c1))
        printf("1");
      else
        printf("2");
    } else {
      printf("0");
    }
    printf(" ");
    
    // king
    if (r1 == r2) {
      printf("%d", abs(c1 - c2));
    } else if (c1 == c2) {
      printf("%d", abs(r1 - r2));
    } else {
      if (abs(r1 - r2) < abs(c1 - c2))
        printf("%d", abs(c1 - c2));
      else
        printf("%d", abs(r1 - r2));
    }
    printf("\n");
    
  }

  return 0;
}

// -------- Samples --------
// 4 3 1 6
// 5 5 5 6
// 1 1 5 3
// 8 1 1 8
