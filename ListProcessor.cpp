// ListProcessor.cpp

// tom bailey   1540  30 sep 2011

// tom bailey   1030  27 jan 2012
// Exercise the List class with verbose Node constructor
//   and destructor.

#include "LinkedList.h"


int main()
{
	List cows;
	cout << "cows list  :  " << cows << endl << endl;

	cout << "The size of cows list is " << cows.size() << endl; //test
	cout << "The sum of cows list is " << cows.sum() << endl << endl; //test

	cows.insertAsFirst(1.23);
	cows.insertAsFirst(2.34);
	cout << "cows list  :  " << cows << endl << endl;

	cows.removeFirst();
	cout << "cows list  :  " << cows << endl << endl;

	cout << "The size of cows list is " << cows.size() << endl; //test
	cout << "The sum of cows list is " << cows.sum() << endl << endl; //test

	//===========================================================================================================

	List horses(cows);
	cout << "cows list  :  " << cows << endl;
	cout << "horses list:  " << horses << endl << endl;

	cout << "The size of horses list is " << horses.size() << endl; //test
	cout << "The sum of horses list is " << horses.sum() << endl << endl; //test



	horses.removeFirst();
	horses.insertAsFirst(5.67);
	cows.insertAsFirst(6.78);
	cout << "cows list  :  " << cows << endl;
	cout << "horses list:  " << horses << endl << endl;

	cout << "The size of horses list is " << horses.size() << endl; //test
	cout << "The sum of horses list is " << horses.sum() << endl << endl; //test

	//================================================================================================

	List pigs;
	cout << "cows list  :  " << cows << endl;
	cout << "horses list:  " << horses << endl;
	cout << "pigs list  :  " << pigs << endl << endl;

	pigs = cows;
	cout << "cows list  :  " << cows << endl;
	cout << "horses list:  " << horses << endl;
	cout << "pigs list  :  " << pigs << endl << endl;

	cout << "The size of pigs list is " << pigs.size() << endl; //test
	cout << "The sum of pigs list is " << pigs.sum() << endl << endl; //test

	pigs = horses;
	cout << "cows list  :  " << cows << endl;
	cout << "horses list:  " << horses << endl;
	cout << "pigs list  :  " << pigs << endl << endl;

	cout << "The size of pigs list is " << pigs.size() << endl; //test
	cout << "The sum of pigs list is " << pigs.sum() << endl << endl; //test

	//=============================================================================================================================

	cows.insertAsLast(5);
	horses.insertAsLast(10);
	pigs.insertAsLast(15);

	cout << "\ncows list is now " << cows << endl; // test
	cout << "horses list is now " << horses << endl;// test
	cout << "pigs list is now " << pigs << endl << endl; //test


	cout << "End of code" << endl;

	system("pause");

	return 0;
}

