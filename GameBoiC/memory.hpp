//
//  memory.hpp
//  GameBoiC
//
//  Created by Tianran on 2017-01-01.
//  Copyright © 2017 Tianran. All rights reserved.
//

#ifndef memory_hpp
#define memory_hpp

#include <iostream>

// Memory Management Unit
class MMU{
public:
    uint8_t  readByte(uint16_t addr);
    uint16_t readWord(uint16_t addr);
    void     writeByte(uint16_t addr, uint8_t  data);
    void     writeWord(uint16_t addr, uint16_t word);
};

#endif /* memory_hpp */
