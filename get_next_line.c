/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oer-refa <oer-refa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 10:12:41 by oer-refa          #+#    #+#             */
/*   Updated: 2023/12/23 11:25:25 by oer-refa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_read_str (int fd, char *str){
    
    char *buff;
    int read_bt;
    buff = malloc ((BUFFER_SIZE + 1) * sizeof(char));
    if (!buff)
        return (NULL);
    read_bt = 1;
    
}
char    *get_next_line(int fd)
{
    char *buffer;
    static char *str;
    int read_bytes;
    read_bytes = read (fd, buffer, 0);  
    if (fd < 0 || BUFFR_SIZE <= 0 || read_bytes < 0)
        return (NULL);
    str = ft_read_str (fd, str);
    if (!str)
        return (NULL);
}