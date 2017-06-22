//
//  main.cpp
//  Dice
//
//  Created by WORK on 21/06/2017.
//  Copyright © 2017 eecs281. All rights reserved.
//

#include <iostream>
#include <unordered_map>
#include <vector>
#include <numeric>

//each dice is the same
using namespace std;

int findWays(int M, int N, int S);
//void recSum(size_t currentDice, size_t diceLimit,unordered_map<int, int>& sumFrequency, vector<int>& dices, int M);
int main() {
    cout << "Enter the dimension of the map" << endl;
    
    double size;
    cin >> size;
    double sum = 0;
    
    vector<vector<double>> map(size, vector<double>(size));
    
    for(int row = 0; row < size; ++row)
    {
        for(int col = 0; col < size; ++col)
        {
            if(row != 0 || col != 0)
            {
                if(col == 0)
                    map[row][col] = 1;
                else if(row == 0)
                    map[row][col] = 1;
                else
                {
                    map[row][col] = map[row][col] = map[row - 1][col] + map[row][col - 1];
                }
                sum += map[row][col];
            }
            
        }
    }
    
    
    cout << map[size - 1][size - 1] << endl;
    cout << sum << endl;
    cout << map[size - 1][size - 1] / sum << endl;
}

int findWays(int M, int N, int S){
    //base case check
    
    if(S > M*N || S < N){
        return 0;
    }else if(S == N || S == M*N){
        return 1;
    }
    vector<vector<int>> sumFrequency(N+1, vector<int>(S+1, 0));
    //first dice
    for (size_t i = 1; i <= S && i <= M; i++)
        sumFrequency[1][i] = 1;
    
    for (size_t i = 2; i <= N; i++){
        //all the other dices
        for (size_t j = 1; j <= S; j++){
            for (size_t k = 1; k <= M && k < j; k++){
                //recurr relations
                sumFrequency[i][j] = sumFrequency[i][j] + sumFrequency[i-1][j-k];
            }
        }
    }
    return sumFrequency[N][S];
}





//void recSum(size_t currentDice, size_t diceLimit,unordered_map<int, int>& sumFrequency, vector<int>& dices, int M){
//    if(diceLimit == dices.size()){
//        return;
//    }else if(currentDice > diceLimit){
//        int sum = std::accumulate(dices.begin(), dices.end(), 0);
//        currentDice = 0;
//        diceLimit ++;
//        auto it = sumFrequency.find(sum);
//        if(it != sumFrequency.end()){
//            //if sum does exist
//            it->second += 1;
//        }else{
//            sumFrequency.insert({sum, 1});
//        }
//        for(size_t i = 0; i < diceLimit; ++i){
//            //reset all the previous dices
//            dices[i] = 1;
//        }
//        diceLimit += 1;
//        currentDice = 0;
//        recSum(currentDice, diceLimit, sumFrequency, dices, M);
//    }else if(dices[currentDice] > M){
//        for(size_t i = 0; i < currentDice; ++i){
//            //reset all the previous dices
//            dices[i] = 1;
//        }
//        currentDice++;
//        //increment
//        dices[currentDice]++;
//        
//        
//    }
//}
