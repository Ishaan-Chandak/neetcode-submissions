// mathematics problem
// Bob can only win when the difference is a multiple of 9 and we have a minimum amount of '?' available on the side opposite
// For all other cases it is Alice who wins

class Solution {
public:
    bool sumGame(string num) {
        int lc = 0, rc = 0, ls = 0, rs = 0;
        int n = num.size();

        string num1 = num.substr(0, n/2);
        string num2 = num.substr(n/2, n/2);

        for(int i = 0; i <n/2; i++) {
            if(num1[i] != '?') ls += (num1[i] - '0');
            else lc++;
        }

        for(int i = 0; i <n/2; i++) {
            if(num2[i] != '?') rs += (num2[i] - '0');
            else rc++;
        }
        
        return (lc + rc) % 2 == 1 || 2 * (ls - rs) != (rc - lc) * 9;
    }
};
