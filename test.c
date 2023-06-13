/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafranco <mafranco@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:12:01 by mafranco          #+#    #+#             */
/*   Updated: 2023/06/06 15:12:01 by mafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libftprintf.h"

int testc()
{
    char    tab[10] = {'\0', 'c', '9', '^', 'X', ')', '@', '\n', '\t', ' '};
    int i;

    i = 0;
    while (i < 10)
    {
        if (ft_printf("%c", tab[i]) != printf("%c", tab[i]))
        {
            printf("\nprobleme : %c\n", tab[i]);
            ft_printf("ft_printf : %c", tab[i]);
            printf("printf : %c", tab[i]);
            return (1);
        }
        i++;
    }
    return (0);
}

int tests()
{
    char    *tab[8] = {"Bonjour", "\nhey", "\0", "   +-&\"()\"", NULL, "132445678", "??????????????", "Bonjour je suis mathis j'ai 21 ans et je fais l'ecole 42 oui voila"};
    int i;

    i = 0;
    while (i < 8)
    {
        if (ft_printf("%s", tab[i]) != printf("%s", tab[i]))
        {
            printf("\nprobleme : %s\n", tab[i]);
            ft_printf("ft_printf : %s", tab[i]);
            printf("printf : %s", tab[i]);
            return (1);
        }
        i++;
    }
    return (0);
}


int testd()
{
    int    tab[10] = {0x42, -+123, 0123, 123456789, 2147483647, -2147483648, -0, 0, -78, 78};
    int i;

    i = 0;
    while (i < 10)
    {
        if (ft_printf("%d", tab[i]) != printf("%d", tab[i]))
        {
            printf("\nprobleme : %d\n", tab[i]);
            ft_printf("ft_printf : %d", tab[i]);
            printf("printf : %d", tab[i]);
            return (1);
        }
        i++;
    }
    return (0);
}

int testi()
{
    int    tab[10] = {0x42, -+123, 0123, 0x522775E, 2147483647, -2147483648, -0, 0, -0x456, 78};
    int i;

    i = 0;
    while (i < 10)
    {
        if (ft_printf("%i", tab[i]) != printf("%i", tab[i]))
        {
            printf("\nprobleme : %i\n", tab[i]);
            ft_printf("ft_printf : %i", tab[i]);
            printf("printf : %i", tab[i]);
            return (1);
        }
        i++;
    }
    return (0);
}

int testu()
{
    int    tab[10] = {0x42, -+123, 0123, 0x522775E, 2147483647, -2147483648, -0, 0, -0x456, 78};
    int i;

    i = 0;
    while (i < 10)
    {
        if (ft_printf("%u", tab[i]) != printf("%u", tab[i]))
        {
            printf("\nprobleme : %u\n", tab[i]);
            ft_printf("ft_printf : %u", tab[i]);
            printf("printf : %u", tab[i]);
            return (1);
        }
        i++;
    }
    return (0);
}

int testx()
{
    int    tab[10] = {0x42, -+123, 0123, 0x522775E, 2147483647, -2147483648, -0, 0, -0x456, 78};
    int i;

    i = 0;
    while (i < 10)
    {
        if (ft_printf("%x", tab[i]) != printf("%x", tab[i]))
        {
            printf("\nprobleme : %x\n", tab[i]);
            ft_printf("ft_printf : %x", tab[i]);
            printf("printf : %x", tab[i]);
            return (1);
        }
        i++;
    }
    return (0);
}

int testX()
{
    int    tab[10] = {0x42, -+123, 0123, 0x522775E, 2147483647, -2147483648, -0, 0, -0x456, 78};
    int i;

    i = 0;
    while (i < 10)
    {
        if (ft_printf("%X", tab[i]) != printf("%X", tab[i]))
        {
            printf("\nprobleme : %X\n", tab[i]);
            ft_printf("ft_printf : %X", tab[i]);
            printf("printf : %X", tab[i]);
            return (1);
        }
        i++;
    }
    return (0);
}

int testp()
{
    int q;
    int j;
    char k;
    char l;
    unsigned long long m;
    char *s = {"salut"};
    double n;

    int *a;
    int *b;
    char *c;
    char *d;
    unsigned long long *e;
    char *f;
    double *g;

    a = &q;
    b = &j;
    c = &k;
    d = &l;
    e = &m;
    f = &s[0];
    g = &n;
    if (ft_printf("%p", a) != printf("%p", a))
    {
        printf("\nprobleme : %p\n", a);
        ft_printf("ft_printf : %p", a);
        printf("printf : %p", a);
        return (1);
    }
    if (ft_printf("%p", b) != printf("%p", b))
    {
        printf("\nprobleme : %p\n", b);
        ft_printf("ft_printf : %p", b);
        printf("printf : %p", b);
        return (1);
    }
    if (ft_printf("%p", c) != printf("%p", c))
    {
        printf("\nprobleme : %p\n", c);
        ft_printf("ft_printf : %p", c);
        printf("printf : %p", c);
        return (1);
    }
    if (ft_printf("%p", d) != printf("%p", d))
    {
        printf("\nprobleme : %p\n", d);
        ft_printf("ft_printf : %p", d);
        printf("printf : %p", d);
        return (1);
    }
    if (ft_printf("%p", e) != printf("%p", e))
    {
        printf("\nprobleme : %p\n", e);
        ft_printf("ft_printf : %p", e);
        printf("printf : %p", e);
        return (1);
    }
    if (ft_printf("%p", f) != printf("%p", f))
    {
        printf("\nprobleme : %p\n", f);
        ft_printf("ft_printf : %p", f);
        printf("printf : %p", f);
        return (1);
    }
    if (ft_printf("%p", g) != printf("%p", g))
    {
        printf("\nprobleme : %p\n", g);
        ft_printf("ft_printf : %p", g);
        printf("printf : %p", g);
        return (1);
    }
    if (ft_printf("%p", NULL) != printf("%p", NULL))
    {
        printf("\nprobleme : %p\n", NULL);
        ft_printf("ft_printf : %p", NULL);
        printf("printf : %p", NULL);
        return (1);
    }
    return (0);
}
/*
int testp()
{
    char *s;
    char *p;

    p = &s[0];
    ft_printf("%p\n", p);
    printf("%p\n", p);
    return (0);
}*/

int main(void)
{
    int tot;
    
    tot = testc();
    tot += tests();
    tot += testd();
    tot += testi();
    tot += testu();
    tot += testx();
    tot += testX();
    tot += testp();
    ft_printf("\n\nTOTAL D'ERREURS : %d\n", tot);
    //int i;
    //int j;
    /*unsigned long long e;

    e = 1234567892123;*/
    //int *p;

    //p = &j;
    /*i = ft_printf(" %X", e);
    j = printf(" %X", e);*/
    /*i = ft_printf("Salut : %c : %s : %d : %i : %u : %x : %X : %p : %%\n", 49, "quarente-neuf", 49, 0x12e, -490, 15456, 120450, p);
    j = printf("Salut : %c : %s : %d : %i : %u : %x : %X : %p : %%\n", 49, "quarente-neuf", 49, 0x12e, -490, 15456, 120450, p);
    printf("i : %d, j : %d\n", i, j);*/
    /*i = ft_printf("%p\n", p);
    j = printf("%p\n", p);*/
    //printf("i = %d, j = %d\n", i, j);
    return (0);
}