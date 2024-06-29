// Do NOT add any other includes
#include <string> 
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

class TrieNode
{
    public:
    bool endOfWord=false;
    vector<TrieNode*> children;
    long long count = 0;
    char key;
    ~TrieNode()
    {
        int m = children.size();
        for(int i=0;i<m;i++)
        {
            delete children[i];
        }
    }

    long long find(char ch)
    {
        int n = children.size();
        for(long long i=0;i<n;i++)
        {
            if (ch==children[i]->key)
            {
                return i;
            }
        }
        return -1;
    }
};

class Dict {
private:
    // You can add attributes/helper functions here
    TrieNode* root;

public: 

    void insertintrie(string word);
    int bk;
    int pag;
    int par;

    /* Please do not touch the attributes and 
    functions within the guard lines placed below  */
    /* ------------------------------------------- */
    Dict();

    ~Dict();

    void insert_sentence(int book_code, int page, int paragraph, int sentence_no, string sentence);

    long long get_word_count(string word);

    void dump_dictionary(string filename);

    /* -----------------------------------------*/
};