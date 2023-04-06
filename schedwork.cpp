#ifndef RECCHECK
#include <set>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#endif

// add or remove necessary headers as you please
#include "schedwork.h"

using namespace std;

// a constant that can be used to indicate an INVALID 
// worker ID if that is useful to your implementation.
// Feel free to not use or delete.
static const Worker_T INVALID_ID = (unsigned int)-1;


// Add prototypes for any helper functions here
bool help(const AvailabilityMatrix& avail,
    size_t dailyNeed,
    size_t maxShifts,
    DailySchedule& sched, int row , int col, map<int,int>);

// bool Sudoku::solveHelper(int row, int col) {
//   // TODO: IMPLEMENT THIS
//   if(col == 9){
//     col = 0;
//     row++;
//   }

//   if(row == 9){
//     return true;
//   }
//   else if(board[row][col] == 0){
//     for(int value = 1; value < 10; ++value){
//       board[row][col] = value;
//      if(isValid(row,col)){ 
//        if(solveHelper(row,col+1)){
//          return true;
//        }
//      }
//      board[row][col] = 0;
//     }
//        return false;
//   } else {
//     return solveHelper(row,col+1);
//   }
// } 

// Add your implementation of schedule() and other helper functions here

bool schedule(
    const AvailabilityMatrix& avail,
    const size_t dailyNeed,
    const size_t maxShifts,
    DailySchedule& sched
)
{
    if(avail.size() == 0U){
        return false;
    }
    sched.clear();
    // Add your code below
    //im thinking a map of user to how many days used.
    map<int , int> temp;
    help(avail, dailyNeed, maxShifts, sched, 0,0,temp);




}
bool help(const AvailabilityMatrix& avail,
    size_t dailyNeed,
    size_t maxShifts,
    DailySchedule& sched, int row , int col,map <int, int> temp){
        //iterate through columns
        if(col == dailyNeed){
            col = 0;
            row++;
        }
        if(row = avail[0].size()){
            return true;
        }else if(avail[row][col] == 1){
            for(int i = 0; i < avail.size()-1;++i ){
                sched[row][col] = i;
                temp[i]++;
                //worker can't work on the same day twice... thats the second condition
                if(temp[i] < maxShifts){
                    if(help(avail,dailyNeed,maxShifts,sched,row, col+1,temp)){
                        return true;
                    }
                }
                sched[row][col] = INVALID_ID;
            }
            return false;
        }else{
            return help(avail,dailyNeed,maxShifts,sched,row, col+1,temp);
        }     

}
