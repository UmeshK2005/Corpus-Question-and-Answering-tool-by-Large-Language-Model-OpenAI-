// Do NOT add any other includes
#include "dict.h"

char separators[] = {' ', '.', ',', '-', ':', '!', 39, 34, '(', ')', '?', '[', ']', ';', '@'};

bool issep(char c) {
    for (char ch:separators) {
        if (ch == c) {
            return true;
        }
    }
    return false;
}


Dict::Dict(){
    // Implement your function here    
    root = new TrieNode();
}


Dict::~Dict(){
    delete root;
}

void Dict::insertintrie(string word) {
    TrieNode* node=root;
    for(auto ch : word)
    {
        if (node->find(ch)==-1)
        {
            TrieNode* new_node=new TrieNode();
            new_node->key=ch;
            node->children.push_back(new_node);
        }
        node=node->children[node->find(ch)];
    }
    node->endOfWord=true;
    node->count++;
}

void Dict::insert_sentence(int book_code, int page, int paragraph, int sentence_no, string sentence){
    // Implement your function here  
    string word;
    for (char c:sentence) {
        if (issep(c)) {
            if (!word.empty()) {
                insertintrie(word);
                word.clear();
            }
        }
        else {
            word += tolower(c);
        }
    }
   
    if (!word.empty()) {
        insertintrie(word);
    }
    return;
}

long long Dict::get_word_count(string word) {
    TrieNode* node=root;
    for(auto ch : word)
    {
        int flag = node->find(ch);
        if(flag==-1)
        {
            return 0;
        }
        node=node->children[flag];
    }
    return node->count;
}

