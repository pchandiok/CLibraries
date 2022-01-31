#include "lib/hclib.c"

int main()
{
    string str = GetString("Enter a string: ");
    printf("%s\n", str);
    printf("%i %i %i\n", letters, words, sentence);
    free(str);

    int i = GetInt("Enter an integer: ");
    printf("%i\n", i);
    double d = GetDouble("Enter an Double: ");
    printf("%f\n", d);
    long l = GetLong("Enter an Long: ");
    printf("%ld\n", l);
    float f = GetFloat("Enter an Float: ");
    printf("%0.f\n", f);
}
