#ifndef EXCEPTION_H
#define EXCEPTION_H
#include "utilities.h"
/*
for some reason, what only works
when we put noexcept 
*/
class DeckFileNotFound: public std::runtime_error
{
public:

    DeckFileNotFound():std::runtime_error("Deck File Error: File not found")
    {

    }
};

class DeckFileFormatError: public std::runtime_error
{

public:

    DeckFileFormatError(int line):std::runtime_error(std::string("Deck File Error: File format error in line ")+std::to_string(line))
    {

    }
};

class DeckFileInvalidSize: public std::runtime_error
{
public:

    DeckFileInvalidSize():std::runtime_error("Deck File Error: Deck size is invalid")
    {

    }
};
#endif