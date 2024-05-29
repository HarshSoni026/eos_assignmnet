#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int arr[10] = {12,54,34,87,97,45,6,32,11,47};
pthread_mutex_t s;

void* thread_func(void *param) {
	int *arr = (int*)param;
	int i, j, temp;
	int array_size = 10;
	int min_index = 0;

    for(int k=0; k<array_size; k++){
        for (i=0; i<array_size-1-k; i++){
            j = i + 1;
            if(arr[i] > arr[j]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
	
	return NULL;
}

int main() {
	int ret = 0;
	pthread_t th;
	ret = pthread_create(&th, NULL, thread_func, arr);
	if (ret < 0) {
		printf("The thread is not created\n");
	}
	pthread_join(th, NULL);
	printf("sorted array:\n");
	for (int i=0; i<10; i++) {
		printf("%d\n", arr[i]);
	}
	printf("\r\n");
	return 0;
}
