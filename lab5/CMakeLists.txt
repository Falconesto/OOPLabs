cmake_minimum_required(VERSION 3.17)
project(lab5)

set(CMAKE_CXX_STANDARD 20)

add_executable(lab5 main.cpp Bank.cpp Bank.h User.cpp User.h Account.cpp Account.h Transaction.cpp Transaction.h CreditAccount.cpp CreditAccount.h DebitAccount.cpp DebitAccount.h DepositAccount.cpp DepositAccount.h Interactions.cpp Interactions.h Time.cpp Time.h)