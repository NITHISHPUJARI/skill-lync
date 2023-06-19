#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<stdio.h>

int main()
{
	int n,fd;
	char buff[100];	// declaring buffer 
	
	//message printing on the display
	printf("Enter text to write in the file:\r\n");
	//read from keyboard, specifying 0 (STDIN_FILENO) as fd for std input device
	//Here, n stores the number of characters	
	n= read(STDIN_FILENO, buff, 100);

	// creating a new file using open.
    // Will create new file "file.txt"
	fd=open("file.txt",O_CREAT | O_RDWR, 0777); 
	
	//writting input data to file (fd)
	write(fd, buff, n);
	//Write to display (1 is standard fd for output device : STDOUT_FILENO )
	write(STDOUT_FILENO, buff, n);
    printf("\r\n");
	//closing the file
	int close(int fd);
	
	return 0;	
}
