#include<stdio.h>
#include<unistd.h>
#include <sys/wait.h>

int main()
{
	int ret, status;
	char *files[]  = {"circle.c", "square.c", "rectangle.c", "main.c"};
	int num_of_files = sizeof(files)/sizeof(files[0]);

	for(int i=0; i<num_of_files; i++){
		ret = fork();
		if (ret < 0) {
			perror("Fork failed");
			_exit(1);
		} else if (ret == 0){
			char *args[]={"gcc", "-c", files[i], NULL};
			int err = execvp("gcc", args);
			if(err < 0) {
				perror("Linking exec() failed");
				_exit(1);
			}
		} else {
			wait(&status);
			if(WEXITSTATUS(status) != 0) {
				perror("Compilation Failed");
				_exit(1);
			}
		}
	}	

	ret = fork();
	if (ret < 0) {
		perror("Fork failed");
		_exit(1);
	} else if(ret == 0) {
		char *args[]={"gcc", "-o", "program.out", "circle.o", "square.o", "rectangle.o", "main.o", NULL};
		int err = execvp("gcc", args);
		if(err < 0) {
			perror("Linking exec() Failed");
			_exit(1);
		}
	} else {
		wait(&status);
		if(WEXITSTATUS(status) != 0) {
			perror("Linking Failed");
			_exit(1);
		}
	}

	ret = fork();
	if (ret < 0) {
		perror("Fork failed");
		_exit(1);
	} else if(ret == 0) {
		char *args[]={"./program.out", NULL};
		int err = execvp("./program.out", args);
		if(err < 0) {
			perror("Execution exec() Failed");
			_exit(1);
		}
	} else {
		wait(&status);
		if(WEXITSTATUS(status) != 0) {
			perror("Execution Failed");
			_exit(1);
		}
		printf("Exit Status : %d\n", WEXITSTATUS(status));
	}



}
