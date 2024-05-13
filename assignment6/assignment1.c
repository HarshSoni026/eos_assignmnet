#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main()
{
	int ret,count,i,s;
	for(i=1;i<=5;i++){
		ret=fork();
		if(ret == 0){
			for(count=1; count<=5; count++){
				printf("child: count %d\n", count);
				printf("child : pid= %d\n", getpid());
				sleep(1);
		}
			_exit(2);
		}
	}
	
	 
	for(i=1;i<=5;i++){
			waitpid(-1, &s, 0);
			printf("child exit: %d\n",  WEXITSTATUS(s));
		}
		return 0;
}

