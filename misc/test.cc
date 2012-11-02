#include <iostream>
#include <string>
#include "largeNum.h"

using namespace std;

int main(){
  LargeNum test1;
  int* num1;
  int* num2;
  int* prod;
  int size,size1,size2,sum;
  num2=test1.toArray(1,size2);
  prod = test1.toArray(1,size2);
  size=1;
  size1=1;
  for(int i=1;i<101;i++){
    size2=size;
    num1=test1.toArray(i,size1);
    prod = test1.multiply(size2,size1,prod,num1,size);
  }
  for(int i=0;i<size;i++){
    sum+=prod[i];
    //cout<<prod[i];
   }
  cout<<sum;
  cout<<endl;
  delete [] num1;
  delete [] num2;
  delete [] prod;
  return 0;
}
