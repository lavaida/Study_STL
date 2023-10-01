#include <iostream>
#include <vector>

// std::vector �����̳�
//- ���Ұ� ���ӵǰ� ����Ǿ� �����Ƿ�, ���ҿ� �����ϴ� at() �Լ��� v[i] ������ �ӵ��� ��������
//insert(), erase(), push_back() ���� ����ϰ� ȣ��Ǿ�� �ϴ� ���α׷��̶��
//�ٸ� �����̳ʸ� �����ϴ� �͵� ���� ����ϴ�.
//- Sequence ��� �����̳��̱� ������, ���Ұ� ���� ������� ��ġ(����)�� �����ϹǷ�
//���� �� ��ҿ� ���� �� ��Ҹ� �����ϴ� front(), back() �Լ��� �����Ѵ�.
//But, Sequence ��������� Array ��� �����̳��̱� ������ push_front(), pop_front() �Լ��� �������� �ʴ´�.

int main(void)
{
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);

	vec.front() = 10;	// reference�� ��ȯ�ϴ� �͵� Overloading �Ǿ� ����.
	vec.back() = 30;

	std::cout << "front(): " << vec.front() << '\n';
	std::cout << "back(): " << vec.back() << '\n';

	std::cout << "##############################\n";

	for (std::vector<int>::size_type i = 0; i < vec.size(); ++i)
	{
		std::cout << vec[i] << ", " << vec.at(i) << '\n';
	}

	std::cout << "##############################\n";

	try
	{
		int result = vec.at(3);	// index ���� üũ�� ���ش�.
	}
	catch (std::out_of_range &e)
	{
		std::cout << e.what() << '\n';
	}

	return 0;
}