#include <iostream>
#include <fstream>
using namespace std;
//First here we create a class and we can declare some variables and functions
class shopping
{
    private://This private will only able use by administrator because it is in private scope
    int pcode;
    float price;//Prrice for the given product
    float dis;//Discount
    string pname;//Product name
    
    public://This public scope any one can able to use
    void menu();//In this function we can able to  check which products are available in the store whether it will be fresh products or daily company products
    void administrator();//In this function the administratoronly can able to login
    void buyer();//This is the coustmer function the coustmer can able to login and check the products and can buy which products are available
    void add();//In this function we can add 
    void edit();//In this function the administrator can able to change the products and edit the products what ever available in the store whether it is day to day stock or any thing
    void rem();//In this function the administrator can remove the products which will be not available in store
    void list();//This function will use to display the list
    void receipt();//This function after coustmer will buy we can generate the receipt
};
//From here onwards we can start the functions one by one which we can add in the class function
void shopping :: menu()
{
    m:
    int choice;
    string email;//For the login purpose
    string password;
    
    cout<<"\t\t\t\t_______________________________________\n";//To display the menu
    cout<<"\t\t\t\t                                       \n";
    cout<<"\t\t\t\t              SUPER MARKET MAIN MENU   \n";
    cout<<"\t\t\t\t                                       \n";
    cout<<"\t\t\t\t_______________________________________\n";
    cout<<"\t\t\t\t                                       \n";
    //Now we create a menu in which user has to select wwther he is an administrator or buyer
    cout<<"\t\t\t\t|  1)Administrator   |\n";//Who can change the products and can able to give the discounts and all
    cout<<"\t\t\t\t|                    |\n";
    cout<<"\t\t\t\t|  2)Buyer           |\n";//Who can buy the products what ever he want
    cout<<"\t\t\t\t|                    |\n";
    cout<<"\t\t\t\t|  3)Exit            |\n";
    cout<<"\t\t\t\t|                    |\n";
    //Now we can display a message please select  from above three
    cout<<"\n\t\t\tPlease select";
    cin>>choice;//Whatever he want he will click that one
    //Now we can create the switch case to select the number
    switch(choice)//To select the number which ever u want
    {
        case 1:
        cout<<"\t\t\t  Please Login \n";//If he is the administrator we can ask the login details and passsword for the verification wether he is only or not
        cout<<"\t\t\t  Enter Email Id \n";//When he was login the administrator can give the Email
        cin>>email;//Administrator want to give the email
        cout<<"\t\t\t  Password \n";//Asking the password from the Administrator
        cin>>password;//Taking the password from Administrator
        
        if(email=="kothanarasimharao@gmial.com" ||email=="dinesh@gmail.com" || email=="veera@gmail.com" && password=="120121131")//Creating passwords for the safety only Administrator will know these passwords
        {
            administrator();
        }
        else//If password and email is wrong means
        {
            cout<<"Invalid email/password";
        }
        break;//To end the case
        case 2:
        {
            buyer();//The buyer function will be availbale now;
        }
        case 3:
        {
            exit(0);//To exit outside
        }
        default :
        {
            cout<<"Please select from the given options";
        }
    }
    goto m;//It will help us going to the main menu again
}
//Now we can create an administration function in which there will be different options inside the MENU
void shopping :: administrator()
{
    m:
    int choice;
    cout<<"\n\n\n\t\t\t Administrator menu";
    cout<<"\n\t\t\t|______1) Add the product______| ";//The Administrator can select this if he want to add the product
    cout<<"\t\t\t\t|                              |";
    cout<<"\n\t\t\t|_____2) Modify the product____|";//The Administrator can able to modify the product
    cout<<"\t\t\t\t|                              |";
    cout<<"\n\t\t\t|_____3) Delete the product____|";//If stock is not available the Administrator can delete the product
    cout<<"\n\t\t\t|                              |";
    cout<<"\n\t\t\t|_____4) Back to main menu ____|";
    
    cout<<"\n\n\t Please enter your choice";//We will ask Administrator
    cin>>choice;//The user can enter the choice
    switch(choice)
    {
        case 1:
        add();
        break;
        case 2:
        edit();
        case 3:
        rem();
        break;
        case 4:
        menu();
        break;
        default :
        cout<<"Invalid choice";
    }
    goto m;
}
//Now we can create a buyer function
void shopping :: buyer()
{
    m:
    int m;
    int choice;//The buyer can enter the choice what ever hw want to buy 
    cout<<"\t\t\t    Buyer    \n";
    cout<<"\t\t\t_____________ \n";
    cout<<"                    \n";
    cout<<"\t\t\t 1) Buy Product \n";//If he want to buy the products
    cout<<"                 \n";
    cout<<"\t\t\t 2) Go back \n";//If he want to go back to outside
    cout<<"\t\t\t Enter your choice : ";
    cin>>choice;
    //We use the switch statement to enter the user choice
    switch(choice)
    {
        case 1:
        receipt();//All the operations wil buyer takes place
        break;
        
        case 2:
        menu();//To see the menu 
        break;
        
        default:
        cout<<"Invalid choice";
        
    }
    goto m;
}
//Now we can create the add function
void shopping :: add()
{
    m:
    fstream data;//We are using the files concept here 
    int c;
    int token=0;
    float p;
    float d;
    string n;
    //Now we have to create we have to ask the user enter the product code price  of the product and discount of the product
    cout<<"\n\n\t\t\t Add new product ";
    cout<<"\n\n\t Product code of the product";
    cin>>pcode;//Product code
    cout<<"\n\n\t Name of the product ";
    cin>>pname;//Product Name
    cout<<"\n\n\t Price of the product ";
    cin>>price;
    cout<<"\n\n\t Discount of the product ";
    cin>>dis;
    //Here we need to add the file because these products are changed by the Administrator these are the show to thw user
    
    data.open("database.txt",ios::in);//Here we can open the file by Administrator to change the product the ios will help wether we want the file is in the reading mode or writing mode the ios::in will help the file is in the reading mode
    
    if(!data)
    {
        data.open("database.txt",ios::app|ios::out);//out means we can edit the file app means we append the file
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";//This is the syntax how we can write in the file mode
        data.close();//Close the file
    }
    else
    {
        data>>c>>n>>p>>d;//If that file exists just we can read from the file
        while(!data.eof())//eof is end of file//This while loop will check every content of the file if there is matches with the pcode that if there is any duplicay the toekn count will increase 
        {
            if(c==pcode)
            {
                token++;
            }
            data>>c>>n>>p>>d;
        }
        data.close();
        if(token==1)//Means if there is a duplicacy then again go to the main menu
        {
            goto m;//It will go back to the menu he want to add the another product code
        }
        else
        {
            data.open("database.txt",ios::app|ios::out);
            data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
            data.close();//Close the file
        }
    }
    cout<<"\n\n\t\t Record Inserted !  ";
}
//Now we are creating the edit function to add or delete the items for the list 
void shopping:: edit()
{
    fstream data,data1;//we are creating the fstream class of  data and data1
    int pkey;//declare the variables
    int token=0;
    int c;
    float p;
    string n;//sting
    cout<<"\n\t\t\t Modify the Record";//For the modification
    cout<<"\n\t\t\t Enter the product code :";//to enter the product code by administrator
    cin>>pkey;//taking the value from the administrator
    data.open("database.txt",ios::in);//we are opening the file if the file is exist or not
    if(!data)
    {
        cout<<"\n\nFile doesn't exist! ";//if file is not present
    }
    //In else block we will open the new file
    else
    {
        data1.open("database1.txt",ios::app|ios::out);//Here file is opening in append mode or edted mode
        //Now we will open the new file and rename the file name to the database.txt
        data>>pcode>>pname>>price>>dis;
        while(!data.eof())//It will check every content of the file
        {
            if(pkey==pcode)//Entered by the administaror which we want to edit then 
            {
                int d;
                cout<<"\n\t\t Product new code :";//Asking the administrator to enter the new code
                cin>>c;
                cout<<"\n\t\t Name of the product :";
                cin>>n;
                cout<<"\n\t\t Price :";
                cin>>p;
                cout<<"\n\t\t Discount :";
                cin>>d;
                //Now all the updated details of the product will be entered with the help of data1 object
                data1<<" "<<c<<" "<<n<<" "<< p<<" "<<d<<"\n";//To take the data from the administrator
                cout<<"\n\n\t\t Record edited"; 
                token++;//To increment the token
            }
            else
            {
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";//If the prosuct key or product code doesbot matches with any of the one thenthe old variables will come

            }
            data>>pcode>>pname>>price>>dis;//Just for the increment purpose
        }
        data.close(); //We are closing both the files
        data1.close();
        //Now we can remove the database1.txt file and remname the database.txt file data1.txt->data.txt
        remove("database.txt");
        rename("database1.txt","database.txt");//First we need to write old name name and then we need to write the new name of the file
        if(token==0)
        {
            cout<<"\n\n Record not found sorry! ";
        }
    }
}
//Now done with the edit function and now we will create the remove function
void shopping::rem()
{
    fstream data,data1;//Will create two objects
    int pkey;
    int token=0;//Because initial value is zero
    cout<<"\n\n\t Delete product";
    cout<<"\n\n\t Product code :";
    cin>>pkey;
    data.open("database.txt",ios::in);//We are opening in reading mode to check this  file is exist ornot
    if(!data)
    {
        cout<<"File Doesn't exist";
    }
    else
    {
        data.open("database1.txt",ios::app|ios::out);//open  the file in append or writing mode
        data>>pcode>>pname>>price>>dis;//This is how we read from the file
        while(!data.eof())
        {
            if(pcode==pkey)
            {
                cout<<"\n\n\t Product deleted successfully";
                token++;//Token is incremented
            }
            else//In else block all the products will be displayed except the one which we want to remove or delete
            {
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";

            }
            data>>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt","database.txt");//Rename the file database1.txt->database.txt
        if(token==0)
        {
            cout<<"\n\n Record not found";
        }
   }
}
//Now we will create the one more function name list it will help to show the list to the custome or buyer
void shopping::list()
{
    fstream data;
    data.open("database.txt",ios::in);//open the file in the reading mode
    cout<<"\n\n|______________________________________________\n";
    cout<<"ProNo\t\tName\t\tPrice\n";
    cout<<"\n\n|______________________________________________\n";
    data>>pcode>>pname>>price>>dis;
    while(!data.eof())
    {
        cout<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\n";
        //For iteration pyrpose we will write again
        data>>pcode>>pname>>price>>dis;
    }
    data.close();
}
//Now we will create the recepit function  which will saw by user
void shopping::receipt()
{
    m:
    //Here can use some arrays because we want to store multiple products of the arrays
    fstream data;
    int y;
    int arrc[100];
    int arrq[100];
    char choice;
    int c=0;
    float amount=0;//Initally we dont know how much amouunt the customer will take or bought thats why initally take it as zero
    float dis=0;
    float total=0;
    cout<<"\n\n\t\t\t\t RECEPIT ";
    data.open("database.txt",ios::in);//open the file to check database is exist or not
    if(!data)
    {
        cout<<"\n\n Empty database";//If the file is not exist
    }
    else
    {
        data.close();
        cout<<"\n______________________________________________\n";
        cout<<"\n|                                              \n";
        cout<<"\n         Please place the order                \n";
        cout<<"\n|                                              \n";
        cout<<"\n______________________________________________\n";
        do//The purpose of the dowhile lopp is every time we need to run the specific part of the code
        {
            cout<<"\n\nEnter Product code :";
            cin>>arrc[c];
            cout<<"\n\nEnter the qunatity :";
            cin>>arrq[c];
            for(int i=0;i<c;i++)
            {
                if(arrc[c]==arrc[i])//If the product code matches with the
                {
                    cout<<"\n\n Duplicate product code. Please try again!";
                    goto m;
                }
            }c++;//If the product code will not be duplicate then the counter will increment
            cout<<"\n\n Do you want to buy another product? if yes then press y else no";
            cin>>choice;    
        }
        while(choice == y);//If the user choose the yes
        
        cout<<"\n\n\t\t\t_________________________RECEPIT____________________________\n";
        cout<<"\nProduct No\t product Name\t product quantity\t price\t Amount\tAmount with discount\n";
        for(int i=0;i<c;i++)
        {
            data.open("database.txt",ios::in);
            data>>pcode>>pname>>price>>dis;
            while(!data.eof())
            {
                if(pcode==arrc[i])
                {
                    amount=price*arrq[i];
                    dis=amount-(amount*dis/100);
                    total=total+dis;
                    cout<<"\n"<<pcode<<"\t\t"<<pname<<"\t\t"<<arrq[i]<<"\t\t"<<price<<"\t\t"<<amount<<"\t\t"<<dis;
                }
                data>>pcode>>pname>>price>>dis;
            }
        }
        data.close();
    }
    cout<<"\n\n________________________________________________";
    cout<<"\n Total Amount : "<<total;
}
int main()
{
    shopping s;
    s.menu();//It is the top of the function it will display when it will run
}
