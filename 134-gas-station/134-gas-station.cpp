class Solution {
public://greedily choose best start poimn for the trip
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
       int start=0;
        int n =gas.size();
        int total =0;
        int current=0;
        for(int i =0; i< n ;i++){
            total+=gas[i]-cost[i];
            current+=gas[i]-cost[i];
            if(current<0){current=0;
            start=i+1;}
         }
        return total>=0?start:-1;
    }
};