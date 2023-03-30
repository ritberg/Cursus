#include "unistd.h"
#include "stdio.h"

int	main()
{
	int	fd1[2];
	int	fd2[2];
	char	inputstr[100];

	int	p;

	scanf("%s", inputstr);
	p = fork();

	if (p > 0)
	{
		char	concatstr[100];

		close(fd1[0]);
		write(fd1[1], inputstr, strlen(inputstr) + 1);
		close(fd1[1]);

		wait(NULL);

		close(fd2[1]);
		read(fd2[0], concatstr, 100);
		printf("Concatenated str %s\n", concatstr);
		close(fd2[0]);
	}
	else
	{
		close(fd1[1]);
		char	concatstr[100];

		read(fd1[0], concatstr, 100);
}
