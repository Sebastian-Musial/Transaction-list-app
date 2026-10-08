#pragma once

#include <string>
#include <iostream>


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
        std::string setName(std::string T_name) {
            name = T_name;
        }
        
        double setAmount(double T_amount) {
            amount = T_amount;
        }

        std::string setCategory(std::string T_category) {
            category = T_category;
        }
        
        std::string setdate(std::string T_date) {
            date = T_date;
        }

    private:
        std::string name;
        double amount;
        std::string date;
        std::string category = "------";
};