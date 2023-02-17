#ifndef _DICTIONARY_LIST
#define _DICTIONARY_LIST
#include <iostream>

class DictionaryList
{
private:
	struct Node {
		int value_; 
		Node* nextNode_;

		Node() {
			value_ = NULL;
			nextNode_ = nullptr;
		}
		
		Node(int value, Node* nextNode = nullptr) {
			value_ = value;
			nextNode_ = nextNode;
		}
	};

	Node* head_;
	Node* tail_;//��������� �� ��������� �������
	void insert(Node* newNode);
	bool search(Node* node);

public:
	DictionaryList();
	~DictionaryList();
	DictionaryList(const DictionaryList & src); //����������� �����������
	DictionaryList(DictionaryList && src) noexcept; //����������� �����������
	DictionaryList& operator=(DictionaryList&& src) noexcept; //�������� ������������� ������������
	
	void swap(DictionaryList& other) noexcept;
	bool isEmpty();
	void outAll();
	void insert(int value);
	void deleteNode(int value);
	bool search(int value);
	void deleteDictionary(DictionaryList list);
	void merge(DictionaryList* list);

	friend DictionaryList* getIntersection(DictionaryList* leftList, DictionaryList* rightList);
};

#endif

