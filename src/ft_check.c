/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 14:49:15 by tcohen            #+#    #+#             */
/*   Updated: 2024/09/01 15:17:59 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_check_argc(int argc)
{
	if (argc != 5)
	{
		ft_putstr_fd("Error Format need : ", 2);
		ft_putstr_fd("<inputfile> <cmd1> <cmd2> <outputfile>\n", 2);
		exit (0);
	}
}

int	ft_is_space(int c)
{
	if (c == 32)
		return (1);
	return (0);
}

int	ft_check_if_just_space(char *str)
{
	int	i;
	int	check;

	i = 0;
	check = 0;
	while (str[i])
	{
		check = ft_is_space((int)str[i]);
		if (check == 0)
			break ;
		i++;
	}
	return (check);
}

void	ft_check_argv(char *cmd, int fd[2])
{
	int	check_alpha;

	check_alpha = 0;
	if (cmd[0] == '\0')
	{
		ft_close_pipe(fd);
		exit(1);
	}
	check_alpha = ft_check_if_just_space(cmd);
	if (check_alpha == 1)
	{
		ft_close_pipe(fd);
		exit (1);
	}
}
