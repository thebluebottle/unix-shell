#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <sys/wait.h>



int main(int argc,char *argv[])
{
	char cmd[10];
	int salir=0;
	char *binaryPath = "/bin/";
		
	while(!salir)
	{
		printf("$ ");
		fgets(cmd, sizeof cmd, stdin);
		if(strcmp(cmd,"exit\n")==0)
		{
			//kill(pidinit,SIGUSR1);
			
			exit(0);
		}
		cmd[strcspn(cmd, "\n")] = 0;
		execlp(cmd,cmd,"-a","/home",NULL);
	
		// No usar system, hay que usar exec, pero es imnportante separar los 
		// par?metros con los espacios
		
		// Si el comando que teclea el usuario termina con un &
		// La ejecución se hace en segundo plano
		// Cuando se hace la ejecución en segundo plano, el shell NO ESPERA
		// la terminación del programa
		
	}
}
