#include <iostream>
using namespace std;

class Tree
{
	class Element
	{
		int Data;
		Element* pLeft;
		Element* pRight;
	public:
		Element(int Data, Element* pLeft = nullptr, Element* pRight = nullptr)
			:Data(Data), pLeft(pLeft), pRight(pRight)
		{
			cout << "EConstructor:\t" << this << endl;
		}
		~Element()
		{
			cout << "EDestructor:\t" << this << endl;
		}
		friend class Tree;
	}*Root;
public:
	Element* getRoot()
	{
		return Root;
	}
	Tree() :Root(nullptr)
	{
		cout << "TConstructor:\t" << this << endl;
	}
	~Tree()
	{
		cout << "TDectructor:\t" << this << endl;
	}
	void insert(int Data, Element* Root)
	{
		if (this->Root == nullptr)this->Root = new Element(Data);
		if (Root == nullptr)return;
		if (Data < Root->Data)
		{
			if (Root->pLeft == nullptr)Root->pLeft = new Element(Data);
			else insert(Data, Root->pLeft);
		}
		else
		{
			if (Root->pRight == nullptr)Root->pRight = new Element(Data);
			else insert(Data, Root->pRight);
		}
	}
	int minValue(Element* Root)
	{
		if (Root == nullptr)return 0;
		return Root->pLeft == nullptr ? Root->Data : minValue(Root->pLeft);
		/*if (Root->pLeft == nullptr)return  Root->Data;
		else return minValue(Root->pLeft);*/
	}
	int maxValue(Element* Root)
	{
		if (Root == nullptr)return 0;
		return Root->pRight == nullptr ? Root->Data : minValue(Root->pRight);

		/*if (Root->pRight == nullptr)return Root->Data;
		else return maxValue(Root->pRight);*/
	}
	int Sum(Element* Root)
	{
		 return Root==nullptr?0:Sum(Root->pLeft) + Sum(Root->pRight) + Root->Data;
	}
	int Count(Element* Root)
	{
		return Root == nullptr ? 0 : Count(Root->pLeft) + Count(Root->pRight) + 1;
	}
	void print(Element* Root)
	{
		if (Root == nullptr)return;
		print(Root->pLeft);
		cout << Root->Data << "\t";
		print(Root->pRight);
	}
};

void main() {
	setlocale(LC_ALL, "Russian");
	int n;
	cout << "������� ���������� ������:"; cin >> n;
	Tree  tree;
	for (int i = 0; i < n; i++)
	{
		tree.insert(rand() % 100,tree.getRoot());
	}
	tree.print(tree.getRoot());
	cout << endl;
	cout << "����������� �������� � ������:" << tree.minValue(tree.getRoot()) << endl;
	cout << "������������ �������� � ������:" << tree.maxValue(tree.getRoot()) << endl;
	cout << "����� ��������� ������:\t\t" << tree.Sum(tree.getRoot()) << endl;
	cout << "���������� ��������� ������:   " << tree.Count(tree.getRoot()) << endl;
}