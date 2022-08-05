/*
함수의 인자로 구조체 전달하기
구조체 변수도 함수의 인자로 전달 가능하다

값에 의한 전달 
typedef struct point
(
int x,y;// 점의 좌표
}POINT;

void print_point(POINT pt);
int main()
{
	POINT arr[]={
	{0,0},{10,10},{20,20},{30,30},{40,40}
	};
	 int sz=sizeof(arr)/sizeof(arr[0]);
	 int i;

	 for(i=0;i<sz;i++)
	 {
		print_point(arr[i]);//POINT pt=arr[i]
		printf(" ");
	 }
	 printf("\n");

	 return 0;
}
void print_point(POINT pt)//pt는 입력 매개변수이므로 값으로 전달한다
{
	printf("(%d,%d)",pt.x,pt.y);
}
위의 방식은 arr[i]를 직접 출력하는 대신 불필요하게 pt로 복사하는 작업을 반복하므로 비효율 적이다.
메모리 추가생성과 복사하는데 추가적인 cpu명령어를 수행하기 때문에 시간적,공간적 성능 저하가 발생한다.
그래서 기본형에 비해 크기가 큰 구조체는 복사하는 대신 구조체의 주소를 전달하는 것이 좋다.

포인터에 의한 전달
구조체를 복사하지 않고 전달하려면 포인터로 전달한다.
void print_point(POINT *Pt)
{
	printf("(%d,%d)",pt->x,pt->y);
}
함수 안에서 구조체 포인터로 구조체의 멤버에 접근해야 하므로 간접 멤버 접근 연산자 이용
typedef struct point
(
int x,y;// 점의 좌표
}POINT;

void print_point(POINT *pt);
int main()
{
	POINT arr[]={
	{0,0},{10,10},{20,20},{30,30},{40,40}
	};
	 int sz=sizeof(arr)/sizeof(arr[0]);
	 int i;

	 for(i=0;i<sz;i++)
	 {
		print_point(&arr[i]);//구조체 변수의 주소를 전달한다.
		printf(" ");
	 }
	 printf("\n");

	 return 0;
}
void print_point(POINT *pt)//pt는 입력 매개변수이므로 값으로 전달한다
{
	printf("(%d,%d)",pt->x,pt->y);
}
POINT 구조체처럼 크기가 작은 구조체는 값으로 전달할 때와 포인터로 전달할 때의 성능 차이가 거의 없다. 하지만 배열이 포함되거나 멤버가 많은 경우에는 포인터로 전달 시 불필요한
복사를 막을 수 있다.
구조체도 배열처럼 복사하지 않고 전달하기 위해 포인터로 전달하므로 입력 매개변수 인지 출력 매개변수인지 구분하여야 한다. 입력 매개변수의 경우 const포인터형으로 선언한다.
출력 혹은 입출력의 경우 일반 포인터로 전달한다.

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct point
{
	int x,y;
}POINT;

void print_point(const POINT*pt);
void set_point(POINT *pt,int x, int y);

int main()
{
	POINT arr[5]={0};
	int sz=sizeof(arr)/sizeof(arr[0]);
	int i;

	srand(unsigned int)time(NULL));//난수의 시드 지정
	for(i=0;i<sz;i++)
	{
		int x=rand()%100;//0~99사이 난수 생성
		int y=rand()%100;
		set_point(&arr[i],x,y);//arr[i]의 변수 설정
	}
	for(i=0;i<sz;i++)
	{
		print_point(&arr[i]);
		printf(" ");
	}
	printf("\n");

	return 0;
}

void print_point(POINT *pt)
{
	printf("(%d,%d)",pt->x,pt->y);
}

void set_point(POINT *pt,int x,int y)
{
	pt->x=x;//pt가 가리키는 POINT변수의 멤버 X값 변경
	pt->y=y;//pt가 가리키는 POINT변수의 멤버 y값 변경
}

구조체 변수를 함수의 매개변수로 전달하는 방버 정리
함수의 매개변수는 구조체 포인터형을 선언한다.
구조체변수가 입력 매개변수 일 때는 const키워드로 지정한다
구조체를 매개변수로 전달받는 함수를 호출할 때는 구조체 변수의 주소를 인자로 전달한다
함수를 정의할 때는 매개변수인 포인터로 구조체의 멤버에 접근한다.

비트필드
구조체를 정의할 때, 비트필드를 이용하면 구조체가 가진 멤버를 비트 단위로 사용하도록 설정 가능하다
비트필드는 메모리 사용을 최소화하거나 정해진 바이트 안에 정보를 인코딩하기 위한 목적으로 사용된다.

typedef struct date{
	unsigned short year:7;//7비트를 연도에 저장
	unsigned short month:4;//4비트를 월에 저장
	unsigned short day:5;//5비트를 일에 저장
}DATE
다 합치면 16비트 즉 2바이트이므로 DATE의 크기는 2바이트이다.
만일 모든 멤버의 비트 수를 더한 값이 데이터형보다 커지면 해당 데이터형을 배열로 할당,
typedef struct date{
	unsigned short year:7;//7비트를 연도에 저장
	unsigned short month:4;//4비트를 월에 저장
	unsigned short day:5;//5비트를 일에 저장
	unsigned short the day_of_week:3//추가시 DATE구조체의 크기가 4바이트가 된다
}DATE

비트필드의 멤버는 정해진 비토로 값을 표현하므로 주어진 비트로 표현할 수 있는 범위를 넘어서는 값을 저장하면 오버플로우가 발생한다.

typedef struct date{
	unsigned short year:7;//7비트를 연도에 저장 (00~99)표현가능
	unsigned short month:4;//4비트를 월에 저장 1~12 표현가능
	unsigned short day:5;//5비트를 일에 저장 1~31표현가능 만약
}DATE

int main()
{
	DATE.dday;
	dday.year=18;//(00~99)표현가능
	dday.month=11;//1~12 표현가능
	dday.day=30//1~31표현가능 만약 40입력시 오버플로우 발생

	printf("DATE의 크기=%d\n",sizeof(DATE));
	printf("%d/%d/%d",dday.year,dday.month,dday.day);
	return 0;
}
비트를 정의할 때 중간에 일부 비트를 비워 두고 멤버 비트를 특정 비트에 할당 가능하다.
사용하지 않는 비트 지정시 멤버 이름 없이 데이터형 다음 :과 비트수만 써준다.
구조체 안에 일반 멤버와 비트필드를 함께 정의할 수도 있다.

구조체의 멤버로 다른 구조체 변수 사용하기
구조체를 정의할 때 다른 구조체의 변수를 멤버로 선언가능하다. 즉 구조체 변수 안에 다른 구조체 변수가 멤버로 포함될 수 있다.

typedef struct point
{
int x,y;
}POINT;

typedef struct line
(
	POINT start,end;// 다른 구조체형의 변수를 멤버로 선언한다.
}LINE;
LINE구조체 변수를 사용할때도 멤버 접근 연산자를 이용
LINE L1={0};
L1.end.x=100;
L1.end.y=100;

typedef struct point
{
int x,y;
}POINT;

typedef struct line
(
	POINT start,end;
}LINE;

double get_length(const LINE*ln);

int main()
{
	LINE ln={{10,20},{30,40}};

	printf("시작점:(%d,%d)",ln.start.x,ln.start.y);
	printf("끝:(%d,%d)",ln.end.x,ln.end.y);
	printf("직선의 길이:%d",get_length(%ln1));

	return 0;
}
double get_length(const LINE*ln)
{
	int dx=ln->end.x-ln.start.x;
	int dy=ln->end.y-ln.start.y;
	return sqrt(dx*dx+dy*dy);
}

공용체와 열거체

열거체
열거체는 정수형의 일종으로 열거형이라고도 한다.

열거체의 개념
열거체는 정수형 변수가 특정 값들 중 한가지 값을 가질 때 유용하게 사용할 수 있으며, 이때 정수형 변수가 가질 수 있는 값들을 열거 상수로 정의한다.
예시
int d1=0;//0~3 사이의 값(0 북 1 남 2 동 3 서);
그러나 갑자기 코드의 다른 부분에서 d1의 값을 변경할 시 어떤 의미인지 한눈에 알 수 없다.
d1=2;//2가 어떤 의미인지 알 수 없다.

이 경우 0~3사이의 값을 사용하는 대신 메크로 상수를 정의할 수 있다. 메크로 상수를 정의할 때는 프로그래머가 매크로 상수의 값을 직접 지정해야 한다.
매크로 상수를 정의해서 사용하면 코드의 의미가 분명해지므로 코드의 가독성이 증가한다.
매크로 상수를 추가로 정의하려면 기존의 매크로 상수와 겹치지 않도록 매크로 상수의 값을 정의할 때 주의해야 한다.

열거체의 정의 및 사용
열거체를 정의하려면 enum키워드 태그명을 쓰고,{} 안에 열거 상수를 나열한다. 열거 상수는 이름이 있는 정수형 상수이다.
enum 태그명{열거상수1,열거상수,...};
enum co;or{red,green,blue};

dufrjcpsms c컴파일러에 의해 int형 처리되고, 열거상수는 정수형 상수가 된다. 따로 지정하지 않으면 열거 상수는 0부터 1씩 증가되는 값으로 정의된다.
매크로 상수를 정희하는 경우와 비교해서 열거 상수를 정의할 때는 프로그래머가 값을 지정할 필요가 없다. 컴파일러가 0부터 1씩 증가하는 값을 순서대로 할당하기 때문이다.
따라서 열거 상수를 추가할 때도,{}의 끝 부분에 이름만 추가하면 된다.

열거 상수를 특정 값으로 정의할 수도 있는데, 열거 상수 이름 다음에 =를 쓰고 열거 상수의 값을 써준다.
만약 열거 상수 중 일부에만 값을 지정하면, 나머지 열거 상수는 그보다 1씩 커지는 정수 값으로 자동으로 설정된다.

열거체도 일종의 사용자 정의형이므로 열거체형의 변수를 선언하거나 배열 또는 포인터를 선언할 수 있다.
매크로 상수를 사용하는 대신 열거 상수 사용시 디버깅에 도움을 준다. c c++의 컴파일러 디버깅 기능은 실행 중에 변수의 값을 확인 가능한데 int형 변수는 값이 int형으로 표시되는 
반면에 열거체 변수는 열거 상수 이름이 표시되므로 값의 의미를 파악하기 더 쉽다.
열거체가 int형으로 처리되므로 열거체 변수의 값은 정수로 출력되고 열거체 정의시 태그명을 생략하면 열거 상수만 정수형 상수로 정의된다.

enum direction{north,south,east,west};

int main()
{
	enum direction d1=north;

	d1=east;
	printf("d1=%d\n",d1);

	switch(d1)
	{
	case north:
		printf("북쪽으로 이동\n");
		break;
	case south:
		printf("남쪽으로 이동\n");
		break;
	case east:
		printf("동쪽으로 이동\n");
		break;
	case west:
		printf("서쪽으로 이동\n");
		break;
	}
	return 0;
}
열거체 변수에 정수 값을 대입해도 컴파일 에러가 발생하지 않는다. 열거체 변수가 int 형으로 처리되기 때문

공용체
공용체는 여러 멤버들이 메모리를 공유해서 사용하는 기능으로, 공용체의 멤버들은 같은 주소에 할당되고, 서로 메모리를 공유한다.
union 태그명{
	데이터형 멤버명;
	데이터형 멤버명;
	.
	.
	.
};

typedef union color_t{
	unsigned int color;
	unsigned int char rgb[4];
}COLOR_T;

공용체를 정의하면 구조체처럼 새로운 데이터형이 된다. 즉 변수를 선언하거나 배열 또는 포인터를 만들 수 있다.
공용체 변수의 멤버들은 모두 같은 주소에 할당된다.
공용체의 크기는 멤버 중 가장 큰 멤버의 크기와 같다.
공용체는 여러 멤버 중 한번에 하나만 사용할 수 있기 때문에, 공용체를 초기화 할 때는 {}안에 첫 번째 멤버의 초기값만 지정한다.
공용체의 멤버에 접근할 때도 멤버 접근 연산자인 .를 사용한다
공용체 포인터의 경우 ->를 사용한다.
*/
