/*
 * Copyright (C) Rida Bazzi, 2016
 *
 * Do not share this file with anyone
 */

/*
*** Name: Harish Chaurasia
*** CSE 340-Project_3 Type Checking
*/

#include <iostream>
#include <istream>
#include <vector>
#include <string>
#include <cstdio>

#include "inputbuf.h"

using namespace std;

bool InputBuffer::EndOfInput()
{
    if (!input_buffer.empty())
        return false;
    else
        return cin.eof();
}

char InputBuffer::UngetChar(char c)
{
    if (c != EOF)
        input_buffer.push_back(c);
    ;
    return c;
}

void InputBuffer::GetChar(char &c)
{
    if (!input_buffer.empty())
    {
        c = input_buffer.back();
        input_buffer.pop_back();
    }
    else
    {
        cin.get(c);
    }
}

string InputBuffer::UngetString(string s)
{
    for (int i = 0; i < s.size(); i++)
        input_buffer.push_back(s[s.size() - i - 1]);
    return s;
}

// for project 2, we implemented peekchar, to look ahead of a character

char InputBuffer::PeekChar()
{
    char c;
    if (!input_buffer.empty())
    {
        // We Just look at the last character in the buffer without actually removing it
        c = input_buffer.back();
    }
    else
    {
        // If the buffer is empty, we read a character from cin but then we also put it back
        cin.get(c);
        if (c != EOF)
        {
            // Puting the character back into the buffer
            input_buffer.push_back(c);
        }
    }
    // Return the character that was "peeked" at
    return c;
}