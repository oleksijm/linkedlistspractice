#include <iostream>
#include "ContactList.h"


int main()
{
	ContactList* cl1 = new ContactList();

	std::string name;

	while (true) 
	{
		std::cout << "Enter the name of the contact or q to quit." << std::endl;
		std::cin >> name;
		if (name == "q")
		{
			//cl1->printList();
			break;
			
		}
		cl1->insert(name);

	}

	cl1->reversePrintList();

	while (true)
	{
		std::cout << "Enter the name of the contact to delete or q to quit." << std::endl;
		std::cin >> name;
		if (name == "q")
		{
			break;
		}
		cl1->deleteNode(name);
		cl1->printList();

	}
	


	return 0;
}
*****************************************************************************************************************************************************************
//ContactList.cpp

#include "ContactList.h"


ContactList::ContactList() :head(0), size(0)
{}

void ContactList::addToHead(const std::string& name)
{
	Contact* newOne = new Contact(name);

	if (head == 0)
	{
		head = newOne;
	}
	else
	{
		newOne->next = head;
		head = newOne;
	}
	size++;
}

void ContactList::printList()
{
	Contact* tp = head;

	while (tp != 0)
	{
		std::cout << *tp << std::endl;
		tp = tp->next;
	}
}

void ContactList::insert(const std::string& name)
{
	Contact* newNode = new Contact(name);

	//case 1 - empty list
	if (head == 0)
	{
		head = newNode;
	}
	else
	{
		Contact* curr = head;
		Contact* prev = 0;

		//traverse list to find insert location
		while (curr != 0)
		{
			if (curr->name >= newNode->name)
			{
				break;
			}
			else
			{
				prev = curr;
				curr = curr->next;
			}
		}
		
			//case 2 - insert at head (not empty)
			if (curr == head)
			{
				newNode->next = head;
				head = newNode;
			}
			//case 3 - insert after head (not empty)
			else
			{
				newNode->next = curr;
				prev->next = newNode;
			}
		
	}
	
	size++;

}

void ContactList::deleteNode(const std::string& name)
{
	//case 1 - empty list
	if (head == 0)
	{
		std::cout << "Node cannot be deleted from an empty linked list!" << std::endl;
	}
	else
	{
		Contact* curr = head;
		Contact* prev = 0;

		//Traverse list to find node to delete
		while (curr != 0)
		{
			if (curr->name == name)
			{
				break;
			}
			else
			{
				prev = curr;
				curr = curr->next;
			}
		}
	//case 2 - Node with "name" not found in list
		if (curr == 0)
		{
			std::cout << "Contact with name " << name << " not found." << std::endl;
		}
		else
		{
	//case 3 - delete from the head node
			if (head == curr)
			{
				head = head->next;
			}

	//case 4 - delete beyond head
			else
			{
				prev->next = curr->next;
			}

			delete curr;
			size--;
		}

	}

}

void ContactList::reversePrintList()
{

	reversePrintWorker(head);

}

void ContactList::reversePrintWorker(Contact* curr)
{
	if (curr != 0)
	{
		reversePrintWorker(curr->next);
		std::cout << *curr << std::endl;
	}



}
***************************************************************************************************************************************************************
//Contactlist.h

#ifndef CONTACTLIST_H_
#define CONTACTLIST_H_

#include "Contact.h"

class ContactList
{
public:
	ContactList();

	void addToHead(const std::string&);
	void printList();
	void insert(const std::string&);
	void deleteNode(const std::string&);
	void reversePrintList();


private:
	void reversePrintWorker(Contact*);
	Contact* head;
	int size;
};


#endif

*****************************************************************************************************************************************************************

//Contact.cpp

#include "Contact.h"

Contact::Contact(std::string n):name(n), next(NULL)
{}

std::ostream& operator<<(std::ostream& os, const Contact& c)
{

	return os << "Name: " << c.name;

}

*******************************************************************************************************************************************************************

//Contact.h

#ifndef CONTACT_H_
#define CONTACT_H_

#include <iostream>
#include <string>

class Contact 
{

	friend std::ostream& operator<<(std::ostream& os, const Contact& c);
	friend class ContactList;

public:

	Contact(std::string name = "none");

private:

	std::string name;
	Contact* next;


};




#endif

