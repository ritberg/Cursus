#ifndef MICROSHELL_H
# define MICROSHELL_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <stdio.h>

typedef struct s_cmd
{
	char			*content;
	struct s_cmd	*next;
}	t_cmd;

# endif
