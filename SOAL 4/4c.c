#include<stdio.h> 
#include<stdlib.h> 
#include<unistd.h> 
#include<sys/types.h> 
#include<string.h> 
#include<sys/wait.h> 

int main() 
{ 
	int store1[2]; // Used to store two ends of first pipe 
	int store2[2]; // Used to store two ends of second pipe 

//	char fixed_str[] = "forgeeks.org"; 
//	char input_str[100]; 
	pid_t p; 

	if (pipe(store1)==-1) 
	{ 
		fprintf(stderr, "Pipe Failed" ); 
		return 1; 
	} 
	if (pipe(store2)==-1) 
	{ 
		fprintf(stderr, "Pipe Failed" ); 
		return 1; 
	} 

//	scanf("%s", input_str); 
	p = fork(); 

	if (p < 0) 
	{ 
		fprintf(stderr, "fork Failed" ); //strderr : default destination for error massaage/ output all the error
		return 1; 
	} 

	// Parent process 
	else if (p > 0) 
	{ 
        close(store1[1]);
        close(store2[0]);
        close(store2[1]);

		dup2(store1[0],0); 
		dup2(store2[1],1); 

        close(store1[0]);

        char *argv[] = {"wc","-l",NULL};
        execv("/usr/bin/wc", argv);

		// Wait for child to send a string 
//		wait(NULL); 

//		close(fd2[1]); // Close writing end of second pipe 

		// Read string from child, print it and close 
		// reading end. 
//		read(fd2[0], concat_str, 100); 
//		close(fd2[0]); 
	} 

    else{
        close(store1[0]);
        dup2(store1[1],1);

        close(store1[1]);

        char *argv[] = {"ls",NULL};
        execv("/bin/ls", argv);
    }
} 