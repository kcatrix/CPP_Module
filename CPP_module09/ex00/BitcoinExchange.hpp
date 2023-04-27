#include <iostream>
#include <fstream>
#include <cstring>
#include <string.h>
#include <cstdlib>
#include <map>
#include <string>
#include <sstream>

using namespace std;

class BitcoinExchange
{
public:
	~BitcoinExchange();
	BitcoinExchange(std::string nom_fichier);
	void lire_fichier_ligne_par_ligne(std::string nom_fichier);
	bool init_database(void);
	void verifier_cle_valeur(std::string cle, std::string valeur, std::string ligne);
	bool parse_valeur(std::string valeur);
	bool parse_ligne(std::string ligne, std::string cle, std::string valeur);
	bool parse_cle(std::string cle);
	bool verif_format_cle(std::string year, std::string month, std::string day);
	bool checkAlpha(std::string tocheck);
	std::string getNewDate(std::string year, std::string month, std::string day);
	std::string remove_space(std::string str);
	
private:
	std::map<std::string, std::string> data;
	std::string year_stock;
	std::string month_stock;
	std::string day_stock;
};