/* 
scanf를 통해서 스트링을  buffer 라는 배열에 읽어들인다. (최대 스트링 길이는 80으로 가정한다.)
char *pStr;  포인터 변수를 이용하여 읽어 들인 스트링을 저장할 메모리를 할당하고 buffer의 내용을 복사(strcpy)한다.
pStr를 이용하여 내용을 출력한다.
*/

#define _CRT_SECURE_NO_WARNINGS  // VS에서 작성할 경우에 대비해서.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// 여기에 malloc을 위한 헤더 파일을 포함시켜야 한다.

#define MAX_STR 80

int main()
{
    char buffer[MAX_STR+1];
    char *pStr;

    scanf("%s", buffer);

    // 여기에 실제 스트링 길이+1 만큼 할당이 필요하다.
    pStr = (char*)malloc(strlen(buffer) + 1);

    // 할당 받은 메모리에 buffer의 내용을 strcpy로 복사한다.
    strcpy(pStr, buffer);

    printf("%s\n", pStr);
    return 0;
}
