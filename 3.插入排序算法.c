# include <stdio.h>
# define MAX 8


void insertion_sort(int list[MAX]){
	int insertion_ele;
	//int i;
	int postion;
	for (int i = 0; i < MAX; i++)
	{
		/* code */
		insertion_ele = list[i];
		postion = i;
		while(postion>0&&list[postion-1]>insertion_ele){
			list[postion] = list[postion-1];
			postion--;
		}
		if (postion != i)
		{
			/* code */
			list[postion] = insertion_ele;
		}
	}
}


int main(int argc, char const *argv[])
{
	/* main */
	//int i；
	int list[MAX] = {23,12,4,65,34,10,1,11};
	insertion_sort(list);
	for (int i = 0; i < MAX; i++)
	{
		/* code */
		printf("%d",list[i]);
		printf("   ");
	}
	return 0;
}
