/* 
주어진 스트링을 새 메모리에 복제하고 그 주소를 돌려주는 함수 str_clone을 작성하라.
프로토타입:  char * str_clone(char *);

main함수처럼 테스트한다. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* str_clone(char *s)
{
    char *t;

    t = (char*)malloc(strlen(s));
    strcpy(t, s);

    return t;
}

int main()
{
    char str[100];
    char *p;

    scanf("%s", str);
    p = str_clone(str);

    printf("%s %s\n", str, p);

    //strcpy(str, "modified");
    //printf("%s %s\n", str, p);

    return 0;
}
