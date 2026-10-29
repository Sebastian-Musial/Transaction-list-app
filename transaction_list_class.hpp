#pragma once

#include "transaction_class.hpp"
#include <vector>
#include <iostream>

class Transaction_list {
    public:
        Transaction_list() {};
        Transaction_list(std::string T_name, double T_amount, std::string T_date, std::string T_category) { 
            list.push_back(Transaction(T_name, T_amount, T_date, T_category));
        };
        Transaction_list(std::string T_name, std::string T_amount, std::string T_date, std::string T_category) { 
            list.push_back(Transaction(T_name, T_amount, T_date, T_category));
        };
        Transaction_list(std::initializer_list<Transaction> init_list) : list(init_list){}
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
                std::string tempString_T_amount = std::to_string(T_amount);
                int dot_index;
                bool dot_exists = false;
                
                for(int i = 0; i < tempString_T_amount.size(); i++) {
                    if(tempString_T_amount[i] == '.') {
                        dot_index = i;
                        dot_exists = true;
                        break;
                    }
                }

                if(dot_exists) list.push_back(Transaction(T_name, tempString_T_amount.substr(0, dot_index + 3), T_date, T_category));
                else list.push_back(Transaction(T_name, tempString_T_amount, T_date, T_category));
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
            std::cout<<"TRANSAKCJA ["<<i<<"] ZOSTALA SKASOWANA  - TRANSACTION ["<<i<<"] HAS DELETED"<<std::endl;
        }

        void modifyTransaction(int i, std::string T_name, std::string T_amount, std::string T_date, std::string T_category) {
            if(i < 0 || i > list.size()) {
                std::cout<<"Podana transakcja do modyfikacji jest nie prawidlowa - Transaction to modify is not correct"<<std::endl;
                return;
            }
            list[i].modifyTransaction(T_name, T_amount, T_date, T_category);
        }
        void modifyTransacion(int i, std::string T_name, double T_amount, std::string T_date, std::string T_category) {
            if(i < 0 || i > list.size()) {
                std::cout<<"Podana transakcja do modyfikacji jest nie prawidlowa - Transaction to modify is not correct"<<std::endl;
                return;
            }
            list[i].modifyTransaction(T_name, T_amount, T_date, T_category);
        }
        void modifyTransacion(int i, std::string T_name, int T_amount, std::string T_date, std::string T_category) {
            if(i < 0 || i > list.size()) {
                std::cout<<"Podana transakcja do modyfikacji jest nie prawidlowa - Transaction to modify is not correct"<<std::endl;
                return;
            }
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
        void filterByCategory(std::string T_category) const;

    //Aggregations
        void sumOfAllTransactions() const;
        void sumOfAllTransactionsInOneCategory(std::string T_category) const;
        void sumOfAllTransactionsInCategories() const;
        void MinAmount() const;
        void MaxAmount() const;

    private:
        int size = 0;
        std::vector<Transaction> list {}; 
};