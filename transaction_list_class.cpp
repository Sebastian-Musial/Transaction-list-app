#include <string>
#include "transaction_list_class.hpp"



void Transaction_list::sortByDate() const {
    if(list.size() == 0) {
        std::cout<<"Lista jest pusta"<<std::endl;
        return;
    }

    for(int i = 0; i < list.size(); i++) {
        std::string min = list[i].getdate();
        int minIndex = i;
        for(int x = i + 1; x < list.size(); i++) {
            if(min > list[x].getdate()) {
                min = list[x].getdate();
                minIndex = x;
            }
        }
        std::cout<<minIndex<<" | ";
        list[minIndex].showTransaction();
        std::cout<<"\n";
    }
}
void Transaction_list::sortByDateReverse() const {
    if(list.size() == 0) {
        std::cout<<"Lista jest pusta"<<std::endl;
        return;
    }

    for(int i = 0; i < list.size(); i++) {
        std::string max = list[i].getdate();
        int maxIndex = i;
        for(int x = i + 1; x < list.size(); i++) {
            if(max < list[x].getdate()) {
                max = list[x].getdate();
                maxIndex = x;
            }
        }
        std::cout<<maxIndex<<" | ";
        list[maxIndex].showTransaction();
        std::cout<<"\n";
    }
}