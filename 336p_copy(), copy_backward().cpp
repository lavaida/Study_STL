#include <iostream>
#include <vector>

// Modifying Algorithms (���Ҹ� �����ϴ� �˰���)

int main(void)
{
	std::vector<int> vec01;
	vec01.push_back(1);
	vec01.push_back(2);
	vec01.push_back(3);
	vec01.push_back(4);
	vec01.push_back(5);

	std::vector<int> vec02(10);	// "0"���� �ʱ�ȭ�� ���� 10��(������ ���� ���� 5�� ���� ���ƾ� �Ѵ�.)

	std::cout << "vec01: ";
	for (size_t i = 0; i < vec01.size(); ++i)
	{
		std::cout << vec01[i] << ' ';
	}
	std::cout << '\n';

	std::cout << "vec02: ";
	for (size_t i = 0; i < vec02.size(); ++i)
	{
		std::cout << vec02[i] << ' ';
	}
	std::cout << '\n';

	std::cout << "##################\n";

	// ������ �������� ������ ���� �����ϰ� �� ���� ���Ҹ� ����Ű�� �ݺ��� ��ȯ.
	//- ����� ���(overwrite), ���� ���(insert)
	//- ��� �˰����� �⺻ ������ ����� ����̸�,
	//�ݺ��� �����(insert_iterator) ���� ����Ͽ� ���� ���� �����ϰ� �� �� �ִ�.
	std::vector<int>::iterator iter;
	iter = std::copy(vec01.begin(), vec01.end(), vec02.begin());
	// [vec02.begin(), vec02.begin() + (vec01.end() - vec01.begin()))
	std::cout << "iter-1: " << *(iter - 1) << '\n';	// 5
	std::cout << "iter  : " << *iter << '\n';		// 0

	std::cout << "vec01: ";
	for (size_t i = 0; i < vec01.size(); ++i)
	{
		std::cout << vec01[i] << ' ';
	}
	std::cout << '\n';

	std::cout << "vec02: ";
	for (size_t i = 0; i < vec02.size(); ++i)
	{
		std::cout << vec02[i] << ' ';
	}
	std::cout << '\n';


	std::cout << "##################\n";

	std::vector<int> vec03(10);	// ������ ������ �������� ��� ������ �� Ŀ���Ѵ�!!!

	std::cout << "vec01: ";
	for (size_t i = 0; i < vec01.size(); ++i)
	{
		std::cout << vec01[i] << ' ';
	}
	std::cout << '\n';

	std::cout << "vec03: ";
	for (size_t i = 0; i < vec03.size(); ++i)
	{
		std::cout << vec03[i] << ' ';
	}
	std::cout << '\n';

	std::cout << "##################\n";

	// �������� ���Ҹ� ���� ��ġ�� ���� �����ϰ� ���Ҹ� �����ϴ� ó�� ��ġ�� �ݺ��ڸ� ��ȯ�ϴ� �˰���
	iter = std::copy_backward(vec01.begin(), vec01.end(), vec03.end());
	//ex) copy_backward(b, e, t)
	//- [b, e)�� ��� ���Ҹ� [t - (e - b), t)�� �������� ������ ���Һ��� ���縦 �Ѵ�!!!
	//������ ������ [iter, vec03.end())
	std::cout << "iter-1: " << *(iter - 1) << '\n';	// 0
	std::cout << "iter  : " << *iter << '\n';		// 1 
	
	std::cout << "vec01: ";
	for (size_t i = 0; i < vec01.size(); ++i)
	{
		std::cout << vec01[i] << ' ';
	}
	std::cout << '\n';

	std::cout << "vec03: ";
	for (size_t i = 0; i < vec03.size(); ++i)
	{
		std::cout << vec03[i] << ' ';
	}
	std::cout << '\n';

	return 0;
}