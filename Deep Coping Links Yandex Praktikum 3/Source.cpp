#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

/*Посмотрите на код, разбивающий текст на слова с учётом стоп-слов. Избавьтесь от лишних копирований в заголовках функций и в циклах for. 
Для этого используйте ссылки в нужных местах кода. 
Тип string замените на string&, set<string> — на set<string>&.
Формат входных и выходных данных
На вход подаются две строки. В первой строке — стоп-слова через пробел. Во второй строке — поисковый запрос. 
Программа должна вывести каждое слово запроса внутри фигурных скобок, по одному слову в строке. Слова из множества стоп-слов выводиться не должны.*/

vector<string> SplitIntoWords(string& text) {
    vector<string> words;
    string word;
    for (char c : text) {
        if (c == ' ') {
            if (!word.empty()) {
                words.push_back(word);
                word.clear();
            }
        }
        else {
            word += c;
        }
    }
    if (!word.empty()) {
        words.push_back(word);
    }
    return words;
}

set<string> ParseStopWords(string& text) {
    set<string> stop_words;
    for (string& word : SplitIntoWords(text)) {
        stop_words.insert(word);
    }
    return stop_words;
}

vector<string> ParseQuery(string& text, set<string>& stop_words) {
    vector<string> words;
    for (string& word : SplitIntoWords(text)) {
        if (stop_words.count(word) == 0) {
            words.push_back(word);
        }
    }
    return words;
}

int main() {
    // Read stop words
    string stop_words_joined;
    getline(cin, stop_words_joined);
    set<string> stop_words = ParseStopWords(stop_words_joined);

    // Read query
    string query;
    getline(cin, query);
    vector<string> query_words = ParseQuery(query, stop_words);

    for (string& word : query_words) {
        cout << '[' << word << ']' << endl;
    }
}
