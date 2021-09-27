#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef struct Node//���������Ľڵ���
{
    int weight;//����Ƶ�� 
    Node *lchild,*rchild;//�������Һ���
}Node;
bool CompareNode(Node *p,Node *q)//����vector��node���weightֵ��������
{
    return p->weight<q->weight;
}
Node* BuildHuffmanTree(vector<Node*> HuffmanTree)//����������������ظ����ָ��
{
    while(HuffmanTree.size()>1)//HuffmanTreeɭ��������������1ʱѭ�����кϲ�
    {
        sort(HuffmanTree.begin(),HuffmanTree.end(),CompareNode);//����Ƶ���Ĵ�С�Խ��������� 
        Node *first=HuffmanTree[0];//ȡƵ����С�Ľ�� 
        Node *second=HuffmanTree[1];//ȡƵ���ڶ�С�Ľ�� 
        Node *merge=new Node;//�ϲ�����������
        merge->weight=first->weight+second->weight;//�ϲ����ʱҪ����������Ȩֵ��� 
        merge->lchild=first;merge->rchild=second;
        vector<Node*>::iterator iter;
        iter=HuffmanTree.erase(HuffmanTree.begin(),HuffmanTree.begin()+2);
		//��ɭ����ɾ��Ƶ����С�������ڵ�first��second
        HuffmanTree.push_back(merge);//��ɭ������Ӻϲ����merge��
    }
    return HuffmanTree[0];//���ع���õĸ��ڵ�
}
void PrintHuffman(Node *node,vector<int> HuffmanCode)//�û��ݷ�����ӡ����
{
    if(node->lchild==NULL && node->rchild==NULL)
    {
        cout<<node->weight<<": ";//���ߵ�Ҷ�ӽڵ㣬�������ӡHuffmanCode�д��Ƶ�� 
        for(vector<int>::iterator iter=HuffmanCode.begin();iter!=HuffmanCode.end();iter++) cout<<*iter;
        cout<<endl;
        return;
    }
    else
    {
        HuffmanCode.push_back(0);//����������ʱ��HuffmanCode�м�һ��0
        PrintHuffman(node->lchild,HuffmanCode);
        HuffmanCode.pop_back();//���ݣ�ɾ���ոռӽ�ȥ��1
        HuffmanCode.push_back(1);//����������ʱ��HuffmanCode�м�һ��1
        PrintHuffman(node->rchild,HuffmanCode);
        HuffmanCode.pop_back();//���ݣ�ɾ���ոռӽ�ȥ��0
    }
}

int main()
{
    vector<Node*> HuffmanTree;//���Node����vector����HuffmanTree
    int n;
	cout<<"������ڵ����(������������):";
	cin>>n;
	cout<<"������ڵ�Ƶ��(�Կո�ָ�):";
    for(int i=0;i<n;i++) 
	{
		Node *temp=new Node;//�����µĽ�� 
		cin>>temp->weight;
        temp->lchild=temp->rchild = NULL;
        HuffmanTree.push_back(temp);//���µĽڵ���뵽����HuffmanTree��
	}
    Node *root=BuildHuffmanTree(HuffmanTree);//�����������������rootָ���¼���صĸ����
    vector<int> HuffmanCode;
    cout<<endl<<"��Ӧ��Huffman�������£�"<<endl;
    PrintHuffman(root,HuffmanCode);
    system("pause"); 
    return 0; 
}
