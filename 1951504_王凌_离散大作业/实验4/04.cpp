#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=1e5;//���ֵ
struct edge
{
	int s;//�ߵ���ʼ����start 
	int e;//�ߵ��ն˶���end
	int w;//��Ȩֵweight
	bool operator < (const edge &a)
	{
		return w<a.w;
	}
};
edge temp[maxn];//��ʱ����洢��
int UFset[maxn];//���鼯���飬��¼���Ƿ���������� 
edge tree[maxn];//��С������
int n,m;//n�����㣬m����
int cnt;
//ͳ�Ƶ�ǰ���������ĸ���
//������cntС��n��������ʧ��
int sum;//��С������Ȩֵ�ܺ�
void print()
{
	//��ӡ��С����������
	cout<<"��С��������Ȩֵ�ܺ�Ϊ��"<<sum<<endl;
	cout<<"��ͨ�ı����£�"<<endl;
	for(int i=1;i<=cnt;i++) 
	{
		cout<<tree[i].s<<" "<<tree[i].e<<"��ȨֵΪ"<<tree[i].w<<endl;
	}
}
void Kruskal()
{
	for(int i=1;i<=n;i++) UFset[i]=i;
	//��ʼ�����鼯���飬ÿһ�����������Ϊ���Լ����൱��n����ͨ���� 
	cnt=0;sum=0;
	sort(temp,temp+m);//���ÿ��ţ����߰�Ȩֵ��С��������
	int v1,v2;
	for(int i=0;i<=m-1;i++)//��С��������� 
	{
		v1=UFset[temp[i].s];//v1�ǵ�ǰȨֵ��С�ߵ��������� 
		v2=UFset[temp[i].e];//v2�ǵ�ǰȨֵ��С�ߵ��յ������ 
		if(v1!=v2)
		//�����������Ȳ�ͬ��˵���������㴦�ڲ�ͬ����ͨ����֮��
		//�����������γɻ�·�����Կ������� 
		{
			cnt++;//���µ�ǰ���������ĸ���
			tree[cnt].s=temp[i].s;tree[cnt].e=temp[i].e;tree[cnt].w=temp[i].w;
			//������㲢��������֮�� 
			for(int j=1;j<=n;j++)//���²��鼯
			{
				//�ϲ�v1��v2����������������������ͳһ���
				if(UFset[j]==v2) UFset[j]=v1;//Ĭ�ϼ�������Ϊv2�ĸ�Ϊv1
			}
			sum+=tree[cnt].w;//������������С 
		}
	}
	//����˫��forѭ��֮��õ�tree������С��������
	print();
}
int main(){
	cout<<"����������ͼ�Ķ�����Ŀ�ͱߵ���Ŀ(�Կո�ָ�������):";
	cin>>n>>m;
	int u,v,w;
	cout<<"�����������ߵĽڵ�����Լ����ǵ�Ȩֵ(�Կո�ָ�������):\n";
	for(int i=0;i<=m-1;i++)
	{
		cin>>u>>v>>w;
		temp[i].s=u;temp[i].e=v;temp[i].w=w;
	}
	Kruskal();
	system("pause");
	return 0;
}

