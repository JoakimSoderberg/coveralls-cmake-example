#include <stdio.h>
#include <complicated.h>

int main(int argc, char **argv)
{
	if (complicated(3) != 4)
	{
		goto fail;
	}

	if (complicated(4) != 4)
	{
		goto fail;
	}

	if (complicated(0) != 0)
	{
		goto fail;
	}

	printf("Success!\n");
	return 0;
fail:
	fprintf(stderr, "Failed test!\n");
	return -1;
}