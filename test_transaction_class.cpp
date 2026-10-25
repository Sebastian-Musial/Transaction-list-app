#include <iostream>
#include <string>
#include <vector>
#include "test_transaction_class.hpp"
#include "transaction_class.hpp"

bool test_transaction() {
    bool Test_pass = true;
    Transaction test_tab[6] {};

    //Correct trsansaction
    try {
        test_tab[0] = Transaction("N_test", "0.01", "25-10-2026", "");
    }
    catch (Transaction::Errors error) {
        std::cout<<"Blad dla: [\"N_test\", \"0.01\", \"25-10-2026\", \"\"]"
            "\nError for: [\"N_test\", \"0.01\", \"25-10-2026\", \"\"]"<<std::endl;
        Test_pass = false;
    }

    try {
        test_tab[1] = Transaction("N_test", "100", "25-10-2026", "C_test");
    }
    catch (Transaction::Errors error) {
        std::cout<<"Blad dla: [\"N_test\", \"100\", \"25-10-2026\", \"C_test\"]"
            "\nError for: [\"N_test\", \"100\", \"25-10-2026\", \"C_test\"]"<<std::endl;
        Test_pass = false;
    }

    try {
        test_tab[2] = Transaction("N_test", "100.123", "25-10-2026", "");
    }
    catch (Transaction::Errors error) {
        std::cout<<"Blad dla: [\"N_test\", \"100.123\", \"25-10-2026\", \"\"]"
            "\nError for: [\"N_test\", \"100.123\", \"25-10-2026\", \"\"]"<<std::endl;
        Test_pass = false;
    }

    //Incorrect transaction
    int correct_test = 0;
    try {
        test_tab[3] = Transaction("N_test", "100", "", "");
    }
    catch (Transaction::Errors error) {
        correct_test++;
        std::cout<<"wyjatek zlapany"<<std::endl;
    }

    try {
        test_tab[4] = Transaction("N_test", "", "25-10-2026", "");
    }
    catch (Transaction::Errors error) {
        correct_test++;
        std::cout<<"wyjatek zlapany"<<std::endl;
    }

    try {
        test_tab[5] = Transaction("N_test", "0", "25-10-2026", "C_test");
    }
    catch (Transaction::Errors error) {
        correct_test++;
        std::cout<<"wyjatek zlapany"<<std::endl;
    }

    if(correct_test != 3) Test_pass = false;

    if(Test_pass == false) return Test_pass;

    std::cout<<"TEST MODYFIKACJI TRANSAKCJI UTWORZONYCH - TEST OF MODIFICATIONS TO CREATED TRANSACTIONS"<<std::endl;
    std::cout<<"Transakcje przed - Transactions before"<<std::endl;

    for(int i = 0; i < 3; i++) {
        test_tab[i].showTransaction();
    }

    test_tab[0].modifyTransaction("Modfify_1", "1234", "25-10-2026", "Modify");
    test_tab[1].modifyTransaction("Modfify_2", 2133, "25-10-2026", "Modify");
    test_tab[2].modifyTransaction("Modfify_3", "1234", "25-10-2026", "Modify");

    std::cout<<"Transakcje po - Transactions after"<<std::endl;

    for(int i = 0; i < 3; i++) {
        test_tab[i].showTransaction();
    }

    return Test_pass;
}

bool test_transaction_valid() {
    class test_trx {
        public:
            std::string T_name;
            std::string T_amount;
            std::string T_date;
            std::string T_category;
    };

    std::vector<test_trx> test_bugs;

    test_trx test_tab_correct_transaction[] = {
        {"N_test", "0.01", "25-10-2026", ""},
        {"N_test", "100", "25-10-2026", "" },
        {"N_test", "100", "25-10-2026", "C_test"}, 
        {"N_test", "0.01", "25-10-2026", "C_test"},
        {"N_test", "100.123", "25-10-2026", "C_test"},
        {"N_test", "100.123", "25-10-2026", ""},
    };

    test_trx test_tab_wrong_transaction[] = {
        {"", "", "", ""},
        {"N_test", "", "", ""},
        {"", "100", "", ""},
        {"", "", "", "C_test"},
        {"", "", "25-10-2026", ""},
        {"N_test", "100", "", ""},
        {"N_test", "", "25-10-2026", ""},
        {"", "100", "25-10-2026", ""},
        {"N_test", "-100", "25-10-2026", "C_test"},
        {"N_test", "0", "25-10-2026", "C_test"},
        {"N_test", "-100", "25-10-2026", ""},
        {"N_test", "0", "25-10-2026", ""},
    };

    for(test_trx X : test_tab_correct_transaction) {
        if(!Transaction::transactionValidation(X.T_name, X.T_amount, X.T_date, X.T_category)) {
            test_bugs.push_back(X);
        }
    }

    for(test_trx X : test_tab_wrong_transaction) {
        if(Transaction::transactionValidation(X.T_name, X.T_amount, X.T_date, X.T_category)) {
            test_bugs.push_back(X);
        }
    }

    if(test_bugs.size() != 0) {
        return false;
    }
    else return true;
}

bool test_date_valid() {
    std::vector<std::string> test_bugs;
    std::string test_tab_correct_date[] = {
        //Poprawne daty - correct date [TRUE]
        {"2025-01-01"},
        {"2025-12-31"},
        {"2025-06-15"},
        {"2024-02-29"},
        {"2000-02-29"},
        {"2023-02-28"},
        {"2025-04-30"},
        {"2025-07-31"},
        {"0001-01-01"},
        {"9999-12-31"},
        //Lata przestępne - Leap years
        {"2024-02-29"}, //True
        {"2000-02-29"}, //True
        {"2400-02-29"}, //True
        //Graniczne wartości - Boundary values
        {"9999-12-31"},
        {"2025-02-28"},
        {"2024-02-29"}
    };

    std::string test_tab_wrong_date[] = {
        //Niepoprawne dni - Not correct date 
        {"2025-01-00"},
        {"2025-01-32"},
        {"2025-04-31"},
        {"2025-06-31"},
        {"2025-09-31"},
        {"2025-11-31"},
        {"2025-02-29"},
        {"2024-02-30"},
        {"2023-02-30"},
        //Lata przestępne - Leap years
        {"2023-02-29"}, 
        {"1900-02-29"}, 
        {"2100-02-29"}, 
        //Niepoprawne miesiące - Not correct months 
        {"2025-00-15"}, 
        {"2025-13-15"}, 
        {"2025-99-15"}, 
        //Niepoprawny format - Incorrect form 
        {"2025-1-01"}, 
        {"2025-01-1"}, 
        {"25-01-01"}, 
        {"20250-01-01"}, 
        {"2025/01/01"},
        {"2025.01.01"},
        {"20250101"},
        {"2025--01-01"},
        {"01-01-2025"},
        //Niepoprawne znaki - Wrong characters 
        {"abcd-ef-gh"},
        {"202a-01-01"},
        {"2025-0a-01"},
        {"2025-01-0b"},
        {"2025-+1-01"},
        {"2025-01--1"},
        //Puste i dodatkowe znaki - Empty and additional characters 
        {""},
        {" "},
        {"2025-01-01 "},
        {" 2025-01-01"},
        {"2025-01-01abc"},
        {"\n2025-01-01"},
        //Graniczne wartości - Boundary values
        {"0000-01-01"}, 
        {"10000-01-01"}, 
        {"2024-02-31"} 
    };

    for(std::string X : test_tab_correct_date) {
        if(!Transaction::dateValidation(X)) {
            test_bugs.push_back(X);
        }
    }

    for(std::string X : test_tab_wrong_date) {
        if(Transaction::dateValidation(X)) {
            test_bugs.push_back(X);
        }
    }

    if(test_bugs.size() != 0) {
        return false;
    }
    else return true;
}




