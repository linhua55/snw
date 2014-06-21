#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[])
{
	if (argc < 2)
	{
		fprintf (stderr, "用法: %s 文件名...\n", argv[0]);
		return 1;
	}

	int i;
	for (i = 1 ; i < argc; ++i)
	{
		FILE *fp = fopen (argv[i], "r+");
		if (!fp)
		{
			fprintf (stderr, "无法打开文件 %s!\n", argv[i]);
		}
		else
		{
			fseek (fp, 0L, SEEK_SET);
			int j;
			for (j = 0; j < 160; ++j)
			{
				int8_t v;
				fread (&v, sizeof (int8_t), 1, fp);
				fseek (fp, -1L, SEEK_CUR);
				v^=0xff;
				fwrite (&v, sizeof (int8_t), 1, fp);
			}
			fclose (fp);
		}
	}
	return 0;
}

