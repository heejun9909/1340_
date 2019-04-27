

Terminal:
g++ -c main.cpp
g++ -c update_info.cpp
g++ -c counting_days.cpp;
g++ -c alertforlevel.cpp;
g++ -c printacommodity.cpp;
g++ -c search.cpp;
g++ -c insert_new_commodity.cpp;
g++ -c deletecommodity.cpp;
g++ -c update_amount.cpp;
g++ -c show.cpp;
g++ -o main main.o update_info.o counting_days.o alertforlevel.o printacommodity.o search.o insert_new_commodity.o deletecommodity.o update_amount.o show.o ./main

INSIDE functions.h:


#ifndef FUNCTIONS_H
#define FUNCTIONS_H
void update_info(int);
int counting_days(int ,int ,int );
void alertforlevel(int );
void printacommodity(int);
void search();
void insert_new_commodity();
void deletecommodity(int);
void update_amount(int);
void show();

#endif
