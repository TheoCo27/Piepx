/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_all.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 15:27:54 by tcohen            #+#    #+#             */
/*   Updated: 2024/08/29 17:35:24 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_close_pipe(int pipe_pointer[2])
{
	close(pipe_pointer[0]);
	close(pipe_pointer[1]);
}

void	ft_close_all(int pipe_pointer[2], int in_out_fd)
{
	ft_close_pipe(pipe_pointer);
	close(in_out_fd);
}

void	ft_wait_pids(int pid1, int pid2)
{
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}

int	ft_clean_info(t_info_exec *cmd)
{
	free(cmd->cmd);
	free(cmd->path);
	ft_free_all(cmd->arg);
	ft_free_all(cmd->t_path);
	return (0);
}
