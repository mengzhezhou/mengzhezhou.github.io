'''C
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<time.h>
void mergesort(int arr[],int len)
{
	
	//如果数组长度小于2，则返回
	if (len < 2)
		return;
	
	int llen;//左子序列长度
	int lindex;//左子序列头索引
	int *temp = (int *)malloc(sizeof(int)*len);//申请额外数组空间
	int i, j, k;//i指针指向左序列头，j指针指向有序列头, k指向额外数组头
	int lmax, rmax;//lmax为左序列索引上界（索引应该小于该值），rmax为右序列索引上界（索引小于该值）
	
	//左子序列长度应该小于待排序的序列长度len（如果大于等于，则没有右子序列）
	for (llen = 1; llen < len; llen *= 2){
		//左子序列的索引从0开始，以二倍的左子序列的速度递增， 其值应该小于len-llen（若大于等于该值，则没有对应的右子序列）
		for (lindex = 0; lindex < len-llen; lindex += (2 * llen)){
			lmax = lindex + llen;//左序列上限
			rmax = lindex + 2 * llen;//右序列上限
			if (rmax > len)//如果右序列上限大于len，就会超出arr索引范围
				rmax = len;
			i = lindex;//左序列指针
			j = lindex + llen;//右序列指针
			k = 0;//额外数组指针
			while (i < lmax && j < rmax)//左右序列都没有超出界限时，将值赋给额外空间
				temp[k++] = (arr[i] < arr[j] ? arr[i++] : arr[j++]);
			while (i < lmax)//左序列还有值，给额外数组
				temp[k++] = arr[i++];
			while (j < rmax)//有序列还有值，给额外数组
				temp[k++] = arr[j++];
			
			while (k > 0)//将值从temp赋给arr
				arr[--j] = temp[--k];	
		}
	}
	free(temp);
}

int *random_array(int n, int rangel, int rangeh)
{
	assert(rangel < rangeh);
	srand((unsigned)time(NULL));
	int *arr = (int *)malloc(n*sizeof(int));
	int i;
	for(i=0; i<n; i++)
		arr[i] = rand()%(rangeh-rangel-1)+rangel;
	return arr;	
}

bool is_sorted(int arr, int n)
{
	int i;
	for (i=1; i < n; i++)
		if (arr[i-1] > arr[i])
			return false;
	return true;
}

int main()
{
	//固定输入时的主函数
/* 	int arr[] = {8, 7, 6, 5, 4, 3, 2, 1, 0};
	int len = (int)sizeof(arr) / sizeof(*arr);
	mergesort(arr, len);
	printf("Merge:\n");
	int i;
	for (i=0; i<len; i++)
		printf("%d ", arr[i]);
	printf("\n");
	return 0; */
	
	//自由输入时的主函数
/* 	int arr[100]; //输入序列所存放的数组
	int len = 0;
	char c;//用于对回车键进行检测
	printf("请输入任意个数，按回车键结束\n");
	printf("Input:\n");
	while(1) {
		scanf("%d", &arr[len++]);
		c = getchar();
		if (c == '\n')
			break;		
	}
	mergesort(arr, len);
	printf("Merge:\n");
	int i;
	for (i=0; i<len; i++)
		printf("%d ", arr[i]);
	printf("\n");
	return 0;	 */
	
	//随机生成
	
	int n;
	double t;
	clock_t start, finish;
	printf("请输入要排序的序列的长度：\n");
	scanf("%d", &n);
	int *arr = randomarr(n, 0, 1000);
	start=clock();
	mergesort(arr, n);
	finish = clock();
	t = double(finish - start) / CLOCKS_PER_SEC;
	assert(is_sorted(arr, n));
	printf("%d个数排序需要%f s", n, t);	
}
'''
