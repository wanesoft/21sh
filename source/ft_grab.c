
#include "../include/twenty_one_sh.h"

static void		ft_grab_4(char **tmp2)
{
	char		*tmp;
	char		c[2];
	
	c[0] = -50;
	c[1] = 0;
	tmp = ft_strjoin(*tmp2, (char *)&c);
	free(*tmp2);
	*tmp2 = tmp;
}

static void		ft_grab_3(char **s, int i, int j, int len)
{
	char		*tmp;
	char		*tmp2;
	char		*tmp3;
	char		*tmp4;
	
	tmp = ft_strndup(*s, i);
	tmp2 = ft_itoa(len);
	ft_grab_4(&tmp2);
	tmp3 = ft_strjoin(tmp, tmp2);
	tmp4 = ft_strjoin(tmp3, &(*s)[j]);
	free(*s);
	*s = tmp4;
	free(tmp);
	free(tmp2);
	free(tmp3);
}

static void		ft_grab_2(char **s, int i, int j)
{
	t_mygv		*mygv;
	int			len;
	
	mygv = ft_get_mygv(NULL);
	ft_push_stack(&(mygv->grab), ft_new_stack(ft_strndup(&(*s)[i], j - i)));
	(*s)[i] = -50;
	len = ft_len_stack(mygv->grab);
	++i;
	ft_grab_3(s, i, j, len);
}

void			ft_grab(char **s, int i, int j)
{
	char		c;

	while ((*s)[i] && (*s)[i] != '"' && (*s)[i] != '\'')
		++i;
	if ((*s)[i])
	{
		c = (*s)[i];
		j = i + 1;
		while ((*s)[j] != c)
			++j;
		++j;
		ft_grab_2(s, i, j);
	}
	else
		return;
	if (j < ft_strlen(*s))
		ft_grab(s, 0, j);
}
