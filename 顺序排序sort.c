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
