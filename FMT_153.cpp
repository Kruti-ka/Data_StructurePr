#include<iostream>
#include<string>
#define max 20
using namespace std;

class fmt
	{
	int gen,age,cnt1=0,cnt2=0,cnt=0;
	string name,gender;
	fmt *lc,*rc;
	public:
	void create();
	void insert(fmt *root,fmt *next);
	void display(fmt *root);
	void totalgen();
	void leaf(fmt *root);

	}*root,*next,*stack[max],*temp;

void fmt::create()
	{
	int ch ;
	fmt * next;
	root = new fmt;
	cout<<"Enter your records";
	cout<<"\nEnter name :";
	cin>>root->name;
	cout<<"Enter gender:";
	cin>>root->gender;
	cout<<"Enter Age :";
	cin>>root->age;
	cout<<"Enter generation number :";
	cin>>root->gen;
	root->lc=root->rc=NULL;
	cnt=cnt1=cnt2=1;
	do{
	cout<<"Do you want to add more records?";
	cin>>ch;
	  if(ch==1){
	  next =new fmt;
	  cout<<"Enter the data for new node";
	  cout<<"\nEnter name :";
	  cin>>next->name;
	  cout<<"Enter gender:";
	  cin>>next->gender;
	  cout<<"Enter Age :";
	  cin>>next->age;
	  cout<<"Enter generation number :";
	  cin>>next->gen;
	  next->lc=next->rc=NULL;
	 insert(root,next);
	 }
	}
	while(ch ==1);
	}

void fmt::insert(fmt *root,fmt *next)
{
	char chr;
	fmt *temp;
	cout<<"On which side you want to insert the data 'L' or 'R'?";
	cin>>chr;
	if(chr=='L' || chr=='l')
	{
	if(root->lc==NULL)
	{
	root->lc=next;
	cnt1++;
	}
	else{
	insert(root->lc,next);
	}
	}
	if(chr=='R' || chr=='r')
	{
	if(root->rc==NULL)
	{
	root->rc=next;
	cnt2++;
	}
	else{
	insert(root->rc,next);
	}
	}
	}
void fmt::display(fmt *root)
	{
	if(root==NULL){
	return;
	}
	else{

	cout <<root->name<<"\t\t"<<root->gender <<"\t\t"<<root->age<<"\t\t"<< root->gen<< endl;
	display(root->lc);
	display(root->rc);
	}
	}
void fmt :: totalgen()
{
 if(cnt1>=cnt2){
 cout<<"Total generation number are:"<<cnt1;
}
else{
cout<<"Total generation number are:"<<cnt2;
}
}
void fmt::leaf(fmt*root)
{
int top=-1;
temp = root;
if(root!=NULL){
 do{
   while(temp!=NULL){
   top++;
   stack[top]=temp;
   temp=temp->lc;
   }
   if(top!=-1)
   {
   temp =stack[top];
   if(temp->lc==NULL && temp->rc==NULL)
   {
   cout <<temp->name<<"\t\t"<<temp->gender <<"\t\t"<<temp->age<<"\t\t"<<temp->gen<< endl;
   }
   temp=temp->rc;
   top--;
   }
   }while(top!=-1 || temp!=NULL);
   }
   }
  
int main()
{
int ch;
fmt f;
do
{
cout << "\n1. Enter the records\n";
cout << "2. Display the records\n";
cout << "3. Total generation records\n";
cout << "4. Display Leaf node\n";
cout << "5.Exit\n";
cout << "Enter your choice: ";
cin >> ch;
switch (ch)
{
case 1:
f.create();
break;
case 2:
cout<<"NAME\t\tGENDER\t\tAGE\t\tGENERATION\n";
f.display(root);
break;
case 3:
f.totalgen();
break;
case 4:
cout<<"NAME\t\tGENDER\t\tAGE\t\tGENERATION\n";
f.leaf(root);
break;
case 5:
exit;
default:
cout<<"INVALID CHOICE!";
break;
}
} while (ch !=6);
return 0;
}

