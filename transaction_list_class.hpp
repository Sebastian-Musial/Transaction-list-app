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

    private:
        int size = 0;
        std::vector<Transaction> list {}; 
};