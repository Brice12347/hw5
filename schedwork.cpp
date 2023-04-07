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
    DailySchedule& sched,unsigned int row ,unsigned int col, vector<int>& temp);


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
		vector<int> temp(avail[0].size());
		for(unsigned int i = 0; i < avail.size(); i++){//dailyNeed
			sched.push_back(vector<Worker_T>());
			for(unsigned int j = 0; j < dailyNeed; j++){//avail[0].size()
				sched[i].push_back(-1);
			}
			
		}

    // Add your code below
    //im thinking a map of user to how many days used.
    
    return help(avail, dailyNeed, maxShifts, sched, 0,0,temp);




}
bool help(const AvailabilityMatrix& avail,
    size_t dailyNeed,
    size_t maxShifts,
    DailySchedule& sched, unsigned int row , unsigned int col,vector<int>& temp){
        //iterate through columns
        if(col == dailyNeed){
            col = 0;
						row++;
						// if(col == maxShifts){
						// 	row++;
						// }else {
						// 	return false;
						// }
            
        }
					// r ./schedwork_tests --gtest_filter=Schedule.Nominal1
					// b schedwork.cpp: 59
        if(row == avail.size()){
            return true;
						//for every worker
        }
				//cout << "sched[0].size(): " << sched[0].size() << endl;
				for(unsigned int i = 0; i < avail[0].size();++i ){
					
					if(avail[row][i]){
						if(temp[i] >= maxShifts){

						}
						else{
							if(find(sched[row].begin(), sched[row].end(), i) != sched[row].end()){//find(sched[row].begin(), sched[row].end(), i) == sched[row].end()
								continue;
							}
							sched[row][col] = i;
							temp[i]++;
							if(help(avail,dailyNeed,maxShifts,sched,row, col+1,temp)){
								return true;
							}
							else{
								sched[row][col] = -1;
								temp[i]--;
							}
						}
					}
					else{
						continue;
					}
				}

			return false;

}
// else if(avail[row][col]){
//             for(unsigned int i = 0; i < sched.size();++i ){
//                 sched[row][col] = i;
//                 temp[i]++;
//                 //worker can't work on the same day twice... thats the second condition
//                 if(temp[i] <= maxShifts){
//                     if(help(avail,dailyNeed,maxShifts,sched,row, col+1,temp)){
//                         return true;
//                     }
//                 }
//                 sched[row][col] = INVALID_ID;
// 								temp[i]--;
//             }
//             return false;
// 				}else{
//             return help(avail,dailyNeed,maxShifts,sched,row, col+1,temp);
//         }     



// for(unsigned int i = 0; i < sched[0].size();++i ){
// 					if(temp[i] == NULL){
// 						temp[i] == 0;
// 					}
// 					if(avail[row][col]){
// 						if(temp[i] < maxShifts){
// 							sched[row][col] = i;
//               temp[i]++;
// 							if(sched[row].size() == dailyNeed){
// 								if(help(avail,dailyNeed,maxShifts,sched,row, col+1,temp)){
//                   return true;
//                 }else{
// 									sched[row][col] = INVALID_ID;
//  									temp[i]--;
// 								}
// 							}
// 						}
// 					}
// 				}