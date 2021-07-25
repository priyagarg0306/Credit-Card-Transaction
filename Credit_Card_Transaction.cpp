#include<bits/stdc++.h>
#include<iostream>
#include<fstream>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<ctime>

using namespace std;

int main();
class customer
{
   string first_name, last_name, full_name, email_id, mob_no,account_no, card_no, user_id, pin, pin1;
    char ch, sex;
    int age;
    int dob;
    double balance;
    string isblocked;

    public:
    void customer_details()
        {
            cout<<"\t\t\t Welcome to Customer Registeration Portal\n\n";
            cout<<"\nEnter First Name: ";
            cin>>first_name;
            cout<<"\nEnter Last Name: ";
            cin>>last_name;
            full_name = first_name + " " + last_name;
            cout<<"\nEnter Gender (M/F/T): ";
            cin>>sex;
            cout<<"\nEnter DOB in (ddmmyyyy) format: ";
            cin>>dob;
            cout<<"\nEnter Age: ";
            cin>>age;
            cout<<"\nEnter Account No: ";
            cin>>account_no;
            cout<<"\nEnter Email-Id: ";
            cin>>email_id;
            cout<<"\nEnter Mobile No: (+91) ";
            cin>>mob_no;
            srand(time(0));
            for(int i =0; i<16; i++)
                {
                    card_no = card_no + to_string(rand()%10);
                }
            user_id = first_name + to_string(rand()%10000);

        }

    void register_customer(customer x)
        {
            if(x.age < 18)
                {
                    system("cls");
                    cout<<"\nSorry! you are not eligible for credit card..";
                    cout<<"\nYou didn't fulfill the age criteria!!";
                    cout<<"\n\nThank you!!";
                    return;
                }
            else
                {
                    cout<<"\nPress Enter to generate your PIN...";
                    getch();
                    x.generate_pin();
                    system("cls");

                    double bal = 0;
                    ofstream fout("registration_data.txt", ios::out|ios::app|ios::binary);
                    fout<< x.full_name<<" "<<x.email_id<<" "<<x.mob_no<<" "<<x.account_no<<" "<<x.card_no<<" "<<x.pin<<" "<<x.user_id <<" "<<x.sex<<" "<<x.age<<" "<<dob<<" "<<"False"<<" "<< bal <<endl;
                    cout<<"\nCustomer Registered Successfully and card is generated!!"<<endl;
                    show_details(x.user_id);
                    fout.close();
                    cout<<"\n\t\t\t Press enter to go back to menu...\n"<<endl;
                    getch();
                }
        }

    void generate_pin()
        {
            while(1)
                {
                    system("cls");

                    cout<<"\t\t\t\t\tWelcome to PIN Generation Portal\n\n";
                    cout<<"\nEnter your 4-digit PIN: ";

                    for(int i=0; i<4; i++)
                        {
                            ch = getch();
                            cout<<"* ";
                            pin = pin + ch;
                        }
                    cout<<"\nConfirm your 4-digit PIN: ";

                    for(int i=0; i<4; i++)
                        {
                            ch = getch();
                            cout<<"* ";
                            pin1 = pin1 + ch;
                        }
                    if(pin1 == pin)
                        break;
                    else
                        pin = "";
                        pin1 = "";
                        cout<<"\nInvalid! Try again...";
                    getch();
                }
            cout<<"\nPress Enter to save...";
            getch();
            cout<<"\nPIN Generated Successfully!!\n";
            getch();
        }

    void get_database()
        {
            customer x;
            cout<<"\n****************** DATABASE PORTAL ***************\n"<<endl;
            string loginid, pwd;
            cout << "Enter administrative login id:\n";
            cin >> loginid;
            cout << "Enter administrative password:\n";
            cin >> pwd;

            if(loginid == "admin" && pwd == "admin"){
                system("CLS");
                ifstream fin("registration_data.txt", ios::in|ios::binary);
                cout << "\n\n";
                cout<<"********************************************\n"<<endl;
                while(fin>>first_name>>last_name>>email_id>>mob_no>>account_no>>card_no>>pin>>user_id>>sex>>age>>dob>>isblocked>>balance){
                    int date = dob/1000000;
                    int month = dob/10000 - date*100;
                    int year = dob%10000;
                    cout <<"Customer Name: "<< first_name<<" "<<last_name<<endl<<"Email-id: "<<email_id<<" "<< endl<<"Mobile Number: "<<mob_no<<endl<<"Account number:"<<account_no<<endl<<"Card Number : "<<card_no<<endl<< "User Id: "<<user_id << endl<<"Sex: "<<sex<<endl<<"Age: "<<age<<endl<<"Date of Birth: "<<date<<"-"<<month<<"-"<<year<<endl;
                    cout<<"********************************************\n"<<endl;
                    }

                fin.close();
                cout << "\t\t\t Press any key to go back to the main menu...\n";
                getch();
                return;
            } else{
                system("CLS");
                cout << "\n\t\t\t Wrong credentials entered...\n";
                cout << "\t\t\t Press any key to go back to the main menu...\n";
                getch();
                return;
            }
        }

    void get_deldatabase()
        {
            customer x;
            cout<<"\n****************** PREVIOUS DATABASE PORTAL***************\n"<<endl;
            string loginid, pwd;
            cout << "Enter administrative login id:\n";
            cin >> loginid;
            cout << "Enter administrative password:\n";
            cin >> pwd;

            if(loginid == "admin" && pwd == "admin"){
                system("CLS");
                ifstream fin("deleted_accounts.txt", ios::in|ios::binary);
                cout << "\n\n";
                cout<<"********************************************\n"<<endl;
                while(fin>>first_name>>last_name>>email_id>>mob_no>>account_no>>card_no>>pin>>user_id>>sex>>age>>dob>>isblocked>>balance){
                    int date = dob/1000000;
                    int month = dob/10000 - date*100;
                    int year = dob%10000;
                    cout <<"Customer Name: "<< first_name<<" "<<last_name<<endl<<"Email-id: "<<email_id<<" "<< endl<<"Mobile Number: "<<mob_no<<endl<<"Account number:"<<account_no<<endl<<"Card Number : "<<card_no<<endl<< "User Id: "<<user_id << endl<<"Sex: "<<sex<<endl<<"Age: "<<age<<endl<<"Date of Birth: "<<date<<"-"<<month<<"-"<<year<<endl;
                    cout<<"********************************************\n"<<endl;
                    }

                fin.close();
                cout << "\t\t\t Press any key to go back to the main menu...\n";
                getch();
                return;
            } else{
                system("CLS");
                cout << "\n\t\t\t Wrong credentials entered...\n";
                cout << "\t\t\t Press any key to go back to the main menu...\n";
                getch();
                return;
            }
        }

    void show_details(string iuserid)
    {
        ifstream datain("registration_data.txt");

        int counter=0;
        while (datain>>first_name>>last_name>>email_id>>mob_no>>account_no>>card_no>>pin>>user_id>>sex>>age>>dob>>isblocked>>balance)
        {
            if(user_id == iuserid){
                counter++;
                int date = dob/1000000;
                int month = dob/10000 - date*100;
                int year = dob%10000;
                cout <<"Customer Name: "<< first_name << " " << last_name <<endl<<"Email-id: "<<email_id<<" "<< endl<<"Mobile Number: "<<mob_no<<endl<<"Account number:"<<account_no<<endl<<"Card Number : "<<card_no<<endl<< "User Id: "<<user_id << endl<<"Sex: "<<sex<<endl<<"Age: "<<age<<endl<<"Date of Birth: "<<date<<"-"<<month<<"-"<<year<<endl;
                cout<<"********************************************\n"<<endl;
                getch();
                return;
            }
        }
        datain.close();
        if(counter==0)
        {
            cout << "\n\t\t\t No such user exists...\n";
            cout << "\n\t\t\t Press any key to go back to the main menu...\n";
            getch();
            return;
        }
    }

    void print_info(){
            string full_name = first_name + " " + last_name;
            cout<<"\n**************Customers's data**************\n"<<endl;
            cout <<"Customer Name: "<< full_name<<endl<<"Email-id: "<<email_id<<" "<< endl<<"Mobile Number: "<<mob_no<<endl<<"Account Number:"<<account_no<<endl<<"Card Number : "<<card_no<<endl<< "User Id: "<<user_id << endl<<"Sex: "<<sex<<endl<<"Age: "<<age<<endl;
            cout<<"********************************************\n"<<endl;
    }
// Update Function
    void update_account(string t)
    {
        system("CLS");
        cout<<"***********Account Updation Portal********\n\n\n";
        char c,newsex;
        int a,newage;
        long long int a_n;
        string f_n,l_n;
        int dobx,newdobx;
        string found="no";

        int counter=0;
        ifstream fin("registration_data.txt",ios::in);
        ofstream fout("temp.txt");

        while (fin>>first_name>>last_name>>email_id>>mob_no>>account_no>>card_no>>pin>>user_id>>sex>>age>>dobx>>isblocked>>balance){
            if(account_no == t){

                   cout<<"\n\n\t\t\tDetails of the Account before Updation\n\n";
                   print_info();  // Calling function to print info

                    cout<<"\n\n";
                    do{
                        cout<<"\n\nWhich Detail you want to update :-\n";
                        cout<<"1. Full Name\n";
                        cout<<"2. Gender\n";
                        cout<<"3. Age and Date of Birth\n";
                        cin>>a;
                        switch(a)
                        {
                            case 1: {
                                    string full_name = first_name + " " +last_name;
                                    cout<<"\n\nYour old Full Name :"<<full_name;
                                    cout<<"\n\nEnter your New First Name :";
                                    cin>>f_n;
                                    cout<<"\nEnter your New Last Name :";
                                    cin>>l_n;
                                    first_name = f_n;
                                    last_name  = l_n;
                                    cout<<"\nName of the Accountee of this account has been Updated Successfully!!!!!\n\n";
                                    }
                                    break;
                            case 2: cout<<"\n\nYour old Gender Detail :"<<sex;
                                    cout<<"\nEnter your new Gender Details :";
                                    cin>>newsex;
                                    sex = newsex;
                                    cout<<"\nGender of this account has been Updated Successfully!!!!!\n\n";
                                    break;
                            case 3:
                                {
                                    cout<<"\n\nYour old Age:"<<age;
                                    int date = dobx/1000000;
                                    int month = dobx/10000 - date*100;
                                    int year = dobx%10000;
                                    cout<<"\nYour old Date of Birth:"<<date<<"-"<<month<<"-"<<year;
                                    cout<<"\n\nEnter your new Age:";
                                    cin>>newage;
                                    age = newage;
                                    cout<<"\nEnter your new Date of Birth in (ddmmyyyy) format:";
                                    cin>>newdobx;
                                    dobx = newdobx;
                                    cout<<"\nAge and Date of Birth of this account has been Updated Successfully!!!!!\n\n";
                                    break;
                                }

                            default: cout<<"\nEnter a Valid Choice!!!!!\n\n";
                                     break;
                        }

                        cout<<"\nDo you want to update any other detail of this accouunt (y/n): ";
                        cin>>c;
                    }while(c=='y'||c=='Y');
                    counter++;

                    fout<<first_name<<" "<<last_name<<" "<<email_id<<" "<<mob_no<<" "<<account_no<<" "<<card_no<<" "<<pin<<" "<<user_id <<" "<<sex<<" "<<age<<" "<<dobx<<" "<<isblocked<<" "<<balance<<endl;

                    cout<<"\n\n\t\t\tDetails of the Account After Updation\n\n";
                    print_info();
                    cout<<"\nPress Enter to return to Main Menu\n";
                    getch();
                }
            else{
                fout<<first_name<<" "<<last_name<<" "<<email_id<<" "<<mob_no<<" "<<account_no<<" "<<card_no<<" "<<pin<<" "<<user_id <<" "<<sex<<" "<<age<<" "<<dobx<<" "<<isblocked<<" "<<balance<<endl;
            }
        }
        if(counter==0)
            {
                cout<<"Record not found\n\n";
                cout<<"Press Enter to return to Main Menu\n";
                getch();
            }
        fin.close();
        fout.close();

        remove("registration_data.txt");
        rename("temp.txt","registration_data.txt");

    }

// Delete Function
    void delete_account(string t)
    {

        cout<<"******************************Account Deletion Portal*********************\n\n\n";
        char d;
        int counter=0;
        ifstream fin("registration_data.txt",ios::in);
        ofstream fout("temp.txt");
        ofstream deldata("deleted_accounts.txt");

        while (fin>>first_name>>last_name>>email_id>>mob_no>>account_no>>card_no>>pin>>user_id>>sex>>age>>dob>>isblocked>>balance){
            if(account_no == t){
                   counter++;
                   cout<<"\n\n\t\t\tDetails of the Account \n\n";
                   print_info();  // Calling function to print info
                  xx:
                    cout<<"\n\nAre you sure you wanna delete your account?(y/n) "; cin>>d;
                    if(d=='y'||d=='Y'){
                        deldata<<first_name<<" "<<last_name<<" "<<email_id<<" "<<mob_no<<" "<<account_no<<" "<<card_no<<" "<<pin<<" "<<user_id <<" "<<sex<<" "<<age<<" "<<dob<<" "<<isblocked<<" "<<balance<<endl;
                        cout<<"Your account has been deleted"<<endl;
                    }
                    else if(d=='n'||d=='N')
                    {
                        cout<<"Your account has not been deleted"<<endl;
                        fout<<first_name<<" "<<last_name<<" "<<email_id<<" "<<mob_no<<" "<<account_no<<" "<<card_no<<" "<<pin<<" "<<user_id <<" "<<sex<<" "<<age<<" "<<dob<<" "<<isblocked<<" "<<balance<<endl;
                    }
                    else
                    {
                        cout<<"Wrong choice try again"<<endl;
                        goto xx;
                    }
                }
            else{
                fout<<first_name<<" "<<last_name<<" "<<email_id<<" "<<mob_no<<" "<<account_no<<" "<<card_no<<" "<<pin<<" "<<user_id <<" "<<sex<<" "<<age<<" "<<dob<<" "<<isblocked<<" "<<balance<<endl;
            }
        }
        if(counter==0)
            {
                cout<<"Record not found";
            }
        fin.close();
        fout.close();
        deldata.close();

        remove("registration_data.txt");
        rename("temp.txt","registration_data.txt");

    }

// Transaction Function
    void add_trans(string iuserid, double amt, double balance)
    {
        ofstream transout("transaction_records.txt", ios::app);

        string transid;
        srand(time(0));
        transid = user_id + to_string(rand()%10000);
        transout << transid << " " << iuserid << " " << amt << " " << balance << " " << balance+amt << endl;

        transout.close();

    }
    vector<string> userexists(string iuserid)
    {
        ifstream datain("registration_data.txt");

        int counter=0;
        while (datain>>first_name>>last_name>>email_id>>mob_no>>account_no>>card_no>>pin>>user_id>>sex>>age>>dob>>isblocked>>balance)
        {
            if(user_id == iuserid){
                counter++;
                vector<string> opvec;
                opvec.push_back(to_string(dob));
                opvec.push_back(card_no);
                opvec.push_back(pin);
                opvec.push_back(isblocked);
                datain.close();
                return opvec;
            }
        }
        datain.close();
        if(counter==0)
        {
            cout << "\n\t\t\t No such user exists...\n";
            cout << "\n\t\t\t Press any key to go back to the main menu...\n";
            getch();
            main();
        }
    }
    void func_transaction(string iuserid, double amt)
    {
        ifstream fin("registration_data.txt",ios::in);
        ofstream fout("temp.txt");

        while (fin>>first_name>>last_name>>email_id>>mob_no>>account_no>>card_no>>pin>>user_id>>sex>>age>>dob>>isblocked>>balance){
            if(user_id == iuserid){

                    cout<<"\n\n";
                    add_trans(iuserid, amt, balance);
                    balance += amt;
                    if(balance > 500000){
                        isblocked.clear();
                        isblocked = "True";
                    }

                    fout<<first_name<<" "<<last_name<<" "<<email_id<<" "<<mob_no<<" "<<account_no<<" "<<card_no<<" "<<pin<<" "<<user_id <<" "<<sex<<" "<<age<<" "<<dob<<" "<<isblocked<<" "<<balance<<endl;
                }
            else{
                fout<<first_name<<" "<<last_name<<" "<<email_id<<" "<<mob_no<<" "<<account_no<<" "<<card_no<<" "<<pin<<" "<<user_id <<" "<<sex<<" "<<age<<" "<<dob<<" "<<isblocked<<" "<<balance<<endl;
            }
        }

        fin.close();
        fout.close();

        remove("registration_data.txt");
        rename("temp.txt","registration_data.txt");

        cout << "\n\t\t\t Transaction Successful.\n";
        cout << "\n\t\t\t Press any key to go to main menu...\n";
        getch();

    }

    void completetransaction(){
        system("CLS");
        cout << "\t\t\t Welcome to the Transaction portal\n";
        string iuserid, icredcardnum;
        string dob_input;
        string pin_input;
        double amt;

        cout << "Login to the portal using your User ID as the login ID:" << endl;
        cin >> iuserid;
        // check if User ID exists in our database or not
        vector<string> checkvec = userexists(iuserid);


        int corr=0, counn=0;
        while(corr != 1 || counn <4){
            if(counn == 3){
                cout << "\nWrong password entered 3 times, try again after 24 hours...\n";
                cout << "\nPress any key to return back to menu.\n";
                getch();
                return;
            }
            else {
                cout << "Enter DOB (DDMMYYYY) as your password:" << endl;
                cin >> dob_input;

                // If DOB matches the one in our database, grant access, otherwise deny access. If 3 wrong inputs, deny access for 24 hours
                if(checkvec[0] == dob_input){
                    corr = 1;
                    system("CLS");
                    cout << "\n\t\t\tLogin credentials matched, you can proceed with the transaction.\n";

                    cout << "\nEnter your Credit Card Number:\n";
                    cin >> icredcardnum;
                    cout << "\nEnter the amount of money you want to transfer:\n";
                    cin >> amt;

                    if(icredcardnum == checkvec[1]){
                        int cor=0, pincount=0;
                        while(cor !=0 || pincount<4){
                            if(pincount == 3){
                                cout << "\n\t\t\t Wrong pin entered 3 times, try again after 24 hours...\n";
                                cout << "\n\t\t\t Press any key to return back to menu.\n";
                                getch();
                                return;
                            }
                            else{
                                cout << "\nEnter the pin to ensure that you are willingly making a transaction of amount: " << amt << endl;
                                cin >> pin_input;

                                if(pin_input == checkvec[2]){
                                    cor = 1;
                                    if(checkvec[3] == "False"){
                                        func_transaction(iuserid, amt);
                                        return;
                                    } else {
                                        cout << "\n\t\t This credit card has been blocked due to suspicious activities.\n";
                                        cout << "\n\t\t Press any key to return to main menu...\n";
                                        getch();
                                        return;
                                    }
                                } else{
                                    pincount++;
                                    cout << "\n\t\t\t Wrong pin entered, try again...\n";
                                }

                            }
                        }

                    } else {
                        cout << "\nThe credit card number is wrong, try again!\n";
                    }

                }
                else {
                    counn++;
                    cout << "\nIncorrect password, try again!\n";
                }
            }
        }
    }

    void show_transactions(string iuserid)
    {
        system("CLS");
        cout << "\t\t\t Transaction history of user: " << iuserid << endl << endl;
        ifstream transin("transaction_records.txt",ios::in);
        string transid;

        int opening_bal, trans_amt , closing_bal;
        int counter=0;
        cout<<"********************************************\n"<<endl;
        while (transin>>transid>>user_id>>trans_amt>>opening_bal>>closing_bal)
        {
            if(user_id == iuserid){
                counter++;
                cout <<"Transaction id: "<< transid << endl << "User-id: "<<user_id<<" "<< endl << "Transaction Amount: "<< trans_amt << endl << "Opening Balance: " << opening_bal << endl <<"Closing Balance: "<< closing_bal << endl;
                cout<<"********************************************\n"<<endl;
            }
        }
        transin.close();
        if(counter==0)
        {
            cout << "\n\t\t\t No transactions made...\n";
            cout << "\n\t\t\t Press any key to go back to the main menu...\n";
            getch();
            main();
        } else{
            getch();
        }
    }

// Credit Card
    public:
        void card_info(string card_number){
            system("cls");
                    ifstream fin("registration_data.txt");
                    string dobx;
                    string found="no";
                    cout<<"\n card information \n"<<endl;
                    while(fin>>first_name>>last_name>>email_id>>mob_no>>account_no>>card_no>>pin>>user_id>>sex>>age>>dobx>>isblocked>>balance){
                        if(card_number==card_no){
                        found="yes";
                        cout<<"\n*******************************************"<<endl;
                        cout<<"* Card holder-name :"<<first_name<<" "<<last_name<<endl;
                        cout<<"* Card number :  "<<card_no<<endl;
                        cout<<"* Card pin : "<<pin<<endl;
                        cout<<"* Balance : "<<balance<<endl;
                        if(isblocked=="True")
                            cout<<"* Status : "<<"Blocked"<<endl;
                        else
                            cout<<"* Status : "<<"Not blocked"<<endl;
                        cout<<"*******************************************\n"<<endl;
                        }
                    }
                    if(found=="no")std::cout << "Card number is invalid" << std::endl;
                    fin.close();
        }
    public:
        public:
        void  card_management(){
            string dobx;
            string agex;
            string found="no";
            char ans;
            string newdata;
            string card_number;
            string pinx;
            cout<<"Enter the card number\n";
            cin>>card_number;
            cout<<"Enter the pin\n";
            cin>>pinx;
            cout<<"To Unblock card  or  Block card, enter U or B, respectively..."<<endl;
            cin>>ans;

            ifstream recentfile("registration_data.txt",ios::in|ios::app);

            ofstream fout("temp.txt",ios::app);
            while(recentfile>>first_name>>last_name>>email_id>>mob_no>>account_no>>card_no>>pin>>user_id>>sex>>age>>dobx>>isblocked>>balance){
                agex=to_string(age);
                if(card_number==card_no && pin==pinx){
                     found="yes";
                    if(ans=='B'){
                        newdata=first_name + " " + last_name + " " + email_id + " " + mob_no +" " + account_no + " " +card_no + " "+pin+ " " + user_id + " " + sex + " " + agex + " " + dobx + " " + "True"+" ";
                        cout << "\n   Card blocked successfully" <<endl;
                        getch();
                    }
                    else if(ans=='U'){
                        newdata=first_name+" "+last_name+" "+email_id+" "+mob_no+" "+account_no+" "+card_no+ " "+ pin +" "+user_id+" "+sex+" "+ agex +" "+dobx+" "+"False"+" ";
                        cout << "\n   Card unblocked successfully" <<endl;
                        getch();
                    }

                }
                else
                {
                fout<<first_name<<" "<<last_name<<" "<<email_id<<" "<<mob_no<<" "<<account_no<<" "<<card_no<<" "<<pin<<" "<<user_id <<" "<<sex<<" "<<agex<<" "<<dobx<<" "<<isblocked<<" "<<balance<<endl;
                }
            }
            if(found!="yes")
            {
                cout << " \n\n\t\t\t Card number is incorrect or pin is wrong \n\n"<<endl;
                getch();
            }

            fout.close();
            recentfile.close();
            remove("registration_data.txt");
            rename("temp.txt","registration_data.txt" );
            ofstream newdt("registration_data.txt",ios::app);
            if((ans=='U'||ans=='u')&& found=="yes")
                newdt<<newdata<<0<<endl;
            else if((ans='B'||ans=='b')&& found=="yes")
                newdt<<newdata<<balance<<endl;
            newdt.close();

        }

};


int main()
{
    int op;
    do
    {
        system("CLS");
        cout << "\t\t\t Welcome to the portal\n";
        cout << "What do you want to do?\n";
        cout << "1. Register as a customer.\n";
        cout << "2. View account details.\n";
        cout << "3. Updating account details.\n";
        cout << "4. Deleting an existing account.\n";
        cout << "5. Make a transaction.\n";
        cout << "6. View transaction history.\n";
        cout << "7. View your Credit Card information.\n";
        cout << "8. Block/Unblock Card.\n";
        cout << "9. Show Database.\n";
        cout << "10. Show deleted user's information.\n";
        cout << "0. Exit.\n";
        cin >> op;

        switch(op)
        {
            case 0:
                break;

            case 1:
                {
                    system("CLS");
                    customer c1;
                    c1.customer_details();
                    c1.register_customer(c1);
                }
                break;

            case 2:
                {
                    system("CLS");
                    customer c2;
                    string p;
                    cout<<"Enter the User ID linked to the account whose details you want to view:\n";
                    cin>>p;
                    c2.show_details(p);
                }
                break;

            case 3:
                {
                    system("CLS");
                    customer c3;
                    string p;
                    cout<<"Enter the account number whose information you want to update:\n";
                    cin>>p;
                    c3.update_account(p);
                }
                break;

            case 4:
                {
                    system("CLS");
                    customer c4;
                    string p;
                    cout<<"Enter the account number whose information you want to delete:\n";
                    cin>>p;
                    c4.delete_account(p);
                }
                break;

            case 5:
                {
                    customer c5;
                    c5.completetransaction();
                }
                break;

            case 6:
                {
                    system("CLS");
                    customer c6;
                    string iuserid;
                    cout<<"Enter the User ID linked to the account whose transaction history you want to view:\n";
                    cin>>iuserid;
                    c6.show_transactions(iuserid);
                }
                break;


            case 7:
                {
                    system("CLS");
                    customer c7;
                    string card_no;
                    cout<<"Enter the Card number\n";
                    cin>>card_no;

                    c7.card_info(card_no);
                    cout<<"\nPress enter to continue..\n";
                    getch();
                }
                break;

            case 8:
                {
                    system("CLS");
                    customer c8;
                    c8.card_management();
                }
                break;

            case 9:
                {
                    system("CLS");
                    customer c9;
                    c9.get_database();
                }
                break;

            case 10:
                {
                    system("CLS");
                    customer c10;
                    c10.get_deldatabase();
                }

            default:
                cout<<"\nEnter a Valid Choice!\n\n";
                break;
        }
    }while(op != 0);

    return 0;
}
