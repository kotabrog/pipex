#include <stdio.h>

int main(int argc, char **argv, char **env)
{
	while (*argv)
	{
		printf("%s\n", *(argv++));
	}
}
