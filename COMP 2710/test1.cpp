#include <iostream>
#include <ctime>
using namespace std;

void moveDisk(int n, char Original, char Aux, char Dest)
{
   if(n == 0)
      return;
   int count;
   moveDisk(n-1, Original, Dest, Aux);
   cout <<"Move Disk " << n << " from " << Original << " to " << Dest << endl;
   moveDisk(n-1, Aux, Original, Dest);
}

int main() {
   int n;
   time_t start, end;
   cout << "Enter the number of disks:";
   cin >> n;
   time(&start);
   moveDisk(n , 'A', 'B', 'C');
   time(&end);
	
   double elapse = difftime (end, start);
   cout << "The elapsed time is " << elapse << " seconds" << " for moving "<< n << " disks" << endl;
   return 0;
}