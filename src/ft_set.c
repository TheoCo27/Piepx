/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 15:04:24 by tcohen            #+#    #+#             */
/*   Updated: 2024/08/29 17:43:49 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_set_cmds(t_info_exec *c1, t_info_exec *c2, int *fd, char **env)
{
	c1->pipe_pointer[0] = fd[0];
	c1->pipe_pointer[1] = fd[1];
	c1->env = env;
	c2->pipe_pointer[0] = fd[0];
	c2->pipe_pointer[1] = fd[1];
	c2->env = env;
}

int	ft_execve_stuff(t_info_exec *info)
{
	info->path = ft_strdup(info->cmd);
	if (!info->path)
		return (ft_free_all(info->arg), 1);
	info->cmd = ft_strdup(info->cmd);
	if (!info->cmd)
		return (free(info->path), ft_free_all(info->arg), 1);
	info->t_path = ft_split(info->cmd, ' ');
	if (!info->t_path)
		return (free(info->cmd), free(info->path), ft_free_all(info->arg), 1);
	return (0);
}
