#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;


struct HNode {
    char ch;
    int freq;
    HNode *left, *right;

    HNode(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
};


struct CompareFreq {
    bool operator()(HNode* a, HNode* b) {
        return a->freq > b->freq; 
    }
};


void makeCodes(HNode* root, const string &code, unordered_map<char,string>& codes) {
    if (!root) return;

   
    if (!root->left && !root->right) {
        codes[root->ch] = code;
    }

    makeCodes(root->left, code + "0", codes);
    makeCodes(root->right, code + "1", codes);
}

int main() {
    string text;
    cout << "Enter the string to encode: ";
    getline(cin, text);

    if (text.empty()) {
        cout << "No text entered.\n";
        return 0;
    }

   
    unordered_map<char,int> freq;
    for (char c : text) freq[c]++;


    priority_queue<HNode*, vector<HNode*>, CompareFreq> pq;
    for (auto &p : freq) {
        pq.push(new HNode(p.first, p.second));
    }

    while (pq.size() > 1) {
        HNode* left = pq.top(); pq.pop();
        HNode* right = pq.top(); pq.pop();

        HNode* parent = new HNode('\0', left->freq + right->freq);
        parent->left = left;
        parent->right = right;
        pq.push(parent);
    }

    HNode* root = pq.top();

    unordered_map<char,string> codes;
    makeCodes(root, "", codes);

   
    cout << "\nHuffman Codes:\n";
    for (auto &p : codes) {
        cout << "'" << p.first << "' : " << p.second << "\n";
    }

    
    string encoded;
    for (char c : text) encoded += codes[c];

    cout << "\nEncoded string:\n" << encoded << "\n";

    return 0;
}
