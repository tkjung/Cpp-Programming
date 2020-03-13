#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 버전5: 각 케이스에 대하여 입력이 여러 개인 경우

typedef struct item {
    char *word; // 입력받는 단어. 동적할당 이용.
    int count;  // 빈도
    struct item *next; // 다음 구조체를 가리키는 포인터
} item_t;

// 새로운 단어: 삽입
// 기존 있는 단어: (빈도+1) 해주는 함수
void update_or_insert( item_t **pStart, char buf[])
{
    // 1. buf를 word에 복사
    item_t *p; // 메모리 할당을 위한 임시 포인터
    p = (item_t*)malloc(sizeof(item_t));

    p->word = (char*)malloc( strlen(buf) + 1 );
    strcpy( p->word, buf );

    p->next = 0;

    // ## 단어를 입력하면 오름차순으로 Linked list에 끼워 넣는다.

    // 2. 첫 항목으로 끼워 넣는 경우:
    // 2-1. 시작 포인터가 0
    if(*pStart == 0)
    {
        p->count = 1;
        *pStart = p;
    }
    // 2-2. 0은 아닌데 첫 항목의 데이터보다 새 데이터가 더 작은 경우
    else if (  strcmp( (*pStart)->word, p->word) > 0  ) // 첫 데이터: ddd, 새 데이터: ccc
    {
        p->count = 1;
        p->next = *pStart; // pStart -> ccc있는 구조체 -> ddd있는 구조체 중, 둘째 화살표 연결
        *pStart = p; // pStart -> ccc있는 구조체 -> ddd있는 구조체 중, 첫째 화살표 연결
    }

    // 3. 중간 어딘가에 끼워 넣는 경우: p = pStart부터 시작해서
    //    p가 가리키는 다음 항목이 있고, 다음 항목이 더 작은 경우에만
    //    p를 다음 항목으로 update해서 반복한다.
    //    찾기가 끝나면 끼워 넣기를 하면 된다.
    else if ( strcmp( (*pStart)->word, p->word) < 0 ) // 첫 데이터: ddd, 새 데이터: eee이상
    {
        p->count = 1;

        item_t *finger = *pStart;
        while (   strcmp( finger->word, p->word ) < 0 && finger->next != 0   )
        {
            finger = finger->next;
        }

        finger->next = p; // pStart -> ddd구조체 -> eee구조체 중, 둘째 화살표 연결

    }

    // 4. 기존 있는 단어라면, (빈도+1)
    else
    {
        item_t *finger = *pStart;
        while (   strcmp( finger->word, p->word ) < 0   )
        {
            finger = finger->next;
        }

        finger->count++;

        free(p);
    }
}

int main( )
{
    item_t *pStart = 0;
    char buf[100];  //최대 단어 길이: 영문자 기준 99

    while ( scanf("%s", buf) == 1 )
    {
        update_or_insert(&pStart, buf);
    }

    // 순서대로 단어와 count를 출력한다.
    while ( pStart != 0 )
    {
        printf("%s %d\n", pStart->word, pStart->count);
        pStart = pStart->next;
    }
}
