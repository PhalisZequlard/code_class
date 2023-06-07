#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

class score {
    friend ifstream& operator>>(ifstream& in, score& b);
    friend ofstream& operator<<(ofstream& out, const score& b);
    int n;
    string* name;
    string* id;
    float* value;
  public:
    score(int a = 47) {
        n = a;
        name = new string[n];
        id = new string[n];
        value = new float[n];
    }

    ~score() {
        delete[] name;
        delete[] id;
        delete[] value;
    }
};

ifstream& operator>>(ifstream& in, score& b) {
    if (in.is_open()) {
        string str;
        int i = 0;
        while (getline(in, str)) {
            istringstream stream(str);
            string s;
            getline(stream, s, ',');
            b.name[i] = s;
            getline(stream, s, ',');
            b.id[i] = s;
            getline(stream, s, ',');
            b.value[i] = stof(s);
            i++;
        }
    } else {
        cout << "Fail to open file" << endl;
    }
    return in;
}

ofstream& operator<<(ofstream& out, const score& b) {
    if (b.n > 0) {
        out << "姓名\t學號\t成績" << endl;
        for (int i = 0; i < b.n; i++) {
            cout << b.name[i] << "\t" << b.id[i] << "\t" << b.value[i] << endl;
        }
    }
    return out;
}

int main() {
    score csie_2_a;
    ifstream myFile("stu.txt");
    myFile >> csie_2_a;
    myFile.close();
    ofstream outFile("output.txt");
    outFile << csie_2_a;
    outFile.close();

    return 0;
}