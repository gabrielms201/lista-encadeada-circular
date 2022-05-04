/*
LICAO LISTA ENCADEADA CIRCULAR - ESTRUTURA DE DADOS
GRUPO:

MAYARA MENEGHETTI HONDA                  :  32152280
PAULO HENRIQUE BRAGA CECHINEL            :  32151128
RICARDO GABRIEL MARQUES DOS SANTOS RUIZ  :  32134908

*/

#ifndef SOLDIER_H
#define SOLDIER_H
#include <ostream>
#include <string>

class Soldier
{
public:
	Soldier(std::string name, unsigned int id);
	std::string getName() const { return _name; }
	unsigned int getId() const { return _id; }
private:
	std::string _name;
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
	return !(s1 == s2);
}


#endif
