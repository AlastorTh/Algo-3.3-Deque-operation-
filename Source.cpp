#include <iostream>
#include "Deque.h"
#include <string>
#include <locale.h>



int main() {

	setlocale(LC_ALL, "RUS");
	Deque<int> deque;

	std::cout << "---Программа работы с деком---" << std::endl;
	std::cout << "pushf - Вставка в начало " << std::endl;
	std::cout << "pushb - Вставка в конец" << std::endl;
	std::cout << "popf- выборка из начала" << std::endl;
	std::cout << "popb- выборка из конца" << std::endl;
	std::cout << "clear- очистка дека" << std::endl;
	std::cout << "print - печать" << std::endl;
	std::string action;

	while (std::cin >> action) {
		if (action == "pushf") 
		{
			int value;
			std::cout << "Введите целочисленное значение:";
			std::cin >> value;
			deque.push_front(value);
		}
		else if (action == "pushb")
		{
			int value;
			std::cout << "Введите целочисленное значение:";
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
				std::cout << "Список пуст!" << std::endl;
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
