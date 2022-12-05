#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<string>
#include<fstream>
using namespace std;
int homeMenu(int);
int userPick(int&,double,int,string,string);
void calc(double&,int&,string&,string&);
int createAccount(string&,string&);
int choiceMenu(int&,string&,string&);
int userChoice(int&,string&,string&);
int loginMenu(int&,string&,string&);
int mainMenu(int& ,string& ,string&);
void printLine();
int main()
{

    int choice,pick;
    string username,password;
    mainMenu(choice,username,password);
    homeMenu(pick);

}
// Display the menu of the system and user can choose choice
int mainMenu(int& choice,string& username,string& password)
{



    cout << setfill(' ')<< setw(90)<<"******************************************************\n";
    cout << setfill(' ')<< setw(80)<<"WELCOME TO BUS RESERVATION SYSTEM"<< endl;
     cout << setfill(' ')<< setw(90)<<"*****************************************************\n";

    cout << setfill(' ')<< setw(70)<<"BY SUPRIYA MISHRA AND SHRIYA SONAM\n";
    cout << setfill(' ')<< setw(70)<<"Please select an option from the menu below:\n";
    cout << setfill(' ')<< setw(35)<<"[1]Login\n";
    cout << setfill(' ')<< setw(50)<<"[2]Create a new account\n";
    cout << setfill(' ')<< setw(34)<<"[3]Exit\n"<< endl;
    cout << setfill(' ')<< setw(52)<<"Please select your choice:";
    cin >> choice;
    cout << endl;

    choiceMenu(choice, username, password);
    userChoice(choice, username, password);
    return choice;

}
// Re-enter choice if user enter the wrong choice
int choiceMenu(int&  choice,string& username,string& password)
{
   while(choice< 1|| choice>3)
   {
       cout << setw(66)<<"Invalid option !. Please enter 1,2 or 3."<< endl;
       choice=mainMenu(choice,username,password);


   }
   return 0;

}
// Display create new account if the choice is 2

int createAccount(string& username,string& password)
{
    cout << setw(85) << "---------------------------------------------------------------\n";
    cout << setw(85)<<  "                       Create a new Account                    \n";
    cout << setw(85)<<  "---------------------------------------------------------------\n";


    cout << setw(47)<<"Create your username: ";
    cin >> username;
    cout <<"\n"<< setw(47)<<"Create your password:";
    cin >> password;
    cout <<"\n"<< setw(68)<<"Your account has been created successfully!"<< endl;
    cout << endl;
    cout << endl;
    return 0;

}
// call the function based on the user's choice
int userChoice(int& choice,string& username,string& password)
{
   switch(choice)
   {
       case 1:
           loginMenu(choice,username,password);
           break;
       case 2:
           createAccount(username,password);
           mainMenu(choice,username,password);
           break;
       case 3:
               exit(0);
       default:
                cout << setw(32)<<"Error!"<< endl;
   }
   return 0;
}
// Display Login menu if the choice is 1
int loginMenu(int& choice,string& username,string& password)
{
   string username2;
   string password2;
cout << setw(85)<< "----------------------------------------------------\n";
   cout << setw(85)<< "                    Login Your Account              \n";
   cout << setw(85)<< "----------------------------------------------------\n";

   bool loginSuccess=false;
   do
   {
       // user must enter the same username and password as in the create account
       cout << setw(46)<<"Enter your username: ";
       cin >> username2;
       cout <<"\n"<< setw(46)<<"Enter your password:";
       cin >> password2;

        if(username2 == username && password2 == password)
            {
            cout << setw(42)<<"Login successful!"<< endl;
            cout << endl;
            cout << endl;
            loginSuccess=true;
            }
    else
        {
        cout << setw(56)<<"Invalid username and password!\n";
        cout << setw(51)<<"Please try to login again."<< endl << endl;
        }
    }while(!loginSuccess);

}
// Display home menu after user successfully login their account
int homeMenu(int pick)
{


    printLine();
    cout << setw(57)<<"Home\n";
   printLine();
   cout << setfill(' ')<< setw(70)<<"Please select an option from the menu below:\n";
   cout << setw(37)<<"[1]Booking\n";
    cout << setw(42)<<"[2]Cancel Order\n";
   cout << setw(34)<<"[3]Exit\n";
   cout << setw(44)<<"Enter your choice:" ;
    cin >> pick;
    cout << endl;
   cout << endl;
    int quantity,choose;
   string name,noPhone;


   if(pick ==1)
        userPick(pick,quantity,choose,name,noPhone);
   if(pick ==2)
    {
        char newBook;
        cout << setw(76)<<"Do you want to cancel your order?Yes(Y/y)/No(N/n):";
            cin >> newBook;
        if(newBook =='Y'|| newBook =='y')
       {


            cout << setw(54)<<"You have cancel your booking.\n";
            cout << setw(35)<<"Thank You!\n";
            cout << setw(45)<<"Come Again Next Time!"<< endl;

       }
        else if(newBook =='n'|| newBook =='N')
        {


            userPick(pick,quantity,choose,name,noPhone);
        }
}
        if(pick ==3)
        {
            cout << setw(31)<<"Thankyou for visiting!";


           exit(0);


        }
}

// Display the bus schedule and their class for user to choose
int userPick(int& pick,double quantity,int choose,string name,string noPhone)
{
   cout << setw(31)<<"Name:";
   cin >> name;
   cout <<"\n";
   cout << setw(46)<<"Number telephone:+91";
   cin >> noPhone;
   cout <<"\n";
   cout << setw(40)<<"Seat Quantity:";
   cin >> quantity;
   cout << endl;




 cout << setw(118)<<"**************************************************************************************"<< endl;
cout << setw(118)<<"No.Seat class Bus No.  Departure             Destination        Date       Time        "<< endl;
cout << setw(118)<<"[1]Economy    106      Terminal Pune         Terminal Mumbai    30/7/22    9:00am      "<< endl;
cout << setw(118)<<"[2]Economy    110      Terminal Bangalore    Terminal Delhi     03/7/22    8:00am      "<< endl;
cout << setw(118)<<"[3]Economy    120      Terminal Mumbai       Terminal Kanpur    07/7/22    5:00pm      "<< endl;
cout << setw(118)<<"[4]Economy    130      Terminal Delhi        Terminal Bangalore 10/7/22    9:00pm      "<< endl;
cout << setw(118)<<"[5]Business   206      Terminal Kanpur       Terminal Hyderabad 15/7/22    9:00pm      "<< endl;
cout << setw(118)<<"[6]Business   210      Terminal Lucknow      Terminal Ranchi    30/7/22    1:00am      "<< endl;
cout << setw(118)<<"[7]Business   220      Terminal Hyderabad    Terminal Pune      13/7/22    8:00am      "<< endl;
cout << setw(118)<<"[8]Business   230      Terminal Ranchi       Terminal Licknow   24/7/22    7:00am      " << endl;
cout << setw(118)<<"***************************************************************************************"<<endl;


cout << setw(45)<<"Choose your ticket:";
cin >> choose;
cout <<"\n";
// For economy class(choose 1-4)
if(choose>=1 && choose<=4)
{
    printLine();
    cout << setw(63)<< setfill(' ')<<"SEAT RESERVATION"<< endl;
    printLine();
    cout << endl;
    const int NROW=10,NCOL=4;
    int seats[NROW][NCOL];
    int seatChoice,getRow,getCol;
    bool isValidInput;
    int n=1,numberSeat=0;
    char addSeat;


    // display seat Layout
    for(int i=0;i<NROW;i++)
    {


       for(int j=0;j<NCOL;j++)
       {
           seats[i][j]=n++;
       }
    }
    cout << setw(75) << setfill(' ') << "Do you want to buy a ticket? Yes(Y/y)or No(N/n):";
    cin >> addSeat;

    while(addSeat =='Y'|| addSeat=='y')
    {
       for(int i=0;i<NROW;i++)
       {


            cout << right << setfill(' ');
           cout << setw(42);
           for(int j=0;j < NCOL;j++)
           {
               cout << seats[i][j]<<'\t';

           }
             cout << endl;
       }
      do
      {


        cout << endl;
        cout << setw(72) << setfill(' ') << "Enter seat(1-40)number to reserve your seats:";
        cin >> seatChoice;
    if(seatChoice < 0|| seatChoice > 40)
       {
            isValidInput=false;
            cout << setw(38) << setfill(' ') << "Invalid Input";
       }
    else
    {


        isValidInput=true;
        numberSeat ++;
    }
}while(!isValidInput);



    getRow=(seatChoice- 1)/NCOL;
    getCol=(seatChoice -1)%NCOL;

    if(seats[getRow][getCol]==0)
    {
    cout << endl;
   cout << setw(72)<< setfill(' ') << "Seat is taken.Please enter a different seat.\n\a";
   cout << endl;
    }
    else if(numberSeat==(quantity+1))
    {
    cout << setw(48)<<"You have reserved your"<< quantity <<"seats."<< endl;
    cout << setw(35)<<"The extra"<< numberSeat- quantity <<"seat/s quantity are rejected."<< endl;
    system("pause");
    }

    else
    {
       seats[getRow][getCol]=0;
       cout << setw(56)<< setfill(' ')<<"Seat is successfully reserved.\n";
       cout << endl;
    }
    cout << setw(81)<< setfill(' ')<<"Do you want to buy another ticket?Yes(Y/y)or No(N/n):";
    cin >> addSeat;
}
    cout << setw(52)<<"You have reserved all your"<< quantity <<"seats."<< endl;
    cout << setw(50)<< setfill(' ')<<"Thank you for your order!"<< endl;
    system("pause");
}

   // For business class(choose 5-8)
else if(choose>=5&& choose<=8)
{
   printLine();
   cout << setw(63)<< setfill(' ')<<"SEAT RESERVATION"<< endl;
   printLine();
   cout << endl;
   const int NROW=10,NCOL=4;
   int seats[NROW][NCOL];
   int seatChoice,getRow,getCol;
   bool isValidInput;
   int n=1,numberSeat=0;
   char addSeat;


  // Display seat Layout
for(int i=0;i < NROW;i++)
{
   for(int j=0;j < NCOL;j++)
   {
       seats[i][j]=n++;
  }
}
cout << setw(75)<< setfill(' ')<<"Do you want to buy a ticket?Yes(Y/y)or No(N/n):";
cin >> addSeat;
while(addSeat =='Y'|| addSeat =='y')
{
    for(int i=0;i<NROW;i++)
   {
       cout << right << setfill(' ');
       cout << setw(42);
       for(int j=0;j<NCOL;j++)
       {
           cout << seats[i][j]<<'\t';
       }
       cout << endl;

   }

do
{


    cout << endl;
    cout << setw(72)<< setfill(' ')<<"Enter seat(1-40)number to reserve your seats:";
    cin >> seatChoice;
    if(seatChoice < 0|| seatChoice > 40)
    {
        isValidInput = false;
        cout << setw(38)<< setfill(' ') << "Invalid Input";
    }
    else
   {


        isValidInput=true;
        numberSeat++;
   }
}while(!isValidInput);

getRow =(seatChoice-1)/NCOL;
getCol= (seatChoice-1)%NCOL;
if(seats[getRow][getCol]==0)
{
    cout << endl;
    cout << setw(72)<< setfill(' ')<<"Seat is taken.Please enter a different seat.\n\a";
    cout << endl;
}
else if(numberSeat==(quantity+1))
{
         cout << setw(48)<<"You have reserved your"<< quantity <<"seats."<< endl;
cout << setw(45)<<"The extra "<< numberSeat- quantity << "seat/s quantity are rejected."<< endl;
system("pause");
}


else
{
   seats[getRow][getCol]=0;
   cout << setw(56)<< setfill(' ')<<"Seat is successfully reserved.\n";
   cout << endl;
}
cout << setw(81)<< setfill(' ')<<"Do you want to buy another ticket?Yes(Y/y)or No(N/n):";
cin >> addSeat;
}

cout << setw(52)<<"You have reserved all your" << quantity <<"seats."<< endl;
cout << setw(50)<< setfill(' ')<<"Thank you for your order!"<< endl;
system("pause");
}


// when user enter other than 1-8,it will display home menu again
else
{
   cout << setw(42)<<"Invalid choice.\n\a";
   homeMenu(pick);
}
calc(quantity,choose,name,noPhone);

}


// display the details of invoice slip in external file called invoice.txt
void calc(double& quantity,int& choose,string& name,string& noPhone)
{


   ofstream outFile;
   outFile.open("invoice.txt");
   if(outFile.fail())
{
       cout << setw(70)<<"The invoice slip was not successfully opened."<< endl;
}
   double total;

   // Price for economy seat class for every trip
double const priceChoose1=30.00,priceChoose2=20.00,priceChoose3=35.00,priceChoose4=25.00;
                        // Price for business seat class for every trip
double const priceChoose5=50.00,priceChoose6=35.00,priceChoose7=55.00,priceChoose8=40.50;
printLine();
cout << setw(80)<<" Express Bus Reservation System"<< endl;
cout << setw(64)<< setfill(' ')<<"Invoice Slip"<< endl;
printLine();


outFile << setw(85)<< "******************************************************************" << endl;
outFile << setw(74)<<"Express Bus Reservation System"<< endl;
outFile << setw(61)<< setfill(' ')<<"Invoice Slip"<< endl;
outFile << setw(85)<<"******************************************************************" <<endl;
if(choose ==1)
{
          total =priceChoose1*quantity;
outFile << setw(50)<<"Name               :" << setw(30)<< name << endl;
outFile << setw(50)<<"Number telephone   :" << setw(21)<<"+91"<< noPhone << endl;
outFile << setw(50)<<"Seat quantity      :" << setw(30)<< quantity << endl;
outFile << setw(50)<<"Seat Class         :" << setw(30)<<"Economy"<< endl;
outFile << setw(50)<<"Bus Number         :" << setw(30)<<"106"<< endl;
outFile << setw(50)<<"Departure Station  :"<< setw(30)<<"Pune"<< endl;
outFile << setw(50)<<"Destination Station:"<< setw(30)<<"Mumbai"<< endl;
outFile << setw(50)<<"Date               :" << setw(30)<<"30/07/21"<< endl;
outFile << setw(50)<<"Time               :"<< setw(30)<<"9:00 am"<< endl;
outFile << fixed << showpoint << setprecision(2);
outFile << setw(50)<<"Total              :"<< setw(24)<<"Rs"<< total << endl;

}
else if(choose==2){
              total = priceChoose2 * quantity;
outFile << setw(58)<<"Name                 :" << setw(30)<< name << endl;

outFile << setw(50)<<"Number telephone     :" << setw(21)<<"+60"<< noPhone << endl;

outFile << setw(50)<<"Seat quantity        :" << setw(30)<< quantity << endl;

outFile << setw(58)<<"Seat Class           :" << setw(30)<<"Economy"<< endl;

outFile << setw(50)<<"Bus Number           :"<< setw(30)<<"110"<< endl;

outFile << setw(50)<<"Departure Station    :"<< setw(30)<<"Bangalore"<< endl;
outFile << setw(50)<<"Destination Station  :"<< setw(30)<<"Delhi"<< endl;
outFile << setw(50)<<"Date                 :" << setw(30)<<"03/07/21"<< endl;
outFile << setw(50)<<"Time                 :"<< setw(30)<<"8:00 am"<< endl;
outFile << fixed << showpoint << setprecision(2);


outFile << setw(50)<<"Total                :"<< setw(24)<<"Rs"<< total << endl;

}
else if(choose==3){

     total= priceChoose3*quantity;
outFile << setw(58)<<"Name                    :" << setw(30)<< name << endl;

outFile << setw(50)<<"Number telephone        :" << setw(21)<<"+91"<< noPhone << endl;

outFile << setw(50)<<"Seat quantity           :" << setw(30)<< quantity << endl;

outFile << setw(58)<<"Seat Class              :" << setw(30)<<"Economy"<< endl;

outFile << setw(50)<<"Bus Number              :"<< setw(30)<<"120"<< endl;

outFile << setw(50)<<"Departure Station       :"<< setw(30)<<"Terminal Mumbai"<< endl;

outFile << setw(50)<<"Destination Station     :"<< setw(30)<<"Terminal Kanpur"<< endl;
outFile << setw(50)<<"Date                    :" << setw(30)<<"07/07/21"<< endl;
outFile << setw(50)<<"Time                    :"<< setw(30)<<"9:00 am"<< endl;
outFile << fixed << showpoint << setprecision(2);
outFile << setw(50)<<"Total                   :"<< setw(24)<<"Rs"<< total << endl;
}
else if(choose==4){

     total =priceChoose4*quantity;
outFile << setw(58)<<"Name                   :" << setw(30)<< name << endl;

outFile << setw(50)<<"Number telephone       :" << setw(21)<<"+60"<< noPhone << endl;

outFile << setw(50)<<"Seat quantity          :" << setw(30)<< quantity << endl;

outFile << setw(58)<<"Seat Class             :" << setw(30)<<"Economy"<< endl;

outFile << setw(50)<<"Bus Number             :"<< setw(30)<<"130"<< endl;

outFile << setw(50)<<"Departure Station      :"<< setw(30)<<"Terminal Delhi"<< endl;

outFile << setw(50)<<"Destination Station    :"<< setw(30)<<"Terminal Bangalore"<< endl;
outFile << setw(50)<<"Date                   :" << setw(30)<<"10/07/21"<< endl;
outFile << setw(50)<<"Time                   :"<< setw(30)<<"9:00 am"<< endl;
outFile << fixed << showpoint << setprecision(2);
outFile << setw(50)<<"Total                  :"<< setw(24)<<"Rs"<< total << endl;

}

else if(choose==5){

     total= priceChoose5*quantity;
outFile << setw(58)<<"Name                 :" << setw(30)<< name << endl;

outFile << setw(50)<<"Number telephone     :" << setw(21)<<"+91"<< noPhone << endl;

outFile << setw(50)<<"Seat quantity        :" << setw(30)<< quantity << endl;

outFile << setw(58)<<"Seat Class           :" << setw(30)<<"Business"<< endl;

outFile << setw(50)<<"Bus Number           :"<< setw(30)<<"206"<< endl;

outFile << setw(50)<<"Departure Station    :"<< setw(30)<<"Terminal Kanpur"<< endl;

outFile << setw(50)<<"Destination Station  :"<< setw(30)<<"Terminal Hyderabad"<< endl;
outFile << setw(50)<<"Date                 :" << setw(30)<<"15/07/21"<< endl;


outFile << setw(50)<<"Time                 :"<< setw(30)<<"9:00 am"<< endl;
outFile << fixed << showpoint << setprecision(2);


outFile << setw(50)<<"Total                :"<< setw(24)<<"Rs"<< total << endl;

}
else if(choose==6){

     total= priceChoose6*quantity;
outFile << setw(58)<<"Name                 :" << setw(30)<< name << endl;

outFile << setw(50)<<"Number telephone     :" << setw(21)<<"+60"<< noPhone << endl;

outFile << setw(50)<<"Seat quantity        :" << setw(30)<< quantity << endl;

outFile << setw(58)<<"Seat Class           :" << setw(30)<<"Buisness"<< endl;

outFile << setw(50)<<"Bus Number           :"<< setw(30)<<"210"<< endl;

outFile << setw(50)<<"Departure Station    :"<< setw(30)<<"Terminal Lucknow"<< endl;

outFile << setw(50)<<"Destination Station  :"<< setw(30)<<"Terminal Ranchi"<< endl;
outFile << setw(50)<<"Date                 :" << setw(30)<<"30/07/21"<< endl;


outFile << setw(50)<<"Time                 :"<< setw(30)<<"1:00 am"<< endl;
outFile << fixed << showpoint << setprecision(2);


outFile << setw(50)<<"Total                :"<< setw(24)<<"Rs"<< total << endl;

}
else if(choose==7){

     total= priceChoose7*quantity;
outFile << setw(58)<<"Name                            :" << setw(30)<< name << endl;

outFile << setw(50)<<"Number telephone                :" << setw(21)<<"+60"<< noPhone << endl;

outFile << setw(50)<<"Seat quantity                   :" << setw(30)<< quantity << endl;

outFile << setw(58)<<"Seat Class                      :" << setw(30)<<"Business"<< endl;

outFile << setw(50)<<"Bus Number                      :"<< setw(30)<<"220"<< endl;

outFile << setw(50)<<"Departure Station               :"<< setw(30)<<"Terminal Hyderabad"<< endl;

outFile << setw(50)<<"Destination Station             :"<< setw(30)<<"Terminal Pune"<< endl;
outFile << setw(50)<<"Date                            :" << setw(30)<<"13/07/21"<< endl;


outFile << setw(50)<<"Time                            :"<< setw(30)<<"8:00 am"<< endl;
outFile << fixed << showpoint << setprecision(2);


outFile << setw(50)<<"Total                           :"<< setw(24)<<"Rs"<< total << endl;

}
else if(choose==8){

     total =priceChoose8*quantity;
outFile << setw(58)<<"Name                 :" << setw(30)<< name << endl;
outFile << setw(50)<<"Number telephone     :" << setw(21)<<"+60"<< noPhone << endl;
outFile << setw(50)<<"Seat quantity        :" << setw(30)<< quantity << endl;
outFile << setw(58)<<"Seat Class           :" << setw(30)<<"Business"<< endl;
outFile << setw(50)<<"Bus Number           :"<< setw(30)<<"230"<< endl;
outFile << setw(50)<<"Departure Station    :"<< setw(30)<<"Terminal Ranchi"<< endl;
outFile << setw(50)<<"Destination Station  :"<< setw(30)<<"Terminal Lucknow "<< endl;
outFile << setw(50)<<"Date                 :" << setw(30)<<"24/07/21"<< endl;
outFile << setw(50)<<"Time                 :"              << setw(30)<<"7:00 am"<< endl;
outFile << fixed << showpoint              << setprecision(2);
outFile << setw(50)<<"Total                :"<< setw(24)<<"Rs"<< total << endl;

}


outFile << setw(65)<<"*******************************************************************" << endl;
outFile << setw(65)<<setfill(' ')  << "Thank you for Choosing us" << endl;
outFile << setw(65)<<setfill(' ')  << "See you again next time" << endl;
outFile << setw(65)<<"*****************************************************" << endl;
outFile << setw(65)<<"*****************Invoice slip has been successfully opened*********" << endl;
outFile.close();
}

void printLine(){
    cout<< setw(85)<<"********************************************************************" << endl;
}

