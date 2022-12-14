// 输入 arr[n]                                // 输入要排序的序列
// merge_sort(arr[n] , p , q):                // [p , q] 表示对第 p ~ q 区域内的元素进行归并排序
//     if p < q :                             // 对 [p , q] 区域不断采用对半分割的方式，最终将整个区域划分为多个仅包含 1 个元素（p==q）的序列
//         mid = ⌊(p+q)/2⌋
//         merge_sort(arr , p , mid)
//         merge_sort(arr , mid+1 , q)
//         merge(arr , p , mid , q)          // 调用实现归并过程的代码模块
// merge_sort() 用于将整个序列分割成多个子序列，merge() 用来合并这些子序列，合并的实现方式为：
// 从 [p, mid] 和 [mid+1, q] 两个区域的元素分别拷贝到 leftarr 和 rightarr 区域。
// 从 leftarr 和 rightarr 区域中各个取出第一个元素，比较它们的大小；
// 将较小的元素拷贝到 [p, q] 区域，然后从较小元素所在的区域内取出下一个元素，继续进行比较；
// 重复执行第 3 步，直至 leftarr 和 rightarr 内的元素全部拷贝到 [p, q] 为止。如果 leftarr 或者 rightarr 有一方为空，则直接将另一方的所有元素依次拷贝到 [p, q] 区域。
// 伪代码：
// merge(arr[n] , p , mid , q):                          // 该算法表示将 [p , mid] 和 [mid+1 , q] 做归并操作
//     leftnum <- mid - p + 1                            // 统计 [p , mid] 区域内的元素个数
//     rightnum <- q - mid                               // 统计 [mid+1 , q] 区域内的元素个数
//     leftarr[leftnum] <- arr[p ... mid]                // 分别将两个区域内的元素各自拷贝到另外两个数组中
//     rightarr[rightnum] <- arr[mid+1 ... q]
//     i <- 1 , j <- 1
//     for k <- p to q :             // 从 leftarr 和 rightarr 数组中第 1 个元素开始，比较它们的大小，将较小的元素拷贝到 arr 数组的 [p , q] 区域
//         if leftarr[i] ≤ rightarr[j] :
//             arr[k] = leftarr[i]
//             i <- i+1
//         else :
//             arr[k] = right[j]
//             j <- j+1


# include<stdio.h>
void merge(int* arr,int p, int mid,int q);
void merge_sort(int* arr,int p,int q);

int main(){
    int i = 0;
    int arr[8] = {34,12,3,2,65,33,32,31};
    merge_sort(arr,1,8);
    while(i<8){
        printf(" %d ",arr[i]);
        i++;
    }
    //return 0;
}
void merge_sort(int* arr,int p,int q){
    int mid;
    if(arr == NULL || p>q || p==q){
        return ;
    }
    mid = (p+q)/2;
    merge_sort(arr,p,mid);
    merge_sort(arr,mid+1,q);
    merge(arr,p,mid,q);
}
//实现归并操作的函数，归并的两个区域分别为[p,mid]和[mid+1,q]
void merge(int* arr,int p, int mid,int q){
    int i, j,k;
    int leftarr[100],rightarr[100];
    int numL = mid - p + 1;
    int numR = q-mid;
    for ( i = 0; i < numL; i++) {
        leftarr[i] = arr[p - 1 + i];
    }
    leftarr[i] = 2147483647;
    for (i = 0; i < numR; i++) {
        rightarr[i] = arr[mid + i];
    }
    rightarr[i] = 2147483647;
    i = 0;
    j = 0;
    for(k = p;k<=q;k++){
        if(leftarr[i] <=rightarr[j]){
            arr[k-1] = leftarr[i];
            i++;
        } else{
            arr[k-1] = rightarr[j];
            j++;
        }
    }
}

//#include <stdio.h>
////实现分割操作的函数
//void merge_sort(int* arr, int p, int q);
////实现归并操作的函数
//void merge(int* arr, int p, int mid, int q);
//int main() {
//    int i = 0;
//    int arr[8] = { 7,5,2,4,1,6,3,0 };
//    //对 arr 数组中第 1 至 8 个元素进行归并排序
//    merge_sort(arr, 1, 8);
//    while (i < 8)
//    {
//        printf("%d ", arr[i]);
//        i++;
//    }
//    return 0;
//}
////实现分割操作的函数，[p,q] 用于指定归并排序的区域范围，
//void merge_sort(int* arr, int p, int q) {
//    int mid;
//    if (arr == NULL || p > q || p == q) {
//        return ;
//    }
//    mid = (p + q) / 2;
//    //将 [p,q] 分为[p,mid] 和 [mid+1,q] 区域
//    merge_sort(arr, p, mid);
//    merge_sort(arr, mid + 1, q);
//    //对分好的 [p,mid] 和 [mid,q] 进行归并操作
//    merge(arr, p, mid, q);
//}
////实现归并操作的函数，归并的 2 个区域分别为 [p,mid] 和 [mid+1,q]
//void merge(int* arr, int p, int mid, int q) {
//    int i,j,k;
//    int leftarr[100], rightarr[100];
//    int numL = mid - p + 1;
//    int numR = q - mid;
//    //将 arr 数组中 [p,mid] 区域内的元素逐一拷贝到 leftarr 数组中
//    for (i = 0; i < numL; i++) {
//        leftarr[i] = arr[p - 1 + i];
//    }
//    //将 arr 数组中 [mid+1,q] 区域内的元素逐一拷贝到 rightarr 数组中
//    leftarr[i] = 2147483647;
//    for (i = 0; i < numR; i++) {
//        rightarr[i] = arr[mid + i];
//    }
//    rightarr[i] = 2147483647;
//    i = 0;
//    j = 0;
//    //逐一比较 leftarr 和 rightarr 中的元素，每次将较小的元素拷贝到 arr 数组中的 [p,q] 区域内
//    for (k = p; k <= q; k++) {
//        if (leftarr[i] <= rightarr[j]) {
//            arr[k - 1] = leftarr[i];
//            i++;
//        }
//        else {
//            arr[k - 1] = rightarr[j];
//            j++;
//        }
//    }
//}
