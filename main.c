/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selkasba <selkasba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 20:33:42 by selkasba          #+#    #+#             */
/*   Updated: 2026/11/14 23:02:10 by selkasba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    int     fd;
    int     fd2;
    char    *line;

    fd = open("test.txt", O_RDONLY);
    fd2 = open("test2.txt", O_RDONLY);
    if (fd == -1 || fd2 == -1)
        return (1);
    line = get_next_line(fd);
    line = get_next_line(fd2);
    while(line)
    {
        printf("%s", line);
        free(line);
        line = get_next_line(fd);
        printf("%s", line);
        free(line);
        line = get_next_line(fd2);
        
    }

    close(fd);
    close(fd2);
    return (0);


}