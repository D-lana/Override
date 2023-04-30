#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	char	buff[0x64]; //100
	int     i;

	i = 0;
	fgets(buff, 0x64, stdin);
	while (i < strlen(buff)) 	{
		if (buff[i] > 0x40) { //64
			if (buff[i] <= 0x5a) { //90
				buff[i] = buff[i] ^ 0x20; //0010 0000
			}
		}
		printf("\\x%02hhx", buff[i]);
		i += 1;
	}
	printf("\n");
	printf(buff);
	exit(0);
}