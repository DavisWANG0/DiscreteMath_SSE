#include<iostream>
using namespace std;
int n,s[1007][1007];
int main()
{	
	printf("�������ڽӾ�������������������v�ĸ�����:");
	cin>>n;
	printf("�������ڽӾ���:\n");
	for(int i=0;i<n;i++)
	{
		printf("\n");
		printf("�������ڽӾ���ĵ�%d��Ԫ��(Ԫ���Կո�ָ�):",i);
		for(int j=0;j<n;j++) cin>>s[i][j];
	}
	
	for(int i=0;i<n;i++) 
		for(int j=0;j<n;j++) 
		if(s[j][i]==1)
		{
			for(int k=0;k<n;k++) 
			 	s[j][k]=s[j][k] | s[i][k];//�߼���
//������j�����i֮����ͨ����ô������н��k
//���j�����k��·��������ԭ������·����Ҳ������j��㾭��i���֮����ͨ�� ��[i,k] ��k��� 
//��������ַ���֮����һ�ֿ��Ե����s[j][k]Ϊ1 
		}
	printf("Warshall�㷨���ô��ݱհ����ڽӾ���Ϊ:\n");
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++) cout<<s[i][j];
		cout<<endl;
	}
	system("pause"); 
} 
