#include<stdio.h>
#include<iostream>
#include<windows.h>
using namespace std;
int main()
{
	int p=-1,q=-1;
	char s;
	first_place://���� 
	cout<<"***************************************"<<endl; 
	cout<<"**        ��ӭ�����߼��������       **"<<endl;
	cout<<"***************************************"<<endl;
	cout<<endl<<"������P��ֵ��0��1��,�Իس�����:";
	cin>>p;
	if(p!=0 && p!=1)
	{
		cout<<endl<<"P��ֵ��������,����������!";
		Sleep(2000);
		system("cls");//����
		goto first_place;
	}
	cout<<endl<<"������Q��ֵ��0��1��,�Իس�����:";
	cin>>q;
	if(q!=0 && q!=1)
	{
		cout<<endl<<"Q��ֵ��������,����������!";
		Sleep(2000);
		system("cls");//����
		goto first_place;
	}
	printf("  ��ȡ:\n       P/\\Q = %d\n",p && q);//������ 
	printf("  ��ȡ:\n       P\\/Q = %d\n",p || q);//������
	printf("  ����:\n       P->Q = %d\n",(!p) || q);//�̺����㣬����ת��Ϊ������ʽ
	printf("  ˫����:\n       P<->Q = %d\n",((!p) || q) && ((!q) || p));//��ֵ���㣬����ת��Ϊ������ʽ
	second_place:
	cout<<"�Ƿ��������?��y/n��"<<endl;//ѯ���Ƿ��������
	cin>>s; 
	if (s=='y' || s=='n')
	{
		if (s=='y')
		{ 
			system("cls");//����
			goto first_place;//���ض���
		}
		else
		{
			cout<<"��ӭ�´��ٴ�ʹ��!"<<endl;//�˳�
			exit(0);
		}
	}
	else
	{
		cout<<"�������,����������!"<<endl; //����У��
		goto second_place;
	}
	system("pause"); 
	return 0;
}
