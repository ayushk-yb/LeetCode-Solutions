class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());
        int n = deck.size();
        queue<int> revealQueue;
        vector<int> reveal(n);
        for(int i = 0; i < n; i++)
        {
            revealQueue.push(i);
        }

        for(int i = 0; i < n; i++)
        {
            int currIdx = revealQueue.front();
            revealQueue.pop();
            int backIdx = revealQueue.front();
            revealQueue.pop();
            revealQueue.push(backIdx);
            reveal[currIdx] = deck[i];
        }

        return reveal;
    }
};