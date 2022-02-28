#include "NumberList.h"
void main()
{
    NumberList n;
    n.Init();
    n.Add(3); 
    n.Add(2);
    n.Add(1); 
    n.Add(5); 
    n.Add(6); 
    n.Add(8); 
    n.Add(7);
    n.Print();
    n.Sort();
    n.Print(); //print dupa sort
}