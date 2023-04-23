#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

class Home_loan{
    public:
    string Author_Name;
    float EMI, INT, Rate, Rate_per_month, Loan_amount, Balance=0;
    float Total_INT=0, Princ=0, xyz;
    int year,months;
    void getdata(){
        cout<<"Enter a Author name : ";
        cin>>Author_Name;
        cout<<"Enter a amount of Loan : ";
        cin>>Loan_amount;
        xyz=Loan_amount;
        cout<<"Enter a Rate for Loan : ";
        cin>>Rate;
        cout<<"Enter a Tenure in year : ";
        cin>>year;
    }
    void putdata(){
        cout<<endl;
        cout<<"\t\t***********************************************************************************"<<endl;
        cout<<"\t\t\t\t\t   HOME LOAN INTEREST CALCULATOR\t\t"<<endl;
        cout<<"\t\t***********************************************************************************\n"<<endl;
    }
    void putdata_1(){
        cout<<"\n";
        cout<<"Author Name is : "<<Author_Name<<endl;
        cout<<"Total Amount of Loan is : "<<Loan_amount<<endl;
        cout<<"Rate for Loan is : "<<Rate<<endl;
        cout<<"Tenure in month is : "<<year<<endl;
    }
    // xyz=Loan_amount;
    void putdata_2(){
        cout<<"\n";
        cout<<"Months\t\tLoan Amount\t\tEMI\t\tINT\t\tPrinc\t\tBalance\n\n";
        for(int i=1 ; i<=(year*12) ; i++){
            cout<<setw(16)<<left<<i;
            for(int j=0 ; j<1 ; j++){
                if(Balance!=0){
                    Loan_amount=Balance;
                }
                cout<<fixed<<setprecision(3)<<setw(24)<<left<<Loan_amount;
                if(i==1){
                    EMI = cal_EMI();
                }
                cout<<setw(16)<<left<<EMI;
                INT=Loan_amount*(Rate/(12*100));
                cout<<setw(16)<<left<<INT;
                Princ=EMI-INT;
                cout<<setw(16)<<left<<Princ;
                Balance=Loan_amount-Princ;
                if(Balance<0){
                    cout<<"0.000"<<endl;
                }
                else{
                    cout<<setw(20)<<left<<Balance<<endl;
                }
                Total_INT = Total_INT + INT;
           }
        }
        cout<<"\nTotal amount of Interest is : "<<Total_INT<<endl;
        cout<<"Total amount paied by User is : "<<xyz+Total_INT<<endl;
    }
    float cal_EMI(){
        Rate_per_month=Rate/(12*100);
        months=year*12;
        EMI=(Loan_amount*Rate_per_month*pow(Rate_per_month+1,months)/(pow(1+Rate_per_month,months)-1));
        return EMI;
    }

};

int main(){
    Home_loan h1;
    h1.putdata();
    h1.getdata();
    h1.putdata_1();
    h1.putdata_2();
    
    return 0;
}
