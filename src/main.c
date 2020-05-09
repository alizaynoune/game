#include "header.h"

void		message_error(char *str)
{
	printf("%sError: %s%s\n", RED, str, DEF);
	exit(1);
}

void		free_error(data_t *d, char *str)
{
	free(d);
	message_error(str);
}

void	*ft_memset(void *b, int c, size_t len)
{
	size_t		i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)b;
	while (i < len)
		str[i++] = (unsigned char)c;
	return ((void *)str);
}

void	*ft_memalloc(size_t size)
{
	void	*ptr;

	ptr = NULL;
	if (size >= 1)
		if (!(ptr = (void *)malloc(sizeof(void) * size)))
			return (NULL);
	ft_memset(ptr, 0, size);
	return (ptr);
}
int		all_digit(char *str)
{
	size_t		i;

	i = 0;
	while (str[i])
	{
		if (str[i] > '9' || str[i] < '0')
			return (0);
		i++;
	}
	return (1);
}


void		read_line(data_t *d)
{
	char	c;

	d->l.len = 0;
	while (read(0, &c, 1) > 0 && c != '\n' && d->l.len < SIZE)
		d->l.line[d->l.len++] = c;
	if (d->l.line[0] == 'q')
	{
		free(d);
		exit(0);
	}
	if (c != '\n' && d->l.len == SIZE)
		while (read(0, &c, 1) > 0 && c != '\n');
	d->l.line[d->l.len] = '\0';
	d->l.len == 0 ? free_error(d, "where the number"): 0;
	all_digit(d->l.line) == 0? free_error(d, "in next time enter just number"): 0;
}

int		main(void)
{
	data_t	*d;
	int	i;

	i = 0;
	if (!(d = ft_memalloc(sizeof(data_t))))
		message_error("malloc (-_-)");
	printf("%spleas enter the number of operation or q to exit%s\n", BLUE, DEF);
	read_line(d);
	if ((d->loop = atoi(d->l.line)) <= 0)
		free_error(d, "nuber of operation is less thane 1");
	printf("%spleas enter your first nuber or q to exit%s\n", BLUE, DEF);
	read_line(d);
	d->len = d->l.len;
	get_res(d);
	printf("%s\n", d->l.line);
	while (i < (d->loop / 2))
	{
		read_line(d);
		d->l.len > d->len || d->l.len == 0 ? message_error("Error: lenght of number") : 0;
		d->l.len < d->len ? fix_str_len(d): 0;
		print_my_number(d->l.line);
		i++;
	}
	free(d);
	return (0);
}
