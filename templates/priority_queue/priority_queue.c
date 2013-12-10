/*
 * =====================================================================================
 *
 *       Filename:  priority_queue.c
 *    Description:  Priority queue maintains a heap and provides following interfaces
 *                    * push - add an element into queue
 *                    * top  - return the top element of queue (largest or smallest)
 *                    * pop  - return and remove the top element from queue
 *
 *       Compiler:  gcc
 *         Author:  Tengwei Cai (twcai), tengweicai@gmail.com
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define swap(a,b) { (a)^=(b);(b)^=(a);(a)^=(b); }

typedef struct priority_queue {
    int (*push) (struct priority_queue *, int);
    int (*top)  (struct priority_queue *);
    int (*pop)  (struct priority_queue *);
    int (*inc)  (struct priority_queue *, int, int);
    int len;
    int max_size;
    int queue[];
} priority_queue;

void max_heapify(int heap[], int index, int len) {
    int l = index * 2 + 1;
    int r = index * 2 + 2;
    int max = heap[index];
    int fg  = index;
    if (l < len && heap[l] > max) {
        max = heap[l];
        fg = l;
    }
    if (r < len && heap[r] > max) {
        max = heap[r];
        fg = r;
    }
    if (fg != index) {
        swap(heap[index], heap[fg]);
        max_heapify(heap, fg, len);
    }
}

int pq_push(priority_queue *self, int ele) {
    if (self->len == self->max_size) {
        return -1;
    }
    else {
        int index = self->len++;
        int pare;

        self->queue[index] = ele;
        while (index > 0) {
            pare = (index - 1) / 2;
            if (self->queue[index] > self->queue[pare]) {
                swap(self->queue[index], self->queue[pare]);
                index = pare;
            } else {
                break;
            }
        }
        return 1;
    }
}

int pq_top(priority_queue *self) {
    if (self->len < 1) {
        return -1;
    }
    return self->queue[0];
}

int pq_pop(priority_queue *self) {
    if (self->len < 1) {
        return -1;
    }
    else if (self->len == 1) {
        self->len = 0;
        return self->queue[0];
    }
    else {
        -- self->len;
        swap(self->queue[0], self->queue[self->len]);
        max_heapify(self->queue, 0, self->len);
        return self->queue[self->len];
    }
}

int pq_inc(priority_queue *self, int id, int val) {
    if (self->len < 1 || id >= self->len) {
        return -1;
    } else {
        int index = id;
        int pare;
        while (index > 0) {
            pare = (index - 1) / 2;
            if (self->queue[index] > self->queue[pare]) {
                swap(self->queue[index], self->queue[pare]);
                index = pare;
            } else {
                break;
            }
        }
        return 1;
    }
}

priority_queue * newPriorityQueue(int size) {
    priority_queue *self;
    self = malloc(sizeof(priority_queue) + size);
    if (self == NULL) {
        fprintf(stderr, "Failed to allocate %d byte for new priority queue", size);
        exit(2);
    }
    self->max_size = size;
    self->push = &pq_push;
    self->top  = &pq_top;
    self->pop  = &pq_pop;
    self->inc  = &pq_inc;
    self->len  = 0;
    return self;
}

priority_queue * newPriorityQueueWithArray(int size, int init_list[], int list_len) {
    priority_queue *self;
    self = malloc(sizeof(priority_queue) + size);
    if (self == NULL) {
        fprintf(stderr, "Failed to allocate %d byte for new priority queue", size);
        exit(1);
    }

    memcpy(self->queue, init_list, sizeof(int) * list_len);
    for (int i = list_len / 2 - 1; i >= 0; i --) {
        max_heapify(self->queue, i, list_len);
    }

    self->max_size = size;
    self->len  = list_len;
    self->push = &pq_push;
    self->top  = &pq_top;
    self->pop  = &pq_pop;
    return self;
}

void destroyPriorityQueue(priority_queue * self) {
    if (self != NULL) {
        free(self);
        self = NULL;
    }
}

int main () {
    const char in_file[1024] = "priority_queue.in";
    int init_len;
    int query_no;

    freopen(in_file, "r", stdin);

    while (scanf("%d %d", &init_len, &query_no) != EOF) {
        int max_queue_len = init_len + query_no;
        priority_queue * pq = newPriorityQueue(max_queue_len);

        for (int i = 0; i < init_len; i ++) {
            int tmp;
            scanf("%d", &tmp);
            pq->push(pq, tmp);
        }

        for (int i = 0; i < query_no; i ++) {
            char op[1024];
            int op_no;
            scanf("%s", op);
            if (strcmp(op, "push") == 0) {
                scanf("%d", &op_no);
                pq->push(pq, op_no);
            }
            else if (strcmp(op, "pop") == 0) {
                printf("Q #%d: %d\n", i + 1, pq->pop(pq));
            }
            else if (strcmp(op, "top") == 0) {
                printf("Q #%d: %d\n", i + 1, pq->top(pq));
            } else if (strcmp(op, "inc") == 0) {
                scanf("%d", &op_no);
                pq->inc(pq, op_no, 1);
            }
        }

        destroyPriorityQueue(pq);
    }
    
    return 0;
}
