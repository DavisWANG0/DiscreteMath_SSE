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
void select()//�û���������
//������������Լ�ѡ����Ӧ�Ĳ��� 
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
	printf("�����Ӧ���ѡ���㷨\nl:�Է��հ�\n2:���ݱհ�\n3:�ԳƱհ�\n4:�˳�\n");
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
void output(int s[100][100])//������� 
{
	printf("�����ϵ����Ϊ:\n");
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++) cout<<s[i][j];
		cout<<endl;
	}
}
void Reverse(int s[100][100])//�Է��հ� 
{
	for(int i=0;i<n;i++) s[i][i]=1;
	//���Խ�����Ϊ1 
	output(s);
	select();
}

void Symmetry(int s2[100][100])//�ԳƱհ� 
{
	int s1[100][100];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			s1[j][i]=s2[i][j];//��ת�þ��� 
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			s2[i][j]=s2[i][j]+s1[i][j]; 
			if(s2[i][j]>1) s2[i][j]=1;
			//ԭ�����ת�þ�������߼��� 
		}
	output(s2); 
	select(); 
}

void Transmit(int s[][100])//���ݱհ�
{
	for(int i=0;i<n;i++) 
		for(int j=0;j<n;j++) 
			if(s[j][i]==1)
			{
				for(int k=0;k<n;k++) 
				 	s[j][k]=s[j][k]|s[i][k];//�߼���
//������j�����i֮����ͨ����ô������н��k
//���j�����k��·��������ԭ������·����Ҳ������j��㾭��i���֮����ͨ�� ��[i,k] ��k��� 
//��������ַ���֮����һ�ֿ��Ե����s[j][k]Ϊ1 
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

