#pragma once

#include "transaction_class.hpp"
#include <vector>
#include <iostream>

class Transaction_list {
    public:
        Transaction_list() {};
        ~Transaction_list() {
            std::cout<<"LISTA ZOSTALA SKASOWANA - LIST HAS DELETED"<<std::endl;
        }

    //Get
        int getSize() const {
            return size;
        }

        std::vector<Transaction> getList() const {
            return list;
        }

    //Set

    //--------
        void showAllTransaction() const {
            if(list.size() == 0) return;
            for(int i = 0; i < list.size(); i++) {
                std::cout<<i<<" | ";
                list[i].showTransaction();
                std::cout<<"\n";
            }
        }

        void addTransaction(std::string T_name, double T_amount, std::string T_date, std::string T_category) {
            try {
                list.push_back(Transaction(T_name, T_amount, T_date, T_category));
            }
            catch(Transaction::Errors Transaction_Validation_Error) {
                std::cout<<"TRANSAKCJA NIE ZOSTALA DODANA DO LISTY - TRANSACTION HAS NOT ADDED TO THE LIST"<<std::endl;
            }
        }
        void addTransaction(std::string T_name, std::string T_amount, std::string T_date, std::string T_category) {
            try {
                list.push_back(Transaction(T_name, T_amount, T_date, T_category));
            }
            catch(Transaction::Errors Transaction_Validation_Error) {
                std::cout<<"TRANSAKCJA NIE ZOSTALA DODANA DO LISTY - TRANSACTION HAS NOT ADDED TO THE LIST"<<std::endl;    
            }
        }

        void deleteTransaction(int i) {
            if(i < 0 || i > list.size()) {
                std::cout<<"Podana transakcja do usuniecia jest nie prawidlowa - Transaction to delete is not correct"<<std::endl;
                return;
            }
            list.erase(list.begin() + i);
        }

        void modifyTransaction(int i, std::string T_name, std::string T_amount, std::string T_date, std::string T_category) {
            list[i].modifyTransaction(T_name, T_amount, T_date, T_category);
        }
        void modifyTransacion(int i, std::string T_name, double T_amount, std::string T_date, std::string T_category) {
            list[i].modifyTransaction(T_name, T_amount, T_date, T_category);
        }

    //Sort
        void sortByDate() const;
        void sortByDateReverse() const;
        void sortByAmount() const;
        void sortByAmountReverse() const;
        void sortByCategory() const;

    //Filter
        void filterByDate(std::string date_1, std::string date_2) const;

    private:
        int size = 0;
        std::vector<Transaction> list {}; 
};