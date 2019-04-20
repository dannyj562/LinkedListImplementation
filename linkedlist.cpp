/*
	@author Danny
	April 20, 2019
	An Implementation of a Linked List requesting users for integers
*/
#include <iostream>
#include <sstream>
using namespace std;

struct Node {
	int data;
	struct Node *next;
};

struct Node *head = NULL;

/*
	@param num 
		An integer requested by the user to insert in linked list
*/
void insert(int num) {
	struct Node *new_node = (struct Node *) malloc(sizeof(struct Node));
	new_node->data = num;
	new_node->next = head;
	head = new_node;
}

void display() {
	cout << endl << "Linked List" << endl;
	while (head != NULL) {
		cout<< head->data << " --> ";
		head = head->next;
	}
	cout<< "NULL" << endl;
}

void prompt() {
	cout << "Please enter a number to be stored in a Linked List " << endl;
	cout << "Type EXIT to stop" << endl;
}

void retrieveInput() {
	string strVal;
	prompt();
	cin >> strVal;
	while (strVal != "EXIT" && strVal != "exit") {	
		istringstream iss (strVal);
		int num;
		if (iss >> num) {
			insert(num);
		} else {
			cout << "Hmm.. Something went wrong. Please try again :) \n" << endl;
		}
		prompt();
		cin >> strVal;
	}
}

int main() {
	retrieveInput();
	display();
}
