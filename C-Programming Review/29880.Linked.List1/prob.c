#include <stdio.h>
#include <stdlib.h>

struct item {
    int score;
    struct item * next;
} ;
void init(struct item **);    // 구현해야 함.
void printall(struct item *); // 구현해야 함.


int main(){
    struct item *first = 0;
    init(&first);

    printf("Before\n");
    printall(first);

    // 코드 수정 시작
    struct item *temp = 0;
    struct item *p = 0;

    // 1. 추가할 마지막 구조체 생성
    p = (struct item*)malloc(sizeof(struct item));
    p->score = 99;
    p->next = 0;

    // 2. 끝 주소 찾아가기.
    temp = first;
    // ** 조건문에 (temp != 0) 이 아니라, (temp->next != 0) 으로 해야한다.
    while (temp->next != 0 )
    {
        temp = temp->next;
    }

    // 3. 끝 주소를 마지막 구조체와 같게 해주기
    temp->next = p;

    // 코드 수정 끝.
    printf("After\n");
    printall(first);
}
