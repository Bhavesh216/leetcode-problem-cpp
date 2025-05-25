string reverseWords(string str) {
    stringstream ss(str);
    string word, result;
    
    while (ss >> word) {
        reverse(word.begin(), word.end());  // Reverse the word
        result += word + " ";
    }
    
    if (!result.empty()) {
        result.pop_back();  // Remove the trailing space
    }

    return result;
}
//string input = "hello world from chatgpt";
//"olleh dlrow morf tpgtahc"
