#pragma once

#include <string>
#include <iostream>
#include <iomanip> 

class Transaction {
    public:
        enum class Errors {
            Transaction_Validation_Error
        };
        Transaction(std::string T_name, double T_amount, std::string T_date, std::string T_category) {
            if(!transactionValidation(T_name, std::to_string(T_amount), T_date, T_category)) {
                throw Errors::Transaction_Validation_Error;
            }
            name = T_name;
            amount = T_amount;
            date = T_date;
            category = T_category;
            std::cout<<"TRANSAKCJA ZOSTALA UTWORZONA - TRANSACTION HAS CREATED"<<std::endl;
        }
        Transaction(std::string T_name, std::string T_amount, std::string T_date, std::string T_category) {
            if(!transactionValidation(T_name, T_amount, T_date, T_category)) {
                throw Errors::Transaction_Validation_Error;
            }
            name = T_name;
            amount = std::stod(T_amount);
            date = T_date;
            category = T_category;
            std::cout<<"TRANSAKCJA ZOSTALA UTWORZONA = TRANSACTION HAS CREATED"<<std::endl;
        }
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

        void modifyTransaction(std::string T_name, double T_amount, std::string T_date, std::string T_category) {
            if(!transactionValidation(T_name, std::to_string(T_amount), T_date, T_category)) {
                std::cout<<"TRANSAKCJA NIE ZOSTALA ZMODYFIKOWANA - TRANSACTION IS NOT MODIFY"<<std::endl;
                return;
            }
            name = T_name;
            amount = T_amount;
            date = T_date;
            category = T_category;
            std::cout<<"TRANSAKCJA ZOSTALA ZMODYFIKOWANA - TRANSACTION IS MODIFY"<<std::endl;
        }
        void modifyTransaction(std::string T_name, std::string T_amount, std::string T_date, std::string T_category) {
            if(!transactionValidation(T_name, T_amount, T_date, T_category)) {
                std::cout<<"TRANSAKCJA NIE ZOSTALA ZMODYFIKOWANA - TRANSACTION IS NOT MODIFY"<<std::endl;
                return;
            }
            name = T_name;
            amount = std::stod(T_amount);
            date = T_date;
            category = T_category;
            std::cout<<"TRANSAKCJA ZOSTALA ZMODYFIKOWANA - TRANSACTION IS MODIFY"<<std::endl;
        }

        //Valid
        bool transactionValidation(std::string T_name, std::string T_amount, std::string T_date, std::string T_category);
        bool dateValidation(std::string T_date);

    private:
        std::string name;
        double amount;
        std::string date;
        std::string category = "------";
};