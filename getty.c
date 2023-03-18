#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc,char *argv[])
{
	//file read
	char buff[150];
	FILE *fData;
	fData = fopen("passwd","rb");
	if (fData == NULL) {
	printf("psswd ERROR\n");
	return 0;
	}
	char user[30];
	char passwd[30];
	char *token;
	char *token2;
	
	int p;
		
	while(1)
	{
		printf("User:");
		scanf("%s",user);

		printf("Passwrd:");
		scanf("%s",passwd);
		
		// Validar si el usuario y el password son correctos y si son correctos
		
	while(fscanf(fData,"%s",buff)==1){
		token = strtok(buff,":");
		
		token2 = strtok(NULL, buff);
		 if (strcmp(token,user) == 0 && strcmp(token2,passwd) ==0) {
		 printf("welcome \n");
		 // ejecutar el shell
		p=fork();
		if(p==0)
			execlp("./shell","./shell",argv[1],NULL);
		wait(NULL);
		break;
		 
		 }
		 printf("usuario o contraseña invalida\n");
	}
		
		
		
		

	}
}
