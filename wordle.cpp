#ifndef RECCHECK
// For debugging
#include <iostream>
// For std::remove
#include <algorithm> 
#include <map>
#include <set>
#include <vector>
#include <deque>
#endif

#include "wordle.h"
#include "dict-eng.h"
using namespace std;


// Add prototypes of helper functions here
set<string> helper(unsigned int index,deque<char>& temp,set<string>& answer, std::string& in,
    const std::string& floating,
    const std::set<std::string>& dict);

// Definition of primary wordle function
std::set<std::string> wordle(
    const std::string& in,
    const std::string& floating,
    const std::set<std::string>& dict)
{
    // Add your code here
   deque<char> temp;
	 int counter = 0;
	 int asterisks = 0;
    for(int i = 0;i < floating.size(); i++){
        temp.push_back(floating[i]);
    }
		for(int i = 0; i < in.length(); i++){
			if(in[i] != '-'){
				counter++;
			}
		}
		asterisks = in.length()-floating.length()-counter;
		for(int i = 0;i < asterisks; i++){
        temp.push_back('*');
    }

    
    
    string in2 = in;
    set<string> answer;
    set<string> result = helper(0, temp,answer, in2, floating, dict);
    return result;
}

// Define any helper functions here
set<string> helper(unsigned int index,deque<char>& temp,set<string>& answer, std::string& in,
    const std::string& floating,
    const std::set<std::string>& dict)
{  
   if(index == in.size()){
        if(dict.find(in) != dict.end() && temp.empty()){
            answer.insert(in);
        }
    }else{
        if(in[index] != '-'){
            helper(index+1,temp,answer, in, floating,dict);
			}else{
                for(unsigned int i = 0; i<temp.size(); i++){
                    char frontTemp = temp.front();
                    if(frontTemp == '*'){
                        temp.pop_front();
                        for(char j = 'a'; j<='z'; j++){
                            in[index] =  j;
                             helper(index+1,temp,answer, in, floating,dict);
                             in[index] = '-';
                        }
							temp.push_back('*');
                    }else{
                        in[index] = frontTemp;
                        temp.pop_front();
                        helper(index+1,temp,answer,in, floating,dict);
                        temp.push_back(frontTemp);
                        in[index] = '-';
                    }
                }
			}
    }
    
    
   return answer;
    

}

//if the index that we are is at the end of the word
    //see if the word that is created is in the dictionary
//else
    //if the index is fixed letter recursive in the next index
    //else count how m
        //if the number of dashes we have is greater than or equal to floating size plus count from earlier
            //loop through the floating indexes and replace with flaoting indexes and add to a set of characters that we have already used
                //loop through all possinle letters a-z and replace with that index and recurse


    //for(int i = index; index < deque.size(); i++){
        //frontTemp = deque.front()
        //if(frontTemp = '*'){a-z}
        //else{helper(deque, index, in, floating dict);}
//      pop_front.deque
        //helper(deque, index, in, floating dict);
        //pushback(frontTemp).deque
        //helper(deque, index, in, floating dict);
    //}