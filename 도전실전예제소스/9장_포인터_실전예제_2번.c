#include <stdio.h>

int main()
{
	char str[80];

	gets(str);

	for (int i = 0; str[i] != '\0'; i++)
	{
		if ('A' <= str[i] && str[i] <= 'Z')
			str[i] += 32;
	}

	printf("%s", str);

	return 0;
}