/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 16:51:13 by tcohen            #+#    #+#             */
/*   Updated: 2024/09/01 15:17:05 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <sys/wait.h>

typedef struct s_info_exec
{
	char	*cmd;
	char	*path;
	char	**t_path;
	char	**arg;
	int		pipe_pointer[2];
	int		in_out_fd;
	char	**env;
}			t_info_exec;

//ft_child.c
int		ft_cmd_arg(char *cmd, t_info_exec *info);
void	ft_cmd1(t_info_exec *cmd, int fd[2]);
void	ft_cmd2(t_info_exec *cmd, int fd[2]);
int		ft_first_child(char **argv, char **env, int fd[2], t_info_exec *cmd);
int		ft_2nd_child(char **argv, char **env, int fd[2], t_info_exec *cmd);
//ft_path.c
int		ft_getenv_path(char **env, t_info_exec *info);
int		ft_check_ifpath(t_info_exec *info);
int		ft_find_cmd(t_info_exec *info);
int		ft_path(char **env, t_info_exec *info);

//ft_secure.c
int		ft_open(char *file_name, char mode, t_info_exec *info);
int		ft_dup2(int old_fd, int new_fd);
int		ft_execve(t_info_exec *cmd);
int		ft_pipe(int fd[2]);
// ft_all.c
void	ft_close_pipe(int pipe_pointer[2]);
void	ft_close_all(int pipe_pointer[2], int in_out_fd);
void	ft_wait_pids(int pid1, int pid2);
int		ft_clean_info(t_info_exec *cmd);
//ft_check.c
void	ft_check_argc(int argc);
void	ft_check_argv(char *cmd, int fd[2]);
int		ft_is_space(int c);
int		ft_check_if_just_space(char *str);
//ft_set.c
void	ft_set_cmds(t_info_exec *c1, t_info_exec *c2, int *fd, char **env);
int		ft_execve_stuff(t_info_exec *info);

#endif
