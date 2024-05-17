#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
	int ret,s, arr1[2],arr2[2], num1, num2, res, n1, n2;

	ret = pipe(arr1);
	ret = pipe(arr2);
	ret = fork();
	if(ret == 0) {
		printf("In child process: START \n");
		close(arr1[0]);
		close(arr2[1]);
		printf("Enter num1 : \n");
		scanf("%d", &num1);
		printf("Enter num2 : \n");
		scanf("%d", &num2);

		ret = write(arr1[1], &num1, sizeof(num1));
		ret = write(arr1[1], &num2, sizeof(num2));

		ret = read(arr2[0], &res, sizeof(res));
		printf("result: %d\n", res);

		close(arr2[0]);
		close(arr1[1]);
		printf("In child process: STOP  \n");
		_exit(1);
	}
	else {
		printf("parent: waiting for data...\n");
		close(arr1[1]);
		close(arr2[0]);
		ret = read(arr1[0], &n1, sizeof(n1));
		ret = read(arr1[0], &n2, sizeof(n2));

		int r = n1 + n2;

		ret = write(arr2[1], &r, sizeof(r));
	

		close(arr2[1]);
		close(arr1[0]);
		printf("In Parent process: end1 \n");
		waitpid(-1, &s, 0);
		printf("In Parent process: end2 \n");
	}
	return 0;
}
