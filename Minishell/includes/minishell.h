/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmaata <wasmaata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:39:16 by enzgonca          #+#    #+#             */
/*   Updated: 2025/07/02 04:58:24 by wasmaata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <fcntl.h>

typedef struct s_token
{
	char			*cmd;
	char			*flags;
	char			*params;
	char			*str;
	struct s_token	*next;
}	t_token;

typedef struct s_index
{
	int		cntpipe;
	int		cnttab;
	int		count;
	int		i;
	int		j;
	int		k;
	int		l;
	int		len;
	int		flag;
	int		stdin;
	int		stdout;
	int		saved_stdin;
	int		saved_stdout;
	long	exit_status;
	char	*pwd;
	char	*readline;
	char	*input;
	char	**tab;
	char	**env;
}	t_index;

//sig
int		ft_ctrld(char *input, t_index *index, t_token *vars);
void	handle_sigint(int sig);
void	handle_sigquit(int sig);
// free
void	ft_free_tokens(t_token *head);
void	ft_freetab(char **tab);
// src -> checker.c
void	ft_checker(t_token *vars, t_index *index);
int		ft_countdblquote(char *input, char c);
int		ft_strqlen(char *str, int i);
int		ft_pipechecker(t_token *vars, t_index *index);
// src -> checker2.c
int		ispipe(t_index *index, char *input);
t_token	*ft_cutpipe(t_token **vars, t_index *index, t_token *head);
// src -> checker3.c
void	*ft_realloc(void *ptr, size_t old_size, size_t new_size);
int		unclosedquote(char *str);
void	wassimo(t_index *index, char *target, int len, char **tab);
void	ft_inshallah(char **tab, t_index *index);
// utils
char	**ft_split(char const *s, char c);
int		ft_tablen(char **split);
char	*get_pwd(int ac);
void	get_env(char **env, int ac);
int		ft_strcmp(const char *first, const char *second);
int		ft_lastq(char *str, char c);
int		ischar(char *str, int i, char c);
int		env_set(char *key, char *value, char ***env);
char	*env_get(char *key, char **env);
int		isaplha(char *str);
char	**copy_env(char	**envc, char **env);
char	**calloc_env(char **env);
void	setup_child_redirections(t_index *index, int *fd);
pid_t	create_pipe_and_fork(t_index *index, int *fd);
void	wait_all_children(pid_t *pids, int count);
void	launch_child_process(t_token *vars, t_index *index,
			int in_fd, int out_fd);
int		alphastrlen(char *str, int i);
int		get_env_size(char **env);

// exec
void	ft_selectform(t_index *index, int ac);
void	cd_case(char **tab, int ac, char **env);
int		ch_dir(char	*path);
void	echo_case(char **tab);
void	export_case(char **tab, int ac, char ***env);
void	env_unset_case(char **tab, int ac, char ***env);
int		imp_exec(char **tab, char **env);
int		pwd_case(int ac);
void	exit_case(char **tab, int ac, t_index *index);
// ft_quoter
void	isexpand(char **tab, char *str, t_index *index);
char	**ft_quoter(char *str, t_index *index);
char	**ft_cutquoter(char **tab, char *str, t_index *index);
// hd.c
void	ft_hdmaker(char *str, int i, char c, t_index *index);
char	*ft_cleaninput(char *src, char *dest);
// redir
void	cleanup_tab(char **tab, int pos);
int		here_document(const char *delimiter);
int		handle_redirections(char **tab);
int		ft_pipeok(char *str);
int		handle_output_redirection(char **tab, int *fd_out, int i);
int		handle_append_redirection(char **tab, int *fd_out, int i);
int		handle_input_redirection(char **tab, int *fd_in, int i);
int		handle_heredoc_redirection(char **tab, int *fd_heredoc, int i);
int		apply_redirections(int fd_in, int fd_out, int fd_heredoc);
// redirmaker
int		ft_cwordredir(char *str);
int		ft_strlenredirec(char *str, int i, t_index *index);
