/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh1.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nverdonc <nverdonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 01:26:04 by nverdonc          #+#    #+#             */
/*   Updated: 2015/01/21 15:45:14 by nverdonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SH1_H
# define FT_SH1_H
# include "Libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <dirent.h>
# include <signal.h>
# include <fcntl.h>
# define BUF_SIZE 10000

typedef struct s_env	t_env;

struct	s_env
{
	char	*elem;
	t_env	*next;
};

void	ft_sh1(char **env, int fd);
void	ft_sh_files(char **env, int  fd);
char	**ft_path(char **env);
int		ft_entry(char *command, t_env **lenv, char **path);
void	ft_command_cd(char *command, t_env *lenv);
int		ft_command_env(t_env *lenv);
int		ft_builtin(char *command, t_env **lenv);
t_env	*ft_list_env(char **env);
t_env	*ft_list_add_env(t_env *lenv, char *env);
void	ft_command_setenv(t_env *lenv, char *command);
int		ft_numberofav(char *command);
char	*ft_return_env(t_env *lenv, char *var);
void	ft_command_unsetenv(t_env **lenv, char **command, int ac);
void	ft_pwd_change(char *newpwd, t_env *lenv);
int		ft_isspace(int c);
char	*ft_oldpwd_cd(t_env *env);
int		ft_bin(char *command, char **path, t_env *lenv);
char	**ft_recreate_env(t_env *env);
int		ft_treat(char *commande, t_env **lenv, char **path);
void	ft_putps1(char *ps1, t_env *lenv);
void	ft_signal();

/*
** Error
*/

void	ft_error(char *command, int error);

/*
** Exec
*/

void	endprocess(pid_t pid);
void	ft_exec(char *path, char *name, char *command, t_env *lenv);
void	ft_basic_process(char *command, t_env *lenv);
int		isexec(char *path);

/*
** Read file
*/

int		ft_treat_file(char *files, char **env);

#endif
