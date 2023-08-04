/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoussa <ramoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 19:08:56 by ramoussa          #+#    #+#             */
/*   Updated: 2023/08/04 05:20:54 by ramoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_strlen(const char *c);
int				ft_toupper(int c);
int				ft_tolower(int c);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
int				ft_strncmp(const char *s1, const char *s2, unsigned int n);
void			*ft_memset(void *b, int c, unsigned int len);
void			ft_bzero(void *s, unsigned int n);
void			*ft_memcpy(void *dst, const void *src, unsigned int n);
void			*ft_memmove(void *dst, const void *src, unsigned int len);
unsigned int	ft_strlcpy(char *dst, const char *src, unsigned int dstsize);
unsigned int	ft_strlcat(char *dst, const char *src, unsigned int dstsize);
void			*ft_memchr(const void *s, int c, unsigned int n);
int				ft_memcmp(const void *s1, const void *s2, unsigned int n);
char			*ft_strnstr(
					const char *haystack,
					const char *needle,
					unsigned int len
					);
int				ft_atoi(const char *str);
void			*ft_calloc(unsigned int count, unsigned int size);
char			*ft_strdup(const char *s1);
char			*ft_substr(const char *s, unsigned int start, unsigned int len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *s, char c);
char			*ft_itoa(int n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **lst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(
					t_list *lst,
					void *(*f)(void *),
					void (*del)(void *)
					);

/**
 * Writes a signed integer to the specified file descriptor.
 *
 * This function takes a signed integer `n` and writes its textual representation
 * to the given file descriptor `fd`. The function handles both positive and
 * negative integers, including the special case of the most negative value
 * (-2147483648). The function returns the number of characters written to the
 * file descriptor on success, or -1 on failure.
 *
 * Note: This function is used for writing integers to a file descriptor and
 * does not add a newline or any other separators after the number.
 *
 * @param n The signed integer to be written.
 * @param fd The file descriptor where the integer will be written.
 * @return The number of characters written on success, or -1 on failure.
 */
int				put_int(int n, int fd);

/**
 * Writes a double-precision floating-point number to specified file descriptor.
 *
 * This function takes a double-precision floating-point number `num` and writes
 * its textual representation to the given file descriptor `fd`. The `percision`
 * parameter specifies the number of decimal places to be displayed for the
 * fractional part of the number. The function returns the number of characters
 * written to the file descriptor on success.
 *
 * The function internally converts the double value into its integer and
 * fractional parts and uses the `put_int` function to write the integer part to
 * the file descriptor. If the `percision` value is greater than zero, it writes
 * the fractional part by multiplying the remaining decimal values with 10 and
 * repeatedly calling `put_int` to write each digit to the file descriptor.
 *
 * @param fd The file descriptor where the double will be written.
 * @param num The double-precision floating-point number to be written.
 * @param percision The number of decimal places for the fractional part.
 * @return The number of characters written to the file descriptor on success.
 */
int				put_double(int fd, double num, u_int8_t percision);

#endif
