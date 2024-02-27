#include<iostream>
#include<string>
using namespace std;

class lms
{
public:
    int bookid, price, rack_no;
    string title, author;
    lms *next ,*temp;
    void create();
    void display();
    void search();
    void update();
    void Delete();
}*start = NULL;

void lms::create()
{
    temp = new lms;
    title = new char[100];
    author= new char[100];
    cout<<"Enter the records :";
    cout<<"\nBook_id :";
    cin>>temp->bookid ;
    cout<<"Book_name :";
    cin>>temp->title;
    cout<<"Book Author :";
    cin>>temp->author;
    cout<<"Price :";
    cin>>temp->price;
    cout<<"Rack no :";
    cin>>temp->rack_no;
    temp->next = NULL;
    temp->next =start;
    start = temp;
}

void lms::display()
{
    lms *temp = start;
    if (temp == NULL)
    {
        cout << "List is empty\n";
    }
    else
    {
        cout<<"BOOKS RECORDS \n";
        cout<< "BID\tNAME\tAUTHOR\tPRICE\tRACKNO\n";
        while (temp != NULL)
        {
            cout <<temp->bookid << "\t" <<temp->title << "\t" <<temp->author << "\t" << temp->price<< "\t"<< temp->rack_no << endl;
            temp = temp->next;
        }
    }
}
void lms :: search()
{
    int bid ,f=0;
    lms *temp = start;
    cout<<"Enter the book id you want to search:";
    cin>>bid;
    while(temp!=NULL)
    {
        if(temp->bookid == bid)
        {
          f =1;
          cout<<"Book Found!!!\n";
          cout<< "BID\tNAME\tAUTHOR\tPRICE\tRACKNO\n";
         cout <<temp->bookid << "\t" <<temp->title << "\t" <<temp->author << "\t" << temp->price<< "\t"<< temp->rack_no << endl;
        }
        temp =temp->next;
    }
    if(f ==0)
    {
        cout<<"Book record not found";
    }    

}
void lms :: update()
{
    int bid;
    lms *temp = start;
    cout<<"Enter the book id you want to update:";
    cin>>bid;
    while(temp!=NULL)
    {
        if(temp->bookid == bid)
        {
          cout<<"Enter the Records\n";
          cout << "BID\tNAME\tAUTHOR\tPRICE\tRACKNO\n";
          cin>>temp->bookid>>temp->title>>temp->author>>temp->price>>temp->rack_no;
        }
        temp =temp->next;
    }
}
void lms :: Delete()
{
    int del;
    lms *temp = start;
    cout<<"Enter the book id whose record you want to delete. ";
    cin>>del;
    if (start == NULL) {
        cout << "List is empty\n";
        return;
    }
    temp = start;
    lms *prev = NULL;
    while (temp != NULL && temp->bookid!= del) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        cout << "Book ID not found\n";
        return;
    }
    if (prev == NULL)
        start = start->next;
    else
        prev->next = temp->next;
    delete temp;
    cout<<"BOOK DELETED SUCCESSFULLY";
}


int main()
{
    int ch;
    char x;
    lms l;
    do
    {
        cout << "\n1. Enter the records\n";
        cout << "2. Display the records\n";
        cout << "3. Search the records\n";
        cout << "4. Update the records\n";
        cout << "5. Delete the records\n";
        cout << "6.Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
                l.create();
                cout << "Do you want to add more records? Enter Y/y:";
                cin >>x;
                if(x =='Y' || x=='y'){
                    l.create();
                }
            break;
        case 2:
            l.display();
            break;
        case 3:
            l.search();
            break;
        case 4:
        l.update();
        break;
        case 5:
           l.Delete();
           break;
        case 6:
        exit;
        default:
        cout<<"INVALID CHOICE!";
        break;
        }
    } while (ch !=7);

    return 0;
}