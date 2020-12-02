#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
  ifstream inputObject1("input.txt");

  string input1;
  string input2;
  string input3;
  
  int splitter1=0;
  int max=0;
  int min=0;

  char choice;

  int count=0; //how many times has the character appeard
  int valid=0; //amount of valid passwords

  bool isValid=false;

  //Part 1
  while(inputObject1>>input1>>input2>>input3)
  {
    count=0; //resets count

    //Finds minimum and maximum number of occurances
    splitter1 = input1.find("-");
    min=stoi(input1.substr(0, splitter1)); //find minimum number
    max=stoi(input1.substr(splitter1+1,input1.size()-splitter1+1)); //find maximum number

    //Get's character choice
    choice = input2[0];

    //Counts how many time the character has appeard
    for(int i=0; i<input3.size(); ++i)
    {
      if(input3[i]==choice) //finds the number of appearances
      {
        ++count;
      }
    }

    if(count<=max && count>=min)
    {
      ++valid;
    }
  }
  inputObject1.close();
  cout << valid << endl;

  //Part 2
  valid=0;
  inputObject1.open("input.txt");
  while(inputObject1>>input1>>input2>>input3)
  {
    isValid=false;
    //Finds 2 occurance positions
    splitter1 = input1.find("-");
    min=stoi(input1.substr(0, splitter1)); //finds first position
    max=stoi(input1.substr(splitter1+1,input1.size()-splitter1+1)); //find second position

    //Get's character choice
    choice = input2[0];

    //Check if character is at only 1 position
    if(min-1<input3.size() && max-1<input3.size() && input3[min-1]==choice && input3[max-1]!=choice)
    {
      isValid=true;
    }
    else if(min-1<input3.size() && max-1<input3.size() && input3[min-1]!=choice && input3[max-1]==choice)
    {
      isValid=true;
    }

    if(isValid)
    {
      ++valid;
    }
  }
  inputObject1.close();  
  cout << valid << endl;

  return 0;
}
