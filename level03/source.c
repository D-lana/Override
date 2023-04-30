#include <time.h>
#include <stdio.h>
#include <string.h>

void    decrypt(int key)
{
	  	long	size;
	  	long	i;
		char	buff[17] = "Q}|u`sfg~sf{}|a3";

		size = strlen((char *)buff); //17
		i  = 0;

	while (i < size) {
		buff[i] = key ^ buff[i];
		i += 1;
	}
	if (strncmp("Congratulations!", buff, 17) == 0) {
		system("/bin/bash");
		return ;
	}
	puts("\nInvalid password");
}

void    test(int input, int value) {
		long	key;

		key = value - input;
		switch (key) {
			case (0):
				decrypt(0);
				break;
			case (1):
				decrypt(1);
				break;
			case (2):
				decrypt(2);
				break;
			case (3):
				decrypt(3);
				break;
			case (21):
				decrypt(21);
				break;
			default:
				decrypt(rand());
				break;
		}
}

int main(int ac, char **av) {
		int password;

		srand(time(NULL));
		puts("***********************************");
		puts("*\t\tlevel03\t\t**");
		puts("***********************************");
		printf("Password:");
		scanf("%d", &password);
		test(password, 0x1337d00d);
		return (0);
}