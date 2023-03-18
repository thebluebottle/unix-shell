#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

#define NPROCS 6

int ptable[NPROCS];

void sighand(int signal)
{
	int i;
	printf("Recibí una señal, aquí tengo que terminar todos los procesos creados\n");
	for(i=0;i<NPROCS;i++)
		kill(ptable[i],SIGKILL);
}

int main()
{
	int i;
	int p;
	char pid[6];
	
	signal(SIGUSR1,sighand);
	
	sprintf(pid,"%d",getpid());
	
	for(i=0;i<NPROCS;i++)
	{
		p=fork();
		if(p==0)
			execlp("xterm","xterm","-e","./getty",pid,NULL);
		ptable[i] = p;
	}
	
	for(i=0;i<NPROCS;i++)
		wait(NULL);	// Si un proceso xterm termina, hay que lanzar otro 
}
