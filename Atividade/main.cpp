/*
É sorteado um número n e o nome de um soldado;
Iniciando no soldado começam a contar até n no sentido horário;
O soldado onde parou a contagem é retirado do círculo (coitado,
está morto!!!!);
A contagem reinicia no soldado ao retirado do círculo;
O último soldado (o que sobrou) é o felizardo que sairá a cavalo e
sobreviverá;
Este problema pode ser resolvido utilizando-se uma LISTA
ENCADEADA CIRCULAR!!!
*/


#include "main.h"
void sample()
{
	List list = List();
	Soldier s1 = Soldier("Ricardo", 18);
	Soldier s2 = Soldier("Paulin", 19);
	Soldier s3 = Soldier("Gabriel", 20);
	list.insert(s1);
	list.insert(s2);
	list.insert(s3);

	//list.remove(s1);
	//list.remove(s2);
	//list.remove(s3);
	//list.clear();
	//list.clear();
	//std::cout << list.find(s1);
	//std::cout << list;
	std::cout << list.findPosition(s1);
	std::cout << list.findPosition(s1);
	std::cout << list.findPosition(s3);
}

void josephus()
{
	List list = List();
	list.insert(Soldier("Pedro", 1));
	list.insert(Soldier("Paulo", 2));
	list.insert(Soldier("Lucas", 3));
	list.insert(Soldier("Ricardo", 4));
	list.insert(Soldier("Gabriel", 5));
	list.insert(Soldier("Arthur", 6));
	list.insert(Soldier("Jailson", 7));
	list.insert(Soldier("Victor", 8));
	list.insert(Soldier("Nathan", 9));
	list.insert(Soldier("Jorge", 10));


	std::string firstSoldierName;
	unsigned int size = list.getSize();
	unsigned int seed = time(0);
	srand(seed);
	unsigned int n = 1 + rand() % size;
	firstSoldierName = list.findById(n).getName();
	Soldier soldier = list.findByName(firstSoldierName);
	unsigned int position = list.findPosition(soldier);

	std::cout << "Soldado Sorteado: " << firstSoldierName << std::endl;
	std::cout << "Numero sorteado: " << n << std::endl;
	std::cout << "<------>" << std::endl;

	while (list.getSize() != 1)
	{
		std::cout << "Lista: " << list << std::endl;
		soldier = list.findByPosition((position + n) % list.getSize());
		position = list.findPosition(soldier);
		std::cout << "\tSoldado morto: " << soldier << std::endl;
		list.remove(soldier);
	}
	std::cout << "Soldado sobrevivente: " << list;
}
int main(int argc, char** argv[])
{
	josephus();
}