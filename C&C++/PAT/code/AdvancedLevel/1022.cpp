#include <bits/stdc++.h>

using namespace std;

struct book {
    string id;
    string title;
    string author;
    vector<string> keywords;
    string publisher;
    string year;
};


int main() {
    map<string, vector<int>> keyMap; // {keyword:书籍下标}
    map<string, vector<int>> publisherMap;
    map<string, vector<int>> authorMap;
    map<string, vector<int>> titleMap;
    map<string, vector<int>> yearMap;

    string str;
    getline(cin, str);
    int n = stoi(str);
    vector<book> books(n);
    for (int i = 0; i < n; ++i) {
        getline(cin, books[i].id);
        getline(cin, books[i].title);
        getline(cin, books[i].author);
        getline(cin, str);
        stringstream input(str);    // 读取str到字符串流中
        string keyword;
        while (getline(input, keyword, ' ')) {
            books[i].keywords.push_back(keyword);
            keyMap[keyword].push_back(i);
        }
        getline(cin, books[i].publisher);
        getline(cin, books[i].year);

        publisherMap[books[i].publisher].push_back(i);
        authorMap[books[i].author].push_back(i);
        titleMap[books[i].title].push_back(i);
        yearMap[books[i].year].push_back(i);
    }

    getline(cin, str);
    int m = stoi(str);
    for (int i = 0; i < m; ++i) {
        getline(cin, str);
        cout << str << endl;
        string t = str.substr(3);;
        vector<int> index;
        switch (str[0]) {
            case '1':
                if (titleMap.find(t) != titleMap.end())
                    index = titleMap[t];
                break;
            case '2':
                if (authorMap.find(t) != authorMap.end())
                    index = authorMap[t];
                break;
            case '3':
                if (keyMap.find(t) != keyMap.end())
                    index = keyMap[t];
                break;
            case '4':
                if (publisherMap.find(t) != publisherMap.end())
                    index = publisherMap[t];
                break;
            case '5':
                if (yearMap.find(t) != yearMap.end())
                    index = yearMap[t];
                break;
        }
        int len = index.size();
        if (len == 0)
            cout << "Not Found" << endl;
        else {
            vector<string> ans;
            for (int j = 0; j < len; ++j)
                ans.push_back(books[index[j]].id);
            sort(ans.begin(), ans.end());
            for (int j = 0; j < len; ++j)
                cout << ans[j] << endl;
        }
    }
}