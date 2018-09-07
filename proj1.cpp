#include<iostream>

#include <math.h> 

using namespace std;

bool isPerfectSquare(long double x)
{  
    //cout << "Sum to be evaluated is " << x <<endl;
  // Find floating point value of 
  // square root of x.
  long double sr = sqrt(x);
  // If square root is an integer/Users/noopurrkalawatia/Documents/c++_programs/proj1.cpp
  return ((sr - floor(sr)) == 0);
}

long double compute_sum(int lower_bound, int times)
{
  long double sum = 0;
  int count = 1;
  do
  {
      sum = sum + (lower_bound * lower_bound);
      ++lower_bound;
      ++count;
      //cout << "Sum is " << sum << endl;
  }while(count <= times);
  return sum;
}
 
int main(void) 
{
  int N,k,count = 1;
  cin >> N ;
  cin >> k;
  long double sum = 0;

  //k are the numbers to be considered together to evaluate the sum.
  //N is the final number upto which the checking can be done.

  for(int i = 1; i <= N ; ++i)
  {
      do
      {
          int j = i;
          //recursive function to compute the sum.
          //for the sum we will pass two arguments, 
          //lower and upper bound
          sum = compute_sum (i,k);

          if (isPerfectSquare(sum))
          {
              cout << "Result : " << j << endl;
              break;
          }
          sum = 0;
          ++count;
          //cout << "count :" << count << endl;
      }while (count <= k);
      count = 0;
  }
  return 0;
}
