# include <stdio.h>
# include <unistd.h>
# include <sys/wait.h>
# include <sys/ptrace.h>
# include <string.h>

int main(int ac, char **av) {
	char    buff[0x80];  
	pid_t   child;      
	int     num;      
	int     status;

	child = fork();
	memset(buff, 0, sizeof(buff));
	num = 0;
	status = 0;
	if (child == 0) {
		prctl(1, 1);
		ptrace(0, 0, 0, 0);
		puts("Give me some shellcode, k\n");
		return ((int)gets(buff));
	} else {
		while (1) {
			wait(&status);
			if (WIFEXITED(status) || WIFSIGNALED(status)) {
				puts("child is exiting...\n");
				break ;
			} 
			else {
				num = ptrace(PTRACE_PEEKUSER, child, 0x2c, 0);
				if (num == 0xb) {
					puts("no exec() for you\n");
					kill(child, SIGKILL);
					break ;
				}
			}
		}
	}
	return (0);
}