/**
 * Created by LonelyEnvoy on 2017-3-10.
 * Babelfish
 * Keywords: STL map
 */

// 法一：C风格，效率较高，可读性差。 G++ 2485ms

#include <stdio.h>
#include <string.h>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    char* english = NULL;
    char* foreign = NULL;
    unsigned int englishCharCount = 0;
    unsigned int foreignCharCount = 0;

    char line[11];
    map<string, string> dict;

    // read dict
    const char separator[] = " ";
    while (true) {
        gets(line);
        if (strlen(line) == 0) break;

        english = strtok(line, separator);
        foreign = strtok(NULL, separator);

        // put into dict
        dict.insert(pair<string, string>(string(foreign), string(english)));
    }

    // parse foreign words
    while (scanf("%s", line) != -1) {
        map<string, string>::iterator itr = dict.find(string(line));
        if (itr == dict.end()) {
            printf("eh\n");
        } else {
            printf("%s\n", itr->second.c_str());
        }
    }
    return 0;
}



// 法二：C++风格，效率较低，可读性好。 G++ 2782ms

#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int main() {

    string line;
    string english;
    string foreign;
    int spacePos;
    map<string, string> dict;
    // read dict
    const char separator[] = " ";
    while (true) {
        getline(cin, line);
        if (line.length() == 0) break;
        spacePos = line.find(' ');
        english = line.substr(0, spacePos);
        foreign = line.substr(spacePos + 1);

        // put into dict
        dict.insert(pair<string, string>(foreign, english));
    }

    // parse foreign words
    while (cin >> line) {
        map<string, string>::iterator itr = dict.find(string(line));
        if (itr == dict.end()) {
            cout << "eh" << endl;
        } else {
            cout << itr->second << endl;
        }
    }
}