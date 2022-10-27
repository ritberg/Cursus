char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	if (*s2 == '\0')
		return (*s1);
	while (*s1)
	{
		if (*s1 != *s2)
			return (0);
		s1++;
		s2++;
	}
	return (*s1);
}
