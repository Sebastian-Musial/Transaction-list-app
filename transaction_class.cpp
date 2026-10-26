#include <string>
#include <iostream>
#include "transaction_class.hpp"

bool Transaction::transactionValidation(std::string T_name, std::string T_amount, std::string T_date, std::string T_category) {
    for(int i = 0; i < T_amount.size(); i++) {
        if(T_amount[i] < '0' || T_amount[i] > '9') {
            if(T_amount.size()-3 == i) continue;
            std::cout<<"Podana kwota jest niepoprawna - Amount is not correct"<<std::endl;
            return false;
        }
    }
    
    if(T_name.size() <= 0) { 
        std::cout<<"Nazwa transakcji jest za krotka - Transaction name is too short"<<std::endl;
        return false;
    }
    if(T_name.size() > 26) {
        std::cout<<"Nazwa transakcji jest za dluga (Rozmiar nazwy > 26)- Transaction name is too long (Name size > 26)"<<std::endl;
        return false;   
    }
    if( T_amount == "" || std::stod(T_amount) <= 0 ) {
        std::cout<<"Kwota transakcji jest za mala (Kwota <= 0) - Transaction amount is too small (Amount <= 0)"<<std::endl;
        return false;
    }
    if(T_amount.size() > 10) {
        std::cout<<"Podana kwota jest za duza (>1000000.00) - Amount is to big (>1000000.00)"<<std::endl;
        return false;
    }
    if(!dateValidation(T_date)) return false;
    if(T_category.size() > 26) {
        std::cout<<"Kategoria transakcji jest za dluga (Rozmiar nazwy kategori > 26)- Transaction category name is too long (Category name size > 26)"<<std::endl;
        return false;   
    }
    return true;
}

bool Transaction::dateValidation(std::string T_date) {
    //YYYY-MM-DD
    bool leapYear = false;
    int daysInMonth[] = {
        31, 28, 31, 30, 31, 30,
        31, 31, 30, 31, 30, 31
    };

    if(T_date.size() != 10) {
        std::cout<<"Podana date jest nie poprawna - Date is not correct"<<std::endl;
        return false;
    }

    if(T_date[4] != '-' && T_date[7] != '-' ) {
        std::cout<<"Podany format daty nie jest poprawny - Date form is not correct"
                    "\nPoprawny format [YYYY-MM-DD] - correct form [YYYY-MM-DD]"<<std::endl;
        return false;
    }

    for(int i = 0; i < 10; i++) {
        if(i == 4 || i == 7) continue; 
        
        if(T_date[i] < '0' || T_date[i] > '9') {
            std::cout<<"Podana data nie jest poprawna - Date is not correct"<<std::endl;
            std::cout<<"Uzywaj tylko cyfr i znaku '-' - Use only a digits and character '-' "<<std::endl;
            return false;
        }
    }

    if( std::stoi(T_date.substr(0, 4)) < 1 ) {
        std::cout<<"Rok musi byc wiekszy od 0 - Year must be bigger from 0"<<std::endl;
        return false;
    }

    int year = std::stoi(T_date.substr(0, 4));
    if((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)) leapYear = true;

    if( std::stoi(T_date.substr(5, 2)) < 1 || std::stoi(T_date.substr(5, 2)) > 12 ) {
        std::cout<<"Niepoprawny miesiac - Month is not correct"<<std::endl;
        return false;
    }

    int month = std::stoi(T_date.substr(5, 2));

    if (leapYear && month == 2) {
        if( std::stoi(T_date.substr(8, 2)) < 1 || std::stoi(T_date.substr(8, 2)) > 29 ) {
            std::cout<<"W roku przystepnym luty ma 29 dni - In leap year, february has 29 days"<<std::endl;
            std::cout<<"Bledny dzien - Wrong day"<<std::endl;
            return false;
        }
    }
    else {
        if( std::stoi(T_date.substr(8, 2)) < 1 || std::stoi(T_date.substr(8, 2)) > daysInMonth[month - 1]) {
            std::cout<<"Bledny dzien - Wrong day"<<std::endl;
            return false;
        }
    }
    
    return true;
}