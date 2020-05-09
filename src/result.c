#include "header.h"
int		len_res(data_t *d)
{
	int		i;
	int		l;
	short		add;

	i = 0;
	add = 0;
	l = d->len - 1;
	while (l >= 0)
	{
		add = ((d->l.line[l--] - '0') + ((d->loop / 2) * 9));
		i++;
	}
	add > 0 ? i += 1 : 0;
	return (i);
}


void		fix_str_len(data_t *d)
{
	int		i;
	int		j;

	i = d->len;
	j = d->l.len;
	while (j >= 0)
		d->l.line[i--] = d->l.line[j--];
	while (i >= 0)
		d->l.line[i--] = '0';
}


void		get_res(data_t *d)
{
	char		*res;
	short		add;
	int		len;
	int		l;

	add = 0;
	len = len_res(d);
	l = d->len - 1;
	if (!(res = ft_memalloc(len)))
		free_error(d, "malloc (-_-)");
	res[len--] = '\0';
	while (l >= 0)
	{
		add = ((d->l.line[l--] - '0') + ((d->loop / 2) * 9) + add);
		res[len--] = (add % 10) + '0';
		add /= 10;
	}
	add > 0 ? res[len] = (add % 10) + '0': 0;
	printf("%sThe result is [%s%s%s]%s\n",GREEN, RED, res, GREEN, DEF);
	free(res);
}

void		print_my_number(char *str)
{
	size_t		i;

	i = 0;
	printf("%s", YELLOW);
	while (str[i])
		printf("%d", 9 - (str[i++] - '0'));
	printf("%s\n", DEF);
}
