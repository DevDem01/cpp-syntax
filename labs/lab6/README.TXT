CS 300 — Lab 6
File Access Control System

Files:
- Main.cpp
- User.h
- User.cpp
- RegularUser.h
- RegularUser.cpp
- AdminUser.h
- AdminUser.cpp

Compilation:
g++  Main.cpp User.cpp RegularUser.cpp AdminUser.cpp -o lab6.exe

Execution (Windows PowerShell):
.\lab6

This program demonstrates inheritance and runtime polymorphism using three classes: User, RegularUser, and AdminUser.

RegularUser supports security levels 1 and 2. AdminUser supports file reading, writing, and changing a RegularUser's security level.