int evaluateExpression(const string& s) {
    int result = s[0] - '0';  // first operand
    
    for (int i = 1; i < s.size(); i += 2) {
        char op = s[i];
        int nextOperand = s[i + 1] - '0';
        
        if (op == 'A') {
            result = result & nextOperand;  // AND
        } else if (op == 'B') {
            result = result | nextOperand;  // OR
        } else if (op == 'C') {
            result = result ^ nextOperand;  // XOR
        }
    }
    
    return result;
}
