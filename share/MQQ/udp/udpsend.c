# include <stdio.h>
# include <stdlib.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

int main(int argc, char *argv[])
{
   int send_sockfd;
   struct sockaddr_in send_address;
   int res,i;
   char buffer[20];

   for (i=0; i<19; i++)
   {
      buffer[i]=*argv[1];
      argv[1]++;
   }
   send_address.sin_family = AF_INET;
   send_address.sin_addr.s_addr = inet_addr("192.168.244.144");
   send_address.sin_port = htons(9734);
  
   if ((send_sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
   {
        perror("socket");	  
        exit(EXIT_FAILURE);
   }
   if ((res = sendto(send_sockfd, buffer, 20, 0 , (struct sockaddr *)&send_address,
                                                 sizeof(struct sockaddr))) < 0)
   {
        perror("sendto");
        exit(EXIT_FAILURE);
   }
   close(send_sockfd); 
}
