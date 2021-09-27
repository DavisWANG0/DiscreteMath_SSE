#include<iostream>
using namespace std;
int n,s[1007][1007];
int main()
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
	
	for(int i=0;i<n;i++) 
		for(int j=0;j<n;j++) 
		if(s[j][i]==1)
		{
			for(int k=0;k<n;k++) 
			 	s[j][k]=s[j][k] | s[i][k];//逻辑加
//如果结点j到结点i之间连通，那么穷举所有结点k
//结点j到结点k的路径可以是原本就有路径，也可以是j结点经过i结点之后再通过 边[i,k] 到k结点 
//如果这两种方法之中有一种可以到达，则s[j][k]为1 
		}
	printf("Warshall算法所得传递闭包的邻接矩阵为:\n");
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++) cout<<s[i][j];
		cout<<endl;
	}
	system("pause"); 
} 
