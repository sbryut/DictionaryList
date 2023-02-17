#include <iostream>
#include "DictionaryList.h"

int main() {
	DictionaryList listFirst;
	std::cout << '\n';

	std::cout << "Is the first dictionary empty? " << listFirst.isEmpty() << '\n' << '\n'; //проверяем, пуст ли список
	listFirst.insert(5);
	listFirst.insert(1); //добавлние элементов
	listFirst.insert(13);
	listFirst.insert(7);
	listFirst.insert(7);
	listFirst.insert(25);

	std::cout << "Updated first dictionary #1: ";
	listFirst.outAll();
	std::cout << '\n';
	std::cout << "Is the first dictionary empty? " << listFirst.isEmpty() << '\n' << '\n';

	listFirst.deleteNode(7);
	listFirst.deleteNode(1); //удаление элементов
	std::cout << "Updated first dictionary #2: ";
	listFirst.outAll();
	std::cout << '\n';

	std::cout << "Is the '10' in the first dictionary ? " << listFirst.search(10) << '\n' << '\n';

	std::cout << "Second dictionary: ";
	DictionaryList listSecond;
	listSecond.insert(5);
	listSecond.insert(4);
	listSecond.insert(25);
	listSecond.insert(7);
	listSecond.outAll();
	std::cout << "--------------------------------------------------------";

	DictionaryList* listThird = getIntersection(&listFirst, &listSecond);
	std::cout << '\n' << "Third dictionary (getIntersection): ";
	listThird->outAll();
	std::cout << "--------------------------------------------------------";

	listFirst.deleteDictionary(listSecond);
	std::cout << '\n' << "Updated first dictionary #4 (delete): ";
	listFirst.outAll();
	std::cout << "--------------------------------------------------------";

	listFirst.merge(&listSecond);
	std::cout << '\n' << "Updated first dictionary #5 (merge): ";
	listFirst.outAll();
	std::cout << '\n' << "Updated second dictionary #2 (merge): ";
	listSecond.outAll();
	std::cout << '\n';

	return 0;
}