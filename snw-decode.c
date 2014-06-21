/*
   Sunny No Window decode
   许可证: GPLv2
   作者: 蔡佳男
   解密从从基于光音网视高校云视频服务搭建的校园视频网下载下来的视频的小工具
   原理来自CampusNetworkVideoHunter https://github.com/sinsoul/CampusNetworkVideoHunter

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
				char v;
				fread (&v, sizeof (char), 1, fp);
				fseek (fp, -1L, SEEK_CUR);
				v^=0xff;
				fwrite (&v, sizeof (char), 1, fp);
			}
			fclose (fp);
		}
	}
	return 0;
}

