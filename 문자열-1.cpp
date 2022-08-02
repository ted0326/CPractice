/*
문자열

문자 배열
문자열은 연속된 문자들의 모임
문자열을 종료할 때 끝에 널 문자를 함께 저장하는 문자열을 널 종료 문자열 이라고 한다.
문자열 변수는 문자배열을 변수로 사용한다.
문자열 상수는 값이 변경되지 않는 문자열이며 문자열 리터릴이라고도 한다.


문자 배열을 선언 할 경우 저장할 문자열의 길이 +1 만큼 배열의 크기를 지정해야한다. 널 문자를 함께 저장해야 하기 때문이다.

보통 문자배열을 초기화 할 깨 문자열 리터럴 을 사용한다. 문자열 리터럴로 초기화 할 때는 컴파일러가 자동으로 문자열의 끝에 널문자를 저장해준다.

초기값인 무자열 리터럴의 길이가 문자 배열의 크기 -1보다 작으면 배열의 나머지 원소를 널 문자로 초기화한다. c에서는 문자열이 널 문자로 끝난다고 가정하기 때문에 문자열 끝에 널 문자가 없을 경우
문제가 발생할 수 있다. 따라서 문자배열의 크기를 충분히 크게 지정해야 한다.

초기값을 지정할 때는 문자 배열의 크기를 생략 가능하다. 이 때 컴파일러는 초기값으로 지정한 문자열의 길이+1크기로 문자 배열을 할당한다.

만일 문자 배열 전체를 널 문자로 초기화하려면 문자 배열을 널 문자열로 초기화 한다.
char str[10]="";
문자배열의 초기값이 따로 없을 때는 널 문자열로 초기화하는 것이 안전하다.

#include<stdio.h>

int main()
{
	char str1[10]={'a','b','c'};
	char str2[10]="abc";
	char str3[]="abc";
	char str4[10]="very long string";
	int size=sizeof(str1)/sizeof(str1[0]);
	int i;
	printf("str1=");
	for(i=0;i<size;i++)
		printf("%c",str1[i]);//%c 문자배열의 원소를출력시 사용 배열처럼 for문으로 출력 가능
	printf("\n");
	printf("str2=%s\n",str2);//문자열을 %s로 출력한다.
	printf("str3=");
	printf(str3);//문자 배열을 직접printf 함수의 인자로 전달할 수 있다.
	printf{"\n");
	printf("str4=%s",str4);//문자배열이 정해진 크기를 넘어서 맨 끝에 널 문자 존재 x 출력시 문자열의 끝을 감지할 수 없다.
	return 0;

	문자배열에 저장된 문자열을 변경하려면 어떻게 해야하나
	저장된 문자열 중 특정 문자 변경시 인덱스를 이용해 변경
	그러나 문자 배열 전체를 변경시 기존 문자배열에 다른 문자열을 대입하면 컴파일 에러가 발생, 배열이름은 배열의 시작 주소이므로 변경 불가하다.
	문자열 처리 함수를 라이브러리 함수로 제공하고 있다.

	표준 c의 문자열 처리 함수
	표준 c 라이브러리는 다양한 문자열 처리 함수를 제공한다.
	문자열을 복사하거나, 문자열의 길이를 구하거나, 문자열을 비교할 때 문자열 처리 함수를 이용가능함

	문자열 처리 함수 종류
	strlen(str) str의 길이를 구한다. 널문자 제외
	strcmp(lhs,rhs) lhs와 rhs를 비교해서 같으면 0 lhs>rhs의 경우 0보다 큰값, lsh<rhs의 경우 0보다 작은 값을 반환함
	strncmp(lhs,rhs,cnt) lhs와 rhs를 cnt개만큼 비교한다. 리턴값은 위와 같음
	strcpy(dest,src) src를 dest로 복사함
	strncpy(dest,src,cnt)src를 ㅇest로 cnt 개만큼 복사함
	strcat(dest,src)dest끝에 src를 연결
	strncat(dest,src,cnt)dest의 끝에 src를 cnt개 연결
	strchr(str,ch)str에서 ch문자를 찾는다
	strstr(str,substr)str에서 substr 문자열을 찾는다
	strtok(str,delim)str을 delim을 이용해서 토큰으로 분리한다


	int isalnum(int c) 알파벳이나 숫자인지 검사
	int isalpha(int c)알파벳인지 검사
	int isdigit(int c)숫자인지 검사
	int islower(int c)소문자인지 검사
	int isupper(int c)대문자인지 검사
	int isspace(int c)공백 문자인지 검사
	int isxdigit(int c)16진수 숫자인지 검사
	int tolower(int c)소문자로 변환
	int toupper(int c)대문자로 변환


	문자열의 길이 구하기
	strlen 함수는 널문자를 제외한 문자열의 길이를 구함
	size_t strlen(const char*str) //str은 입력 매개변수, size_t는 표준 c라이브러리에서 정의된 데이터형으로 크기를 나타내는데 사용되는 부호없는 정수형이다.

	#include<stdio.h>
	#include<string.h>

	int main()
	{
	char s1[]="hello";
	int len=0;

	printf("s1의 길이:%d\n",strlen(s1));//널문자를 제외한 문자열의 길이
	printf("s2의 길이:%d\n",strlen(s2));// 널 문자열의 길이
	printf("s2의 길이:%d\n",strlen("bye bye"));//문자열 리터럴의 길이
	printf("s1의 크기:%d\n",sizeof(s1));//널 문잘ㄹ 포함한 배열의 크기

	len=strlen(s1);
	if(len>0)
		s1[len-1]='\0';//마지막 한 글자 삭제
	printf("s1=%s\n",s1);

	return 0;
	}
	문자열의 복사
	strcpy 함수는 src문자열을 dest문자 배열로 복사한다
	char*strcpy(char*dest,const char*src);//dest는 출력,src는 입력 매개변수
	strcpy 함수는 s1의 문자들을 s2로복사하는데 널 문자를 만날 때까지 복사한다. 이 때 널 문자도 복사되므로 복사 후 s2도 널 종료 문자열이다.
	strcpy 함수를 호출할 때는 첫 번째 인자로는 문자 배열을, 두 번째 인자로는 문자 배열이날 리터럴을 전달한다. 첫 번째 인자로 문자열 리터럴을 전달하면 에러가 발생 하는데 문자열 리터럴은 상수이므로
	변경할 수 없기 때문이다.
	strcpy(dest,src)를 사용할 경우 dest 배열의 크기가 strlen(src)+1보다 크거나 같아야 한다. strcpy의 경우 src의 크기가 dest를 넘어도 무조건 복사하므로 실행에러가 발생할 수 있다. 
	이처럼 할당 받은 메모리 범위를 넘어서 메모리에 값을 저장할 때 메모리가 변조되는 상황을 버퍼오버런이라고 한다.
	strncpy의 경우도 strcpy와 같은데 strncpy도 src를 count개 복사할 만큼 dest의 크기가 충분한지 검사하지는 않으므로 주의해야 한다. 그리고 일부만 복사하는 경우 맨 끝에 널문자를 포함하지 않으므로
	직접 널 문자를 저장해줘야 한다.

	#define _CRY_SECURE_NO_WARNINGS
	#include <stdio.h>
	#include<string.h>
	#define size 32

	int main()
	{
		char str1[size]="";//널 문자열로 초기화
		char str2[size]="";
		char temp[size];

		printf("2개의 문자열?");
		scanf("%s %s",str1,str2);//빈칸으로 구분해서 문자열 입력
		printf("str1=%s,str2=%s\n",str1,str2);

		strcpy(temp,str1);//str1을 temp로 복사
		strcpy(str1,str2);//str2를 str1으로 복사
		strcpy(str2,temp);//temp를 str2로 복사
		printf("str1=%s,str2=%s\n",str1,str2);
		return 0;

strcmp 함수는 lhs문자열과 rhs문자열을 알파벳순으로 비교한다.
int strcmp(const char *lhs,const char *rhs)
문자열을 비교할 때는 관계연산자 대신 strcmp 함수를 사용해야 한다.
관계연산자를 사용하면 문자열의 내용을 비교하는 대신 문자열의 주소를 비교하기 때문
strcmp함수의 인자로 문자 배열을 전달할 수도 있고, 문자열 리터럴을 전달할 수도 있다.

#define _CRY_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>
#define size 10

int main()
{
	char s1[size]="apple";
	char s2[size]="apple";
	char password[size];

	if(s1==s2)
		printf("same address\n");
	if(strcmp(s1,s2)==0)
		printf("same string");
	printf("패스워드:")
	scanf("%s",password);
	if(strcmp(password,"abcd1234"==0);
		printf("login succeeded\n");
	else
		printf("login fail\n);
	return 0;
	}
	strcat dest문자열 끝에 src 문자열을 복사해서 연결한다.
	strcat 함수의 첫 번째 매개변수는 출력 매개변수로, 문자열을 저장할 수 있는 문자 배열을 지정해야하고 두번째 매개변수는 복사할 문자열로 입력 매개변수이므로 변경되지 않는다.
	strcat도 연결시 메모리가 충분한지 확인하지 않으므로 사용할 때 메모리가 충분한지 확인하고 사용하여야 한다.

	int main()
	{
		char sentence[20]="";
		char word[20];

		do{
			printf("단어?");
			scanf("%s",word);
			strcat(sentence,word);//입력단어를 문장끝에 연결
			strcat(sentence," ");//단어를 구분할 수 있게 공백을 추가
		}while(strcmp(word,".")!=0);/.이 입력될 때까지 반복
		printf("%s\n",sentence);
		return 0;
	}
문자열을 일부만 연결할 시 strncat사용

문자열 검색
strchr은 문자가 있는지 찾고, strstr은  문자열이 있는지 찾는다
이 두 함수모두 문자나 문자열을 찾으면 찾은 위치의 주소를 리턴한다. 만일 문자나 문자열을 찾을 수 없으면 null을 리턴한다

int main()
{
	char filename[]="readme.txt";
	char *P=NULL;

	p=strchr(filename,'.');
	if(p!=NULL)
		printf("file extension:%s\n",p+1)//여기서 p는 .이 있는 인덱스를 가르키고 p+1은 그 다음위치를 리턴함
	p=strchr(filename,'txt');
	if(p!=NULL)
		printf("file type::text file");
	return 0;
}

문자열의 토큰 나누기
어떤 문장에서 더이상 나눌 수 없는 최소 단위를 토큰이라고 한다.
strtok는 주어진 문자열을 주어진 문자들을 이용해서 토큰으로 쪼개고 토큰의 주소를 리턴한다. 더이상 토큰이 없으면 NULL값을 리턴한다.
strtok 함수를 호출하고 나면 첫번째 매개변수인 str이 변경되므로 주의해야한다.
첫번째 strtok함수 호출 후 이전 문자열에서 다음 토큰을 구하려면 strtok함수의 첫 번째 인자를 NULL로 지정해야 한다.

int main()
{
	char phone[]="02-123-4567";
	char *p=NULL;

	p=strtok(phone,"-");
	printf("area code:%s\n",p);
	p=strtok(NULL,"-");
	printf("prefix :%s\n",p);
	p=strtok(NULL,"-");
	printf("line number:%s\n",p);
	return 0;
}
문자열의 입출력
scanf함수로 문자열을 입력받을 때는 %s문자열을 사용한다.
그런데 scanf 함수는 공백문자까지만 입력으로 가져오므로 공백이 있는 문자열을 읽을 수 없다.그러므로 gets함수를 사용한다.
gets함수는 줄바꿈 문자가 입력될 때까지 입력된 문자열을 str에 저장한다. 그러나 문자배열을 인자로 전달하면서 배열의 크기를 전달하지 않아 버퍼 오버런에 매우 취약하다. 그러므로 gets_s를 사용하는 것이 좋다.
puts 함수는 인자로 전달한 문자열의 마지막에 있는 널 문자를 줄바꿈 문자로 바꾸어 출력을 처리하므로 따로 줄바꿈문자를 입력할 필요가 없다.

char*형의 문자열 포인터
문자열 포인터는 char*형의 변수로 문자열의 주소를 저장하는 포인터이다.

문자열 리터럴의 의미
상수는 필요할 때 잠깐동안 cpu레지스터에 값을 넣어서 사용하는 임시 값이다. 따라서 메모리가 할당 되지 않으며 주소가 없다.
그러나 문자열 리터럴은 메모리에 할당된다. 길이가 정해진 것이 아니라 cpu레지스터에 보관할 수 없기 때문이다. 텍스트 세그먼트라는 특별한 메모리 영역에 문자열 리터럴을 보관하고 그 주소를 대신 사용한다.
배열이름 대신 문자열 리터럴을 사용한다고 생각하면 된다.
배열 이름이 배열주소를 의미하듯 문자열리터럴은 문자열 리터럴의 주소를 의미한다.
문자열 리터럴은 문자 배열처럼 메모리에 저장되나 값을 변경할 수 없다. 문자열 메모리가 저장되는 텍스트 세그먼트는 변경할 수 없는 메모리이기 때문, 읽기전용으로만 사용 가능하다.
문자열 리터럴을 연속해서 사용하면 하나로 합쳐진다
char str="avc""xtz"/avcxtz로 합쳐진다.

문자열 포인터의 용도
char*형의 포인터는 문자 배열을 가리킬 수 있다.
문자배열을 직접 사용하지 않고 포인터를 이용하는 이유는 문자열의 시작주소뿐만 아니라 특정 위치를 가리키게 할 수 있기 때문이다.

int main()
{
	char str[64]="";
	char *p=str;//p는 str배열을 가리킨다.

	strcpy(p,"test string");//p가 가리키는 문자배열 변경
	if(islower(p[0]))
		p[0]=toupper(p[0]);//단어의 첫글자를 대문자로 변경,p가 가리키는 str[0]를 변경한다
	p=strchr(p,' ');//str중 ' ' 의 주소를 포인터 p에 저장한다.
	if(islower(p[1]))
		p[1]=toupper(p[1]);//' '다음문자를 대문자로 변경
	puts(str);
	return 0;

	const char*형은 일기 전용 문자열 포인터이므로 문자열의 내용을 읽을 수는 있으나 변경할 수 없다.
	함수의 매개변수를 입력 매개변수로 지정할 때 유용하다.
	문자열 전달 시 널문자로 문자열의 끝을 알 수 있어서 배열의 크기가 필요 없다.

	문자열 사용을 위한 가이드라인
	문자열을 어떤 형으로 저장할지 선택하는 기준
	문자열 변수는 문자 배열에 저장한다
	문자열 상수는 문자열 리터럴로 나타낸다.

	char* 형의 포인터는 문자배열, 즉 변경할 수 있는 문자열을 가리킬 때만 사용한다.
	const char*형의 포인터는 변경할 수 없는 문자열을 가리킬 때 사용한다.
	문자열 리터럴을 가리킬 때는 const char*형의 포인터를 사용한다.
	문자배열을 읽기 전용으로 접ㄱ근할 때는 const char* 포인터를 사용한다
	
	문자열을 매개변수로 전달하는 함수를 정의할 때 주의사항
	문자열이 출력 매개변수 일 때는 char*형의 매개변수를 사용하고 문자배열의 크기도 매개변수로 받아와야함 함수 안에서 문자열을 변경할 때는 문자배열을 넘어서지 않도록 주의
	문자열이 입력 매개변수 일 때는 const char*형 매개변수 사용, 이 때 문자열 끝을 널 문자로 확인할 수 있으므로 문자배열의 크기를 매개변수로 받을 필요가 없다.
	문자열 사용시 문자배열처럼 인덱스 사용 가능

	문자열을 매개변수로 전달하는 함수 호출시 주의 사항
	매개변수의 데이터형이 char*형일 때는 문자 배열과 char*형의 포인터만 인자로 전달 가능, 함수 호출 후 인자로 전달된 문자열의 내용이 변경 될 수 있음
	매개변수의 데이터형이 const char*형일 때 문자배열,문자열리터럴,char*형의 포인터, const char*형의 포인터를 모두 인자로 전달 할 수 있다. 함수 호출 후에도 인자로 전달된 문자열의 내용은 달라지지 않는다.

	int swap_string(char*lhs.char*rhs,int size);

	int main()
	{
		char str1[size]="";
		char str2[size]="";

		printf("문자열 2개?");
		scnaf("%s %s",str1,str2);

		prntf("str1=%s,str2=%s\n",str1,str2);
		swap_string(str1,str2,size);
		printf("str1=%s,str2=%s\n",str1,str2);
		return 0;
	}
	int swap_string(char*lhs.char*rhs,int size)
	{
		int lhs_len=strlen(lhs);
		int rhs_len=strlen(rhs);
		char temp[size]="";

		if(lhs_len+1>size || rhs_len+1>size)
			return 0;
		strcpy(temp,lhs);
		strcpy(lhs,rhs);
		strcpy(rhs,temp);
		return 1;

문자열의 배열
문자열을 여러개 저장하려면 2차원 배열이 필요하다.
2차원 문자 배열
2차원 문자 배열을 선언할 때는 널 문자를 포함한 문자열의 길이를 열 크기로, 문자열의 개수를 행 크기로 지정한다.
char books[5][30]//문자열 길이가 30인 문자열 5개 저장

2차원 문자 배열의 각 문자열에 접근하려면 행 인덱스만 사용하면 된다
i번째 문자열의 j번째 문자에 접근하려면 books[i][j]처럼 행 인덱스와 열 인덱스를 모두 사용한다.

int main()
{
	char books[5][30]={
		"wonder",
		"me before you",
		"the hunger games",
		"twilight",
		"harry potter"}

	int i=0;
	for(i=0;i<5;i++)
		printf("책 제목:%s\n",books[i]);
	for(i=0;i<5;i++)
		if(islower(books[i][0])
			books[i][0]=toupper(books[i][0]);
	puts("<<변경 후>>");
	for(i=0;i<5;i++)
		printf("책 제목:%s\n",books[i]);
	return 0;
}
2차원 문자배열에 저장된 문자열에 대하여 strlen,strcpy,strcmp,strcat 등의 문자열 처리 함수를 사용하려면 행 인덱스만 지정해서 사용하면 된다.

문자열 포인터 배열
같은 문자열 리터럴을 여려 번 사용할 때는 문자열 포인터에 문자열 리터럴의 주소를 저장해두고 사용 할 수 있다.
const char*형의 포인터로 문자열 리터럴을 가리키는 경우에는 문자열 리터럴을 수정할 필요가 있을 때, 포인터 선언문만 수정하면 된다
문자열 리터럴의 주소가 원소인 배열은 const char*형의 포인터 배열로 선언한다.

*/