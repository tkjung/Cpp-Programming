/*
다음의 프로그램은 두개의 스트링을 바꾸기 위한 시도인데,
swap 함수에서 call-by-value 때문에 실제로 포인터가 바뀌지 않는다.
이를 double pointer를 이용하여 두 스트링이 바뀌도록 수정하라.
*/

#include <stdio.h>
void swap(char **one, char **two){
    char *t;
    t = *one; *one = *two; *two = t;
}

int main(){
    char *p = "First string.";
    char *q = "Second string.";;

    swap(&p, &q);
    printf("%s %s\n", p, q);
    return 0;
}
