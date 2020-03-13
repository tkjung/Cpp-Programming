#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct worditem
{
    char *word;  // 오타 수정 from char word[30];
    int wtype;   // 0 noun(명사), 1 verb(동사), 2 adjective(형용사)
} worditem;

typedef struct itemlist
{
    int numWords;  // 전체 단어 수
    worditem ** theList; // worditem에 대한 포인터 배열을 만들 이중포인터
} itemlist;

// 단어 구조체 1개를 채운 후 포인터를 돌려주는 함수
worditem *getWordItem()
{
    worditem *pw;
    pw = (worditem*)malloc(sizeof(worditem));

    // 단어 입력
    char buffer[100];
    scanf("%s", buffer);
    pw->word = (char*)malloc(strlen(buffer) + 1);
    strcpy(pw->word, buffer);

    // 단어 타입 입력
    scanf("%d", &pw->wtype);

    return pw;
}

// getWordItem()함수를 반복호출하여, 포인터 배열로 목록을 만듦
itemlist *getWordList()
{
    itemlist *pi;
    pi = (itemlist*)malloc(sizeof(itemlist));

    // 단어 개수 입력
    scanf("%d", &pi->numWords);
    // 단어 개수만큼 구조체 포인터 형성
    pi->theList = (worditem**)malloc(sizeof(worditem*) * pi->numWords);

    // getWordItem()을 호출하여, 목록에 하나씩 입력해준다.
    for(int i = 0; i < pi->numWords; i++)
    {
        pi->theList[i] = getWordItem();
    }

    return pi;
}

void printAll(itemlist *pi)
{
    for(int i = 0; i < pi->numWords; i++)
    {
        printf("%s", pi->theList[i]->word);

        if( pi->theList[i]->wtype == 0 )
        {
            printf("\t명사\n");
        }
        else if( pi->theList[i]->wtype == 1 )
        {
            printf("\t동사\n");
        }
        else
        {
            printf("\t형용사\n");
        }
    }
}

int main()
{
    itemlist *myList;

    myList = getWordList();  //

    printAll(myList);

    return 0;
}
