#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct person{
    char id[15];    // 주민 번호.
    char *name;     // 이름. 최대 200바이트로 하되 메모리 낭비를 없게 동적할당한다.
}person;

// 함수 getPerson, printAll, removeAll 함수를 작성하라.
person *getPerson()
{
    person *ps;
    ps = (person*)malloc(sizeof(person));

    // 주민번호 입력
    // 데이터가 없을 시에는 0을 반환, 있을 시엔 입력.
    if( scanf("%s", ps->id) != 1 )
    {
        return 0;
    }

    // 이름 입력
    char buffer[200];
    scanf("%s", buffer);
    ps->name = (char*)malloc(strlen(buffer) + 1);
    strcpy(ps->name, buffer);

    return ps;
}

void printAll(person *ps[], int count)
{
    for(int i = 0; i < count; i++)
    {
        printf("%s %s\n", ps[i]->id, ps[i]->name);
    }
}

void removeAll(person *ps[], int count)
{
    // 포인터를 반납하는 것이 아니라, 포인터가 가리키는 메모리를 반납
    // 할당 받은 것을 반납
    for(int i = 0; i < count; i++)
    {
        free(ps[i]->name);
        free(ps[i]);
    }
}

int main()
{
    person *employee[100];
    int count;
    person *t;

    for ( count = 0; t = getPerson(); count++)
    {
        employee[count] = t;
    }

    printAll(employee, count);  // 이 출력 함수는 만들어야 한다.
    removeAll(employee, count);  //  동적할당한 모든 메모리를 반환. 주의할 점이 있다.

    return 0;
}
