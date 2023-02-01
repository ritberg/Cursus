int	ft_atoi_base(const char *str, int str_base)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i])
	{
		result = result * str_base;
		if (str[i] >= '0' && str[i] <= '9')
			result = result + str[i] - '0';
		else if (str[i] >= 'A' && str[i] <= 'Z')
			result = result + str[i] - '7';
		else if (str[i] >= 'a' && str[i] <= 'z')
			result = result + str[i] - 'W';
		i++;
	}
	return (result * sign);
}
