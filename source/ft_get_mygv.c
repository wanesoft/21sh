
#include "../include/minishell.h"

t_mygv					*ft_get_mygv(t_mygv *mygv)
{
	static t_mygv		*mygv_here;
	
	if (mygv == NULL)
		return (mygv_here);
	else
		mygv_here = mygv;
	return (0);
}
