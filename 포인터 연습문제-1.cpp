#include<stdio.h>

/*int main()
{
	int arr[5] = { 1,2,3,4,5 };
	int* p = NULL;
	int i;
	p = arr;
	for (i = 0; i < 5; i++)
	{
		printf("%d", ++(*p));//(*p)���� ������Ű�� ��� ��  1 2 3 4 5 �� ������ ���� �ƴ� 2 3 4 5 6 �� �߻�
		p++;//�ּҸ� ������Ű�� ���̹Ƿ� *p�� ���� ������ �Ͱ��� ���谡 ����
	}
	printf("\n");
	return 0;
}*/
/*int main()
{
	int arr[5] = { 1,2,3,4,5 };
	int* p = NULL;
	int i;
	p = arr;
	for (i = 0; i < 5; i++)
	{
		printf("%d", *p++);//p�� ������ ǥ���� �� p�� �ּҰ��� �����ϹǷ� ����� 1 2 3 4 5 �� ���´�.
	}
	printf("\n");
	return 0;
}
*/
/*int get_sum_average(int arr[], int size, double* average)//avg�� �ּҸ� �޾Ƽ� �Լ������� �۵���
{
	int sum = 0;
	int i;
	for (i = 0; i < size; i++)
	{
		sum += arr[i];//scores�� �迭�� ���ҵ��� ���� ����
	}
	if (average != NULL)
	{
		*average = (double)sum / size;
	}
	return sum;
}
int main()
{
	int scores[5] = { 98,99,78,85,91 };
	double ave;

	printf("�հ�:%d\n", get_sum_average(scores, 5, &ave));
	printf("���:%.2f\n", ave);
	return 0;
}*/
/* void max_min(int x, int y, int size, int crr[], int drr[], int* max_num, int* min_num);

int main()
{
	int a = 10, b = 15;
	int arr[10] = {};
	int brr[10] = {};
	int max = 0, min = 0;
	max_min(a, b, 10, arr, brr, &max, &min);
	for (int i = 0; i < 10; i++)
		printf("%d", brr[i]);
	printf("\n");
	printf("%d,%d",max,min);
	return 0;
}
void max_min(int x, int y,int size,int crr[],int drr[],int*max_num,int*min_num)
{
	int i;
	int j = 0;
	for (i = 1; i <= x; i++)
		if (x % i == 0)
		{
			crr[j] = i;
			j++;
		}
	j = 0;
	for (i = 1; i <= y; i++)
		if (y % i == 0)
		{
			drr[j] = i;
			j++;
		}
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			if (drr[j] != 0)
			{
				if (drr[j] = crr[i])
				{
					if (*max_num < drr[j])
						*max_num = drr[j];
				}
			}
		}
	}
	*min_num = x * y / *max_num;//����
}*/
/*int main()
{
	int x[3] = {1,2,3};
	int* p = x;
	for (int i = 0; i < 3; i++)
	{
		printf("x[%d]�� �ּ�:%p\n",i, p++);
	}
	return 0;
}*/
/*int main()
{
	double x[10] = { 0.10,2.00,3.40,5.20,4.50,7.80,9.70,1.40,6.60,7.20 };
	double* p = x;
	for (int i = 0; i < 10; i++,p++)
	{
		printf("%.2f ", ( * p)++);
	}
}*/
/*int main()
{
	int x[10] = { 44,32,65,23,45,76,77,89,23,45 };//����
	int* p = x;
	printf("�迭:");
	for (int i = 0; i < 10; i++)
		printf("%d ", *(p)++);
	printf("\n");
	printf("����:");
	for (int i =9; i>-1; i--,p--)
		printf("%d ",*(p)--);
	return 0;
}*/
/*int main()
{
	double x[10] = { 0.10,2.00,3.40,5.20,4.50,7.80,9.70,1.40,6.60,7.20 };
	double* p = x;
	double sum=0;
	for (int i = 0; i < 10; i++)
	{
		sum += p[i];
	}
	printf("�迭:");
	for (int i = 0; i < 10; i++, p++)
	{
		printf("%.2f ", (*p)++);
	}
	printf("\n");
	printf("���:%f", sum / 10);
	return 0;
}*/
/*void arith_seq(int arr[], int x, int y);//����
int main()
{
	int x[10] = { 0 };
	int a, b;
	printf("ù ��°��:");
	scanf_s(" % d\n", &a);
	printf("����:");
	scanf_s("%d\n:", &b);
	arith_seq(x,a,b);
	printf("��������:");
	for (int i = 0; i < 10; i++)
	{
		printf("%d", x[i]);
	}
	return 0;
}
void arith_seq(int arr[], int x, int y)
{
	arr[0] = x;
	for (int i = 1; i < 10; i++)
		arr[i] = arr[0] + y * i;
}*/
/*void get_min_max(int arr[], int* x, int* y);
int main()
{
	int x[10] = { 23,45,62,12,99,83,23,50,72,37 };
	int min = 0, max = 0;
	printf("�迭:");
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", x[i]);
	}
	printf("\n");
	get_min_max(x,&min,&max);
	printf("�ִ밪:%d\n", max);
	printf("�ּҰ�:%d", min);
	return 0;
}
void get_min_max(int arr[], int* x, int* y)
{
	int a, b;
	a = arr[0];
	b = arr[0];
	
	for (int i = 0; i < 10; i++)
	{
		if (arr[i] < a)
			a = arr[i];
	}
	for (int i = 0; i < 10; i++)
	{
		if (arr[i] > b)
			b = arr[i];
	}
	*x = a;
	*y = b;
}*/
/*void reverse_array(double arr[], double brr[]);

int main()
{
	double x[10] = { 1.2,3.1,4.3,4.5,6.7,2.3,8.7,9.5,2.3,5.8 };
	double y[10] = {0};
	printf(" �迭 :");
	for (int i = 0; i < 10; i++)
	{
		printf(" %.1f ", x[i]);
	}
	printf("\n");
	reverse_array(x,y);
	printf("����: ");
	for (int i = 0; i < 10; i++)
	{
		printf(" %.1f ", y[i]);
	}
	return 0;

}
void reverse_array(double arr[], double brr[])
{
	for (int i = 0; i < 10; i++)
	{
		brr[i] = arr[9 - i];
	}
}*/

/*void fill_array(int* arr, int x, int size);

int main()
{
	int a;
	int x[20] = {};
	printf("�迭�� ���ҿ� ������ ��?");
	scanf_s("%d", &a);
	fill_array(x, a, 20);
	printf("�迭:");
	for (int i = 0; i < 20; i++)
		printf(" %d ", x[i]);
	return 0;
}
void fill_array(int* arr, int x,int size)
{
	for (int i = 0; i < size; i++)
		arr[i] = x;
}*/
void fill_array2(int *arr, int x, int size1, int size2);

/*int main()//����
{
	int x[4][5] = { { 0 } };
	int a;
	int(*p)[5] = x;
	printf("�迭�� ���ҿ� ������ ��?");
	scanf_s("%d", &a);
	fill_array2(*p, a, 4, 5);
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 5; j++)
			printf("%d", p[i][j]);
	return 0;

}
void fill_array2(int *arr, int x, int size1, int size2)
{
	int i, j;
	for (i = 0; i < size1; i++)
		for (j = 0; j < size2; j++)
			arr[i][j] = x;

}*/
/*void get_rect_info(int x, int y, int* p, int* q);

int main()
{
	int a, b;
	int result1, result2;
	printf("����:");
	scanf_s("%d", &a);
	printf("����:");
	scanf_s("%d", &b);
	get_rect_info(a, b, &result1, &result2);
	printf("���� %d,�ѷ�:%d", result1, result2);
	return 0;
}
void get_rect_info(int x, int y, int* p, int* q)
{
	*q = 2 * (x + y);
	
	*p = (x * y);

}*/