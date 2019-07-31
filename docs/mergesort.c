#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<time.h>
void mergesort(int arr[], int len)
{

	//������鳤��С��2���򷵻�
	if (len < 2)
		return;

	int llen;//�������г���
	int lindex;//��������ͷ����
	int *temp = (int *)malloc(sizeof(int)*len);//�����������ռ�
	int i, j, k;//iָ��ָ��������ͷ��jָ��ָ��������ͷ, kָ���������ͷ
	int lmax, rmax;//lmaxΪ�����������Ͻ磨����Ӧ��С�ڸ�ֵ����rmaxΪ�����������Ͻ磨����С�ڸ�ֵ��

				   //�������г���Ӧ��С�ڴ���������г���len��������ڵ��ڣ���û���������У�
	for (llen = 1; llen < len; llen *= 2) {
		//�������е�������0��ʼ���Զ������������е��ٶȵ����� ��ֵӦ��С��len-llen�������ڵ��ڸ�ֵ����û�ж�Ӧ���������У�
		for (lindex = 0; lindex < len - llen; lindex += (2 * llen)) {
			lmax = lindex + llen;//����������
			rmax = lindex + 2 * llen;//����������
			if (rmax > len)//������������޴���len���ͻᳬ��arr������Χ
				rmax = len;
			i = lindex;//������ָ��
			j = lindex + llen;//������ָ��
			k = 0;//��������ָ��
			while (i < lmax && j < rmax)//�������ж�û�г�������ʱ����ֵ��������ռ�
				temp[k++] = (arr[i] < arr[j] ? arr[i++] : arr[j++]);
			while (i < lmax)//�����л���ֵ������������
				temp[k++] = arr[i++];
			while (j < rmax)//�����л���ֵ������������
				temp[k++] = arr[j++];

			while (k > 0)//��ֵ��temp����arr
				arr[--j] = temp[--k];
		}
	}
	free(temp);
}

int *random_array(int n, int rangel, int rangeh)
{
	assert(rangel < rangeh);
	srand((unsigned)time(NULL));
	int *arr = (int *)malloc(n * sizeof(int));
	int i;
	for (i = 0; i<n; i++)
		arr[i] = rand() % (rangeh - rangel - 1) + rangel;
	return arr;
}

int is_sorted(int arr[], int n)
{
	int i;
	for (i = 1; i < n; i++)
		if (arr[i - 1] > arr[i])
			return 0;
	return 1;
}

int main()
{
	//�̶�����ʱ��������
	//int arr[] = {8, 7, 6, 5, 4, 3, 2, 1, 0};
	//int len = (int)sizeof(arr) / sizeof(*arr);
	//mergesort(arr, len);
	//printf("Merge:\n");
	//int i;
	//for (i=0; i<len; i++)
	//printf("%d ", arr[i]);
	//printf("\n");
 

	//��������ʱ��������
	/* 	int arr[100]; //������������ŵ�����
	int len = 0;
	char c;//���ڶԻس������м��
	printf("������������������س�������\n");
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

	//�������
	int n;
	int i;
	double t;
	clock_t start, finish;
	printf("������Ҫ��������еĳ��ȣ�\n");
	scanf_s("%d", &n);
	int *arr = random_array(n, 0, 1000);
	for (i = 0; i<n; i++)
		printf("%d ", arr[i]);
	printf("/n");
	start = clock();
	mergesort(arr, n);
	finish = clock();
	printf("���Ϊ��\n");
	for (i = 0; i<n; i++)
		printf("%d ", arr[i]);
	t = (double)(finish - start) / CLOCKS_PER_SEC;
	assert(is_sorted(arr, n)==1);
	printf("%d����������Ҫ%f s", n, t);
	free(arr);
	getchar();
	getchar();
}
