/*This program is prepared by Ayush Mistri (22CS041)
                              Triparna Kar (22CS029)
                              Dev Patel    (22CS052)    */

#include <iostream>
#include <iomanip>
#include <math.h>
#include<cstring>

using namespace std;

class Home_loan   //creating a class to calculate home loan interest
{
    private:     //Declaring data members as private
    string Author_Name;
    float EMI, INT, Rate, Rate_per_month, Loan_amount, Balance=0;
    float Total_INT=0, Principle_amt=0, xyz;
    int year,months;

    public:     //Declaring and Defining member fuction in public access mode
    void getdata()      //creating getdata() fuction to input data
    {
        cout<<"Enter a Author name : ";
        getline(cin,Author_Name);
        cout<<"Enter a amount of Loan : ";
        cin>>Loan_amount;
        xyz=Loan_amount;        //Assigning Loan_amount in another member xyz for later use
        cout<<"Enter a Rate of interest : ";
        cin>>Rate;
        cout<<"Enter a Tenure in years : ";
        cin>>year;
    }

    void title()        //Function to print the title of calculator
    {
        cout<<endl;
        cout<<"\t\t***********************************************************************************"<<endl;
        cout<<"\t\t\t\t\t   HOME LOAN INTEREST CALCULATOR\t\t"<<endl;
        cout<<"\t\t***********************************************************************************\n"<<endl;
    }

    void putdata()      //Creating function to print the inputted data
    {
        cout<<"\n";     //Inserting a new line in output
        cout<<"Author Name : "<<Author_Name<<endl;
        cout<<"Total Amount of Loan : "<<Loan_amount<<endl;
        cout<<"Rate of interest : "<<Rate<<endl;
        cout<<"Tenure in month : "<<year<<endl;
    }
    
    void Loan_calculation()   //Fuction for calculation and print monthly amounts and interests
    {
        cout<<"\n";
        cout<<"Months\t\tLoan Amount\t\tEMI\t\tINT\t\tPrinciple_amt\t\tBalance\n\n";
        for(int i=1 ; i<=(year*12) ; i++)       //outer loop for iterating months
        {
            cout<<setw(16)<<left<<i;       //Using setw and left manipulator for Output
            for(int j=0 ; j<1 ; j++)    //inner loop for calculating monthly amounts 
            {
                if(Balance!=0)
                {
                    Loan_amount=Balance;
                }
                cout<<fixed<<setprecision(3)<<setw(24)<<left<<Loan_amount;
                if(i==1)
                {
                    EMI = cal_EMI();    //Assinging the returned value of fuction in EMI only once
                                        //EMI is constant in program
                }
                cout<<setw(16)<<left<<EMI;
                
                INT=Loan_amount*(Rate/(12*100));      //monthly interest calculation
                cout<<setw(16)<<left<<INT;

                Principle_amt=EMI-INT;      //calculation for monthly principle Amount
                cout<<setw(16)<<left<<Principle_amt;

                Balance=Loan_amount-Principle_amt;      //Remaining balance amount
                if(Balance<0){
                    cout<<"0.000"<<endl;  //Final balance amount
                }
                else{
                    cout<<setw(20)<<left<<Balance<<endl;    //Monthly balance remaining
                }
                Total_INT = Total_INT + INT;    //Total interest amount on loan
           }
        }
        cout<<"\nTotal amount of Interest : "<<Total_INT<<endl;
        cout<<"Total amount paied by User : "<<xyz+Total_INT<<endl; 
    }
    float cal_EMI()     //Function to calculate the EMI
    {
        Rate_per_month=Rate/(12*100);
        months=year*12;
        EMI=(Loan_amount*Rate_per_month*pow(Rate_per_month+1,months)/(pow(1+Rate_per_month,months)-1));
                        //Formula to calculate EMI
        return EMI;
    }

};

int main(){
    Home_loan h1;   //Creating object of class Home_loan
    h1.title();     //calling the respective member fuctions through object
    h1.getdata();
    h1.putdata();
    h1.Loan_calculation();
    
    return 0;
}
