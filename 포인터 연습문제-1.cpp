#include<stdio.h>

/*int main()
{
	int arr[5] = { 1,2,3,4,5 };
	int* p = NULL;
	int i;
	p = arr;
	for (i = 0; i < 5; i++)
	{
		printf("%d", ++(*p));//(*p)값을 증가시키고 출력 즉  1 2 3 4 5 가 나오는 것이 아닌 2 3 4 5 6 이 발생
		p++;//주소를 증가시키는 것이므로 *p의 값이 증가된 것과는 관계가 없음
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
		printf("%d", *p++);//p의 변수를 표출한 뒤 p의 주소값이 증가하므로 결과는 1 2 3 4 5 가 나온다.
	}
	printf("\n");
	return 0;
}
*/
/*int get_sum_average(int arr[], int size, double* average)//avg의 주소를 받아서 함수내에서 작동됨
{
	int sum = 0;
	int i;
	for (i = 0; i < size; i++)
	{
		sum += arr[i];//scores의 배열의 원소들의 합을 구함
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

	printf("합계:%d\n", get_sum_average(scores, 5, &ave));
	printf("평균:%.2f\n", ave);
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
	*min_num = x * y / *max_num;//질문
}*/
/*int main()
{
	int x[3] = {1,2,3};
	int* p = x;
	for (int i = 0; i < 3; i++)
	{
		printf("x[%d]의 주소:%p\n",i, p++);
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
	int x[10] = { 44,32,65,23,45,76,77,89,23,45 };//질문
	int* p = x;
	printf("배열:");
	for (int i = 0; i < 10; i++)
		printf("%d ", *(p)++);
	printf("\n");
	printf("역순:");
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
	printf("배열:");
	for (int i = 0; i < 10; i++, p++)
	{
		printf("%.2f ", (*p)++);
	}
	printf("\n");
	printf("평균:%f", sum / 10);
	return 0;
}*/
/*void arith_seq(int arr[], int x, int y);//질문
int main()
{
	int x[10] = { 0 };
	int a, b;
	printf("첫 번째항:");
	scanf_s(" % d\n", &a);
	printf("공차:");
	scanf_s("%d\n:", &b);
	arith_seq(x,a,b);
	printf("등차수열:");
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
	printf("배열:");
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", x[i]);
	}
	printf("\n");
	get_min_max(x,&min,&max);
	printf("최대값:%d\n", max);
	printf("최소값:%d", min);
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
	printf(" 배열 :");
	for (int i = 0; i < 10; i++)
	{
		printf(" %.1f ", x[i]);
	}
	printf("\n");
	reverse_array(x,y);
	printf("역순: ");
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
	printf("배열의 원소에 저장할 값?");
	scanf_s("%d", &a);
	fill_array(x, a, 20);
	printf("배열:");
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

/*int main()//질문
{
	int x[4][5] = { { 0 } };
	int a;
	int(*p)[5] = x;
	printf("배열의 원소에 저장할 값?");
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
	printf("가로:");
	scanf_s("%d", &a);
	printf("세로:");
	scanf_s("%d", &b);
	get_rect_info(a, b, &result1, &result2);
	printf("넓이 %d,둘레:%d", result1, result2);
	return 0;
}
void get_rect_info(int x, int y, int* p, int* q)
{
	*q = 2 * (x + y);
	
	*p = (x * y);

}*/