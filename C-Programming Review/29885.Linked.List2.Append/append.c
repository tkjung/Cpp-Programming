#include <stdio.h>
#include <stdlib.h>

// 버전4: del_end( ) 함수 완성, 전체 완성

typedef struct item {
    int data;
    struct item * next;
} item_t;

// 함수들의 프로토타입 선언 부분
void append(item_t **, int); // 리스트의 맨 뒤에 붙이는 함수
void del_end(item_t ** ppS ); // 리스트의 맨 뒤 항목을 삭제하는 함수
void print_all(item_t *); //  출력 함수

int main()
{
    struct item *pStart = 0;
    int data;

    while (scanf("%d", &data) == 1)
    {
        append(&pStart, data);
    }

    // 만일 입력이 1 2 3 였다면
    printf("넣은 후: "); print_all( pStart ); // 1 --> 2 --> 3  --> END  출력.
    del_end( &pStart );  // 3을 지움.
    printf("삭제 후: "); print_all( pStart ); // 1 --> 2 --> END 를 출력.

    return 0;
}

void append(item_t **pStart, int num)
{
    item_t *pAlloc; // 메모리 할당을 위한 임시 포인터

    if (*pStart == 0) // 비어있는 리스트에 삽입하는 경우
    {
        pAlloc = (item_t*)malloc(sizeof(item_t));
        pAlloc->data = num;
        pAlloc->next = 0;
        *pStart = pAlloc;
    }
    else // 1개 이상 들어있는 경우
    {
        item_t * finger;
        finger = *pStart; // 0인 경우는 없다.

        // 1. 반복문으로 끝 항목을 찾는다.
        while( finger->next != 0 )
        {
            finger = finger->next;
        }
        // 끝 항목이 맞는지 확인
        printf("끝 직전 구조체의 data값 : %d\n", finger->data);

        // 2. 끝 항목의 뒤에 새 항목을 할당하여 붙인다.
        pAlloc = (item_t*)malloc(sizeof(item_t));
        pAlloc->data = num;    // 새로운 데이터 설정
        pAlloc->next = 0;      // 마지막 항목 포인터도 0으로 만든다.
        finger->next = pAlloc; // 끝에 연결.
    }
}

// 모든 항목을 순서대로 출력하는 함수.
void print_all(item_t *s)
{
    printf("START --> ");
    while( s != 0  )
    {
        printf("%d --> ", s->data);
        s = s->next;
    }
    printf(" END\n");
}

// 리스트의 맨 뒤 항목을 삭제하는 함수
void del_end(item_t ** pStart )
{
    // 1. 경우의 수를 나눈다.
    // 1-1. 비어있어서 del_end( )할 항목이 없는 경우
    if ( *pStart == 0 )
    {
        printf("del_end( )할 항목이 없습니다.\n");
    }

    // 1-2. 구조체가 1개만 있어서 1개만 삭제하면 되는 경우
    else if ( (*pStart)->next == 0 )
    {
        *pStart = 0;
    }

    // 1-3. 구조체가 2개 이상이라서, 마지막 것을 삭제하는 경우
    else
    {
        // 2. free시킬 임시 포인터 pFree를 만들어, 마지막을 가리켜 붙잡아둔다.
        item_t *pFree = 0;
        pFree = (item_t*)malloc(sizeof(item_t)); // 2-1. 크기만큼 동적할당

        // 2-2. pFree를 마지막 구조체를 가리키게 한다.
        pFree = *pStart;

        while ( pFree->next != 0 )
        {
            pFree = pFree->next;  // pFree->next = 0 이 된다.
        }

        // 3. finger가 마지막 직전 구조체를 가리키게 한다.
        item_t * finger;
        finger = *pStart;

        while ( finger->next->next != 0 ) // 마지막 직전을 가리키게 하는 조건문
        {
            finger = finger->next;
        }

        // 4. finger->next 에 0을 주어 마지막으로 만든다.
        finger->next = 0;

        // 5. 붙잡아두었던 것을 free 시켜준다.
        free(pFree);
    }
}
