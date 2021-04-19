#include<iostream>
#include<string.h>
#include<cmath>
#include<fstream>
#include<stdlib.h>
#include<stdio.h>
#include<windows.h>
using namespace std;
void deletion(char* filename)
{
    int value;
    value=remove(filename);
    if(value==0)
    {
        cout<<"\nFile deleted successfully";
    }
    else
    cout<<"\nNo such file exists\n";

}
class ship
{
    protected:
    char color[15],mftdOrigin[50],owner[50],homePort[100],builder[50];
    int numPassengers,yearBuilt,load;
    double len,bre,weight,speed;
    char pro[50],name[50];
 
};

///////////////////PASSENGER SHIP////////////////////////////////
class Pship:virtual public ship
{
    int i;
    public:
    void see_p(void);
    void add_p(void);
    void search_p(void);
    void inputInfo_p(char *);
    void displayInfo_p(char *);
};
//------------------SEEING LIST OF PASSENGER SHIPS------------------------
void Pship::see_p()
{
    system("cls");
    ifstream in;
    in.open("Pship.txt",ios::app);
    cout<<"LIST OF PASSENGER SHIPS\n";
    i=0;
    while(in)
    {
        i++;
        in.getline(name,50);
        if(strlen(name)>1)
        cout<<i<<"."<<name<<endl;
    }
    in.close();
}
//------------------ADDING IN PASSENGER SHIP------------------------
void Pship::add_p()
{
    system("cls");
    char name[50],details[1000];
    ofstream o;
    fflush(stdin);
    o.open("Pship.txt",ios::app);
    cout<<"Enter the Ship Name: ";
    fflush(stdin);
    gets(name);
    o<<name<<endl; //writing in the file
    o.close();
    strcat(name,".txt");
    inputInfo_p(name);
    cout<<"\nYour data is recorded";

}
void Pship::displayInfo_p(char* name)
{
    ifstream of;
    of.open(name,ios::in);
    of>>color;
    cout<<"\nThe color is: "<<color<<endl;
    of>>mftdOrigin;  //Reading from the file
    cout<<"The Manufactured origin is: "<<mftdOrigin<<endl;
    of>>speed;
    cout<<"The speed in KM/HR is: "<<speed<<endl;
    of>>len;
    cout<<"The length  of ship is: "<<len<<endl;
    of>>bre;
    cout<<"The breadth of ship is: "<<bre<<endl;
    of>>weight;
    cout<<"The weight of the ship is: "<<weight<<endl;
    of>>owner;
    cout<<"The name of the owner of the ship:"<<owner<<endl;
    of>>builder;
    cout<<"The name of the builder of the ship:"<<builder<<endl;
    of>>homePort;
    cout<<"The name of the homeport is: "<<homePort<<endl;
    of>>numPassengers;
    cout<<"The maximum number of passengers it can carry are: "<<numPassengers<<endl;
    of>>yearBuilt;
    cout<<"The manufacturng year is: "<<yearBuilt<<endl;
    of.close();
}

void Pship::inputInfo_p(char* name)
{
    ofstream of;
    of.open(name,ios::app);
    cout<<"Enter the color:";
    fflush(stdin);
    gets(color);
    of<<color<<"\n";
    cout<<"Enter the Manufactured origin:";
    fflush(stdin);
    gets(mftdOrigin);
    of<<mftdOrigin<<"\n";
    cout<<"Enter the speed in KM/HR:";
    fflush(stdin);
    cin>>speed;
    of<<speed<<"\n";
    cout<<"Enter the length  of ship in KM:";
    fflush(stdin);
    cin>>len;
    of<<len<<"\n";
    cout<<"Enter the breadth of ship in KM:";
    fflush(stdin);
    cin>>bre;
    of<<bre<<"\n";
    cout<<"Enter the weight of the ship in KG:";
    fflush(stdin);
    cin>>weight;
    of<<weight<<"\n";
    cout<<"Enter the name of the owner of the ship:";
    fflush(stdin);
    gets(owner);
    of<<owner<<"\n";
    cout<<"Enter the name of the builder of the ship:";
    fflush(stdin);
    gets(builder);
    of<<builder<<"\n";
    cout<<"Enter the name of the homeport:";
    fflush(stdin);
    gets(homePort);
    of<<homePort<<"\n";
    cout<<"Enter the maximum number of passengers it can carry:";
    fflush(stdin);
    cin>>numPassengers;
    of<<numPassengers<<"\n";
    cout<<"Enter the manufacturng year:";
    fflush(stdin);
    cin>>yearBuilt;
    of<<yearBuilt<<"\n";
    of.close();
}


//------------------SEARCHING PASSENGER SHIP------------------------
void Pship::search_p()
{
    char name[50],details;
    cout<<"Enter the ship name: ";
    fflush(stdin);
    gets(name);
    strcat(name,".txt");
    ifstream i;
    i.open(name,ios::in);
    if(!i)
    {
        system("cls");
        cout<<"THIS SHIP ISN'T INCLUDED IN THE DIRECTORY\n";
        cout<<"KINDLY CHECK THE LIST AGAIN\n";
        cout<<"THANK YOU\n";
    }
    else 
    {
        system("cls");
        i.seekg(0);
        cout<<"THE DETAILS ARE:\n";
        cout<<"--------------------";
        displayInfo_p(name);
    }
}

///////////////////CARGO SHIP////////////////////////////////
class Cship:virtual public ship
{
    int j;
    public:
    void see_c(void);
    void add_c(void);
    void search_c(void);
    void inputInfo_c(char *);
    void displayInfo_c(char *);
};
void Cship::displayInfo_c(char* name)
{
    ifstream of;
    of.open(name,ios::in);
    of>>color;
    cout<<"\nThe color is: "<<color<<endl;
    of>>mftdOrigin;
    cout<<"The Manufactured origin is: "<<mftdOrigin<<endl;
    of>>speed;
    cout<<"The speed in KM/HR is: "<<speed<<endl;
    of>>len;
    cout<<"The length  of ship is: "<<len<<endl;
    of>>bre;
    cout<<"The breadth of ship is: "<<bre<<endl;
    of>>weight;
    cout<<"The weight of the ship is: "<<weight<<endl;
    of>>owner;
    cout<<"The name of the owner of the ship:"<<owner<<endl;
    of>>builder;
    cout<<"The name of the builder of the ship:"<<builder<<endl;
    of>>homePort;
    cout<<"The name of the homeport is: "<<homePort<<endl;
    of>>load;
    cout<<"The maximum number of passengers it can carry are: "<<load<<endl;
    of>>yearBuilt;
    cout<<"The manufacturng year is: "<<yearBuilt<<endl;
    of.close();
}

void Cship::inputInfo_c(char* name)
{
    ofstream of;
    of.open(name,ios::app);
    cout<<"Enter the color:";
    fflush(stdin);
    gets(color);
    of<<color<<"\n";
    cout<<"Enter the Manufactured origin:";
    fflush(stdin);
    gets(mftdOrigin);
    of<<mftdOrigin<<"\n";
    cout<<"Enter the speed in KM/HR:";
    fflush(stdin);
    cin>>speed;
    of<<speed<<"\n";
    cout<<"Enter the length  of ship:";
    fflush(stdin);
    cin>>len;
    of<<len<<"\n";
    cout<<"Enter the breadth of ship :";
    fflush(stdin);
    cin>>bre;
    of<<bre<<"\n";
    cout<<"Enter the weight of the ship :";
    fflush(stdin);
    cin>>weight;
    of<<weight<<"\n";
    cout<<"Enter the name of the owner of the ship:";
    fflush(stdin);
    gets(owner);
    of<<owner<<"\n";
    cout<<"Enter the name of the builder of the ship:";
    fflush(stdin);
    gets(builder);
    of<<builder<<"\n";
    cout<<"Enter the name of the homeport:";
    fflush(stdin);
    gets(homePort);
    of<<homePort<<"\n";
    cout<<"Enter the maximum load it can carry:";
    fflush(stdin);
    cin>>load;
    of<<load<<"\n";
    cout<<"Enter the manufacturng year:";
    fflush(stdin);
    cin>>yearBuilt;
    of<<yearBuilt<<"\n";
    of.close();
}

void Cship::see_c()
{
    system("cls");
    ifstream in;
    in.open("Cship.txt",ios::app);
    cout<<"LIST OF CARGO SHIPS\n";
    j=0;
    while(in)
    {
        j++;
        in.getline(name,50);
        if(strlen(name)>1)
        cout<<j<<"."<<name<<endl;
    }
    in.close();
}
//------------------ADDING IN CARGO SHIP------------------------
void Cship::add_c()
{
    system("cls");
    char name[50],details[1000];
    ofstream o;
    o.open("Cship.txt",ios::app);
    fflush(stdin);
    cout<<"Enter the Ship Name: ";
    fflush(stdin);
    gets(name);
    o<<name<<endl;
    o.close();
    strcat(name,".txt");
    inputInfo_c(name);
    cout<<"\nYour data is recorded";
}
//------------------SEARCHING IN CARGO SHIP------------------------
void Cship::search_c()
{
    char name[50],details;
    cout<<"Enter the ship name: ";
    fflush(stdin);
    gets(name);
    fflush(stdin);
    strcat(name,".txt");
    ifstream i;
    i.open(name,ios::in);
    if(!i)
    {
        cout<<"THIS SHIP ISN'T INCLUDED IN THE DIRECTORY\n";
        cout<<"KINDLY CHECK THE LIST AGAIN\n";
        cout<<"THANK YOU\n";
    }
    else 
    {
        system("cls");
        i.seekg(0);
        cout<<"THE DETAILS ARE:\n";
        cout<<"--------------------";
        displayInfo_c(name);
    }
}
//------------------PROPERTIES------------------------
class Properties:virtual public ship
{
    int j,p;
    public:
    void see_pro(void);
    void add_pro(void);
    void add_pro_detail(void);
    void search_pro(void);
    void add_ship(void);
    void inputInfo_pro(char *);
    void displayInfo_pro(char *);
};
void Properties::displayInfo_pro(char* name)
{
    ifstream of;
    of.open(name,ios::in);
    of>>color;
    cout<<"\nThe color is: "<<color<<endl;
    of>>mftdOrigin;
    cout<<"The Manufactured origin is: "<<mftdOrigin<<endl;
    of>>speed;
    cout<<"The speed in KM/HR is: "<<speed<<endl;
    of>>len;
    cout<<"The length  of ship is: "<<len<<endl;
    of>>bre;
    cout<<"The breadth of ship is: "<<bre<<endl;
    of>>weight;
    cout<<"The weight of the ship is: "<<weight<<endl;
    of>>owner;
    cout<<"The name of the owner of the ship:"<<owner<<endl;
    of>>builder;
    cout<<"The name of the builder of the ship:"<<builder<<endl;
    of>>homePort;
    cout<<"The name of the homeport is: "<<homePort<<endl;
    of>>load;
    cout<<"The maximum load it can carry is: "<<load<<endl;
    of>>load;
    cout<<"The maximum number of passengers it can carry are: "<<numPassengers<<endl;
    of>>yearBuilt;
    cout<<"The manufacturng year is: "<<yearBuilt<<endl;
    of.close();
}

void Properties::inputInfo_pro(char* name)
{
    int ch;
    ofstream of;
    of.open(name,ios::app);
    cout<<"Enter the color:";
    fflush(stdin);
    gets(color);
    of<<color<<"\n";
    cout<<"Enter the Manufactured origin:";
    fflush(stdin);
    gets(mftdOrigin);
    of<<mftdOrigin<<"\n";
    cout<<"Enter the speed in KM/HR:";
    fflush(stdin);
    cin>>speed;
    of<<speed<<"\n";
    cout<<"Enter the length  of ship:";
    fflush(stdin);
    cin>>len;
    of<<len<<"\n";
    cout<<"Enter the breadth of ship :";
    fflush(stdin);
    cin>>bre;
    of<<bre<<"\n";
    cout<<"Enter the weight of the ship :";
    fflush(stdin);
    cin>>weight;
    of<<weight<<"\n";
    cout<<"Enter the name of the owner of the ship:";
    fflush(stdin);
    gets(owner);
    of<<owner<<"\n";
    cout<<"Enter the name of the builder of the ship:";
    fflush(stdin);
    gets(builder);
    of<<builder<<"\n";
    cout<<"Enter the name of the homeport:";
    fflush(stdin);
    gets(homePort);
    of<<homePort<<"\n";
    cout<<"Whether you want to enter the maximum load or maximum passengers it can carry?";
    cout<<"\nEnter 1 for load and 2 for passengers";
    cin>>ch;
    if(ch==1)
    {
        cout<<"Enter the maximum load it can carry:";
        fflush(stdin);
        cin>>load;
        of<<load<<"\n";        
    }
    else 
    {
        cout<<"Enter the maximum passengers it can carry:";
        fflush(stdin);
        cin>>numPassengers;
        of<<numPassengers<<"\n";  
    }
    cout<<"Enter the manufacturng year:";
    fflush(stdin);
    cin>>yearBuilt;
    of<<yearBuilt<<"\n";
    of.close();
}
///////////////////PROPERTIES////////////////////////////////
void Properties::see_pro()
{
    system("cls");
    ifstream in;
    in.open("Properties.txt");
    cout<<"LIST OF PROPERTIES\n";
    j=0;
    while(in)
    {
        j++;
        in.getline(pro,50);
        if(strlen(pro)>1)
        cout<<j<<"."<<pro<<endl;
    }
    in.close();
}
//------------------ADD PROPERTY WITH DETAILS------------------------
void Properties::add_pro_detail()
{
    char ch1;
    system("cls");
    char pro[50],ship[50],details[1000];
    ofstream o;
    fflush(stdin);
    o.open("Properties.txt",ios::app);
    cout<<"Enter the Property Name:";
    fflush(stdin);
    gets(pro);
    o<<pro<<endl;
    o.close();
        strcat(pro,".txt");
        ofstream of;
        of.open(pro,ios::app);
        cout<<"Enter the Ship Name: ";
        fflush(stdin);
        gets(ship);
        of<<ship<<"\n";
        of.close();
        strcat(ship,".txt");
        ofstream out;
        out.open(ship,ios::app);
        inputInfo_pro(ship);
        cout<<"\nYour data is recorded";

}
//------------------ADD PROPERTY------------------------
void Properties::add_pro()
{
    system("cls");
    char pro[50];
    ofstream o;
    fflush(stdin);
    o.open("Properties.txt",ios::app);
    cout<<"Enter the Property Name: ";
    fflush(stdin);
    gets(pro);
    o<<pro<<endl;
    o.close();
    cout<<"\nYour data is recorded";
}
//------------------ADD SHIP IN PROPERTY------------------------
void Properties::add_ship()
{
    system("cls");
    char pr[50],ship[50],temp[50];
    fflush(stdin);
    cout<<"Enter the Property Name: ";
    fflush(stdin);
    gets(pr);
    strcpy(temp,pr);
    strcat(temp,".txt");
    ofstream o;
    o.open(temp,ios::app);
    cout<<"Enter the ship name:";
    fflush(stdin);
    gets(ship);
    o<<ship<<endl;
    o.close();
    cout<<"\nYour data is recorded";
}
//------------------SEARCH PROPERTY------------------------
void Properties::search_pro()
{
    char pro[50],ship[50];
    cout<<"Enter the property name: ";
    fflush(stdin);
    gets(pro);
    strcat(pro,".txt");
    ifstream i;
    i.open(pro,ios::in);
    if(!i)
    {
        cout<<"THIS PROPERTY ISN'T INCLUDED IN THE DIRECTORY\n";
        cout<<"KINDLY CHECK THE LIST AGAIN\n";
        cout<<"THANK YOU\n";
    }
    else 
    {
        system("cls");
        cout<<"THE SHIPS WITH THIS PROPERTY ARE:\n";
        i.seekg(0);
        p=1;
        while(!i.eof())
        {
            i.getline(ship,50);
            if(strlen(ship)>1)
            cout<<p<<"."<<ship<<endl;
            p++;
        }
        
    }
}
class Routes
{
    char r[200],ship[50];
    int p;
    public:
    void add_r(void);  //Add a route
    void add_r_ship(void); //Add a route to a ship
    void add_ship_r(void);  //Add a ship in a route
    void search_r_ship(void);   //Find routes of a ship
    void search_ship_r(void);   //Find ships of a routes

};
void Routes::add_r()
{
    system("cls");
    ofstream o;
    fflush(stdin);
    o.open("Routes.txt",ios::app);
    cout<<"Enter the Route Name: ";
    fflush(stdin);
    gets(r);
    o<<r<<endl;
    o.close();
    cout<<"\nYour data is recorded";
}
void Routes::add_r_ship()  //Add a ship to a route
{
    system("cls");
    char temp[200];
    fflush(stdin);
    cout<<"Enter the Route Name: ";
    fflush(stdin);
    gets(r);
    strcpy(temp,r);
    strcat(temp,".txt");
    ofstream o;
    o.open(temp,ios::app);
    fflush(stdin);
    cout<<"Enter the Ship Name: ";
    fflush(stdin);
    gets(ship);
    o<<ship<<endl;
    o.close();
    ofstream out;
    strcat(ship,"_r.txt");
    out.open(ship,ios::app);
    out<<r<<endl;
    cout<<"\nYour data is recorded";
}
void Routes::add_ship_r()  //Add a route to a ship
{
    system("cls");
    char temp[50];
    fflush(stdin);
    cout<<"Enter the Ship Name: ";
    fflush(stdin);
    gets(ship);
    strcpy(temp,ship);
    strcat(temp,"_r.txt");
    ofstream o;
    o.open(temp,ios::app);
    fflush(stdin);
    cout<<"Enter the Route Name: ";
    fflush(stdin);
    gets(r);
    o<<r<<endl;
    o.close();
    ofstream out;
    strcat(r,".txt");
    out.open(r,ios::app);
    out<<ship<<endl;
    cout<<"\nYour data is recorded";
}
void Routes::search_r_ship()  //Find routes of a ship
{
    char r[200],ship[50];
    cout<<"Enter the ship name: ";
    fflush(stdin);
    gets(ship);
    strcat(ship,"_r.txt");
    ifstream i;
    i.open(ship,ios::in);
    if(!i)
    {
        cout<<"THIS SHIP ISN'T INCLUDED IN THE DIRECTORY\n";
        cout<<"KINDLY CHECK THE LIST AGAIN\n";
        cout<<"THANK YOU\n";
    }
    else 
    {
        system("cls");
        cout<<"THE ROUTES OF THIS SHIP ARE:\n";
        i.seekg(0);
        p=1;
        while(!i.eof())
        {
            i.getline(r,50);
            if(strlen(r)>1)
            cout<<p<<"."<<r<<endl;
            p++;
        }
        
    }
}
void Routes::search_ship_r()  //Find ships of a route
{
    char r[200],ship[50];
    cout<<"Enter the route name: ";
    fflush(stdin);
    gets(r);
    strcat(r,".txt");
    ifstream i;
    i.open(r,ios::in);
    if(!i)
    {
        cout<<"THIS ROUTE ISN'T INCLUDED IN THE DIRECTORY\n";
        cout<<"KINDLY CHECK THE LIST AGAIN\n";
        cout<<"THANK YOU\n";
    }
    else 
    {
        system("cls");
        cout<<"THE ROUTES OF THIS SHIP ARE:\n";
        i.seekg(0);
        p=1;
        while(!i.eof())
        {
            i.getline(ship,50);
            if(strlen(ship)>1)
            cout<<p<<"."<<ship<<endl;
            p++;
        }
        
    }
}
class System
{
    public:
    System()
    {
        char ch;
        cout<<"\t\t\t\t";
        for(int i=0;i<=24;i++)
        {
            cout<<"* ";
        }
        cout<<"\n\t\t\t\t*\t\tOVERFLOW PVT LTD\t\t*"<<endl;
        cout<<"\t\t\t\t*\t\t\t\t\t\t*";
        cout<<"\n\t\t\t\t*\tSHIPS   DIRECTORY   MANAGEMENT\t\t*"<<endl;
        cout<<"\t\t\t\t";
        for(int i=0;i<=24;i++)
        {
            cout<<"* ";
        }
        //system("Color 7C");
        cout<<endl;
        cout<<"\t\t\t\t";cout<<"	          __  ~ __ ~ __                 \n";
        cout<<"\t\t\t\t";cout<<"	         |==|  |==|  |==|                 \n";
        cout<<"\t\t\t\t";cout<<"	       __|__|__|__|__|__|_                \n";
        cout<<"\t\t\t\t";cout<<"	    __|___________________|___            \n";
        cout<<"\t\t\t\t";cout<<"     __|__[]__[]__[]__[]__[]__[]__|______         \n";
        cout<<"\t\t\t\t";cout<<"     \\................................./ \n";
        cout<<"\t\t\t\t";cout<<"      \\.............................../  \n";
        cout<<"\t\t\t\t";cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout<<"\t\t\t\t";cout<<" ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ \n";
        cout<<"\t\t\t\t";cout<<"  ~  ~  ~  ~  ~  ~  ~  ~  ~  ~  ~  ~  ~  ~  ~  ~\n";
        do
        {
        Menu:
        cout<<"\n\n1>> Ships Category\n2>> Properties of Ships\n3>> Routes\n4>> Delete records\n4>> Exit\n";
        int n;
        cout<<"\nEnter the choice  ";
        cin>>n;
        system("cls");
        if(n==1)  ///SHIPS CATEGORY
        {
            Ships :
            cout<<"1>> Passenger Ships\n2>> Cargo Ships\n3>> Previous Menu\n";
            cout<<"\nEnter the choice  ";
            cin>>n;
            if(n==1)   //PASSENGER SHIPS
            {
                Pship p;
                cout<<"\n1>> See the list of Ships\n2>> Add Ship Name and Details\n3>> Show Details\n4>> Previous Menu\n";
                cout<<"\nEnter the choice  ";
                cin>>n;
                if(n==1)
                {
                    p.see_p();
                    cout<<"\nDo you want to continue? ";
                    cin>>ch;
                }
                else if(n==2)
                {
                    p.add_p();
                    cout<<"\nDo you want to continue? ";
                    cin>>ch;
                }
                else if(n==3)
                {
                    p.search_p();
                    cout<<"\nDo you want to continue? ";
                    cin>>ch;
                }
                else
                {
                    goto Ships;
                }
            }
            else if(n==2)
            {
                Cship c;
                cout<<"\n1>> See the list of Ships\n2>> Add Ship Name and Details\n3>> Show Details\n4>> Previous Menu\n";
                cout<<"\nEnter the choice  ";
                cin>>n;
                if(n==1)
                {
                    c.see_c();
                    cout<<"\nDo you want to continue? ";
                    cin>>ch;
                }
                else if(n==2)
                {
                    c.add_c();
                    cout<<"\nDo you want to continue? ";
                    cin>>ch;
                }
                else if(n==3)
                {
                    c.search_c();
                    cout<<"\nDo you want to continue? ";
                    cin>>ch;
                }
                else
                {
                    goto Ships;
                }
            }
            else
            goto Menu;
        }
        else if(n==2)  //PROPERTIES
        {
            Properties s;
            cout<<"\n1>> See the list of properties\n2>> Add property\n3>> Search the properties\n4>> Add property with boat name and details\n5>> Add ship in a property\n6>> Previous Menu";
            cout<<"\nEnter the choice  ";
            cin>>n;
            if(n==1)
            {
                s.see_pro();
                cout<<"\nDo you want to continue? ";
                cin>>ch;
                
            }
            else if(n==2)
            {
                s.add_pro();
                cout<<"\nDo you want to continue? ";
                cin>>ch;
            }
            else if(n==3)
            {
                s.search_pro();
                cout<<"\nDo you want to continue? ";
                cin>>ch;
            }
            else if(n==4)
            {
                s.add_pro_detail();
                cout<<"\nDo you want to continue? ";
                cin>>ch;
            }
            else if(n==5)
            {
                s.add_ship();
                cout<<"\nDo you want to continue? ";
                cin>>ch;
            }
            else
            goto Menu;
        }
        else if(n==3)
        {
            cout<<"1>> Add a route\n2>> Add a ship in a route\n3>> Add a route to a ship\
            \n4>> Find routes of a ship\n5>> Find ships of a route\n6>> Previous menu";
            cout<<"\nEnter the choice:";
            cin>>n;
            Routes r;
            if(n==1)
            {
                r.add_r();
                cout<<"\nDo you want to continue? ";
                cin>>ch;
            }
            else if(n==2)
            {
                r.add_r_ship();
                cout<<"\nDo you want to continue? ";
                cin>>ch; 
            }
            else if(n==3)
            {
                r.add_ship_r();
                cout<<"\nDo you want to continue? ";
                cin>>ch;
            }
            else if(n==4)
            {
                r.search_r_ship();
                cout<<"\nDo you want to continue? ";
                cin>>ch;
            }
            else if(n==5)
            {
                r.search_ship_r();
                cout<<"\nDo you want to continue? ";
                cin>>ch;
            }
            else
            goto Menu;
        }
        else if(n==4)    //DELETION
        {
            cout<<"1>> Delete ship\n2>> Delete route\n3>> Previous Menu";
            cout<<"\nEnter the choice";
            cin>>n;
            if(n==1)
            {
                char filename[50];
                cout<<"Enter the file name:";
                fflush(stdin);
                cin.getline(filename,50);
                strcat(filename,".txt");
                deletion(filename);
            }
            else if (n==2)
            {
                char routename[50];
                cout<<"Enter the route name:";
                fflush(stdin);
                cin.getline(routename,50);
                strcat(routename,".txt");
                deletion(routename);
            }
            else
            goto Menu;
        }
        else
        exit(0);
        }while(ch=='y'||ch=='Y');
    }
};
int main()
{
    System s;
    return 0;
}