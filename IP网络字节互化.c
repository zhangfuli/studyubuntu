#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
int main(int argc,char* argv[]){
	struct in_addr addr1,addr2;
	ulong l1,l2;
	l1=inet_addr("192.168.0.74");
	l2=inet_addr("211.100.21.179");
	printf("l1=%ld\n",l1);
	printf("l2=%ld\n",l2);
	memcpy(&addr1,&l1,4);
	memcpy(&addr2,&l2,4);
	printf("%s\n",inet_ntoa(addr1));
	printf("%s\n",inet_ntoa(addr2));
	return 0;
}
