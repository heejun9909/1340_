#include<iostream>
#include<cmath>
#include<string>
#include<ctime>
#include<fstream>

void insert_new_commodity (){
    int number;
    cout<<" How many commodity you wish to insert this time?"<<endl;
    cin>>number;
    for(int i=number_of_commodity; i<number_of_commodity+number;i++){
        cout<<"name: ";
        cin>>commodity[i].name;
        for (int j=0; j<commodity[i].name.length(); j++) {               
            if ('A' <= commodity[i].name[j] && commodity[i].name[j] <= 'Z'){
                commodity[i].name[j] = commodity[i].name[j] - 'A' + 'a';
            }
        }
        cout<<"cost for each: ";
        cin>>commodity[i].cost;
        cout<<"price for each: ";
        cin>>commodity[i].price;
        cout<<"manufacturers_contact_info: ";
        cin>>commodity[i].manufacturers_contact_info;
        cout<<"amount: ";
        cin>>commodity[i].amount;
        cout<<"please enter the expiration date in this format \"dd mm yyyy\"";
        cin>>commodity[i].expiration_day>>commodity[i].expiration_month>>commodity[i].expiration_year;
        commodity[i].availability_of_shop=true;
        commodity[i].profit=0;
        commodity[i].nod=counting_days(commodity[i].expiration_day,commodity[i].expiration_month,commodity[i].expiration_year);
    }
    number_of_commodity += number;
    cout<<"returning back to the main menu right now"<<endl;
    return;
}
