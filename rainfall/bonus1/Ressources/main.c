
#include <stdio.h>

int main(void)
{
	for (int i = 0; i <= 0; i--)
	{
		size_t tmp;

		tmp = i * 4;
		if (tmp == 60)
		{
			printf("%d\n", i);
			return 0;
		}
	}
	return 0;
}
