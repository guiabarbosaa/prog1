#include <stdio.h>

int main() {
    char c;

    scanf("%c", &c);
    printf("RESP:");
    while (c != '.' && c != '?' && c != '!') {
        if (c == ' ') {
            printf("_");
        } else {
            printf("%c", c);
        }
        scanf("%c", &c);
    }

    return 0;
}

