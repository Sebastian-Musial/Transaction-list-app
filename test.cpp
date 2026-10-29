#include <iostream>
#include "test_transaction_class.hpp"
#include "test_transaction_list_class.hpp"

int main() {
    std::cout<<"TEST FOR TRANSACTION CLASS"<<std::endl;
    try {
        if(test_transaction()) std::cout<<"test_transaction [PASS]\n\n"<<std::endl;
        else std::cout<<"test_transaction [NOT PASS]\n\n"<<std::endl;
        if(test_transaction_valid()) std::cout<<"test_transaction_valid [PASS]\n\n"<<std::endl;
        else std::cout<<"test_transaction_valid [NOT PASS]\n\n"<<std::endl;
        if(test_date_valid()) std::cout<<"test_date_valid [PASS]\n\n"<<std::endl;
        else std::cout<<"test_date_valid [NOT PASS]\n\n"<<std::endl;
    }
    catch (...) {}
    char stop;
    std::cout<<"Write letter and press enter to continue"<<std::endl;
    std::cin>>stop;

    std::cout<<"\nTEST FOR TRANSACTION LIST CLASS"<<std::endl;
    try {
        test_transaction_list();
    }
    catch (...) {}
    std::cout<<"Write letter and press enter to end test"<<std::endl;
    char stop2;
    std::cin>>stop2;

}