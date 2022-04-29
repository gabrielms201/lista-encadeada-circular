#include "main.h"

int main(int argc, char** argv[])
{
	List list = List();
	Soldier *s1 = new Soldier("Ricardo", 18);
	Soldier s2 = Soldier("Paulin", 19);
	Soldier s3 = Soldier("Gabriel", 20);
	list.insert(*s1);
	//list.insert(s2);
	//list.insert(s3);

	/*list.remove(s1);
	list.remove(s2);
	list.remove(s3);*/
	list.clear();
	list.clear();
	list.insert(*s1);
	list.insert(*s1);
	std::cout << list.find(*s1);
	std::cout << list;
}