/*
포인터 "myarray"를 이용하여 정수의 동적 할당 배열로 사용하도록
수정하라.
*/

#include <stdio.h>
#include <stdlib.h>
int main()
{
    int index;

    int size;

    printf("Size 를 입력하세요:");
    scanf("%d", &size);

    int *myarray[size];

    // 동적 할당이 필요함.
    for (index=0; index<size; index++)
    {
        myarray[index] = (int*)malloc(sizeof(index));
        scanf("%d", &myarray[index]);
    }

    for (index=size-1; index>=0; index--)
    {
        printf("%d\n", myarray[index]);
    }

    return 0;
}
