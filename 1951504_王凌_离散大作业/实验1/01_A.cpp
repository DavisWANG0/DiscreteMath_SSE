#include<stdio.h>
#include<iostream>
#include<windows.h>
using namespace std;
int main()
{
	int p=-1,q=-1;
	char s;
	first_place://标语 
	cout<<"***************************************"<<endl; 
	cout<<"**        欢迎进入逻辑运算程序       **"<<endl;
	cout<<"***************************************"<<endl;
	cout<<endl<<"请输入P的值（0或1）,以回车结束:";
	cin>>p;
	if(p!=0 && p!=1)
	{
		cout<<endl<<"P的值输入有误,请重新输入!";
		Sleep(2000);
		system("cls");//清屏
		goto first_place;
	}
	cout<<endl<<"请输入Q的值（0或1）,以回车结束:";
	cin>>q;
	if(q!=0 && q!=1)
	{
		cout<<endl<<"Q的值输入有误,请重新输入!";
		Sleep(2000);
		system("cls");//清屏
		goto first_place;
	}
	printf("  合取:\n       P/\\Q = %d\n",p && q);//与运算 
	printf("  析取:\n       P\\/Q = %d\n",p || q);//或运算
	printf("  条件:\n       P->Q = %d\n",(!p) || q);//蕴含运算，将其转化为与或非形式
	printf("  双条件:\n       P<->Q = %d\n",((!p) || q) && ((!q) || p));//等值运算，将其转化为与或非形式
	second_place:
	cout<<"是否继续运算?（y/n）"<<endl;//询问是否继续操作
	cin>>s; 
	if (s=='y' || s=='n')
	{
		if (s=='y')
		{ 
			system("cls");//清屏
			goto first_place;//返回顶层
		}
		else
		{
			cout<<"欢迎下次再次使用!"<<endl;//退出
			exit(0);
		}
	}
	else
	{
		cout<<"输入错误,请重新输入!"<<endl; //错误校验
		goto second_place;
	}
	system("pause"); 
	return 0;
}
