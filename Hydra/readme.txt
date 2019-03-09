# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    readme.txt                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vokrut <vokrut@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/09 11:25:24 by vokrut            #+#    #+#              #
#    Updated: 2019/03/09 14:48:09 by vokrut           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

On Server site: 

1. Compile the server.c using <gcc server.c -o server>
2. Run server providing the port <./server 5000>, 
    where port number = 5000;

On Client site:

1. Compile the client.c using <gcc client.c -o client>
2. Run client providing IP & port number <./client 127.0.0.1 5000>,
    where IP = 127.0.0.1, port number = 5000
3. Enter message <ping>
4. Observe: you suppossed to get <pong pong> answer.