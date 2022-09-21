
//思路：伪代码

// arr[1...N]                        // 待查找序列
// linear_search(arr , value):       // value 表示要查找的目标元素
//     for i <-1 to length(arr):     // 从 arr 序列中第一个元素开始遍历，直至最后一个元素
//         if arr[i] == value:       // 如果成功找到一个元素和目标元素匹配，则返回该元素所处的位置
//             return i                    
//     return -1                     // 返回 -1，表示查找失败。

// 某些场景中，待查找序列可能包含多个目标元素，需要我们全部找到。这种情况下，顺序查找算法仍然适用，只需对实现过程做一下微调即可，对应的伪代码如下：
// arr[1...N]       //待查找序列
// index[1...N]     //存储目标元素的位置
// j <- 1
// linear_search(arr , value):       // value 表示要查找的目标元素
//     for i <-1 to length(arr):     // 从 arr 序列中第一个元素开始遍历，直至最后一个元素
//         if arr[i] == value:       // 如果成功找到一个元素和目标元素匹配，则返回该元素所处的位置
//             index[j] <- i         // 将目标元素所在序列的位置存储到 index 中
//             j <- j + 1            // j 自加，为下次在 index 中存储目标元素的位置做准备       
//     return index




//顺序查找
#include <stdio.h>
#define N 10     //待查找序列的元素个数
//实现顺序查找，arr[N] 为待查找序列，value 为要查找的目标元素
int linear_search(int arr[N], int value) {
    int i;
    //从第 1 个元素开始遍历
    for (i = 0; i < N; i++) {
        //匹配成功，返回元素所处的位置下标
        if (arr[i] == value) {
            return i;
        }
    }
    //匹配失败，返回 -1
    return -1;
}

int main()
{
    int arr[11] = { 10,14,19,26,27,31,33,35,42,44,};
    int add = linear_search(arr, 33);
    if (add != -1) {
        printf("search for is %d ", add + 1);
    }
    else {
        printf("error");
    }
    return 0;
}
