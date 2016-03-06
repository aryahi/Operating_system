# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <signal.h>
//	Zombie and no zombie process

void event( int signo )
{
	if(signo == SIGCHLD)
	{
		int i = wait(NULL);
		printf("%d\n",i);
	}
	else if(signo == SIGINT)
	{
		printf("Sigint Signal no. = %d\n",SIGINT);
	}
	else if(signo == SIGTSTP)
	{
		printf("Sigtstp Signal no. = %d\n",SIGTSTP);
	}
	else if(signo == SIGCONT)
	{
		printf("Sigcont Signal no. = %d\n",SIGCONT);
	}
	else if(signo == SIGTERM)
	{
		printf("Sigterm Signal no. = %d\n",SIGTERM);
	}
	//kill(pid,signo);
}
int main( int argc, char *argv[])
{
    int pid, s;
	signal(SIGCHLD,event);
	signal(SIGINT,event);
	//signal(SIGTSTP,event);// Continues the stopped event (Ctrl + Z)
	signal(SIGCONT,event);// To run it, we have to comment SIGTSTP = Continues the stopped event using bg/ff
	signal(SIGTERM,event);//to run it, in new terminal (kill child pid)

//	Also use (kill -INT pid) (kill -CONT pid) in new terminal

    pid = fork();
    if(pid == 0)
    {
		
		printf("\nI am the child(%d) of %s(%d)\n",getpid(),argv[0],getppid());	
		printf("\nMy work is done, I am terminating\n");
		sleep(600);
    }
    else if(pid > 0)
    {
		sleep(80);
		int i = wait(&s);
//		Only sleep(50) is terminated by ctrl+c
		printf("\nQ\n");
		sleep(50);
		printf("\nI was the parent process(%d) of process(%d) and Status: %d\n",getpid(),i,WEXITSTATUS(s));//See what it returns in WEXITSTATUS
		sleep(20);
    }
    else
    {
		printf("\nError!! Can't create a process\n");
    }
    //return 257; 	
	exit(10);
   
}
