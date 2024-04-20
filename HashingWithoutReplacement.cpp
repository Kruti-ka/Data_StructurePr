#include<iostream>
#include<string>
using namespace std;
int key[20],c[20],n;
int i;
class Album
{  
	public:
	int track_no;
	string composer,singer,title;
	void declare();
	void display();
	void accept();
	void search();
	void modify();
	void Delete();
}h[20];
void Album::declare()
{
	cout<<"\nEnter the Total No Of Keys: ";
	cin>>n;
	cout<<"\nEnter The Keys: ";
	for(i=0;i<n;i++)
	{
	cin>>key[i];
	}
	for(i=0;i<20;i++)
	{
	
		h[i].track_no=-1;
		c[i]=0;
		
	}
}

void Album::accept()
{
	int no,pos;
	for(i=0;i<n;i++)
	{
		no=key[i]%10;
		pos=no;
		
		do
		{
			if(h[no].track_no==-1)
			{
			h[no].track_no=key[i];
	cout<<"\n********Enter Music Album Details********";
		
				cout<<"\nEnter Title: ";
				cin>>h[no].title;
				cout<<"\nEnter Singer: ";
				cin>>h[no].singer;
				cout<<"\nEnter Composer: ";
				cin>>h[no].composer;
				break;
				
			}
			else
			{
				no++;
				c[pos]=no;
				if(no>10)
				{
					no=0;
				}
			}
		}while(no<10);
	}
}

void Album::display()
{
	cout<<"\nTrackNO\t\tTITLE\t\tSINGER\t\tCOMPOSER\tCHAIN";
	for(i=0;i<20;i++)
	{
		cout<<"\n";
    cout<<h[i].track_no<<"\t\t"<<h[i].title<<"\t\t"<<h[i].singer<<"\t\t"<<h[i].composer<<"\t\t"<<c[i];
	}
}
 void Album::search() {
    int track_no;
    cout << "\nEnter the Track Number to search: ";
    cin >> track_no;

    int pos = track_no % 10;
    int count = 0;
    
    while (count < 20) {
        if (h[pos].track_no == track_no) {
            cout<<"\nTrackNO\t\tTITLE\t\tSINGER\t\tCOMPOSER\tCHAIN\n";
			cout<<h[pos].track_no<<"\t\t"<<h[pos].title<<"\t\t"<<h[pos].singer<<"\t\t"<<h[pos].composer<<"\t\t"<<c[i];
            return;
        }
        pos = (pos + 1) % 20;
        count++;
    }
    cout << "\nTrack not found.";
}

void Album::modify() {
    int track_no;
    cout << "\nEnter the Track Number to modify: ";
    cin >> track_no;

    int pos = track_no % 10;
    int count = 0;
    
    while (count < 20) {
        if (h[pos].track_no == track_no) {
            cout << "\nModifying track number " << track_no;
            cout << "\nEnter new title: ";
            cin >> h[pos].title;
            cout << "\nEnter new singer: ";
            cin >> h[pos].singer;
            cout << "\nEnter new composer: ";
            cin >> h[pos].composer;
            cout << "\nTrack modified successfully!";
            break;
        }
        pos = (pos + 1) % 20;
        count++;
		
			 cout << "\nTrack not found.";
		}
        
    }
	void Album ::Delete()
	{
		int tr ,no;
		cout<<"Enter key to delete";
		cin>>tr;
		no = tr %10;
		if(h[no].track_no ==tr)
		{
			h[no].track_no =-1;
			h[no].title=-1;
			h[no].singer =-1;
			h[no].composer =-1;
		}
		else{
			cout<<"Track not found.";
		}
	}
    



int main()
{
	int ch;
    Album a;
    
    do{
        cout<<"\n1. DECLARE";
		cout<<"\n2. ACCEPT";
		cout<<"\n3. DISPLAY";
		cout<<"\n4. SEARCH";
		cout<<"\n5. MODIFY";
		cout<<"\n6. DELETE";
        cout<<"\n7.EXIT: ";
        cout<<"\nEnter your Choice: ";
		cin>>ch;
        switch (ch)
        {
        case 1:
            a.declare();
            break;
        case 2:
            a.accept();
            break;
        case 3:
            a.display();
            break;
        case 4:
            a.search();
            break;
		case 5:
		     a.modify();
			 break;
		case 6:
		     a.Delete();
			 break;
        case 7:
            exit(0);
            break;
        default:
            cout<<"Invalid choice";
            break;
        }
    }while(ch!=6);
}			
