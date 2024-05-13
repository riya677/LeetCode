#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> freqMap; 
        int operations = 0;
        
        
        for (int num : nums) {
            freqMap[num]++;
        }
        
        
        for (int num : nums) {
            int complement = k - num; 
            if (freqMap.find(num) != freqMap.end() && freqMap.find(complement) != freqMap.end()) {
                
                if (num == complement) {
                    operations += freqMap[num] / 2; 
                } else {
                    operations += min(freqMap[num], freqMap[complement]); 
                }
                freqMap.erase(num); 
                freqMap.erase(complement);
            }
        }
        
        return operations;
    }
};
