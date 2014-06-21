# Sunny No Window

Linux下一个能从基于光音网视高校云视频服务搭建的校园视频网获取视频下载地址的工具

原理来自[CampusNetworkVideoHunter](https://github.com/sinsoul/CampusNetworkVideoHunter)

## 使用方法


	 snw <命令> [参数] <-命令选项> [选项值]
	
	 命令:
	      search, se             根据名称搜索 [参数] 关键词
	      infomation, info       视频信息 [参数] ID
	      play                   播放视频 [参数] ID
	      get [-n 第n集 ...]      使用wget下载视频 [参数] ID, -n指定下载 [选项值] 第n集
	      decode, dc             解密视频


`snw`的decode是调用`snw-decode`

## 安装说明

很简单, 只比将大象放进冰箱里多一个步骤

1.打开文件 `snw`, 将其中的校园网地址改为你自己学校的
, xml存放路径, 播放器也可以依照自己喜好修改

```bash

#校园网视频地址
ADDRESS="http://10.0.12.252"	#改为你学校的地址
#视频信息xml存放位置
SNW_ROOT="$HOME/.snw"			#依照自己喜好修改
#播放器
PLAYER="smplayer"				#依照自己喜好修改

```

2.编译snw-decode

```bash

gcc snw-decode.c -o snw-decode

```

3.将`snw`和`snw-decode`移动到你家里的`bin`下面

```bash

cp snw snw-decode ~/bin

```

4.为`snw`和`snw-decode`添加可执行属性

```bash

chmod +x ~/bin/snw ~/bin/snw-decode

```

##许可证

[GPLv2](https://www.gnu.org/licenses/gpl-2.0.html)

## 已知BUG

经当iconv转码错误时, 输出的表格对齐不对, 暂时误解, 谁要是知道解决方法麻烦告诉一声 :weary:
