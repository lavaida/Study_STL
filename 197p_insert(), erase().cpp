#include <iostream>
#include <vector>

int main(void)
{
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(4);
	vec.push_back(5);

	std::vector<int>::iterator iter = std::find(vec.begin(), vec.end(), 4);
	if (iter != vec.end())
	{
		vec.insert(iter, 3);	// 반복자가 가리키는 위치에 원소(값)를 추가하고, 한 칸씩 뒤로 민다.
	}

	for (size_t i = 0; i < vec.size(); ++i)
	{
		std::cout << vec.at(i) << ' ';
	}
	std::cout << '\n';

	std::cout << "################################\n";

	iter = vec.begin();
	for (; iter != vec.end();)
	{
		if ((*iter) % 2 == 0)
		{
			iter = vec.erase(iter);	// 지워지는 원소의 다음 원소의 위치에 해당하는 반복자가 반환된다.
		}
		else
		{
			++iter;
		}
	}

	iter = vec.begin();
	for (; iter != vec.end(); ++iter)
	{
		std::cout << *iter << ' ';
	}
	std::cout << '\n';

	std::cout << "size: " << vec.size() << ", capacity: " << vec.capacity() << '\n';

	return 0;
}