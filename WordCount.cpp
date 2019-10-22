#include "iostream"
#include "fstream"
#include "string"
#include "cassert"

using namespace std;

class WordCount
{
private:
	string fName;			//�ļ���
	string fMode;			//ͳ��ģʽ
	int fCharCount;			//�ַ���
	int fWordCount;			//������
	int fSentCount;			//������
public:
	WordCount()				//������ʼ��
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

void WordCount::Count(int n)		//ͳ�Ƹ������ݱ���
{
	int i;
	string s;
	char c,e[] = {'.','?','!',':',')'};

	ifstream infile;
	infile.open(fName.begin());
	assert(infile.is_open());	//����ȡ�ļ����󣬽�������
	if(n==1)	//�ж��ַ���
	{
		fCharCount = 0;
		infile >> noskipws;
		while(!infile.eof())	
		{
			infile >> c;
			fCharCount++;
		}
		fCharCount--;	//�ж��ַ���ʱ��ȥ����β�ַ�
		infile.close();
	}
	else if(n==2)	//�жϵ�����
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
	else if(n==3)	//�жϾ�����������β�޷��ţ�����Ϊ���ӡ�
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

void WordCount::Get(string m,string n)	//��main�������ȡ�ļ�����ͳ��ģʽ
{
	fMode = m;
	fName = n;
}

void WordCount::Display()	//������
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

