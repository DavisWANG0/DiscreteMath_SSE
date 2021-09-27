#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
int s[100][100];
int n;
void output(int s[][100]);
void Reverse(int s2[][100]);
void Symmetry(int s2[][100]);
void Transmit(int s2[][100]);
void select();
void exit();
void select()//用户交互界面
//用来输入矩阵以及选择相应的操作 
{
	printf("请输入邻接矩阵的行数与列数（结点v的个数）:");
	cin>>n;
	printf("请输入邻接矩阵:\n");
	for(int i=0;i<n;i++)
	{
		printf("\n");
		printf("请输入邻接矩阵的第%d行元素(元素以空格分隔):",i);
		for(int j=0;j<n;j++) cin>>s[i][j];
	}
	printf("输入对应序号选择算法\nl:自反闭包\n2:传递闭包\n3:对称闭包\n4:退出\n");
	int ops=0;
	cin>>ops; 
	switch(ops)
	{
		case 1:Reverse(s); break;
		case 2:Transmit(s);break;
		case 3:Symmetry(s);break;
		case 4:exit(1);break;
	}
}
void output(int s[100][100])//输出函数 
{
	printf("所求关系矩阵为:\n");
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++) cout<<s[i][j];
		cout<<endl;
	}
}
void Reverse(int s[100][100])//自反闭包 
{
	for(int i=0;i<n;i++) s[i][i]=1;
	//主对角线置为1 
	output(s);
	select();
}

void Symmetry(int s2[100][100])//对称闭包 
{
	int s1[100][100];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			s1[j][i]=s2[i][j];//求转置矩阵 
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			s2[i][j]=s2[i][j]+s1[i][j]; 
			if(s2[i][j]>1) s2[i][j]=1;
			//原矩阵和转置矩阵进行逻辑加 
		}
	output(s2); 
	select(); 
}

void Transmit(int s[][100])//传递闭包
{
	for(int i=0;i<n;i++) 
		for(int j=0;j<n;j++) 
			if(s[j][i]==1)
			{
				for(int k=0;k<n;k++) 
				 	s[j][k]=s[j][k]|s[i][k];//逻辑加
//如果结点j到结点i之间连通，那么穷举所有结点k
//结点j到结点k的路径可以是原本就有路径，也可以是j结点经过i结点之后再通过 边[i,k] 到k结点 
//如果这两种方法之中有一种可以到达，则s[j][k]为1 
			}
	output(s);
	select();
}

int main() 
{
	select();
	system("pause"); 
	return 0;
}

