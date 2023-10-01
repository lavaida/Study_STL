#include <iostream>
#include <list>

// std::list �����̳�
//- std::vector, std::deque �����̳�ó�� Sequence �����̳��̱� ������ ���Ұ� ������� ������ �����ϰ� �ִ�.
//But, Node ��� �����̳ʶ� ���Ұ� ��� ������ ����Ǿ� ������, Doubly linked List�� �����Ǿ� �ִ�.
//�׸��� Node ��� �����̳ʶ� Random Access Iterator�� �ƴ� Bidirectional Iterator�� �����Ѵ�.

int main(void)
{
	std::list<int> list;
	list.push_back(4);
	list.push_back(5);
	list.push_front(3);
	list.push_front(2);
	list.push_front(1);

	std::list<int>::iterator iter = list.begin();
	for (; iter != list.end(); ++iter)
	{
		std::cout << *iter << ' ';
	}
	std::cout << '\n';

	std::cout << "######################\n";

	// std::vector, std::deque �����̳ʴ� ���ο� ���Ҹ� �߰��ϴ� �� ���Ҹ� �о�� ������ �ʿ��� ��찡 ������,
	//std::list �����̳ʴ� Sequence �߰��� ���Ҹ� Insert/Erase �ϴ��� ��� �ð� ���⵵�� ���� ������ �����ش�.

	std::list<int> list02;
	list02.push_back(1);
	list02.push_back(2);

	std::list<int>::iterator iter021 = list02.begin();
	++iter021;	// ����� �ݺ��ڶ� "+=" ������ ����� �� ����.

	std::list<int>::iterator iter022 = list02.insert(iter021, 3);	// ������ ��ġ�� ���� �߰��� push_back() �Լ��� ����� ��.
	std::cout << "*iter021: " << *iter021 << '\n';
	std::cout << "*iter022: " << *iter022 << '\n';
	for (iter = list02.begin(); iter != list02.end(); ++iter)
	{
		std::cout << *iter << ' ';
	}
	std::cout << '\n';

	iter022 = list02.insert(iter021, 4);
	std::cout << "*iter021: " << *iter021 << '\n';
	std::cout << "*iter022: " << *iter022 << '\n';
	for (iter = list02.begin(); iter != list02.end(); ++iter)
	{
		std::cout << *iter << ' ';
	}
	std::cout << '\n';

	std::cout << "######################\n";
	iter021 = list02.begin();
	++iter021;

	iter022 = list02.end();
	--iter022;

	std::cout << "*iter021: " << *iter021 << '\n';
	iter021 = list02.erase(iter021);
	for (iter = list02.begin(); iter != list02.end(); ++iter)
	{
		std::cout << *iter << ' ';
	}
	std::cout << '\n';

	std::cout << "*iter021: " << *iter021 << '\n';
	iter021 = list02.erase(iter021);
	for (iter = list02.begin(); iter != list02.end(); ++iter)
	{
		std::cout << *iter << ' ';
	}
	std::cout << '\n';

	// Array ��� �����̳ʰ� �ƴ� Node ��� �����̳ʶ�,
	//������ ����/���� ������ ������ �� �޸𸮰� ���Ҵ�ǰų� ������ ��ġ�� ������� �����Ƿ�, �ݺ��ڰ� ��ȿ�ϴ�!
	std::cout << "*iter022: " << *iter022 << '\n';

	return 0;
}