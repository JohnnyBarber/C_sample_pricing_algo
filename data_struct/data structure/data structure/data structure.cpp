#include<iostream>
#include<string>
using namespace std;

/*
Linked list with user defined data structure using pointer
and recursive methods.
*/

struct Entry {
	string name, phone;
	Entry *next;        //next points to another Entry data type
};

//print single entry
void PrintEntry(Entry *e) {
	cout << e->name << " " << e->phone << endl;
}

//print all the entries
void PrintList(Entry *list) {
	for (Entry *cur = list; cur != NULL; cur = cur->next)
		PrintEntry(cur);           //last-in-first-out
}

//using the recursive methods for printing all the entries
void RecPrintList(Entry *list) {
	if (list != NULL) {
		PrintEntry(list);          //last-in-first-out
		RecPrintList(list->next); 
	}
}

//printing entries by first-in-first-out by reversing the printing order
void RecPrintListFIFO(Entry *list) {
	if (list != NULL) {
		RecPrintList(list->next);
		PrintEntry(list);          //first-in-last-out
	}
}

Entry *GetNewEntry() {
	cout << "Enter name (ENTER to exit): ";
	string name;
	getline(cin, name);
	if (name == "") return NULL;

	Entry *newOne = new Entry;
	newOne->name = name;
	cout << "Enter phone: ";
	string phone;
	getline(cin, phone);
	newOne->phone = phone;
	newOne->next = NULL;         //no one follows
	return newOne;
}

//insert new entry into list and sort them alphebatically
void InsertSorted(Entry * &list, Entry* newOne) {
	if (list == NULL || list->name > newOne->name) {
		newOne->next = list;
		list = newOne;
	}
	else {
		InsertSorted(list->next, newOne);
	}
}

/*
The following codes are steps of the previous recursion methods:

void InsertSorted(Entry * &list, Entry* newOne) {
Entry *cur, *prev = NULL;

for (cur = list; cur != NULL; cur = cur->next) {
if (cur->name > newOne->name) break;
prev = cur;
}

newOne->next = cur;
if (prev != NULL)
prev->next = newOne;
else
list = newOne;
}
*/

//build the linked list
Entry *BuildList() {
	Entry *list = NULL;
	while (true) {
		Entry *newOne = GetNewEntry();
		if (newOne == NULL) break;
		InsertSorted(list, newOne);
	}
	return list;
}

/*
deallocate the linked list:
Running a long program would make mannual 
deallocation more helpful. Otherwise, the 
program would deallocate the heap automatically
*/
void Deallocate(Entry *list) {
	/*
	if (list != NULL){
		delete list;
		Deallocate(list->next);
	}

	This is very dangerous because?
	Deleting the fisrt entry of the list
	may make the rest of the entries no
	longer to be found. Thus, we can save
	the rest of the entries first, then
	delete the first entries of the list
	using a recursion.

	if (list != NULL) {
		Entry *next = list->next;
		delete list;
		Deallocate(next);
	}
	*/

	//delete from the last entries to the first
	if (list != NULL) {
		Deallocate(list->next);
		delete list;
	}
}

int main()
{
	Entry *n = BuildList();
	PrintList(n);

	system("pause");
	return 0;
}

/*
Compare a linked list with an array/vector:

ARRAY/VECTOR::                                          LINKED LIST::
+Fast, direct access by index                           +Insert/remove only requires re-writting pointers
-Insert/remove requires shuffling                       +Each element individually allocated, easy to grow/shrink
-Cannot easily grow/shrink (must copy over contents)    -Must traverse links to access elements
*/