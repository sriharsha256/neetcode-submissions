class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int tankGas=0,tankcost=0,tank=0,idx=0;
        int n = gas.size();
        for(int i=0;i<n;i++)
        {
            tankGas += gas[i];
            tankcost += cost[i];
            tank += gas[i] - cost[i];
            if(tank<0)
            {
                idx = i+1;
                tank=0;
            }
        }
        if(tankGas < tankcost) return -1;
        return idx;
    }
};
