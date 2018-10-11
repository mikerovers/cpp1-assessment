#ifndef CPP1_ASSESSMENT_FILENOTOPENEDEXCEPTION_H
#define CPP1_ASSESSMENT_FILENOTOPENEDEXCEPTION_H

#include <exception>

class FileNotOpenedException : public std::exception
{
public:
    explicit FileNotOpenedException(const char* path);

    const char* what() const noexcept override
    {
        return "File could not be opened.";
    }

private:
    const char* path;
};


#endif //CPP1_ASSESSMENT_FILENOTOPENEDEXCEPTION_H
