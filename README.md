# AllPermutationPassword
全排列密码字典生成程序
## 运行
g++编译main.cpp
也可使用Clion直接打开本项目

sudo执行编译后的结果 ==需要写入当前文件夹的写入权限==

输入最小密码长度和最大密码长度分别回车确认

稍等片刻会在本目录生成dic0.txt，dic1.txt，dic2.txt ....
50000000条记录会形成一个txt，以此分片

## 注意
由于是全排列所有密码可能

所以在输入长度后，若过大，生成dic.txt会非常巨大具体txt行数可由公式计算：

$\sum_{i=MiniDigit}^{MaxDigit}{92^{i}}$
