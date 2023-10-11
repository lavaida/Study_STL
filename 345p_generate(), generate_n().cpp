#include <algorithm>
#include <iostream>
#include <vector>

// Modifying Algorithms (���Ҹ� �����ϴ� �˰���)

int Func(void)
{
	return 0;	// ��ȯ�Ǵ� ������ ���Ҹ� ä�� �ִ´�.
}

int main(void)
{
	// generate() �˰���� for_each(), transform() �˰����� ū ��������
	//�Ű������� �������� ���Ҹ� ���޹��� �ʱ� ������ ���Ұ� ������ �ִ� ���� ���� Ȱ���� �� ����,
	//�ܼ��� ������ ������ ä�� �ִ´�.

	std::vector<int> vec01;
	vec01.push_back(1);
	vec01.push_back(2);
	vec01.push_back(3);

	std::cout << "vec01: ";
	for (size_t i = 0; i < vec01.size(); ++i)
	{
		std::cout << vec01[i] << ' ';	// 1 2 3
	}
	std::cout << '\n';

	// �������� ��� ���Ҹ� �ܼ��� ������ ������ ������ �� ����ϴ� �˰���
	std::generate(vec01.begin(), vec01.end(), Func);	// void �Ű������� ����ؾ� �Ѵ�!!!

	std::cout << "vec01: ";
	for (size_t i = 0; i < vec01.size(); ++i)
	{
		std::cout << vec01[i] << ' ';	// 0 0 0
	}
	std::cout << '\n';

	std::cout << "#################\n";

	std::vector<int> vec02;
	vec02.push_back(1);
	vec02.push_back(2);
	vec02.push_back(3);
	vec02.push_back(4);
	vec02.push_back(5);

	std::cout << "vec02: ";
	for (size_t i = 0; i < vec02.size(); ++i)
	{
		std::cout << vec02[i] << ' ';	// 1 2 3 4 5
	}
	std::cout << '\n';

	std::generate_n(vec02.begin(), 2, Func);
	//���� Func() �Լ��� ���� ��ȯ�Ǵ� "0"�� ���� �־�������,
	//�Լ� ��ü�� �̿��ϸ� ó���� �ʱ�ȭ�ؼ� �־��� ���� ���� ���� ������ ���� ����.

	std::cout << "vec02: ";
	for (size_t i = 0; i < vec02.size(); ++i)
	{
		std::cout << vec02[i] << ' ';	// 0 0 3 4 5
	}
	std::cout << '\n';

	return 0;
}