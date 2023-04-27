#include "PmergeMe.hpp"

PmergeMe::PmergeMe(vector <int> arr)
{
    struct timeval start, end;
    long seconds, microseconds;
    gettimeofday(&start, NULL); 
    int nb_tab = 2;
    triFusionInsertion(arr, 0, arr.size() - 1, nb_tab);
    gettimeofday(&end, NULL); // enregistre l'heure de fin de l'exécution
    seconds = end.tv_sec - start.tv_sec;
    microseconds = end.tv_usec - start.tv_usec;
    double elapsed_time = seconds + double(microseconds) / 1000000;
    Sup_doublons(arr);
    cout << "After: ";
    PrintVector(arr);
    std::cout << "Time to process a range of " << arr.size() << " elements with std::vector : " << std::fixed << std::setprecision(6) << elapsed_time << " us" << std::endl;
}

PmergeMe::PmergeMe(list <int> list)
{
    struct timeval start, end;
    long seconds, microseconds;
    gettimeofday(&start, NULL); 
    triFusionInsertion_lst(list, 0, list.size() - 1);
    gettimeofday(&end, NULL); // enregistre l'heure de fin de l'exécution
    seconds = end.tv_sec - start.tv_sec;
    microseconds = end.tv_usec - start.tv_usec;
    double elapsed_time = seconds + double(microseconds) / 1000000;
    Sup_doublons_lst(list);
    std::cout << "Time to process a range of " << list.size() << " elements with std::list : " << std::fixed << std::setprecision(6) << elapsed_time << " us" << std::endl;
}

PmergeMe::~PmergeMe()
{
}

void PrintVector(vector<int> arr)
{
    for (long unsigned int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void PrintList(list<int> lst)
{
    for (list<int>::iterator it = lst.begin(); it != lst.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}


vector<int> getVector(int ac, char** av)
{
    vector<int> arr;
    int i = 1;
    while (i < ac)
    {
        arr.push_back(atoi(av[i]));
        i++;
    }
    return arr;
}

list<int> getlist(int ac, char** av)
{
    list<int> list;
    int i = 1;
    while (i < ac)
    {
        list.push_back(atoi(av[i]));
        i++;
    }
    return list;
}

void Sup_doublons(vector<int>& arr)
{
    std::vector<int>::iterator it = std::unique(arr.begin(), arr.end());
    arr.erase(it, arr.end());;
}

void Sup_doublons_lst(list<int>& list)
{
    list.unique();
}

bool parse(int ac, char** av)
{
    if (ac < 2)
    {
        cout << "Error: Wrong number of arguments" << endl;
        return false;
    }
	if (verif_digit(ac, av) == false)
        return false;
    return true;
}

bool verif_digit(char ac, char** av)
{
    int i = 1;
    int j = 0;
    while (i < ac)
    {
        j = 0;
        while (av[i][j])
        {
            if (isDigit(av[i][j]) == false)
            {
                cout << "Error" << endl;
                return false;
            }
            j++;
        }
        i++;
    }
	return true;
}

bool isDigit(char c)
{
    if (c >= '0' && c <= '9')
        return (true);

    return (false);
}

// Fusionne deux tableaux triés
void PmergeMe::fusionner(vector<int>& arr, int gauche, long unsigned int milieu, long unsigned int droite)
{
    long unsigned int i, j, k;
    vector<int> tableau_gauche, tableau_droite;

    // Copie des données des deux moitiés dans les tableaux temporaires
    for (i = gauche; i <= milieu; i++) {
        tableau_gauche.push_back(arr[i]);
    }
    for (i = milieu + 1; i <= droite; i++) {
        tableau_droite.push_back(arr[i]);
    }
    i = j = 0;
    k = gauche;

    // Fusionne les deux tableaux temporaires dans le tableau d'origine
    while (i < tableau_gauche.size() && j < tableau_droite.size()) {
        if (tableau_gauche[i] < tableau_droite[j]) {
            arr[k++] = tableau_gauche[i++];
        }
        else {
            arr[k++] = tableau_droite[j++];
        }
    }

    // Copie les éléments restants du tableau_gauche dans arr
    while (i < tableau_gauche.size()) {
        arr[k++] = tableau_gauche[i++];
    }

    // Copie les éléments restants du tableau_droite dans arr
    while (j < tableau_droite.size()) {
        arr[k++] = tableau_droite[j++];
    }
}

// Trie les sous-tableaux par insertion
void PmergeMe::triInsertion(vector<int>& arr, int gauche, int droite)
{
    for (int i = gauche + 1; i <= droite; i++) {
        int cle = arr[i];
        int j = i - 1;

        while (j >= gauche && arr[j] > cle) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = cle;
    }
}

// Trie le tableau par l'algorithme Merge-Insert
void PmergeMe::triFusionInsertion(vector<int>& arr, int gauche, int droite, int k)
{
    if (gauche >= droite) {
        return;
    }
    else if (droite - gauche + 1 <= k) {
        triInsertion(arr, gauche, droite);
    }
    else {
        int milieu = (gauche + droite) / 2;
        triFusionInsertion(arr, gauche, milieu, k);
        triFusionInsertion(arr, milieu + 1, droite, k);
        fusionner(arr, gauche, milieu, droite);
    }
}

// Liste triée

int PmergeMe::Indice(std::list<int>& list, int pos)
{
    int poscheck = 0;
    std::list<int>::iterator it = list.begin();
    while(it != list.end())
    {
        if(pos == poscheck)
        {
            return *it;
        }
        it++;
        poscheck++;
    }
    return 0;
}

void PmergeMe::triInsertion_lst(std::list<int>& list, std::list<int>&temp, int min, int max)
{
    int checkpos = 0;
    std::list<int>::iterator it = list.begin();
    std::list<int>::iterator ittemp = temp.begin();
    while(checkpos < min)
    {
        checkpos++;
        it++;
    }
    while(min <= max)
    {
        *it = *ittemp;
        it++;
        ittemp++;
        min++;
    }
}

void PmergeMe::triFusionInsertion_lst(std::list<int>& list, int min, int max) 
{
	if (min < max) 
    {
		int middle = (min + max) / 2;
		triFusionInsertion_lst(list, min, middle);
		triFusionInsertion_lst(list, middle + 1, max);
		MergeSortedRangeList(list, min, middle, max);
	}
}


void PmergeMe::MergeSortedRangeList(std::list<int>& list, int min, int middle, int max) 
{
	
	std::list<int> temp;

	int i, j;
	i = min;
	j = middle + 1;
	while (i <= middle && j <= max)
    {
		if (Indice(list, i) <= Indice(list, j))
        {
			temp.push_back(Indice(list, i));
			++i;
		}
		else {
			temp.push_back(Indice(list, j));
			++j;
		}

	}

	while (i <= middle) 
    {
		temp.push_back(Indice(list, i));
		++i;
	}

	while (j <= max)
    {
		temp.push_back(Indice(list, j));
		++j;
	}
    triInsertion_lst(list, temp, min, max);
}
