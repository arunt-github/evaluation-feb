#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>
#include <sstream>
#include <cstdlib>
#include <cmath>
#include <numeric>
#include <cctype>
#include <cstring>
#include <algorithm>

using namespace std;

string norm_word(string word)
{
    if (islower(word))
    {
        return ("---num---");
    }
    else
    {
        return transform(word.begin(), word.end(), word.begin(), ::tolower);
    }
}

unordered_map<string, vector<float>> read_lexicon()
{
    unordered_map<string, vector<float>> lexiconVec;
    ifstream lexicon("./lexicons/ppdb-xl.txt");
    string lex;
    while (getline(lexicon, lex))
    {
    }
    cout << lex << endl;
    lexicon.close();
    return lexiconVec;
}

void retro_fit()
{
}

void print_word_vecs()
{
}

unordered_map<string, vector<float>> read_word_vecs()
{
    unordered_map<string, vector<float>> wordVectors;

    ifstream sample_vec("sample_vec.txt");
    string sample, word;
    while (getline(sample_vec, sample))
    {
        int pos = sample.find(" ");
        word = sample.substr(0, pos);
        cout << word << endl;
        int num_words = 0;
        int lenOfSentence = sample.size();
        for (int i = 0; i < lenOfSentence; i++)
        {
            if (sample[i] == ' ')
            {
                num_words++;
            }
        }

        vector<float> v;
        for (int i = 0; i < num_words; i++)
            v.push_back(0);
        wordVectors[word] = v;

        stringstream ss(sample);
        string vecVal;
        int i = 0;
        while (ss >> vecVal && i < 48)
        {
            float val = stof(vecVal);
            wordVectors[word][i] = val;
            i++;
        }
    }

    float sum = accumulate(wordVectors[word].begin(), wordVectors[word].end(), 0);
    float valud = (sqrt(pow(sum, 2) + 1e-6));
    for (int i = 0; i < 48; i++)
    {
        wordVectors[word][i] = wordVectors[word][i] / valud;
    };
    return wordVectors;
}

int main()
{

    unordered_map<string, vector<float>> wordVecs;
    unordered_map<string, vector<float>> lexicon;

    ofstream output("out_vec.txt");
    int numIter = 10;
    // if (!sample_vec.is_open() or !lexicon.is_open())
    // {
    //     cerr << "Error opening the file!";
    //     return 1;
    // }
    wordVecs = read_word_vecs();
    lexicon = read_lexicon();
    return 0;
}