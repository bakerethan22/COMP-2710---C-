//Ethan Baker
//ezb0061@auburn.edu
//project2_Baker_ezb0061.cpp
//
//lines 22-39 used to define variables for user input
//lines 45-78 initializes test cases for use later
//lines 87-173 creates both strategy 1 and strategy 2.
//lines 174-185 creates the main method.
//lines 190-325 used for creating how each person shoots.
//lines 329-401 used for test cases 
//
//Used stackoverflow.com for how to use stdlib.h, assert.h, ctime, cstdlib as well
// as how to implement test cases and use a continue feature.
//
//Compilation instructions: Use "g++ project2_Baker_ezb0061.cpp" to compile code
//Run instructions: Use "./a.out" to execute code


# include <iostream>
# include <stdlib.h>
# include <assert.h>
# include <ctime>
# include <cstdlib>
using namespace std;

const int AaronAcc = 33;
const int BobAcc = 50;
const int TOTAL_RUNS = 10000;
const string Duels = "/10000";
int aWins1;
int aWins2;
int bWins1;
int bWins2;
int cWins1;
int cWins2;
int num2;
int num1;
bool AliveA;
bool AliveB;
bool AliveC;
bool True = true;
bool False = false;
string target;


/* at_least_two_alive() function prototype */
bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive);
    

/* Aaron_shoots1() function prototype */
void Aaron_shoots1(bool & B_alive, bool & C_alive);
  
    
/* Bob_shoots() function prototype */
void Bob_shoots(bool & A_alive, bool & C_alive);
   

/* Charlie_shoots() function prototype */   
void Charlie_shoots(bool & A_alive, bool & B_alive);
  
/* Aaron_shoots2() function prototype */    
void Aaron_shoots2(bool & B_alive, bool & C_alive);
   

// TEST METHOD PROTOTYPES
void test_at_least_two_alive(void);
/* This is a test driver for at_least_two_alive() */

void test_Aaron_shoots1(void);
/* This is a test driver for Aaron_shoots() */

void test_Bob_shoots(void);
/* This is a test driver for Bob_shoots() */

void test_Charlie_shoots(void);
/* This is a test driver for Charlie_shoots() */

void test_Aaron_shoots2(void);
/* This is a test driver for Aaron_shoots2() */

/* Function for the continue key */
void continueKey() {
   cout << "Press any key to continue...";
   cin.ignore().get(); //Pause Command for Linux Terminal
}

/* Strategy 1 */
void strategy1() {
   cout << "Ready to test strategy 1 (run " << TOTAL_RUNS << " times):" << endl;
   continueKey();

   for (int i = 0; i < TOTAL_RUNS; i++) {
      AliveA = AliveB = AliveC = true;
      do {
         if (AliveA) {
            Aaron_shoots1(AliveB, AliveC);
         }
         if (AliveB) {
            Bob_shoots(AliveA, AliveC);
         }
         if (AliveC) {
            Charlie_shoots(AliveA, AliveB);
         }
      } while (at_least_two_alive(AliveA, AliveB, AliveC));
      if (AliveA) {
         aWins1 += 1;
      }
      if (AliveB) {
         bWins1 += 1;
      }
      if (AliveC) {
         cWins1 += 1;
      }
      cout << "\n";
   }
   double percentA = aWins1 * 0.01;
   double percentB = bWins1 * 0.01;
   double percentC = cWins1 * 0.01;
   cout << "Aaron won " << aWins1 << Duels << " duels or " << percentA << "%";
   cout << "\nBob won " << bWins1 << Duels << " duels or " << percentB << "%";
   cout << "\nCharlie won " << cWins1 << Duels << " duels or " << percentC << "%";
}

/* Strategy 2 */
void strategy2() {
   cout << "\n\nReady to test strategy 2 (run " << TOTAL_RUNS << " times):" << endl;
   continueKey();

   for (int i = 0; i < TOTAL_RUNS; i++) {
      AliveA = AliveB = AliveC = true;
      do {
         if (AliveA) {
            Aaron_shoots2(AliveB, AliveC);
         }
         if (AliveB) {
            Bob_shoots(AliveA, AliveC);
         }
         if (AliveC) {
            Charlie_shoots(AliveA, AliveB);
         }
      } while (at_least_two_alive(AliveA, AliveB, AliveC));
      if (AliveA) {
         aWins2 += 1;
      }
      if (AliveB) {
         bWins2 += 1;
      }
      if (AliveC) {
         cWins2 += 1;
      }
      cout << "\n";
   }
   double percentA = aWins2 * 0.01;
   double percentB = bWins2 * 0.01;
   double percentC = cWins2 * 0.01;
   cout << "Aaron won " << aWins2 << Duels << " duels or " << percentA << "%";
   cout << "\nBob won " << bWins2 << Duels << " duels or " << percentB << "%";
   cout << "\nCharlie won " << cWins2 << Duels << " duels or " << percentC << "%";

   if (aWins2 > aWins1) {
      num2 = 2;
      num1 = 1;
   }
   else if (aWins2 == aWins1) {
      cout << "\n\nStrategy 2 is equal to strategy 1." << endl;
      return;
   }
   else {
      num2 = 1;
      num1 = 2;
   }
   cout << "\n\nStrategy " << num2 << " is better than strategy " << num1 << "." << endl;
}

// MAIN METHOD
int main() {
   srand(time(0));
   cout << "*** Welcome to Duel Simulator ***" << endl;
   test_at_least_two_alive();
   test_Aaron_shoots1();
   test_Bob_shoots();
   test_Charlie_shoots();
   test_Aaron_shoots2();
   strategy1();
   strategy2();
}

// FUNCTION
/* Function of at_least_two_alive() */
bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive) {
   int count = 0;

   if (A_alive) {
      count++;
   }
   if (B_alive) {
      count++;
   }
   if (C_alive) {
      count++;
   }

   if (count > 1) {
      return true;
   }
   else {
      return false;
   }
}

/* Function of Aaron_shoots1() */
void Aaron_shoots1(bool & B_alive, bool & C_alive) {
   AliveB = B_alive;
   AliveC = C_alive;
   int randomNumb = rand()%100;

   if (AliveC) {
      cout << "\n\t\t\t\t\t\tAaron is shooting at Charlie";
      target = "Charlie";
   }
   else {
      cout << "\n\t\t\t\t\t\tAaron is shooting at Bob";
      target = "Bob";
   }

   if (randomNumb <= AaronAcc) {
      cout << "\n\t\t\t\t\t\t" << target << " is dead.\n";
      if (target == "Charlie") {
         AliveC = false;
         return;
      }
      else {
         AliveB = false;
         return;
      }
   }
   else {
      cout << "\n\t\t\t\t\t\tAaron misses.\n";
      return;
   }
}

/* Function of Bob_shoots() */
void Bob_shoots(bool & A_alive, bool & C_alive) {
   AliveA = A_alive;
   AliveC = C_alive;
   int randomNumb = rand()%100;

   if (AliveC) {
      cout << "\n\t\t\t\t\t\tBob is shooting at Charlie";
      target = "Charlie";
   }
   else {
      cout << "\n\t\t\t\t\t\tBob is shooting at Aaron";
      target = "Aaron";
   }

   if (randomNumb <= BobAcc) {
      cout << "\n\t\t\t\t\t\t" << target << " is dead.\n";
      if (target == "Charlie") {
         AliveC = false;
      }
      else {
         AliveA = false;
      }
   }
   else {
      cout << "\n\t\t\t\t\t\tBob misses.\n";
   }
}

/* Function of Charlie_shoots() */
void Charlie_shoots(bool & A_alive, bool & B_alive) {
   AliveA = A_alive;
   AliveB = B_alive;

   if (AliveB) {
      cout << "\n\t\t\t\t\t\tCharlie is shooting at Bob";
      AliveB = false;
      target = "Bob";
   }
   else {
      cout << "\n\t\t\t\t\t\tCharlie is shooting at Aaron";
      AliveA = false;
      target = "Aaron";
   }
   cout << "\n\t\t\t\t\t\t" << target << " is dead.\n";
}

/* Function of Aaron_shoots2() */
void Aaron_shoots2(bool & B_alive, bool & C_alive) {
   AliveB = B_alive;
   AliveC = C_alive;
   int randomNumb = rand()%100;

   if ((AliveB == true) && (AliveC == true)) {
      cout << "\n\t\t\t\t\t\tAaron intentionally misses his first shot" << endl;
      cout << "\t\t\t\t\t\tBoth Bob and Charlie are alive." << endl;
      return;
   }

   if (AliveC) {
      cout << "\n\t\t\t\t\t\tAaron is shooting at Charlie";
      target = "Charlie";
   }
   else {
      cout << "\n\t\t\t\t\t\tAaron is shooting at Bob";
      target = "Bob";
   }

   if (randomNumb <= AaronAcc) {
      cout << "\n\t\t\t\t\t\t" << target << " is dead.\n";
      if (target == "Charlie") {
         AliveC = false;
         return;
      }
      else {
         AliveB = false;
         return;
      }
   }
   else {
      cout << "\n\t\t\t\t\t\tAaron misses.\n";
      return;
   }
}

// TEST FUNCTIONS
/* Test driver for at_least_two_alive() */
void test_at_least_two_alive(void) {
   cout << "Unit Testing 1: Function - at_least_two_alive()\n";
   cout << "\t\t\tCase 1: Aaron alive, Bob alive, Charlie alive\n";
   assert(true == at_least_two_alive(true, true, true));
   cout << "\t\t\tCase passed ...\n";
   cout << "\t\t\tCase 2: Aaron dead, Bob alive, Charlie alive\n";
   assert(true == at_least_two_alive(false, true, true));
   cout << "\t\t\tCase passed ...\n";
   cout << "\t\t\tCase 3: Aaron alive, Bob dead, Charlie alive\n";
   assert(true == at_least_two_alive(true, false, true));
   cout << "\t\t\tCase passed ...\n";
   cout << "\t\t\tCase 4: Aaron alive, Bob alive, Charlie dead\n";
   assert(true == at_least_two_alive(true, true, false));
   cout << "\t\t\tCase passed ...\n";
   cout << "\t\t\tCase 5: Aaron dead, Bob dead, Charlie alive\n";
   assert(false == at_least_two_alive(false, false, true));
   cout << "\t\t\tCase passed ...\n";
   cout << "\t\t\tCase 6: Aaron dead, Bob alive, Charlie dead\n";
   assert(false == at_least_two_alive(false, true, false));
   cout << "\t\t\tCase passed ...\n";
   cout << "\t\t\tCase 7: Aaron alive, Bob dead, Charlie dead\n";
   assert(false == at_least_two_alive(true, false, false));
   cout << "\t\t\tCase passed ...\n";
   cout << "\t\t\tCase 8: Aaron dead, Bob dead, Charlie dead\n";
   assert(false == at_least_two_alive(false, false, false));
   cout << "\t\t\tCase passed ...\n";
   continueKey();
}

/* Test driver for Aaron_shoots1() */
void test_Aaron_shoots1(void) {
   cout << "Unit Testing 2: Function Aaron_shoots1(Bob_alive, Charlie_alive)\n";
   cout << "\t\t\tCase 1: Bob alive, Charlie alive";
   Aaron_shoots1(True, True);
   cout << "\t\t\tCase 2: Bob dead, Charlie alive";
   Aaron_shoots1(False, True);
   cout << "\t\t\tCase 3: Bob alive, Charlie dead";
   Aaron_shoots1(True, False);
   continueKey();
}

/* Test driver for Bob_shoots() */
void test_Bob_shoots(void) {
   cout << "Unit Testing 3: Function Bob_shoots(Aaron_alive, Charlie_alive)\n";
   cout << "\t\t\tCase 1: Aaron alive, Charlie alive";
   Bob_shoots(True, True);
   cout << "\t\t\tCase 2: Aaron dead, Charlie alive";
   Bob_shoots(False, True);
   cout << "\t\t\tCase 3: Aaron alive, Charlie dead";
   Bob_shoots(True, False);
   continueKey();
}

/* Test driver for Charlie_shoots() */
void test_Charlie_shoots(void) {
   cout << "Unit Testing 4: Function Charlie_shoots(Aaron_alive, Bob_alive)\n";
   cout << "\t\t\tCase 1: Aaron alive, Bob alive";
   Charlie_shoots(True, True);
   cout << "\t\t\tCase 2: Aaron dead, Bob alive";
   Charlie_shoots(False, True);
   cout << "\t\t\tCase 3: Aaron alive, Bob dead";
   Charlie_shoots(True, False);
   continueKey();
}

/* Test driver for Aaron_shoots2() */
void test_Aaron_shoots2(void) {
   cout << "Unit Testing 5: Function Aaron_shoots2(Bob_alive, Charlie_alive)\n";
   cout << "\t\t\tCase 1: Bob alive, Charlie alive";
   Aaron_shoots2(True, True);
   cout << "\t\t\tCase 2: Bob dead, Charlie alive";
   Aaron_shoots2(False, True);
   cout << "\t\t\tCase 3: Bob alive, Charlie dead";
   Aaron_shoots2(True, False);
   continueKey();
}