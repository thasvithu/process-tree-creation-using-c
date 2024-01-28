#include <stdio.h>

int main() {
	int A = fork(); //0 = child or 1 = Parent
	
	if (A < 0)
		printf("Process A Creation Failed!");
	else if (A == 0) {
		//Child
		printf("Child A PID = %d, Child A PPID = %d\n", getpid(), getppid());
		
		//PROCESS B
		int B = fork();
		
		if (B < 0)
			printf("Process B Creation Failed!");
		else if (B == 0) {
			printf("Child B PID = %d, Child B PPID = %d\n", getpid(), getppid());
		}
		else {
			//PROCESS C
			int C = fork();
			
			if (C < 0)
				printf("Process C Creation Failed!");
			else if (C ==0) {
				printf("Child C PID = %d, Child C PPID = %d\n", getpid(), getppid());
				
				//PROCESS E
				int E = fork();
				
				if (E < 0)
					printf("Process E Creation Failed!");
				else if (E == 0) {
					printf("Child E PID = %d, Child E PPID = %d\n", getpid(), getppid());
					
					//PROCESS F
					int F = fork();
					
					if (F < 0)
						printf("Process F Creation Failed!");
					else if (F == 0) {
						printf("Child F PID = %d, Child F PPID = %d\n", getpid(), getppid());
					}
					else {
						//PROCESS G
						int G = fork();
						
						if (G < 0)
							printf("Process G Creation Failed!");
						else if (G == 0) {
							printf("Child G PID = %d, Child G PPID = %d\n", getpid(), getppid());
						}
						else {
							wait(NULL);
						}
					}
				}
				else {
					wait(NULL);
				}
			}
			else {
				//PROCESS D
				int D = fork();
				
				if (D < 0)
					printf("Process D Creation Failed!");
				else if (D == 0) {
					printf("Child D PID = %d, Child D PPID = %d\n", getpid(), getppid());
					
					//PROCESS H
					int H = fork();
					
					if (H < 0)
						printf("Process H Creation Failed!");
					else if (H == 0) {
						printf("Child H PID = %d, Child H PPID = %d\n", getpid(), getppid());
					}
				}
				else {
					//PROCESS I
					int I = fork();
					
					if (I < 0)
						printf("Process I Creation Failed!");
					else if (I == 0) {
						printf("Child I PID = %d, Child I PPID = %d\n", getpid(), getppid());
						
						//PROCESS J
						int J = fork();
						
						if (J < 0)
							printf("Process J Creation Failed!");
						else if (J == 0) {
							printf("Child J PID = %d, Child J PPID = %d\n", getpid(), getppid());
						}
						else {
							wait(NULL);
						}
					}
					else {
						wait(NULL);
					}
				}
			}
		}
	}
	else {
		//Parent
		printf("Parent PID = %d\n", getpid());
	}
	
	return 0;
}
