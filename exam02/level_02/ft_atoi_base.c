int ft_atoi_base(const char *str, int str_base)
{
    int i;
    int count_sign;
    int d;
    int res;
    char hexadec[100];
    int j;

    i = 0;
    d = 0;
    res = 0;
    count_sign = 0;
    j = 0;
    while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\v' || str[i] == '\r' || str[i] == '\f')
        i++;
    while (str[i] == '-')
    {
        count_sign++;
        i++;
    }
    if (str_base = 16)
        while (str[i])
        {
            d = d * 10 + (str[i] - '0');
            i++;
        }
        while (d != 0)
        {
            res = d % 16;
            if (res < 10)
                hexadec[j] = res + '0';
            else
                hexadec[j] = res + 87;
            d = d / 16;
        }
}