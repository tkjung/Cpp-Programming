#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 버전2: 더블포인터 버전

int main()
{
    char **str;
    char buffer[100];
    int numStr;

    scanf("%d", &numStr);

    str = (char**)malloc(sizeof(char*) * numStr);

    for (int i = 0; i < numStr; i++)
    {
        scanf("%s", buffer);
        str[i] = (char*)malloc(strlen(buffer) + 1);
        strcpy(str[i], buffer);
    }

    for (int i = numStr-1; i >=0; i--)
    {
        printf("%s\n", str[i]);
    }
}
