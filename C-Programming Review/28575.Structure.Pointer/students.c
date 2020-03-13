#include <stdio.h>
#include <stdlib.h>

typedef struct stu {
    int id;
    char name[20];
    float gpa;   // 평점 평균
} stu;


int main()
{
    stu *kim;

    // 주어진 구조체 포인터를 이용하여 동적할당을 하고
    kim = (stu*)malloc(sizeof(stu));

    // id, 이름, 학점(평점평균) 순서로 표준 입력에서 읽어서 동적으로 할당된 구조체에 저장한다.
    scanf("%d %s %f", &kim->id, kim->name, &kim->gpa);

    // 같은 순서로 확인 출력한다.
    printf("학번: %d\n이름: %s\n학점: %.2f\n", kim->id, kim->name, kim->gpa);
}
