#include <stdint.h>

#define SRAM_START          0x20000000U
#define SRAM1_SIZE          (112U * 1024U)                                          //112KB
#define SRAM2_SIZE          (16U * 1024U)                                           //16KB
#define SRAM_SIZE           ((SRAM1_SIZE) + (SRAM2_SIZE))                           //128KB   
#define SRAM_END            ((SRAM_START) + (SRAM_SIZE))           
#define STACK_START         SRAM_END

void ResetHandler(void);
void DefaultHandler(void);
void NMIHandler(void)       __attribute__((weak, alias("DefaultHandler")));
void HardFault(void)        __attribute__((weak, alias("DefaultHandler")));
void MemManage(void)        __attribute__((weak, alias("DefaultHandler")));
void BusFault(void)         __attribute__((weak, alias("DefaultHandler")));
void UsageFault(void)       __attribute__((weak, alias("DefaultHandler")));
void SVCall(void)           __attribute__((weak, alias("DefaultHandler")));
void DebugMonitor(void)     __attribute__((weak, alias("DefaultHandler")));
void PendSV(void)           __attribute__((weak, alias("DefaultHandler")));
void SysTick(void)          __attribute__((weak, alias("DefaultHandler")));
void WWDG(void)             __attribute__((weak, alias("DefaultHandler")));
void PVD(void)              __attribute__((weak, alias("DefaultHandler")));
void TAMP_STAMP(void)       __attribute__((weak, alias("DefaultHandler")));
void RTC_WKUP(void)         __attribute__((weak, alias("DefaultHandler")));
void FLASH(void)            __attribute__((weak, alias("DefaultHandler")));
void RCC(void)              __attribute__((weak, alias("DefaultHandler")));
void EXTl0(void)            __attribute__((weak, alias("DefaultHandler")));
void EXTl1(void)            __attribute__((weak, alias("DefaultHandler")));
void EXTl2(void)            __attribute__((weak, alias("DefaultHandler")));
void EXTl3(void)            __attribute__((weak, alias("DefaultHandler")));
void EXTl4(void)            __attribute__((weak, alias("DefaultHandler")));

uint32_t vectors[]          __attribute__((section(".isr_vector"))) = {
    STACK_START,
    (uint32_t)&ResetHandler,
    (uint32_t)NMIHandler,
    (uint32_t)HardFault,
    (uint32_t)MemManage,
    (uint32_t)BusFault,
    (uint32_t)UsageFault,
    (uint32_t)SVCall,
    0,
    0,
    0,
    0,
    (uint32_t)DebugMonitor,
    (uint32_t)PendSV,
    0,
    (uint32_t)SysTick,
    (uint32_t)WWDG,
    (uint32_t)PVD,
    (uint32_t)TAMP_STAMP,
    (uint32_t)RTC_WKUP,
    (uint32_t)FLASH,
    (uint32_t)RCC,
    (uint32_t)EXTl0,
    (uint32_t)EXTl1,
    (uint32_t)EXTl2,
    (uint32_t)EXTl3,
    (uint32_t)EXTl4

};

void DefaultHandler(void){
    while(1);
}
void ResetHandler(void){
    //copy .data section to SRAM
    //Init the .bss section to zero in SRAM
    //call init function of std library
    //call main()
}
