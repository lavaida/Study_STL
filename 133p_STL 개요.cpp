#include <iostream>
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

int main(void)
{
	// ���� ���� �ݺ��ڸ� ���� std::vector �����̳�

	std::vector<int> vec;

	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);

	std::vector<int>::iterator iter = vec.begin();
	std::cout << iter[0] << ' ';
	std::cout << iter[1] << ' ';
	std::cout << iter[2] << '\n';

	iter += 2;
	std::cout << *iter << '\n';

	iter = vec.begin();

	std::vector<int>::iterator iter2 = iter + 2;
	std::cout << *iter2 << '\n';


	return 0;
}