/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selkasba <selkasba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 20:33:42 by selkasba          #+#    #+#             */
/*   Updated: 2026/11/23 19:57:22 by selkasba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

char *ft_strstr(char *s, char *f)
{
    int j;
    int i;

    i = 0;
    while(s[i])
    {
        j = 0;
        while(s[j] && s[i+j]==f[j])
        {
            j++;
            if (f[j] == '\0' )
                return(&s[i]);
            
        }
        i++;
        
    }
    return(NULL);
}

int main(void)
{
    int     fd;
    int     fd2;
    char    *line;

    

    // fd = open("text.txt", O_APPEND);
    // fd2 = open("test2.txt", O_RDONLY);
    // if (fd == -1 || fd2 == -1)
    //     return (1);
    // int fd3= open("test.txt", O_RDWR);
    // write(fd, "\ndima raja", 9);


    
    int id =getpid();
    printf("%d\n", id);
    // line = get_next_line(fd);
    // // line = get_next_line(fd2);
    // while(line)
    // {
    //     // if(ft_strstr(line,"ra"))
    //         printf("%s", line);
    //     free(line);
    //     line = get_next_line(fd);
    //     // printf("%s", line);
    //     // free(line);
    //     // line = get_next_line(fd2);
        
    // }
    // line = get_next_line(fd);
	// printf("%s",line);
    // free(line);
    // line = get_next_line(fd);
	// printf("%s",line);
    // free(line);

    // close(fd);
    // // close(fd2);
    // return (0);

   

}

