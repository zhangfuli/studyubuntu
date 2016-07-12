#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#define PORT 5559

int main(int argc, char **argv)
{
   char buf[200];
   int count=0;
   int recv_sockfd,new_sockfd;
   struct sockaddr_in sin_addr, pin_addr;
   int len, pin_addr_size;
   pin_addr_size = sizeof(struct sockaddr);
   memset(&sin_addr, 0 , sizeof(sin_addr));
   sin_addr.sin_family = AF_INET;
   sin_addr.sin_addr.s_addr = htonl(INADDR_ANY);
   sin_addr.sin_port = htons(PORT);
   
   if ((recv_sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
   {
      perror("socket");
      exit(1);
   }
  
   if (bind(recv_sockfd, (struct sockaddr*) &sin_addr, sizeof(sin_addr)) < 0)
   {
      perror("bind");
      exit(1);
   }
   
   if (listen(recv_sockfd, 5) < 0)
   {
      perror("listen");
      exit(1);
   }

while(1)
{
   if ((new_sockfd = accept(recv_sockfd, (struct sockaddr *) &pin_addr,&pin_addr_size)) < 0)
      {
         perror("accept");
         exit(1);
      }
printf("new_sofd = %d\n",count);
   while (1)
   {
      if (recv(new_sockfd, buf, 200, 0) == -1)
      {
         perror("recv");
         exit(1);
      }
      printf("received from client :%s\n", buf);
     sleep(1);
   }
  close(new_sockfd);  
}
  return 0;
}


