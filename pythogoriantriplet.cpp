

#include <bits/stdc++.h>
using namespace std;
int square (int);
int
square (int n)
{
  return n * n;
}

int
main ()
{
  vector < int >v
  {
  3, 1, 4, 6, 5};
  transform (v.begin (), v.end (), v.begin (), square);
  sort (v.begin (), v.end ());
  for (int i = 0; i < v.size (); i++)
    {
      int j = v.size () - 1;
      int k = v.size () - 2;
      while (i < k)
	{
	  if (v[i] == v[j] - v[k])
	    {
	      cout << sqrt (v[i]) << " " << sqrt (v[k]) << " " << sqrt (v[j]);
	      j--;
	      k++;
	    }
	  else if (v[i] > v[j] - v[k])
	    k--;
	  else
	    j--;
	}
    }
  return 0;
}
