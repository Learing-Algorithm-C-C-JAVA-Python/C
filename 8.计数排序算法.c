// //计数排序算法，list 为待排序序列
// countingSort(list)
//     size <- len(list)      // 获取 list 序列中的元素个数=
//     max <- getMax(list)    // 找到 list 序列中的最大值
//     array[0...max+1] <- 0    // 定义一个长度为 max+1 的数组，
//     for j <- 0 to size      // 创建 array[max+1] 并统计各个元素的出现次数
//         array[list[j]] <- array[list[j]] + 1
//     for i <- 1 to max       // 对 array[max+1] 存储的元素做累加操作
//         array[i] <- array[i] + array[i - 1];
//     for j <- size to 0 // 根据 array[max+1] 中的累加值，找到各个元素排序后的具体位置
//         output[array[list[i]] - 1] = list[i]; // output存储有序序列
//         array[list[i]] <- array[list[i]] - 1  // 确定一个元素的位置后，array[max+1] 中相应位置的数值要减 1
//     return output[size]


// 代码实现：
#include <stdio.h>
#define N 7       //待排序序列中的元素个数
#define MAX 100   //待排序序列中的最大值不能超过 100
//找到数组中的最大值
int getMax(int list[]) {
    int i, max = list[0];
    for (i = 1; i < N; i++) {
        if (list[i] > max)
            max = list[i];
    }
    return max;
}

void countingSort(int list[]) {
    int i;
    //第 1 步，找到序列中的最大值
    int max = getMax(list);
    //第 2 步，创建一个数组，长度至少为 max+1，并初始化为 0
    int array[MAX] = { 0 };
    int output[N] = { 0 };
    //第 3 步，统计各个元素的出现次数，并存储在相应的位置上
    for (i = 0; i < N; i++) {
        array[list[i]]++;
    }
    //第 4 步，累加 array 数组中的出现次数
    for (i = 1; i <= max; i++) {
        array[i] += array[i - 1];
    }

    //第 5 步，根据 array 数组中的信息，找到各个元素排序后所在位置，存储在 output 数组中
    for (i = N - 1; i >= 0; i--) {
        output[array[list[i]] - 1] = list[i];
        //第 6 步，数组相应位置上的值减1
        array[list[i]]--;
    }

    // 将 output 数组中的数据原封不动地拷贝到 list 数组中
    for (i = 0; i < N; i++) {
        list[i] = output[i];
    }
}

void printlist(int list[]) {
    int i;
    for (i = 0; i < N; ++i) {
        printf("%d ", list[i]);
    }
}

int main() {
    int list[] = { 4, 2, 2, 8, 3, 3, 1 };
    //进行计数排序
    countingSort(list);
    printlist(list);
}
