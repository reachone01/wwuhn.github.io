// insert�򵥰� ��������ת����
// 259 ��ת������insert��ʵ�֣�insertʵ�ֶ�̬ƽ��
// 468 ������
// https://visualgo.net/zh/bst
#if 0 //insert�򵥰� ��������ת���� https://www.bilibili.com/video/av75227504?p=29
#include <iostream>
#include <string>
using namespace std;

template <class Comparable>
class RedBlackTree;

template <class Comparable>
class RedBlackNode;

template <class Comparable>
class RedBlackTree
{
public:
	RedBlackTree(const Comparable& negInf);
	enum{RED,BLACK};
	~RedBlackTree();
	void insert(const Comparable& x);
	typedef RedBlackNode<Comparable> Node;
//private:  // for test
	Node* header;
	Node* nullNode;
	
	Node* current;
	Node* parent;
	Node* grand;
	Node* great;
	void rotateWithLeftChild(Node* &k2) const;
	void rotateWithRightChild(Node* &k1) const;
	void doubleRotateWithLeftChild(Node* &k3) const;
	void doubleRotateWithrightChild(Node* &k4) const;
};

template <class Comparable>
class RedBlackNode
{
public: // for test
	Comparable    element;
	RedBlackNode* left;
	RedBlackNode* right;
	int           color;
	
	RedBlackNode(const Comparable& theElement = Comparable(),
				RedBlackNode* lt=NULL,
				RedBlackNode* rt=NULL,
				int c=RedBlackTree<Comparable>::BLACK)
				:element(theElement),left(lt),right(rt),color(c){}
	friend class RedBlackTree<Comparable>;
};

template <class Comparable>
RedBlackTree<Comparable>:: RedBlackTree(const Comparable& negInf)
{
	nullNode = new Node();
	nullNode->left = nullNode->right=nullNode;
	header=new Node(negInf);
	header->left=header->right=nullNode;
}

template <class comparable>
RedBlackTree<comparable>::~RedBlackTree()
{
	delete nullNode;
	delete header; 
}

class DSException
{
public:
	DSException(const string & msg = ""):message(msg){}
	virtual ~DSException(){}
	virtual string toString() const
	{
		return "Exception " + string(": ") + what();
	}
	virtual string what() const
	{
		return message;
	}
private:
	string message;
};

class DuplicateItemException: public DSException
{
public:
	DuplicateItemException(const string& msg = "") : DSException(msg){}
};					

template <class Comparable>
void RedBlackTree<Comparable>::insert(const Comparable& x)
{
	current=parent=grand=header;
	nullNode->element = x;
	while(current->element != x)
	{
		great = grand, grand = parent; parent = current;
		current = x < current->element ? current->left : current->right;
	}
	if(current != nullNode)
		throw DuplicateItemException();

	current = new Node(x,nullNode,nullNode);
	if(x < parent->element)
		parent->left = current;
	else
		parent->right = current;
	// ��Ҫ�Զ���̬ƽ����Ǻ����
	// �²���Ľڵ��Ǻ�ɫ��
	// �²�������ⲿ���ӣ��󣩣�������ת��������ڲ����ӣ��ң�����˫��ת
}

template <class Comparable>
void RedBlackTree<Comparable>::rotateWithLeftChild(Node* &k2) const
{
	Node* k1=k2->left;
	k2->left=k1->right;
	k1->right=k2;
	k2=k1; //k1�����Ǹ�
}

template <class Comparable>
void RedBlackTree<Comparable>::rotateWithRightChild(Node* &k1) const
{
	Node* k2=k1->right;
	k1->right = k2->left;
	k2->left=k1;
	k1=k2;
}

template <class Comparable>  // ����ڲ�����ڵ����, ���䵥���ƶ��ǲ���������ģ����Ǿ�����˫��ת
// ������k1Ϊ��, k1��k2������ת;
// Ȼ����k3Ϊ��, k3����ת֮���k1������ת;
void RedBlackTree<Comparable>::doubleRotateWithLeftChild(Node* &k3) const
{
	rotateWithRightChild(k3->left);
	rotateWithLeftChild(k3);
}

template <class Comparable>
void RedBlackTree<Comparable>::doubleRotateWithrightChild(Node* &k4) const
{
	rotateWithLeftChild(k4->right);
	rotateWithRightChild(k4);
}
/*
-��
  \
  30
  / \
  15  70
   \
    20
*/

int main()
{
	const int NEG_INF = -99999;
	RedBlackTree<int> t(NEG_INF);
#if 0
	t.insert(30);
	t.insert(15);
	t.insert(70);
	t.insert(20);
	cout<< t.header->right->element<<endl;
	cout<< t.header->right->left->element<<endl;
	cout<< t.header->right->right->element<<endl;
	cout<< t.header->right->left->right->element<<endl;
	cout<<"����ת"<<endl;
	t.rotateWithLeftChild(t.header->right);
/*
-��
  \
  30
  / \
  15  70
   \
    20
*/
	
/*
-��
  \
  15
    \
     30
	/  \
   20   70
*/

	cout<<t.header->right->element<<endl;
	cout<<t.header->right->right->left->element<<endl;

	cout<<"����ת"<<endl;
	t.rotateWithRightChild(t.header->right);
	cout<< t.header->right->element<<endl;
	cout<< t.header->right->left->element<<endl;
	cout<< t.header->right->right->element<<endl;
	cout<< t.header->right->left->right->element<<endl;
#else
	t.insert(12);
	t.insert(16);
	t.insert(8);
	t.insert(10);
	t.insert(4);
	t.insert(14);
	t.insert(2);
	t.insert(6);
	t.insert(5);
/*
	   12
	  /  \
	8     16
	/\    /
   4  10 14
  / \
  2  6
     /
	 5
*/
	cout<<t.header->right->left->element<<endl;
	t.doubleRotateWithLeftChild(t.header->right->left);
	cout<<t.header->right->left->element<<endl;
/*
	   12
	  /  \
	6     16
	/\    /
   4  8  14
  / \  \
  2  5  10
*/
#endif
	cout<<"OK"<<endl;
    system("pause");
	return 0;
}
/*
30
15
70
20
����ת
15
20
����ת
30
15
70
20
OK
*/
#endif


# if 0 // -----------------------------------------------��ת������insert��ʵ�֣�insertʵ�ֶ�̬ƽ��
#include <iostream>
#include <string>
using namespace std;

template <class Comparable>
class RedBlackTree;

template <class Comparable>
class RedBlackNode;

template <class Comparable>
class RedBlackTree
{
public:
	RedBlackTree(const Comparable& negInf);
	enum{RED,BLACK};
	~RedBlackTree();
	void insert(const Comparable& x);
	typedef RedBlackNode<Comparable> Node;
//private: // for test
	Node* header;
	Node* nullNode;
	
	Node* current;
	Node* parent;
	Node* grand;
	Node* great;
	void rotateWithLeftChild(Node* &k2) const;
	void rotateWithRightChild(Node* &k1) const;
	void doubleRotateWithLeftChild(Node* &k3) const;
	void doubleRotateWithrightChild(Node* &k4) const;
	void handleReorient(const Comparable& item);
	
	RedBlackNode<Comparable>* rotate(const Comparable& item, Node* parent) const;
};

template <class Comparable>
class RedBlackNode
{
public: // for test
	Comparable element;
	RedBlackNode* left;
	RedBlackNode* right;
	int color;
	
	RedBlackNode(const Comparable& theElement = Comparable(),
				RedBlackNode* lt=NULL,
				RedBlackNode* rt=NULL,
				int c=RedBlackTree<Comparable>::BLACK)
				:element(theElement),left(lt),right(rt),color(c){}
	friend class RedBlackTree<Comparable>;
};

template <class Comparable>
RedBlackTree<Comparable>:: RedBlackTree(const Comparable& negInf)
{
	nullNode = new Node();
	nullNode->left = nullNode->right=nullNode;
	header=new Node(negInf);
	header->left=header->right=nullNode;
}

template <class comparable>
RedBlackTree<comparable>::~RedBlackTree()
{
	delete nullNode;
	delete header; 
}

class DSException
{
public:
	DSException(const string & msg = ""):message(msg){}
	virtual ~DSException(){}
	virtual string toString() const
	{
		return "Exception " + string(": ") + what();
	}
	virtual string what() const
	{
		return message;
	}
private:
	string message;
};

class DuplicateItemException: public DSException
{
public:
	DuplicateItemException(const string& msg = "") : DSException(msg){}
};
						

template <class Comparable>
void RedBlackTree<Comparable>::insert(const Comparable& x)
{
	current=parent=grand=header;
	nullNode->element = x;
	while(current->element != x)
	{
		great = grand, grand = parent; parent = current;
		current = x < current->element ? current->left : current->right;

		if(current->left->color == RED && current->right->color == RED)
			handleReorient(x);

	}
	if(current != nullNode)
		throw DuplicateItemException();

	current = new Node(x,nullNode,nullNode);
	if(x < parent->element)
		parent->left = current;
	else
		parent->right = current;
	// ��Ҫ�Զ���̬ƽ����Ǻ����
	// �²���Ľڵ��Ǻ�ɫ��
	// �²�������ⲿ���ӣ��󣩣�������ת��������ڲ����ӣ��ң�����˫��ת
	handleReorient(x);
}
template <class Comparable>
void RedBlackTree<Comparable>:: handleReorient(const Comparable& item)
{
	// ��ɫ
	current->color=RED;
	current->left->color=BLACK;
	current->right->color=BLACK;

	if(parent->color == RED)
	{
		grand->color=RED;
		if(item < grand->element != item < parent->element) // �ڲ����ӣ��ң�
			parent = rotate(item,grand); // ��һ����ת
		current = rotate(item,great);
		current->color = BLACK;		
	}
	header->right->color = BLACK;

}

template <class Comparable>
RedBlackNode<Comparable>* void RedBlackTree<Comparable>::rotate(const Comparable& item, Node* parent) const
{
	if(item < parent->element)
	{
		item < parent->left->element ?
			rotateWithLeftChild(parent->left):
			rotateWithRightChild(parent->left);
		return parent->left;
	}
	else
	{
		item < parent->right->element ?
			rotateWithLeftChild(parent->right) :
			rotateWithRightChild(parent->right);
		return parent->right;
	}
	
}

template <class Comparable>
void RedBlackTree<Comparable>::rotateWithLeftChild(Node* &k2) const
{
	Node* k1=k2->left;
	k2->left=k1->right;
	k1->right=k2;
	k2=k1; //k1�����Ǹ�
}
template <class Comparable>
void RedBlackTree<Comparable>::rotateWithRightChild(Node* &k1) const
{
	Node* k2=k1->right;
	k1->right = k2->left;
	k2->left=k1;
	k1=k2;
}

template <class Comparable>
void RedBlackTree<Comparable>::doubleRotateWithLeftChild(Node* &k3) const
{
	rotateWithRightChild(k3->left);
	rotateWithLeftChild(k3);
}

template <class Comparable>
void RedBlackTree<Comparable>::doubleRotateWithrightChild(Node* &k4) const
{
	rotateWithLeftChild(k4->right);
	rotateWithRightChild(k4);
}

int main()
{
	const int NEG_INF = -99999;
	RedBlackTree<int> t(NEG_INF);

	t.insert(50);
	t.insert(40);
	t.insert(30);
	cout<<t.header->right->element<<endl; // 40

 system("pause");
	return 0;
}


#endif

#if 1   // -----------------------------����������������������������--------------������

#include <iostream>
#include <string>
using namespace std;

template <class Comparable>
class RedBlackTree;

template <class Comparable>
class RedBlackNode;

template <typename Object>
class Cref;

template <class Comparable>
class RedBlackTree										// ReadBlackTree��
{
public:
	RedBlackTree(const Comparable& negInf);
	enum{RED,BLACK};
	~RedBlackTree();
	void insert(const Comparable& x);

    bool isEmpty() const;
    void makeEmpty();

    Cref<Comparable> find(const Comparable & x) const; // ����һ����ָ���װ�����ã���Ϊ���ò���Ϊ��
    Cref<Comparable> findMin() const;
    Cref<Comparable> findMax() const;
	typedef RedBlackNode<Comparable> Node;
private:
	Node* header;			//ָ��������ͷ(α���ڵ�)
	Node* nullNode;
	//��insertʱʹ�������ĸ�ָ��
    Node *current;  // ��ǰ�ڵ�
    Node *parent;   // ���ڵ�
    Node *grand;    // �游�ڵ�
    Node *great;    // ���游�ڵ�
	void rotateWithLeftChild(Node* &k2) const;	// ����ת(�����Һ���)
	void rotateWithRightChild(Node* &k1) const;	// ����ת(��������)
	void doubleRotateWithLeftChild(Node* &k3) const;
	void doubleRotateWithrightChild(Node* &k4) const;
	// �Զ�����: [1]����Ⱦɫ; [2]:�Զ���ת
	void handleReorient(const Comparable& item);
	// �Զ���ת����(������ת�Ժ��theParent�����ĸ�)
	RedBlackNode<Comparable>* rotate(const Comparable& item, Node* parent) const;
    
    void reclainMemory(Node *t) const;			// �ݹ�ɾ�����нڵ�
};

template <class Comparable>
class RedBlackNode												// RedBlackNode��
{
public:
	Comparable    element;
	RedBlackNode* left;
	RedBlackNode* right;
	int           color;
	
	RedBlackNode(const Comparable& theElement = Comparable(),
				RedBlackNode* lt=NULL,
				RedBlackNode* rt=NULL,
				int c=RedBlackTree<Comparable>::BLACK)
				:element(theElement),left(lt),right(rt),color(c){}
	friend class RedBlackTree<Comparable>;
};

template <class Comparable>
RedBlackTree<Comparable>:: RedBlackTree(const Comparable& negInf)		// RedBlackTree���캯��
{
	nullNode = new Node();
	//nullNode �������ӽڵ㶼ָ���Լ�
	nullNode->left = nullNode->right=nullNode;
	header=new Node(negInf);
	header->left=header->right=nullNode;
}

template <class comparable>
RedBlackTree<comparable>::~RedBlackTree()								// RedBlackTree��������
{
    if (!isEmpty())
        makeEmpty();
	delete nullNode;
	delete header; 
}

class DSException														// DSException��
{
public:
	DSException(const string & msg = ""):message(msg){}
	virtual ~DSException(){}
	virtual string toString() const
	{
		return "Exception " + string(": ") + what();
	}
	virtual string what() const
	{
		return message;
	}
private:
	string message;
};

class DuplicateItemException: public DSException
{
public:
	DuplicateItemException(const string& msg = "") : DSException(msg){}
};					
class NullPointerException : public DSException
{
public:
    NullPointerException(const string &_msg = string())
        : DSException(_msg) {}
};

template <class Comparable>
void RedBlackTree<Comparable>::insert(const Comparable& x)				// insert()
{
	current=parent=grand=header;
	nullNode->element = x;
	while(current->element != x)
	{
		// ���游��Ϊ���游, ���׳�Ϊ�游, �Լ���Ϊ����
        // ÿ���ڵ㶼�ɳ�һ��
		great = grand, grand = parent; parent = current;
		current = x < current->element ? current->left : current->right;
		//����1. ���current�ڵ���������ɫ����
		if(current->left->color == RED && current->right->color == RED)
			handleReorient(x);
	}

	if(current != nullNode) // ������а�����ͬ��Ԫ��
		throw DuplicateItemException();

	current = new Node(x,nullNode,nullNode);
	if(x < parent->element)
		parent->left = current;
	else
		parent->right = current;
	// ��Ҫ�Զ���̬ƽ����Ǻ����
	// �²���Ľڵ��Ǻ�ɫ��
	// �²�������ⲿ���ӣ��󣩣�������ת��������ڲ����ӣ��ң�����˫��ת
	// ����2. ����²���Ľڵ��ƻ��˺�ڹ���
	handleReorient(x);
}

// �Զ�ƽ�⺯��:[1]����Ⱦɫ��[2]�Զ���ת
template <class Comparable>
void RedBlackTree<Comparable>:: handleReorient(const Comparable& item)  // handleReorient()
{
	current->color=RED;					// ��current�ڵ�Ⱦ�ɺ�ɫ
	current->left->color=BLACK;			// ��current��left��right�ڵ�Ⱦ�ɺ�ɫ
	current->right->color=BLACK;
	// ���current�ڵ�ĸ��ڵ�Ҳ�Ǻ�� -> ����ת or ˫��ת
	if(parent->color == RED)
	{
		grand->color=RED;		// �����游(үү)����ɫȾ�ɺ�ɫ
		// Ȼ���ж��²���Ľڵ��Ƿ����ڲ�����(�ҽڵ�)?
        // �����, ������һ����ת->����˫��ת
        // ifע��: ����ýڵ�С��үү, С�ڰְ�, �����������ͬʱ����
        // ��˵������үү��������
		if(item < grand->element != item < parent->element) 
			parent = rotate(item,grand); // ��grand(�游)�ڵ������ת
		current = rotate(item,great);	 // ��great(���游)�ڵ������ת
		current->color = BLACK;			 // �ǰ�ڵ�Ϊ��ɫ
	}
	header->right->color = BLACK;		// ���ڵ�����Ǻ�ɫ��
}

template <class Comparable>										//�Զ��жϲ�������ת����
RedBlackNode<Comparable>* RedBlackTree<Comparable>::
	rotate(const Comparable& item, Node* parent) const			// rotate()
{
    if(item < parent->element) //λ��parent��������
    {
        //���Ϊ��, ��˵��parent->left������,����, ���Һ���
        item < parent->left->element ?
        //���parent�����һ������, ����parent->leftΪ��, ����ת
        rotateWithLeftChild( parent->left )  :  // LL
        //���parent�ұ���һ������, ����parent->leftΪ��, ����ת
        rotateWithRightChild( parent->left ) ;  // LR

        return parent->left;     //����������
    }
    else    //λ��������
    {
        //���Ϊ��, ��˵��parent->right������,����ת������, ���Һ���, ����ת
        item < parent->right->element ?
        rotateWithLeftChild( parent->right ) :  // RL
        rotateWithRightChild( parent->right );  // RR

        return parent->right;    // ����������
    }
	
}

template <class Comparable>
void RedBlackTree<Comparable>::rotateWithLeftChild(Node* &k2) const  // ��(��)��ת
{
	Node* k1=k2->left;
	k2->left=k1->right;
	k1->right=k2;
	k2=k1; //k1�����Ǹ�
}

template <class Comparable>
void RedBlackTree<Comparable>::rotateWithRightChild(Node* &k1) const // ��(��)��ת
{
	Node* k2=k1->right;
	k1->right = k2->left;
	k2->left=k1;
	k1=k2;
}

template <class Comparable>
void RedBlackTree<Comparable>::doubleRotateWithLeftChild(Node* &k3) const
{
	rotateWithRightChild(k3->left);
	rotateWithLeftChild(k3);
}

template <class Comparable>
void RedBlackTree<Comparable>::doubleRotateWithrightChild(Node* &k4) const
{
	rotateWithLeftChild(k4->right);
	rotateWithRightChild(k4);
}

template <typename Comparable>
Cref<Comparable> RedBlackTree<Comparable>::find(const Comparable &x) const  // find()
{
    if (isEmpty())
        return Cref<Comparable>();

    nullNode->element = x;
    Node *iter = header->right;

    while (true)
    {
        if (x < iter->element)
            iter = iter->left;
        else if (x > iter->element)
            iter = iter->right;

        else if (iter != nullNode)
            return Cref<Comparable>(iter->element) ;
        else
            return Cref<Comparable>();
    }
}
template <typename Comparable>
Cref<Comparable> RedBlackTree<Comparable>::findMax() const			// findMax()
{
    if (isEmpty())
        return Cref<Comparable>();

    Node *iter = header->right;
    while (iter->right != nullNode)
    {
        iter = iter->right;		// һֱ������
    }

    return Cref<Comparable>(iter->element);
}
template <typename Comparable>
Cref<Comparable> RedBlackTree<Comparable>::findMin() const			// findMin()
{
    if (isEmpty())
        return Cref<Comparable>();

    Node *iter = header->right;
    while (iter->left != nullNode)
    {
        // һֱ������
        iter = iter->left;
    }

    return Cref<Comparable>(iter->element);
}

template <typename Comparable>
bool RedBlackTree<Comparable>::isEmpty() const						// isEmpty()
{
    if (header->right == nullNode)
        return true;
    return false;
}

template <typename Comparable>
void RedBlackTree<Comparable>::makeEmpty()							// makeEmpty()
{
    reclainMemory(header->right);
    header->right = nullNode;
}

template <typename Comparable>
void RedBlackTree<Comparable>::reclainMemory(Node *t) const			// reclainMemory()
{
    //t == t->left��ʱ��, �ǵ�t==nullNodeʱ
    if (t != t->left)
    {
        reclainMemory(t->left);
        reclainMemory(t->right);
        delete t;
    }

}

// һ����ָ���װ�����ã���Ϊ����ʱ���ܷ��ؿգ��������ǲ���Ϊ�յ�
template <typename Object>											// Cref��
class Cref
{
public:
    Cref():obj(NULL) {}
    explicit Cref(const Object &x)
        : obj(& x) {}

    const Object &get() const
    {
        if (isNull())
            throw NullPointerException();
        else
            return * obj;
    }

    bool isNull() const
    {
        if (obj == NULL)
            return true;
        return false;
    }

private:
    const Object * obj;
};

int main()
{
    const int NEG_INF = -999999;
    RedBlackTree<int> tree(NEG_INF);

    tree.insert(50);
    tree.insert(40);
    tree.insert(30);
    tree.insert(10);
    tree.insert(55);
    tree.insert(88);
    tree.insert(200);
    tree.insert(100);
    tree.insert(70);
    tree.insert(80);
    tree.insert(650);

    Cref<int> g = tree.findMin();
    cout << "Min = " << g.get() << endl;
    g = tree.findMax();
    cout << "Max = " << g.get() << endl;

    int searchVal;
	cout<<"��������Ҫ���ҵ�����(����null�������)��";
    while (cin >> searchVal)
    {
        g = tree.find(searchVal);
        if (g.isNull())
            cout << "not found" << endl;
        else
            cout << g.get() << " founded" << endl;
    }

    tree.makeEmpty();
    if (tree.isEmpty())
    {
        cout << "is Empty" << endl;
    }
    else
    {
        cout << "not Empty" << endl;
    }
	system("pause");
    return 0;
}
/*
Min = 10
Max = 650
��������Ҫ���ҵ�����(����null�������)��10
10 founded
200
200 founded
234
not found
null
is Empty
*/
#endif