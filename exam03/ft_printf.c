#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

void	put_str(char *str, int *len)
{
	if (!str)
		str = "(null)"; //cf. gnl cursus
	while (*str)
		*len += write(1, str++, 1);
}

void	put_digit(long long int nb, int base, int *len)
{
	char	*hexadec = "0123456789abcdef";

	if (nb < 0)
	{
		nb *= -1;
		*len += write(1, "-", 1);
	}
	if (nb >= base)                        //nb = 57, in hexadec = 39
		put_digit((nb / base), base, len);    // 57 / 16 = 3
	*len += write(1, &hexadec[nb % base], 1);   // 57 % 16 = 9
}

int	ft_printf(const char *format, ...)
{
	int len = 0;

	va_list	pointer;
	va_start(pointer, format);

	while (*format)
	{
		if ((*format == '%') && ((*(format + 1) == 's') || \
					(*(format + 1) == 'd') || (*(format + 1) == 'x')))
		{
			format++;
			if (*format == 's')
				put_str(va_arg(pointer, char *), &len);
			else if (*format == 'd')
				put_digit((long long int)va_arg(pointer, int), 10, &len);
			else if (*format == 'x')
				put_digit((long long int)va_arg(pointer, unsigned int), 16, &len);
		}
		else
			len += write(1, format, 1);
		format++;
	}
//	va_end(pointer);
	return (va_end(pointer), len);
}


int	main()
{
	printf("Un nombre décimal (base 10):\n");
	ft_printf("ft_printf: %d\n", 2147483647);
	printf("printf: %d\n", 2147483647);
	printf("\n");

//	ft_printf("%i\n", 42);
//	printf("Un nombre i: %i\n", 42);

	printf("Chaîne de caractères:\n");
	ft_printf("ft_printf: %s\n", "abc"); // NULL as last arg??
	printf("printf: %s\n", "abc");
	printf("\n");

/*
	int x = 1 + 2;
	void	*p = &x;
	ft_printf("%p\n", p);
	printf("Pointeur: %p\n", p);
*/

/*	Afficher les valeurs de retour pour x:
	long l = 25;

	int r1 = ft_printf("%x", l);
	int r2 = printf("%lx", l);
	printf("\n R1 = %i, R2 = %i\n", r1, r2);
*/

	printf("Un nombre en hexadécimal (base 16) min:\n");
	ft_printf("ft_printf: %x\n", 103087);
	printf("printf:  %x\n", 103087);
	printf("\n");


//	ft_printf("%%%%%%%\n");
//	printf("\n%%%%%%%\n");

	ft_printf("ft_printf : salut\n");
	printf("printf : salut\n");
	printf("\n");

	ft_printf(""); //an empty line is printed for both
	printf("");

	return (0);
}
