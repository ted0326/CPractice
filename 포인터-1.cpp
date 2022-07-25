/*포인터
* 포인터는 주소를 저장하는 변수이다. 포인터 변수에는 주소값이 저장된다.
* 포인터를 사용할 때 주소값이 아니라 포인터가 어떤 변수를 가르키는 지가 중요하다.
* [포인터는 다른 변수를 가리키는 변수]
*
* 포인터의 선언
* *기호를 사용하여 포인터를 선언
* {
* 데이터형*변수명;
* 데이터형*변수명=초기값;
* ex)
* int *p;
* double *pd;
* int a=123;
* int *pa=&a;
* char *pc=NULL;
* }
* 포인터 선언 시 지정하는 데이터형은 포인터가 가리키는 변수의 데이터형이다.
* 포인터 선언할 때 *의 위치는 관계없으나 변수쪽에 붙여서 사용하는 것이 좋다.
* ex)
* int *p1,*p2,*p3//p1,p2,p3 모두 포인터
* int* p1,p2,p3// p1만 포인터
*
* 포인터의 데이터형이 다르더라도 포인터의 크기는 항상 같다.
* 포인터의 크기는 플랫폼에 의해서 결정된다.
*
* int *p1;
* double *pd;
* printf("sizeof(p1)=%d\n",sizeof(p1));//4바이트
* printf("sizeof(pd)=%d\n",sizeof(pd));//4바이트*/
#include<stdio.h>
int main()
{
	int* pi;
	double* pd;
	char* pc;

	printf("sizeof(pi)=%zd\n", sizeof(pi));//4바이트 (32플랫폼기준 64시 8바이트)
	printf("sizeof(pd)=%zd\n", sizeof(pd));//4바이트(32플랫폼기준 64시 8바이트)
	printf("sizeof(pc)=%zd\n", sizeof(pc));//4바이트(32플랫폼기준 64시 8바이트)

	printf("sizeof(int*)=%zd\n", sizeof(int*));//4바이트(32플랫폼기준 64시 8바이트)
	printf("sizeof(double*)=%zd\n", sizeof(double*));//4바이트(32플랫폼기준 64시 8바이트)
	printf("sizeof(char*)=%zd\n", sizeof(char*));//4바이트(32플랫폼기준 64시 8바이트)
	return 0;
}

