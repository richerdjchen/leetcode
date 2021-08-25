class Solution {
public:
    void parseComplex(string s, int &a, int &b) {
        int idx = s.find("+");
        a = stoi(s.substr(0, idx), nullptr, 10);
        b = stoi(s.substr(idx + 1, s.size()-1), nullptr, 10);
    }
    string complexNumberMultiply(string num1, string num2) {
        int a, b, c, d;     // a,b holds values for num1 | c,d for num2
        parseComplex(num1, a, b);
        parseComplex(num2, c, d);
        
        string p1 = to_string(a*c + b*d*-1);
        string p2 = to_string(a*d + b*c);
        return p1 + "+" + p2 + "i";
    }
};