#include <iostream>
#include <vector>
#include "list.h"
#include "node.h"

using namespace std;

int main()
{
    setlocale(LC_ALL,"rus");
    list<int> a = list<int>();
    a.append(1);
    a.append(2);
    a.append(3);
    a.append(4);
}