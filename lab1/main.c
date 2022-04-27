#include <stdio.h>
#include <string.h>


int main()
{
	char str[256], tmp_str[256];
	int count = 1, max_count = 1;
    char *chr, *tmp_chr;
    char *max_adr = str;
	char max_chr;
	int int_max_adr;

    printf("Enter any string without spaces:\n");
	scanf("%s", str);

	for (;;)
	{
		for (chr = str + 1; *(chr - 1) != '\0'; chr++)
		{
			if (*(chr - 1) == *(chr)) count++;
			else
			{
				if (count > max_count)
	       			{
					max_count = count;
					max_adr = (chr - 1) - count + 1;
					max_chr = *(chr - 1);
				}

				count = 1;
			}
		}

		if (max_count == 1) break;

		tmp_chr = tmp_str;
		for (chr = str; *chr != '\0'; chr++)
			if ((chr < max_adr) || (chr > max_adr + max_count - 1))
			{
				*tmp_chr = *chr;
				tmp_chr++;
			}
		*tmp_chr = '\0';

		int_max_adr = (int)(max_adr - str);
		printf("%s --> %d,%d %c\n", str, int_max_adr, (int_max_adr + max_count - 1), max_chr);
		strcpy(str, tmp_str);

		max_count = 1; max_adr = str;
	}

	printf("Output string: %s\n", str);


	return 0;
}
