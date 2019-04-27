#include<iostream>
#include<cmath>
#include<string>
#include<ctime>
#include<fstream>
using namespace std;

struct information{
string name;
double cost;
double price;
string manufacturers_contact_info;
int amount;
double profit;
int expiration_day;
int expiration_month;
int expiration_year;
int nod;
bool availability_of_shop;
};

information commodity[1000];

time_t t = time(NULL);
tm* timePtr = localtime(&t);
int currentday=(timePtr->tm_mday);
int currentmonth=(timePtr->tm_mon)+1;
int currentyear=(timePtr->tm_year)+1900;

int number_of_commodity=0;
int amount_level;
int nod_alert;

void update_info(int);
int counting_days(int ,int ,int );
double totalprofits=0;
void alertforlevel(int );

void gettingdatas(){
    ifstream fin;
    fin.open("initial_list.txt");
    int i;
    int number;
    fin>>number;
    for(int i=0;i<number;i++){
        fin>>commodity[i].name>>commodity[i].cost>>commodity[i].price>>commodity[i].manufacturers_contact_info>>commodity[i].amount>>commodity[i].expiration_day>>commodity[i].expiration_month>>commodity[i].expiration_year;
        commodity[i].availability_of_shop=true;
        commodity[i].profit=0;
        commodity[i].nod=counting_days(commodity[i].expiration_day,commodity[i].expiration_month,commodity[i].expiration_year);
        //alertforlevel(i);
        i++;
    }  
    number_of_commodity +=number;  
    fin.close();
}
void printacommodity(int i){
    cout<<"name: "<<commodity[i].name<<" cost: "<<commodity[i].cost<<" price: "<<commodity[i].price<<" manufacturers_contact_info: ";
    cout<<commodity[i].manufacturers_contact_info<<" amount: "<<commodity[i].amount<<" expiration date: "<<commodity[i].expiration_day;
    cout<<"/"<<commodity[i].expiration_month<<"/"<<commodity[i].expiration_year<<endl;
}

void search(){
    string n;
    double cp;
    int an;
    cout <<"Choose a filter by entering a number: " << "1. Name " << "2.cost "<<"3.price "<<"4.amount "<<"5.nod "<<"0.exit "<<endl;
    int number;
    cin>>number;
    
    while(number!=0){
        
    if ( number == 1){
        cout<<"please enter the name"<<endl;
        cin>>n;
        for (int i=0; i<n.length(); i++) {
            if ('A' <= n[i] && n[i] <= 'Z'){
                n[i] = n[i] - 'A' + 'a';}
            }
        int k=0;
        for(int j=0;j<number_of_commodity;j++){
            if(n==commodity[j].name){
                printacommodity(j);
                k = j;
                break;
            }
        }
        cout<<"Do you want to update any one of these information? \"Y/N\" \n";
        char ans;
        cin>>ans;
        if(ans=='Y'){
            update_info(k);
        }
    }
    if(number==2){
        cout<<"please enter a cost";
        cin>>cp;
        cout<<"Higher/lower than or equal to \"H/L/E\""<<endl;
        char hle;
        cin>>hle;
        if(hle=='H'){
            for(int i=0;i<number_of_commodity;i++){
                if(commodity[i].cost>cp){
                    cout<<commodity[i].name<<" "<<commodity[i].cost<<endl;
                }
            }
        }
        if(hle=='L'){
            for(int i=0;i<number_of_commodity;i++){
                if(commodity[i].cost<cp){
                    cout<<commodity[i].name<<" "<<commodity[i].cost<<endl;
                }
            }
        }
        if(hle=='E'){
            for(int i=0;i<number_of_commodity;i++){
                if(commodity[i].cost==cp){
                    cout<<commodity[i].name<<" "<<commodity[i].cost<<endl;
                }
            }
        }
    }
    if(number==3){
        cout<<"please enter a price";
        cin>>cp;
        cout<<"Higher/lower than or equal to \"H/L/E\""<<endl;
        char hle;
        cin>>hle;
        if(hle=='H'){
            for(int i=0;i<number_of_commodity;i++){
                if(commodity[i].price>cp){
                    cout<<commodity[i].name<<" "<<commodity[i].price<<endl;
                }
            }
        }
        if(hle=='L'){
            for(int i=0;i<number_of_commodity;i++){
                if(commodity[i].price<cp){
                    cout<<commodity[i].name<<" "<<commodity[i].price<<endl;
                }
            }
        }
        if(hle=='E'){
            for(int i=0;i<number_of_commodity;i++){
                if(commodity[i].price==cp){
                    cout<<commodity[i].name<<" "<<commodity[i].price<<endl;
                }
            }
        }
    }
    if(number==4){
        cout<<"please enter a amount";
        cin>>an;
        cout<<"Higher/lower than or equal to \"H/L/E\""<<endl;
        char hle;
        cin>>hle;
        if(hle=='H'){
            for(int i=0;i<number_of_commodity;i++){
                if(commodity[i].amount>an){
                    cout<<commodity[i].name<<" "<<commodity[i].amount<<endl;
                }
            }
        }
        if(hle=='L'){
            for(int i=0;i<number_of_commodity;i++){
                if(commodity[i].amount<an){
                    cout<<commodity[i].name<<" "<<commodity[i].amount<<endl;
                }
            }
        }
        if(hle=='E'){
            for(int i=0;i<number_of_commodity;i++){
                if(commodity[i].amount==an){
                    cout<<commodity[i].name<<" "<<commodity[i].amount<<endl;
                }
            }
        }
    }
    if(number==5){
        cout<<"please enter number of days left before expiration date";
        cin>>an;
        cout<<"Higher/lower than or equal to \"H/L/E\""<<endl;
        char hle;
        cin>>hle;
        if(hle=='H'){
            for(int i=0;i<number_of_commodity;i++){
                if(commodity[i].nod>an){
                    cout<<commodity[i].name<<" "<<commodity[i].nod<<endl;
                }
            }
        }
        if(hle=='L'){
            for(int i=0;i<number_of_commodity;i++){
                if(commodity[i].nod<an){
                    cout<<commodity[i].name<<" "<<commodity[i].nod<<endl;
                }
            }
        }
        if(hle=='E'){
            for(int i=0;i<number_of_commodity;i++){
                if(commodity[i].cost==an){
                    cout<<commodity[i].name<<" "<<commodity[i].nod<<endl;
                }
            }
        }
    }
    cout <<"Choose a filter by entering a number: " << "1. Name " << "2.cost "<<"3.price "<<"4.amount "<<"5.nod "<<"0.exit "<<endl;
    cin>>number;
    }
    cout<<"returning back to the main menu right now\n";
}



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
    


void update_amount(int i){                //recording sales and counting profit
    int amounttobededucted;
    string commodity_name;
    cout<<"please input \"done 0\" if you finish updating "<<"\n"<<"input in this format: (name) (amount to be deducted)\n";
    cin>>commodity_name>>amounttobededucted; 
    while(amounttobededucted!=0){
        for(int i=0;i<number_of_commodity;i++){
            if (commodity[i].name==commodity_name){
                cout<<"Amount of "<<commodity_name<<" has been changed from "<<commodity[i].amount<<" to ";   //don't endl for this cout
                commodity[i].amount-=amounttobededucted;
                cout<<commodity[i].amount<<endl;
                if(commodity[i].amount<=0){
                    deletecommodity(i);
                }
                break;
            }
        }
        commodity[i].profit+=(commodity[i].price-commodity[i].cost)*amounttobededucted;
        cout<<"please input \"done 0\" if you finish updating "<<endl;
        cin>>commodity_name>>amounttobededucted; 
    }
    cout<<"returning back to the main menu right now\n";
}



void update_info(int i){                //changing information
    cout<<"Updating : \n"<<"1.cost\n2.price\n3.manufacturer_contact_info\n4.amount\n0.exit"<<endl;
    int number;
    cin>>number;
    double c_or_p;
    int a;
    string m;
    while(number!=0){
        if(number==1){
            cout<<"please enter the new cost for each:\n";
            cin>>c_or_p;
            commodity[i].cost=c_or_p;
        }
        if(number==2){
            cout<<"please enter the new price for each:\n";
            cin>>c_or_p;
            commodity[i].price=c_or_p;
        }
        if(number==3){
            cout<<"please enter the new manufacturer_contact_info:\n";
            cin>>m;
            commodity[i].manufacturers_contact_info=m;
        }
        if(number==4){
            cout<<"please enter the new amount:\n";
            cin>>a;
            commodity[i].amount=a;
            if(commodity[i].amount==0){
                deletecommodity(i);
            }
            if(commodity[i].amount<amount_level){
                alertforlevel(i);
            }
            
        }
        cout<<"Updating : \n"<<"1.cost\n2.price\n3.manufacturer_contact_info\n4.amount\n0.exit"<<endl;
        cin>>number;
    }
}


void alertforlevel(int i){

    if(commodity[i].nod<=nod_alert){
        cout<<"it’s "<<commodity[i].nod<<" days left"<<endl;
    } 
    
    
    if (commodity[i].amount<=amount_level){
        cout<<"There are only "<<commodity[i].amount<<" of "<<commodity[i].name<<" left, please contact "<<commodity[i].manufacturers_contact_info<<endl;
    }

    cout<<"returning back to the main menu right now\n";

}

void show(){
    cout<<"Showing whole list of commodity in orders of: \n"<<"1.no orders \n2.cost\n3.price\n4.amount\n5.expiration date\n0.exit"<<endl;
    int input; 
    cin>>input;
    int numbers[number_of_commodity];
    int idx[number_of_commodity];
    cout<<"number_of_commodity= "<<number_of_commodity<<endl;
    while(input!=0) {
        if(input==1){
            for(int i=0;i<number_of_commodity;i++){
                printacommodity(i);
            }
        }
        if(input==2){                                //show commoditys sorted by cost 
            for(int i=0;i<number_of_commodity;i++){
                numbers[i]=commodity[i].cost;
                idx[i]=i;
            }
            int tempnumbers,tempidx;
            for(int i=0;i<number_of_commodity;i++){
                for(int j=i+1;j<number_of_commodity;j++){
                    if(numbers[j]<numbers[i]){
                        tempnumbers=numbers[i];            //swaping
                        tempidx=idx[i];
                        numbers[i]=numbers[j];
                        idx[i]=idx[j];
                        numbers[j]=tempnumbers;
                        idx[j]=tempidx;
                    }
                }
            }
            for(int i=0;i<number_of_commodity;i++){
                printacommodity(idx[i]);
            }
        }
        if(input==3){             //show commoditys sorted by price
            for(int i=0;i<number_of_commodity;i++){
                numbers[i]=commodity[i].price;
                idx[i]=i;
            }
            int tempnumbers,tempidx;
            for(int i=0;i<number_of_commodity;i++){
                for(int j=i+1;j<number_of_commodity;j++){
                    if(numbers[j]<numbers[i]){
                        tempnumbers=numbers[i];            //swaping
                        tempidx=idx[i];
                        numbers[i]=numbers[j];
                        idx[i]=idx[j];
                        numbers[j]=tempnumbers;
                        idx[j]=tempidx;
                    }
                }
            }
            for(int i=0;i<number_of_commodity;i++){
                printacommodity(idx[i]);
            }
        }                     
        if(input==4){             //show commoditys sorted by amount
            for(int i=0;i<number_of_commodity;i++){
                numbers[i]=commodity[i].amount;
                idx[i]=i;
            }
            int tempnumbers,tempidx;
            for(int i=0;i<number_of_commodity;i++){
                for(int j=i+1;j<number_of_commodity;j++){
                    if(numbers[j]<numbers[i]){
                        tempnumbers=numbers[i];            //swaping
                        tempidx=idx[i];
                        numbers[i]=numbers[j];
                        idx[i]=idx[j];
                        numbers[j]=tempnumbers;
                        idx[j]=tempidx;
                    }
                }
            }
            for(int i=0;i<number_of_commodity;i++){
                printacommodity(idx[i]);
            }
        }
        if(input==5){                 //show commoditys sorted by nod(how many days before expiration date)
            for(int i=0;i<number_of_commodity;i++){
                numbers[i]=commodity[i].nod;
                idx[i]=i;
            }
            int tempnumbers,tempidx;
            for(int i=0;i<number_of_commodity;i++){
                for(int j=i+1;j<number_of_commodity;j++){
                    if(numbers[j]<numbers[i]){
                        tempnumbers=numbers[i];            //swaping
                        tempidx=idx[i];
                        numbers[i]=numbers[j];
                        idx[i]=idx[j];
                        numbers[j]=tempnumbers;
                        idx[j]=tempidx;
                    }
                }
            }
            for(int i=0;i<number_of_commodity;i++){
                printacommodity(idx[i]);
            }
        }
        cout << "Showing whole list of commodity in orders of: \n"<<"1.no orders \n2.cost\n3.price\n4.amount\n5.expiration date\n0.exit"<<endl;
        cin>>input;
        }
        cout<<"returning back to the main menu right now"<<endl;
        return; 
    }





int counting_days(int eday,int emonth,int eyear){
    int nod=0;
    bool febis29=false;
    int days_in_month[13]={29,31,28,31,30,31,30,31,31,30,31,30,31};
    int cday=currentday,cmonth=currentmonth,cyear=currentyear;
    if(cyear%4==0){
        febis29=true;
        days_in_month[2]=29;
    }
    while(cday!=eday||cmonth!=emonth||cyear!=eyear){
        

    if(cyear==eyear){
        if(emonth>cmonth){
            while(emonth!=cmonth){
                if(cmonth==2&&febis29==true){
                    days_in_month[3]=29;
                }
                while(cday<=days_in_month[cmonth]){
                    cday++;
                    nod++;
                }
                cmonth++;
                cday=1;
            }
        }
        if(emonth==cmonth){
            nod+=eday-cday;
            cday=eday;
        }
    }
    else if(eyear>cyear){
        while(eyear!=cyear){
               while(cmonth<=12){
                  while(cday<=days_in_month[cmonth]){
                    cday++;
                    nod++;
                  }
                  cmonth++;
                  cday=1;
               }
               cmonth=1;
               cyear++;
               if(cyear%4==0){
                   febis29=true;
                   days_in_month[2]=29;
               }
               days_in_month[2]=28;
               febis29=false;
            }
    }
    }
    return nod;
}


int main(){
    //gettingdatas();
    ofstream fout;
    fout.open("profits.txt");
    if(fout.fail()){
        cout<<"fail"<<endl;
        exit(1);
    }
    fout<<"Total profits made: $"<<totalprofits<<endl;
    fout.close();
    cout<<"welcome to inventory system "<<endl;

    cout<<" what is the minimum amount of commodity that you wish to get alert?"<<endl;
    cin>>amount_level;

    cout<<" what is the minimum days before expiry date that you wish to get alert?"<<endl;
    cin>>nod_alert;
    
    cout<<"please enter a number to callout the functions below"<<endl;
    cout<<"1.show"<<"\n"<<"2.insert"<<"\n"<<"3.search"<<"\n"<<"4.delete"<<"\n"<<"5.recording sales"<<"\n"<<"6.updating information"<<"\n"<<"0.exit"<<endl;
    int function_number;
    cin>>function_number;
    string name;
    while(function_number!=0){
    if(function_number==1){
        show();
    }
    if(function_number==2){
        insert_new_commodity();
    }
    if(function_number==3){
        search();
    }
    if(function_number==4){
        cout<<"please enter the name of the commodity that you want to delete"<<endl;
        cin>>name;
        for(int i=0;i<number_of_commodity;i++){
            if(commodity[i].name==name){
                deletecommodity (i);
            }
        }
    }
    if(function_number==5){
        cout<<"please enter the name of the commodity that you want to record the sales"<<endl;
        cin>>name;
        for(int i=0;i<number_of_commodity;i++){
            if(commodity[i].name==name){
                update_amount(i);
            }
        }
    }
    if(function_number==6){
        cout<<"please enter the name of the commodity that you want to update it's information"<<endl;
        cin>>name;
        for(int i=0;i<number_of_commodity;i++){
            if(commodity[i].name==name){
                update_info(i);
            }
        }
        
    }
    for(int i=0;i<number_of_commodity;i++){
        alertforlevel(i);

    }
    cout<<"number_of_commodity= "<<number_of_commodity<<endl;
    cout<<"please enter a number to callout the functions below"<<endl;
    cout<<"1.show"<<"\n"<<"2.insert"<<"\n"<<"3.search"<<"\n"<<"4.delete"<<"\n"<<"5.recording sales"<<"\n"<<"6.updating information"<<"\n"<<"0.exit"<<endl;
    cin>>function_number;
    }
    cout<<"thanks for using the programme";
}
