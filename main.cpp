#include<iostream>
#include <vector>

using namespace std;

vector<char> MakeCharVector() {
    vector<char> charVec;
    charVec.push_back('0');
    charVec.push_back('1');
    charVec.push_back('2');
    charVec.push_back('3');
    charVec.push_back('4');
    charVec.push_back('5');
    charVec.push_back('6');
    charVec.push_back('7');
    charVec.push_back('8');
    charVec.push_back('9');
    charVec.push_back('a');
    charVec.push_back('A');
    charVec.push_back('b');
    charVec.push_back('B');
    charVec.push_back('c');
    charVec.push_back('C');
    charVec.push_back('d');
    charVec.push_back('D');
    charVec.push_back('e');
    charVec.push_back('E');
    charVec.push_back('f');
    charVec.push_back('F');
    charVec.push_back('g');
    charVec.push_back('G');
    charVec.push_back('h');
    charVec.push_back('H');
    charVec.push_back('i');
    charVec.push_back('I');
    charVec.push_back('j');
    charVec.push_back('J');
    charVec.push_back('k');
    charVec.push_back('K');
    charVec.push_back('l');
    charVec.push_back('L');
    charVec.push_back('m');
    charVec.push_back('M');
    charVec.push_back('n');
    charVec.push_back('N');
    charVec.push_back('o');
    charVec.push_back('O');
    charVec.push_back('p');
    charVec.push_back('P');
    charVec.push_back('q');
    charVec.push_back('Q');
    charVec.push_back('r');
    charVec.push_back('R');
    charVec.push_back('s');
    charVec.push_back('S');
    charVec.push_back('t');
    charVec.push_back('T');
    charVec.push_back('u');
    charVec.push_back('U');
    charVec.push_back('v');
    charVec.push_back('V');
    charVec.push_back('w');
    charVec.push_back('W');
    charVec.push_back('x');
    charVec.push_back('X');
    charVec.push_back('y');
    charVec.push_back('Y');
    charVec.push_back('z');
    charVec.push_back('Z');
    charVec.push_back('`');
    charVec.push_back('~');
    charVec.push_back('!');
    charVec.push_back('@');
    charVec.push_back('#');
    charVec.push_back('$');
    charVec.push_back('%');
    charVec.push_back('^');
    charVec.push_back('&');
    charVec.push_back('*');
    charVec.push_back('(');
    charVec.push_back(')');
    charVec.push_back('-');
    charVec.push_back('_');
    charVec.push_back('+');
    charVec.push_back('=');
    charVec.push_back('[');
    charVec.push_back('{');
    charVec.push_back(']');
    charVec.push_back('}');
    charVec.push_back('|');
    charVec.push_back('\\');
    charVec.push_back(';');
    charVec.push_back(':');
    charVec.push_back('"');
    charVec.push_back('\'');
    charVec.push_back('<');
    charVec.push_back(',');
    charVec.push_back('.');
    charVec.push_back('>');
    charVec.push_back('?');
    charVec.push_back('/');
    return charVec;
}

int countNum = 0;
int fileNum = 0;

void ForeachPass(vector<char> charVec, vector<char> &subVec, int num) {
    num -= 1;
    for (int i = 0; i < charVec.size(); ++i) {
        subVec.push_back(charVec[i]);
        if (num == 0) {
            for (char j : subVec) {
                putchar(j);
            }
            putchar('\n');
            subVec.pop_back();
            countNum += 1;
            if (countNum == 50000000) {
                countNum = 0;
                fileNum += 1;
                string fileName = "dic" + to_string(fileNum) + ".txt";
                freopen(fileName.c_str(), "w", stdout);
            }
            continue;
        }
        ForeachPass(charVec, subVec, num);
        subVec.pop_back();
    }
}

int main() {
    vector<char> charVec = MakeCharVector();

    int miniNum, maxNum;
    cout << "输入最小生成长度" << endl;
    cin >> miniNum;
    cout << "输入最大生成长度" << endl;
    cin >> maxNum;

    //输出定向，全排列会自动保存在dic.txt中
    string fileName = "dic" + to_string(fileNum) + ".txt";
    freopen(fileName.c_str(), "w", stdout);
    for (int i = miniNum; i <= maxNum; ++i) {
        vector<char> subVec;
        ForeachPass(charVec, subVec, i);
    }

}