#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <process.h>
#include <cstring>
#include <fstream>


void Search();
void CREATE();
void create();
void Display();
void food();
void clothes();
void house();
void update();
using namespace std;
class service
  {

      public:
          char name[20], place[30], gen[7];
       int idcode=0,foodcost=0,clothescost=0,housecost=0,totalcost=0;
       char foodtype[20], houseloc[50], clothestype[20];
        void getdata()

	    {
		  cout<<"\n ENTER YOUR NAME, IDCODE, GENDER (MALE/FEMALE/OTHER) AND PLACE OF RESIDENCE\t";
		  cin>>name>>idcode>>gen>>place;
	    }

	    int getidcode ()
	    {
		  return (idcode);
	    }

	    char* getname()
	    {
		  return(name);
	    }

	    char* getplace()
	    {
		  return(place);
	    }

	    void display()
	    {
          cout<<"\n NAME = \t"<<name;
		  cout<<"\n IDCODE = \t"<<idcode;
		  cout<<"\n GENDER = \t"<<gen;
		  cout<<"\n PLACE = \t"<<place;
		  cout<<"\n Donations made for:-";
		  cout<<"\n"<<foodcost<<" for FOOD:"<<foodtype;
		  cout<<"\n"<<clothescost<<" for CLOTHES:"<<clothestype;
		  cout<<"\n"<<housecost<<" for Housing";
		  cout<<"\n Totalcost = "<<totalcost;
	    }
  };


void update()
 {
     fstream fsoc ("Social.dat", ios :: in);
     fstream ftemp ("Temp.dat", ios:: out);
     service s;
     char name [20];
     cout <<"\n Enter name to update your details \t";

     while (fsoc.read((char*)&s, sizeof (s)))
            {   if (strcmp(s.getname(),name)==0)
                     { cout<<"\n Enter new details";
                       s.getdata();
                       ftemp.write ((char*)& s, sizeof (s));
                     }
                else
                      ftemp.write ((char*)& s, sizeof (s));
            }

    fsoc.close();
    ftemp.close();
    remove("Social.dat");
    rename ("Temp.dat", "Social.dat");
 }



int main ()
{
    service s;
    int ch;
    do
     {
	   cout<<"\n WELCOME TO RAISE YOUR HAND TO HELP SOCIETY (RYHTHS) PROCESSING SYSTEM";
	   cout<<"\n MENU";
	   cout<<"\n 1. Create a Social Donation Account";
	   cout<<"\n 2. Access your Account details";
	   cout<<"\n 3. Display";
	   cout<<"\n 4. Exit";
	   cout<<"\n Enter your choice \t";
	   cin>>ch;

       switch (ch)
	      {
		    case 1: CREATE();
			        break;
            case 2: Search();
                    break;
            case 3: Display();
                     break;

	    }
     } while (ch<=3);
     return 0;
}

void Display()
{
    fstream fsoc ("Social.dat", ios::in);
    service s;
    int regno, found=0;
    cout<<"\n Enter idcode to display\t";
    cin>>regno;
    while(fsoc.read((char*)&s, sizeof(s)))
    {
        if (s.getidcode()==regno)
        {
            found = 1;
            s.display();
            break;
        }
    }
    if (found==0)
         {cout<<"\n No such student";
          cout<<"\n You are now being forwarded to create a Social Account";
          CREATE();
         }

}

void CREATE()
{
    fstream fsoc ("Social.dat", ios::out);
    service s;
    cout<<"\n You have chosen to create a Social Donation Account";
    int n;
    cout<<"\n Enter limit";
    cin>>n;
    for (int i=0; i<n; i++)
    {
        s.getdata();
        fsoc.write((char *)& s, sizeof(s));
    }
    fsoc.close();
    create();
}
 void create()
 { fstream fsoc ("Social.dat", ios::in|ios::out);
    service s;
  int regno;
  cout<<"\n Enter your id number\t";
  cin>>regno;
  while(fsoc.read((char*)&s, sizeof(s)))
  {if(s.getidcode()==regno)
  { char ch;
      cout<<"\n 1. Do you wish to donate food?(Y OR N)";
  cin>>ch;
  if (ch=='Y')
     {int chf;
       cout<<"\n You have chosen to donate food.";
       cout<<"\n Choose type of food package you wish to donate";
       cout<<"\n 1. Lunch/Dinner meal with beverage (AED 30)";
       cout<<"\n 2. Breakfast with beverage (AED 25)";
       cout<<"\n 3. Beverages (AED 5)";
       cout<<"\n 4. Fruits (AED 10)";
       cout<<"\n 5. Exit/Continue";
       cout<<"\n Enter your number of choice \t";
       cin>>chf;

       do
        { switch (chf)
             {
                 case 1: strcpy (s.foodtype, "Lunch/Dinner Meal with Beverage");
                         s.foodcost += 30;
                         fsoc.write ((char*)& s, sizeof (s));
                         break;
                 case 2: strcpy (s.foodtype, "Breakfast Meal");
                         s.foodcost += 25;
                         fsoc.write ((char*)& s, sizeof (s));
                         break;
                 case 3: strcpy (s.foodtype, "Beverages");
                         s.foodcost += 5;
                         fsoc.write ((char*)& s, sizeof (s));
                         break;
                 case 4: strcpy (s.foodtype, "Fruits");
                         s.foodcost += 10;
                         fsoc.write ((char*)& s, sizeof (s));
                         break;
             }
        } while (ch<=4);

     s.totalcost += s.foodcost;
     fsoc.write ((char*)& s, sizeof (s));
     cout<<"\n You have successfully donated \t"<<s.foodcost<<"  for \t"<<s.foodtype<<" .";
     cout<<"\n The total cost is \t"<<s.totalcost;
     cout<<"\n Thank you for choosing RAISE YOUR HAND TO HELP SOCIETY (RYHTHS) PROCESSING SYSTEM";
     s.display();
     }
  cout<<"\n 2. Do you wish to donate clothes? (Y OR N)";
  cin>>ch;
  if (ch=='Y')
      {
          int chc;
       cout<<"\n You have chosen to donate food.";
       cout<<"\n Choose type of clothing you wish to donate";
       cout<<"\n 1. Winter Clothing (Full Set)(2 pieces)(AED 70)";
       cout<<"\n 2. Cotton Jumpers (3 pieces) (AED 20)";
       cout<<"\n 3. Children Wear ( 2 pieces) (AED 15)";
       cout<<"\n 4. Undergarments for Men/Women(4 pieces)(AED 15)";
       cout<<"\n 5. Exit/Continue";
       cout<<"\n Enter your number of choice \t";
       cin>>chc;
       do
        { switch (chc)
             {
                 case 1: strcpy (s.clothestype, "Winter Clothing (Full Set)(2 pieces)");
                         s.clothescost += 70;
                         fsoc.write ((char*)& s, sizeof (s));
                         break;
                 case 2: strcpy (s.clothestype, "Cotton Jumpers (3 pieces)");
                         s.clothescost += 20;
                         fsoc.write ((char*)& s, sizeof (s));
                         break;
                 case 3: strcpy (s.clothestype, "Children Wear ( 2 pieces)");
                         s.clothescost += 5;
                         fsoc.write ((char*)& s, sizeof (s));
                         break;
                 case 4: strcpy (s.clothestype, "Undergarments for Men/Women(4 pieces)");
                         s.clothescost += 10;
                         fsoc.write ((char*)& s, sizeof (s));
                         break;
                 case 5: continue;
             }
        } while (ch<=4);
     s.totalcost += s.clothescost;
     fsoc.write ((char*)& s, sizeof (s));
     cout<<"\n You have successfully donated \t"<<s.clothescost<<"  for \t"<<s.clothestype<<" .";
     cout<<"\n The total cost is \t"<<s.totalcost;
     cout<<"\n Thank you for choosing RAISE YOUR HAND TO HELP SOCIETY (RYHTHS) PROCESSING SYSTEM";
     s.display();
      }

  cout<<"\n 3. Do you wish to provide housing facilities? (Y OR N)";
  cin>>ch;
  if (ch == 'Y')
      {
          char name [20], yes;
     int found = 0;
     int cost;
     cout<<"\n You have chosen to contribute towards housing facilities.";
     cout<<"\n Enter amount of money you wish to donate \t";
                     cin>>cost;
                     s.housecost += cost;
                     s.totalcost += s.housecost;
                     fsoc.write ((char*)& s, sizeof (s));

   s.display();
      }
  fsoc.close();
}
  }
}
void Search()
{   fstream fsoc ("Social.dat", ios::in | ios::out);
    service s;
    int regno, found = 0,ch;
    cout<<"\n You have chosen to search for your Social Donation Account";
    cout<<"\n Enter your IDCODE to search for your account \t";
    cin>>regno;
    while (fsoc.read((char*)& s, sizeof(s)))
	     {
		    if(s.getidcode()== regno)
		        { cout<<"\n Your account has been found";
                  s.display();
			      found = 1;
		        }
	     }
	     if (found==1)
			      { cout<<"\n 1. Do you wish to donate food?(Y OR N)";
		          cin>>ch;
                  if(ch=='Y')
                      {
                          int chf;
       cout<<"\n You have chosen to donate food.";
       cout<<"\n Choose type of food package you wish to donate";
       cout<<"\n 1. Lunch/Dinner meal with beverage (AED 30)";
       cout<<"\n 2. Breakfast with beverage (AED 25)";
       cout<<"\n 3. Beverages (AED 5)";
       cout<<"\n 4. Fruits (AED 10)";
       cout<<"\n 5. Exit/Continue";
       cout<<"\n Enter your number of choice \t";
       cin>>chf;

       do
        { switch (chf)
             {
                 case 1: strcpy (s.foodtype, "Lunch/Dinner Meal with Beverage");
                         s.foodcost += 30;
                         fsoc.write ((char*)& s, sizeof (s));
                         break;
                 case 2: strcpy (s.foodtype, "Breakfast Meal");
                         s.foodcost += 25;
                         fsoc.write ((char*)& s, sizeof (s));
                         break;
                 case 3: strcpy (s.foodtype, "Beverages");
                         s.foodcost += 5;
                         fsoc.write ((char*)& s, sizeof (s));
                         break;
                 case 4: strcpy (s.foodtype, "Fruits");
                         s.foodcost += 10;
                         fsoc.write ((char*)& s, sizeof (s));
                         break;
             }
        } while (chf<=4);

     s.totalcost += s.foodcost;
     fsoc.write ((char*)& s, sizeof (s));
     cout<<"\n You have successfully donated \t"<<s.foodcost<<"  for \t"<<s.foodtype<<" .";
     cout<<"\n The total cost is \t"<<s.totalcost;
     cout<<"\n Thank you for choosing RAISE YOUR HAND TO HELP SOCIETY (RYHTHS) PROCESSING SYSTEM";
     s.display();
                      }

                  cout<<"\n 2. Do you wish to donate clothes? (Y OR N)";
                  cin>>ch;
                  if (ch=='Y')
                      {
                          int chc;
       cout<<"\n You have chosen to donate clothes.";
       cout<<"\n Choose type of clothing you wish to donate";
       cout<<"\n 1. Winter Clothing (Full Set)(2 pieces)(AED 70)";
       cout<<"\n 2. Cotton Jumpers (3 pieces) (AED 20)";
       cout<<"\n 3. Children Wear ( 2 pieces) (AED 15)";
       cout<<"\n 4. Undergarments for Men/Women(4 pieces)(AED 15)";
       cout<<"\n 5. Exit/Continue";
       cout<<"\n Enter your number of choice \t";
       cin>>chc;
       do
        { switch (chc)
             {
                 case 1: strcpy (s.clothestype, "Winter Clothing (Full Set)(2 pieces)");
                         s.clothescost += 70;
                         fsoc.write ((char*)& s, sizeof (s));
                         break;
                 case 2: strcpy (s.clothestype, "Cotton Jumpers (3 pieces)");
                         s.clothescost += 20;
                         fsoc.write ((char*)& s, sizeof (s));
                         break;
                 case 3: strcpy (s.clothestype, "Children Wear ( 2 pieces)");
                         s.clothescost += 5;
                         fsoc.write ((char*)& s, sizeof (s));
                         break;
                 case 4: strcpy (s.clothestype, "Undergarments for Men/Women(4 pieces)");
                         s.clothescost += 10;
                         fsoc.write ((char*)& s, sizeof (s));
                         break;
                 case 5: continue;
             }
        } while (chc<=5);
     s.totalcost += s.clothescost;
     fsoc.write ((char*)& s, sizeof (s));
     cout<<"\n You have successfully donated \t"<<s.clothescost<<"  for \t"<<s.clothestype<<" .";
     cout<<"\n The total cost is \t"<<s.totalcost;
     cout<<"\n Thank you for choosing RAISE YOUR HAND TO HELP SOCIETY (RYHTHS) PROCESSING SYSTEM";
     s.display();
                      }

                  cout<<"\n 3. Do you wish to provide housing facilities? (Y OR N)";
                  cin>>ch;
                  if (ch == 'Y')
                      {

     int found = 0;
     int cost;
     cout<<"\n You have chosen to contribute towards housing facilities.";
     cout<<"\n Enter amount of money you wish to donate \t";
                     cin>>cost;
                     s.housecost += cost;
                     s.totalcost += s.housecost;
                     fsoc.write ((char*)& s, sizeof (s));

   s.display();
                      }

			      }
    else
	   {cout<<"\n Your Social Donation account does not exist. Proceeding to create a social account";
	    CREATE();

   fsoc.close();

	   }

	     }

