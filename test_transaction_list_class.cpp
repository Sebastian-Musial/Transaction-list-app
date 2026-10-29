#include <iostream>
#include "transaction_list_class.hpp"
#include "test_transaction_list_class.hpp"

void test_transaction_list() {
    Transaction_list test_list = {
        //T_name, T_amount, T_date, T_category
        {"Trx_1","100", "2026-10-27", "7T_category"}, //1
        {"Trx_2","100.00", "1999-10-27", "1T_category"}, //2
        {"Trx_3","100", "2100-10-27", ""}, //3
        {"Trx_4","100.00", "1800-10-27", ""}, //4
        {"Trx_5","2500", "3100-10-27", "1T_category"}, //5
        {"Trx_6","2500.00", "2026-10-27", "99T_category"}, //6
        {"Trx_7","250", "4200-10-27", ""}, //7
        {"Trx_8","250.00", "1200-10-27", ""}, //8
        {"Trx_9","1000", "2026-10-27", "22T_category"}, //9
        {"Trx_10","1000.00", "2026-10-27", "2T_category"} //10
    };
    Transaction_list easy_list = {
        {"Aggregations", "100", "2026-10-27", "Cat_1"},
        {"Aggregations", "25", "2026-10-27", "Cat_1"},
        {"Aggregations", "75", "2026-10-27", "Cat_2"},
        {"Aggregations", "125", "2026-10-27", "Cat_1"},
        {"Aggregations", "100", "2026-10-27", "Cat_2"},
        {"Aggregations", "200", "2026-10-27", "Cat_2"},
        {"Aggregations", "200", "2026-10-27", "Cat_3"}
    };
    Transaction_list empty_list;

    std::cout<<"TESTS START"<<std::endl;
    TEST_showAllTransaction(test_list);
    TEST_addTransaction(test_list);
    TEST_deleteTransaction(test_list);
    TEST_modifyTransaction(test_list);

    TEST_sortByDate(test_list, empty_list);
    TEST_sortByDateReverse(test_list, empty_list);
    TEST_sortByAmount(test_list, empty_list);
    TEST_sortByAmountReverse(test_list, empty_list);
    TEST_sortByCategory(test_list, empty_list);

    TEST_filterByDate(test_list);
    TEST_filterByCategory(test_list);

    TEST_aggregations(easy_list);
    std::cout<<"TESTS END"<<std::endl;
}

void TEST_showAllTransaction(Transaction_list &test_list) {
    std::cout<<"TEST - showAllTransaction()"<<std::endl;
    test_list.showAllTransaction();
    std::cout<<"TEST END- showAllTransaction()"<<std::endl;
}

void TEST_addTransaction(Transaction_list &test_list) {
    std::cout<<"TEST - addTransaction()"<<std::endl;
    std::cout<<"2 correct transaction and 3 wrong transaction"<<std::endl;
    test_list.addTransaction("ADD_1","123", "2026-12-27", "ADD_TEST");
    test_list.addTransaction("ADD_2",123.12, "2026-12-27", "");
    test_list.addTransaction("ADD_3","", "2026-12-27", "ADD_TEST");
    test_list.addTransaction("ADD_4","123", "", "ADD_TEST");
    test_list.addTransaction("","123.12", "2026-12-27", "");
    std::cout<<"After addTransaction all list: "<<std::endl;
    test_list.showAllTransaction();
    std::cout<<"TEST END- addTransaction()"<<std::endl;
}

void TEST_deleteTransaction(Transaction_list &test_list) {
    std::cout<<"TEST - deleteTransaction()"<<std::endl;
    std::cout<<"List before delete index 9 (corect index) an 20 (wrong index)"<<std::endl;
    test_list.showAllTransaction();
    test_list.deleteTransaction(9);
    // test_list.deleteTransaction(20);
    std::cout<<"List after deleted index 9 (corect index) an 20 (wrong index)"<<std::endl;
    test_list.showAllTransaction();
    std::cout<<"TEST END- deleteTransaction()"<<std::endl;
}

void TEST_modifyTransaction(Transaction_list &test_list) {
    std::cout<<"TEST - modifyTransaction()"<<std::endl;
    std::cout<<"List before modify index 0 (corect index) an 20 (wrong index)"<<std::endl;
    test_list.showAllTransaction();
    test_list.modifyTransacion(0, "MODIFY", 9999, "2026-10-30", "C_MODIFY");
    // test_list.modifyTransacion(20, "MODIFY", 9999, "2026-10-30", "C_MODIFY");
    std::cout<<"List after modify index 0 (corect index) an 20 (wrong index)"<<std::endl;
    test_list.showAllTransaction();
    std::cout<<"TEST END- modifyTransaction()"<<std::endl;
}

void TEST_sortByDate(Transaction_list &test_list, Transaction_list &empty_list) {
    std::cout<<"TEST - sortByDate()"<<std::endl;

    std::cout<<"Empty list before sort"<<std::endl;
    empty_list.showAllTransaction();
    std::cout<<"Empty sorted list"<<std::endl;
    empty_list.sortByDate();

    std::cout<<"List before sort"<<std::endl;
    test_list.showAllTransaction();
    std::cout<<"Sorted list"<<std::endl;
    test_list.sortByDate();

    std::cout<<"TEST END- sortByDate()"<<std::endl;
}

void TEST_sortByDateReverse(Transaction_list &test_list, Transaction_list &empty_list) {
    std::cout<<"TEST - sortByDateReverse()"<<std::endl;

    std::cout<<"Empty list before sort"<<std::endl;
    empty_list.showAllTransaction();
    std::cout<<"Empty sorted list"<<std::endl;
    empty_list.sortByDateReverse();

    std::cout<<"List before sort"<<std::endl;
    test_list.showAllTransaction();
    std::cout<<"Sorted list"<<std::endl;
    test_list.sortByDateReverse();

    std::cout<<"TEST END- sortByDateReverse()"<<std::endl;
}

void TEST_sortByAmount(Transaction_list &test_list, Transaction_list &empty_list) {
    std::cout<<"TEST - sortByAmount()"<<std::endl;

    std::cout<<"Empty list before sort"<<std::endl;
    empty_list.showAllTransaction();
    std::cout<<"Empty sorted list"<<std::endl;
    empty_list.sortByAmount();

    std::cout<<"List before sort"<<std::endl;
    test_list.showAllTransaction();
    std::cout<<"Sorted list"<<std::endl;
    test_list.sortByAmount();

    std::cout<<"TEST END- sortByAmount()"<<std::endl;
}

void TEST_sortByAmountReverse(Transaction_list &test_list, Transaction_list &empty_list) {
    std::cout<<"TEST - sortByAmountReverse()"<<std::endl;

    std::cout<<"Empty list before sort"<<std::endl;
    empty_list.showAllTransaction();
    std::cout<<"Empty sorted list"<<std::endl;
    empty_list.sortByAmountReverse();

    std::cout<<"List before sort"<<std::endl;
    test_list.showAllTransaction();
    std::cout<<"Sorted list"<<std::endl;
    test_list.sortByAmountReverse();

    std::cout<<"TEST END- sortByAmountReverse()"<<std::endl;    
}

void TEST_sortByCategory(Transaction_list &test_list, Transaction_list &empty_list) {
    std::cout<<"TEST - sortByCategory()"<<std::endl;

    std::cout<<"Empty list before sort"<<std::endl;
    empty_list.showAllTransaction();
    std::cout<<"Empty sorted list"<<std::endl;
    empty_list.sortByCategory();

    std::cout<<"List before sort"<<std::endl;
    test_list.showAllTransaction();
    std::cout<<"Sorted list"<<std::endl;
    test_list.sortByCategory();

    std::cout<<"TEST END- sortByCategory()"<<std::endl;  
}

void TEST_filterByDate(Transaction_list &test_list) {
    std::cout<<"TEST - filterByDate()"<<std::endl;
    std::cout<<"List before filter"<<std::endl;
    test_list.showAllTransaction();
    std::cout<<"List after filtered (2000-01-01 - 3001-01-01)"<<std::endl;
    test_list.filterByDate("2000-01-01", "3001-01-01");
    std::cout<<"TEST END- filterByDate()"<<std::endl;
}

void TEST_filterByCategory(Transaction_list &test_list) {
    std::cout<<"TEST - filterByCategory()"<<std::endl;
    std::cout<<"List before filter"<<std::endl;
    test_list.showAllTransaction();
    std::cout<<"List after filtered (1T_category)"<<std::endl;
    test_list.filterByCategory("1T_category");
    std::cout<<"TEST END- filterByDate()"<<std::endl;
}

void TEST_aggregations(Transaction_list &easy_list) {
    std::cout<<"TEST - aggregations()"<<std::endl;
    std::cout<<"List for tests"<<std::endl;
    easy_list.showAllTransaction();
    easy_list.sumOfAllTransactions();
    easy_list.sumOfAllTransactionsInOneCategory("Cat_1");
    easy_list.sumOfAllTransactionsInOneCategory("Cat_2");
    easy_list.sumOfAllTransactionsInOneCategory("Cat_3");
    easy_list.sumOfAllTransactionsInOneCategory("Cat_4");
    easy_list.sumOfAllTransactionsInCategories();
    easy_list.MinAmount();
    easy_list.MaxAmount();
    std::cout<<"TEST END- aggregations()"<<std::endl;
}