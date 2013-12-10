/*
 * =====================================================================================
 *
 *       Filename:  quick_sort.c
 *    Description:  A quick sort implementation.
 *       Compiler:  gcc
 *         Author:  Tengwei Cai (twcai), tengweicai@gmail.com
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define swap(a,b) { (a)^=(b);(b)^=(a);(a)^=(b); }

void quick_sort (int list[], int start, int end) {
    if (start >= end)
        return;
    int pivot = end;
    int i = start - 1;
    for (int j = start; j < end; j ++) {
        if (list[j] <= list[pivot]) {
            i ++;
            if (i != j) swap(list[i], list[j]);
        }
    }
    for (int z = start; z < end; z ++) {
        printf("%d ", list[z]);
    }
    printf("\n");
    if (i + 1 != pivot) swap(list[i+1], list[pivot]);
    quick_sort(list, start, i);
    quick_sort(list, i+2, end);
}

void random_quick_sort (int list[], int start, int end) {
    if (start >= end) return;
    int pivot = start + random() % (end - start);
    if (pivot != end) swap(list[pivot], list[end]);
    pivot = end;
    int i = start - 1;
    for (int j = start; j < end; j ++) {
        if (list[j] <= list[pivot]) {
            i ++;
            if (i != j) swap(list[i], list[j]);
        }
    }
    for (int z = start; z < end; z ++) {
        printf("%d ", list[z]);
    }
    printf("\n");
    if (i + 1 != pivot) swap(list[i+1], list[pivot]);
    random_quick_sort(list, start, i);
    random_quick_sort(list, i+2, end);
}

int main ()
{
    char in_file[1024] = "quick_sort.in";
    freopen(in_file, "r", stdin);

    int len;
    int *list;
    while (scanf("%d", &len) != EOF) {
        list = malloc(len * sizeof(int));
        assert(list);

        for (int i = 0; i < len; i ++) {
            scanf("%d", &list[i]);
        }

        random_quick_sort(list, 0, len - 1);
        
        for (int i = 0; i < len; i ++) {
            printf("%d ", list[i]);
        }
        printf("\n");
    }
    return 0;
}
