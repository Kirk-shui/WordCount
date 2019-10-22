# WordCount

========================================

开发语言：C++
介绍：命令行文本计数统计程序。
目前功能：能统计导入的纯英文txt文本中的字符数，单词数，句子数。用Visual C++编译运行，在命令行输入：
wc.exe [参数][文件名] 
可使用。参数有‘-c’（统计字符）、‘-w’（统计单词）、‘-s’（统计句子数）

========================================

文件列表：
README.MD		介绍项目内容的文件
WordCount.cpp		程序代码，可使用C++编译器使用打开命令窗口。
file.txt			单元测试用文本文件
PerformanceTest		存放单元测试截图的文件夹

========================================

例程运行：
Test01：
file.txt:(NULL)
Go:
input : wc.exe -c file.txt
output : Charater Number is 0.
input : wc.exe -w file.txt
output : Word Number is 0.
input : wc.exe -s file.txt
output : Sentence Number is 0.

Test02:
file.txt:'\n'
Go:
input : wc.exe -c file.txt
output : Charater Number is 1.
input : wc.exe -w file.txt
output : Word Number is 0.
input : wc.exe -s file.txt
output : Sentence Number is 0.

Test03:
file.txt:
Go:
input : wc.exe -t file.txt
output : Error!
input : wc.exe -w file.txt
output : Assertion failed: infile.is_open(). file E:\......（报错）

Test04:
file.txt : Hello World!
Go:
input : wc.exe -c file.txt
output : Charater Number is 12.
input : wc.exe -w file.txt
output : Word Number is 2.
input : wc.exe -s file.txt
output : Sentence Number is 1.


Test05:
file.txt : However long the night, the dawn will break.
Go:
input : wc.exe -c file.txt
output : Charater Number is 44.
input : wc.exe -w file.txt
output : Word Number is 8.
input : wc.exe -s file.txt
output : Sentence Number is 1.

Test06:
file.txt : However long the night, the dawn will break.'\n'Everyone is fighting their own battle.
Go:
input : wc.exe -c file.txt
output : Charater Number is 83.
input : wc.exe -w file.txt
output : Word Number is 14.
input : wc.exe -s file.txt
output : Sentence Number is 2.