#include<iostream>
#include<vector>
#include<cstdlib>
#include<algorithm>
#include<ctime>
#include<iterator>
using namespace std;

void main() {
	srand(time(0));
	//������� ������ �� 10 ��������� � ��������� ��� ���������� ������� � ��������� �� - 50 �� 50.

	vector<int> v(10);
	vector<int>::iterator it;
	ostream_iterator<int> os(cout, "\t");

	generate_n(begin(v), 10, []() {
		return -50 + rand() % 100;
	});

	/*for (it = begin(v); it != end(v); it++)
		cout << *it << "\t";*/
		
	for (auto i : v)
		cout << i << "\t";

	//	1.	��������� � ������� ����� ������ ���������� �� ������������ ������� � ���������� �����, ����������� � �������.
	
	/*int s = sqrt(abs(*(begin(v)) * *(end(v) - 1)));
	cout << s << endl;

	for_each(begin(v), (end(v) - 1), [s](int &i) {
		return i+=s;
	});*/

	
	//	2.	��������� ������ ����� �� ����� 1 - ��� �������������� ����� � 5 - ���(�� �������) �����.

	

	//	3.	��������� ��� �������� ����� �� ������� ��������������

	int sum = 0;
	for_each(begin(v), (end(v) - 1), [&sum](int &i) {
		sum += i;
	});
	cout << sum << endl;
	int averSum=(abs(sum)/v.size());
	cout << averSum << endl;
	
	for_each(begin(v), (end(v)-1), [&averSum] (int &i){
		if (i % 2 != 0)
			return (i /= averSum);
	});

	//	4.	������� �� ������� ����� ����� ���� �����
	//	5.	�������� ������ 3 - �� ����� �� ����� 2 - � ���������� �����


	//	������� ������ �� 10 ��������� � ��������� ��� ���������� ������� � ��������� �� - 50 �� 50.
	//	1.	�������� ��� ���� ������� ��������������
	//	2.	������� ������ ����� � ��������� ������������� ������
	//	3.	�������� ��� ������������� ����� ������������ ������
	//	4.	�������� ������ ������ ������������� ����� ��������� ��������
	//	5.	�������� ������ ������ ����� ��������� ��������� � ��������

	copy(begin(v), end(v), os);



	system("pause");
}