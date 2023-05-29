/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafranco <mafranco@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 02:36:50 by mafranco          #+#    #+#             */
/*   Updated: 2023/05/26 02:36:50 by mafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int imprimechar(char c)
{
    write(1, &c, 1);
    return(1);
}

int imprimeint(int nb, int i)
{
    if (nb == -2147483648)
    {
        imprimechar('-');
        imprimechar('2');
        imprimechar('1');
        imprimechar('4');
        imprimechar('7');
        imprimechar('4');
        imprimechar('8');
        imprimechar('3');
        imprimechar('6');
        imprimechar('4');
        imprimechar('8');
        return(11);
    }
    else if (nb < 0)
    {
        imprimechar('-');
        imprimeint(nb * -1, i + 1);
    }
    else if (nb > 9)
    {
        imprimeint(nb / 10, i + 1);
        imprimechar((nb % 10) + 48);
    }
    else
        imprimechar(nb + 48);
    i++;
    return(i);
}

int where(va_list list, char c)
{
    int i;

    i = 0;
    if (c == 'c')
        i += imprimechar(va_arg(list, int));
    if (c == 'd')
        i += imprimeint(va_arg(list, int), 0);
    return(i);
}

int imprimef(const char *s, ...)
{
    va_list list;
    int     i;

    va_start(list, s);
    i = 0 ;
    while (s[i])
    {
        where(list, s[i]);
        i++;
    }
    va_end(list);
    return(i);
}

int main()
{
    imprimef("cd", 'X', 123456);
    return(0);
}