/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 16:44:50 by tcohen            #+#    #+#             */
/*   Updated: 2024/08/29 17:34:40 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_exit(int fork_nb, int pid1, int fd[2])
{
	if (fork_nb == 0)
	{
		ft_close_pipe(fd);
		perror("fork pid[0] failed");
		exit(1);
	}
	if (fork_nb == 1)
	{
		ft_close_pipe(fd);
		perror("fork pid[1] failed");
		waitpid(pid1, NULL, 0);
		exit(2);
	}
}

int	main(int argc, char **argv, char **env)
{
	t_info_exec	cmd[2];
	int			fd[2];
	int			pid[2];

	ft_check_argc(argc);
	ft_pipe(fd);
	ft_set_cmds(&cmd[0], &cmd[1], fd, env);
	pid[0] = fork();
	if (pid[0] < 0)
		ft_exit(0, pid[0], fd);
	if (pid[0] == 0)
		ft_first_child(argv, env, fd, &cmd[0]);
	pid[1] = fork();
	if (pid[1] < 0)
		ft_exit(1, pid[0], fd);
	if (pid[1] == 0)
		ft_2nd_child(argv, env, fd, &cmd[1]);
	ft_close_pipe(fd);
	ft_wait_pids(pid[0], pid[1]);
	return (0);
}
