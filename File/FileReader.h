#ifndef CPP1_ASSESSMENT_FILEREADER_H
#define CPP1_ASSESSMENT_FILEREADER_H

#include <fstream>

class FileReader
{
public:
    std::ifstream openFile(const char path[]);
};


#endif //CPP1_ASSESSMENT_FILEREADER_H
