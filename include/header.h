#ifndef HEADER_H
# define HEADER_H
/*
*** includes
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*
*** colors
*/

#define DEF	"\e[1;0m"
#define RED	"\e[1;31m"
#define BLUE	"\e[1;96m"
#define YELLOW	"\e[1;33m"
#define GREEN	"\e[1;32m"
/*
*** size of buffer
*/

#define SIZE	(1000)

typedef struct		line_s
{
	char		line[SIZE + 1];
	size_t		len;
}			line_t;
typedef struct		data_s
{
	line_t		l;
	size_t		len;
	int		loop;
	char		*rus;
}			data_t;

void		get_res(data_t *d);
void		fix_str_len(data_t *d);
void		print_my_number(char *str);
void		*ft_memalloc(size_t size);
void		free_error(data_t *d, char *str);

#endif
