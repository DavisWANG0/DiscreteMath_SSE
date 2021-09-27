#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef struct Node//霍夫曼树的节点类
{
    int weight;//结点的频数 
    Node *lchild,*rchild;//结点的左右孩子
}Node;
bool CompareNode(Node *p,Node *q)//即以vector中node结点weight值升序排序
{
    return p->weight<q->weight;
}
Node* BuildHuffmanTree(vector<Node*> HuffmanTree)//构造霍夫曼树，返回根结点指针
{
    while(HuffmanTree.size()>1)//HuffmanTree森林中树个数大于1时循环进行合并
    {
        sort(HuffmanTree.begin(),HuffmanTree.end(),CompareNode);//根据频数的大小对结点进行排序 
        Node *first=HuffmanTree[0];//取频数最小的结点 
        Node *second=HuffmanTree[1];//取频数第二小的结点 
        Node *merge=new Node;//合并上面两个树
        merge->weight=first->weight+second->weight;//合并结点时要将两个结点的权值相加 
        merge->lchild=first;merge->rchild=second;
        vector<Node*>::iterator iter;
        iter=HuffmanTree.erase(HuffmanTree.begin(),HuffmanTree.begin()+2);
		//从森林中删除频数最小的两个节点first和second
        HuffmanTree.push_back(merge);//向森林中添加合并后的merge树
    }
    return HuffmanTree[0];//返回构造好的根节点
}
void PrintHuffman(Node *node,vector<int> HuffmanCode)//用回溯法来打印编码
{
    if(node->lchild==NULL && node->rchild==NULL)
    {
        cout<<node->weight<<": ";//若走到叶子节点，则迭代打印HuffmanCode中存的频数 
        for(vector<int>::iterator iter=HuffmanCode.begin();iter!=HuffmanCode.end();iter++) cout<<*iter;
        cout<<endl;
        return;
    }
    else
    {
        HuffmanCode.push_back(0);//遇到左子树时给HuffmanCode中加一个0
        PrintHuffman(node->lchild,HuffmanCode);
        HuffmanCode.pop_back();//回溯，删除刚刚加进去的1
        HuffmanCode.push_back(1);//遇到右子树时给HuffmanCode中加一个1
        PrintHuffman(node->rchild,HuffmanCode);
        HuffmanCode.pop_back();//回溯，删除刚刚加进去的0
    }
}

int main()
{
    vector<Node*> HuffmanTree;//存放Node结点的vector容器HuffmanTree
    int n;
	cout<<"请输入节点个数(必须是正整数):";
	cin>>n;
	cout<<"请输入节点频数(以空格分隔):";
    for(int i=0;i<n;i++) 
	{
		Node *temp=new Node;//构造新的结点 
		cin>>temp->weight;
        temp->lchild=temp->rchild = NULL;
        HuffmanTree.push_back(temp);//将新的节点插入到容器HuffmanTree中
	}
    Node *root=BuildHuffmanTree(HuffmanTree);//构造霍夫曼树，并用root指针记录返回的根结点
    vector<int> HuffmanCode;
    cout<<endl<<"对应的Huffman编码如下："<<endl;
    PrintHuffman(root,HuffmanCode);
    system("pause"); 
    return 0; 
}
