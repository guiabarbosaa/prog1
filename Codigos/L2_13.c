#include <stdio.h>

int main() {
    char c;

    scanf("%c", &c);
    while (c != '.' && c != '?' && c != '!') {
           if (c >= 'a' && c <= 'z') {
            printf("%c", c - 32);
         } else {
            printf("%c", c);
        }
        scanf("%c", &c);
    }
    
    printf("%c", c);

    return 0;
}

