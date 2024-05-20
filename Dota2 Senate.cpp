#include <string>
#include <queue>

class Solution {
public:
    std::string predictPartyVictory(std::string senate) {
        std::queue<int> radiantQueue, direQueue;
        int n = senate.size();
        
    
        for (int i = 0; i < n; ++i) {
            if (senate[i] == 'R') {
                radiantQueue.push(i);
            } else {
                direQueue.push(i);
            }
        }
        
        
        while (!radiantQueue.empty() && !direQueue.empty()) {
            int rIndex = radiantQueue.front();
            int dIndex = direQueue.front();
            radiantQueue.pop();
            direQueue.pop();
            
            
            if (rIndex < dIndex) {
                radiantQueue.push(rIndex + n);
            } else {
                direQueue.push(dIndex + n);
            }
        }
        
        
        return radiantQueue.empty() ? "Dire" : "Radiant";
    }
};
