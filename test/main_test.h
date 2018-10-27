#ifndef MAIN_TEST_H
#define MAIN_TEST_H

#include <iostream>
#include <string>

// Controller include
#include "controller.h"

// Dealer includes
#include "shamir_dealer.h"

// File includes
#include "readable_file.h"
#include "writable_file.h"

// List include
#include "list.h"

/* controller tests */
void test_controller();

/* list tests */
void test_list();

/* file tests */
void test_file();

/* shamir_dealer tests */
void test_shamir_dealer();

#endif
