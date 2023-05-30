/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafranco <mafranco@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 21:14:12 by mafranco          #+#    #+#             */
/*   Updated: 2023/05/29 21:14:12 by mafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

size_t ft_strlen(const char *s)
{
    int i;

    i = 0;
    while (s[i] != '\0')
        i++;
    return (i);
}

char    *ft_strdup(const char *s)
{
    char       *ptr;
    size_t     i;

    if (!s)
        return(NULL);
    i = 0;
    ptr = (char*)malloc((ft_strlen(s) + 1)*sizeof(s));
    if (!ptr)
        return(NULL);
    while (s[i])
    {
        ptr[i] = s[i];
        i++;
    }
    ptr[i] = 0;
    return(ptr);
}

int    pfputchar(int c)
{
    write(1, &c, 1);
    return(1);
}

size_t  pfstrlen(char *s)
{
    size_t  i;

    i = 0;
    while (s[i])
        i++;
    return (i);
}

int    pfputstr(char *s)
{
    int i;

    i = 0;
    if (!s)
        pfputstr("(null)");
    while (s[i])
    {
        write(1, &s[i], 1);
        i++;
    }
    return(i);
}

int pfputnbr(int nbr, int i)
{
    if (nbr == -2147483648)
    {
        char    *s;
        s = "-2147483648";
        return(pfputstr(s));
    }
    if (nbr < 0)
    {
        pfputchar('-');
        i += pfputnbr((nbr * -1), i) + 1;
    }
    else if (nbr > 9)
    {
        i += pfputnbr((nbr / 10), i);
        i += pfputchar((nbr % 10) + 48);
    }
    else
        i += pfputchar(nbr + 48);
    return(i);
}

int pfputhexa(unsigned int nbr, char *s, int i)
{
    if (nbr > 15)
    {
        pfputhexa(nbr / 16, s, i);
        i += pfputchar(s[(nbr % 16)]);
    }
    else
        i += pfputchar(s[(nbr % 16)]);
    return(i);
}

int pfputunsin(unsigned int nbr, char c)
{
    int i;

    i = 0;
    if (c == 'u')
        i += pfputnbr(nbr, 0);
    else if (c == 'x')
        i += pfputhexa(nbr, "0123456789abcdef", 0);
    else if (c == 'X')
        i += pfputhexa(nbr, "0123456789ABCDEF", 0);
    return(i);
}

int pfputcdi(int nb, char c)
{
    int i;

    if (c == 'c')
        i = pfputchar(nb);
    else if (c == 'd')
        i = pfputnbr(nb, 0);
    else if (c == 'i')
        i = pfputnbr(nb, 0);
    return(i);
}

int pfputptr(unsigned long long ptr)
{
    int i;

    i = pfputstr("0x");
    i += pfputhexa(ptr, "0123456789abcdef", 0);
    return(i);
}

int parcourir(char *str, int i)
{
    int count;

    count = 0;
    while (str[i])
    {
        if (str[i] != '%')
            count += pfputchar(str[i]);
        else
            return(count + 1);
        i++;
    }
    return(count);
}

int debut(va_list args, char *str, int i)
{
    int count;

    count = 0;
    while (str[i])
    {
        count -= i;
        i += parcourir(str, i);
        count += i;
        if (str[i] == '%')
            count += pfputchar('%');
        else if (str[i] == 's')
            count += pfputstr(va_arg(args, char *));
        else if (str[i] == 'd' || str[i] == 'i' || str[i] == 'c')
            count += pfputcdi(va_arg(args, int), str[i]);
        else if (str[i] == 'u' || str[i] == 'x' || str[i] == 'X')
            count += pfputunsin(va_arg(args, unsigned int), str[i]);
        else if (str[i] == 'p')
            count += pfputptr(va_arg(args, unsigned long long));
        i++;
    }
    return(count);
}

int ft_printf(const char *str, ...)
{
    va_list list;
    int count;
    char    *t;

    t = ft_strdup(str);
    va_start(list, str);
    count = debut(list, t, 0);
    va_end(list);
    free(t);
    return(count);
}

int main()
{
    int i;

    i = ft_printf("123%%%d%c\n", 123, 'C');
    printf("%d\n", i);
    return(0);
}