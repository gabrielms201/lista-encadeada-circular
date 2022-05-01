/*
LICAO LISTA ENCADEADA CIRCULAR - ESTRUTURA DE DADOS
GRUPO:

MAYARA MENEGHETTI HONDA                  :  32152280
PAULO HENRIQUE BRAGA CECHINEL            :  32151128
RICARDO GABRIEL MARQUES DOS SANTOS RUIZ  :  32134908

*/

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
// Main
int main(int argc, char* argv[])
{
	try
	{
		std::cout << "Bem vindo ao programa que resolve o teste de josephus! Deseja realizar os testes funcionais antes? (1/0): ";
		int resp;
		std::cin >> resp;
		if (resp)
		{
			tests();
		}

		std::cout << std::endl << "< ----------------------------------- > \n" << "Demonstracao: " << std::endl;
		menu();
		std::cout << std::endl << "< ----------------------------------- > \n" << "Teste de Josephus: " << std::endl;
		josephus();
		system("pause");
	}
	catch(std::exception& e)
	{
		std::cerr << "exception: " << e.what() << std::endl;
	}

}
// Teste de Josephus
void josephus()
{
	List list = List();


	Soldier s1 = Soldier("Pedro", 1);
	Soldier s2 = Soldier("Paulo", 2);
	Soldier s3 = Soldier("Lucas", 3);
	Soldier s4 = Soldier("Ricardo", 4);
	Soldier s5 = Soldier("Gabriel", 5);
	Soldier s6 = Soldier("Arthur", 6);
	Soldier s7 = Soldier("Jailson", 7);
	Soldier s8 = Soldier("Victor", 8);
	Soldier s9 = Soldier("Nathan", 9);
	Soldier s10 = Soldier("Jorge", 10);

	list.insert(s1);
	list.insert(s2);
	list.insert(s3);
	list.insert(s4);
	list.insert(s5);
	list.insert(s6);
	list.insert(s7);
	list.insert(s8);
	list.insert(s9);
	list.insert(s10);

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
	std::cout << "Soldado sobrevivente: " << list << std::endl;
}
// Testes funcionais
void tests()
{
	std::cout << std::endl << "< -------- TESTES FUNCIONAIS -------- > ";

	// Teste isEmpty
	{
		List list = List();
		std::cout << std::endl << "Teste da operacao isEmpty: " << std::endl;
		std::string empty = list.isEmpty() ? "true" : "false";
		std::cout << "\tIsEmpty: " << empty;
	}

	// Teste isFull
	{
		List list = List();
		std::cout << std::endl << "Teste da operacao isFull: " << std::endl;
		std::string empty = list.isFull() ? "true" : "false";
		std::cout << "\tIsFull: " << empty;
	}

	// Teste insert
	{
		List list = List();
		std::cout << std::endl << "Teste da operacao insert: " << std::endl;
		Soldier s1 = Soldier("Ricardo", 18);
		list.insert(s1);
		std::cout << "\tConteudo da lista: " << list;
	}
	// Teste remove
	{
		List list = List();
		std::cout << std::endl << "Teste da operacao remove: " << std::endl;
		Soldier s1 = Soldier("Ricardo", 18);
		list.remove(s1);
		std::cout << "\tConteudo da lista: " << list;
	}
	// Teste removeById
	{
		List list = List();
		std::cout << std::endl << "Teste da operacao removeById: " << std::endl;
		Soldier s1 = Soldier("Ricardo", 18);
		list.removeById(18);
		std::cout << "\tConteudo da lista: " << list;
	}
	// Teste removeByName
	{
		List list = List();
		std::cout << std::endl << "Teste da operacao removeByName: " << std::endl;
		Soldier s1 = Soldier("Ricardo", 18);
		list.removeByName("Ricardo");
		std::cout << "\tConteudo da lista: " << list;
	}
	// Teste clear
	{
		List list = List();
		std::cout << std::endl << "Teste da operacao clear: " << std::endl;
		Soldier s1 = Soldier("Ricardo", 18);
		Soldier s2 = Soldier("Paulo", 19);
		Soldier s3 = Soldier("Gabriel", 20);
		list.insert(s1);
		list.insert(s2);
		list.insert(s3);
		std::cout << "\tConteudo da lista (antes do clear): " << list << std::endl;
		list.clear();
		std::cout << "\tConteudo da lista (depois do clear): " << list;
	}
	// Teste find
	{
		List list = List();
		std::cout << std::endl << "Teste da operacao find: " << std::endl;
		Soldier s1 = Soldier("Ricardo", 18);
		std::cout << "\tConteudo da lista: " << list << std::endl;
		std::string found = list.find(s1) ? "true" : "false";
		std::cout << "\tEncontrou antes de adicionar: " << found << std::endl;
		list.insert(s1);
		found = list.find(s1) ? "true" : "false";
		std::cout << "\tEncontrou depois de adicionar: " << found << std::endl;
		std::cout << "\tConteudo da lista: " << list;
	}
	// Teste findById
	{
		List list = List();
		std::cout << std::endl << "Teste da operacao findById: " << std::endl;
		Soldier s1 = Soldier("Ricardo", 18);
		list.insert(s1);
		std::cout << "\tConteudo da lista: " << list;
		Soldier soldier = list.findById(18);
		std::cout << "\n\tSoldado: " << soldier;
	}
	// Teste findByName
	{
		List list = List();
		std::cout << std::endl << "Teste da operacao findByName: " << std::endl;
		Soldier s1 = Soldier("Ricardo", 18);
		list.insert(s1);
		std::cout << "\tConteudo da lista: " << list;
		Soldier soldier = list.findByName("Ricardo");
		std::cout << "\n\tSoldado: " << soldier;
	}
	// Teste findByPosition
	{
		List list = List();
		std::cout << std::endl << "Teste da operacao findByPosition: " << std::endl;
		Soldier s1 = Soldier("Ricardo", 18);
		Soldier s2 = Soldier("Paulo", 19);
		Soldier s3 = Soldier("Gabriel", 20);

		list.insert(s1);
		list.insert(s2);
		list.insert(s3);

		std::cout << "\tConteudo da lista: " << list;

		Soldier soldier1 = list.findByPosition(0);
		Soldier soldier2 = list.findByPosition(1);
		Soldier soldier3 = list.findByPosition(2);

		std::cout << "\n\tSoldado 1: " << soldier1 << std::endl;
		std::cout << "\tSoldado 2: " << soldier2 << std::endl;
		std::cout << "\tSoldado 3: " << soldier3;
	}

	// Teste findPosition
	{
		List list = List();
		std::cout << std::endl << "Teste da operacao findPosition: " << std::endl;
		Soldier s1 = Soldier("Ricardo", 18);
		Soldier s2 = Soldier("Paulo", 19);
		Soldier s3 = Soldier("Gabriel", 20);

		list.insert(s1);
		list.insert(s2);
		list.insert(s3);

		std::cout << "\tConteudo da lista: " << list;

		unsigned int pos1 = list.findPosition(s1);
		unsigned int pos2 = list.findPosition(s2);
		unsigned int pos3 = list.findPosition(s1);

		std::cout << "\n\tSoldado Ricardo: " << pos1 << std::endl;
		std::cout << "\tSoldado Paulo: " << pos2 << std::endl;
		std::cout << "\tSoldado Gabriel: " << pos3;
	}
	// Teste getSize
	{
		List list = List();
		std::cout << std::endl << "Teste da operacao getSize: " << std::endl;

		Soldier s1 = Soldier("Ricardo", 18);
		Soldier s2 = Soldier("Paulo", 19);
		Soldier s3 = Soldier("Gabriel", 20);

		list.insert(s1);
		list.insert(s2);
		list.insert(s3);

		std::cout << "\tTamanho da lista: " << list.getSize();
	}
	// Teste toString
	{
		List list = List();
		std::cout << std::endl << "Teste da operacao toString: " << std::endl;

		Soldier s1 = Soldier("Ricardo", 18);
		Soldier s2 = Soldier("Paulo", 19);
		Soldier s3 = Soldier("Gabriel", 20);

		list.insert(s1);
		list.insert(s2);
		list.insert(s3);

		std::cout << "\tConteudo da lista:" << list.toString();
	}
	// Teste overload operador <<
	{
		List list = List();
		std::cout << std::endl << "Teste do overload do operador << : " << std::endl;

		Soldier s1 = Soldier("Ricardo", 18);
		Soldier s2 = Soldier("Paulo", 19);
		Soldier s3 = Soldier("Gabriel", 20);

		list.insert(s1);
		list.insert(s2);
		list.insert(s3);

		std::cout << "\tConteudo da lista:" << list;
	}

	std::cout << std::endl << "Pressione uma tecla para continuar: " << std::endl;
	system("pause");
}

void menu()
{
	List list = List();
	std::cout << "MENU" << std::endl;
	int qnt = 5;
	Soldier soldier(0, 0);
	unsigned int num;
	std::string str;
	for (int i = 0; i < qnt; i++)
	{
		std::cout << "(" << i+1 << "/" << qnt << ")" << " Inserir Elemento na Lista : " << std::endl;

		std::cout << "Valor do inteiro: ";
		std::cin >> num;

		std::cout << "Valor da string: ";
		std::cin >> str;

		soldier = Soldier(str.c_str(), num);
		list.insert(soldier);

		std::cout << "Valor da lista: " << list.toString(true) << std::endl;
	}
	

	std::cout << std::endl << "Pressione uma tecla para continuar: " << std::endl;
	system("pause");
}