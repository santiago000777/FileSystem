#include "common.h"
#include "File.h"

class A {
public:
	A() {}
	A(int i, float d) {
		this->i = i;
		this->d = d;
	}
	int GetSize() const {
		return sizeof(i) + sizeof(d) + sizeof(x);
	}

	int i { 1 };
	float d { 1.54f };
	char x = 'a';
};

#define STATE	1
int main() {
	File file("BinExample.bin");

	std::vector<A> vA;
	vA.push_back({ 4, 8.54f });
	vA.push_back({ 15, 0.57f });

	std::vector<int> vI { 4, 5, 7 };

	std::string s = "Ahoj";

	//	const int* p1  -> p1 je pointer na constantu int
	//	int *const p2  -> p2 je constantni pointer na int
	//	int const* p3  -> p3 je pointer na constantu int
	
#if STATE == 0
	file.Clear();
	file.Open(File::MODE::WRITE);
	
	file.Save(vA, vA[0].GetSize());

	file.Save(vI);

	file.Save(s);

	std::cout << "Prepsano!\n";
#elif STATE == 1
	file.Open(File::MODE::READ);

	std::vector<A> result;
	file.Load(result, 9);
	std::vector<int> resultI;
	file.Load(resultI);
	std::string resultS;
	file.Load(resultS);

#endif

	// Git commands
/*
	--CREATE GITHUB REPO--
	* git init									-> vytvoreni .git
	* git branch -M <branch>					-> tvorba nove branch
	* git remote add origin <pathFromGitHub>	-> vytvoreni remote s cestou, ktera se generuje na GitHubu -> musi se rucne repo vytvorit
	* git remote -v								-> kontrola remotu
		...

	--CLONE GITHUB REPO--
	* git clone <pathFromGitHub>				-> kopirovani repo z github

	--PULL--
	* git log									-> zobrazeni vsech commitu
	* git pull origin <branch>					-> nahrani do visual studia

	--COMMIT & PUSH--
	* git status								-> rozdily mezi kodem a poslednim commitem

	* git add <path>							-> pridani daneho souboru, ktery se zmenil, ke commitu
	* git add -A								-> pridani vsech souboru, ktery se zmenil, ke commitu

	* git commit -m "<msg>"						-> commit se zpravou
	* git push origin <branch>					-> nahrani do githubu

	--CHECKOUT--
	* git checkout <branch>						-> prechazeni na novou branch
	* git checkout <commit>						-> vraceni na dany commit
*/

}