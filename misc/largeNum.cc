#include <iostream>
#include <sstream>
#include <string>
#include <math.h>
#include "largeNum.h"

using namespace std;

LargeNum::LargeNum(){
}

LargeNum::~LargeNum(){ 
}

//This method takes an int and stores it in an array form
int* LargeNum::toArray(int num, int& size){
 string result;
 stringstream ss;
 ss << num;
 result = ss.str();
 size=result.length();
 int* num4 = new int[size];
 int nums;
 for(int i=0; i<size;i++){
 nums=result[i]-'0';
 num4[i]=nums;
 }
 return num4;
}

//Implements adding two large numbers
int* LargeNum::sum(int size1, int size2,int* num1, int* num2, int& size){
  int remain=0; 
  int j=max(size1,size2)+1;//size of sum array
  int* sum = new int[j];//might have one extra 0 before real num
  size=j;//changes value of size in callee function
  sum[0]=0;
  int k=0;
  if(size1>size2){
   for(int i=size2; i>0;i--){
     k=size1-(size2-i);
     remain=num1[k-1]+num2[i-1];
     if(remain>9){
       remain=remain-10;
       num1[k-2]++;
     }
     sum[k+1-1]=remain;
    }
   for(int i=size1-size2;i>0;i--){
     sum[i+1-1]=num1[i-1];
   }
  }
  else{
   for(int i=size1; i>0;i--){
     k=size2-(size1-i);
     remain=num1[i-1]+num2[k-1];
     if(remain>9){
       remain=remain-10;
       if(size1==size2&&i==1){
         sum[0]++;
       }
       else{
        num2[k-2]++;
       }
     }
     sum[k]=remain;
   }
   for(int i=size2-size1;i>0;i--){
     sum[i]=num2[i-1];
   }
  }

  return sum;
}

//precondition: size1 is greater than size2
//Handles the multiplication of large numbers
int* LargeNum::multiply(int size1,int size2,int* num1,int* num2,int& size){
  size=size1+size2;
  int* res = new int[size];
  int remain=0;
  int remain2=0;
  int k=size2;
  for(int i=0;i<size;i++){
    res[i]=0;
  }

  //the actual multiplication, no carrying occurs
  while(k>0){
    for(int i=size1;i>0;i--){
      remain=num1[i-1]*num2[k-1]+remain2;
      remain2=(int)(remain/10);
      if(i!=1){
        remain=remain%10;
      }
      res[size-(size1-i)-1-(size2-k)]+=remain;
    }
    remain2=0;
    k--;
  }

  remain=0;
  remain2=0;
  //Carries over so each bucket has an int less than 10
  for(int i=size;i>0;i--){
    remain=res[i-1]+remain2;
    remain2=(int)(remain/10);
    remain=remain%10;
    res[i-1]=remain;
  }

  return res;
}
