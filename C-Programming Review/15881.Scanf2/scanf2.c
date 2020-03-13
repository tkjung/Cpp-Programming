#include <stdio.h>

int main()
{
    int eng;
    int math;

    int num_eng = 0;
    int num_math = 0;
    int num_equal = 0;

    while ( scanf("%d %d", &eng, &math) == 2 )
    {
        if (eng > math)
        {
            num_eng += 1;
        }

        else if (math > eng)
        {
            num_math += 1;
        }

        else
        {
            num_equal += 1;
        }
    }

    printf("영어 성적이 더 좋은 학생 수 : %d \n", num_eng);
    printf("수학 성적이 더 좋은 학생 수 : %d \n", num_math);
    printf("영어 수학 성적이 같은 학생 수 : %d \n", num_equal);
}
