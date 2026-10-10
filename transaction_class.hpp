#pragma once

#include <string>
#include <iostream>
#include <iomanip> 

class Transaction {
    public:
        Transaction(std::string T_name, double T_amount, std::string T_date, std::string T_category) : name{T_name}, amount{T_amount}, date{T_date}, category{T_category} {}
        ~Transaction() {
            std::cout<<"TRANSAKCJA ZOSTALA SKASOWANA - TRANSACTION HAS DELETED"<<std::endl;
        }

        //Get
        std::string getName() const {
            return name;
        }

        double getAmount() const {
            return amount;
        }

        std::string getCategory() const {
            return category;
        }

        std::string getdate() const {
            return date;
        }

        //Set
        void setName(std::string T_name) {
            name = T_name;
        }
        
        void setAmount(double T_amount) {
            amount = T_amount;
        }

        void setCategory(std::string T_category) {
            category = T_category;
        }
        
        void setdate(std::string T_date) {
            date = T_date;
        }

        //--------
        void showTransaction() const {
            std::cout<<std::setw(26)<<name<<" | "<<std::setw(10)<<amount<<" | "<<std::setw(10)<<date<<" | "<<std::setw(26)<<category<<std::endl;
        }

    private:
        std::string name;
        double amount;
        std::string date;
        std::string category = "------";
};