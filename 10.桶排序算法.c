#include <stdio.h>
#include <stdlib.h>

#define N 7   // 待排序序列中的元素个数
#define NBUCKET 6  // 桶的数量
#define INTERVAL 10  // 每个桶能存放的元素个数
//建立桶
struct Node {
    float data;
    struct Node *next;
};

void BucketSort(float arr[]);
struct Node *InsertionSort(struct Node *list);
void print(float arr[]);

int main() {
    float array[N] = { 0.42, 0.32, 0.23, 0.52, 0.25, 0.47, 0.51 };
    BucketSort(array);
    print(array);
    return 0;
}

// 桶排序，arr 为待排序序列
void BucketSort(float arr[]) {
    int i, j;
    struct Node **buckets;
    // 创建所有桶
    buckets = (struct Node **)malloc(sizeof(struct Node *) * NBUCKET);
    // 设置每个桶为空桶
    for (i = 0; i < NBUCKET; ++i) {
        buckets[i] = NULL;
    }
    // 根据规定，将 arr 中的每个元素分散存储到各个桶中
    for (i = 0; i < N; ++i) {
        struct Node *current;
        int pos = arr[i] * 10;  //根据规则，确定元素所在的桶
        //创建存储该元素的存储块，并连接到指定的桶中
        current = (struct Node *)malloc(sizeof(struct Node));
        current->data = arr[i];
        current->next = buckets[pos];
        buckets[pos] = current;
    }
    // 调用自定义的排序算法，对各个桶进行排序
    for (i = 0; i < NBUCKET; ++i) {
        buckets[i] = InsertionSort(buckets[i]);
    }
    // 合并所有桶内的元素
    for (j = 0, i = 0; i < NBUCKET; ++i) {
        struct Node *node;
        node = buckets[i];
        while (node) {
            arr[j++] = node->data;
            node = node->next;
        }
    }
}

// 自定义的排序算法，用于对各个桶内元素进行排序
struct Node *InsertionSort(struct Node *list) {
    struct Node *k, *nodeList;
    if (list == NULL || list->next == NULL) {
        return list;
    }
    nodeList = list;
    k = list->next;
    nodeList->next = NULL;
    while (k != NULL) {
        struct Node *ptr;
        if (nodeList->data > k->data) {
            struct Node *tmp;
            tmp = k;
            k = k->next;
            tmp->next = nodeList;
            nodeList = tmp;
            continue;
        }
        for (ptr = nodeList; ptr->next != 0; ptr = ptr->next) {
            if (ptr->next->data > k->data)
                break;
        }
        if (ptr->next != 0) {
            struct Node *tmp;
            tmp = k;
            k = k->next;
            tmp->next = ptr->next;
            ptr->next = tmp;
            continue;
        }
        else {
            ptr->next = k;
            k = k->next;
            ptr->next->next = 0;
            continue;
        }
    }
    return nodeList;
}

void print(float ar[]) {
    int i;
    for (i = 0; i < N; ++i) {
        printf("%.2f ", ar[i]);
    }
}

