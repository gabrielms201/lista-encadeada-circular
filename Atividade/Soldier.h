#ifndef SOLDIER_H
#define SOLDIER_H
#include <ostream>
class Soldier
{
public:
	Soldier(const char* name, unsigned int id);
	const char* getName() const { return _name; }
	unsigned int getId() const { return _id; }
private:
	const char* _name;
	unsigned int _id;

};

inline std::ostream& operator <<(std::ostream& str, const Soldier& soldier)
{
	return str << soldier.getName();
}

inline bool operator == (const Soldier& s1, const Soldier& s2)
{
	if (s1.getId() == s2.getId() && s1.getName() == s2.getName())
	{
		return true;
	}
	return false;
}

inline bool operator != (const Soldier& s1, const Soldier& s2)
{
	if (s1.getId() != s2.getId() || s1.getName() != s2.getName())
	{
		return true;
	}
	return false;
}


#endif
