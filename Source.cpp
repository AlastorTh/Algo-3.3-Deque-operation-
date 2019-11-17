#include <iostream>
#include "Deque.h"
#include <string>
#include <locale.h>



int main() {

	setlocale(LC_ALL, "RUS");
	Deque<int> deque;

	std::cout << "---��������� ������ � �����---" << std::endl;
	std::cout << "pushf - ������� � ������ " << std::endl;
	std::cout << "pushb - ������� � �����" << std::endl;
	std::cout << "popf- ������� �� ������" << std::endl;
	std::cout << "popb- ������� �� �����" << std::endl;
	std::string action;

	while (std::cin >> action) {
		if (action == "pushf") 
		{
			int value;
			std::cout << "������� ������������� ��������:";
			std::cin >> value;
			deque.push_front(value);
		}
		else if (action == "pushb")
		{
			int value;
			std::cout << "������� ������������� ��������:";
			std::cin >> value;
			deque.push_back(value);
		}
		else if (action == "popf") 
		{
			deque.pop_front();
		}
		else if (action == "popb")
		{
			deque.pop_back();
		}
		
		else if (action == "print") 
		{
			if (deque.empty()) 
			{
				std::cout << "������ ����!" << std::endl;
			}
			std::cout << deque;
		}
		else if (action == "clear")
		{
			deque.clear();
		}
		else if (action == "exit") 
		{
			return 0;
		}
		

	}
	return 0;
}
