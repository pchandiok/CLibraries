#include <stdio.h>
#include <stdlib.h>
#include "lib/hclib.h"

int main()
{
    string str = GetString("Enter a string: ");
    printf("%s\n", str);
    free(str);
}
