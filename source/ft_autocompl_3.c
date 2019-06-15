
#include "../include/twenty_one_sh.h"

void			ft_autocompl_3(char **arr, t_mygv *mygv, char *str, int len)
{
	int			i;
	int			fl;
	int			j;
	char		tmp;
	
	i = mygv->g_j;
	fl = 1;
	j = 0;
	while (fl && *arr)
	{
		tmp = arr[j][len];
		while (arr[j])
		{
			if (arr[j][len] != tmp)
			{
				fl = 0;
				break;
			}
			++j;
		}
		if (fl)
			ft_put_letter(tmp, mygv);
		++len;
		j = 0;
	}
}
