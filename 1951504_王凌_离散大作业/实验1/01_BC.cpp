#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "conio.h"
#include "math.h"
#define N 50 

void panduan(int b[N],int f);//��ֵ����
int tkh(char sz[N],char ccu[N],int icu[N],int h0);//�ּ����㺯��
int fkh(char sz[N],char ccu[N],int icu[N],int h0);//�����㺯��

int main()
{
	int i1,i2,d=1,icu[N],kh=0,jg,j=0,h0;//icu[N]���ڴ�ű���ֵ,kh�������ż���,jg��Ž��
	int bj=0,hq[N],h=0,x=0,xq[N];//hq[N]��ź�ȡ���,xq[N]�����ȡ���
	char sz[N],ccu[N],sz0[N];//sz[N]���ʽ��,ccu[N]��ű���,sz0[N]Ҳ�����ڴ��ʽ��
	hq[0]=-1;
	xq[0]=-1;
	printf("***************************************\n");//����
	printf("**                                   **\n");
	printf("**         ��ӭ�����߼��������      **\n");
	printf("**   (��������ֵ��,����ʽ,֧������)  **\n");
	printf("**                                   **\n");
	printf("**              ��!��ʾ��            **\n");
	printf("**              ��&��ʾ��            **\n");
	printf("**              ��|��ʾ��            **\n");
	printf("**             ��^��ʾ�̺�           **\n");
	printf("**             ��~��ʾ��ֵ           **\n");
	printf("**                                   **\n");
	printf("***************************************\n\n");
	printf("������һ���Ϸ������⹫ʽ:\n");//����ʽ��
	gets(sz);//��ȡʽ��
	strcpy(sz0,sz);//����ʽ��
	for(unsigned i1=0;i1<strlen(sz);i1++)
	{
		if(sz[i1]==')' || sz[i1]=='(')//�洢��������
			kh++;
		if(sz[i1]>='a' && sz[i1]<='z' || sz[i1]>='A' && sz[i1]<='Z') 
		{
			for(i2=0;i2<j;i2++)//�жϲ����������
				if(ccu[i2]==sz[i1])//ȥ���ظ�����
					d=0;
			if(d==1)
			{
				ccu[j]=sz[i1];
				j++;
			}
			d=1; 
		}
	}
	printf("\n��ʽ���еı�������Ϊ:%d\n",j);//�����������
	h0=j; 
	printf("\n�����ֵ������:\n \n");//�����ֵ���ͷ
	for(i1=0;i1<h0;i1++)
		printf(" %c ",ccu[i1]); 
	printf("    ");
	puts(sz);
	printf("\n"); 
	for(i1=0;i1<j;i1++)//�Ƚ����еı�����ֵΪ�㡣
		icu[i1]=0;
	for(i2=0;i2<j;i2++)//�����ֵ��ǰ��
		printf(" %d ",icu[i2]);
	jg=tkh(sz,ccu,icu,h0);//�ú�������
	if(jg==0)//���Ϊ0����ȡ��1
		hq[h++]=bj;
	else//������ȡ��1
		xq[x++]=bj; 
	printf("    %d\n",jg);//���������
	strcpy(sz,sz0); 
	for(i1=0;i1<(int)pow(2.0,j) - 1;i1++)
	{
		++bj;
		panduan(icu,j - 1);//��ֵ����
		jg=tkh(sz,ccu,icu,h0); 
		if(jg==0)//���Ϊ0����ȡ��1
			hq[h++]=bj;
		else//������ȡ��1
			xq[x++]=bj; 
		strcpy(sz,sz0);//�ָ����޸ĵ�����
		for(i2=0;i2<j;i2++)
			printf(" %d ",icu[i2]);//�����ֵ��ǰ��
		printf("    %d\n",jg);//���������
	} 
	if(hq[0]==-1)//�����ں�ȡ��ʽʱ
		printf("\n�����⹫ʽ����������ȡ��ʽ.\n");
	else
	{ 
		printf("\n�����⹫ʽ������ȡ��ʽ:\n\t");
		for(i1=0;i1<h;i1++)
			{
				if (i1 > 0)//�жϲ���ӷ���
					printf("\\/");
				printf("M(%d)",hq[i1]);//�������ȡ��ʽ
			}
	}
	if(xq[0]==-1)//��������ȡ��ʽʱ
		printf("\n�����⹫ʽ����������ȡ��ʽ.\n");
	else
	{
		printf("\n\n�����⹫ʽ������ȡ��ʽ:\n\t");
		for(i1=0;i1<x;i1++)
		{
			if (i1 > 0)//�жϲ���ӷ���
				printf("/\\");
			printf("m(%d)",xq[i1]);//�������ȡ��ʽ
		}
	}
	printf("\n"); 
	printf("\n��ӭ�´��ٴ�ʹ��!\n");//����
	_getch();
	return 0;
}

void panduan(int b[N],int f)//�����Ƹ�ֵ
{
	int i;
	i=f;
	if(b[f]==0)//��1
		b[f]=1;
	else//��λ
	{
		b[f]=0;
		panduan(b,--i);
	} 
}

int tkh (char sz[N],char ccu[N],int icu[N],int h0)//�ּ����㺯��
{
	int i,j,h,s,kh=0,wz[N],a; 
	char xs1[N],ckh[N];//xs1�������������ڵ��ַ� ckh�����������š�
	s=strlen(sz);
	for(i=0;i<s;i++)
		if(sz[i]=='(' || sz[i]==')')//�ж�����
		{
			wz[kh]=i;//�洢����λ��
			ckh[kh]=sz[i];//�洢��������
			kh++;
		}
		if(kh==0)
			return fkh(sz,ccu,icu,h0);//��������ţ�ֱ������
		else
		{
			for(i=0;i<kh;i++)
				if(ckh[i]==')')//�ҵ���һ����
			break;
			for(j=wz[i-1]+1,h=0;j<wz[i];j++,h++)//�洢���ڼ������е�����
				xs1[h]=sz[j]; 
			xs1[h]='\0';
			a=fkh(xs1,ccu,icu,h0);//�������ڼ����ŵ�ʽ�ӣ��õ����
			if(a==1)//�жϲ��洢���
				sz[wz[i-1]]=1;
			else
				sz[wz[i-1]]=-2;
			for(j=wz[i-1]+1;j<s+wz[i-1]-wz[i];j++)//�����ź�����ǰ��
				sz[j]=sz[j+wz[i]-wz[i-1]];
			sz[j]='\0'; 
			return tkh(sz,ccu,icu,h0);//ѭ��ִ��
		}
}

int fkh(char sz[N],char ccu[N],int icu[N],int h0)//�����㺯��
{
	int i,h=0,j=0,j1=0,j2=0,j3=0,j4=0,j5=0,i1,i2,p1=-1,p2=-1,s;
	char dt[N];
	s=strlen(sz);
	if(s==1)
		if(sz[0]==-2)//�ж��Ƿ������һ��
			return 0;
		else
			return 1;//1����sz[0]��ֵ
	else
	{ 
		for(i=0;i<s-j;i++)//�ȴ����
			if(sz[i]=='!')
			{ 
				for(i1=0;i1 <h0;i1++)
					if(sz[i+1]==ccu[i1])//��������ֵ����P1
						p1=icu[i1];
				if(sz[i+1]==-2)//�����ǰ��������0����P1����0
					p1=0; 
				if(p1==-1)//��������֣�ֱ�Ӹ�P1
					p1=sz[i+1]; 
				dt[j+2] =! p1;//������
				sz[i]=j+2;
				j++;
				p1=0;
				for(i1=i+1;i1<s-j;i1++)
					sz[i1]=sz[i1+1];//������ʽ��ǰ��һ��
			}
		p1=-1; 
		j1=j; 
		for(i=0;i<s-j1-2*j2;i++)//������
			if(sz[i]=='&')
			{ 
				for(i1=0;i1<h0;i1++)
				{ 
					if(sz[i-1]==ccu[i1])//��������ֵ����P1
						p1=icu[i1];
					if(sz[i+1]==ccu[i1])//��������ֵ����P2
						p2=icu[i1];
				}
				for(i2=2;i2<j+2;i2++) 
				{
					if(sz[i-1]==i2)//���Ϊǰ���������������ֵ����P1
						p1=dt[i2]; 
					if(sz[i+1]==i2)//���Ϊǰ���������������ֵ����P2
						p2=dt[i2];
				}
				if(sz[i-1]==-2)//�����ǰ��������0����P1����0
				p1=0; 
				if(sz[i+1]==-2)//�����ǰ��������0����P2����0
					p2=0;
				if(p1==-1)//��������֣�ֱ�Ӹ�P1
					p1=(int)(sz[i-1]);
				if(p2==-1)//��������֣�ֱ�Ӹ�P2
					p2=(int)(sz[i+1]); 
				dt[j+2]=p1 && p2;//������
				sz[i-1]=j+2;
				j++;
				j2++;
				p1=-1;
				p2=-1; 
				for(i1=i;i1<s-j1-2*j2;i1++)//������ʽ��ǰ������
					sz[i1]=sz[i1+2];
				i=i-1;
			}
		for(i=0;i<s-j1-2*j2-2*j3;i++)//�����
			if(sz[i]=='|')
			{
				for(i1=0;i1<h0;i1++)
				{ 
					if(sz[i-1]==ccu[i1])//��������ֵ����P1
						p1=icu[i1];
					if(sz[i+1]==ccu[i1])//��������ֵ����P2
						p2=icu[i1];
				}
				for(i2=2;i2<j+2;i2++) 
				{
					if(sz[i-1]==i2)//���Ϊǰ���������������ֵ����P1
						p1=dt[i2];
					if(sz[i+1]==i2)//���Ϊǰ���������������ֵ����P2
						p2=dt[i2];
				}
				if(sz[i-1]==-2)//�����ǰ��������0����P1����0
					p1=0; 
				if(sz[i+1]==-2)//�����ǰ��������0����P2����0
					p2=0;
				if(p1==-1)//��������֣�ֱ�Ӹ�P1
					p1=sz[i-1];
				if(p2==-1)//��������֣�ֱ�Ӹ�P2
					p2=sz[i+1];
				dt[j+2]=p1 || p2;//������
				sz[i-1]=j+2;
				j++;
				j3++;
				p1=-1;
				p2=-1; 
				for(i1=i;i1<s-j1-2*j2-2*j3;i1++)//������ʽ��ǰ������
					sz[i1]=sz[i1+2];
				i--; 
			}
		for(i=0;i<s-j1-2*j2-2*j3-2*j4;i++)//�����̺�
			if(sz[i]=='^')
			{
				for(i1=0;i1<h0;i1++)
				{ 
					if(sz[i-1]==ccu[i1])//��������ֵ����P1
						p1=icu[i1];
					if(sz[i+1]==ccu[i1])//��������ֵ����P2
						p2=icu[i1];
				}
				for(i2=2;i2<j+2;i2++) 
				{
					if(sz[i-1]==i2)//���Ϊǰ���������������ֵ����P1
						p1=dt[i2];
					if(sz[i+1]==i2)//���Ϊǰ���������������ֵ����P2
						p2=dt[i2];
				}
				if(sz[i-1]==-2)//�����ǰ��������0����P1����0
	   				p1=0; 
				if(sz[i+1]==-2)//�����ǰ��������0����P2����0
					p2=0;
				if(p1==-1)//��������֣�ֱ�Ӹ�P1
	  				p1=sz[i-1];
				if(p2==-1)//��������֣�ֱ�Ӹ�P2
					p2=sz[i+1];
				dt[j+2] =! p1 || p2;//�̺�����
				sz[i-1]=j+2;
				j++;
				j4++;
				p1=-1;
				p2=-1; 
				for(i1=i;i1<s-j1-2*j2-2*j3-2*j4;i1++)//������ʽ��ǰ������
					sz[i1]=sz[i1+2];
				i--; 
			}
		for(i=0;i<s-j1-2*j2-2*j3-2*j4-2*j5;i++)//�����ֵ
			if(sz[i]=='~')
			{
				for(i1=0;i1<h0;i1++)
				{ 
					if(sz[i-1]==ccu[i1])//��������ֵ����P1
						p1=icu[i1];
					if(sz[i+1]==ccu[i1])//��������ֵ����P2
						p2=icu[i1];
				}
				for(i2=2;i2<j+2;i2++) 
				{
					if(sz[i-1]==i2)//���Ϊǰ���������������ֵ����P1
						p1=dt[i2];
					if(sz[i+1]==i2)//���Ϊǰ���������������ֵ����P2
						p2=dt[i2];
				}
				if(sz[i-1]==-2)//�����ǰ��������0����P1����0
					p1=0; 
				if(sz[i+1]==-2)//�����ǰ��������0����P2����0
					p2=0;
				if(p1==-1)//��������֣�ֱ�Ӹ�P1
					p1=sz[i-1];
				if(p2==-1)//��������֣�ֱ�Ӹ�P2
					p2=sz[i+1];
				dt[j+2]=(!p1 || p2) && (!p2 || p1);//��ֵ����
				sz[i-1]=j+2;
				j++;
				j5++;
				p1=-1;
				p2=-1; 
				for(i1=i;i1<s-j1-2*j2-2*j3-2*j4-2*j5;i1++)//������ʽ��ǰ������
					sz[i1]=sz[i1+2];
				i--; 
			}
		return dt[j+1];//���ؽ��
    }
}
