/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utf_32_8.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 20:59:54 by mburson           #+#    #+#             */
/*   Updated: 2017/01/19 20:59:56 by mburson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>
#include <libft.h>
#include <string.h>
#include <stdlib.h>

#include <stdio.h>

static unsigned char     format_trailing(unsigned char c)
{
    return ((c & 0b00111111) | 0b10000000);
}

static unsigned char     format_first(unsigned char c, int length)
{
    return ((0b11110000 << (4 - length)) | c);
}

static char                get_length(wint_t c)
{
    if ((0xFFFFFFFF << 7) & c)
        return (1);
    if ((0xFFFFFFFF << 11) & c)
        return (2);
    if ((0xFFFFFFFF << 16) & c)
        return (3);
    if ((0xFFFFFFFF << 21) & c)
        return (4);
    return (0);
}

unsigned char    *ft_utf_32_8(wint_t c)
{
    unsigned char   *res;
    int             len;

    if (!(len = get_length(c)))
        return (NULL);
    printf("length: %d\n", len);
    if (!(res = (unsigned char*)malloc(sizeof(char) * (len + 1))))
        return (NULL);
    res[len] = '\0';
    if (len == 1)
    {
        res[0] = (unsigned char)c;
        return (res);
    }
    while (len)
    {
        len--;
        res[len] = (unsigned char)c;
        if (len)
            res[len] = format_trailing(res[len]);
        else
            res[len] = format_first(res[len], len);
    }
    return (res);
}
