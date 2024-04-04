#include<iostream>
#include<string>
using namespace std;

class cms
{
public:
    int donarid;
    long int amt,cno;
    string name,address;
    cms *next ,*temp,*prev;
    void create();
    void display();
    void search();
    void update();
    void Delete();
}*start = NULL ,*end1;

void cms::create()
{
    temp = new cms;
    name = new char[100];
    address= new char[100];
    cout<<"Enter the records :";
    cout<<"\nDonar_id :";
    cin>>temp->donarid;
    cout<<"Donar name :";
    cin>>temp->name;
    cout<<"Donar Addres:";
    cin>>temp->address;
    cout<<"Amount:";
    cin>>temp->amt;
    cout<<"Phone no. :";
    cin>>temp->cno;
    temp->next = temp->prev =NULL;
    if(start == NULL)
    {
        end1 = start =temp;
    }
    else{
        end1->next = temp;
        temp->prev = end1;
        end1 = temp;
    }
}

void cms::display()
{
    int cnt =0;
    cms *temp = start;
    if (temp == NULL)
    {
        cout << "List is empty\n";
    }
    else
    {
        cout<<"DONAR RECORDS \n";
        cout<< "DID\tNAME\tADDRESS\t\tAMOUNT\tCONTACT_NO\n";
        while (temp != NULL)
        {
            cout <<temp->donarid<< "\t" <<temp->name<< "\t" <<temp->address << "\t" << temp->amt<< "\t"<< temp->cno<<endl;
            cnt++;
            temp = temp->next;
        }
    }
}
void cms :: search()
{
    int did ,f=0;
    cms *temp = start;
    cout<<"Enter the donar id you want to search:";
    cin>>did;
    while(temp!=NULL)
    {
        if(temp->donarid == did)
        {
          f =1;
          cout<<"Record Found!!!\n";
           cout<< "DID\tNAME\tADDRESS\t\tAMOUNT\tCONTACT_NO\n";
        cout <<temp->donarid<< "\t" <<temp->name<< "\t" <<temp->address << "\t" << temp->amt<< "\t"<< temp->cno<<endl;
        break;
        }
        temp =temp->next;
    }
    if(f ==0)
    {
        cout<<"Book record not found";
    }    

}
void cms :: update()
{
    int did;
    cms *temp = start;
    cout<<"Enter the book id you want to update:";
    cin>>did;
    while(temp!=NULL)
    {
        if(temp->donarid == did)
        {
          cout<<"Enter the Records\n";
          cout<< "DID\tNAME\tADDRESS\t\tAMOUNT\tCONTACT_NO\n";
          cin>>temp->donarid>>temp->name>>temp->address>>temp->amt>>temp->cno;
        }
        cout<<"RECORD UPDATED";
        temp =temp->next;
    }
}
void cms:: Delete()
{
    int del;
    cms *temp,*p;
     temp = start;
    cout<<"Enter the book id whose record you want to delete. ";
    cin>>del;
    if (start == NULL) {
        cout << "List is empty\n";
        return;
    }
    while(temp!=NULL)
    {
        if(temp->donarid==del){
            break;
        }
        p=temp;
        temp = temp->next;
    }
    p->next=temp->next;
    temp->next->prev =p->next;
    delete(temp);
    //cout<<"BOOK DELETED SUCCESSFULLY";
    }



int main()
{
    int ch;
    char x;
    cms c;
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
                c.create();
                cout << "Do you want to add more records? Enter Y/y:";
                cin >>x;
                if(x =='Y' || x=='y'){
                    c.create();
                }
            break;
        case 2:
            c.display();
            break;
        case 3:
            c.search();
            break;
        case 4:
        c.update();
        break;
        case 5:
           c.Delete();
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