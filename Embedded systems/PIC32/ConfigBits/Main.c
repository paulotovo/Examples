/******************************************************************************************
 *
 *	Hardware Settings for PIC32MX795F512L 
 *
 ******************************************************************************************
 * FileName:        Main.c
 * Processor:       PIC32MX795F512L
 * Compiler:        CX32 v1.3.1
 * Company:         Hardware & Development of cross-platform software
 *
 * Author             Date		     Comment
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Paulo Tovo		    15/07/2017	
 *******************************************************************************************/
 
#define  MAIN_C

// Adds support for PIC32 Peripheral library functions and macros
#include <plib.h>   

#define USE_CONFIG_WITH_CRYSTAL_20MHZ_PLL
// #define USE_CONFIG_WITH_CRYSTAL_20MHZ
// #define USE_CONFIG_WITH_INTERNAL_OSCILLATOR
// #define USE_CONFIG_WITH_INTERNAL_OSCILLATOR_PLL

#if defined(USE_CONFIG_WITH_CRYSTAL_20MHZ_PLL)
/////////////////////////////////////////////////////////////////////////////////////////////
//
// Settings for external crystal 16MHZ WITH PLL
//
// Configuration Bit settings
// SYSCLK = 80 MHz (20MHz Crystal/ FPLLIDIV * FPLLMUL / FPLLODIV)
// PBCLK = 40 MHz
// Primary Osc w/PLL (XT+,HS+,EC+PLL)
// WDT OFF
// Other options are don't care
//
/////////////////////////////////////////////////////////////////////////////////////////////

// FPLLIDIV = 20MHZ / 5 = 4MHZ
// FPLLMUL  = FPLLIDIV * 20 => 4MHZ * 20 = 80MHZ
// FPLLODIV = 80MHZ / 1 => SYSCLK = 80MHZ
// PBCLK = 40MHZ ( Peripheral Bus Clock Divisor = SYSCLK / FPBDIV )

#pragma config POSCMOD      = HS           // Primary oscillator to High Speed
#pragma config FNOSC        = PRIPLL       // Primary oscillator with PLL
#pragma config FPLLIDIV     = DIV_5        // PLL Input divider (5x divider)
#pragma config FPLLMUL      = MUL_20       // PLL Multiplier (20x Multiplier)
#pragma config FPLLODIV     = DIV_1        // System PLL Output Clock Divider (PLL Divide by 1)
#pragma config FWDTEN       = OFF          // Watchdog Timer Enable (WDT Disabled (SWDTEN Bit Controls))
#pragma config FPBDIV       = DIV_2        // Peripheral Bus Clock Divisor -  PBCLK is SYSCLK divided by 2
#pragma config CP           = OFF          // Code Protect
#pragma config BWP          = OFF          // Boot Flash Write Protect
#pragma config PWP          = OFF          // Program Flash Write Protect
#pragma config ICESEL       = ICS_PGx1     // ICE/ICD Comm Channel Select
#pragma config DEBUG        = OFF          // Background Debugger Enable


#elif(USE_CONFIG_WITH_CRYSTAL_20MHZ)
/////////////////////////////////////////////////////////////////////////////////////////////
//
// Settings for external crystal 16MHZ WITHOUT PLL
//
// Configuration Bit settings
// SYSCLK = 20 MHz 
// PBCLK  = 20 MHz ( Peripheral Bus Clock Divisor = SYSCLK / FPBDIV )
// Primary Osc HS+
// WDT OFF
// Other options are don't care
//
/////////////////////////////////////////////////////////////////////////////////////////////

#pragma config POSCMOD      = HS           // Primary oscillator to High Speed
#pragma config FNOSC        = PRI          // Primary oscillator 
#pragma config FWDTEN       = OFF          // Watchdog Timer Enable (WDT Disabled (SWDTEN Bit Controls))
#pragma config FPBDIV       = DIV_1        // Peripheral Bus Clock Divisor -  PBCLK is SYSCLK divided by 1
#pragma config CP           = OFF          // Code Protect
#pragma config BWP          = OFF          // Boot Flash Write Protect
#pragma config PWP          = OFF          // Program Flash Write Protect
#pragma config ICESEL       = ICS_PGx1     // ICE/ICD Comm Channel Select
#pragma config DEBUG        = OFF          // Background Debugger Enable


#elif(USE_CONFIG_WITH_INTERNAL_OSCILLATOR)
/////////////////////////////////////////////////////////////////////////////////////////////
//
// Settings for INTERNAL OSCILLATOR WITHOUT PLL
//
// Configuration Bit settings
// SYSCLK = 8 MHz 
// PBCLK  = 8 MHz ( Peripheral Bus Clock Divisor = SYSCLK / FPBDIV )
// Primary Osc OFF because i'm using internal oscillator
// WDT OFF
// Other options are don't care
//
/////////////////////////////////////////////////////////////////////////////////////////////


// DEVCFG1
#pragma config FNOSC = FRC              // Oscillator Selection Bits (Fast RC Osc)
#pragma config FSOSCEN = OFF            // Secondary Oscillator Enable (Disabled)
#pragma config IESO = OFF               // Internal/External Switch Over (Disabled)
#pragma config POSCMOD = OFF             // Primary Oscillator Configuration (Primary osc disabled)
#pragma config OSCIOFNC = OFF           // CLKO Output Signal Active on the OSCO Pin (Disabled)
#pragma config FPBDIV = DIV_1           // Peripheral Clock Divisor (Pb_Clk is Sys_Clk/1)
#pragma config WDTPS = PS1              // Watchdog Timer Postscaler (1:1)
#pragma config FWDTEN = OFF             // Watchdog Timer Enable (WDT Disabled (SWDTEN Bit Controls))

// DEVCFG0
#pragma config DEBUG = OFF              // Background Debugger Enable (Debugger is disabled)
#pragma config ICESEL = ICS_PGx1        // ICE/ICD Comm Channel Select (ICE EMUC1/EMUD1 pins shared with PGC1/PGD1)
#pragma config PWP = OFF                // Program Flash Write Protect (Disable)
#pragma config BWP = OFF                // Boot Flash Write Protect bit (Protection Disabled)
#pragma config CP = OFF                 // Code Protect (Protection Disabled)


#elif(USE_CONFIG_WITH_INTERNAL_OSCILLATOR_PLL)
/////////////////////////////////////////////////////////////////////////////////////////////
//
// Settings for INTERNAL OSCILLATOR WITH PLL
//
// Configuration Bit settings
// SYSCLK = 80 MHz (8MHz Crystal/ FPLLIDIV * FPLLMUL / FPLLODIV)
// PBCLK = 80 MHz ( Peripheral Bus Clock Divisor = SYSCLK / FPBDIV )
// Primary Osc OFF because i'm using internal oscillator
// WDT OFF
// Other options are don't care
//
/////////////////////////////////////////////////////////////////////////////////////////////

// FPLLIDIV = 8MHZ / 2 = 4MHZ
// FPLLMUL  = FPLLIDIV * 20 => 4MHZ * 20 = 80MHZ
// FPLLODIV = 80MHZ / 1 => SYSCLK = 80MHZ

// DEVCFG2
#pragma config FPLLIDIV = DIV_2         // PLL Input Divider (2x Divider)
#pragma config FPLLMUL = MUL_20         // PLL Multiplier (20x Multiplier)
#pragma config UPLLIDIV = DIV_1         // USB PLL Input Divider (1x Divider)
#pragma config UPLLEN = OFF             // USB PLL Enable (Disabled and Bypassed)
#pragma config FPLLODIV = DIV_1         // System PLL Output Clock Divider (PLL Divide by 1)

// DEVCFG1
#pragma config FNOSC = FRCPLL           // Oscillator Selection Bits (Fast RC Osc with PLL)
#pragma config FSOSCEN = OFF            // Secondary Oscillator Enable (Disabled)
#pragma config IESO = OFF               // Internal/External Switch Over (Disabled)
#pragma config POSCMOD = OFF            // Primary Oscillator Configuration (Primary osc disabled)
#pragma config OSCIOFNC = OFF           // CLKO Output Signal Active on the OSCO Pin (Disabled)
#pragma config FPBDIV = DIV_1           // Peripheral Clock Divisor (Pb_Clk is Sys_Clk/1)
#pragma config WDTPS = PS1              // Watchdog Timer Postscaler (1:1)
#pragma config FWDTEN = OFF             // Watchdog Timer Enable (WDT Disabled (SWDTEN Bit Controls))

// DEVCFG0
#pragma config DEBUG = OFF              // Background Debugger Enable (Debugger is disabled)
#pragma config ICESEL = ICS_PGx1        // ICE/ICD Comm Channel Select (ICE EMUC1/EMUD1 pins shared with PGC1/PGD1)
#pragma config PWP = OFF                // Program Flash Write Protect (Disable)
#pragma config BWP = OFF                // Boot Flash Write Protect bit (Protection Disabled)
#pragma config CP = OFF                 // Code Protect (Protection Disabled)

#else
	#error "No settings for processor."
#endif	

// Let compile time pre-processor calculate the CORE_TICK_PERIOD
#define SYS_FREQ 			(80000000L)
#define TOGGLES_PER_SEC	    10
#define CORE_TICK_RATE	    (SYS_FREQ/2/TOGGLES_PER_SEC)

int main(void)
{
  while(1)	
  {

  }
}