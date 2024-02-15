#include <iostream>
#include <vector>
#include <fstream>
#include <conio.h>

int findEndBracket(std::string code, int i) {
    while (code[++i]) {
        if (code[i] == ']') 
            return i;
        if (code[i] == '[')
            i = findEndBracket(code, i);
    }
}

int main(int argc, char *argv[]) {

    // retrieving code

    if (argc == 1) {
        std::cout << "Syntax: brainf [-f file_name | -c code]\n"
                     "Existing options:\n"
                     "    -f : takes code from the given file\n"
                     "    -c : takes code from the argument";
        return -1;
    }
    std::string code;
    if (argv[1] == (std::string)"-f") {
        if (argv[2] == NULL) {
            std::cout << "'file_name' Argument Is Empty";
            return -1;
        }
        std::string text;
        std::ifstream file(argv[2]);
        if (!file) {
            std::cout << "Could Not Able To Open File";
            return -1;
        }
        while (getline(file, text))
            code += text;
        file.close();
    } else if (argv[1] == (std::string)"-c") {
        if (argv[2] == NULL) {
            std::cout << "'code' Argument Is Empty";
            return -1;
        }
        code = argv[2];
    } else {
        std::cout << "'" << argv[1] << "' Option Does Not Exist";
        return -1;
    }

    // the interpreter

    std::vector<int> memo = {0};
    int ptr = 0;
    std::vector<int> loops;
    for (int i = 0; i < code.length(); i++) {
        switch (code[i]) {
            case '+':
                memo[ptr] = (memo[ptr] + 1) % 256;
                break;
            case '-':
                memo[ptr] = (memo[ptr] + 255) % 256;
                break;
            case '>':
                if (++ptr == memo.size())
                    memo.push_back(0);
                break;
            case '<':
                if (--ptr < 0) {
                    memo.insert(memo.begin(), 0);
                    ptr++;
                }
                break;
            case '[':
                loops.push_back(i);
                if (memo[ptr] != 0) 
                    break;
                i = findEndBracket(code, i);
            case ']':
                if (memo[ptr] != 0)
                    i = loops.back() - 1;
                loops.pop_back();
                break;
            case '.':
                std::cout << (char)memo[ptr];
                break;
            case ',':
                char input = getch();
                memo[ptr] = (int)input;
                break;
        }
    }
}