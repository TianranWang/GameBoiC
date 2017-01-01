//
//  cpu.cpp
//  GameBoiC
//
//  Created by Tianran on 2017-01-01.
//  Copyright © 2017 Tianran. All rights reserved.
//

#include "cpu.hpp"

CPU::CPU(){
    this->reg              = Registers();
    this->total_clock      = 0;
    this->last_instr_clock = 0;
}

void CPU::reset(){
    this->reg              = Registers();
    this->total_clock      = 0;
    this->last_instr_clock = 0;
}

// 0x3E
void CPU::LDrn_an(){
    reg.a = memory.readByte(++reg.pc);
    last_instr_clock = 2;
}

// 0x06
void CPU::LDrn_bn(){
    reg.b = memory.readByte(++reg.pc);
    last_instr_clock = 2;
}
// 0x0E
void CPU::LDrn_cn(){
    reg.c = memory.readByte(++reg.pc);
    last_instr_clock = 2;
}

// 0x16
void CPU::LDrn_dn(){
    reg.d = memory.readByte(++reg.pc);
    last_instr_clock = 2;
}

// 0x1E
void CPU::LDrn_en(){
    reg.e = memory.readByte(++reg.pc);
    last_instr_clock = 2;
}

// 0x26
void CPU::LDrn_hn(){
    reg.h = memory.readByte(++reg.pc);
    last_instr_clock = 2;
}

// 0x2E
void CPU::LDrn_ln(){
    reg.l = memory.readByte(++reg.pc);
    last_instr_clock = 2;
}

void CPU::LDrr_aa(){ reg.a = reg.a; last_instr_clock = 1;}
void CPU::LDrr_ab(){ reg.a = reg.b; last_instr_clock = 1;}
void CPU::LDrr_ac(){ reg.a = reg.c; last_instr_clock = 1;}
void CPU::LDrr_ad(){ reg.a = reg.d; last_instr_clock = 1;}
void CPU::LDrr_ae(){ reg.a = reg.e; last_instr_clock = 1;}
void CPU::LDrr_ah(){ reg.a = reg.h; last_instr_clock = 1;}
void CPU::LDrr_al(){ reg.a = reg.l; last_instr_clock = 1;}
void CPU::LDrm_ahl(){
    uint16_t addr    = ((static_cast<uint16_t>(reg.h)) << 8) + reg.l;
    reg.a            = memory.readByte(addr);
    last_instr_clock = 2;
}
void CPU::LDrr_ba(){ reg.b = reg.a; last_instr_clock = 1;}
void CPU::LDrr_bb(){ reg.b = reg.b; last_instr_clock = 1;}
void CPU::LDrr_bc(){ reg.b = reg.c; last_instr_clock = 1;}
void CPU::LDrr_bd(){ reg.b = reg.d; last_instr_clock = 1;}
void CPU::LDrr_be(){ reg.b = reg.e; last_instr_clock = 1;}
void CPU::LDrr_bh(){ reg.b = reg.h; last_instr_clock = 1;}
void CPU::LDrr_bl(){ reg.b = reg.l; last_instr_clock = 1;}
void CPU::LDrm_bhl(){
    uint16_t addr    = ((static_cast<uint16_t>(reg.h)) << 8) + reg.l;
    reg.b            = memory.readByte(addr);
    last_instr_clock = 2;
}
void CPU::LDrr_ca(){ reg.c = reg.a; last_instr_clock = 1;}
void CPU::LDrr_cb(){ reg.c = reg.b; last_instr_clock = 1;}
void CPU::LDrr_cc(){ reg.c = reg.c; last_instr_clock = 1;}
void CPU::LDrr_cd(){ reg.c = reg.d; last_instr_clock = 1;}
void CPU::LDrr_ce(){ reg.c = reg.e; last_instr_clock = 1;}
void CPU::LDrr_ch(){ reg.c = reg.h; last_instr_clock = 1;}
void CPU::LDrr_cl(){ reg.c = reg.l; last_instr_clock = 1;}
void CPU::LDrm_chl(){
    uint16_t addr    = ((static_cast<uint16_t>(reg.h)) << 8) + reg.l;
    reg.c            = memory.readByte(addr);
    last_instr_clock = 2;
}
void CPU::LDrr_da(){ reg.d = reg.a; last_instr_clock = 1;}
void CPU::LDrr_db(){ reg.d = reg.b; last_instr_clock = 1;}
void CPU::LDrr_dc(){ reg.d = reg.c; last_instr_clock = 1;}
void CPU::LDrr_dd(){ reg.d = reg.d; last_instr_clock = 1;}
void CPU::LDrr_de(){ reg.d = reg.e; last_instr_clock = 1;}
void CPU::LDrr_dh(){ reg.d = reg.h; last_instr_clock = 1;}
void CPU::LDrr_dl(){ reg.d = reg.l; last_instr_clock = 1;}
void CPU::LDrm_dhl(){
    uint16_t addr    = ((static_cast<uint16_t>(reg.h)) << 8) + reg.l;
    reg.d            = memory.readByte(addr);
    last_instr_clock = 2;
}
void CPU::LDrr_ea(){ reg.e = reg.a; last_instr_clock = 1;}
void CPU::LDrr_eb(){ reg.e = reg.b; last_instr_clock = 1;}
void CPU::LDrr_ec(){ reg.e = reg.c; last_instr_clock = 1;}
void CPU::LDrr_ed(){ reg.e = reg.d; last_instr_clock = 1;}
void CPU::LDrr_ee(){ reg.e = reg.e; last_instr_clock = 1;}
void CPU::LDrr_eh(){ reg.e = reg.h; last_instr_clock = 1;}
void CPU::LDrr_el(){ reg.e = reg.l; last_instr_clock = 1;}
void CPU::LDrm_ehl(){
    uint16_t addr    = ((static_cast<uint16_t>(reg.h)) << 8) + reg.l;
    reg.e            = memory.readByte(addr);
    last_instr_clock = 2;
}
void CPU::LDrr_ha(){ reg.h = reg.a; last_instr_clock = 1;}
void CPU::LDrr_hb(){ reg.h = reg.b; last_instr_clock = 1;}
void CPU::LDrr_hc(){ reg.h = reg.c; last_instr_clock = 1;}
void CPU::LDrr_hd(){ reg.h = reg.d; last_instr_clock = 1;}
void CPU::LDrr_he(){ reg.h = reg.e; last_instr_clock = 1;}
void CPU::LDrr_hh(){ reg.h = reg.h; last_instr_clock = 1;}
void CPU::LDrr_hl(){ reg.h = reg.l; last_instr_clock = 1;}
void CPU::LDrm_hhl(){
    uint16_t addr    = ((static_cast<uint16_t>(reg.h)) << 8) + reg.l;
    reg.h            = memory.readByte(addr);
    last_instr_clock = 2;
}
void CPU::LDrr_la(){ reg.l = reg.a; last_instr_clock = 1;}
void CPU::LDrr_lb(){ reg.l = reg.b; last_instr_clock = 1;}
void CPU::LDrr_lc(){ reg.l = reg.c; last_instr_clock = 1;}
void CPU::LDrr_ld(){ reg.l = reg.d; last_instr_clock = 1;}
void CPU::LDrr_le(){ reg.l = reg.e; last_instr_clock = 1;}
void CPU::LDrr_lh(){ reg.l = reg.h; last_instr_clock = 1;}
void CPU::LDrr_ll(){ reg.l = reg.l; last_instr_clock = 1;}
void CPU::LDrm_lhl(){
    uint16_t addr    = ((static_cast<uint16_t>(reg.h)) << 8) + reg.l;
    reg.l            = memory.readByte(addr);
    last_instr_clock = 2;
}
void CPU::LDmr_hla(){ uint16_t addr = ((static_cast<uint16_t>(reg.h)) << 8) + reg.l; memory.writeByte(addr, reg.a); last_instr_clock = 2; }
void CPU::LDmr_hlb(){ uint16_t addr = ((static_cast<uint16_t>(reg.h)) << 8) + reg.l; memory.writeByte(addr, reg.b); last_instr_clock = 2; }
void CPU::LDmr_hlc(){ uint16_t addr = ((static_cast<uint16_t>(reg.h)) << 8) + reg.l; memory.writeByte(addr, reg.c); last_instr_clock = 2; }
void CPU::LDmr_hld(){ uint16_t addr = ((static_cast<uint16_t>(reg.h)) << 8) + reg.l; memory.writeByte(addr, reg.d); last_instr_clock = 2; }
void CPU::LDmr_hle(){ uint16_t addr = ((static_cast<uint16_t>(reg.h)) << 8) + reg.l; memory.writeByte(addr, reg.e); last_instr_clock = 2; }
void CPU::LDmr_hlh(){ uint16_t addr = ((static_cast<uint16_t>(reg.h)) << 8) + reg.l; memory.writeByte(addr, reg.h); last_instr_clock = 2; }
void CPU::LDmr_hll(){ uint16_t addr = ((static_cast<uint16_t>(reg.h)) << 8) + reg.l; memory.writeByte(addr, reg.l); last_instr_clock = 2; }
void CPU::LDmn_hln(){ uint16_t addr = ((static_cast<uint16_t>(reg.h)) << 8) + reg.l; memory.writeByte(addr, memory.readByte(++reg.pc)); last_instr_clock = 3; }

void CPU::LDrm_abc(){
    uint16_t addr = ((static_cast<uint16_t>(reg.b)) << 8) + reg.c;
    reg.a         = memory.readByte(addr);
    last_instr_clock = 2;
}

void CPU::LDrm_ade(){
    uint16_t addr = ((static_cast<uint16_t>(reg.d)) << 8) + reg.e;
    reg.a         = memory.readByte(addr);
    last_instr_clock = 2;
}

void CPU::LDrm_ann(){
    uint16_t addr = ((static_cast<uint16_t>(memory.readByte(++reg.pc))) << 8) + memory.readByte(++reg.pc);
    reg.a         = memory.readByte(addr);
    last_instr_clock = 4;
}
