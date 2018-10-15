#ifndef ZODIAC_LIST_H
#define ZODIAC_LIST_H

#include <map>            // Контейнер для создания словаря

//#ifndef RUSSIAN
std::map <std::string, std::string> zodiac_list = {
  {"Aries", "21.03-20.04"}, 	//овен
  {"Taurus", "21.04-20.05"},	//телец
  {"Gemini", "21.05-20.06"},	//близнецы
  {"Cancer", "21.06-20.07"},	//рак
  {"Leo", "21.07-20.08"},	//лев
  {"Virgo", "21.08-20.09"},	//дева
  {"Libra", "21.09-20.10"},	//весы
  {"Scorpio", "21.10-20.11"},	//скорпион
  {"Sagittarius", "21.11-20.12"},	//стрелец
  {"Capricorn", "21.12-20.01"},	//козерог
  {"Aquarius", "21.01-20.02"},	//водолей
  {"Pisces", "21.02-20.03"},	//рыбы
};
//#endif
#endif // ZODIAC_LIST_H
