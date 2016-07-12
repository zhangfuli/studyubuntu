#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

int main()
{
   
   int recv_sockfd;
   struct sockaddr_in  recv_address;
   int res;
   int len;
   struct sockaddr_in remote_address;
   char buffer[20];

   recv_address.sin_family = AF_INET;
   recv_address.sin_addr.s_addr = htonl(INADDR_ANY);
   recv_address.sin_port = htons(9734);
 
   if ((recv_sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
   {
        perror("socket");
        exit(EXIT_FAILURE);
   }
   if (bind(recv_sockfd, (struct sockaddr *) &recv_address, sizeof(struct sockaddr)) < 0 )
   {
        perror("bind");
        exit(EXIT_FAILURE);
   }
 
   while(1)
   {
        len = sizeof(remote_address);
        if ((res = recvfrom(recv_sockfd, buffer , 20, 0, 
                               (struct sockaddr *)&remote_address, &len)) < 0)
        {
             perror("recvfrom");
             exit(EXIT_FAILURE);
        }
        printf("%s\n",buffer);
    }
    close(recv_sockfd);
} 

