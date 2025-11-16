#include <stdio.h>
#include <string.h>

int main() {
    char palavra[] = "arara";
    int i, j, len;

    len = strlen(palavra);

    for (i = 0, j = len - 1; i < j; i++, j--) {
        if (palavra[i] != palavra[j]) {
            printf("A palavra '%s' não é um palíndromo.\n", palavra);
            return 0;
        }
    }

    printf("A palavra '%s' é um palíndromo.\n", palavra);
    return 0;
}
