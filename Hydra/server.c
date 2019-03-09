/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vokrut <vokrut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 22:34:17 by vokrut            #+#    #+#             */
/*   Updated: 2019/03/09 14:31:52 by vokrut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int ac, char **av)
{
    int                 sock;
    int                 bytes_read;
    int                 sock_accept;
    char                buf[256];
    struct sockaddr_in  addr;
    socklen_t           addr_size;

    if (ac != 2)
    {
        printf("Port number has not been provided\n!");
        return (0);
    }
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0)
    {
        printf("Could not create a socket\n");
        return (0);
    }
    printf("Socket has been successfully created\n");
    memset(&addr, '0', sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.sin_port = htons(atoi(av[1]));
    if (bind(sock, (struct sockaddr*)&addr, sizeof(addr)))
    {
        printf("Failed to bind\n");
        return (0);
    }
    printf("Socket has been successfully bound\n");
    
    if (listen (sock, 5) == -1)
    {
        printf("Failed to lesten");
        return (0);
    }
    printf("Listeting...\n");
    //pid_t pid = Demonize();
    printf("Server ready to connect...\n");
    while (1)
    {
        addr_size = sizeof(addr);
        sock_accept = accept(sock, (struct sockaddr*)&addr, &addr_size);
        if (sock_accept < 0)
        {
            printf("Error to accept\n");
            return (0);
        }
        else
        {
            bytes_read = recv(sock_accept, buf, 255, 0);
            if (bytes_read <= 0)
                break ;
            buf[bytes_read] = '\0';
            if (!strncmp(buf, "ping", 4))
                send(sock_accept, "pong pong\n", 10, 0);
        }
        close(sock_accept);
    }
    return (0);
}