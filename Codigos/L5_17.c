#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    char palavra[500][501];
    int i=0;
    while(scanf("%[A-Za-z]", palavra[i])==1)
    {
        scanf("%*[^A-Za-z]");
        i++;
    }
    
    for(i;i>=0;i--)
    {
        printf("%s ", palavra[i]);
    }
    return 0;
}
		
		
