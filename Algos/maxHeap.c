#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int size;
    int capacity;
} PriorityQueue;

PriorityQueue* createPriorityQueue(int capacity) {
    PriorityQueue* pq = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    pq->data = (int*)malloc(sizeof(int) * capacity);
    pq->size = 0;
    pq->capacity = capacity;
    return pq;
}

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void push(PriorityQueue *pq, int value) {
    if (pq->size == pq->capacity) {
        pq->capacity *= 2;
        pq->data = (int*)realloc(pq->data, pq->capacity * sizeof(int));
    }

    pq->data[pq->size] = value;
    int i = pq->size;
    pq->size++;

    while (i != 0 && pq->data[(i - 1) / 2] < pq->data[i]) {
        swap(&pq->data[i], &pq->data[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int top(PriorityQueue *pq) {
    if (pq->size == 0) {
        printf("Priority Queue is empty.\n");
        return -1;
    }
    return pq->data[0];
}

void pop(PriorityQueue *pq) {
    if (pq->size == 0) {
        printf("Priority Queue is empty.\n");
        return;
    }

    pq->data[0] = pq->data[pq->size - 1];
    pq->size--;

    int i = 0;
    while (1) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int largest = i;

        if (left < pq->size && pq->data[left] > pq->data[largest]) {
            largest = left;
        }

        if (right < pq->size && pq->data[right] > pq->data[largest]) {
            largest = right;
        }

        if (largest == i) {
            break;
        }

        swap(&pq->data[i], &pq->data[largest]);
        i = largest;
    }
}

void destroyPriorityQueue(PriorityQueue *pq) {
    free(pq->data);
    free(pq);
}

int main() {
    PriorityQueue *pq = createPriorityQueue(10);

    push(pq, 3);
    push(pq, 10);
    push(pq, 5);
    push(pq, 6);
    push(pq, 7);

    printf("Top element: %d\n", top(pq)); 

    pop(pq);
    printf("Top element after pop: %d\n", top(pq));

    destroyPriorityQueue(pq);
    return 0;
}
