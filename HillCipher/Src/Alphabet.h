#pragma once

struct Alphabet26
{
    char chars[26] = {
        'A', 'B', 'C', 'D', 'E', 'F', 'G',
        'H', 'I', 'J', 'K', 'L', 'M', 'N',
        'O', 'P', 'Q', 'R', 'S', 'T', 'U',
        'V', 'W', 'X', 'Y', 'Z'
    };

    Alphabet26()
    {
    }

    int length()
    {
        return 26;
    }

    int canonicalPositionOf(char ch)
    {
        return (int) ch - 65;
    }
};
