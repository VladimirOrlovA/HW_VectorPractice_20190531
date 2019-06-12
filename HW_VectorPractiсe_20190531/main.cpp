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

	/*int firstNegNum;
	for (size_t i = 0; i < size(v); i++){
		if (v[i] < 0) {
			firstNegNum = i;
			break;
		}
	}
	cout << "firstNegNum = " << v[firstNegNum] << endl;
	int sum15 = 0;
	if (firstNegNum <= size(v) / 2)
		sum15 = v[firstNegNum] + v[firstNegNum + 5];
	else
		sum15 = v[firstNegNum];
	cout <<"sum15 = "<< sum15 << endl;
	for (auto& i : v)
		i /= sum15;*/

	//	3.	��������� ��� �������� ����� �� ������� ��������������

	/*int sum = 0;
	for_each(begin(v), end(v), [&sum](int &i) {
		sum += i;
	});
	cout << sum << endl;
	int averSum=(abs(sum)/v.size());
	cout << averSum << endl;

	for_each(begin(v), end(v), [&averSum] (int &i){
		if (i % 2 != 0)
			return (i = i/averSum);
	});*/

	//	4.	������� �� ������� ����� ����� ���� �����

	/*int sum_of_elems = 0;
	for (auto i : v)
		sum_of_elems += i;
	cout << "sum_of_elems v = " << sum_of_elems << endl;
	for (auto& i : v)
		i = i - sum_of_elems;*/

	//	5.	�������� ������ 3 - �� ����� �� ����� 2 - � ���������� �����

	/*int cnt = 1;
	for (it = begin(v); it != end(v); it++, cnt++) {
		if (cnt == 3) {
			cnt = 1;
			*it *= (*(it - 2) + *(it - 1));
			it++;
		}
	}*/

	//	������� ������ �� 10 ��������� � ��������� ��� ���������� ������� � ��������� �� - 50 �� 50.
	//	1.	�������� ��� ���� ������� ��������������

	/*int sum = 0;
	for_each(begin(v), end(v), [&sum](int &i) {
		sum += i;
	});

	int averSum = (abs(sum) / v.size());

	for_each(begin(v), (end(v) - 1), [&averSum](int &i) {
		if (i == 0)
			return (i = averSum);
	});*/

	//	2.	������� ������ ����� � ��������� ������������� ������

	/*int lastNegNum;

	for (size_t i = (size(v)-1); i!=0; i--)
	{
		if (v[i] < 0) {
			lastNegNum = v[i];
			break;
		}
	}
	cout << "lastNegNum = " << lastNegNum << endl;

	for_each(begin(v), end(v), [&lastNegNum](int &i) {
		return (i += lastNegNum);
	});*/

	//	3.	�������� ��� ������������� ����� ������������ ������

	/*
	it=(max_element(begin(v), end(v)));
	cout <<"Max elem -> "<< *it<<endl;
	for_each(begin(v), (end(v) - 1), [&it](int &i) {
		if (i > 0)
			return (i = *it);
	});
	*/

	//	4.	�������� ������ ������ ������������� ����� ��������� ��������

	/*int cnt = 1;
	it = (max_element(begin(v), end(v)));
	cout << "Max elem -> " << *it << endl;
	for_each(begin(v), (end(v) - 1), [&it, &cnt](int &i) {
		if (i < 0 && cnt == 2) {
			cnt = 1;
			return (i = (*it/2));
		}
		cnt++;

	});*/
	//	5.	�������� ������ ������ ����� ��������� ��������� � ��������

	it = (max_element(begin(v), end(v)));
	cout << "Max elem -> " << *it << endl;
	int t = *it;
	it = (min_element(begin(v), end(v)));
	cout << "Min elem -> " << *it << endl;
	t -= *it;
	cout << "\n-----------\n" << t << "\n-----------\n";

	for_each(begin(v), end(v), [&t](auto &i) {
		//cout << i << "\t";
		if (i % 2 == 0)
			return (i = t);
	});

	copy(begin(v), end(v), os);
	system("pause");
}