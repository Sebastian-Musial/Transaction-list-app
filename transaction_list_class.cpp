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
        for(int x = i + 1; x < list.size(); x++) {
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
        for(int x = i + 1; x < list.size(); x++) {
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

void Transaction_list::sortByAmount() const {
    if(list.size() == 0) {
        std::cout<<"Lista jest pusta"<<std::endl;
        return;
    }

    for(int i = 0; i < list.size(); i++) {
        double min = list[i].getAmount();
        int minIndex = i;
        for(int x = i + 1; x < list.size(); x++) {
            if(min > list[x].getAmount()) {
                min = list[x].getAmount();
                minIndex = x;
            }
        }
        std::cout<<minIndex<<" | ";
        list[minIndex].showTransaction();
        std::cout<<"\n";
    }
}
void Transaction_list::sortByAmountReverse() const {
    if(list.size() == 0) {
        std::cout<<"Lista jest pusta"<<std::endl;
        return;
    }

    for(int i = 0; i < list.size(); i++) {
        double max = list[i].getAmount();
        int maxIndex = i;
        for(int x = i + 1; x < list.size(); x++) {
            if(max < list[x].getAmount()) {
                max = list[x].getAmount();
                maxIndex = x;
            }
        }
        std::cout<<maxIndex<<" | ";
        list[maxIndex].showTransaction();
        std::cout<<"\n";
    }
}

void Transaction_list::sortByCategory() const {
    if(list.size() == 0) {
        std::cout<<"Lista jest pusta"<<std::endl;
        return;
    }

    std::vector<std::string> categories;
    categories.push_back(list[0].getCategory());

    for(int i = 0; i < list.size(); i++) {
        bool found = false;
        for(int x = 0; x < categories.size(); x++) {
            if(categories[x] == list[i].getCategory()) {
                found = true;
                break;
            }
        }
    
        if (!found) {
            categories.push_back(list[i].getCategory());
        }    
    }

    for(int i = 0; i < categories.size(); i++) {
        for(int x = 0; x < list.size(); x++) {
            if(categories[i] == list[x].getCategory()) {
                std::cout<<x<<" | ";
                list[x].showTransaction();
                std::cout<<"\n";
            }
        }
    }
}