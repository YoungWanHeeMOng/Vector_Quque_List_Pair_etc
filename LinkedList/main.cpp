

#include <iostream>

#include "linkedlist.h"
#include "song.h"
#include <string>
using namespace std;

int main()
{
	Song *song = new Song("Queen", "We will ROck You");
	Song *song2=new Song("Queen", "I wait it all");
	Song *song3=new Song("Queen", "we are the Champions");

	LinkedList<Song*> lList;

	lLIst->addAtFront(song);
	lList.addAtBack(song2);
	lList.addAfterNode(song,song3);

	cout << lList << endl;

	lList.removeNode(song3);
	cout << lList << endl;
	lList.removeNode(song);
	cout << lList << endl;


cout << "Hello , World" << endl;

return 0;
}