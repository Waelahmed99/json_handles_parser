#include <bits/stdc++.h>

#define NAMES "/home/wael/CLionProjects/codeforces_handles/names.txt"
#define HANDLES "/home/wael/CLionProjects/codeforces_handles/handles.txt"
#define OUTPUT "/home/wael/CLionProjects/codeforces_handles/handles.json"

using namespace std;

vector<string> readData(const string& fileName) {
    ifstream file(fileName);
    string line;
    vector<string> result;
    if (file.is_open()) {
        while (getline(file, line))
            result.push_back(line);
    }
    file.close();
    return result;
}

int main() {
    vector<string> names = readData(NAMES);
    vector<string> handles = readData(HANDLES);

    if (names.empty() || handles.empty())
        return cout << "No input data!", 0;
    if (names.size() != handles.size())
        return cout << "Handles and names lengths do NOT match!", 0;

    string json = "[\n";
    for (int i = 0; i < min(names.size(), handles.size()); i++)
        json += "\t{\n\t\"name\": \"" + names[i] + "\",\n" + "\t\"handle\": \"" + handles[i] + "\"\n\t},\n";

    json.pop_back();
    json.pop_back();
    json += "\n]";
    ofstream file(OUTPUT);
    file << json;
    cout << "Done | Data has been parsed to: " << OUTPUT << endl;
    return 0;
}
