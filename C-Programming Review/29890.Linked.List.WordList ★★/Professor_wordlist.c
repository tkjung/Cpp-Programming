#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct wlist {
    char *word;
    int count;
    struct wlist *next;
} wlist_t;

void update_or_insert(wlist_t **start, char buf[])
{
    // 1. buf를 word에 복사
    wlist_t *p;
    p = (wlist_t*)malloc(sizeof(wlist_t));

    p->word = (char*)malloc(strlen(buf) + 1);
    strcpy(p->word, buf);

    p->count = 1;
    p->next = 0;

    // 2-1. 첫 항목으로 삽입하는 경우
    if(  *start == 0 || strcmp(p->word, (*start)->word) < 0  )
    {
        p->next = *start;
        *start = p;
    }

    // 2-2. 첫 항목으로 삽입하지 않는 경우
    else
    {
        wlist_t *finger;
        finger= *start;

        // 멈추는 조건: finger->next == 0 또는 w < finger->next->word
        while ( finger->next != 0 && (strcmp(p->word, finger->next->word) >= 0 )  )
        {
            finger = finger->next;
        }

        p->next = finger->next;
        finger->next = p;

        // 여기에 오면 같은 단어이거나 앞단어이다.
        if ( strcmp ( p->word, finger->word ) == 0 )
        {
            // 증가
            finger->count++;
            finger->next = p->next;
            free(p);
        }
    }
}

int main()
{
    wlist_t *pStart = 0;
    char buf[100]; // 최대 단어 길이는 영문자 기준 99

    while ( scanf("%s", buf) == 1 )
    {
        update_or_insert(&pStart, buf);
    }

    // 그리고는 순서대로 항목과 count를 출력한다
    while ( pStart != 0 )
    {
        printf("%s %d\n", pStart->word, pStart->count);
        pStart = pStart->next;
    }
}
