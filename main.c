/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selkasba <selkasba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 20:33:42 by selkasba          #+#    #+#             */
/*   Updated: 2026/11/14 20:05:02 by selkasba         ###   ########.fr       */
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
    char    *line;

    fd = open("test.txt", O_RDONLY);
    if (fd == -1)
        return (1);
    line = get_next_line(fd);
    while(line)
    {
    printf("%s", line);
    free(line);
    line = get_next_line(fd);
    }
    line = get_next_line(fd);
    while (line)
    {
        line = get_next_line(fd);
        printf("%s", line);
        free(line);
        
    }
    line = get_next_line(fd);
    if (line == NULL)
        printf("\nOK : nouvel appel après la fin du fichier\n");
    else
    {
         printf("\nErreur : ligne inattendue [%s]\n", line);
        free(line);
    }
    close(fd);
    return (0);


}