#include <stdio.h>

int main()
{
    int i;

    for (i = 0; i <= 15; i++) {
        if (i == 10) {
            continue;
        }
        printf("Iteration %d\n", i);
    }

    return 0;
}
