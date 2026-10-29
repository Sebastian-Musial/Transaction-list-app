#pragma once

#include "transaction_list_class.hpp"

void test_transaction_list();

void TEST_showAllTransaction(Transaction_list &test_list);
void TEST_addTransaction(Transaction_list &test_list);
void TEST_deleteTransaction(Transaction_list &test_list);
void TEST_modifyTransaction(Transaction_list &test_list);

void TEST_sortByDate(Transaction_list &test_list, Transaction_list &empty_list);
void TEST_sortByDateReverse(Transaction_list &test_list, Transaction_list &empty_list);
void TEST_sortByAmount(Transaction_list &test_list, Transaction_list &empty_list);
void TEST_sortByAmountReverse(Transaction_list &test_list, Transaction_list &empty_list);
void TEST_sortByCategory(Transaction_list &test_list, Transaction_list &empty_list);

void TEST_filterByDate(Transaction_list &test_list);
void TEST_filterByCategory(Transaction_list &test_list);

void TEST_aggregations(Transaction_list &easy_list);