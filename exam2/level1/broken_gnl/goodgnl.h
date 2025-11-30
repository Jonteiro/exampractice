/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   goodgnl.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilveir <jsilveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 17:21:15 by abraz-ab          #+#    #+#             */
/*   Updated: 2025/11/20 15:11:04 by jsilveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL
# define GNL

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#define _GNU_SOURCE

char	*get_next_line(int fd);

#endif