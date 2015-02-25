/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcim <jalcim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 23:37:32 by jalcim            #+#    #+#             */
/*   Updated: 2014/03/25 22:03:04 by jalcim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _libft_
#define _libft_

#include <unistd.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_read t_read;

struct s_read
{
  char c;
  int size;
  t_read *next;
};

char **ft_strsplit(char const *s, char c);
char *ft_read_chain(int fd, char c);
char * ft_strcat (char * dest, const char *src);
char * ft_strncat (char * dest, const char *src, size_t size);
char * ft_strrcpy (char *dest, const char *src);
char * ft_strcpy (char *dest, const char *src);
char * ft_strrncpy (char *dest, const char *src, size_t size);
char * ft_strncpy (char *dest, const char *src, size_t size);
char * ft_strdup (const char *str);
char * ft_strstr (const char *s1, const char *s2);
char * ft_strnstr (const char *s1, const char *s2, size_t size);
char * ft_strchr (const char *src, int c);
char *ft_strnew(char *string);
char *ft_strsub(const char *s1, unsigned int start, size_t len);
char * ft_strjoin(char const *s1, char const *s2);
char * ft_strtrim(const char *s);
char * ft_itoa(int n);
char * ft_strmap(char const *s, char (*f)(char));
char * ft_strmapi(char const *s, char (*f)(unsigned int, char));
char * ft_itoa(int n);
unsigned int ft_bindec(char *bin);
char * ft_strrchr (const char *src, int c);

size_t ft_strlcat (char *dest, const char *src, size_t size);

int	ft_strlcar (char *str, int c);
int ft_strrlcar (char *buf, int c);
int	ft_strlen (const char *src);
int	ft_strcmp(const char *s1, const char *s2);
int	ft_strncmp(const char *s1, const char *s2, size_t size);
int	ft_strnequ(const char *s1, const char *s2, size_t n);
int	ft_strequ(const char *s1, const char *s2);
int	get_next_line (int fd, char **line);

int ft_atoi(const char *buf);
int ft_power(int nb, int power);
int ft_int_len(int nb);
int ft_isalnum (int c);
int ft_isalpha(int c);
int ft_isascii (int c);
int ft_isdigit(int c);
int ft_isprint(int c);
int ft_tolower(int c);
int ft_toupper(int c);
int ft_strequ(const char *s1, const char *s2);
int ft_strnequ(const char *s1, const char *s2, size_t n);
int ft_printf(const char *fmt, ...);
int ft_memcmp (const void *dest, const void *src, size_t size);

void * ft_memset (void *source, int rempl, size_t size);
void * ft_memcpy (void *dest, const void *src, size_t n);
void * ft_memccpy (void *dest, const void *src, int c, size_t size);
void * ft_memchr(const void *src, int c, size_t size);
void * ft_memmove (void *dest, const void *src, size_t size);
void * ft_memalloc(size_t size);
void *ft_realloc (void *replace, int size);

void ft_putnbr(int n);
void ft_putnbr_fd(int n, int fd);
void ft_striteri(char *s, void (*f)(unsigned int, char *));
void ft_striter(char *s, void (*f)(char *));
void ft_memdel(void **ap);
void ft_bzero (void *src, size_t size);
void ft_rbzero (void *src, size_t size);
void ft_strdel(char **as);
void ft_strclr(char *s);
void ft_putchar(char c);
void ft_putchar_fd(char c, int fd);
void ft_putstr(const char *s);
void ft_putstr_fd(const char *s, int fd);
void ft_putendl(const char *s);
void ft_putendl_fd(const char *s, int fd);
void ft_putbin(unsigned int origin);

#endif
