#pragma once
#include <iostream>
#include <fstream>
#include "Node.h"
#include "dict.h"
#include "search.h"

using namespace std;

class Diction {
private:
    TrieNode* root;

public: 

    void insertintrie(string word);
    int bk;
    int pag;
    int par;

    Diction();
    ~Diction();

    void insert_sentence(int book_code, int page, int paragraph, int sentence_no, string sentence);

    long long get_word_count(string word);
};

class QNA_tool {

private:

    // You are free to change the implementation of this function
    void query_llm(string filename, Node* root, int k, string API_KEY, string question);
    // filename is the python file which will call ChatGPT API
    // root is the head of the linked list of paragraphs
    // k is the number of paragraphs (or the number of nodes in linked list)
    // API_KEY is the API key for ChatGPT
    // question is the question asked by the user

    // You can add attributes/helper functions here
    Dict dic;
    vector<Dict*> made;
    vector<Diction*> made2;
    long long size = 0;
    double scorer(string word);
    double get_para_score(string query, Dict* gg, vector<pair<string,double>> keyword);
    Node* result;
    long long num_boo = 98;
    void insert_sentence_2(int book_code, int page, int paragraph, int sentence_no, string sentence);
    long long siz = 0;
    double get_para_score_2(string query, Diction* gg, vector<pair<string,double>> keyword);
    Node* get_top_k_para_2(string question, int k);
    double scorer3(string myword);
    Node* get_top_k_para_3(string question, int k);
    double get_para_score_3(string query, Diction* gg, vector<pair<string,double>> keyword, vector<pair<string,double>> queeryy);
    double scorer2(string myword);

public:

    /* Please do not touch the attributes and
    functions within the guard lines placed below  */
    /* ------------------------------------------- */
    
    QNA_tool(); // Constructor
    ~QNA_tool(); // Destructor

    void insert_sentence(int book_code, int page, int paragraph, int sentence_no, string sentence);
    // This function is similar to the functions in dict and search 
    // The corpus will be provided to you via this function
    // It will be called for each sentence in the corpus

    Node* get_top_k_para(string question, int k);
    // This function takes in a question, preprocess it
    // And returns a list of paragraphs which contain the question
    // In each Node, you must set: book_code, page, paragraph (other parameters won't be checked)

    std::string get_paragraph(int book_code, int page, int paragraph);
    // Given the book_code, page number, and the paragraph number, returns the string paragraph.
    // Searches through the corpus.

    void query(string question, string filename);
    // This function takes in a question and a filename.
    // It should write the final answer to the specified filename.

    /* -----------------------------------------*/
    /* Please do not touch the code above this line */

    // You can add attributes/helper functions here
};

