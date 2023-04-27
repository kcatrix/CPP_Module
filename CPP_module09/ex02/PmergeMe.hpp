#include <iostream>
#include <stack>
#include <cstdlib>
#include <string.h>
#include <list>
#include <vector>
#include <iterator>
#include <string>
#include <iomanip>
#include <sstream>
#include <sys/time.h>
#include <algorithm>

using namespace std;

bool parse(int ac, char** av);
bool isDigit(char c);
bool verif_digit(char ac, char** av);
vector<int> getVector(int ac, char** av);
list<int> getlist(int ac, char** av);
void PrintVector(vector<int> arr);
void PrintList(list<int> list);
void Sup_doublons(vector<int>& arr);
void Sup_doublons_lst(list<int>& list);

class PmergeMe
{
	public:
		PmergeMe(vector <int> arr);
		PmergeMe(list <int> list);
		// ------------------------------List---------------------------------
		int  Indice(std::list<int>& list, int pos);
		void triInsertion_lst(std::list<int>& list, std::list<int>&temp, int min, int max);
		void triFusionInsertion_lst(std::list<int>& list, int min, int max);
		void MergeSortedRangeList(std::list<int>& list, int min, int middle, int max);
		// ------------------------------Vector---------------------------------
		void triInsertion(vector<int>& arr, int gauche, int droite);
		void triFusionInsertion(vector<int>& arr, int gauche, int droite, int k);
		void fusionner(vector<int>& arr, int gauche, long unsigned int milieu, long unsigned int droite);
		~PmergeMe();
};