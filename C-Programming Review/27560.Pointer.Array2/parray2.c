/*
이전 문제의 프로그램을 수정하여 출력 전에
 parr[0]와 parr[4]의 값을 맞바꾸어보라.
나머지는 그대로 둔다.

* 힌트: 정수를 바꾸는 것이 아니다.^K
따라서 임시 변수는 포인터 형 변수가 필요.

** 여기서 우리는 데이터의 실제 위치를 바꾸지 않아도 포인터만을
바꾸어 순서를 "사실상" 바꾸는 효과를 가져올 수 있음을 관찰하자. 
*/

#include <stdio.h>

int main()
{
    int arr[5] = {55, 22, 33, 44, 11};
    int *parr[5]; // 정수 포인터 5개로 구성된 배열이다.
    int i;

    for(i = 0; i < 5; i++)
    {
        parr[i] = &arr[i];
    }

    int *temp;
    temp = parr[0];
    parr[0] = parr[4];
    parr[4] = temp;

    for(i = 0; i < 5; i++)
    {
        printf("%d ", *parr[i]);
    }

    return 0;
}
