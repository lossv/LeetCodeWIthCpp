//
// Created by lossv on 2021/10/20.
//

#include <iostream>
#include <string>


using namespace std;


class WordDictionary {
public:

    WordDictionary() {

    }

    void addWord(const string &word) {

    }

    bool search(const string &word) {
        return true;
    }
};


int main() {
    WordDictionary wordDictionary = WordDictionary();
    wordDictionary.addWord("bad");
    wordDictionary.addWord("dad");
    wordDictionary.addWord("mad");
    wordDictionary.search("pad"); // return False
    wordDictionary.search("bad"); // return True
    wordDictionary.search(".ad"); // return True
    wordDictionary.search("b.."); // return True


    return 0;
}