# include <stdio.h>
//define定义初始化元素的个数
# define N 8

//creat Shell_sort
void Shell_sort(int list[N]){
	//定义变量
	int temp,i,j;
	//初始化间隔数为1
	int interval = 1;
	//计算最大间隔
	while(interval<N/3){
		interval = interval*3+1;
	}
	  //根据间隔数，不断划分序列，并对各子序列排序
	while(interval>0){
		//对子序列做间隔排序
		for (i = interval;i<N;i++)
		{
			/* code */
			temp = list[i];
			j = i;
			  while (j > interval - 1 && list[j - interval] >= temp) {
                list[j] = list[j - interval];
                j -= interval;
            }
        if (j != i)
        {
        	/* code */
        	list[j] = temp;
        }
		}
		//计算新的间隔数，继续划分序列
		interval = (interval - 1)/3;
	}

}



int main(int argc, char const *argv[])
{
	/* code */
	int i;
	//初始化数组
    int list[N] = { 90,33,42,10,14,19,27,44 };
    Shell_sort(list);
    //遍历
    for (int i = 0; i < N; i++)
    {
    	/* code */
    	printf(" %d " ,list[i]);
    }
	return 0;
}
