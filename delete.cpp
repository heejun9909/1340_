#include<iostream>
#include<cmath>
#include<string>
#include<ctime>
#include<fstream>

void deletecommodity (int i){ //delete a commodity when it's out-of-stock or all become expired
    if(commodity[i].amount<=0){
        cout<<commodity[i].name<<" is out-of-stock!!"<<endl;
    }
    if(commodity[i].nod<=0){
        cout<<commodity[i].name<<" is expired!!"<<endl;
    }
    ofstream fout;
    fout.open("profits.txt",ios::app);
    fout<<"profits made by selling "<<commodity[i].name<<" is "<<commodity[i].profit;
    fout.close();
    totalprofits+=commodity[i].profit;
    cout<<commodity[i].name<<" has been deleted"<<endl;
    commodity[i].name=commodity[number_of_commodity-1].name;
    commodity[i].cost=commodity[number_of_commodity-1].cost;
    commodity[i].price=commodity[number_of_commodity-1].price;
    commodity[i].manufacturers_contact_info=commodity[number_of_commodity-1].manufacturers_contact_info;
    commodity[i].expiration_day=commodity[number_of_commodity-1].expiration_day;
    commodity[i].expiration_month=commodity[number_of_commodity-1].expiration_month;
    commodity[i].expiration_year=commodity[number_of_commodity-1].expiration_year;
    commodity[i].nod=commodity[number_of_commodity-1].nod;
    commodity[i].profit=commodity[number_of_commodity-1].profit;
    commodity[i].availability_of_shop=commodity[number_of_commodity-1].availability_of_shop;
    commodity[number_of_commodity-1].availability_of_shop=false;
    commodity[number_of_commodity-1].name="deleted item";
    commodity[number_of_commodity-1].amount=0;//when we insert a new commodity ,the old one would be replaced
    commodity[number_of_commodity-1].profit=0;
    number_of_commodity--;
    return;
}
