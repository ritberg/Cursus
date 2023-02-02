#include "unistd.h"

int small_atoi(char *str)
{
    int i;
    int result;

    i = 0;
    result = 0;
    while (str[i])
    {
        result = result * 10 + (str[i] - '0');
        i++;
    }
    return (result);
}

int main(int argc, char **argv)
{
    int d;
    int j;
    int result;
    int k;
    char    hexadec[100];

    d = 0;
    result = 0;
    if (argc == 2)
    {
        d = small_atoi(argv[1]);
        j = 0;
        while (d != 0)
        {
            result = d % 16;
            if (result < 10)
                hexadec[j] = result + '0';
            else
                hexadec[j] = result + 87; //what is 87???
            d = d / 16;
            j++;
        }
        k = j - 1;
        while (k >= 0)
        {
            write(1, &hexadec[k], 1);
            k--;
        }
    }
    write(1, "\n", 1);
    return (0);
}