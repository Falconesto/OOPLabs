cmake_minimum_required(VERSION 3.17)
project(lab4)

set(CMAKE_CXX_STANDARD 20)

add_executable(lab4 main.cpp File.cpp File.h Backup.cpp Backup.h BackUpPoint.cpp BackUpPoint.h Time.cpp Time.h Expired.cpp Expired.h ExpiredByDate.cpp ExpiredByDate.h ExpiredBySize.cpp ExpiredBySize.h ExpiredByNumber.cpp ExpiredByNumber.h ExpiredByMixed.cpp ExpiredByMixed.h)