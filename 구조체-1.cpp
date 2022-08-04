/*
구조체의 기본
구조체는 서로 다른 데이터형의 변수들을 하나로 묶어서 사용하는 기능이다.
struct contact{
char name[20];
char phone[20];
int ringtone;
}
구조체는 이처럼 서로 다른 데이터형의 변수들을 하나로 묶을 때 유용한 기능이다.
c에서 구조체는 사용자 정의형을 만드는 방법을 제공한다
c++에서는 구조체 개념을 확장시켜 클래스를 정의하고 객체를 다루는 기능을 제공한다.

구조체의 정의
구조체를 사용하기 위해 먼저 구조체를 정의해야 한다.
struct 태그명{
데이터형 멤버명;
데이터 멤버명;
.
.
.
};
태그 이름은 구조체를 구별하기 위한 식별자이다.
{}안에 구조체의 멤버를 나열한다. 구조체를 구성하는 변수를 구조체의 멤버라 하는데 일반 변수처럼 데이터형과 변수명으로 구조체의 멤버를 선언한다.
구조체는 함수 안에 정의할 수도 있고 함수 밖에 정의할 수도 있는데 함수안에서 정의할 경우 해당 함수에서만 사용 가능하다.
구조체는 사용자 정의형을 만드는 기능이므로 구조체를 정의하면 새로운 데이터형이 만들어진다.
주의할 점은 데이터형만 정의할 뿐 구조체 변수가 생성되는 것은 아니다. 구조체형의 변수를 선언해야 구조체 변수가 메모리에 할당되면서 구조체의 멤버들이 비로소 메모리에 할당된다.
구조체형은 태그 이름만 사용할 수 없고, struct키워드와 태그 이름을 함께 사용해야 한다.

struct contact{
char name[20];
char phone[20];
int ringtone;
}
int main()
{
	printf("contact 구조체의 크기=%d\n,sizeof(struct contact));//struct을 사용하지 않으면 컴파일 에러발생

	return 0;
}

void test()
{
	struct contact c1;//함수 밖에서 구조체를 선언하였으므로 여러함수에서 구조체를 사용 가능하다. c1은 구조체 변수의 이름이다.
}

구조체 변수의 선언 및 초기화
구조체 변수 선언 시 struct 키워드와 구조체 태그명을 쓴 다음, 구조체 변수명을 써준다.
struct contact ct;//struct 생략 시 컴파일 에러 발생
구조체 변수가 메모리에 할당될 때 구조체 멤버들이 선언된 순서대로 메모리에 할당된다.
구조체 변수도 선언 시 초기화하지 않으면 쓰레기 값을 가진다. 구조체 변수를 선언할 때 초기화 할 시 {}안에 멤버들의 초기값을 선언한 순서대로 나열하여야 한다.
struct contact ct={"김석진","01012345678",0}
{}안에 지정한 구조체의 초기값이 멤버의 개수보다 부족하면 나머지 멤버들은 0으로 초기화 되고 개수보다 초기값이 많으면 컴파일 에러가 발생한다. 그리고 그냥 {0}선언시 모든 멤버가 0으로 초기화된다.
구조체를 정의하면서 구조체 변수를 함께 선언가능 이 경우에는 구조체의 태그이름을 생략할 수 있으나 생략된 구조체는 나중에 다시 사용할 수 없으므로 태그이름을 지정하는 것이 좋다.

구조체의 변수 사용
구조체 멤버에 접근하려면 멤버 접근 연산자(.)를 이용한다.
구조체 변수 이름 다음.을 쓰고 멤버이름을 적어준다. 구조체 멤버도 다른 변수처럼 수식에 사용하거나 함수 호출의 인자로 사용할 수도 있다.

구조체의 멤버는 독립적인 변수가 아니라 구조체에 속한 변수이므로 항상 구조체 변수를 통해서만 접근할 수 있다.
만일 구조체 변수 없이 사용하면 구조체의 멤버가 아닌 일반 변수라는 뜻이 된다.
구조체 변수를 여러 개 선언하면, 각각의 구조체 변수는 서로 다른 메모리에 할당된다.

struct contact{
char name[20];
char phone[20];
int ringtone;
}
int main()
{
	struct contact c1={"김석진","0121021",0};
	struct contact c2={0},c3={0};
	
	c1.ringtone=5;
	strcpy(c1.phone,"1215120");
	printf(" 이름 :%c\n",c1.name);
	printf("전화번호:%s\n",c1.phone):
	printf("벨소리 :%d\n"),c1.ringtone):

	strcpy(c2.name,"진정국");
	strcpy(c2.phone,"01205401");
	c2.ringtone=1;
	printf(" 이름 :%c\n",c2.name);
	printf("전화번호:%s\n",c2.phone):
	printf("벨소리 :%d\n"),c2.ringtone):

	printf("이름:");
	scanf("%s",c3.name);
	printf("전화번호:");
	scanf("%s",c3.phone);
	printf("벨소리:");
	scanf("%d",c3.ringtone);
	printf(" 이름 :%c\n",c3.name);
	printf("전화번호:%s\n",c3.phone):
	printf("벨소리 :%d\n"),c3.ringtone):

	return 0;
	}
	구조체 변수가 만들어지면 구조체의 멤버는 변수로서 어디서든 사용 될 수 있다.
	단 항상 구조체 변수 이름과 멤버 접근 연산자를 통해서 사용해야한다.

	구조체 변수 간의 초기화와 대입
	 같은 구조체형의 변수들끼리 서로 초기화하거나 대입할 수 있다.
	 구조체 변수를 다른 구조체 변수로 초기화하면, 동일한 멤버 간에 1:1로 복사해서 초기화한다.
	 struct contact c1=c2;
	 구조체 변수에 다른 구조체 변수를 대입할 수는 있지만, 구조체 변수를 초기화할 때처럼 {}안에 나열된 값을 대입할 수는 없다.
	 c3={"김석진","01215015"}//컴파일 에러 발생
	 구조체 변수끼리 대입할 수는 있지만 구조체의 멤버인 배열끼리 대입하는 것은 컴파일 에러이다.

struct contact{
char name[20];
char phone[20];
int ringtone;
}
int main()
{
	struct contact c1={"김석진","0121021",0};
	struct contact c2={"진정국","0121521",1};
	struct contact c3=c2;
	printf("c2로 초기화 후의 c3=%s,%s,%d\n,c3.name,c3.phone,c3.ringtone);
	c3=c1;
	printf("c1으로 초기화 후의 c3=%s,%s,%d\n,c3.name,c3.phone,c3.ringtone);
	return 0;
}

구조체 변수의 비교
두 구조체 변수의 값이 같은지 비교하려면 구조체 변수끼리 직접 비교하는 것이 아니라 멤버대 멤버로 비교해야 한다.
struct contact{
char name[20];
char phone[20];
int ringtone;
}
int main()
{
	struct contact c1={"진정국","5454545",1};
	struct contact c2=c1;

	if(strcmp(c1.name,c2.name)==0 && strcmp(c1.phone,c2.phone)==0 && strcmp(c1.ringtone,c2.ringtone)==0)
		printf("c1 과 c2가 같다");
	else
		printf("다르다");
	return 0;
}

typedef
구조체를 사용시 struct키워드와 태그명을 함께 사용하여야 하는데 매번 사용시 불편함이 발생한다. 이럴 때 사용하는 것이 typedef이다. typedef를 이용하면 기존의 데이터형에 대한 별명(alias)을 만들 수 있다.

typedef 정의
typedef로 데이터형을 정의하려면, typedef 키워드 다음에 기존의 데이터형 이름을 쓰고, 기존의 데이터형에 대하여 사용할 새로운 이름을 써준다.
typedef 기존 데이터형 새이름
typedef struct contact cont;

struct contact{
char name[20];
char phone[20];
int ringtone;
}
typedef struct contact cont;
우선 typedef로 데이터형 이름을 정의하고 나면, struct contact 대신 cont를 데이터형 이름으로 사용 가능하다.
cont c={"김석진","0121021",0};
typedef 정의 후에도 기존의 데이터형은 그대로 사용 가능하며 기존의 데이터형과 typedef로 정의된 데이터형은 이름만 다를 뿐 같은 데이터형이다.

typedef의 사용목적
typedef문은 프로그램의 이식성과 가독성을 향상시키기 위한 목적으로 사용될 수 있다.
이식성은 하나의 소스파일로 여러 플랫폼에서 수정 없이 컴파일되고 실행될 수 있는 특성이다.

typedef struct point{
	int x,y;//정수좌표
	}POINT;
typedef struct point{
	double x,y;//실수 좌표
}POINT;

typedef int coord_t;
typedef struct point{
	coord_t x,y;// x,y 는 coord_t형으로 선언, 이 경우 int 형이다
	}POINT;
만일 실수 좌표로 사용하려면 typedef 정의 부분만 변경하면 된다.

구조체의 활용
구조체를 정의하면 구조체는 새로운 데이터형이 된다. 기본형을 사용하는 것처럼 어디든지 사용할 수 있다.구조체형의 변수 선언,구조체 배열이나 포인터, 함수정의 시 매개변수의 데이터형이나
리턴형, 다른 구조체를 정의할 때 멤버의 데이터형으로 구조체형을 사용할 수 있다.

구조체 배열
같은 구조체형의 변수를 여러 개 묶어서 사용하려면 구조체 배열을 선언한다.
contact contacts[5]//크기가 5인 contact구조체 배열 선언
구조체 배열의 원소에 접근할 때도 인덱스를 사용한다.
arr가 구조체 배열의 이름일 때 구조체의 멤버에 접근하려면 arr[i].member형식으로 접근한다.

typedef struct contact{
char name[20];
char phone[20];
int ringtone;
} cont;

int main()
{
	cont arr[]={
	{"김석직","454513",0},
	{"진정국","421245",1},
	{"박지민","212435453",2}
	};
	int size=sizeof(arr)/sizeof(arr[0]);
	int i;
	printf("이름 전화번호 벨\n");
	for(i=0;i<size;i++)
	{
	printf("%6s %11s %d\n",arr[i].name,arr[i].phone,arr[i].ringtone);
	}
	return 0;
}
입력받은 이름을 초기화된 contact형 배열에서 찾아서 전화번호를 출력하는 코드
#define str_size=20
typedef struct contact
{
	char name[str_size];
	char phone[str_size];
	int ringtone;
}	CONTACT;

int main()
{
	CONTACT arr[]={
	{"김석진","510421",0},
	{"전정국","511421",1},
	{"박지민","512421",2},
	{"김남준","513421",3},
	{"민윤기","514421",4},
	{"정호석","515421",5},
	{"김태형","515721",6},
	};
	int size=sizeof(arr)/sizeof(arr[0]);
	int i;
	char name[str_size];
	int index;

	printf("이름");
	scanf("%s",name);

	index=-1;
	for(i=0;i<size;i++)
	{
	if(strcmp(arr[i].name,name)==0)
	{
		index=i;
		break;//for문 탈출
	}
	if(index>=0)
	{
	printf("%s의 전화번호:%s\n",arr[index].name,arr[index].phone);
	}
	else
		printf("검색실패");
	return 0;
}

구조체 포인터
구조체 포인터는 구조체 변수의 주소를 저장하는 포인터이다.
struct contact *p=&ct;//p는 contact구조체 변수 ct를 가르킨다.

구조체 포인터로 구조체 변수의 멤버에 접근하려면 간접 멤버 접근 연산자인 ->연산자를 사용한다
p->ringtone=5;
strcpy(p->phone,"01025730343");
간접 멤버 접근 연산자 대신 역참조 연산자와 멤버 접근 연산자를 사용하는 것도 가능하다.
(*p).ringtone=5;
strcpy((*p).phone,"0102573034");
그러나 간접 멤버 접근 연산자를 이용하는 것이 더 쉽다.
#define str_size=20

typedef struct contact
{
	char name[str_size];
	char phone[str_size];
	int ringtone;
} cont;

int main()
{
	cont ct={"김석진","510421",0};
	cont *p=&ct;
	p->ringtone=5;
	strcpy(p->phone,"01025730343");
	printf(" 이름 :%c\n",p->name);
	printf("전화번호:%s\n",p->phone):
	printf("벨소리 :%d\n"),p->ringtone):
	return 0;
}
구조체 포인터 활용
#define str_size=20
typedef struct contact
{
	char name[str_size];
	char phone[str_size];
	int ringtone;
}	CONTACT;

int main()
{
	CONTACT arr[]={
	{"김석진","510421",0},
	{"전정국","511421",1},
	{"박지민","512421",2},
	{"김남준","513421",3},
	{"민윤기","514421",4},
	{"정호석","515421",5},
	{"김태형","515721",6},
	};
	int size=sizeof(arr)/sizeof(arr[0]);
	int i;
	char name[str_size];
	int index;
	CONTACT *recent=NULL;
	while(1)
	{
	printf("이름,.입력시 종료");
	scanf("%s",name);
	if(strcmp(name,".")==0)
		break;
	index=-1;
	for(i=0;i<size;i++)
	{
		if(strcmp(arr[i].name,name)==0)
		{
			index=i;
			break;//for문 탈출
		}
	}
	if(index>=0)
	{
		printf("%s의 전화번호 %s로 전화를 겁니다\n",arr[index].name,arr[index].phone);
		recent=%arr[index];
	}
	else
		printf("검색실패");
	}
	if(recent)//recent 가 NULL값이 아닐경우 출력
		printf("최근통화:%s %s\n",recent->name,recent->phone);
	return 0;
}
구조체 변수를 가리키는 포인터가 읽기전용포인터로 사용될 때는 const포인터로 선언하는 것이 좋다
const포인터로 구조체 변수에 접근할 때는 구조체 변수의 값을 읽어볼 수만 있고 변경할 수는 없다.


*/