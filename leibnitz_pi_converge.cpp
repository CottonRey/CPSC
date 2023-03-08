#include <iostream>
#include <cmath>
#include <cfloat>
#include <iomanip>

using namespace std;

int main()
{
  float piOver4 = 0.0;
  float pi;
  int n = 2;

  cout << fixed;
  cout << setprecision(DBL_DIG);

  while (n <= 1048576){
    piOver4 = 0;
    pi = 0;
    for (int k = 0; k <= n; k++){
      piOver4 += ((pow(-1.0,k)) / ((2.0*k) + 1.0));
    }
    pi = piOver4 * 4;
    cout << "PI: " << pi << "; n: " << n << endl;
    n = n * 2;
  }
}
