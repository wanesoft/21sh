
#include "../include/twenty_one_sh.h"

static int			ft_count_files(void)
{
	DIR				*d1;
	struct dirent	*f1;
	int				count;
	
	count = 0;
	d1 = opendir(".");
	while ((f1 = readdir(d1)))
		++count;
	closedir(d1);
	return (count);
}

char				**ft_autocompl_dir(void)
{
	DIR				*d1;
	char			**arr;
	struct dirent	*f1;
	int				i;
	
	i = 0;
	arr = (char **)malloc(sizeof (char *) * (ft_count_files() + 1));
	arr[ft_count_files()] = NULL;
	d1 = opendir(".");
	while ((f1 = readdir(d1)))
	{
		arr[i] = ft_strdup(f1->d_name);
		++i;
	}
	closedir(d1);
	return (arr);
}
