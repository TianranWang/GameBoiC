//
//  cpu.hpp
//  GameBoiC
//
//  Created by Tianran on 2017-01-01.
//  Copyright © 2017 Tianran. All rights reserved.
//

#ifndef cpu_hpp
#define cpu_hpp

#include <iostream>
#include <functional>
#include <vector>

#include "memory.hpp"

typedef std::vector<std::function<void()>> FnMap;

struct Registers {
    uint8_t a, b, c, d, e, h, l, f;
    uint16_t pc, sp;
};

class CPU {
public:
    Registers reg;
    FnMap     opcode_map;
    MMU       memory;
    int       total_clock;
    int       last_instr_clock;
    
    CPU();
    
    void reset();
    
private:
    void NOP();
    void STOP();
    
    // n <- 8 bit immediate value
    // r <- register
    // m <- value at MEM[(high<<8) + low]
    
    // 8-bit loads
    
    // LD r, n
    // r <- n
    // r = regs
    // n  = imediate value
    // clock = 2
    void LDrn_an();
    void LDrn_bn();
    void LDrn_cn();
    void LDrn_dn();
    void LDrn_en();
    void LDrn_hn();
    void LDrn_ln();
    
    // LD r1, r2
    // r1 <- r2
    // r1, r2 = a b c d e h l (hl)
    void LDrr_aa();
    void LDrr_ab();
    void LDrr_ac();
    void LDrr_ad();
    void LDrr_ae();
    void LDrr_ah();
    void LDrr_al();
    void LDrm_ahl(); // clock cycle = 2
    
    void LDrr_ba();
    void LDrr_bb();
    void LDrr_bc();
    void LDrr_bd();
    void LDrr_be();
    void LDrr_bh();
    void LDrr_bl();
    void LDrm_bhl(); // clock cycle = 2
    
    void LDrr_ca();
    void LDrr_cb();
    void LDrr_cc();
    void LDrr_cd();
    void LDrr_ce();
    void LDrr_ch();
    void LDrr_cl();
    void LDrm_chl(); // clock cycle = 2
    
    void LDrr_da();
    void LDrr_db();
    void LDrr_dc();
    void LDrr_dd();
    void LDrr_de();
    void LDrr_dh();
    void LDrr_dl();
    void LDrm_dhl(); // clock cycle = 2
    
    void LDrr_ea();
    void LDrr_eb();
    void LDrr_ec();
    void LDrr_ed();
    void LDrr_ee();
    void LDrr_eh();
    void LDrr_el();
    void LDrm_ehl(); // clock cycle = 2
    
    void LDrr_ha();
    void LDrr_hb();
    void LDrr_hc();
    void LDrr_hd();
    void LDrr_he();
    void LDrr_hh();
    void LDrr_hl();
    void LDrm_hhl(); // clock cycle = 2
    
    void LDrr_la();
    void LDrr_lb();
    void LDrr_lc();
    void LDrr_ld();
    void LDrr_le();
    void LDrr_lh();
    void LDrr_ll();
    void LDrm_lhl(); // clock cycle = 2
    
    void LDmr_hla(); // clock cycle = 4
    void LDmr_hlb();
    void LDmr_hlc();
    void LDmr_hld();
    void LDmr_hle();
    void LDmr_hlh();
    void LDmr_hll();
    void LDmn_hln(); // clock cycle = 3
    
    // special for reg.a
    void LDrm_abc();
    void LDrm_ade();
    void LDrm_ann();
};


#endif /* cpu_hpp */
