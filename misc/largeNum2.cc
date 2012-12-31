#include <iostream>
#include <sstream>
#include <string>
#include <math.h>
#include "largeNum2.h"

using namespace std;

LargeNum2::LargeNum2(){
	size=0;
	num = toArray( 0, size );
}

LargeNum2::LargeNum2( int initNum ){
	size=0;
	num = toArray( initNum, size );
}

LargeNum2::LargeNum2( int* num1, int size1 ){
	size = size1;
	num = num1;
}

LargeNum2::~LargeNum2(){ 
}

//This methods prints out the number
void LargeNum2::print(){
  for( int i =0; i < size; i++){
    cout<<num[i];
  }
  cout<<endl;
}

void LargeNum2::set( int value ){
	num = toArray( value, size );
}

//This method takes an int and stores it in an array form
int* LargeNum2::toArray(int num, int& size){
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
LargeNum2 LargeNum2::sum(LargeNum2 number1, LargeNum2 number2){
  int remain=0; 
  int size1 = number1.size;
  int size2 = number2.size;
  int* num1 = number1.num;
  int* num2 = number2.num;
  int j=max(size1, size2)+1;//size of sum array
  int* sum = new int[j];//might have one extra 0 before real num
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
  if( sum[0] == -1 )
	  j--;
  LargeNum2 sumA( sum, j );

  return sumA;
}

//precondition: size1 is greater than size2
//Handles the multiplication of large numbers
int* LargeNum2::multiply(int size1,int size2,int* num1,int* num2,int& size){
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
