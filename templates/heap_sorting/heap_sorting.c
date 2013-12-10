/*
 * =====================================================================================
 *
 *       Filename:  heap_sorting.c
 *    Description:  Heap sorting - O(n*lgn), stable or not? sorting method.
 *                  
 *                  for i (n .. 1)
 *                      Max-heapify(array, i)
 *                      exchange(array[i], array[0])
 *
 *       Compiler:  gcc
 *         Author:  Tengwei Cai (twcai), tengweicai@gmail.com
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define exchange(a, b) { (a) ^= (b); (b) ^= (a); (a) ^= (b); }

void max_heapify (int array[], int index, int len) {
    int max = array[index];
    int flag = index;
    int l = index * 2;
    int r = index * 2 + 1;

    if (l < len && array[l] > max) {
        max = array[l];
        flag = l;
    }
    if (r < len && array[r] > max) {
        max = array[r];
        flag = r;
    }
    
    if (flag != index) {
        exchange(array[index], array[flag]);
        max_heapify(array, flag, len);
    }
}

void heap_sorting (int array[], int len) {
    for (int i = (len - 1) / 2; i >= 0; i --) {
        max_heapify(array, i, len);
    }

    for (int i = len - 1; i >= 0; i --) {
        exchange(array[i], array[0]);
        max_heapify(array, 0, i);
    }
}

int main () {
    char in_file[1024] = "heap_sorting.in";
    int *array;
    int len;

    freopen(in_file, "r", stdin);

    while (scanf("%d", &len) != EOF) {
        array = malloc(sizeof(int) * len);
        for (int i = 0; i< len; i ++) {
            scanf("%d", &array[i]);
        }

        heap_sorting(array, len);

        for (int i = 0; i < len; i ++) {
            printf("%10d ", array[i]);
            if (i % 7 == 6)
                printf("\n");
        }
        printf("\n\n");

        free(array);
    }

    return 0;
}
