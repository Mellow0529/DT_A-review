#include <iostream>
#include <stack>
#include <exception>


template <class Type> 
class CQueue
{
public:
	CQueue(void);
	~CQueue(void);

	// 在队列末尾添加一个结点
	void appendTail(const Type& node);

	// 删除队列的头结点
	Type deleteHead();

private:
	std::stack<Type> stack1;
	std::stack<Type> stack2;
};

template <class Type>
CQueue<Type>::CQueue(void)
{
}

template <class Type>
CQueue<Type>::~CQueue(void)
{
}

template <class Type>
void CQueue<Type>::appendTail(const Type& node)
{
	stack1.push(node);
}

template <class Type>
Type CQueue<Type>::deleteHead()
{
	while (!stack1.empty())
	{
		stack2.push(stack1.top());
		stack1.pop();
	}
	Type node = stack2.top();
	stack2.pop();
	while (!stack2.empty())
	{
		stack1.push(stack2.top());
		stack2.pop();
	}
	return node;
}


// ====================测试代码====================
void Test(char actual, char expected)
{
	if (actual == expected)
		std::cout << "Test passed." << std::endl;
	else
		std::cout << "Test FAILED." << std::endl;
}

#if 0
int main(int argc, char* argv[])
{
	CQueue<char> queue;

	queue.appendTail('a');
	queue.appendTail('b');
	queue.appendTail('c');

	char head = queue.deleteHead();
	Test(head, 'a');

	head = queue.deleteHead();
	Test(head, 'b');

	queue.appendTail('d');
	head = queue.deleteHead();
	Test(head, 'c');

	queue.appendTail('e');
	head = queue.deleteHead();
	Test(head, 'd');

	head = queue.deleteHead();
	Test(head, 'e');

	return 0;
}
#endif
