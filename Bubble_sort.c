# include <stdio.h>
# define N 5
//创建排序函数
void Bubble_sort(int list[N]){
    int temp = 0;
    for (int i = 0; i < N-1 ; i++) {
        for (int j = 0; j < N-1-i; j++) {
            if (list[j] > list[j + 1]){
                temp = list[j];
                list[j] = list[j+1];
                list[j+1] = temp;
            }
        }
    }

}


int main(){
    int list[N] = {45,3,2,65,12};
    Bubble_sort(list);
    for (int i = 0; i < N; i++) {
        printf("%d",list[i]);
        printf(" ");
    }
}
