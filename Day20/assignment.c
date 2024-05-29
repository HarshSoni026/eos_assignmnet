#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <string.h>


#define MAX_FILE_SIZE 1024 * 1024 * 1024

int main() {
	struct stat st;
	int fd, ret, dst_fd;
	void *scr_addr, *dst_addr;;
	fd = open("/home/harsh/0324desd/eos/Day03/cmd_history.txt", O_RDONLY);
	if(fd < 0) {
		perror("open() failed");
		_exit(1);
	}
	ret = fstat(fd, &st);
	if(ret < 0) {
		perror("fstat() failed");
		close(fd);
		_exit(2);
	}
	printf("reading file of size: %lu\n", st.st_size);

	scr_addr = mmap(NULL, st.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
	if(scr_addr == (void*)-1) {
		perror("mmap() failed");
		close(fd);
		_exit(3);
	}

	dst_fd = open("/home/harsh/0324desd/eos/eos_assignment/new.txt", O_RDWR | O_CREAT, 0644);
	if(dst_fd < 0){
		perror("open() failed");
		close(dst_fd);
		_exit(4);
	}

	int trunc = ftruncate(dst_fd, st.st_size);
	if(trunc == -1){
		perror("ftruncate() failed");
		close(trunc);
		_exit(5);
	}

	dst_addr = mmap(NULL, st.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, dst_fd, 0);
	if( dst_addr < 0){
		perror("mmap() failed");
		close(dst_fd);
		_exit(6);
	}

	 memcpy(dst_addr, scr_addr, st.st_size);

	close(fd);
	close(dst_fd);
	return 0;
}

