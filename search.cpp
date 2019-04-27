#include<iostream>
#include<cmath>
#include<string>
#include<ctime>
#include<fstream>

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
