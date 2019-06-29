
#include "../include/twenty_one_sh.h"

static int		ft_add_to_str(char **s, int i, int n)
{
	char		*tmp;
	char		*tmp2;
	
	tmp = ft_strndup(*s, i);
	t_mygv *m = ft_get_mygv(NULL);
	t_stack *st = ft_imap_stack(m->grab, n);
	tmp2 = ft_strjoin(tmp, st->data);
	++i;
	while ((*s)[i] != -50)
		++i;
	++i;
	free(*s);
	*s = ft_strjoin(tmp2, &(*s)[i]);
	free(tmp);
	free(tmp2);
	return (i);
}

char			*ft_ungrab(char *s, int i)
{
	char		*ss;
	
	ss = ft_strdup(s);
	while (ss[i])
	{
		if (ss[i] == -50)
		{
			ft_add_to_str(&ss, i, ft_atoi(&s[i + 1]));
			ft_printf("KSAJDK _______________ %s\n", ss);
		}
		++i;
	}
	return (ss);
}
