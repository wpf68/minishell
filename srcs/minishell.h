/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 17:25:50 by pwolff            #+#    #+#             */
/*   Updated: 2022/07/04 11:31:52 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define SIZE_PROMPT 2096
/*# define COLOR(val) printf("\033[%sm", val)
 * 30 NOIR
 * 31 ROUGE
 * 32 VERT
 * 33 JAUNE
 * 34 BLEU
 * 35 MAGENTA
 * 36 CYAN
 * 37 BLANC
 * + 10 : fonds
 * 1 haute intensité
 * 7 video inversé
 */

# include "../libft_total/libft.h"

/* readline  */
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
/* malloc   */
# include <stdlib.h>
/* write - read - access - fork - getcwd - chdir - execve - dup */
# include <unistd.h>
/* fork - wait */
# include <sys/types.h>
/* wait - wait3 - wait4 */
# include <sys/wait.h>
# include <sys/times.h>
# include <sys/resource.h>
/* signal */
# include <signal.h>
/* stat */
//# include <stat.h>
/* unlink - dup */
# include <fcntl.h>
/* opendir */
# include <dirent.h>
/* strerror */
# include <string.h>
/* perror */
# include <errno.h>
/* ioctl */
# include <sys/ioctl.h>
/* tcsetattr */
# include <termios.h>
/* tgetent t.. */
# include <curses.h>
# include <term.h>

typedef struct s_sig
{
	pid_t	child;
	int		status;
}	t_sig;

t_sig	g_signale;

typedef struct s_setting
{
	int		on_off;	
	char	*path_prompt;
	char	path_begin[SIZE_PROMPT];
	char	path_end[SIZE_PROMPT];
	char	*command;
	char	*command_arrow;
	char	**cmd_shell;
	int		nb_command;
	char	**comd_arg[SIZE_PROMPT];
	char	*path_env;
	int		pdes[2];
	int		in;
	char	**var_envp;
	char	path_cd[SIZE_PROMPT];
	char	prompt[SIZE_PROMPT];
	char	name_export[SIZE_PROMPT];
	char	arg_export[SIZE_PROMPT];
	int		redirect;
	char	*name_redirect;
	int		fd;
	int		error_quote;
	int		double_arrow;
	int		debug;
	char	**split;
	size_t	q;
	size_t	dq;
	size_t	j;
	int		index;
	char	temp[SIZE_PROMPT];
	char	*var;
	int		k;
	int		l;
	int		color;
	int		sort_env[1024];
}	t_setting;

char	**ft_split_quote(t_setting *set, char const *s, char c);

int		ft_error(char *str, int nb);
int		ft_name_minishell(t_setting *set);
void	ft_init(t_setting *set, char **envp);
void	ft_search_prompt(t_setting *set);
int		ft_split_shell(t_setting *set);
void	ft_signal(int signal);
int		ft_command(t_setting *set);
void	ft_split_prompt(t_setting *set);

void	ft_test_quote_dquote(t_setting *set);
void	ft_free(t_setting *set);
void	ft_free_env(t_setting *set);
void	ft_free_split(char **split);
char	*ft_path_cmd(t_setting *set, int i);
int		ft_test_command(t_setting *set, int i);
int		ft_test_builtins(t_setting *set, int i);
int		ft_run_builtins(t_setting *set, int i);
int		ft_redirect(t_setting *set, int j);
int		ft_redirect_in(t_setting *set, int j);

void	ft_double_arrow(t_setting *set, int j);

void	ft_child(t_setting *set, int j);
void	ft_parent(t_setting *set, int j);
void	ft_run_command(t_setting *set);
void	ft_exec_cmd(t_setting *set, int i);
char	*ft_look_for_var(t_setting *set, char *str);
void	ft_interpreter_quotes(t_setting *set);

void	ft_rm_heredoc(void);
void	ft_rm_debug(void);
void	ft_create_var_error(t_setting *set);
void	ft_echo(t_setting *set, int i);
void	ft_exit(t_setting *set, int i);
void	ft_export(t_setting *set, int i);
void	ft_export2(t_setting *set, int j, char *str);
void	ft_cd(t_setting *set, int i);
void	ft_unset(t_setting *set, int i);
void	ft_envp(t_setting *set);
void	ft_envp_export_empty(t_setting *set);
void	ft_pwd(t_setting *set);
void	ft_verif_cmds(t_setting *set);
void	ft_presentation(void);
void	if_no_quote(t_setting *set, int i, int j, char *new_var);

#endif
