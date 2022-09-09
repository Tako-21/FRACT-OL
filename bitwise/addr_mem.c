#include <stdio.h>

int main(void)
{
    long n = 1;
    double f = 1.;
    unsigned char *byte = (unsigned char *)&n;

    for (unsigned i = 0; i < sizeof n; ++i)
        printf("%x ", byte[i]);

    printf("\n");
    byte = (unsigned char *)&f;

    for (unsigned i = 0; i < sizeof f; ++i)
        printf("%x ", byte[i]);

    printf("\n");
    return 0;
}

