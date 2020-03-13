#include <stdio.h>
#include <stdlib.h>

typedef struct square {
    int width; // 가로
    int height; // 세로
} square;

int main(int ac, char *av[])
{
    int count = 0; // 입력한 사각형 개수
    square *ps[100]; // 사각형은 최대 100개로 가정

    // 1. 동적할당, 입
    struct square temp;
    //
    for(int i = 0; i < 100 && scanf("%d %d", &ps[i]->width, &ps[i]->height) == 2; i++)
    {
        // 구조체 포인터 배열을 이용하여 동적할당
        ps[i] = (square*)malloc(sizeof(square));

        // 2개씩 짝지어서 입력받음. 그때마다 사각형 개수 +1
        //if ( scanf("%d %d", &ps[i]->width, &ps[i]->height) == 2)
        //{
            //count += 1;
        //}
    }

    int numSquare = i;

    // 2. 큰 것이 위에 오도록 정렬
    for(int j = 0; j < count -1; j++)
    {
        for(int i = 0; i < count - 1; i++)
        {
            if(  (ps[i]->width * ps[i]-> height) < (ps[i+1]->width * ps[i+1]->height)  )
            {
                square *t;
                t = ps[i];
                ps[i] = ps[i+1];
                ps[i+1] = t;
            }
        }
    }

    // 3. 정렬 후 출력
    for(int i = 0; i < count; i++)
    {
        printf("%d %d\n", ps[i]->width, ps[i]->height);
    }
}
