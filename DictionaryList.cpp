#include "DictionaryList.h"

DictionaryList::DictionaryList() :
    head_(nullptr),
    tail_(nullptr)
{}

DictionaryList::~DictionaryList() 
{
    if (head_ != nullptr)
    {
        Node* helper = head_;
        while (helper)
        {
            helper = helper->nextNode_;
            delete head_;
            head_ = helper;
        }
    }
  //  delete head_;
   // delete tail_;
}

DictionaryList::DictionaryList(const DictionaryList& list) //����������� ����������� 
{
    if (list.head_ == nullptr)
    {
        head_ = nullptr;
        return;
    }
    head_ = new Node(list.head_->value_);
    Node* srcPtr = list.head_->nextNode_;
    Node* destPtr = head_;
    while (srcPtr != nullptr)
    {
        destPtr->nextNode_ = new Node(srcPtr->value_);
        destPtr = destPtr->nextNode_;
        srcPtr = srcPtr->nextNode_;
    }
}

DictionaryList::DictionaryList(DictionaryList&& list) noexcept : //����������� �����������
    head_(list.head_)
{
    list.head_ = nullptr;
}



DictionaryList& DictionaryList::operator=(DictionaryList&& list) noexcept //�������� ������������� ������������
{
    if (this != &list) // list - ��������� ������
    {
        swap(list); // ������ list � ������, ������� ����� �� =, ����� ��������� ����� ���������� �������� =
    }
    return *this;
}


void DictionaryList::swap(DictionaryList& other) noexcept //����� ��� ������ �������� 2�� ����������
{
    std::swap(head_, other.head_);
    std::swap(tail_, other.tail_);
}


void DictionaryList::outAll() //����� ������
{

    if (isEmpty()) return;
    Node* helper = head_; //������� ��������� �� ������ ����

    while (helper)
    { 
        std::cout << helper->value_ << " ";
        helper = helper->nextNode_; //��������� �������� ���������� �� ���� ����
    }

    std::cout << '\n';
}

bool DictionaryList::isEmpty() // �������� ������� ����� � �������
{ 
	return head_ == nullptr;
}

void DictionaryList::insert(Node* newNode)
{
    if (isEmpty()) //���� ������� ����. �� ��������� ����������� �������
    {
        head_ = newNode;
        tail_ = newNode;
        return;
    }

    if (this->search(newNode)) return;

    if (newNode->value_ < head_->value_)
    {
        newNode->nextNode_ = head_;
        head_ = newNode;
    }
    else
    {
        Node* helper = head_;

        while (helper != tail_) 
        {
            if (helper->nextNode_->value_ > newNode->value_)
            {
                break;
            }
            helper = helper->nextNode_;
        }

        if (helper == tail_)
        {
            newNode->nextNode_ = nullptr;
            helper->nextNode_ = newNode;
            tail_ = newNode;
            return;
        }
        newNode->nextNode_ = helper->nextNode_;
        helper->nextNode_ = newNode;
    }
}

void DictionaryList::insert(int value) 
{
    Node* newNode = new Node(value); //������� ���� �� ���������
    this->insert(newNode);
}

void DictionaryList::deleteNode(int value) 
{
    if (isEmpty()) 
    {
        //std::cout << "The dictionary is empty.\n";
        return;
    }

    if (!this->search(value))
    {
        //std::cout << "The specified item is not in the dictionary.\n";
        return;
    }

    if (head_->value_ == value) //���������, ����� �� value 1�� �������
    { 
        Node* helper = head_;
        head_ = helper->nextNode_;
        return;
    }

    if (tail_->value_ == value)  //���������, ����� �� value ��������� �������
    {
        Node* helper = head_;
        while (helper->nextNode_ != tail_) helper = helper->nextNode_; //������� ������, �������������� �� ������������� ����
        helper->nextNode_ = nullptr; // "��������" ��������� ����������
        tail_ = helper;
        return;
    }
    Node* first = head_;//������� ��� ����, �������� 2�� ����� ���������� � value, 
    Node* second = first->nextNode_;//1�� ���� ����� ��� ��������������� ��������� �� ��-�, ������ ����� ����������

    while (second && second->value_ != value) // 1) ���� �� ������ ���� �� �����, ���� �� ������ ����
    {
        first = first->nextNode_;
        second = second->nextNode_;
    }

    if (!second) { // 2) ������ �������� (second == nullptr)
        return;
    }
    else // 3) ������� ������ ����
    {
        first->nextNode_ = second->nextNode_;
        delete second;
    }
}

bool DictionaryList::search(int value) 
{
    Node* node = new Node(value);
    return this->search(node);
}

bool DictionaryList::search(Node* node)
{
    Node* helper = head_;

    while (helper)
    {
        if (helper->value_ == node->value_) {
            return 1;
        }
        helper = helper->nextNode_;
    }
}

void DictionaryList::deleteDictionary(DictionaryList list) 
{
    if (list.isEmpty()) {
        std::cout << "Second dictionary is empty.\n";
        return;
    }

    Node* helper = list.head_;

    while (helper)
    {
        if (this->search(helper->value_)) 
        {
            this->deleteNode(helper->value_);
        }
        helper = helper->nextNode_; 
    }
}

void DictionaryList::merge(DictionaryList* list) 
{
    Node* helper = list->head_;
    while (helper)
    {
        Node* next = helper->nextNode_;

        if (helper == list->head_) {
            if (list->head_->nextNode_) { list->head_ = list->head_->nextNode_; }
            else { list->head_ = nullptr; }
        }
        this->insert(helper);
        list->deleteNode(helper->value_);
        helper = next;
    }
}

DictionaryList* getIntersection(DictionaryList* listFirst, DictionaryList* listSecond) 
{
    DictionaryList* listThird = new DictionaryList;

    DictionaryList::Node* helper = listFirst->head_;

    while (helper) 
    {
        if (listSecond->search(helper->value_))
        {
            listThird->insert(helper->value_);
        }
        helper = helper->nextNode_;
    }
    return listThird;
}
