#include <iostream>
#include <vector>

// std::vector 컨테이너
//- 원소가 연속되게 저장되어 있으므로, 원소에 접근하는 at() 함수나 v[i] 연산은 속도가 빠르지만
//insert(), erase(), push_back() 등이 빈번하게 호출되어야 하는 프로그램이라면
//다른 컨테이너를 선택하는 것도 좋은 방법니다.
//- Sequence 기반 컨테이너이기 때문에, 원소가 서로 상대적인 위치(순서)를 유지하므로
//가장 앞 요소와 가장 뒤 요소를 참조하는 front(), back() 함수를 제공한다.
//But, Sequence 기반이지만 Array 기반 컨테이너이기 때문에 push_front(), pop_front() 함수를 제공하지 않는다.

int main(void)
{
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);

	vec.front() = 10;	// reference를 반환하는 것도 Overloading 되어 있음.
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
		int result = vec.at(3);	// index 범위 체크를 해준다.
	}
	catch (std::out_of_range &e)
	{
		std::cout << e.what() << '\n';
	}

	return 0;
}