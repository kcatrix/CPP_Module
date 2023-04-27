#include "BitcoinExchange.hpp"

template<typename T>
std::string to_string(const T & value) {
    std::ostringstream oss;
    oss << value;
    return oss.str();
}

BitcoinExchange::BitcoinExchange(std::string nom_fichier)
{
    if (init_database() == false)
    {
        std::cout << "Error: data not found" << std::endl;
        return ;
    }
	lire_fichier_ligne_par_ligne(nom_fichier);
}

BitcoinExchange::~BitcoinExchange()
{
}

bool BitcoinExchange::init_database(void)
{
    std::string nom_fichier = "data.csv";
    std::ifstream fichier(nom_fichier.c_str());
    if (fichier.is_open() == false)
        return (false);
    std::string ligne;
    while (std::getline(fichier, ligne)) {
        char* token = strtok(const_cast<char*>(ligne.c_str()), ",");
        std::string cle(token);
        token = strtok(NULL, ",");
        std::string valeur(token);
        data.insert(std::pair<std::string, std::string>(cle, valeur));
    }
    fichier.close();
    // for(std::map<string, string>::iterator it = data.begin(); (it != data.end()); it++)
    // {
    //     std::cout << it->first << " : " << it->second << std::endl;
    // }
    return (true);
}

void BitcoinExchange::lire_fichier_ligne_par_ligne(std::string nom_fichier) 
{
    std::ifstream fichier(nom_fichier.c_str());
    std::string ligne;
    if (fichier.is_open() == false)
    {
        std ::cout << "Error: could not open file." << std::endl;
        return ;
    }
    while (std::getline(fichier, ligne)) {
        char* token = strtok(const_cast<char*>(ligne.c_str()), "|");
        std::string cle(token);
        token = strtok(NULL, "|");
        if (token != NULL && checkAlpha(ligne) == false)
        {
            std::string valeur(token);
            verifier_cle_valeur(cle, valeur, ligne);
        }
        else if (checkAlpha(ligne) == true)
            continue;
        else
            std::cout << "Error: bad input => " << ligne << std::endl;
    }
    fichier.close();
}

void BitcoinExchange::verifier_cle_valeur(std::string cle, std::string valeur, std::string ligne)
{
    float calcul;
    std::string old_cle = cle;
    std::string old_valeur = valeur;
    float valeur_f = atof(valeur.c_str());
    if (parse_ligne(ligne, cle, valeur) == false || parse_cle(cle) == false || parse_valeur(valeur) == false)
        return ;
    
    cle = remove_space(cle);

    std::map<std::string, std::string>::iterator it = data.find(cle);
    while (it == data.end())
    {   
        cle = getNewDate(year_stock, month_stock, day_stock);
        it = data.find(cle);
    }
    calcul = atof(it->second.c_str()) * atof(valeur.c_str());
    std::cout << old_cle << "=> " << valeur_f << " = " << calcul << std::endl;
}

bool BitcoinExchange::parse_valeur(std::string valeur)
{
    float valeur_f = atof(valeur.c_str());
    if (valeur_f < 0)
    {
        std::cout << "Error: not a positive number" << std::endl;
        return false;
    }
    else if (valeur_f > 1000)
    {
        std::cout << "Error: too large a number" << std::endl;
        return false;
    }
    return true;
}

bool BitcoinExchange::parse_ligne(std::string ligne, std::string cle, std::string valeur)
{
    int i = 0;
    while(ligne[i])
    {
        if (ligne[i] != ' ' && (ligne[i] < '0' || ligne[i] > '9') && ligne[i] != '-')
        {
            std::cout << "Error: bad input => " << cle << " | " << valeur << std::endl;
            return false;
        }
         i++;
    }
    return true;
}

bool BitcoinExchange::parse_cle(std::string cle)
{
    int i = 0;
    int y = 0;
    while (cle[i])
    {
        if (cle[i] == '-')
            y++;
        i++;
    }
    if (y != 2)
    {
        std::cout << "Error: bad input => " << cle << std::endl;
        return false;
    }
    char* token = strtok( const_cast<char*>(cle.c_str()), "-");
    std::string cle1(token);
    token = strtok(NULL, "-");
    if (token == NULL)
    {
        std::cout << "Error: bad input => " << cle << std::endl;
        return false;
    }
    std::string cle2(token);
    token = strtok(NULL, "-");
    if (token == NULL)
    {
        std::cout << "Error: bad input => " << cle << std::endl;
        return false;
    }
    std::string cle3(token);
    year_stock = cle1;
    month_stock = cle2;
    day_stock = cle3;
    if (verif_format_cle(cle1, cle2, cle3) == false)
        return false;
    return true;

}

bool BitcoinExchange::verif_format_cle(std::string year, std::string month, std::string day)
{
    if (year.length() != 4 || month.length() != 2 || day.length() != 3)
    {
        std::cout << "Error: bad input => " << year << "-" << month << "-" << day << std::endl;
        return false;
    }
    int yearval = std::atoi(year.c_str());
    int monthval = std::atoi(month.c_str());
    int dayval = std::atoi(day.c_str());
    if(yearval > 2023 || yearval < 2009 || (yearval == 2009 && monthval == 1 && dayval == 1))
    {
        std::cout << "Error year:" << yearval << std::endl;
        return false;
    }
    else if(monthval < 1 || monthval > 12)
    {
        std::cout << "Error month:" << monthval << std::endl;
        return false;
    }
    else
    {
        if(monthval == 1)
        {
            if(dayval > 31 || dayval < 1)
            {
                std::cout << "Error day:" << dayval << std::endl;
                return false;
            }
        }
        else if(monthval == 2)
        {
            if(dayval > 28 || dayval < 1)
            {
                std::cout << "Error day:" << dayval << std::endl;
                return false;
            }

        }
        else if(monthval == 3)
        {
            if(dayval > 31 || dayval < 1)
            {
                std::cout << "Error day:" << dayval << std::endl;
                return false;
            }

        }
        else if(monthval == 4)
        {
            if(dayval > 30 || dayval < 1)
            {
                std::cout << "Error day:" << dayval << std::endl;
                return false;
            }
        }
        else if(monthval == 5)
        {
            if(dayval > 31 || dayval < 1)
            {
                std::cout << "Error day:" << dayval << std::endl;
                return false;
            }

        }
        else if(monthval == 6)
        {
            if(dayval > 30 || dayval < 1)
            {
                std::cout << "Error day:" << dayval << std::endl;
                return false;
            }

        }
        else if(monthval == 7)
        {
            if(dayval > 31 || dayval < 1)
            {
                std::cout << "Error day:" << dayval << std::endl;
                return false;
            }

        }
        else if(monthval == 8)
        {
            if(dayval > 31 || dayval < 1)
            {
                std::cout << "Error day:" << dayval << std::endl;
                return false;
            }

        }
        else if(monthval == 9)
        {
            if(dayval > 30 || dayval < 1)
            {
                std::cout << "Error day:" << dayval << std::endl;
                return false;
            }

        }
        else if(monthval == 10)
        {
            if(dayval > 31 || dayval < 1)
            {
                std::cout << "Error day:" << dayval << std::endl;
                return false;
            }

        }
        else if(monthval == 11)
        {
            if(dayval > 30 || dayval < 1)
            {
                std::cout << "Error day:" << dayval << std::endl;
                return false;
            }

        }
        else if(monthval == 12)
        {
            if(dayval > 31 || dayval < 1)
            {
                std::cout << "Error day:" << dayval << std::endl;
                return false;
            }
        }
    }
    return true;
}

std::string BitcoinExchange::getNewDate(std::string year, std::string month, std::string day)
{
    int yearval = std::atoi(year.c_str());
    int monthval = std::atoi(month.c_str());
    int dayval = std::atoi(day.c_str());

    if(dayval > 1)
    {
        dayval--;
    }
    else if(dayval == 1)
    {
        if(monthval > 1)
        {
            monthval--;
            dayval = 31;
        }
        else if(monthval == 1)
        {
            yearval--;
            monthval = 12;
            dayval = 31;
        }
    }
    year = to_string(yearval);
    month = to_string(monthval);
    day = to_string(dayval);
    year_stock = year;
    month_stock = month;
    day_stock = day;
    std::string newdate = year + "-";
    if (monthval < 10)
        newdate += "0" + month;
    else
        newdate += month;
    newdate += "-";
    if(dayval < 10)
        newdate += "0" + day;
    else
        newdate += day;
    return(newdate);
}

std::string BitcoinExchange::remove_space(std::string str)
{
  for(std::string::iterator it = str.begin(); it != str.end(); ++it) {
        if(*it == ' ') {
            str.erase(it);
            --it;
        }
    }
    return str;
}

bool BitcoinExchange::checkAlpha(std::string tocheck)
{
    int i = 0;

    while(tocheck[i])
    {
        if((tocheck[i] > 'a' && tocheck[i] < 'z') || (tocheck[i] > 'A' && tocheck[i] < 'Z'))
            return true;
        i++;
    }
    return false;
}