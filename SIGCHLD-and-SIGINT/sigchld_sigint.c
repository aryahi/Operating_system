# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <signal.h> //For signals to work

void event( int signo )
{
	if(signo == SIGCHLD)
	{
		int i = wait(NULL);
		printf("%d\n",i);
	}
	else if(signo == SIGINT)
	{
		printf("Signal no. = %d\n",SIGINT);
	}
}
int main( int argc, char *argv[])
{
  int pid, s;
	signal(SIGCHLD,event);
	signal(SIGINT,event);
  pid = fork();
  if(pid == 0)
  {
		printf("\nI am the child(%d) of %s(%d)\n",getpid(),argv[0],getppid());	
		printf("\nMy work is done, I am terminating\n");
  }
  else if(pid > 0)
  {
		sleep(80);
		int i = wait(&s);
		sleep(50);
		printf("\nI was the parent process(%d) of process(%d) and Status: %d\n",getpid(),i,WEXITSTATUS(s));
		sleep(20);
  }
  else
  {
		printf("\nError!! Can't create a process\n");
  }
 	
	return 10;
   
}
