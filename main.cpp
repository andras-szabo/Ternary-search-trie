#include <iostream>
#include "tst.h"

void test()
{
    cTST<int>   tst(-1);
    
    std::vector<std::string> vec { "now", "then", "mardy", "bum", "I've", "seen", "your", "frown",
    "and", "it's", "like", "looking", "down", "a", "barrel", "of", "gun", "goes", "off", "out", "come",
    "all", "these", "words", "there's", "very", "pleasant", "side", "to", "you", "one", "I", "prefer",
    "laughs", "jokes", "around", "remembers", "cuddles", "in", "kitchen", "yeah"};

    // Fill up tst
    for (const auto& i : vec)
        tst.put(i, 1);

    // List all keys
    auto v = tst.keys();
    for (const auto& i : v)
        std::cout << i << "\n";
    
    std::cout << "\n";

    // Look for keys matching wildcard
    auto x = tst.wildcardSearch("o**");
    for(const auto& i : x)
        std::cout << i << "\n";

    std::cout << "\n";
    
    auto y = tst.wildcardSearch("m*rd*");
    for (const auto& i : y )
        std::cout << i << "\n";
    
}

int main()
{
    test();
    return 0;
}