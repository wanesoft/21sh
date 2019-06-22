
#include "../include/twenty_one_sh.h"

static int		ft_check(int ans, int len)
{
	if (ans || len)
		return (1);
	return (0);
}

static int		ft_out(char **big, char **line, int ans, char ch)
{
	int			i;
	int			len;
	char		*tmp;
	char		*tmp1;
	
	if (!ans && !(*big))
		return (0);
	i = 0;
	while ((*big)[i] && (*big)[i] != ch)
		i++;
	*line = ft_strsub(*big, 0, i);
	len = (int)ft_strlen(*big);
	tmp1 = ft_strchr((*big), ch);
	tmp = (tmp1) ? ft_strdup(tmp1 + 1) : tmp1;
	free(*big);
	*big = tmp;
	return (ft_check(ans, len));
}

int				ft_gnl_pro(const int fd, char **line, char ch)
{
	static char	*big[1024];
	char		str[BUFF_SIZE + 1];
	char		*tmp;
	int			ans;
	
	if (!line || fd < 0 || BUFF_SIZE < 0)
		return (-1);
	while ((ans = (int)read(fd, str, BUFF_SIZE)) > 0)
	{
		str[ans] = '\0';
		if (!big[fd])
			if (!(big[fd] = ft_strnew(0)))
				return (-1);
		tmp = big[fd];
		big[fd] = ft_strjoin(big[fd], str);
		free(tmp);
		if (ft_strchr(str, ch))
			return (ft_out(&(big[fd]), line, ans, ch));
	}
	if (ans == -1)
		return (-1);
	return (ft_out(&big[fd], line, ans, ch));
}
