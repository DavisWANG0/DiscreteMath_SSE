#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=1e5;//最大值
struct edge
{
	int s;//边的起始顶点start 
	int e;//边的终端顶点end
	int w;//边权值weight
	bool operator < (const edge &a)
	{
		return w<a.w;
	}
};
edge temp[maxn];//临时数组存储边
int UFset[maxn];//并查集数组，记录点是否进入生成树 
edge tree[maxn];//最小生成树
int n,m;//n个顶点，m条边
int cnt;
//统计当前生成树结点的个数
//若最终cnt小于n，则生成失败
int sum;//最小生成树权值总和
void print()
{
	//打印最小生成树函数
	cout<<"最小生成树的权值总和为："<<sum<<endl;
	cout<<"连通的边如下："<<endl;
	for(int i=1;i<=cnt;i++) 
	{
		cout<<tree[i].s<<" "<<tree[i].e<<"边权值为"<<tree[i].w<<endl;
	}
}
void Kruskal()
{
	for(int i=1;i<=n;i++) UFset[i]=i;
	//初始化并查集数组，每一个顶点的祖先为它自己。相当于n个连通分量 
	cnt=0;sum=0;
	sort(temp,temp+m);//调用快排，将边按权值由小到大排列
	int v1,v2;
	for(int i=0;i<=m-1;i++)//从小到大遍历边 
	{
		v1=UFset[temp[i].s];//v1是当前权值最小边的起点的祖先 
		v2=UFset[temp[i].e];//v2是当前权值最小边的终点的祖先 
		if(v1!=v2)
		//若两个点祖先不同，说明两个顶点处在不同的连通分量之中
		//连起来不会形成回路，所以可以相连 
		{
			cnt++;//更新当前生成树结点的个数
			tree[cnt].s=temp[i].s;tree[cnt].e=temp[i].e;tree[cnt].w=temp[i].w;
			//这个顶点并入生成树之中 
			for(int j=1;j<=n;j++)//更新并查集
			{
				//合并v1和v2的两个分量，即两个集合统一编号
				if(UFset[j]==v2) UFset[j]=v1;//默认集合祖先为v2的改为v1
			}
			sum+=tree[cnt].w;//更新生成树大小 
		}
	}
	//结束双层for循环之后得到tree即是最小生成树。
	print();
}
int main(){
	cout<<"请输入所求图的顶点数目和边的数目(以空格分隔各个数):";
	cin>>n>>m;
	int u,v,w;
	cout<<"请输入两条边的节点序号以及它们的权值(以空格分隔各个数):\n";
	for(int i=0;i<=m-1;i++)
	{
		cin>>u>>v>>w;
		temp[i].s=u;temp[i].e=v;temp[i].w=w;
	}
	Kruskal();
	system("pause");
	return 0;
}

