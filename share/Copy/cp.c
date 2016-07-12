#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc,char* argv[]){
	int srcfd;
	int destfd;
	int readnum;
	int writenum;
	char buffer[1024];

	srcfd=open(argv[1],O_RDONLY|O_CREAT,0644);
	destfd=open(argv[2],O_WRONLY|O_CREAT,0644);

	if((-1==srcfd)||(-1==destfd)){
		printf("open error\n");
		exit(1);
	}
	while ((readnum=read(srcfd,buffer,sizeof(buffer)))>0)
	{
		writenum=write(destfd,buffer,readnum);
		if (-1==writenum)
		{
			printf("write error\n");
			exit(1);
		}
	}
	close(srcfd);
	close(destfd);
	return 0;
}