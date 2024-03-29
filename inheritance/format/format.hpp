#ifndef CS2_WP_
#define CS2_WP_

#include <fstream>
#include <iostream>

class wordProccessor {
public:
    wordProccessor () : width(20) {};
    void selectFormatingOption() {
        format *txt;
        txt = new LeftJustify(width);
        txt->output();
        delete txt;
        std::cout << "----------------" << std::endl;
    }

private:
    int width;
};

class format {
public:
    format (int w): width(w) {};
    virtual ~format() {};
    void output() {
        std::string line, word;
        std::ifstream inFile("quote.txt");
        inFile >> word;
        line = word;
        while (inFile >> word) {  //done on eof()
            if ((line.length() + word.length() + 1) > width) {
                justify(line);
                line = word;
            } else {
                line = line + " " + word;
            }
        }

        justify(line);
        line = "";

        inFile.close();

    };

protected:
    unsigned int width;

private:
    virtual void justify(const std::string&) = 0; //Algo
};

class LeftJustify: public format {
public:
    LeftJustify(int w): format(w) {};

private:
    virtual void justify(const std::string& line) {
        std::cout << line << std::endl;
    };

};

class RightJustify: public format {
public:
    RightJustify(int w): format(w) {};

private:
    virtual void justify(const std::string& line) {
        for (unsigned int i = 0; i < width-line.length(); ++i) 
            std::cout << " " << line << std::endl;
    };

};

class CenterJustify: public format {
public:
    CenterJustify(int w): format(w) {};

private:
    virtual void justify(const std::string& line) {
        std::cout << line << std::endl;
    };

};


#endif