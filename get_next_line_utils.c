/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selkasba <selkasba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 22:09:57 by selkasba          #+#    #+#             */
/*   Updated: 2026/11/11 22:09:57 by selkasba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
size_t ft_strlen(char *s)
{
    char *p;
    p = s;

    while(*p)
        *p++;
    return (p - s );
}


char *ft_strchr(char *s, char c)
{
    if(!s)
        return (NULL);
    size_t i;

    i =0;
    while(s[i])
    {
        if(s[i] == c)
            return (&s[i]);
        i++;
    }
    return (NULL);
}


char *ft_strjoin(char *s1, char *s2)
{
    size_t len1;
    size_t len2;

    if(!s2)
        return (NULL);
    if (!s1)
        len1 = 0;
    else
        len1 = ft_strlen(s1);
    len2 = ft_strlen(s2);

    char *s = (char *)malloc(len1 + len2 + 1);
    if(!s)
        return (NULL);

    size_t i = 0;
    while(s1[i])
    {
        s[i] = s1[i];
        i++;
    }
    size_t j =0;
     while(s2[j])
    {
        s[i] = s2[j];
        i++;
        j++;
    }
    s[i] = '\0';
    return(s);



}

char *ft_strcpy(char *s1, char *s2)
{
    size_t  i;

    s2 = malloc(ft_strlen(s1) + 1);
    i = 0;
    while(s1[i])
    {
        s2[i] = s1[i];
        i++;
    }
    s2[i] = '\0';
    return (s2);
}
