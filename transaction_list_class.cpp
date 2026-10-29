#include <string>
#include <utility>
#include <algorithm>
#include "transaction_list_class.hpp"



void Transaction_list::sortByDate() const {
    if(list.size() == 0) {
        std::cout<<"Lista jest pusta"<<std::endl;
        return;
    }

    std::vector<Transaction> tempList = list;

    for(int i = 0; i < tempList.size(); i++) {
        std::string min = tempList[i].getdate();
        int minIndex = i;
        for(int x = i + 1; x < tempList.size(); x++) {
            if(min > tempList[x].getdate()) {
                min = tempList[x].getdate();
                minIndex = x;
            }
        }

        std::swap(tempList[i], tempList[minIndex]);

        std::cout<<i<<" | ";
        tempList[i].showTransaction();
        std::cout<<"\n";
    }
}
void Transaction_list::sortByDateReverse() const {
    if(list.size() == 0) {
        std::cout<<"Lista jest pusta"<<std::endl;
        return;
    }

    std::vector<Transaction> tempList = list;

    for(int i = 0; i < tempList.size(); i++) { 
        std::string max = tempList[i].getdate();
        int maxIndex = i;
        for(int x = i + 1; x < tempList.size(); x++) {
            if(max < tempList[x].getdate()) {
                max = tempList[x].getdate();
                maxIndex = x;
            }
        }

        std::swap(tempList[i], tempList[maxIndex]);

        std::cout<<i<<" | ";
        tempList[i].showTransaction();
        std::cout<<"\n";
    }
}

void Transaction_list::sortByAmount() const {
    if(list.size() == 0) {
        std::cout<<"Lista jest pusta"<<std::endl;
        return;
    }

    std::vector<Transaction> tempList = list;

    for(int i = 0; i < tempList.size(); i++) {  
        double min = tempList[i].getAmount();
        int minIndex = i;
        for(int x = i + 1; x < tempList.size(); x++) {
            if(min > tempList[x].getAmount()) {
                min = tempList [x].getAmount();
                minIndex = x;
            }
        }

        std::swap(tempList[i], tempList[minIndex]);

        std::cout<<i<<" | ";
        tempList[i].showTransaction();
        std::cout<<"\n";
    }
}
void Transaction_list::sortByAmountReverse() const {    
    if(list.size() == 0) {
        std::cout<<"Lista jest pusta"<<std::endl;
        return;
    }

    std::vector<Transaction> tempList = list;

    for(int i = 0; i < tempList.size(); i++) {
        double max = tempList[i].getAmount();
        int maxIndex = i;
        for(int x = i + 1; x < tempList.size(); x++) {
            if(max < tempList[x].getAmount()) {
                max = tempList[x].getAmount();
                maxIndex = x;
            }
        }

        std::swap(tempList[i], tempList[maxIndex]);

        std::cout<<i<<" | ";
        tempList[i].showTransaction();
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

///////////////////////////////////////////////////////////////

void Transaction_list::filterByDate(std::string date_1, std::string date_2) const {
    if(list.size() == 0) {
        std::cout<<"Lista jest pusta"<<std::endl;
        return;
    }
    
    std::string earlierDate;
    std::string laterDate;
    std::vector<Transaction> tempList = list;

    if(date_1 > date_2) {
        earlierDate = date_2;
        laterDate = date_1;
    }
    else {
        earlierDate = date_1;
        laterDate = date_2;
    }

    for(int i = 0; i < tempList.size(); i++) {
        std::string min = tempList[i].getdate();
        int minIndex = i;

        for(int x = i + 1; x < tempList.size(); x++) {
            if(min > tempList[x].getdate()) {
                min = tempList[x].getdate();
                minIndex = x;
            }
        }

        std::swap(tempList[i], tempList[minIndex]);

        if(tempList[i].getdate() >= earlierDate && tempList[i].getdate() <= laterDate) {
            std::cout<<i<<" | ";
            tempList[i].showTransaction();
            std::cout<<"\n";
        }
    }
}

void Transaction_list::filterByCategory(std::string T_category) const { 
    if(list.size() == 0) {
        std::cout<<"Lista jest pusta"<<std::endl;
        return;
    }

    for(int i = 0; i < list.size(); i++) {
        if(list[i].getCategory() == T_category) {
            std::cout<<i<<" | ";
            list[i].showTransaction();
            std::cout<<"\n";
        }
    }
}

///////////////////////////////////////////////////////////////

void Transaction_list::sumOfAllTransactions() const {
    if(list.size() == 0) {
        std::cout<<"Lista jest pusta"<<std::endl;
        return;
    }

    double sum = 0;
    for(int i = 0; i < list.size(); i++) sum += list[i].getAmount();
    std::cout<<"Suma wszystkich transakcji wynosi: "<<sum<<std::endl; 
}

void Transaction_list::sumOfAllTransactionsInOneCategory(std::string T_category) const {
    if(list.size() == 0) {
        std::cout<<"Lista jest pusta"<<std::endl;
        return;
    }
    
    double sum = 0;
    for(int i = 0; i < list.size(); i++) {
        if(list[i].getCategory() == T_category) { 
            sum += list[i].getAmount();
        }
    }
    std::cout<<"Suma wszystkich transakcji dla kategori \""<<T_category<<"\" wynosi: "<<sum<<std::endl;
}

void Transaction_list::sumOfAllTransactionsInCategories() const {
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

    double* sum = nullptr;
    sum = new double [categories.size()]();

    for(int i = 0; i < categories.size(); i++) {
        for(int x = 0; x <list.size(); x++) {
            if(categories[i] == list[x].getCategory()) {
                sum[i] += list[x].getAmount(); 
            }
        }
        std::cout<<"Suma kategori \""<<categories[i]<<"\" : "<<sum[i]<<std::endl;
    }

    delete[] sum;
}

void Transaction_list::MinAmount() const {
    if(list.size() == 0) {
        std::cout<<"Lista jest pusta"<<std::endl;
        return;
    }

    double min = list[0].getAmount();
    for(int i = 0; i <list.size(); i++) {
        if(list[i].getAmount() < min) {
            min = list[i].getAmount();
        }
    }

    std::cout<<"Najmniejsza transakcja byla wykonana na kwote: "<<min<<std::endl;
    std::cout<<"Ponizej lista transakcji z najmniejsza kwota na liscie"<<std::endl;

    for(int i = 0; i <list.size(); i++) {
        if(list[i].getAmount() == min) {
            std::cout<<i<<" | ";
            list[i].showTransaction();
            std::cout<<"\n"; 
        }
    }
}

void Transaction_list::MaxAmount() const {
    if(list.size() == 0) {
        std::cout<<"Lista jest pusta"<<std::endl;
        return;
    }
    double max = list[0].getAmount();
    for(int i = 0; i <list.size(); i++) {
        if(list[i].getAmount() > max) {
            max = list[i].getAmount();
        }
    }

    std::cout<<"Najwieksza transakcja byla wykonana na kwote: "<<max<<std::endl;
    std::cout<<"Ponizej lista transakcji z najwieksza kwota na liscie"<<std::endl;

    for(int i = 0; i <list.size(); i++) {
        if(list[i].getAmount() == max) {
            std::cout<<i<<" | ";
            list[i].showTransaction();
            std::cout<<"\n"; 
        }
    }
}