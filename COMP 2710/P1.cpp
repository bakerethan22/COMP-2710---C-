//Ethan Baker
//ezb0061@auburn.edu
//project1_Baker_ezb0061.cpp
//
//lines 14-16 used to define variables for user input
//line 23-34 used to 
//
//Used geeksforgeeks.com for how to use cout, cin, precision as well
// as how to implement for and while loops
//
//Compilation instructions: Use "g++ project1_Baker_ezb0061.cpp" to compile code
//Run instructions: Use "./a.out" to execute code
	
	
#include <iomanip>
#include <ios>
#include <iostream>
using namespace std;
	
int main() 
{
   double loan, rate, payment;
   double monthly_rate, interest, principal, total_interest;
   int month;
   bool valid = false;
   bool valid_loan = false;
   bool valid_rate = false;
   bool valid_payment = false;
   

   //checks if all inputs are valid. If not, then reinput
   while (!valid) {
      while (!valid_loan){
         cout << "Loan Amount: ";
         cin >> loan;
         if (loan >= 0) {
            valid_loan = true;
         }
      }
   
      while (!valid_rate) {
         cout << "Interest Rate (% per year): ";
         cin >> rate;
         if (rate >= 0) {
            valid_rate = true;
         }
      }
   
      while (!valid_payment) {
         cout << "Monthly Payments: ";
         cin >> payment;
         if (payment >= 0) {
            valid_payment = true;
         }
      }
      if (payment > loan * rate / 12 / 100) {
         valid = true;
      }
      else {
         valid_loan = false;
         valid_rate = false;
         valid_payment = false;
      }
      cout << endl;
   }
   //round the outputs to two decimal places
   cout.setf(ios::fixed); 
   cout.setf(ios::showpoint); 
   cout.precision(2); 
   
   //sets up table
   cout << "********************************************************\n"
         << "\tAmortization Table\n"
         << "********************************************************\n"
         << "Month" << "\t"
         << "Balance" << "\t"
         << "Payment" << "\t"
         << "Rate" << "\t"
         << "Interest" << "\t"
         << "Principal" << endl;
        
   monthly_rate = rate / 12;
   month = 0;
   interest = 0;
   principal = 0;
   total_interest = 0;
   
   while (loan >= payment) {
      //first month without payment
      if (month == 0) {
         cout << month++  << "\t"
               << "$" << loan << "\t"
               << "N/A" << "\t"
               << "N/A" << "\t"
               << "N/A" << "\t"
               << "N/A" << endl;
      }
         //every month after first month
      else {
         interest = loan * (monthly_rate / 100);
         principal = payment - interest;
         loan = loan - principal;
         total_interest = total_interest + interest;
         
         cout << month++ << "\t"
               << "$" << loan << "\t"
               << "$" << payment << "\t"
               << monthly_rate << "\t"
               << "$" << interest << "\t"
               << "$" << principal << endl;
             
      }
   }
   
   //calculating the final monthly installment
   interest = loan * (monthly_rate / 100);
   payment = loan + interest;
   principal = loan;
   total_interest = total_interest + interest;
   loan = 0;
   
   if (loan < payment) {
      loan = 0;
      cout << month++ << "\t"
               << "$" << loan << "\t"
               << "$" << payment << "\t"
               << monthly_rate << "\t"
               << "$" << interest << "\t"
               << "$" << principal << endl;
   }
   cout << "********************************************************" << endl;
   
   //Gives summary of payments
   cout << "It takes " << (month - 1) << " months to pay off the loan." << endl;
   cout << "Total interest paid is: " << "$" << total_interest << endl;
}