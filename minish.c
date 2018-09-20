#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include</usr/include/wait.h>

int main(){
		char command[100];
		do{
		fprintf(stdout,"minish>");
                scanf("%[^\n]%*c",command);
		pid_t pid=fork();
		if(pid == 0){
			printf("child process");
			if(execlp(command,command,(char *) NULL) == -1){ 
 			fprintf(stderr, "execl failed\n"); 
			exit(-2);
			}
		}
		else if(pid>0){
			printf("parent process");
			while(wait(NULL) != pid);
			printf("parent process terminating");
		}
		else{
			fprintf(stderr,"fork failed");
			exit -1;
		}
		}while(1);

}
