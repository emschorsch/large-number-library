#include <iostream>
#include <string>
#include "largeNum.h"
#include "largeNum2.h"

using namespace std;

int main(){
  LargeNum test1;
  LargeNum2 test3;
  LargeNum2 test2(100);
  test2.print();
  test3.set(99);
  test3.print();
  LargeNum2 test4 = test3.sum(test3, test2);
  test4.print();
  int* num1;
  int* num2;
  int* prod;
  int size,size1,size2,sum=0;
  num2=test1.toArray(1,size2);
  cout<<size2<<" "<<num2<<endl;
  prod = test1.toArray(1,size2);
  size=1;
  size1=1;
  for(int i=1;i<6;i++){
    size2=size;
    num1=test1.toArray(i,size1);
    prod = test1.multiply(size2,size1,prod,num1,size);
  }
  for(int i=0;i<size;i++){
    sum+=prod[i];
    cout<<prod[i];
   }
  cout<<endl;
  delete [] num1;
  delete [] num2;
  delete [] prod;
  return 0;
}
