#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>


// 1. Container(�����̳�)
//- ���� Ÿ���� �����͸� ����/������ �������� ������� Ŭ���� ��ü.
//
// case 01. Standard Sequence Container(ǥ�� ������ �����̳�)
//- �����̳��� ���Ұ� �ڽŸ��� ���� ��ġ(����)�� ������ �����̳�
//ex) std::vector, std::deque, std::list - ������ 
// case 02. Standard Associative Container(ǥ�� ���� �����̳�)
//- ����Ǵ� ���Ұ� ���� ������ �ٸ��� Ư�� ���� ���ؿ� ���� �ڵ� ���ĵǴ� �����̳�
//ex) std::set, std::multiset, std::map, std::multimap - ������
//
// case 03. Array-based Container(�迭 ��� �����̳�)
//- ������ ���� ���� �ϳ��� �޸� ������ ����Ǵ� �����̳�
//ex) std::vector, std::deque
// case 04. Node-based Container(��� ��� �����̳�)
//- ������ �ϳ��� �ϳ��� �޸� ������ �����ϴ� �����̳�
//ex) std::list, std::set, std::multiset, std::map, std::multimap

// ###################################################################################
// 2. Iterator(�ݺ���)
//- �����Ϳ� ����ϰ� �����ϸ�, �����̳ʿ� ����� ���Ҹ� ��ȸ�ϰ� �����ϴ� �Ϲ�ȭ�� ����� �����Ѵ�.
//��, �����̳ʿ� �˰����� �ϳ��� �����ϰ� �����ִ� �������̽� ������ �Ѵ�.
//cf) �����̳� ������ ������ Sequence(������)�̶�� �Ѵ�.
//������ ���� �ִ� ������ �ǹ��ϴµ�, �ϳ��� ���۰� �ϳ��� ���� ���´�.
//���⼭ �ݺ��ڴ� �������� �� ���Ҹ� ����Ų��.
//- STL�� ��� �����̳ʴ� �ڽŸ��� �ݺ��ڸ� �����ϴµ�, ��� �Լ� begin()�� end()��
//�������� ���۰� ���� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
//- �������� ���۰� ������ ���� ���� ���Ұ� �ƴ� ���� ǥ��(past-the-end)�ϴ� ���Ҹ� �ǹ��Ѵ�.
//�� begin�� end�� range(����)��� �ϸ�, ���п��� ǥ���ϴ� ����� �����
// half-open range(�ݰ� ����)�� [begin, end)ó�� ǥ���Ѵ�.

// case 01. Input Iterator(�Է� �ݺ���)
//- �� ��ġ�� ���Ҹ� �� ���� ���� �� �ִ� �ݺ���. ex) istream
// case 02. Output Iterator(��� �ݺ���)
//- �� ��ġ�� ���Ҹ� �� ���� �� �� �ִ� �ݺ���. ex) ostream
// case 03. Forward Iterator(������ �ݺ���)
//- �Է�, ��� �ݺ��� ��ɿ� ���������� �̵�(++)�� ������ ���Ҵ�� �� �ִ� �ݺ���
// case 04. Bidirectional Iterator(����� �ݺ���)
//- ������ �ݺ��� ��ɿ� ���������� �̵�(--)�� ������ �ݺ���. ex) std::list, std::set, std::multiset, std::map, std::multimap
// case 05. Random Access Iterator(���� ���� �ݺ���)
//- ����� �ݺ��� ��ɿ� +, -, +=, -=, [] ������ ������ �ݺ��� ex) std::vector, std::deque

// ###################################################################################
// 3. Algorithm(�˰���)
//- STL�� �������� ���Ҹ� ����/����/����/ó���� �������� �˰����̶�� ���� ��Ҹ� �����Ѵ�.
//�� ���� �ݺ���([begin, end))�� �ʿ�� �ϰ�, ��κ��� ������ �ݺ��ڸ� �䱸������ ����� ���� ���� �ݺ��ڸ� �䱸�Ѵ�.

// case 01. Non-modifying Algorithms(���Ҹ� �������� �ʴ� �˰���)
// case 02. Modifying Algorithms(���Ҹ� �����ϴ� �˰���)
// case 03. Removing Algorithms(���� �˰���)
// case 04. Mutating Algorithms(���� �˰���)
// case 05. Sorting Algorithms(���� �˰���)
// case 06. Sorted Range Algorithms(���ĵ� ���� �˰���)
// case 07. Numeric Algorithms(��ġ �˰���)

// ###################################################################################
// 4. Function Object(�Լ� ��ü), Functor
//- Ŭ���̾�Ʈ�� ������ ������ �ٸ� ���� ��ҿ� �ݿ��Ϸ� �� �� ���ȴ�.
//(STL �˰����� �Լ� ��ü, �Լ�, �Լ� ������ ���� ���ڷ� �޾� �˰����� �����ϰ� ���۽�Ų��.)

// ###################################################################################
// 5. Adapter(�����)
//- STL ���� ����� �������̽��� �����ϴµ� ���δ�.

// case 01. Container Adapter(�����̳� �����)
//- std::stack, std::queue, std::priority_queue
// case 02. Iterator Adapter(�ݺ��� �����)
//- std::reverse_iterator, std::back_insert_iterator, std::front_insert_iterator, std::insert_iterator
// case 03. Function Adapter(�Լ� �����)
//- binder(���δ�), negator(������), adapter for pointers to functions(�Լ� ������ �����)

//ex) stack
//- �Ϲ� �����̳ʸ� LIFO(Last-In First-Out) ����� �����̳ʷ� ��ȯ�Ѵ�.
//(empty, size, push_back, pop_back, back, �������̽�(��� �Լ�)�� �����ϴ� �����̳ʸ� ������� �Ѵ�.
//So, Sequence �����̳ʸ� ������� �Ѵ�. Default �����̳ʴ� std::deque �����̳�.)

//ex) reverse_iterator
//- �Ϲ� �ݺ����� ���� ����� �ݴ�� ���۽�Ű�� ������ �ݺ��ڷ� ��ȯ�Ѵ�.

//ex) not2
//- ���� Predicate(������) �Լ� ��ü�� NOT(�ݴ�)�� ��ȯ�Ѵ�.

// ###################################################################################
// 6. Allocator(�Ҵ���)
//- �޸� �Ҵ� ������ ��å(�޸� �Ҵ� ��)�� ĸ��ȭ�� STL ���� ���.
//���ø� Ŭ������ �����Ǿ� �ְ�, ��� �����̳ʴ� �⺻ �Ҵ��ڸ� ����Ѵ�.
//(new�� delete ������ �����ε��ؼ� ����� �� �ֵ��� �Ҵ��ڵ� ���� ������ �� �ִ�.
//So, ���� �����忡 ����ȭ�ǰ� ������ ����� �޸� �Ҵ� ���� �ʿ��ϰų� ����ڰ� �����̳ʿ� �´�
// �޸� �Ҵ� ���� �����ϰų� Ư�� ���� ȯ�濡�� ����ȭ�� �޸� �Ҵ� ���� �����ϴ� � ���ȴ�.)


int main(void)
{
	// ���� ���� �ݺ��ڸ� ���� std::vector �����̳�

	std::vector<int> vec;

	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);

	std::vector<int>::iterator iter = vec.begin();
	std::cout << iter[0] << ' ';	// [] ������
	std::cout << iter[1] << ' ';
	std::cout << iter[2] << '\n';

	iter += 2;	// += ������
	std::cout << *iter << '\n';

	iter = vec.begin();

	std::vector<int>::iterator iter2 = iter + 2;	// + ������
	std::cout << *iter2 << '\n';

	std::cout << "##################################\n";

	// find �˰��� - ������ �ݺ��ڸ� �䱸��.
	iter = find(vec.begin(), vec.end(), 2);
	if (iter != vec.end())
	{
		std::cout << *iter << '\n';
	}

	iter = find(vec.begin(), vec.end(), 5);
	if (iter == vec.end())
	{
		std::cout << "���� ����\n";
	}

	std::cout << "##################################\n";

	// sort �˰��� - ���� ���� �ݺ��ڸ� �䱸��.
	std::vector<int> vec02;
	vec02.push_back(1);
	vec02.push_back(5);
	vec02.push_back(2);
	vec02.push_back(4);
	vec02.push_back(3);

	// �Լ� ��ü std::less, std::greater
	std::sort(vec02.begin(), vec02.end(), std::less<int>());	// ��������(Ascending Order)

	std::vector<int>::iterator iter02 = vec02.begin();
	for (; iter02 != vec02.end(); ++iter02)
	{
		std::cout << *iter02 << ' ';
	}
	std::cout << '\n';

	std::sort(vec02.begin(), vec02.end(), std::greater<int>());	// ��������(Descending Order)

	iter02 = vec02.begin();
	for (; iter02 != vec02.end(); ++iter02)
	{
		std::cout << *iter02 << ' ';
	}
	std::cout << '\n';

	std::cout << "##################################\n";

	// Container Adapter
	std::stack<int, std::vector<int>> stack;	// Default�� std::deque �����̳�

	stack.push(1);
	stack.push(2);
	stack.push(3);

	std::cout << stack.top() << '\n';
	stack.pop();
	std::cout << stack.top() << '\n';
	stack.pop();
	std::cout << stack.top() << '\n';
	stack.pop();

	if (stack.empty() == true)
	{
		std::cout << "stack.empty() == true\n";
	}
	else
	{
		stack.pop();	// ���� ���Ұ� ���µ� pop() �Լ� ȣ���ϸ� Runtime Error �߻�.
	}

	std::cout << "##################################\n";

	iter02 = vec02.begin();
	for (; iter02 != vec02.end(); ++iter02)
	{
		std::cout << *iter02 << ' ';
	}
	std::cout << '\n';

	// Iterater Adapter
	//- ������ �ݺ��ڴ� �ݺ��ڰ� ����Ű�� ���ҿ� ���� ����Ű�� ���� �ٸ���!
	//�ݺ��ڰ� ����Ű�� ������ ���� ������ ���� �����Ѵ�.
	//Because, �������� ����(range)�� �ݰ� ����([begin, end))�̹Ƿ� �˰��� ���� ��
	//������ �ݺ��ڿ� ȣȯ�� �ǵ��� ����Ǿ��� ������!!!
	//	begin(1) end(��)
	// �� 1 2 3 4 5 ��
	// rIterEnd(��) rIter(5)
	std::reverse_iterator<std::vector<int>::iterator> rIter(vec02.end());
	std::reverse_iterator<std::vector<int>::iterator> rIterEnd(vec02.begin());
	// ����, �����̳� ��ü���� ������ �ݺ��ڸ� �����Ѵ�.
	std::vector<int>::reverse_iterator rIter02 = vec02.rbegin();
	std::vector<int>::reverse_iterator rIterEnd02 = vec02.rend();

	if (rIter == rIter02
		&& rIterEnd == rIterEnd02)
	{
		// Iterator Adapter�� �⺻������ �����ϰ� ����.
		std::cout << "rIter == rIter02\n";
		std::cout << "rIterEnd == rIterEnd02\n";
	}

	rIter = vec02.rbegin();
	for (; rIter != vec02.rend(); ++rIter)
	{
		std::cout << *rIter << ' ';
	}
	std::cout << '\n';

	std::cout << "##################################\n";

	std::vector<int> vec03;
	vec03.push_back(1);
	vec03.push_back(2);
	vec03.push_back(3);
	vec03.push_back(4);
	vec03.push_back(5);

	std::vector<int>::iterator normalIter = vec03.begin() + 3;
	std::vector<int>::reverse_iterator reverseIter(normalIter);

	// "--" �����ڸ� ������� �ʰ� "++" �����ڸ����� ������, �������� ��ȸ�� ��� �����ϰ� ����Ǿ� �ִ�.
	std::cout << "������ �ݺ���: " << *normalIter << '\n';	// 4 ����Ŵ
	std::cout << "������ �ݺ���: " << *reverseIter << '\n';	// 3 ����Ŵ!!!


	return 0;
}