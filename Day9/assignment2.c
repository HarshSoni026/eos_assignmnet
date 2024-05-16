#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main()
{
	int r1,r2,r3,count,s1,s2,s3,s4;
	r1 = fork();
	if(r1 == 0)
	{
		r2 = fork();
		if(r2 == 0)
		{
			r3 = fork();
			if(r3 == 0)
			{ 
				for(count=1; count<6; count++){
					printf("count by Child D: %d\n",count);
					printf("child D pID : %d\n", getpid());
					sleep(1);
				}
				wait(&s3);
				_exit(0);
		}
		
				for(count=1; count<6; count++){
					printf("count by Child C: %d\n",count);
					printf("child C pID : %d\n", getpid());
					sleep(1);
				}
				wait(&s2);
				_exit(0);
		}

				for(count=1; count<6; count++){
					printf("count by Child B: %d\n",count);
					printf("child B pID : %d\n", getpid());
					sleep(1);
				}
				wait(&s1);
				_exit(0);
		}
		for(count=1; count<=5; count++){
			printf("count by Parent A = %d\n", count);
			printf("parent A pID : %d\n", getpid());
			sleep(1);
	}
		wait(&s4);
		_exit(0);

	return 0;
		
}
