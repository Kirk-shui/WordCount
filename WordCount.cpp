#include "iostream"
#include "fstream"
#include "string"
#include "cassert"

using namespace std;

class WordCount
{
private:
	string fName;			//文件名
	string fMode;			//统计模式
	int fCharCount;			//字符数
	int fWordCount;			//单词数
	int fSentCount;			//句子数
public:
	WordCount()				//变量初始化
	{
		fCharCount = 0;
		fWordCount = 0;
		fSentCount = 0;
		fName = "";
		fMode = "";
	}
	void Count(int n);
	void Get(string m,string n);
	void Display();
};

void WordCount::Count(int n)		//统计各个数据变量
{
	int i;
	string s;
	char c,e[] = {'.','?','!',':',')'};

	ifstream infile;
	infile.open(fName.begin());
	assert(infile.is_open());	//若读取文件错误，结束程序
	if(n==1)	//判断字符数
	{
		fCharCount = 0;
		infile >> noskipws;
		while(!infile.eof())	
		{
			infile >> c;
			fCharCount++;
		}
		fCharCount--;	//判断字符数时，去掉结尾字符
		infile.close();
	}
	else if(n==2)	//判断单词数
	{
		fWordCount = 0;
		while(!infile.eof())	
		{
			if(infile.get(c) && c!='\n')
			{
				infile >> s;
				fWordCount++;
			}
		}
		infile.close();
	}
	else if(n==3)	//判断句子数，若结尾无符号，则不视为句子。
	{
		fSentCount = 0;
		while(infile.get(c))	
		{
			if(c<'A' || c>'z')
			{
				for(i=0;i<5;i++)
				{
					if(c==e[i])  
					{
						fSentCount++;
						break;
					}
				}
			}
		}
		infile.close();
	}
}

void WordCount::Get(string m,string n)	//从main函数里读取文件名与统计模式
{
	fMode = m;
	fName = n;
}

void WordCount::Display()	//输出结果
{
	if(fMode == "-c")
	{
		Count(1);
		cout << "Charater Number is " << fCharCount << "." << endl;
	}
	else if(fMode == "-w")
	{
		Count(2);
		cout << "Word Number is " << fWordCount << "." << endl;
	}
	else if(fMode == "-s")
	{
		Count(3);
		cout << "Sentence Number is " << fSentCount << "." << endl;
	}
	else
		cout << "Error!" << endl;
}

void main()
{
	string Start,Mode,FileName;
	WordCount WC; 

	while(1)
	{
		cin >> Start;
		if(Start != "exit")
		{
			cin >> Mode >> FileName;
			WC.Get(Mode,FileName);
			WC.Display();
		}
	}
}

