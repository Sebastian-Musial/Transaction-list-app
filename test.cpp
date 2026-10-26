#include <iostream>
#include "test_transaction_class.hpp"

int main() {
    try {
    if(test_transaction()) std::cout<<"test_transaction [PASS]\n\n"<<std::endl;
    else std::cout<<"test_transaction [NOT PASS]\n\n"<<std::endl;
    if(test_transaction_valid()) std::cout<<"test_transaction_valid [PASS]\n\n"<<std::endl;
    else std::cout<<"test_transaction_valid [NOT PASS]\n\n"<<std::endl;
    if(test_date_valid()) std::cout<<"test_date_valid [PASS]\n\n"<<std::endl;
    else std::cout<<"test_date_valid [NOT PASS]\n\n"<<std::endl;
    }
    catch (...) {}
            int stop;
        std::cin>>stop;
}