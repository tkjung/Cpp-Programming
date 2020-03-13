#include <stdio.h>
#include <string.h>

int main()
{
    char name[20][100];
    char *ptr[20];
    int count = 0; // 입력된 이름이 개수

    while ( count < 20 && scanf("%s", name[count]) == 1 )
    {
        count++;
    }

    // 각 포인터가 순서대로 스트링을 가리키게 한다.
    for( int i = 0 ; i < count; i++)
    {
        ptr[i] = name[i];
    }

    printf("----초기 데이터----\n");

    for( int i = 0; i < count; i++)
    {
        printf("%s\n", ptr[i]);
    }

    // 정렬
    for( int i = 0; i < count-1 ; i++)
    {
        // ptr[0]과 ptr[1] 중에 ptr[0]이 더 나중의 알파벳이면
        if (  strcmp( ptr[i], ptr[i+1] ) > 0 )
        {
            // ptr[0] <-> ptr[1] 교체
            char *temp;
            temp = ptr[i];
            ptr[i] = ptr[i+1];
            ptr[i+1] = temp;
        }
    }

    printf("\n\n----정렬 후 데이터----\n");

    for( int i = 0; i < count; i++)
    {
        printf("%s\n", ptr[i]);
    }
}
