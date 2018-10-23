  
    /*
  * benchmark_no_taylor_acc.h
  *
    * Code generation for model "benchmark_no_taylor_acc".
  *
  * Model version              : 1.2
  * Simulink Coder version : 8.11 (R2016b) 25-Aug-2016
  * C source code generated on : Fri Jan 26 17:50:45 2018
 * 
 * Target selection: accel.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Emulation hardware selection: 
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
  */


  #ifndef RTW_HEADER_benchmark_no_taylor_acc_h_
  #define RTW_HEADER_benchmark_no_taylor_acc_h_
  
      

  
#include <stddef.h>

#include <string.h>

#include <float.h>
    #ifndef benchmark_no_taylor_acc_COMMON_INCLUDES_
  # define benchmark_no_taylor_acc_COMMON_INCLUDES_
      #include <stdlib.h>
        #define S_FUNCTION_NAME simulink_only_sfcn 
  #define S_FUNCTION_LEVEL 2
  #define RTW_GENERATED_S_FUNCTION

    #include "rtwtypes.h"
      #include "simstruc.h"
      #include "fixedpoint.h"
    
  #endif /* benchmark_no_taylor_acc_COMMON_INCLUDES_ */
  

    #include "benchmark_no_taylor_acc_types.h"    
        
    /* Shared type includes */
          #include "multiword_types.h"

    

  
  
#include "mwmathutil.h"

#include "rt_defines.h"

#include "rt_nonfinite.h"

  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
              /* Block signals for system '<S23>/B_44_57' */
                  
          
  
     typedef struct  {
  
  
          
          
                  
          

                  real_T B_3_4_0; /* '<S30>/Integral schedule' */
                          

	  
          

          
          
                  
          

                  real_T B_3_10_0; /* '<S30>/Rate Limiter' */
                          

	  
          




  
    } B_Pitchcontroller_benchmark_no_taylor_T;
  

        
              
          /* Block states (auto storage) for system '<S23>/B_44_57' */
              
        
  
     typedef struct  {
  
  
          
          
                  
          

                  real_T DiscreteTimeIntegrator_DSTATE; /* '<S30>/Discrete-Time Integrator' */
                          

	  
          

          
          
                  
          

                  real_T IntegerDelay_DSTATE; /* '<S30>/Integer Delay' */
                          

	  
          

          
          
                  
          

                  real_T PrevY; /* '<S30>/Rate Limiter' */
                          

	  
          

          
          
                  
          

                  int8_T Pitchcontroller_SubsysRanBC; /* '<S23>/Pitch controller' */
                          

	  
          

          
          
                  
          

                  boolean_T Pitchcontroller_MODE; /* '<S23>/Pitch controller' */
                          

	  
          

          
          
                  
          

                  char_T pad_Pitchcontroller_MODE[6]; 
                          

	  
          




  
    } DW_Pitchcontroller_benchmark_no_taylor_T;
  

      
        
            /* Block signals (auto storage) */
                  
          
  
     typedef struct  {
  
  
          
          
                  
          

                  real_T B_53_0_0[4]; /* '<S27>/Computation Delay' */
                          

	  
          

          
          
                  
          

                  real_T B_53_2_0[4]; /* '<S59>/Computation Delay' */
                          

	  
          

          
          
                  
          

                  real_T B_53_4_0[4]; /* '<S75>/Computation Delay' */
                          

	  
          

          
          
                  
          

                  real_T B_53_6_0[4]; /* '<S91>/Computation Delay' */
                          

	  
          

          
          
                  
          

                  real_T B_53_8_0[4]; /* '<S107>/Computation Delay' */
                          

	  
          

          
          
                  
          

                  real_T B_53_10_0[4]; /* '<S123>/Computation Delay' */
                          

	  
          

          
          
                  
          

                  real_T B_53_12_0[4]; /* '<S139>/Computation Delay' */
                          

	  
          

          
          
                  
          

                  real_T B_53_14_0[4]; /* '<S155>/Computation Delay' */
                          

	  
          

          
          
                  
          

                  real_T B_53_16_0[4]; /* '<S171>/Computation Delay' */
                          

	  
          

          
          
                  
          

                  real_T B_53_18_0[4]; /* '<S43>/Computation Delay' */
                          

	  
          

          
          
                  
          

                  real_T B_53_20_0[10]; /* '<S6>/CTrate1' */
                          

	  
          

          
          
                  
          

                  real_T B_53_21_0[10]; /* '<S1>/Sample WS' */
                          

	  
          

          
          
                  
          

                  real_T B_53_22_0; /* '<S4>/Reference delay' */
                          

	  
          

          
          
                  
          

                  real_T B_53_23_0; /* '<S1>/Sample power' */
                          

	  
          

          
          
                  
          

                  real_T B_53_27_0; /* '<S2>/Integrator' */
                          

	  
          

          
          
                  
          

                  real_T B_53_29_0; /* '<S9>/FromWs' */
                          

	  
          

          
          
                  
          

                  real_T B_53_30_0; /* '<S3>/To rated farm power' */
                          

	  
          

          
          
                  
          

                  real_T B_53_36_0; /* '<S25>/Generator efficiency' */
                          

	  
          

          
          
                  
          

                  real_T B_53_40_0; /* '<S57>/Generator efficiency' */
                          

	  
          

          
          
                  
          

                  real_T B_53_44_0; /* '<S73>/Generator efficiency' */
                          

	  
          

          
          
                  
          

                  real_T B_53_48_0; /* '<S89>/Generator efficiency' */
                          

	  
          

          
          
                  
          

                  real_T B_53_52_0; /* '<S105>/Generator efficiency' */
                          

	  
          

          
          
                  
          

                  real_T B_53_56_0; /* '<S121>/Generator efficiency' */
                          

	  
          

          
          
                  
          

                  real_T B_53_60_0; /* '<S137>/Generator efficiency' */
                          

	  
          

          
          
                  
          

                  real_T B_53_64_0; /* '<S153>/Generator efficiency' */
                          

	  
          

          
          
                  
          

                  real_T B_53_68_0; /* '<S169>/Generator efficiency' */
                          

	  
          

          
          
                  
          

                  real_T B_53_72_0; /* '<S41>/Generator efficiency' */
                          

	  
          

          
          
                  
          

                  real_T B_53_74_0; /* '<Root>/Total power' */
                          

	  
          

          
          
                  
          

                  real_T B_53_78_0; /* '<S27>/gen sample' */
                          

	  
          

          
          
                  
          

                  real_T B_53_79_0; /* '<S59>/gen sample' */
                          

	  
          

          
          
                  
          

                  real_T B_53_80_0; /* '<S75>/gen sample' */
                          

	  
          

          
          
                  
          

                  real_T B_53_81_0; /* '<S91>/gen sample' */
                          

	  
          

          
          
                  
          

                  real_T B_53_82_0; /* '<S107>/gen sample' */
                          

	  
          

          
          
                  
          

                  real_T B_53_83_0; /* '<S123>/gen sample' */
                          

	  
          

          
          
                  
          

                  real_T B_53_84_0; /* '<S139>/gen sample' */
                          

	  
          

          
          
                  
          

                  real_T B_53_85_0; /* '<S155>/gen sample' */
                          

	  
          

          
          
                  
          

                  real_T B_53_86_0; /* '<S171>/gen sample' */
                          

	  
          

          
          
                  
          

                  real_T B_53_87_0; /* '<S43>/gen sample' */
                          

	  
          

          
          
                  
          

                  real_T B_53_102_0; /* '<S11>/Constant' */
                          

	  
          

          
          
                  
          

                  real_T B_53_103_0; /* '<S13>/Constant' */
                          

	  
          

          
          
                  
          

                  real_T B_53_104_0; /* '<S14>/Constant' */
                          

	  
          

          
          
                  
          

                  real_T B_53_105_0; /* '<S15>/Constant' */
                          

	  
          

          
          
                  
          

                  real_T B_53_106_0; /* '<S16>/Constant' */
                          

	  
          

          
          
                  
          

                  real_T B_53_107_0; /* '<S17>/Constant' */
                          

	  
          

          
          
                  
          

                  real_T B_53_108_0; /* '<S18>/Constant' */
                          

	  
          

          
          
                  
          

                  real_T B_53_109_0; /* '<S19>/Constant' */
                          

	  
          

          
          
                  
          

                  real_T B_53_110_0; /* '<S20>/Constant' */
                          

	  
          

          
          
                  
          

                  real_T B_53_111_0; /* '<S12>/Constant' */
                          

	  
          

          
          
                  
          

                  real_T B_53_115_0[9009]; /* '<S193>/Ux_full' */
                          

	  
          

          
          
                  
          

                  real_T B_53_117_0[9]; /* '<S193>/Selector1' */
                          

	  
          

          
          
                  
          

                  real_T B_53_118_0; /* '<S183>/Nodelay' */
                          

	  
          

          
          
                  
          

                  real_T B_53_129_0; /* '<S185>/Nodelay' */
                          

	  
          

          
          
                  
          

                  real_T B_53_137_0; /* '<S186>/Nodelay' */
                          

	  
          

          
          
                  
          

                  real_T B_53_142_0; /* '<S187>/Nodelay' */
                          

	  
          

          
          
                  
          

                  real_T B_53_144_0; /* '<S188>/Nodelay' */
                          

	  
          

          
          
                  
          

                  real_T B_53_154_0; /* '<S189>/Nodelay' */
                          

	  
          

          
          
                  
          

                  real_T B_53_161_0; /* '<S190>/Nodelay' */
                          

	  
          

          
          
                  
          

                  real_T B_53_165_0; /* '<S191>/Nodelay' */
                          

	  
          

          
          
                  
          

                  real_T B_53_173_0; /* '<S192>/Nodelay' */
                          

	  
          

          
          
                  
          

                  real_T B_53_178_0; /* '<S184>/Nodelay' */
                          

	  
          

          
          
                  
          

                  real_T B_53_180_0[100]; /* '<S7>/wcconcat' */
                          

	  
          

          
          
                  
          

                  real_T B_53_233_0[100]; /* '<S7>/wdconcat' */
                          

	  
          

          
          
                  
          

                  real_T B_53_286_0[100]; /* '<S7>/ctconcat' */
                          

	  
          

          
          
                  
          

                  real_T B_53_289_0; /* '<S11>/Constant1' */
                          

	  
          

          
          
                  
          

                  real_T B_53_296_0; /* '<S29>/C_T table' */
                          

	  
          

          
          
                  
          

                  real_T B_53_298_0[9009]; /* '<S195>/Ux_full' */
                          

	  
          

          
          
                  
          

                  real_T B_53_300_0[9]; /* '<S195>/Selector1' */
                          

	  
          

          
          
                  
          

                  real_T B_53_302_0; /* '<S13>/Constant1' */
                          

	  
          

          
          
                  
          

                  real_T B_53_309_0; /* '<S61>/C_T table' */
                          

	  
          

          
          
                  
          

                  real_T B_53_311_0[9009]; /* '<S196>/Ux_full' */
                          

	  
          

          
          
                  
          

                  real_T B_53_313_0[9]; /* '<S196>/Selector1' */
                          

	  
          

          
          
                  
          

                  real_T B_53_315_0; /* '<S14>/Constant1' */
                          

	  
          

          
          
                  
          

                  real_T B_53_322_0; /* '<S77>/C_T table' */
                          

	  
          

          
          
                  
          

                  real_T B_53_324_0[9009]; /* '<S197>/Ux_full' */
                          

	  
          

          
          
                  
          

                  real_T B_53_326_0[9]; /* '<S197>/Selector1' */
                          

	  
          

          
          
                  
          

                  real_T B_53_328_0; /* '<S15>/Constant1' */
                          

	  
          

          
          
                  
          

                  real_T B_53_335_0; /* '<S93>/C_T table' */
                          

	  
          

          
          
                  
          

                  real_T B_53_337_0[9009]; /* '<S198>/Ux_full' */
                          

	  
          

          
          
                  
          

                  real_T B_53_339_0[9]; /* '<S198>/Selector1' */
                          

	  
          

          
          
                  
          

                  real_T B_53_341_0; /* '<S16>/Constant1' */
                          

	  
          

          
          
                  
          

                  real_T B_53_348_0; /* '<S109>/C_T table' */
                          

	  
          

          
          
                  
          

                  real_T B_53_350_0[9009]; /* '<S199>/Ux_full' */
                          

	  
          

          
          
                  
          

                  real_T B_53_352_0[9]; /* '<S199>/Selector1' */
                          

	  
          

          
          
                  
          

                  real_T B_53_354_0; /* '<S17>/Constant1' */
                          

	  
          

          
          
                  
          

                  real_T B_53_361_0; /* '<S125>/C_T table' */
                          

	  
          

          
          
                  
          

                  real_T B_53_363_0[9009]; /* '<S200>/Ux_full' */
                          

	  
          

          
          
                  
          

                  real_T B_53_365_0[9]; /* '<S200>/Selector1' */
                          

	  
          

          
          
                  
          

                  real_T B_53_367_0; /* '<S18>/Constant1' */
                          

	  
          

          
          
                  
          

                  real_T B_53_374_0; /* '<S141>/C_T table' */
                          

	  
          

          
          
                  
          

                  real_T B_53_376_0[9009]; /* '<S201>/Ux_full' */
                          

	  
          

          
          
                  
          

                  real_T B_53_378_0[9]; /* '<S201>/Selector1' */
                          

	  
          

          
          
                  
          

                  real_T B_53_380_0; /* '<S19>/Constant1' */
                          

	  
          

          
          
                  
          

                  real_T B_53_387_0; /* '<S157>/C_T table' */
                          

	  
          

          
          
                  
          

                  real_T B_53_389_0[9009]; /* '<S202>/Ux_full' */
                          

	  
          

          
          
                  
          

                  real_T B_53_391_0[9]; /* '<S202>/Selector1' */
                          

	  
          

          
          
                  
          

                  real_T B_53_393_0; /* '<S20>/Constant1' */
                          

	  
          

          
          
                  
          

                  real_T B_53_400_0; /* '<S173>/C_T table' */
                          

	  
          

          
          
                  
          

                  real_T B_53_402_0[9009]; /* '<S194>/Ux_full' */
                          

	  
          

          
          
                  
          

                  real_T B_53_404_0[9]; /* '<S194>/Selector1' */
                          

	  
          

          
          
                  
          

                  real_T B_53_406_0; /* '<S12>/Constant1' */
                          

	  
          

          
          
                  
          

                  real_T B_53_413_0; /* '<S45>/C_T table' */
                          

	  
          

          
          
                  
          

                  real_T B_53_414_0[10]; /* '<S6>/CTrate5' */
                          

	  
          

          
          
                  
          

                  real_T B_53_422_0; /* '<S2>/Active power diff to freq' */
                          

	  
          

          
          
                  
          

                  real_T B_53_423_0; /* '<S4>/F_meas delay' */
                          

	  
          

          
          
                  
          

                  real_T B_53_424_0; /* '<S4>/P meas delay' */
                          

	  
          

          
          
                  
          

                  real_T B_53_425_0; /* '<S4>/settings' */
                          

	  
          

          
          
                  
          

                  real_T B_53_426_0; /* '<S4>/Unit Delay' */
                          

	  
          

          
          
                  
          

                  real_T B_53_428_0; /* '<S4>/Sample frequency' */
                          

	  
          

          
          
                  
          

                  real_T B_53_429_0; /* '<S4>/Sample power' */
                          

	  
          

          
          
                  
          

                  real_T B_53_431_0; /* '<S24>/Main shaft  spring constant  K [Nm//rad]' */
                          

	  
          

          
          
                  
          

                  real_T B_53_433_0; /* '<S56>/Main shaft  spring constant  K [Nm//rad]' */
                          

	  
          

          
          
                  
          

                  real_T B_53_435_0; /* '<S72>/Main shaft  spring constant  K [Nm//rad]' */
                          

	  
          

          
          
                  
          

                  real_T B_53_437_0; /* '<S88>/Main shaft  spring constant  K [Nm//rad]' */
                          

	  
          

          
          
                  
          

                  real_T B_53_439_0; /* '<S104>/Main shaft  spring constant  K [Nm//rad]' */
                          

	  
          

          
          
                  
          

                  real_T B_53_441_0; /* '<S120>/Main shaft  spring constant  K [Nm//rad]' */
                          

	  
          

          
          
                  
          

                  real_T B_53_443_0; /* '<S136>/Main shaft  spring constant  K [Nm//rad]' */
                          

	  
          

          
          
                  
          

                  real_T B_53_445_0; /* '<S152>/Main shaft  spring constant  K [Nm//rad]' */
                          

	  
          

          
          
                  
          

                  real_T B_53_447_0; /* '<S168>/Main shaft  spring constant  K [Nm//rad]' */
                          

	  
          

          
          
                  
          

                  real_T B_53_449_0; /* '<S40>/Main shaft  spring constant  K [Nm//rad]' */
                          

	  
          

          
          
                  
          

                  real_T B_53_452_0; /* '<S28>/F_t*h' */
                          

	  
          

          
          
                  
          

                  real_T B_53_453_0; /* '<S60>/F_t*h' */
                          

	  
          

          
          
                  
          

                  real_T B_53_454_0; /* '<S76>/F_t*h' */
                          

	  
          

          
          
                  
          

                  real_T B_53_455_0; /* '<S92>/F_t*h' */
                          

	  
          

          
          
                  
          

                  real_T B_53_456_0; /* '<S108>/F_t*h' */
                          

	  
          

          
          
                  
          

                  real_T B_53_457_0; /* '<S124>/F_t*h' */
                          

	  
          

          
          
                  
          

                  real_T B_53_458_0; /* '<S140>/F_t*h' */
                          

	  
          

          
          
                  
          

                  real_T B_53_459_0; /* '<S156>/F_t*h' */
                          

	  
          

          
          
                  
          

                  real_T B_53_460_0; /* '<S172>/F_t*h' */
                          

	  
          

          
          
                  
          

                  real_T B_53_461_0; /* '<S44>/F_t*h' */
                          

	  
          

          
          
                  
          

                  real_T B_53_467_0; /* '<S21>/Product' */
                          

	  
          

          
          
                  
          

                  real_T B_53_470_0; /* '<S11>/Constant2' */
                          

	  
          

          
          
                  
          

                  real_T B_53_475_0; /* '<S23>/Rated speed' */
                          

	  
          

          
          
                  
          

                  real_T B_53_480_0; /* '<S33>/Constant' */
                          

	  
          

          
          
                  
          

                  real_T B_53_483_0; /* '<S32>/Constant' */
                          

	  
          

          
          
                  
          

                  real_T B_53_492_0; /* '<S24>/Sum' */
                          

	  
          

          
          
                  
          

                  real_T B_53_497_0; /* '<S24>/Generator inertia' */
                          

	  
          

          
          
                  
          

                  real_T B_53_499_0; /* '<S24>/Rotor inertia' */
                          

	  
          

          
          
                  
          

                  real_T B_53_501_0; /* '<S11>/Switch2' */
                          

	  
          

          
          
                  
          

                  real_T B_53_504_0; /* '<S25>/Generator Time constant' */
                          

	  
          

          
          
                  
          

                  real_T B_53_505_0; /* '<S34>/Hydraulic delay time' */
                          

	  
          

          
          
                  
          

                  real_T B_53_506_0; /* '<S34>/Hydraulic  time constant' */
                          

	  
          

          
          
                  
          

                  real_T B_53_509_0; /* '<S35>/e.k' */
                          

	  
          

          
          
                  
          

                  real_T B_53_510_0; /* '<S27>/Balluf resolution' */
                          

	  
          

          
          
                  
          

                  real_T B_53_515_0; /* '<S27>/anemometer resolution' */
                          

	  
          

          
          
                  
          

                  real_T B_53_516_0; /* '<S27>/gen resolution' */
                          

	  
          

          
          
                  
          

                  real_T B_53_517_0; /* '<S27>/gen sensor time constant' */
                          

	  
          

          
          
                  
          

                  real_T B_53_518_0; /* '<S27>/gen sensor time constant1' */
                          

	  
          

          
          
                  
          

                  real_T B_53_519_0; /* '<S27>/rot resolution' */
                          

	  
          

          
          
                  
          

                  real_T B_53_523_0; /* '<S37>/Product' */
                          

	  
          

          
          
                  
          

                  real_T B_53_526_0; /* '<S12>/Constant2' */
                          

	  
          

          
          
                  
          

                  real_T B_53_531_0; /* '<S39>/Rated speed' */
                          

	  
          

          
          
                  
          

                  real_T B_53_536_0; /* '<S49>/Constant' */
                          

	  
          

          
          
                  
          

                  real_T B_53_539_0; /* '<S48>/Constant' */
                          

	  
          

          
          
                  
          

                  real_T B_53_548_0; /* '<S40>/Sum' */
                          

	  
          

          
          
                  
          

                  real_T B_53_553_0; /* '<S40>/Generator inertia' */
                          

	  
          

          
          
                  
          

                  real_T B_53_555_0; /* '<S40>/Rotor inertia' */
                          

	  
          

          
          
                  
          

                  real_T B_53_557_0; /* '<S12>/Switch2' */
                          

	  
          

          
          
                  
          

                  real_T B_53_560_0; /* '<S41>/Generator Time constant' */
                          

	  
          

          
          
                  
          

                  real_T B_53_561_0; /* '<S50>/Hydraulic delay time' */
                          

	  
          

          
          
                  
          

                  real_T B_53_562_0; /* '<S50>/Hydraulic  time constant' */
                          

	  
          

          
          
                  
          

                  real_T B_53_565_0; /* '<S51>/e.k' */
                          

	  
          

          
          
                  
          

                  real_T B_53_566_0; /* '<S43>/Balluf resolution' */
                          

	  
          

          
          
                  
          

                  real_T B_53_571_0; /* '<S43>/anemometer resolution' */
                          

	  
          

          
          
                  
          

                  real_T B_53_572_0; /* '<S43>/gen resolution' */
                          

	  
          

          
          
                  
          

                  real_T B_53_573_0; /* '<S43>/gen sensor time constant' */
                          

	  
          

          
          
                  
          

                  real_T B_53_574_0; /* '<S43>/gen sensor time constant1' */
                          

	  
          

          
          
                  
          

                  real_T B_53_575_0; /* '<S43>/rot resolution' */
                          

	  
          

          
          
                  
          

                  real_T B_53_579_0; /* '<S53>/Product' */
                          

	  
          

          
          
                  
          

                  real_T B_53_582_0; /* '<S13>/Constant2' */
                          

	  
          

          
          
                  
          

                  real_T B_53_587_0; /* '<S55>/Rated speed' */
                          

	  
          

          
          
                  
          

                  real_T B_53_592_0; /* '<S65>/Constant' */
                          

	  
          

          
          
                  
          

                  real_T B_53_595_0; /* '<S64>/Constant' */
                          

	  
          

          
          
                  
          

                  real_T B_53_604_0; /* '<S56>/Sum' */
                          

	  
          

          
          
                  
          

                  real_T B_53_609_0; /* '<S56>/Generator inertia' */
                          

	  
          

          
          
                  
          

                  real_T B_53_611_0; /* '<S56>/Rotor inertia' */
                          

	  
          

          
          
                  
          

                  real_T B_53_613_0; /* '<S13>/Switch2' */
                          

	  
          

          
          
                  
          

                  real_T B_53_616_0; /* '<S57>/Generator Time constant' */
                          

	  
          

          
          
                  
          

                  real_T B_53_617_0; /* '<S66>/Hydraulic delay time' */
                          

	  
          

          
          
                  
          

                  real_T B_53_618_0; /* '<S66>/Hydraulic  time constant' */
                          

	  
          

          
          
                  
          

                  real_T B_53_621_0; /* '<S67>/e.k' */
                          

	  
          

          
          
                  
          

                  real_T B_53_622_0; /* '<S59>/Balluf resolution' */
                          

	  
          

          
          
                  
          

                  real_T B_53_627_0; /* '<S59>/anemometer resolution' */
                          

	  
          

          
          
                  
          

                  real_T B_53_628_0; /* '<S59>/gen resolution' */
                          

	  
          

          
          
                  
          

                  real_T B_53_629_0; /* '<S59>/gen sensor time constant' */
                          

	  
          

          
          
                  
          

                  real_T B_53_630_0; /* '<S59>/gen sensor time constant1' */
                          

	  
          

          
          
                  
          

                  real_T B_53_631_0; /* '<S59>/rot resolution' */
                          

	  
          

          
          
                  
          

                  real_T B_53_635_0; /* '<S69>/Product' */
                          

	  
          

          
          
                  
          

                  real_T B_53_638_0; /* '<S14>/Constant2' */
                          

	  
          

          
          
                  
          

                  real_T B_53_643_0; /* '<S71>/Rated speed' */
                          

	  
          

          
          
                  
          

                  real_T B_53_648_0; /* '<S81>/Constant' */
                          

	  
          

          
          
                  
          

                  real_T B_53_651_0; /* '<S80>/Constant' */
                          

	  
          

          
          
                  
          

                  real_T B_53_660_0; /* '<S72>/Sum' */
                          

	  
          

          
          
                  
          

                  real_T B_53_665_0; /* '<S72>/Generator inertia' */
                          

	  
          

          
          
                  
          

                  real_T B_53_667_0; /* '<S72>/Rotor inertia' */
                          

	  
          

          
          
                  
          

                  real_T B_53_669_0; /* '<S14>/Switch2' */
                          

	  
          

          
          
                  
          

                  real_T B_53_672_0; /* '<S73>/Generator Time constant' */
                          

	  
          

          
          
                  
          

                  real_T B_53_673_0; /* '<S82>/Hydraulic delay time' */
                          

	  
          

          
          
                  
          

                  real_T B_53_674_0; /* '<S82>/Hydraulic  time constant' */
                          

	  
          

          
          
                  
          

                  real_T B_53_677_0; /* '<S83>/e.k' */
                          

	  
          

          
          
                  
          

                  real_T B_53_678_0; /* '<S75>/Balluf resolution' */
                          

	  
          

          
          
                  
          

                  real_T B_53_683_0; /* '<S75>/anemometer resolution' */
                          

	  
          

          
          
                  
          

                  real_T B_53_684_0; /* '<S75>/gen resolution' */
                          

	  
          

          
          
                  
          

                  real_T B_53_685_0; /* '<S75>/gen sensor time constant' */
                          

	  
          

          
          
                  
          

                  real_T B_53_686_0; /* '<S75>/gen sensor time constant1' */
                          

	  
          

          
          
                  
          

                  real_T B_53_687_0; /* '<S75>/rot resolution' */
                          

	  
          

          
          
                  
          

                  real_T B_53_691_0; /* '<S85>/Product' */
                          

	  
          

          
          
                  
          

                  real_T B_53_694_0; /* '<S15>/Constant2' */
                          

	  
          

          
          
                  
          

                  real_T B_53_699_0; /* '<S87>/Rated speed' */
                          

	  
          

          
          
                  
          

                  real_T B_53_704_0; /* '<S97>/Constant' */
                          

	  
          

          
          
                  
          

                  real_T B_53_707_0; /* '<S96>/Constant' */
                          

	  
          

          
          
                  
          

                  real_T B_53_716_0; /* '<S88>/Sum' */
                          

	  
          

          
          
                  
          

                  real_T B_53_721_0; /* '<S88>/Generator inertia' */
                          

	  
          

          
          
                  
          

                  real_T B_53_723_0; /* '<S88>/Rotor inertia' */
                          

	  
          

          
          
                  
          

                  real_T B_53_725_0; /* '<S15>/Switch2' */
                          

	  
          

          
          
                  
          

                  real_T B_53_728_0; /* '<S89>/Generator Time constant' */
                          

	  
          

          
          
                  
          

                  real_T B_53_729_0; /* '<S98>/Hydraulic delay time' */
                          

	  
          

          
          
                  
          

                  real_T B_53_730_0; /* '<S98>/Hydraulic  time constant' */
                          

	  
          

          
          
                  
          

                  real_T B_53_733_0; /* '<S99>/e.k' */
                          

	  
          

          
          
                  
          

                  real_T B_53_734_0; /* '<S91>/Balluf resolution' */
                          

	  
          

          
          
                  
          

                  real_T B_53_739_0; /* '<S91>/anemometer resolution' */
                          

	  
          

          
          
                  
          

                  real_T B_53_740_0; /* '<S91>/gen resolution' */
                          

	  
          

          
          
                  
          

                  real_T B_53_741_0; /* '<S91>/gen sensor time constant' */
                          

	  
          

          
          
                  
          

                  real_T B_53_742_0; /* '<S91>/gen sensor time constant1' */
                          

	  
          

          
          
                  
          

                  real_T B_53_743_0; /* '<S91>/rot resolution' */
                          

	  
          

          
          
                  
          

                  real_T B_53_747_0; /* '<S101>/Product' */
                          

	  
          

          
          
                  
          

                  real_T B_53_750_0; /* '<S16>/Constant2' */
                          

	  
          

          
          
                  
          

                  real_T B_53_755_0; /* '<S103>/Rated speed' */
                          

	  
          

          
          
                  
          

                  real_T B_53_760_0; /* '<S113>/Constant' */
                          

	  
          

          
          
                  
          

                  real_T B_53_763_0; /* '<S112>/Constant' */
                          

	  
          

          
          
                  
          

                  real_T B_53_772_0; /* '<S104>/Sum' */
                          

	  
          

          
          
                  
          

                  real_T B_53_777_0; /* '<S104>/Generator inertia' */
                          

	  
          

          
          
                  
          

                  real_T B_53_779_0; /* '<S104>/Rotor inertia' */
                          

	  
          

          
          
                  
          

                  real_T B_53_781_0; /* '<S16>/Switch2' */
                          

	  
          

          
          
                  
          

                  real_T B_53_784_0; /* '<S105>/Generator Time constant' */
                          

	  
          

          
          
                  
          

                  real_T B_53_785_0; /* '<S114>/Hydraulic delay time' */
                          

	  
          

          
          
                  
          

                  real_T B_53_786_0; /* '<S114>/Hydraulic  time constant' */
                          

	  
          

          
          
                  
          

                  real_T B_53_789_0; /* '<S115>/e.k' */
                          

	  
          

          
          
                  
          

                  real_T B_53_790_0; /* '<S107>/Balluf resolution' */
                          

	  
          

          
          
                  
          

                  real_T B_53_795_0; /* '<S107>/anemometer resolution' */
                          

	  
          

          
          
                  
          

                  real_T B_53_796_0; /* '<S107>/gen resolution' */
                          

	  
          

          
          
                  
          

                  real_T B_53_797_0; /* '<S107>/gen sensor time constant' */
                          

	  
          

          
          
                  
          

                  real_T B_53_798_0; /* '<S107>/gen sensor time constant1' */
                          

	  
          

          
          
                  
          

                  real_T B_53_799_0; /* '<S107>/rot resolution' */
                          

	  
          

          
          
                  
          

                  real_T B_53_803_0; /* '<S117>/Product' */
                          

	  
          

          
          
                  
          

                  real_T B_53_806_0; /* '<S17>/Constant2' */
                          

	  
          

          
          
                  
          

                  real_T B_53_811_0; /* '<S119>/Rated speed' */
                          

	  
          

          
          
                  
          

                  real_T B_53_816_0; /* '<S129>/Constant' */
                          

	  
          

          
          
                  
          

                  real_T B_53_819_0; /* '<S128>/Constant' */
                          

	  
          

          
          
                  
          

                  real_T B_53_828_0; /* '<S120>/Sum' */
                          

	  
          

          
          
                  
          

                  real_T B_53_833_0; /* '<S120>/Generator inertia' */
                          

	  
          

          
          
                  
          

                  real_T B_53_835_0; /* '<S120>/Rotor inertia' */
                          

	  
          

          
          
                  
          

                  real_T B_53_837_0; /* '<S17>/Switch2' */
                          

	  
          

          
          
                  
          

                  real_T B_53_840_0; /* '<S121>/Generator Time constant' */
                          

	  
          

          
          
                  
          

                  real_T B_53_841_0; /* '<S130>/Hydraulic delay time' */
                          

	  
          

          
          
                  
          

                  real_T B_53_842_0; /* '<S130>/Hydraulic  time constant' */
                          

	  
          

          
          
                  
          

                  real_T B_53_845_0; /* '<S131>/e.k' */
                          

	  
          

          
          
                  
          

                  real_T B_53_846_0; /* '<S123>/Balluf resolution' */
                          

	  
          

          
          
                  
          

                  real_T B_53_851_0; /* '<S123>/anemometer resolution' */
                          

	  
          

          
          
                  
          

                  real_T B_53_852_0; /* '<S123>/gen resolution' */
                          

	  
          

          
          
                  
          

                  real_T B_53_853_0; /* '<S123>/gen sensor time constant' */
                          

	  
          

          
          
                  
          

                  real_T B_53_854_0; /* '<S123>/gen sensor time constant1' */
                          

	  
          

          
          
                  
          

                  real_T B_53_855_0; /* '<S123>/rot resolution' */
                          

	  
          

          
          
                  
          

                  real_T B_53_859_0; /* '<S133>/Product' */
                          

	  
          

          
          
                  
          

                  real_T B_53_862_0; /* '<S18>/Constant2' */
                          

	  
          

          
          
                  
          

                  real_T B_53_867_0; /* '<S135>/Rated speed' */
                          

	  
          

          
          
                  
          

                  real_T B_53_872_0; /* '<S145>/Constant' */
                          

	  
          

          
          
                  
          

                  real_T B_53_875_0; /* '<S144>/Constant' */
                          

	  
          

          
          
                  
          

                  real_T B_53_884_0; /* '<S136>/Sum' */
                          

	  
          

          
          
                  
          

                  real_T B_53_889_0; /* '<S136>/Generator inertia' */
                          

	  
          

          
          
                  
          

                  real_T B_53_891_0; /* '<S136>/Rotor inertia' */
                          

	  
          

          
          
                  
          

                  real_T B_53_893_0; /* '<S18>/Switch2' */
                          

	  
          

          
          
                  
          

                  real_T B_53_896_0; /* '<S137>/Generator Time constant' */
                          

	  
          

          
          
                  
          

                  real_T B_53_897_0; /* '<S146>/Hydraulic delay time' */
                          

	  
          

          
          
                  
          

                  real_T B_53_898_0; /* '<S146>/Hydraulic  time constant' */
                          

	  
          

          
          
                  
          

                  real_T B_53_901_0; /* '<S147>/e.k' */
                          

	  
          

          
          
                  
          

                  real_T B_53_902_0; /* '<S139>/Balluf resolution' */
                          

	  
          

          
          
                  
          

                  real_T B_53_907_0; /* '<S139>/anemometer resolution' */
                          

	  
          

          
          
                  
          

                  real_T B_53_908_0; /* '<S139>/gen resolution' */
                          

	  
          

          
          
                  
          

                  real_T B_53_909_0; /* '<S139>/gen sensor time constant' */
                          

	  
          

          
          
                  
          

                  real_T B_53_910_0; /* '<S139>/gen sensor time constant1' */
                          

	  
          

          
          
                  
          

                  real_T B_53_911_0; /* '<S139>/rot resolution' */
                          

	  
          

          
          
                  
          

                  real_T B_53_915_0; /* '<S149>/Product' */
                          

	  
          

          
          
                  
          

                  real_T B_53_918_0; /* '<S19>/Constant2' */
                          

	  
          

          
          
                  
          

                  real_T B_53_923_0; /* '<S151>/Rated speed' */
                          

	  
          

          
          
                  
          

                  real_T B_53_928_0; /* '<S161>/Constant' */
                          

	  
          

          
          
                  
          

                  real_T B_53_931_0; /* '<S160>/Constant' */
                          

	  
          

          
          
                  
          

                  real_T B_53_940_0; /* '<S152>/Sum' */
                          

	  
          

          
          
                  
          

                  real_T B_53_945_0; /* '<S152>/Generator inertia' */
                          

	  
          

          
          
                  
          

                  real_T B_53_947_0; /* '<S152>/Rotor inertia' */
                          

	  
          

          
          
                  
          

                  real_T B_53_949_0; /* '<S19>/Switch2' */
                          

	  
          

          
          
                  
          

                  real_T B_53_952_0; /* '<S153>/Generator Time constant' */
                          

	  
          

          
          
                  
          

                  real_T B_53_953_0; /* '<S162>/Hydraulic delay time' */
                          

	  
          

          
          
                  
          

                  real_T B_53_954_0; /* '<S162>/Hydraulic  time constant' */
                          

	  
          

          
          
                  
          

                  real_T B_53_957_0; /* '<S163>/e.k' */
                          

	  
          

          
          
                  
          

                  real_T B_53_958_0; /* '<S155>/Balluf resolution' */
                          

	  
          

          
          
                  
          

                  real_T B_53_963_0; /* '<S155>/anemometer resolution' */
                          

	  
          

          
          
                  
          

                  real_T B_53_964_0; /* '<S155>/gen resolution' */
                          

	  
          

          
          
                  
          

                  real_T B_53_965_0; /* '<S155>/gen sensor time constant' */
                          

	  
          

          
          
                  
          

                  real_T B_53_966_0; /* '<S155>/gen sensor time constant1' */
                          

	  
          

          
          
                  
          

                  real_T B_53_967_0; /* '<S155>/rot resolution' */
                          

	  
          

          
          
                  
          

                  real_T B_53_971_0; /* '<S165>/Product' */
                          

	  
          

          
          
                  
          

                  real_T B_53_974_0; /* '<S20>/Constant2' */
                          

	  
          

          
          
                  
          

                  real_T B_53_979_0; /* '<S167>/Rated speed' */
                          

	  
          

          
          
                  
          

                  real_T B_53_984_0; /* '<S177>/Constant' */
                          

	  
          

          
          
                  
          

                  real_T B_53_987_0; /* '<S176>/Constant' */
                          

	  
          

          
          
                  
          

                  real_T B_53_996_0; /* '<S168>/Sum' */
                          

	  
          

          
          
                  
          

                  real_T B_53_1001_0; /* '<S168>/Generator inertia' */
                          

	  
          

          
          
                  
          

                  real_T B_53_1003_0; /* '<S168>/Rotor inertia' */
                          

	  
          

          
          
                  
          

                  real_T B_53_1005_0; /* '<S20>/Switch2' */
                          

	  
          

          
          
                  
          

                  real_T B_53_1008_0; /* '<S169>/Generator Time constant' */
                          

	  
          

          
          
                  
          

                  real_T B_53_1009_0; /* '<S178>/Hydraulic delay time' */
                          

	  
          

          
          
                  
          

                  real_T B_53_1010_0; /* '<S178>/Hydraulic  time constant' */
                          

	  
          

          
          
                  
          

                  real_T B_53_1013_0; /* '<S179>/e.k' */
                          

	  
          

          
          
                  
          

                  real_T B_53_1014_0; /* '<S171>/Balluf resolution' */
                          

	  
          

          
          
                  
          

                  real_T B_53_1019_0; /* '<S171>/anemometer resolution' */
                          

	  
          

          
          
                  
          

                  real_T B_53_1020_0; /* '<S171>/gen resolution' */
                          

	  
          

          
          
                  
          

                  real_T B_53_1021_0; /* '<S171>/gen sensor time constant' */
                          

	  
          

          
          
                  
          

                  real_T B_53_1022_0; /* '<S171>/gen sensor time constant1' */
                          

	  
          

          
          
                  
          

                  real_T B_53_1023_0; /* '<S171>/rot resolution' */
                          

	  
          

          
          
                  
          

                  real_T B_53_1033_0[226800]; /* '<S181>/Uy_full' */
                          

	  
          

          
          
                  
          

                  real_T B_53_1034_0[10]; /* '<S181>/Turb x' */
                          

	  
          

          
          
                  
          

                  real_T B_53_1037_0[200]; /* '<S183>/uyselector' */
                          

	  
          

          
          
                  
          

                  real_T B_53_1039_0[200]; /* '<S184>/uyselector' */
                          

	  
          

          
          
                  
          

                  real_T B_53_1041_0[200]; /* '<S185>/uyselector' */
                          

	  
          

          
          
                  
          

                  real_T B_53_1043_0[200]; /* '<S186>/uyselector' */
                          

	  
          

          
          
                  
          

                  real_T B_53_1045_0[200]; /* '<S187>/uyselector' */
                          

	  
          

          
          
                  
          

                  real_T B_53_1047_0[200]; /* '<S188>/uyselector' */
                          

	  
          

          
          
                  
          

                  real_T B_53_1049_0[200]; /* '<S189>/uyselector' */
                          

	  
          

          
          
                  
          

                  real_T B_53_1051_0[200]; /* '<S190>/uyselector' */
                          

	  
          

          
          
                  
          

                  real_T B_53_1053_0[200]; /* '<S191>/uyselector' */
                          

	  
          

          
          
                  
          

                  real_T B_53_1055_0[200]; /* '<S192>/uyselector' */
                          

	  
          

          
          
                  
          

                  real_T B_53_1097_0; /* '<Root>/Clock' */
                          

	  
          

          
          
                  
          

                  real_T B_52_0_1; /* '<S202>/Wind speed' */
                          

	  
          

          
          
                  
          

                  real_T B_52_0_2; /* '<S202>/Wind speed' */
                          

	  
          

          
          
                  
          

                  real_T B_51_0_1; /* '<S201>/Wind speed' */
                          

	  
          

          
          
                  
          

                  real_T B_51_0_2; /* '<S201>/Wind speed' */
                          

	  
          

          
          
                  
          

                  real_T B_50_0_1; /* '<S200>/Wind speed' */
                          

	  
          

          
          
                  
          

                  real_T B_50_0_2; /* '<S200>/Wind speed' */
                          

	  
          

          
          
                  
          

                  real_T B_49_0_1; /* '<S199>/Wind speed' */
                          

	  
          

          
          
                  
          

                  real_T B_49_0_2; /* '<S199>/Wind speed' */
                          

	  
          

          
          
                  
          

                  real_T B_48_0_1; /* '<S198>/Wind speed' */
                          

	  
          

          
          
                  
          

                  real_T B_48_0_2; /* '<S198>/Wind speed' */
                          

	  
          

          
          
                  
          

                  real_T B_47_0_1; /* '<S197>/Wind speed' */
                          

	  
          

          
          
                  
          

                  real_T B_47_0_2; /* '<S197>/Wind speed' */
                          

	  
          

          
          
                  
          

                  real_T B_46_0_1; /* '<S196>/Wind speed' */
                          

	  
          

          
          
                  
          

                  real_T B_46_0_2; /* '<S196>/Wind speed' */
                          

	  
          

          
          
                  
          

                  real_T B_45_0_1; /* '<S195>/Wind speed' */
                          

	  
          

          
          
                  
          

                  real_T B_45_0_2; /* '<S195>/Wind speed' */
                          

	  
          

          
          
                  
          

                  real_T B_44_0_1; /* '<S194>/Wind speed' */
                          

	  
          

          
          
                  
          

                  real_T B_44_0_2; /* '<S194>/Wind speed' */
                          

	  
          

          
          
                  
          

                  real_T B_43_0_1; /* '<S193>/Wind speed' */
                          

	  
          

          
          
                  
          

                  real_T B_43_0_2; /* '<S193>/Wind speed' */
                          

	  
          

          
          
                  
          

                  real_T B_42_0_1[10]; /* '<S192>/Wake center and diameter' */
                          

	  
          

          
          
                  
          

                  real_T B_42_0_2[10]; /* '<S192>/Wake center and diameter' */
                          

	  
          

          
          
                  
          

                  real_T B_41_0_1[10]; /* '<S191>/Wake center and diameter' */
                          

	  
          

          
          
                  
          

                  real_T B_41_0_2[10]; /* '<S191>/Wake center and diameter' */
                          

	  
          

          
          
                  
          

                  real_T B_40_0_1[10]; /* '<S190>/Wake center and diameter' */
                          

	  
          

          
          
                  
          

                  real_T B_40_0_2[10]; /* '<S190>/Wake center and diameter' */
                          

	  
          

          
          
                  
          

                  real_T B_39_0_1[10]; /* '<S189>/Wake center and diameter' */
                          

	  
          

          
          
                  
          

                  real_T B_39_0_2[10]; /* '<S189>/Wake center and diameter' */
                          

	  
          

          
          
                  
          

                  real_T B_38_0_1[10]; /* '<S188>/Wake center and diameter' */
                          

	  
          

          
          
                  
          

                  real_T B_38_0_2[10]; /* '<S188>/Wake center and diameter' */
                          

	  
          

          
          
                  
          

                  real_T B_37_0_1[10]; /* '<S187>/Wake center and diameter' */
                          

	  
          

          
          
                  
          

                  real_T B_37_0_2[10]; /* '<S187>/Wake center and diameter' */
                          

	  
          

          
          
                  
          

                  real_T B_36_0_1[10]; /* '<S186>/Wake center and diameter' */
                          

	  
          

          
          
                  
          

                  real_T B_36_0_2[10]; /* '<S186>/Wake center and diameter' */
                          

	  
          

          
          
                  
          

                  real_T B_35_0_1[10]; /* '<S185>/Wake center and diameter' */
                          

	  
          

          
          
                  
          

                  real_T B_35_0_2[10]; /* '<S185>/Wake center and diameter' */
                          

	  
          

          
          
                  
          

                  real_T B_34_0_1[10]; /* '<S184>/Wake center and diameter' */
                          

	  
          

          
          
                  
          

                  real_T B_34_0_2[10]; /* '<S184>/Wake center and diameter' */
                          

	  
          

          
          
                  
          

                  real_T B_33_0_1[10]; /* '<S183>/Wake center and diameter' */
                          

	  
          

          
          
                  
          

                  real_T B_33_0_2[10]; /* '<S183>/Wake center and diameter' */
                          

	  
          

          
          
                  
          

                  real_T B_32_0_1[10]; /* '<S7>/Deficit' */
                          

	  
          

          
          
                  
          

                  real_T B_1_0_1; /* '<S4>/Network Operator' */
                          

	  
          

          
          
                  
          

                  real_T B_0_0_1[10]; /* '<S1>/control' */
                          

	  
          

          
          
                  
          

                  real_T B_0_0_2; /* '<S1>/control' */
                          

	  
          

          
          
                  
          

                  real_T B_53_1036_0[2000]; /* '<S181>/Selector1' */
                          

	  
          

          
          
                  
          

                  real_T B_53_462_0[10]; /* '<S6>/CTrate7' */
                          

	  
          

          
          
                  
          

                  uint32_T B_53_1028_0; /* '<S204>/FixPt Constant' */
                          

	  
          

          
          
                  
          

                  uint32_T B_53_1031_0; /* '<S205>/Constant' */
                          

	  
          

          
          
                  
          

                  uint32_T B_53_1032_0; /* '<S205>/FixPt Switch' */
                          

	  
          

          
          
                  
          

                  uint32_T B_53_1057_0; /* '<S218>/FixPt Constant' */
                          

	  
          

          
          
                  
          

                  uint32_T B_53_1059_0; /* '<S219>/Constant' */
                          

	  
          

          
          
                  
          

                  uint32_T B_53_1060_0; /* '<S219>/FixPt Switch' */
                          

	  
          

          
          
                  
          

                  uint32_T B_53_1061_0; /* '<S222>/FixPt Constant' */
                          

	  
          

          
          
                  
          

                  uint32_T B_53_1063_0; /* '<S223>/Constant' */
                          

	  
          

          
          
                  
          

                  uint32_T B_53_1064_0; /* '<S223>/FixPt Switch' */
                          

	  
          

          
          
                  
          

                  uint32_T B_53_1065_0; /* '<S226>/FixPt Constant' */
                          

	  
          

          
          
                  
          

                  uint32_T B_53_1067_0; /* '<S227>/Constant' */
                          

	  
          

          
          
                  
          

                  uint32_T B_53_1068_0; /* '<S227>/FixPt Switch' */
                          

	  
          

          
          
                  
          

                  uint32_T B_53_1069_0; /* '<S230>/FixPt Constant' */
                          

	  
          

          
          
                  
          

                  uint32_T B_53_1071_0; /* '<S231>/Constant' */
                          

	  
          

          
          
                  
          

                  uint32_T B_53_1072_0; /* '<S231>/FixPt Switch' */
                          

	  
          

          
          
                  
          

                  uint32_T B_53_1073_0; /* '<S234>/FixPt Constant' */
                          

	  
          

          
          
                  
          

                  uint32_T B_53_1075_0; /* '<S235>/Constant' */
                          

	  
          

          
          
                  
          

                  uint32_T B_53_1076_0; /* '<S235>/FixPt Switch' */
                          

	  
          

          
          
                  
          

                  uint32_T B_53_1077_0; /* '<S238>/FixPt Constant' */
                          

	  
          

          
          
                  
          

                  uint32_T B_53_1079_0; /* '<S239>/Constant' */
                          

	  
          

          
          
                  
          

                  uint32_T B_53_1080_0; /* '<S239>/FixPt Switch' */
                          

	  
          

          
          
                  
          

                  uint32_T B_53_1081_0; /* '<S242>/FixPt Constant' */
                          

	  
          

          
          
                  
          

                  uint32_T B_53_1083_0; /* '<S243>/Constant' */
                          

	  
          

          
          
                  
          

                  uint32_T B_53_1084_0; /* '<S243>/FixPt Switch' */
                          

	  
          

          
          
                  
          

                  uint32_T B_53_1085_0; /* '<S246>/FixPt Constant' */
                          

	  
          

          
          
                  
          

                  uint32_T B_53_1087_0; /* '<S247>/Constant' */
                          

	  
          

          
          
                  
          

                  uint32_T B_53_1088_0; /* '<S247>/FixPt Switch' */
                          

	  
          

          
          
                  
          

                  uint32_T B_53_1089_0; /* '<S250>/FixPt Constant' */
                          

	  
          

          
          
                  
          

                  uint32_T B_53_1091_0; /* '<S251>/Constant' */
                          

	  
          

          
          
                  
          

                  uint32_T B_53_1092_0; /* '<S251>/FixPt Switch' */
                          

	  
          

          
          
                  
          

                  uint32_T B_53_1093_0; /* '<S254>/FixPt Constant' */
                          

	  
          

          
          
                  
          

                  uint32_T B_53_1095_0; /* '<S255>/Constant' */
                          

	  
          

          
          
                  
          

                  uint32_T B_53_1096_0; /* '<S255>/FixPt Switch' */
                          

	  
          

          
          
                  
          

                  boolean_T B_53_485_0; /* '<S31>/Enable Pitch control?' */
                          

	  
          

          
          
                  
          

                  boolean_T B_53_541_0; /* '<S47>/Enable Pitch control?' */
                          

	  
          

          
          
                  
          

                  boolean_T B_53_597_0; /* '<S63>/Enable Pitch control?' */
                          

	  
          

          
          
                  
          

                  boolean_T B_53_653_0; /* '<S79>/Enable Pitch control?' */
                          

	  
          

          
          
                  
          

                  boolean_T B_53_709_0; /* '<S95>/Enable Pitch control?' */
                          

	  
          

          
          
                  
          

                  boolean_T B_53_765_0; /* '<S111>/Enable Pitch control?' */
                          

	  
          

          
          
                  
          

                  boolean_T B_53_821_0; /* '<S127>/Enable Pitch control?' */
                          

	  
          

          
          
                  
          

                  boolean_T B_53_877_0; /* '<S143>/Enable Pitch control?' */
                          

	  
          

          
          
                  
          

                  boolean_T B_53_933_0; /* '<S159>/Enable Pitch control?' */
                          

	  
          

          
          
                  
          

                  boolean_T B_53_989_0; /* '<S175>/Enable Pitch control?' */
                          

	  
          

          
          
                  
          

                  char_T pad_B_53_989_0[2]; 
                          

	  
          
          
                  
          

                  B_Pitchcontroller_benchmark_no_taylor_T Pitchcontroller_c; /* '<S167>/B_44_120' */
                          

	  
          
          
                  
          

                  B_Pitchcontroller_benchmark_no_taylor_T Pitchcontroller_a2; /* '<S151>/B_44_113' */
                          

	  
          
          
                  
          

                  B_Pitchcontroller_benchmark_no_taylor_T Pitchcontroller_nb; /* '<S135>/B_44_106' */
                          

	  
          
          
                  
          

                  B_Pitchcontroller_benchmark_no_taylor_T Pitchcontroller_f; /* '<S119>/B_44_99' */
                          

	  
          
          
                  
          

                  B_Pitchcontroller_benchmark_no_taylor_T Pitchcontroller_p; /* '<S103>/B_44_92' */
                          

	  
          
          
                  
          

                  B_Pitchcontroller_benchmark_no_taylor_T Pitchcontroller_e; /* '<S87>/B_44_85' */
                          

	  
          
          
                  
          

                  B_Pitchcontroller_benchmark_no_taylor_T Pitchcontroller_i; /* '<S71>/B_44_78' */
                          

	  
          
          
                  
          

                  B_Pitchcontroller_benchmark_no_taylor_T Pitchcontroller_a; /* '<S55>/B_44_71' */
                          

	  
          
          
                  
          

                  B_Pitchcontroller_benchmark_no_taylor_T Pitchcontroller_n; /* '<S39>/B_44_64' */
                          

	  
          
          
                  
          

                  B_Pitchcontroller_benchmark_no_taylor_T Pitchcontroller; /* '<S23>/B_44_57' */
                          

	  
          




  
    } B_benchmark_no_taylor_T;
  

        
              
          /* Block states (auto storage) for system '<Root>' */
              
        
  
     typedef struct  {
  
  
          
          
                  
          

                  real_T wcDelay2_DSTATE[40]; /* '<S183>/wcDelay2' */
                          

	  
          

          
          
                  
          

                  real_T wcDelay3_DSTATE[80]; /* '<S183>/wcDelay3' */
                          

	  
          

          
          
                  
          

                  real_T wcDelay4_DSTATE[120]; /* '<S183>/wcDelay4' */
                          

	  
          

          
          
                  
          

                  real_T wcDelay5_DSTATE[20]; /* '<S183>/wcDelay5' */
                          

	  
          

          
          
                  
          

                  real_T wcDelay6_DSTATE[60]; /* '<S183>/wcDelay6' */
                          

	  
          

          
          
                  
          

                  real_T wcDelay7_DSTATE[100]; /* '<S183>/wcDelay7' */
                          

	  
          

          
          
                  
          

                  real_T wcDelay8_DSTATE[40]; /* '<S183>/wcDelay8' */
                          

	  
          

          
          
                  
          

                  real_T wcDelay9_DSTATE[80]; /* '<S183>/wcDelay9' */
                          

	  
          

          
          
                  
          

                  real_T wcDelay10_DSTATE[120]; /* '<S183>/wcDelay10' */
                          

	  
          

          
          
                  
          

                  real_T wcDelay3_DSTATE_g[40]; /* '<S185>/wcDelay3' */
                          

	  
          

          
          
                  
          

                  real_T wcDelay4_DSTATE_j[80]; /* '<S185>/wcDelay4' */
                          

	  
          

          
          
                  
          

                  real_T wcDelay6_DSTATE_i[20]; /* '<S185>/wcDelay6' */
                          

	  
          

          
          
                  
          

                  real_T wcDelay7_DSTATE_a[60]; /* '<S185>/wcDelay7' */
                          

	  
          

          
          
                  
          

                  real_T wcDelay9_DSTATE_c[40]; /* '<S185>/wcDelay9' */
                          

	  
          

          
          
                  
          

                  real_T wcDelay10_DSTATE_e[80]; /* '<S185>/wcDelay10' */
                          

	  
          

          
          
                  
          

                  real_T wcDelay4_DSTATE_g[40]; /* '<S186>/wcDelay4' */
                          

	  
          

          
          
                  
          

                  real_T wcDelay7_DSTATE_j[20]; /* '<S186>/wcDelay7' */
                          

	  
          

          
          
                  
          

                  real_T wcDelay10_DSTATE_f[40]; /* '<S186>/wcDelay10' */
                          

	  
          

          
          
                  
          

                  real_T wcDelay2_DSTATE_e[20]; /* '<S188>/wcDelay2' */
                          

	  
          

          
          
                  
          

                  real_T wcDelay3_DSTATE_gu[60]; /* '<S188>/wcDelay3' */
                          

	  
          

          
          
                  
          

                  real_T wcDelay4_DSTATE_e[100]; /* '<S188>/wcDelay4' */
                          

	  
          

          
          
                  
          

                  real_T wcDelay6_DSTATE_o[40]; /* '<S188>/wcDelay6' */
                          

	  
          

          
          
                  
          

                  real_T wcDelay7_DSTATE_az[80]; /* '<S188>/wcDelay7' */
                          

	  
          

          
          
                  
          

                  real_T wcDelay8_DSTATE_f[20]; /* '<S188>/wcDelay8' */
                          

	  
          

          
          
                  
          

                  real_T wcDelay9_DSTATE_n[60]; /* '<S188>/wcDelay9' */
                          

	  
          

          
          
                  
          

                  real_T wcDelay10_DSTATE_h[100]; /* '<S188>/wcDelay10' */
                          

	  
          

          
          
                  
          

                  real_T wcDelay3_DSTATE_p[20]; /* '<S189>/wcDelay3' */
                          

	  
          

          
          
                  
          

                  real_T wcDelay4_DSTATE_n[60]; /* '<S189>/wcDelay4' */
                          

	  
          

          
          
                  
          

                  real_T wcDelay7_DSTATE_l[40]; /* '<S189>/wcDelay7' */
                          

	  
          

          
          
                  
          

                  real_T wcDelay9_DSTATE_h[20]; /* '<S189>/wcDelay9' */
                          

	  
          

          
          
                  
          

                  real_T wcDelay10_DSTATE_o[60]; /* '<S189>/wcDelay10' */
                          

	  
          

          
          
                  
          

                  real_T wcDelay4_DSTATE_no[20]; /* '<S190>/wcDelay4' */
                          

	  
          

          
          
                  
          

                  real_T wcDelay10_DSTATE_i[20]; /* '<S190>/wcDelay10' */
                          

	  
          

          
          
                  
          

                  real_T wcDelay3_DSTATE_i[40]; /* '<S191>/wcDelay3' */
                          

	  
          

          
          
                  
          

                  real_T wcDelay4_DSTATE_o[80]; /* '<S191>/wcDelay4' */
                          

	  
          

          
          
                  
          

                  real_T wcDelay6_DSTATE_og[20]; /* '<S191>/wcDelay6' */
                          

	  
          

          
          
                  
          

                  real_T wcDelay7_DSTATE_an[60]; /* '<S191>/wcDelay7' */
                          

	  
          

          
          
                  
          

                  real_T wcDelay9_DSTATE_j[40]; /* '<S191>/wcDelay9' */
                          

	  
          

          
          
                  
          

                  real_T wcDelay10_DSTATE_g[80]; /* '<S191>/wcDelay10' */
                          

	  
          

          
          
                  
          

                  real_T wcDelay4_DSTATE_jo[40]; /* '<S192>/wcDelay4' */
                          

	  
          

          
          
                  
          

                  real_T wcDelay7_DSTATE_d[20]; /* '<S192>/wcDelay7' */
                          

	  
          

          
          
                  
          

                  real_T wcDelay10_DSTATE_ik[40]; /* '<S192>/wcDelay10' */
                          

	  
          

          
          
                  
          

                  real_T wdDelay2_DSTATE[40]; /* '<S183>/wdDelay2' */
                          

	  
          

          
          
                  
          

                  real_T wdDelay3_DSTATE[80]; /* '<S183>/wdDelay3' */
                          

	  
          

          
          
                  
          

                  real_T wdDelay4_DSTATE[120]; /* '<S183>/wdDelay4' */
                          

	  
          

          
          
                  
          

                  real_T wdDelay5_DSTATE[20]; /* '<S183>/wdDelay5' */
                          

	  
          

          
          
                  
          

                  real_T wdDelay6_DSTATE[60]; /* '<S183>/wdDelay6' */
                          

	  
          

          
          
                  
          

                  real_T wdDelay7_DSTATE[100]; /* '<S183>/wdDelay7' */
                          

	  
          

          
          
                  
          

                  real_T wdDelay8_DSTATE[40]; /* '<S183>/wdDelay8' */
                          

	  
          

          
          
                  
          

                  real_T wdDelay9_DSTATE[80]; /* '<S183>/wdDelay9' */
                          

	  
          

          
          
                  
          

                  real_T wdDelay10_DSTATE[120]; /* '<S183>/wdDelay10' */
                          

	  
          

          
          
                  
          

                  real_T wdDelay3_DSTATE_g[40]; /* '<S185>/wdDelay3' */
                          

	  
          

          
          
                  
          

                  real_T wdDelay4_DSTATE_g[80]; /* '<S185>/wdDelay4' */
                          

	  
          

          
          
                  
          

                  real_T wdDelay6_DSTATE_m[20]; /* '<S185>/wdDelay6' */
                          

	  
          

          
          
                  
          

                  real_T wdDelay7_DSTATE_n[60]; /* '<S185>/wdDelay7' */
                          

	  
          

          
          
                  
          

                  real_T wdDelay9_DSTATE_b[40]; /* '<S185>/wdDelay9' */
                          

	  
          

          
          
                  
          

                  real_T wdDelay10_DSTATE_a[80]; /* '<S185>/wdDelay10' */
                          

	  
          

          
          
                  
          

                  real_T wdDelay4_DSTATE_n[40]; /* '<S186>/wdDelay4' */
                          

	  
          

          
          
                  
          

                  real_T wdDelay7_DSTATE_e[20]; /* '<S186>/wdDelay7' */
                          

	  
          

          
          
                  
          

                  real_T wdDelay10_DSTATE_a3[40]; /* '<S186>/wdDelay10' */
                          

	  
          

          
          
                  
          

                  real_T wdDelay2_DSTATE_m[20]; /* '<S188>/wdDelay2' */
                          

	  
          

          
          
                  
          

                  real_T wdDelay3_DSTATE_k[60]; /* '<S188>/wdDelay3' */
                          

	  
          

          
          
                  
          

                  real_T wdDelay4_DSTATE_nd[100]; /* '<S188>/wdDelay4' */
                          

	  
          

          
          
                  
          

                  real_T wdDelay6_DSTATE_h[40]; /* '<S188>/wdDelay6' */
                          

	  
          

          
          
                  
          

                  real_T wdDelay7_DSTATE_h[80]; /* '<S188>/wdDelay7' */
                          

	  
          

          
          
                  
          

                  real_T wdDelay8_DSTATE_l[20]; /* '<S188>/wdDelay8' */
                          

	  
          

          
          
                  
          

                  real_T wdDelay9_DSTATE_k[60]; /* '<S188>/wdDelay9' */
                          

	  
          

          
          
                  
          

                  real_T wdDelay10_DSTATE_i[100]; /* '<S188>/wdDelay10' */
                          

	  
          

          
          
                  
          

                  real_T wdDelay3_DSTATE_a[20]; /* '<S189>/wdDelay3' */
                          

	  
          

          
          
                  
          

                  real_T wdDelay4_DSTATE_m[60]; /* '<S189>/wdDelay4' */
                          

	  
          

          
          
                  
          

                  real_T wdDelay7_DSTATE_a[40]; /* '<S189>/wdDelay7' */
                          

	  
          

          
          
                  
          

                  real_T wdDelay9_DSTATE_n[20]; /* '<S189>/wdDelay9' */
                          

	  
          

          
          
                  
          

                  real_T wdDelay10_DSTATE_aw[60]; /* '<S189>/wdDelay10' */
                          

	  
          

          
          
                  
          

                  real_T wdDelay4_DSTATE_e[20]; /* '<S190>/wdDelay4' */
                          

	  
          

          
          
                  
          

                  real_T wdDelay10_DSTATE_o[20]; /* '<S190>/wdDelay10' */
                          

	  
          

          
          
                  
          

                  real_T wdDelay3_DSTATE_j[40]; /* '<S191>/wdDelay3' */
                          

	  
          

          
          
                  
          

                  real_T wdDelay4_DSTATE_nw[80]; /* '<S191>/wdDelay4' */
                          

	  
          

          
          
                  
          

                  real_T wdDelay6_DSTATE_mj[20]; /* '<S191>/wdDelay6' */
                          

	  
          

          
          
                  
          

                  real_T wdDelay7_DSTATE_g[60]; /* '<S191>/wdDelay7' */
                          

	  
          

          
          
                  
          

                  real_T wdDelay9_DSTATE_m[40]; /* '<S191>/wdDelay9' */
                          

	  
          

          
          
                  
          

                  real_T wdDelay10_DSTATE_e[80]; /* '<S191>/wdDelay10' */
                          

	  
          

          
          
                  
          

                  real_T wdDelay4_DSTATE_b[40]; /* '<S192>/wdDelay4' */
                          

	  
          

          
          
                  
          

                  real_T wdDelay7_DSTATE_o[20]; /* '<S192>/wdDelay7' */
                          

	  
          

          
          
                  
          

                  real_T wdDelay10_DSTATE_g[40]; /* '<S192>/wdDelay10' */
                          

	  
          

          
          
                  
          

                  real_T ctDelay2_DSTATE[40]; /* '<S183>/ctDelay2' */
                          

	  
          

          
          
                  
          

                  real_T ctDelay3_DSTATE[80]; /* '<S183>/ctDelay3' */
                          

	  
          

          
          
                  
          

                  real_T ctDelay4_DSTATE[120]; /* '<S183>/ctDelay4' */
                          

	  
          

          
          
                  
          

                  real_T ctDelay5_DSTATE[20]; /* '<S183>/ctDelay5' */
                          

	  
          

          
          
                  
          

                  real_T ctDelay6_DSTATE[60]; /* '<S183>/ctDelay6' */
                          

	  
          

          
          
                  
          

                  real_T ctDelay7_DSTATE[100]; /* '<S183>/ctDelay7' */
                          

	  
          

          
          
                  
          

                  real_T ctDelay8_DSTATE[40]; /* '<S183>/ctDelay8' */
                          

	  
          

          
          
                  
          

                  real_T ctDelay9_DSTATE[80]; /* '<S183>/ctDelay9' */
                          

	  
          

          
          
                  
          

                  real_T ctDelay10_DSTATE[120]; /* '<S183>/ctDelay10' */
                          

	  
          

          
          
                  
          

                  real_T ctDelay3_DSTATE_l[40]; /* '<S185>/ctDelay3' */
                          

	  
          

          
          
                  
          

                  real_T ctDelay4_DSTATE_e[80]; /* '<S185>/ctDelay4' */
                          

	  
          

          
          
                  
          

                  real_T ctDelay6_DSTATE_k[20]; /* '<S185>/ctDelay6' */
                          

	  
          

          
          
                  
          

                  real_T ctDelay7_DSTATE_n[60]; /* '<S185>/ctDelay7' */
                          

	  
          

          
          
                  
          

                  real_T ctDelay9_DSTATE_k[40]; /* '<S185>/ctDelay9' */
                          

	  
          

          
          
                  
          

                  real_T ctDelay10_DSTATE_a[80]; /* '<S185>/ctDelay10' */
                          

	  
          

          
          
                  
          

                  real_T ctDelay4_DSTATE_er[40]; /* '<S186>/ctDelay4' */
                          

	  
          

          
          
                  
          

                  real_T ctDelay7_DSTATE_j[20]; /* '<S186>/ctDelay7' */
                          

	  
          

          
          
                  
          

                  real_T ctDelay10_DSTATE_p[40]; /* '<S186>/ctDelay10' */
                          

	  
          

          
          
                  
          

                  real_T ctDelay2_DSTATE_m[20]; /* '<S188>/ctDelay2' */
                          

	  
          

          
          
                  
          

                  real_T ctDelay3_DSTATE_k[60]; /* '<S188>/ctDelay3' */
                          

	  
          

          
          
                  
          

                  real_T ctDelay4_DSTATE_o[100]; /* '<S188>/ctDelay4' */
                          

	  
          

          
          
                  
          

                  real_T ctDelay6_DSTATE_f[40]; /* '<S188>/ctDelay6' */
                          

	  
          

          
          
                  
          

                  real_T ctDelay7_DSTATE_d[80]; /* '<S188>/ctDelay7' */
                          

	  
          

          
          
                  
          

                  real_T ctDelay8_DSTATE_e[20]; /* '<S188>/ctDelay8' */
                          

	  
          

          
          
                  
          

                  real_T ctDelay9_DSTATE_a[60]; /* '<S188>/ctDelay9' */
                          

	  
          

          
          
                  
          

                  real_T ctDelay10_DSTATE_d[100]; /* '<S188>/ctDelay10' */
                          

	  
          

          
          
                  
          

                  real_T ctDelay3_DSTATE_j[20]; /* '<S189>/ctDelay3' */
                          

	  
          

          
          
                  
          

                  real_T ctDelay4_DSTATE_c[60]; /* '<S189>/ctDelay4' */
                          

	  
          

          
          
                  
          

                  real_T ctDelay7_DSTATE_m[40]; /* '<S189>/ctDelay7' */
                          

	  
          

          
          
                  
          

                  real_T ctDelay9_DSTATE_n[20]; /* '<S189>/ctDelay9' */
                          

	  
          

          
          
                  
          

                  real_T ctDelay10_DSTATE_j[60]; /* '<S189>/ctDelay10' */
                          

	  
          

          
          
                  
          

                  real_T ctDelay4_DSTATE_ob[20]; /* '<S190>/ctDelay4' */
                          

	  
          

          
          
                  
          

                  real_T ctDelay10_DSTATE_d2[20]; /* '<S190>/ctDelay10' */
                          

	  
          

          
          
                  
          

                  real_T ctDelay3_DSTATE_d[40]; /* '<S191>/ctDelay3' */
                          

	  
          

          
          
                  
          

                  real_T ctDelay4_DSTATE_i[80]; /* '<S191>/ctDelay4' */
                          

	  
          

          
          
                  
          

                  real_T ctDelay6_DSTATE_n[20]; /* '<S191>/ctDelay6' */
                          

	  
          

          
          
                  
          

                  real_T ctDelay7_DSTATE_f[60]; /* '<S191>/ctDelay7' */
                          

	  
          

          
          
                  
          

                  real_T ctDelay9_DSTATE_f[40]; /* '<S191>/ctDelay9' */
                          

	  
          

          
          
                  
          

                  real_T ctDelay10_DSTATE_h[80]; /* '<S191>/ctDelay10' */
                          

	  
          

          
          
                  
          

                  real_T ctDelay4_DSTATE_m[40]; /* '<S192>/ctDelay4' */
                          

	  
          

          
          
                  
          

                  real_T ctDelay7_DSTATE_db[20]; /* '<S192>/ctDelay7' */
                          

	  
          

          
          
                  
          

                  real_T ctDelay10_DSTATE_b[40]; /* '<S192>/ctDelay10' */
                          

	  
          

          
          
                  
          

                  real_T UnitDelay_DSTATE; /* '<S4>/Unit Delay' */
                          

	  
          

          
          
                  
          

                  real_T Measurementfilterlowpass_DSTATE; /* '<S23>/Measurement filter (low pass)' */
                          

	  
          

          
          
                  
          

                  real_T IntegerDelay_DSTATE; /* '<S31>/Integer Delay' */
                          

	  
          

          
          
                  
          

                  real_T Measurementfilterlowpass_DSTATE_i; /* '<S39>/Measurement filter (low pass)' */
                          

	  
          

          
          
                  
          

                  real_T IntegerDelay_DSTATE_i; /* '<S47>/Integer Delay' */
                          

	  
          

          
          
                  
          

                  real_T Measurementfilterlowpass_DSTATE_j; /* '<S55>/Measurement filter (low pass)' */
                          

	  
          

          
          
                  
          

                  real_T IntegerDelay_DSTATE_c; /* '<S63>/Integer Delay' */
                          

	  
          

          
          
                  
          

                  real_T Measurementfilterlowpass_DSTATE_a; /* '<S71>/Measurement filter (low pass)' */
                          

	  
          

          
          
                  
          

                  real_T IntegerDelay_DSTATE_f; /* '<S79>/Integer Delay' */
                          

	  
          

          
          
                  
          

                  real_T Measurementfilterlowpass_DSTATE_e; /* '<S87>/Measurement filter (low pass)' */
                          

	  
          

          
          
                  
          

                  real_T IntegerDelay_DSTATE_l; /* '<S95>/Integer Delay' */
                          

	  
          

          
          
                  
          

                  real_T Measurementfilterlowpass_DSTATE_c; /* '<S103>/Measurement filter (low pass)' */
                          

	  
          

          
          
                  
          

                  real_T IntegerDelay_DSTATE_j; /* '<S111>/Integer Delay' */
                          

	  
          

          
          
                  
          

                  real_T Measurementfilterlowpass_DSTATE_ja; /* '<S119>/Measurement filter (low pass)' */
                          

	  
          

          
          
                  
          

                  real_T IntegerDelay_DSTATE_n; /* '<S127>/Integer Delay' */
                          

	  
          

          
          
                  
          

                  real_T Measurementfilterlowpass_DSTATE_aq; /* '<S135>/Measurement filter (low pass)' */
                          

	  
          

          
          
                  
          

                  real_T IntegerDelay_DSTATE_e; /* '<S143>/Integer Delay' */
                          

	  
          

          
          
                  
          

                  real_T Measurementfilterlowpass_DSTATE_k; /* '<S151>/Measurement filter (low pass)' */
                          

	  
          

          
          
                  
          

                  real_T IntegerDelay_DSTATE_id; /* '<S159>/Integer Delay' */
                          

	  
          

          
          
                  
          

                  real_T Measurementfilterlowpass_DSTATE_k1; /* '<S167>/Measurement filter (low pass)' */
                          

	  
          

          
          
                  
          

                  real_T IntegerDelay_DSTATE_fg; /* '<S175>/Integer Delay' */
                          

	  
          

          
          
                  
          

                  real_T CTrate1_Buffer0[10]; /* '<S6>/CTrate1' */
                          

	  
          

          
          
                  
          

                  real_T CTrate_Buffer0[10]; /* '<S6>/CTrate' */
                          

	  
          

          
          
                  
          

                  real_T CTrate2_Buffer0[10]; /* '<S6>/CTrate2' */
                          

	  
          

          
          
                  
          

                  real_T CTrate3_Buffer0[10]; /* '<S6>/CTrate3' */
                          

	  
          

          
          
                  
          

                  real_T CTrate4_Buffer0[10]; /* '<S6>/CTrate4' */
                          

	  
          

          
          
                  
          

                  real_T CTrate5_Buffer0[10]; /* '<S6>/CTrate5' */
                          

	  
          

          
          
                  
          

                  real_T CTrate6_Buffer0[10]; /* '<S6>/CTrate6' */
                          

	  
          

          
          
                  
          

                  real_T CTrate7_Buffer0[10]; /* '<S6>/CTrate7' */
                          

	  
          

          
          
                  
          

                  real_T PrevY; /* '<S23>/Rate Limiter' */
                          

	  
          

          
          
                  
          

                  real_T PrevY_k; /* '<S39>/Rate Limiter' */
                          

	  
          

          
          
                  
          

                  real_T PrevY_h; /* '<S55>/Rate Limiter' */
                          

	  
          

          
          
                  
          

                  real_T PrevY_i; /* '<S71>/Rate Limiter' */
                          

	  
          

          
          
                  
          

                  real_T PrevY_n; /* '<S87>/Rate Limiter' */
                          

	  
          

          
          
                  
          

                  real_T PrevY_f; /* '<S103>/Rate Limiter' */
                          

	  
          

          
          
                  
          

                  real_T PrevY_j; /* '<S119>/Rate Limiter' */
                          

	  
          

          
          
                  
          

                  real_T PrevY_nx; /* '<S135>/Rate Limiter' */
                          

	  
          

          
          
                  
          

                  real_T PrevY_h5; /* '<S151>/Rate Limiter' */
                          

	  
          

          
          
                  
          

                  real_T PrevY_m; /* '<S167>/Rate Limiter' */
                          

	  
          

          
          
                  
          

                  real_T Sum_DWORK1[10]; /* '<S181>/Sum' */
                          

	  
          

          
          
                  
                      struct {
        real_T modelTStart;
    } ComputationDelay_RWORK; /* '<S27>/Computation Delay' */


	  
          

          
          
                  
                      struct {
        real_T modelTStart;
    } ComputationDelay_RWORK_i; /* '<S59>/Computation Delay' */


	  
          

          
          
                  
                      struct {
        real_T modelTStart;
    } ComputationDelay_RWORK_h; /* '<S75>/Computation Delay' */


	  
          

          
          
                  
                      struct {
        real_T modelTStart;
    } ComputationDelay_RWORK_p; /* '<S91>/Computation Delay' */


	  
          

          
          
                  
                      struct {
        real_T modelTStart;
    } ComputationDelay_RWORK_pu; /* '<S107>/Computation Delay' */


	  
          

          
          
                  
                      struct {
        real_T modelTStart;
    } ComputationDelay_RWORK_f; /* '<S123>/Computation Delay' */


	  
          

          
          
                  
                      struct {
        real_T modelTStart;
    } ComputationDelay_RWORK_fv; /* '<S139>/Computation Delay' */


	  
          

          
          
                  
                      struct {
        real_T modelTStart;
    } ComputationDelay_RWORK_d; /* '<S155>/Computation Delay' */


	  
          

          
          
                  
                      struct {
        real_T modelTStart;
    } ComputationDelay_RWORK_dz; /* '<S171>/Computation Delay' */


	  
          

          
          
                  
                      struct {
        real_T modelTStart;
    } ComputationDelay_RWORK_g; /* '<S43>/Computation Delay' */


	  
          

          
          
                  
                      struct {
        real_T modelTStart;
    } Referencedelay_RWORK; /* '<S4>/Reference delay' */


	  
          

          
          
                  
                      struct {
        real_T modelTStart;
    } F_measdelay_RWORK; /* '<S4>/F_meas delay' */


	  
          

          
          
                  
                      struct {
        real_T modelTStart;
    } Pmeasdelay_RWORK; /* '<S4>/P meas delay' */


	  
          

          
          
                  
                      struct {
        real_T modelTStart;
    } Hydraulicdelaytime_RWORK; /* '<S34>/Hydraulic delay time' */


	  
          

          
          
                  
                      struct {
        real_T modelTStart;
    } Hydraulicdelaytime_RWORK_h; /* '<S50>/Hydraulic delay time' */


	  
          

          
          
                  
                      struct {
        real_T modelTStart;
    } Hydraulicdelaytime_RWORK_k; /* '<S66>/Hydraulic delay time' */


	  
          

          
          
                  
                      struct {
        real_T modelTStart;
    } Hydraulicdelaytime_RWORK_l; /* '<S82>/Hydraulic delay time' */


	  
          

          
          
                  
                      struct {
        real_T modelTStart;
    } Hydraulicdelaytime_RWORK_ks; /* '<S98>/Hydraulic delay time' */


	  
          

          
          
                  
                      struct {
        real_T modelTStart;
    } Hydraulicdelaytime_RWORK_p; /* '<S114>/Hydraulic delay time' */


	  
          

          
          
                  
                      struct {
        real_T modelTStart;
    } Hydraulicdelaytime_RWORK_j; /* '<S130>/Hydraulic delay time' */


	  
          

          
          
                  
                      struct {
        real_T modelTStart;
    } Hydraulicdelaytime_RWORK_f; /* '<S146>/Hydraulic delay time' */


	  
          

          
          
                  
                      struct {
        real_T modelTStart;
    } Hydraulicdelaytime_RWORK_g; /* '<S162>/Hydraulic delay time' */


	  
          

          
          
                  
                      struct {
        real_T modelTStart;
    } Hydraulicdelaytime_RWORK_b; /* '<S178>/Hydraulic delay time' */


	  
          

          
          
                  
                      struct {
        void *TUbufferPtrs[8];
    } ComputationDelay_PWORK; /* '<S27>/Computation Delay' */


	  
          

          
          
                  
                      struct {
        void *TUbufferPtrs[8];
    } ComputationDelay_PWORK_h; /* '<S59>/Computation Delay' */


	  
          

          
          
                  
                      struct {
        void *TUbufferPtrs[8];
    } ComputationDelay_PWORK_a; /* '<S75>/Computation Delay' */


	  
          

          
          
                  
                      struct {
        void *TUbufferPtrs[8];
    } ComputationDelay_PWORK_g; /* '<S91>/Computation Delay' */


	  
          

          
          
                  
                      struct {
        void *TUbufferPtrs[8];
    } ComputationDelay_PWORK_j; /* '<S107>/Computation Delay' */


	  
          

          
          
                  
                      struct {
        void *TUbufferPtrs[8];
    } ComputationDelay_PWORK_d; /* '<S123>/Computation Delay' */


	  
          

          
          
                  
                      struct {
        void *TUbufferPtrs[8];
    } ComputationDelay_PWORK_o; /* '<S139>/Computation Delay' */


	  
          

          
          
                  
                      struct {
        void *TUbufferPtrs[8];
    } ComputationDelay_PWORK_al; /* '<S155>/Computation Delay' */


	  
          

          
          
                  
                      struct {
        void *TUbufferPtrs[8];
    } ComputationDelay_PWORK_ds; /* '<S171>/Computation Delay' */


	  
          

          
          
                  
                      struct {
        void *TUbufferPtrs[8];
    } ComputationDelay_PWORK_dy; /* '<S43>/Computation Delay' */


	  
          

          
          
                  
                      struct {
        void *TUbufferPtrs[2];
    } Referencedelay_PWORK; /* '<S4>/Reference delay' */


	  
          

          
          
                  
                        void *HiddenToWks_InsertedFor_FarmControl_at_outport_0_PWORK;    /* synthesized block */


	  
          

          
          
                  
                        void *HiddenToWks_InsertedFor_FarmControl_at_outport_1_PWORK;    /* synthesized block */


	  
          

          
          
                  
                        void *HiddenToWks_InsertedFor_Grid_at_outport_0_PWORK;    /* synthesized block */


	  
          

          
          
                  
                        void *FromWs_PWORK[3];    /* '<S9>/FromWs' */


	  
          

          
          
                  
                        void *HiddenToWks_InsertedFor_NetworkLoad_at_outport_0_PWORK;    /* synthesized block */


	  
          

          
          
                  
                        void *HiddenToWks_InsertedFor_NetworkOperator_at_outport_0_PWORK;    /* synthesized block */


	  
          

          
          
                  
                        void *HiddenToWks_InsertedFor_Totalpower_at_outport_0_PWORK;    /* synthesized block */


	  
          

          
          
                  
                        void *HiddenToWks_InsertedFor_Turbines_at_outport_0_PWORK;    /* synthesized block */


	  
          

          
          
                  
                        void *HiddenToWks_InsertedFor_Turbines_at_outport_1_PWORK;    /* synthesized block */


	  
          

          
          
                  
                        void *HiddenToWks_InsertedFor_Turbines_at_outport_2_PWORK;    /* synthesized block */


	  
          

          
          
                  
                        void *HiddenToWks_InsertedFor_Turbines_at_outport_3_PWORK;    /* synthesized block */


	  
          

          
          
                  
                        void *HiddenToWks_InsertedFor_Turbines_at_outport_4_PWORK;    /* synthesized block */


	  
          

          
          
                  
                        void *HiddenToWks_InsertedFor_Turbines_at_outport_5_PWORK;    /* synthesized block */


	  
          

          
          
                  
                        void *HiddenToWks_InsertedFor_WindField_at_outport_0_PWORK;    /* synthesized block */


	  
          

          
          
                  
                        void *HiddenToWks_InsertedFor_WindField_at_outport_1_PWORK;    /* synthesized block */


	  
          

          
          
                  
                        void *Scope_PWORK;    /* '<Root>/Scope' */


	  
          

          
          
                  
                      struct {
        void *TUbufferPtrs[2];
    } F_measdelay_PWORK; /* '<S4>/F_meas delay' */


	  
          

          
          
                  
                      struct {
        void *TUbufferPtrs[2];
    } Pmeasdelay_PWORK; /* '<S4>/P meas delay' */


	  
          

          
          
                  
                        void *HiddenToWks_InsertedFor_CTrate6_at_outport_0_PWORK;    /* synthesized block */


	  
          

          
          
                  
                        void *HiddenToWks_InsertedFor_CTrate7_at_outport_0_PWORK;    /* synthesized block */


	  
          

          
          
                  
                      struct {
        void *TUbufferPtrs[2];
    } Hydraulicdelaytime_PWORK; /* '<S34>/Hydraulic delay time' */


	  
          

          
          
                  
                      struct {
        void *TUbufferPtrs[2];
    } Hydraulicdelaytime_PWORK_f; /* '<S50>/Hydraulic delay time' */


	  
          

          
          
                  
                      struct {
        void *TUbufferPtrs[2];
    } Hydraulicdelaytime_PWORK_n; /* '<S66>/Hydraulic delay time' */


	  
          

          
          
                  
                      struct {
        void *TUbufferPtrs[2];
    } Hydraulicdelaytime_PWORK_m; /* '<S82>/Hydraulic delay time' */


	  
          

          
          
                  
                      struct {
        void *TUbufferPtrs[2];
    } Hydraulicdelaytime_PWORK_k; /* '<S98>/Hydraulic delay time' */


	  
          

          
          
                  
                      struct {
        void *TUbufferPtrs[2];
    } Hydraulicdelaytime_PWORK_m0; /* '<S114>/Hydraulic delay time' */


	  
          

          
          
                  
                      struct {
        void *TUbufferPtrs[2];
    } Hydraulicdelaytime_PWORK_fg; /* '<S130>/Hydraulic delay time' */


	  
          

          
          
                  
                      struct {
        void *TUbufferPtrs[2];
    } Hydraulicdelaytime_PWORK_h; /* '<S146>/Hydraulic delay time' */


	  
          

          
          
                  
                      struct {
        void *TUbufferPtrs[2];
    } Hydraulicdelaytime_PWORK_d; /* '<S162>/Hydraulic delay time' */


	  
          

          
          
                  
                      struct {
        void *TUbufferPtrs[2];
    } Hydraulicdelaytime_PWORK_a; /* '<S178>/Hydraulic delay time' */


	  
          

          
          
                  
                        void *HiddenToWks_InsertedFor_Deficit_at_outport_0_PWORK;    /* synthesized block */


	  
          

          
          
                  
                        void *HiddenToWks_InsertedFor_ctconcat_at_outport_0_PWORK;    /* synthesized block */


	  
          

          
          
                  
                        void *HiddenToWks_InsertedFor_wcconcat_at_outport_0_PWORK;    /* synthesized block */


	  
          

          
          
                  
                        void *HiddenToWks_InsertedFor_wdconcat_at_outport_0_PWORK;    /* synthesized block */


	  
          

          
          
                  
          

                  uint32_T Output_DSTATE; /* '<S216>/Output' */
                          

	  
          

          
          
                  
          

                  uint32_T Output_DSTATE_g; /* '<S224>/Output' */
                          

	  
          

          
          
                  
          

                  uint32_T Output_DSTATE_d; /* '<S228>/Output' */
                          

	  
          

          
          
                  
          

                  uint32_T Output_DSTATE_n; /* '<S232>/Output' */
                          

	  
          

          
          
                  
          

                  uint32_T Output_DSTATE_h; /* '<S236>/Output' */
                          

	  
          

          
          
                  
          

                  uint32_T Output_DSTATE_e; /* '<S240>/Output' */
                          

	  
          

          
          
                  
          

                  uint32_T Output_DSTATE_db; /* '<S244>/Output' */
                          

	  
          

          
          
                  
          

                  uint32_T Output_DSTATE_o; /* '<S248>/Output' */
                          

	  
          

          
          
                  
          

                  uint32_T Output_DSTATE_d4; /* '<S252>/Output' */
                          

	  
          

          
          
                  
          

                  uint32_T Output_DSTATE_es; /* '<S220>/Output' */
                          

	  
          

          
          
                  
          

                  uint32_T Output_DSTATE_ej; /* '<S203>/Output' */
                          

	  
          

          
          
                  
                      struct {
        int_T Tail[4];
        int_T Head[4];
        int_T Last[4];
        int_T CircularBufSize[4];
        int_T MaxNewBufSize;
    } ComputationDelay_IWORK; /* '<S27>/Computation Delay' */


	  
          

          
          
                  
                      struct {
        int_T Tail[4];
        int_T Head[4];
        int_T Last[4];
        int_T CircularBufSize[4];
        int_T MaxNewBufSize;
    } ComputationDelay_IWORK_k; /* '<S59>/Computation Delay' */


	  
          

          
          
                  
                      struct {
        int_T Tail[4];
        int_T Head[4];
        int_T Last[4];
        int_T CircularBufSize[4];
        int_T MaxNewBufSize;
    } ComputationDelay_IWORK_b; /* '<S75>/Computation Delay' */


	  
          

          
          
                  
                      struct {
        int_T Tail[4];
        int_T Head[4];
        int_T Last[4];
        int_T CircularBufSize[4];
        int_T MaxNewBufSize;
    } ComputationDelay_IWORK_e; /* '<S91>/Computation Delay' */


	  
          

          
          
                  
                      struct {
        int_T Tail[4];
        int_T Head[4];
        int_T Last[4];
        int_T CircularBufSize[4];
        int_T MaxNewBufSize;
    } ComputationDelay_IWORK_h; /* '<S107>/Computation Delay' */


	  
          

          
          
                  
                      struct {
        int_T Tail[4];
        int_T Head[4];
        int_T Last[4];
        int_T CircularBufSize[4];
        int_T MaxNewBufSize;
    } ComputationDelay_IWORK_d; /* '<S123>/Computation Delay' */


	  
          

          
          
                  
                      struct {
        int_T Tail[4];
        int_T Head[4];
        int_T Last[4];
        int_T CircularBufSize[4];
        int_T MaxNewBufSize;
    } ComputationDelay_IWORK_i; /* '<S139>/Computation Delay' */


	  
          

          
          
                  
                      struct {
        int_T Tail[4];
        int_T Head[4];
        int_T Last[4];
        int_T CircularBufSize[4];
        int_T MaxNewBufSize;
    } ComputationDelay_IWORK_m; /* '<S155>/Computation Delay' */


	  
          

          
          
                  
                      struct {
        int_T Tail[4];
        int_T Head[4];
        int_T Last[4];
        int_T CircularBufSize[4];
        int_T MaxNewBufSize;
    } ComputationDelay_IWORK_ez; /* '<S171>/Computation Delay' */


	  
          

          
          
                  
                      struct {
        int_T Tail[4];
        int_T Head[4];
        int_T Last[4];
        int_T CircularBufSize[4];
        int_T MaxNewBufSize;
    } ComputationDelay_IWORK_e0; /* '<S43>/Computation Delay' */


	  
          

          
          
                  
                      struct {
        int_T Tail;
        int_T Head;
        int_T Last;
        int_T CircularBufSize;
        int_T MaxNewBufSize;
    } Referencedelay_IWORK; /* '<S4>/Reference delay' */


	  
          

          
          
                  
          

                  int_T FromWs_ZCTimeIndices[4]; /* '<S9>/FromWs' */
                          

	  
          

          
          
                  
          

                  int_T FromWs_CurZCTimeIndIdx; /* '<S9>/FromWs' */
                          

	  
          

          
          
                  
                        int_T FromWs_IWORK;    /* '<S9>/FromWs' */


	  
          

          
          
                  
                      struct {
        int_T Tail;
        int_T Head;
        int_T Last;
        int_T CircularBufSize;
        int_T MaxNewBufSize;
    } F_measdelay_IWORK; /* '<S4>/F_meas delay' */


	  
          

          
          
                  
                      struct {
        int_T Tail;
        int_T Head;
        int_T Last;
        int_T CircularBufSize;
        int_T MaxNewBufSize;
    } Pmeasdelay_IWORK; /* '<S4>/P meas delay' */


	  
          

          
          
                  
                      struct {
        int_T Tail;
        int_T Head;
        int_T Last;
        int_T CircularBufSize;
        int_T MaxNewBufSize;
    } Hydraulicdelaytime_IWORK; /* '<S34>/Hydraulic delay time' */


	  
          

          
          
                  
                      struct {
        int_T Tail;
        int_T Head;
        int_T Last;
        int_T CircularBufSize;
        int_T MaxNewBufSize;
    } Hydraulicdelaytime_IWORK_m; /* '<S50>/Hydraulic delay time' */


	  
          

          
          
                  
                      struct {
        int_T Tail;
        int_T Head;
        int_T Last;
        int_T CircularBufSize;
        int_T MaxNewBufSize;
    } Hydraulicdelaytime_IWORK_a; /* '<S66>/Hydraulic delay time' */


	  
          

          
          
                  
                      struct {
        int_T Tail;
        int_T Head;
        int_T Last;
        int_T CircularBufSize;
        int_T MaxNewBufSize;
    } Hydraulicdelaytime_IWORK_c; /* '<S82>/Hydraulic delay time' */


	  
          

          
          
                  
                      struct {
        int_T Tail;
        int_T Head;
        int_T Last;
        int_T CircularBufSize;
        int_T MaxNewBufSize;
    } Hydraulicdelaytime_IWORK_e; /* '<S98>/Hydraulic delay time' */


	  
          

          
          
                  
                      struct {
        int_T Tail;
        int_T Head;
        int_T Last;
        int_T CircularBufSize;
        int_T MaxNewBufSize;
    } Hydraulicdelaytime_IWORK_o; /* '<S114>/Hydraulic delay time' */


	  
          

          
          
                  
                      struct {
        int_T Tail;
        int_T Head;
        int_T Last;
        int_T CircularBufSize;
        int_T MaxNewBufSize;
    } Hydraulicdelaytime_IWORK_n; /* '<S130>/Hydraulic delay time' */


	  
          

          
          
                  
                      struct {
        int_T Tail;
        int_T Head;
        int_T Last;
        int_T CircularBufSize;
        int_T MaxNewBufSize;
    } Hydraulicdelaytime_IWORK_b; /* '<S146>/Hydraulic delay time' */


	  
          

          
          
                  
                      struct {
        int_T Tail;
        int_T Head;
        int_T Last;
        int_T CircularBufSize;
        int_T MaxNewBufSize;
    } Hydraulicdelaytime_IWORK_h; /* '<S162>/Hydraulic delay time' */


	  
          

          
          
                  
                      struct {
        int_T Tail;
        int_T Head;
        int_T Last;
        int_T CircularBufSize;
        int_T MaxNewBufSize;
    } Hydraulicdelaytime_IWORK_mc; /* '<S178>/Hydraulic delay time' */


	  
          

          
          
                  
          

                  int_T Integrator_MODE; /* '<S2>/Integrator' */
                          

	  
          

          
          
                  
          

                  int8_T CTrate1_semaphoreTaken; /* '<S6>/CTrate1' */
                          

	  
          

          
          
                  
          

                  int8_T CTrate_semaphoreTaken; /* '<S6>/CTrate' */
                          

	  
          

          
          
                  
          

                  int8_T CTrate2_semaphoreTaken; /* '<S6>/CTrate2' */
                          

	  
          

          
          
                  
          

                  int8_T CTrate3_semaphoreTaken; /* '<S6>/CTrate3' */
                          

	  
          

          
          
                  
          

                  int8_T CTrate4_semaphoreTaken; /* '<S6>/CTrate4' */
                          

	  
          

          
          
                  
          

                  int8_T CTrate5_semaphoreTaken; /* '<S6>/CTrate5' */
                          

	  
          

          
          
                  
          

                  int8_T CTrate6_semaphoreTaken; /* '<S6>/CTrate6' */
                          

	  
          

          
          
                  
          

                  int8_T CTrate7_semaphoreTaken; /* '<S6>/CTrate7' */
                          

	  
          

          
          
                  
          

                  char_T pad_CTrate7_semaphoreTaken[4]; 
                          

	  
          
          
                  
          

                  DW_Pitchcontroller_benchmark_no_taylor_T Pitchcontroller_c; /* '<S167>/B_44_120' */
                          

	  
          
          
                  
          

                  DW_Pitchcontroller_benchmark_no_taylor_T Pitchcontroller_a2; /* '<S151>/B_44_113' */
                          

	  
          
          
                  
          

                  DW_Pitchcontroller_benchmark_no_taylor_T Pitchcontroller_nb; /* '<S135>/B_44_106' */
                          

	  
          
          
                  
          

                  DW_Pitchcontroller_benchmark_no_taylor_T Pitchcontroller_f; /* '<S119>/B_44_99' */
                          

	  
          
          
                  
          

                  DW_Pitchcontroller_benchmark_no_taylor_T Pitchcontroller_p; /* '<S103>/B_44_92' */
                          

	  
          
          
                  
          

                  DW_Pitchcontroller_benchmark_no_taylor_T Pitchcontroller_e; /* '<S87>/B_44_85' */
                          

	  
          
          
                  
          

                  DW_Pitchcontroller_benchmark_no_taylor_T Pitchcontroller_i; /* '<S71>/B_44_78' */
                          

	  
          
          
                  
          

                  DW_Pitchcontroller_benchmark_no_taylor_T Pitchcontroller_a; /* '<S55>/B_44_71' */
                          

	  
          
          
                  
          

                  DW_Pitchcontroller_benchmark_no_taylor_T Pitchcontroller_n; /* '<S39>/B_44_64' */
                          

	  
          
          
                  
          

                  DW_Pitchcontroller_benchmark_no_taylor_T Pitchcontroller; /* '<S23>/B_44_57' */
                          

	  
          




  
    } DW_benchmark_no_taylor_T;
  

      
        
        
        /* Continuous states (auto storage) */
        typedef struct {
      	    real_T Integrator_CSTATE; /* '<S2>/Integrator' */
	    real_T TorqueIntegrator_CSTATE; /* '<S25>/Torque Integrator' */
	    real_T generatorint_CSTATE; /* '<S24>/generator int' */
	    real_T TorqueIntegrator_CSTATE_h; /* '<S57>/Torque Integrator' */
	    real_T generatorint_CSTATE_h; /* '<S56>/generator int' */
	    real_T TorqueIntegrator_CSTATE_o; /* '<S73>/Torque Integrator' */
	    real_T generatorint_CSTATE_b; /* '<S72>/generator int' */
	    real_T TorqueIntegrator_CSTATE_p; /* '<S89>/Torque Integrator' */
	    real_T generatorint_CSTATE_bf; /* '<S88>/generator int' */
	    real_T TorqueIntegrator_CSTATE_f; /* '<S105>/Torque Integrator' */
	    real_T generatorint_CSTATE_a; /* '<S104>/generator int' */
	    real_T TorqueIntegrator_CSTATE_j; /* '<S121>/Torque Integrator' */
	    real_T generatorint_CSTATE_g; /* '<S120>/generator int' */
	    real_T TorqueIntegrator_CSTATE_i; /* '<S137>/Torque Integrator' */
	    real_T generatorint_CSTATE_i; /* '<S136>/generator int' */
	    real_T TorqueIntegrator_CSTATE_oh; /* '<S153>/Torque Integrator' */
	    real_T generatorint_CSTATE_l; /* '<S152>/generator int' */
	    real_T TorqueIntegrator_CSTATE_n; /* '<S169>/Torque Integrator' */
	    real_T generatorint_CSTATE_bt; /* '<S168>/generator int' */
	    real_T TorqueIntegrator_CSTATE_nc; /* '<S41>/Torque Integrator' */
	    real_T generatorint_CSTATE_am; /* '<S40>/generator int' */
	    real_T Integrator_CSTATE_a; /* '<S34>/Integrator' */
	    real_T Tower_CSTATE[2]; /* '<S36>/Tower' */
	    real_T rotorint_CSTATE; /* '<S24>/rotor int' */
	    real_T Integrator_CSTATE_p; /* '<S66>/Integrator' */
	    real_T Tower_CSTATE_p[2]; /* '<S68>/Tower' */
	    real_T rotorint_CSTATE_f; /* '<S56>/rotor int' */
	    real_T Integrator_CSTATE_m; /* '<S82>/Integrator' */
	    real_T Tower_CSTATE_d[2]; /* '<S84>/Tower' */
	    real_T rotorint_CSTATE_a; /* '<S72>/rotor int' */
	    real_T Integrator_CSTATE_i; /* '<S98>/Integrator' */
	    real_T Tower_CSTATE_i[2]; /* '<S100>/Tower' */
	    real_T rotorint_CSTATE_d; /* '<S88>/rotor int' */
	    real_T Integrator_CSTATE_pq; /* '<S114>/Integrator' */
	    real_T Tower_CSTATE_pr[2]; /* '<S116>/Tower' */
	    real_T rotorint_CSTATE_k; /* '<S104>/rotor int' */
	    real_T Integrator_CSTATE_h; /* '<S130>/Integrator' */
	    real_T Tower_CSTATE_iw[2]; /* '<S132>/Tower' */
	    real_T rotorint_CSTATE_e; /* '<S120>/rotor int' */
	    real_T Integrator_CSTATE_e; /* '<S146>/Integrator' */
	    real_T Tower_CSTATE_b[2]; /* '<S148>/Tower' */
	    real_T rotorint_CSTATE_fa; /* '<S136>/rotor int' */
	    real_T Integrator_CSTATE_md; /* '<S162>/Integrator' */
	    real_T Tower_CSTATE_f[2]; /* '<S164>/Tower' */
	    real_T rotorint_CSTATE_o; /* '<S152>/rotor int' */
	    real_T Integrator_CSTATE_o; /* '<S178>/Integrator' */
	    real_T Tower_CSTATE_m[2]; /* '<S180>/Tower' */
	    real_T rotorint_CSTATE_n; /* '<S168>/rotor int' */
	    real_T Integrator_CSTATE_j; /* '<S50>/Integrator' */
	    real_T Tower_CSTATE_c[2]; /* '<S52>/Tower' */
	    real_T rotorint_CSTATE_ai; /* '<S40>/rotor int' */
	    real_T torsionint_CSTATE; /* '<S24>/torsion int' */
	    real_T torsionint_CSTATE_a; /* '<S56>/torsion int' */
	    real_T torsionint_CSTATE_j; /* '<S72>/torsion int' */
	    real_T torsionint_CSTATE_aj; /* '<S88>/torsion int' */
	    real_T torsionint_CSTATE_n; /* '<S104>/torsion int' */
	    real_T torsionint_CSTATE_jv; /* '<S120>/torsion int' */
	    real_T torsionint_CSTATE_a4; /* '<S136>/torsion int' */
	    real_T torsionint_CSTATE_k; /* '<S152>/torsion int' */
	    real_T torsionint_CSTATE_c; /* '<S168>/torsion int' */
	    real_T torsionint_CSTATE_j2; /* '<S40>/torsion int' */
	    real_T Hydraulictimeconstant_CSTATE; /* '<S34>/Hydraulic  time constant' */
	    real_T genIntegrator_CSTATE; /* '<S27>/gen Integrator' */
	    real_T genIntegrator1_CSTATE; /* '<S27>/gen Integrator1' */
	    real_T Hydraulictimeconstant_CSTATE_c; /* '<S50>/Hydraulic  time constant' */
	    real_T genIntegrator_CSTATE_e; /* '<S43>/gen Integrator' */
	    real_T genIntegrator1_CSTATE_d; /* '<S43>/gen Integrator1' */
	    real_T Hydraulictimeconstant_CSTATE_d; /* '<S66>/Hydraulic  time constant' */
	    real_T genIntegrator_CSTATE_i; /* '<S59>/gen Integrator' */
	    real_T genIntegrator1_CSTATE_g; /* '<S59>/gen Integrator1' */
	    real_T Hydraulictimeconstant_CSTATE_h; /* '<S82>/Hydraulic  time constant' */
	    real_T genIntegrator_CSTATE_j; /* '<S75>/gen Integrator' */
	    real_T genIntegrator1_CSTATE_f; /* '<S75>/gen Integrator1' */
	    real_T Hydraulictimeconstant_CSTATE_g; /* '<S98>/Hydraulic  time constant' */
	    real_T genIntegrator_CSTATE_d; /* '<S91>/gen Integrator' */
	    real_T genIntegrator1_CSTATE_j; /* '<S91>/gen Integrator1' */
	    real_T Hydraulictimeconstant_CSTATE_j; /* '<S114>/Hydraulic  time constant' */
	    real_T genIntegrator_CSTATE_a; /* '<S107>/gen Integrator' */
	    real_T genIntegrator1_CSTATE_p; /* '<S107>/gen Integrator1' */
	    real_T Hydraulictimeconstant_CSTATE_k; /* '<S130>/Hydraulic  time constant' */
	    real_T genIntegrator_CSTATE_m; /* '<S123>/gen Integrator' */
	    real_T genIntegrator1_CSTATE_m; /* '<S123>/gen Integrator1' */
	    real_T Hydraulictimeconstant_CSTATE_f; /* '<S146>/Hydraulic  time constant' */
	    real_T genIntegrator_CSTATE_ae; /* '<S139>/gen Integrator' */
	    real_T genIntegrator1_CSTATE_h; /* '<S139>/gen Integrator1' */
	    real_T Hydraulictimeconstant_CSTATE_m; /* '<S162>/Hydraulic  time constant' */
	    real_T genIntegrator_CSTATE_ju; /* '<S155>/gen Integrator' */
	    real_T genIntegrator1_CSTATE_o; /* '<S155>/gen Integrator1' */
	    real_T Hydraulictimeconstant_CSTATE_e; /* '<S178>/Hydraulic  time constant' */
	    real_T genIntegrator_CSTATE_mc; /* '<S171>/gen Integrator' */
	    real_T genIntegrator1_CSTATE_gl; /* '<S171>/gen Integrator1' */
  
    } X_benchmark_no_taylor_T;
    
                /* State derivatives (auto storage) */
            typedef struct {
        	    real_T Integrator_CSTATE; /* '<S2>/Integrator' */
	    real_T TorqueIntegrator_CSTATE; /* '<S25>/Torque Integrator' */
	    real_T generatorint_CSTATE; /* '<S24>/generator int' */
	    real_T TorqueIntegrator_CSTATE_h; /* '<S57>/Torque Integrator' */
	    real_T generatorint_CSTATE_h; /* '<S56>/generator int' */
	    real_T TorqueIntegrator_CSTATE_o; /* '<S73>/Torque Integrator' */
	    real_T generatorint_CSTATE_b; /* '<S72>/generator int' */
	    real_T TorqueIntegrator_CSTATE_p; /* '<S89>/Torque Integrator' */
	    real_T generatorint_CSTATE_bf; /* '<S88>/generator int' */
	    real_T TorqueIntegrator_CSTATE_f; /* '<S105>/Torque Integrator' */
	    real_T generatorint_CSTATE_a; /* '<S104>/generator int' */
	    real_T TorqueIntegrator_CSTATE_j; /* '<S121>/Torque Integrator' */
	    real_T generatorint_CSTATE_g; /* '<S120>/generator int' */
	    real_T TorqueIntegrator_CSTATE_i; /* '<S137>/Torque Integrator' */
	    real_T generatorint_CSTATE_i; /* '<S136>/generator int' */
	    real_T TorqueIntegrator_CSTATE_oh; /* '<S153>/Torque Integrator' */
	    real_T generatorint_CSTATE_l; /* '<S152>/generator int' */
	    real_T TorqueIntegrator_CSTATE_n; /* '<S169>/Torque Integrator' */
	    real_T generatorint_CSTATE_bt; /* '<S168>/generator int' */
	    real_T TorqueIntegrator_CSTATE_nc; /* '<S41>/Torque Integrator' */
	    real_T generatorint_CSTATE_am; /* '<S40>/generator int' */
	    real_T Integrator_CSTATE_a; /* '<S34>/Integrator' */
	    real_T Tower_CSTATE[2]; /* '<S36>/Tower' */
	    real_T rotorint_CSTATE; /* '<S24>/rotor int' */
	    real_T Integrator_CSTATE_p; /* '<S66>/Integrator' */
	    real_T Tower_CSTATE_p[2]; /* '<S68>/Tower' */
	    real_T rotorint_CSTATE_f; /* '<S56>/rotor int' */
	    real_T Integrator_CSTATE_m; /* '<S82>/Integrator' */
	    real_T Tower_CSTATE_d[2]; /* '<S84>/Tower' */
	    real_T rotorint_CSTATE_a; /* '<S72>/rotor int' */
	    real_T Integrator_CSTATE_i; /* '<S98>/Integrator' */
	    real_T Tower_CSTATE_i[2]; /* '<S100>/Tower' */
	    real_T rotorint_CSTATE_d; /* '<S88>/rotor int' */
	    real_T Integrator_CSTATE_pq; /* '<S114>/Integrator' */
	    real_T Tower_CSTATE_pr[2]; /* '<S116>/Tower' */
	    real_T rotorint_CSTATE_k; /* '<S104>/rotor int' */
	    real_T Integrator_CSTATE_h; /* '<S130>/Integrator' */
	    real_T Tower_CSTATE_iw[2]; /* '<S132>/Tower' */
	    real_T rotorint_CSTATE_e; /* '<S120>/rotor int' */
	    real_T Integrator_CSTATE_e; /* '<S146>/Integrator' */
	    real_T Tower_CSTATE_b[2]; /* '<S148>/Tower' */
	    real_T rotorint_CSTATE_fa; /* '<S136>/rotor int' */
	    real_T Integrator_CSTATE_md; /* '<S162>/Integrator' */
	    real_T Tower_CSTATE_f[2]; /* '<S164>/Tower' */
	    real_T rotorint_CSTATE_o; /* '<S152>/rotor int' */
	    real_T Integrator_CSTATE_o; /* '<S178>/Integrator' */
	    real_T Tower_CSTATE_m[2]; /* '<S180>/Tower' */
	    real_T rotorint_CSTATE_n; /* '<S168>/rotor int' */
	    real_T Integrator_CSTATE_j; /* '<S50>/Integrator' */
	    real_T Tower_CSTATE_c[2]; /* '<S52>/Tower' */
	    real_T rotorint_CSTATE_ai; /* '<S40>/rotor int' */
	    real_T torsionint_CSTATE; /* '<S24>/torsion int' */
	    real_T torsionint_CSTATE_a; /* '<S56>/torsion int' */
	    real_T torsionint_CSTATE_j; /* '<S72>/torsion int' */
	    real_T torsionint_CSTATE_aj; /* '<S88>/torsion int' */
	    real_T torsionint_CSTATE_n; /* '<S104>/torsion int' */
	    real_T torsionint_CSTATE_jv; /* '<S120>/torsion int' */
	    real_T torsionint_CSTATE_a4; /* '<S136>/torsion int' */
	    real_T torsionint_CSTATE_k; /* '<S152>/torsion int' */
	    real_T torsionint_CSTATE_c; /* '<S168>/torsion int' */
	    real_T torsionint_CSTATE_j2; /* '<S40>/torsion int' */
	    real_T Hydraulictimeconstant_CSTATE; /* '<S34>/Hydraulic  time constant' */
	    real_T genIntegrator_CSTATE; /* '<S27>/gen Integrator' */
	    real_T genIntegrator1_CSTATE; /* '<S27>/gen Integrator1' */
	    real_T Hydraulictimeconstant_CSTATE_c; /* '<S50>/Hydraulic  time constant' */
	    real_T genIntegrator_CSTATE_e; /* '<S43>/gen Integrator' */
	    real_T genIntegrator1_CSTATE_d; /* '<S43>/gen Integrator1' */
	    real_T Hydraulictimeconstant_CSTATE_d; /* '<S66>/Hydraulic  time constant' */
	    real_T genIntegrator_CSTATE_i; /* '<S59>/gen Integrator' */
	    real_T genIntegrator1_CSTATE_g; /* '<S59>/gen Integrator1' */
	    real_T Hydraulictimeconstant_CSTATE_h; /* '<S82>/Hydraulic  time constant' */
	    real_T genIntegrator_CSTATE_j; /* '<S75>/gen Integrator' */
	    real_T genIntegrator1_CSTATE_f; /* '<S75>/gen Integrator1' */
	    real_T Hydraulictimeconstant_CSTATE_g; /* '<S98>/Hydraulic  time constant' */
	    real_T genIntegrator_CSTATE_d; /* '<S91>/gen Integrator' */
	    real_T genIntegrator1_CSTATE_j; /* '<S91>/gen Integrator1' */
	    real_T Hydraulictimeconstant_CSTATE_j; /* '<S114>/Hydraulic  time constant' */
	    real_T genIntegrator_CSTATE_a; /* '<S107>/gen Integrator' */
	    real_T genIntegrator1_CSTATE_p; /* '<S107>/gen Integrator1' */
	    real_T Hydraulictimeconstant_CSTATE_k; /* '<S130>/Hydraulic  time constant' */
	    real_T genIntegrator_CSTATE_m; /* '<S123>/gen Integrator' */
	    real_T genIntegrator1_CSTATE_m; /* '<S123>/gen Integrator1' */
	    real_T Hydraulictimeconstant_CSTATE_f; /* '<S146>/Hydraulic  time constant' */
	    real_T genIntegrator_CSTATE_ae; /* '<S139>/gen Integrator' */
	    real_T genIntegrator1_CSTATE_h; /* '<S139>/gen Integrator1' */
	    real_T Hydraulictimeconstant_CSTATE_m; /* '<S162>/Hydraulic  time constant' */
	    real_T genIntegrator_CSTATE_ju; /* '<S155>/gen Integrator' */
	    real_T genIntegrator1_CSTATE_o; /* '<S155>/gen Integrator1' */
	    real_T Hydraulictimeconstant_CSTATE_e; /* '<S178>/Hydraulic  time constant' */
	    real_T genIntegrator_CSTATE_mc; /* '<S171>/gen Integrator' */
	    real_T genIntegrator1_CSTATE_gl; /* '<S171>/gen Integrator1' */
  
      } XDot_benchmark_no_taylor_T;
              
        /* State disabled  */
        typedef struct {
      	    boolean_T Integrator_CSTATE; /* '<S2>/Integrator' */
	    boolean_T TorqueIntegrator_CSTATE; /* '<S25>/Torque Integrator' */
	    boolean_T generatorint_CSTATE; /* '<S24>/generator int' */
	    boolean_T TorqueIntegrator_CSTATE_h; /* '<S57>/Torque Integrator' */
	    boolean_T generatorint_CSTATE_h; /* '<S56>/generator int' */
	    boolean_T TorqueIntegrator_CSTATE_o; /* '<S73>/Torque Integrator' */
	    boolean_T generatorint_CSTATE_b; /* '<S72>/generator int' */
	    boolean_T TorqueIntegrator_CSTATE_p; /* '<S89>/Torque Integrator' */
	    boolean_T generatorint_CSTATE_bf; /* '<S88>/generator int' */
	    boolean_T TorqueIntegrator_CSTATE_f; /* '<S105>/Torque Integrator' */
	    boolean_T generatorint_CSTATE_a; /* '<S104>/generator int' */
	    boolean_T TorqueIntegrator_CSTATE_j; /* '<S121>/Torque Integrator' */
	    boolean_T generatorint_CSTATE_g; /* '<S120>/generator int' */
	    boolean_T TorqueIntegrator_CSTATE_i; /* '<S137>/Torque Integrator' */
	    boolean_T generatorint_CSTATE_i; /* '<S136>/generator int' */
	    boolean_T TorqueIntegrator_CSTATE_oh; /* '<S153>/Torque Integrator' */
	    boolean_T generatorint_CSTATE_l; /* '<S152>/generator int' */
	    boolean_T TorqueIntegrator_CSTATE_n; /* '<S169>/Torque Integrator' */
	    boolean_T generatorint_CSTATE_bt; /* '<S168>/generator int' */
	    boolean_T TorqueIntegrator_CSTATE_nc; /* '<S41>/Torque Integrator' */
	    boolean_T generatorint_CSTATE_am; /* '<S40>/generator int' */
	    boolean_T Integrator_CSTATE_a; /* '<S34>/Integrator' */
	    boolean_T Tower_CSTATE[2]; /* '<S36>/Tower' */
	    boolean_T rotorint_CSTATE; /* '<S24>/rotor int' */
	    boolean_T Integrator_CSTATE_p; /* '<S66>/Integrator' */
	    boolean_T Tower_CSTATE_p[2]; /* '<S68>/Tower' */
	    boolean_T rotorint_CSTATE_f; /* '<S56>/rotor int' */
	    boolean_T Integrator_CSTATE_m; /* '<S82>/Integrator' */
	    boolean_T Tower_CSTATE_d[2]; /* '<S84>/Tower' */
	    boolean_T rotorint_CSTATE_a; /* '<S72>/rotor int' */
	    boolean_T Integrator_CSTATE_i; /* '<S98>/Integrator' */
	    boolean_T Tower_CSTATE_i[2]; /* '<S100>/Tower' */
	    boolean_T rotorint_CSTATE_d; /* '<S88>/rotor int' */
	    boolean_T Integrator_CSTATE_pq; /* '<S114>/Integrator' */
	    boolean_T Tower_CSTATE_pr[2]; /* '<S116>/Tower' */
	    boolean_T rotorint_CSTATE_k; /* '<S104>/rotor int' */
	    boolean_T Integrator_CSTATE_h; /* '<S130>/Integrator' */
	    boolean_T Tower_CSTATE_iw[2]; /* '<S132>/Tower' */
	    boolean_T rotorint_CSTATE_e; /* '<S120>/rotor int' */
	    boolean_T Integrator_CSTATE_e; /* '<S146>/Integrator' */
	    boolean_T Tower_CSTATE_b[2]; /* '<S148>/Tower' */
	    boolean_T rotorint_CSTATE_fa; /* '<S136>/rotor int' */
	    boolean_T Integrator_CSTATE_md; /* '<S162>/Integrator' */
	    boolean_T Tower_CSTATE_f[2]; /* '<S164>/Tower' */
	    boolean_T rotorint_CSTATE_o; /* '<S152>/rotor int' */
	    boolean_T Integrator_CSTATE_o; /* '<S178>/Integrator' */
	    boolean_T Tower_CSTATE_m[2]; /* '<S180>/Tower' */
	    boolean_T rotorint_CSTATE_n; /* '<S168>/rotor int' */
	    boolean_T Integrator_CSTATE_j; /* '<S50>/Integrator' */
	    boolean_T Tower_CSTATE_c[2]; /* '<S52>/Tower' */
	    boolean_T rotorint_CSTATE_ai; /* '<S40>/rotor int' */
	    boolean_T torsionint_CSTATE; /* '<S24>/torsion int' */
	    boolean_T torsionint_CSTATE_a; /* '<S56>/torsion int' */
	    boolean_T torsionint_CSTATE_j; /* '<S72>/torsion int' */
	    boolean_T torsionint_CSTATE_aj; /* '<S88>/torsion int' */
	    boolean_T torsionint_CSTATE_n; /* '<S104>/torsion int' */
	    boolean_T torsionint_CSTATE_jv; /* '<S120>/torsion int' */
	    boolean_T torsionint_CSTATE_a4; /* '<S136>/torsion int' */
	    boolean_T torsionint_CSTATE_k; /* '<S152>/torsion int' */
	    boolean_T torsionint_CSTATE_c; /* '<S168>/torsion int' */
	    boolean_T torsionint_CSTATE_j2; /* '<S40>/torsion int' */
	    boolean_T Hydraulictimeconstant_CSTATE; /* '<S34>/Hydraulic  time constant' */
	    boolean_T genIntegrator_CSTATE; /* '<S27>/gen Integrator' */
	    boolean_T genIntegrator1_CSTATE; /* '<S27>/gen Integrator1' */
	    boolean_T Hydraulictimeconstant_CSTATE_c; /* '<S50>/Hydraulic  time constant' */
	    boolean_T genIntegrator_CSTATE_e; /* '<S43>/gen Integrator' */
	    boolean_T genIntegrator1_CSTATE_d; /* '<S43>/gen Integrator1' */
	    boolean_T Hydraulictimeconstant_CSTATE_d; /* '<S66>/Hydraulic  time constant' */
	    boolean_T genIntegrator_CSTATE_i; /* '<S59>/gen Integrator' */
	    boolean_T genIntegrator1_CSTATE_g; /* '<S59>/gen Integrator1' */
	    boolean_T Hydraulictimeconstant_CSTATE_h; /* '<S82>/Hydraulic  time constant' */
	    boolean_T genIntegrator_CSTATE_j; /* '<S75>/gen Integrator' */
	    boolean_T genIntegrator1_CSTATE_f; /* '<S75>/gen Integrator1' */
	    boolean_T Hydraulictimeconstant_CSTATE_g; /* '<S98>/Hydraulic  time constant' */
	    boolean_T genIntegrator_CSTATE_d; /* '<S91>/gen Integrator' */
	    boolean_T genIntegrator1_CSTATE_j; /* '<S91>/gen Integrator1' */
	    boolean_T Hydraulictimeconstant_CSTATE_j; /* '<S114>/Hydraulic  time constant' */
	    boolean_T genIntegrator_CSTATE_a; /* '<S107>/gen Integrator' */
	    boolean_T genIntegrator1_CSTATE_p; /* '<S107>/gen Integrator1' */
	    boolean_T Hydraulictimeconstant_CSTATE_k; /* '<S130>/Hydraulic  time constant' */
	    boolean_T genIntegrator_CSTATE_m; /* '<S123>/gen Integrator' */
	    boolean_T genIntegrator1_CSTATE_m; /* '<S123>/gen Integrator1' */
	    boolean_T Hydraulictimeconstant_CSTATE_f; /* '<S146>/Hydraulic  time constant' */
	    boolean_T genIntegrator_CSTATE_ae; /* '<S139>/gen Integrator' */
	    boolean_T genIntegrator1_CSTATE_h; /* '<S139>/gen Integrator1' */
	    boolean_T Hydraulictimeconstant_CSTATE_m; /* '<S162>/Hydraulic  time constant' */
	    boolean_T genIntegrator_CSTATE_ju; /* '<S155>/gen Integrator' */
	    boolean_T genIntegrator1_CSTATE_o; /* '<S155>/gen Integrator1' */
	    boolean_T Hydraulictimeconstant_CSTATE_e; /* '<S178>/Hydraulic  time constant' */
	    boolean_T genIntegrator_CSTATE_mc; /* '<S171>/gen Integrator' */
	    boolean_T genIntegrator1_CSTATE_gl; /* '<S171>/gen Integrator1' */
  
    } XDis_benchmark_no_taylor_T;
    
        
        /* Continuous State Absolute Tolerance  */
        typedef struct {
                    real_T Integrator_CSTATE; /* '<S2>/Integrator' */
              real_T TorqueIntegrator_CSTATE; /* '<S25>/Torque Integrator' */
              real_T generatorint_CSTATE; /* '<S24>/generator int' */
              real_T TorqueIntegrator_CSTATE_h; /* '<S57>/Torque Integrator' */
              real_T generatorint_CSTATE_h; /* '<S56>/generator int' */
              real_T TorqueIntegrator_CSTATE_o; /* '<S73>/Torque Integrator' */
              real_T generatorint_CSTATE_b; /* '<S72>/generator int' */
              real_T TorqueIntegrator_CSTATE_p; /* '<S89>/Torque Integrator' */
              real_T generatorint_CSTATE_bf; /* '<S88>/generator int' */
              real_T TorqueIntegrator_CSTATE_f; /* '<S105>/Torque Integrator' */
              real_T generatorint_CSTATE_a; /* '<S104>/generator int' */
              real_T TorqueIntegrator_CSTATE_j; /* '<S121>/Torque Integrator' */
              real_T generatorint_CSTATE_g; /* '<S120>/generator int' */
              real_T TorqueIntegrator_CSTATE_i; /* '<S137>/Torque Integrator' */
              real_T generatorint_CSTATE_i; /* '<S136>/generator int' */
              real_T TorqueIntegrator_CSTATE_oh; /* '<S153>/Torque Integrator' */
              real_T generatorint_CSTATE_l; /* '<S152>/generator int' */
              real_T TorqueIntegrator_CSTATE_n; /* '<S169>/Torque Integrator' */
              real_T generatorint_CSTATE_bt; /* '<S168>/generator int' */
              real_T TorqueIntegrator_CSTATE_nc; /* '<S41>/Torque Integrator' */
              real_T generatorint_CSTATE_am; /* '<S40>/generator int' */
              real_T Integrator_CSTATE_a; /* '<S34>/Integrator' */
              real_T Tower_CSTATE[2]; /* '<S36>/Tower' */
              real_T rotorint_CSTATE; /* '<S24>/rotor int' */
              real_T Integrator_CSTATE_p; /* '<S66>/Integrator' */
              real_T Tower_CSTATE_p[2]; /* '<S68>/Tower' */
              real_T rotorint_CSTATE_f; /* '<S56>/rotor int' */
              real_T Integrator_CSTATE_m; /* '<S82>/Integrator' */
              real_T Tower_CSTATE_d[2]; /* '<S84>/Tower' */
              real_T rotorint_CSTATE_a; /* '<S72>/rotor int' */
              real_T Integrator_CSTATE_i; /* '<S98>/Integrator' */
              real_T Tower_CSTATE_i[2]; /* '<S100>/Tower' */
              real_T rotorint_CSTATE_d; /* '<S88>/rotor int' */
              real_T Integrator_CSTATE_pq; /* '<S114>/Integrator' */
              real_T Tower_CSTATE_pr[2]; /* '<S116>/Tower' */
              real_T rotorint_CSTATE_k; /* '<S104>/rotor int' */
              real_T Integrator_CSTATE_h; /* '<S130>/Integrator' */
              real_T Tower_CSTATE_iw[2]; /* '<S132>/Tower' */
              real_T rotorint_CSTATE_e; /* '<S120>/rotor int' */
              real_T Integrator_CSTATE_e; /* '<S146>/Integrator' */
              real_T Tower_CSTATE_b[2]; /* '<S148>/Tower' */
              real_T rotorint_CSTATE_fa; /* '<S136>/rotor int' */
              real_T Integrator_CSTATE_md; /* '<S162>/Integrator' */
              real_T Tower_CSTATE_f[2]; /* '<S164>/Tower' */
              real_T rotorint_CSTATE_o; /* '<S152>/rotor int' */
              real_T Integrator_CSTATE_o; /* '<S178>/Integrator' */
              real_T Tower_CSTATE_m[2]; /* '<S180>/Tower' */
              real_T rotorint_CSTATE_n; /* '<S168>/rotor int' */
              real_T Integrator_CSTATE_j; /* '<S50>/Integrator' */
              real_T Tower_CSTATE_c[2]; /* '<S52>/Tower' */
              real_T rotorint_CSTATE_ai; /* '<S40>/rotor int' */
              real_T torsionint_CSTATE; /* '<S24>/torsion int' */
              real_T torsionint_CSTATE_a; /* '<S56>/torsion int' */
              real_T torsionint_CSTATE_j; /* '<S72>/torsion int' */
              real_T torsionint_CSTATE_aj; /* '<S88>/torsion int' */
              real_T torsionint_CSTATE_n; /* '<S104>/torsion int' */
              real_T torsionint_CSTATE_jv; /* '<S120>/torsion int' */
              real_T torsionint_CSTATE_a4; /* '<S136>/torsion int' */
              real_T torsionint_CSTATE_k; /* '<S152>/torsion int' */
              real_T torsionint_CSTATE_c; /* '<S168>/torsion int' */
              real_T torsionint_CSTATE_j2; /* '<S40>/torsion int' */
              real_T Hydraulictimeconstant_CSTATE; /* '<S34>/Hydraulic  time constant' */
              real_T genIntegrator_CSTATE; /* '<S27>/gen Integrator' */
              real_T genIntegrator1_CSTATE; /* '<S27>/gen Integrator1' */
              real_T Hydraulictimeconstant_CSTATE_c; /* '<S50>/Hydraulic  time constant' */
              real_T genIntegrator_CSTATE_e; /* '<S43>/gen Integrator' */
              real_T genIntegrator1_CSTATE_d; /* '<S43>/gen Integrator1' */
              real_T Hydraulictimeconstant_CSTATE_d; /* '<S66>/Hydraulic  time constant' */
              real_T genIntegrator_CSTATE_i; /* '<S59>/gen Integrator' */
              real_T genIntegrator1_CSTATE_g; /* '<S59>/gen Integrator1' */
              real_T Hydraulictimeconstant_CSTATE_h; /* '<S82>/Hydraulic  time constant' */
              real_T genIntegrator_CSTATE_j; /* '<S75>/gen Integrator' */
              real_T genIntegrator1_CSTATE_f; /* '<S75>/gen Integrator1' */
              real_T Hydraulictimeconstant_CSTATE_g; /* '<S98>/Hydraulic  time constant' */
              real_T genIntegrator_CSTATE_d; /* '<S91>/gen Integrator' */
              real_T genIntegrator1_CSTATE_j; /* '<S91>/gen Integrator1' */
              real_T Hydraulictimeconstant_CSTATE_j; /* '<S114>/Hydraulic  time constant' */
              real_T genIntegrator_CSTATE_a; /* '<S107>/gen Integrator' */
              real_T genIntegrator1_CSTATE_p; /* '<S107>/gen Integrator1' */
              real_T Hydraulictimeconstant_CSTATE_k; /* '<S130>/Hydraulic  time constant' */
              real_T genIntegrator_CSTATE_m; /* '<S123>/gen Integrator' */
              real_T genIntegrator1_CSTATE_m; /* '<S123>/gen Integrator1' */
              real_T Hydraulictimeconstant_CSTATE_f; /* '<S146>/Hydraulic  time constant' */
              real_T genIntegrator_CSTATE_ae; /* '<S139>/gen Integrator' */
              real_T genIntegrator1_CSTATE_h; /* '<S139>/gen Integrator1' */
              real_T Hydraulictimeconstant_CSTATE_m; /* '<S162>/Hydraulic  time constant' */
              real_T genIntegrator_CSTATE_ju; /* '<S155>/gen Integrator' */
              real_T genIntegrator1_CSTATE_o; /* '<S155>/gen Integrator1' */
              real_T Hydraulictimeconstant_CSTATE_e; /* '<S178>/Hydraulic  time constant' */
              real_T genIntegrator_CSTATE_mc; /* '<S171>/gen Integrator' */
              real_T genIntegrator1_CSTATE_gl; /* '<S171>/gen Integrator1' */
    
    } CStateAbsTol_benchmark_no_taylor_T;
    
              /* Zero-crossing (trigger) state */
              
      typedef struct {
                        real_T Integrator_IntgUpLimit_ZC; /* '<S2>/Integrator' */
                real_T Integrator_IntgLoLimit_ZC; /* '<S2>/Integrator' */
                real_T Integrator_LeaveSaturate_ZC; /* '<S2>/Integrator' */
                real_T FromWs_repeatedTime_ZC; /* '<S9>/FromWs' */
    
      } ZCV_benchmark_no_taylor_T;
      
                      /* Zero-crossing (trigger) state */
              
      typedef struct  {
        
          
          
                  
          

                  ZCSigState Integrator_IntgUpLimit_ZCE; /* '<S2>/Integrator' */
                          

	  
          

          
          
                  
          

                  ZCSigState Integrator_IntgLoLimit_ZCE; /* '<S2>/Integrator' */
                          

	  
          

          
          
                  
          

                  ZCSigState Integrator_LeaveSaturate_ZCE; /* '<S2>/Integrator' */
                          

	  
          

          
          
                  
          

                  ZCSigState FromWs_repeatedTime_ZCE; /* '<S9>/FromWs' */
                          

	  
          




      } PrevZCX_benchmark_no_taylor_T;
      
              
            /* Parameters for system: '<S23>/B_44_57' */
      
        struct P_Pitchcontroller_benchmark_no_taylor_T_ {
          
          
          
                  
          

                  real_T P_0; /* Expression: wt.ctrl.torq.beta
    * Referenced by: '<S30>/Pitch_ref [deg]'
    */
                          

	  
          

          
          
                  
          

                  real_T P_1; /* Computed Parameter: P_1
    * Referenced by: '<S30>/Discrete-Time Integrator'
    */
                          

	  
          

          
          
                  
          

                  real_T P_2; /* Expression: 0
    * Referenced by: '<S30>/Discrete-Time Integrator'
    */
                          

	  
          

          
          
                  
          

                  real_T P_3; /* Expression: wt.ctrl.pitch.ulim*pi/180
    * Referenced by: '<S30>/Discrete-Time Integrator'
    */
                          

	  
          

          
          
                  
          

                  real_T P_4; /* Expression: wt.ctrl.pitch.llim
    * Referenced by: '<S30>/Discrete-Time Integrator'
    */
                          

	  
          

          
          
                  
          

                  real_T P_5; /* Expression: 0.0
    * Referenced by: '<S30>/Integer Delay'
    */
                          

	  
          

          
          
                  
          

                  real_T P_6[6]; /* Expression: wt.ctrl.pitch.pwr
    * Referenced by: '<S30>/Gain correction'
    */
                          

	  
          

          
          
                  
          

                  real_T P_7[451]; /* Expression: wt.ctrl.pitch.beta
    * Referenced by: '<S30>/Gain correction'
    */
                          

	  
          

          
          
                  
          

                  real_T P_8[2706]; /* Expression: wt.ctrl.pitch.gs
    * Referenced by: '<S30>/Gain correction'
    */
                          

	  
          

          
          
                  
          

                  real_T P_9; /* Expression: wt.ctrl.pitch.Igain
    * Referenced by: '<S30>/Integral gain'
    */
                          

	  
          

          
          
                  
          

                  real_T P_10; /* Expression: wt.ctrl.pitch.Pgain
    * Referenced by: '<S30>/Proportional gain'
    */
                          

	  
          

          
          
                  
          

                  real_T P_11; /* Expression: 180/pi
    * Referenced by: '<S30>/To degrees'
    */
                          

	  
          

          
          
                  
          

                  real_T P_12; /* Expression: wt.ctrl.pitch.ulim
    * Referenced by: '<S30>/Saturation'
    */
                          

	  
          

          
          
                  
          

                  real_T P_13; /* Expression: 0
    * Referenced by: '<S30>/Saturation'
    */
                          

	  
          

          
          
                  
          

                  real_T P_14; /* Computed Parameter: P_14
    * Referenced by: '<S30>/Rate Limiter'
    */
                          

	  
          

          
          
                  
          

                  real_T P_15; /* Computed Parameter: P_15
    * Referenced by: '<S30>/Rate Limiter'
    */
                          

	  
          

          
          
                  
          

                  real_T P_16; /* Expression: wt.ctrl.pitch.ini
    * Referenced by: '<S30>/Rate Limiter'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_17; /* Computed Parameter: P_17
    * Referenced by: '<S30>/Integer Delay'
    */
                          

	  
          

          
          
                  
          

                  char_T pad_P_17[4]; 
                          

	  
          




        };
      
      
      
            /* Parameters (auto storage) */
      
        struct P_benchmark_no_taylor_T_ {
          
          
          
                  
          

                  real_T P_0[2]; /* Computed Parameter: P_0
    * Referenced by: '<S193>/Wind speed'
    */
                          

	  
          

          
          
                  
          

                  struct_y3RzpqBmu9D4ZSdlM53gkD P_1; /* Expression: p
    * Referenced by: '<S193>/Wind speed'
    */
                          

	  
          

          
          
                  
          

                  real_T P_2[2]; /* Computed Parameter: P_2
    * Referenced by: '<S194>/Wind speed'
    */
                          

	  
          

          
          
                  
          

                  struct_y3RzpqBmu9D4ZSdlM53gkD P_3; /* Expression: p
    * Referenced by: '<S194>/Wind speed'
    */
                          

	  
          

          
          
                  
          

                  real_T P_4[2]; /* Computed Parameter: P_4
    * Referenced by: '<S195>/Wind speed'
    */
                          

	  
          

          
          
                  
          

                  struct_y3RzpqBmu9D4ZSdlM53gkD P_5; /* Expression: p
    * Referenced by: '<S195>/Wind speed'
    */
                          

	  
          

          
          
                  
          

                  real_T P_6[2]; /* Computed Parameter: P_6
    * Referenced by: '<S196>/Wind speed'
    */
                          

	  
          

          
          
                  
          

                  struct_y3RzpqBmu9D4ZSdlM53gkD P_7; /* Expression: p
    * Referenced by: '<S196>/Wind speed'
    */
                          

	  
          

          
          
                  
          

                  real_T P_8[2]; /* Computed Parameter: P_8
    * Referenced by: '<S197>/Wind speed'
    */
                          

	  
          

          
          
                  
          

                  struct_y3RzpqBmu9D4ZSdlM53gkD P_9; /* Expression: p
    * Referenced by: '<S197>/Wind speed'
    */
                          

	  
          

          
          
                  
          

                  real_T P_10[2]; /* Computed Parameter: P_10
    * Referenced by: '<S198>/Wind speed'
    */
                          

	  
          

          
          
                  
          

                  struct_y3RzpqBmu9D4ZSdlM53gkD P_11; /* Expression: p
    * Referenced by: '<S198>/Wind speed'
    */
                          

	  
          

          
          
                  
          

                  real_T P_12[2]; /* Computed Parameter: P_12
    * Referenced by: '<S199>/Wind speed'
    */
                          

	  
          

          
          
                  
          

                  struct_y3RzpqBmu9D4ZSdlM53gkD P_13; /* Expression: p
    * Referenced by: '<S199>/Wind speed'
    */
                          

	  
          

          
          
                  
          

                  real_T P_14[2]; /* Computed Parameter: P_14
    * Referenced by: '<S200>/Wind speed'
    */
                          

	  
          

          
          
                  
          

                  struct_y3RzpqBmu9D4ZSdlM53gkD P_15; /* Expression: p
    * Referenced by: '<S200>/Wind speed'
    */
                          

	  
          

          
          
                  
          

                  real_T P_16[2]; /* Computed Parameter: P_16
    * Referenced by: '<S201>/Wind speed'
    */
                          

	  
          

          
          
                  
          

                  struct_y3RzpqBmu9D4ZSdlM53gkD P_17; /* Expression: p
    * Referenced by: '<S201>/Wind speed'
    */
                          

	  
          

          
          
                  
          

                  real_T P_18[2]; /* Computed Parameter: P_18
    * Referenced by: '<S202>/Wind speed'
    */
                          

	  
          

          
          
                  
          

                  struct_y3RzpqBmu9D4ZSdlM53gkD P_19; /* Expression: p
    * Referenced by: '<S202>/Wind speed'
    */
                          

	  
          

          
          
                  
          

                  real_T P_20[2]; /* Computed Parameter: P_20
    * Referenced by: '<S7>/Deficit'
    */
                          

	  
          

          
          
                  
          

                  struct_PHIXY0GEtWQsAQQbCno1GE P_21; /* Expression: p
    * Referenced by: '<S7>/Deficit'
    */
                          

	  
          

          
          
                  
          

                  real_T P_22; /* Expression: wt.meas.delay
    * Referenced by: '<S27>/Computation Delay'
    */
                          

	  
          

          
          
                  
          

                  real_T P_23[4]; /* Expression: [wt.rotor.ini wt.pitch.ini 0 wt.gen.ini]
    * Referenced by: '<S27>/Computation Delay'
    */
                          

	  
          

          
          
                  
          

                  real_T P_24; /* Expression: wt.meas.delay
    * Referenced by: '<S59>/Computation Delay'
    */
                          

	  
          

          
          
                  
          

                  real_T P_25[4]; /* Expression: [wt.rotor.ini wt.pitch.ini 0 wt.gen.ini]
    * Referenced by: '<S59>/Computation Delay'
    */
                          

	  
          

          
          
                  
          

                  real_T P_26; /* Expression: wt.meas.delay
    * Referenced by: '<S75>/Computation Delay'
    */
                          

	  
          

          
          
                  
          

                  real_T P_27[4]; /* Expression: [wt.rotor.ini wt.pitch.ini 0 wt.gen.ini]
    * Referenced by: '<S75>/Computation Delay'
    */
                          

	  
          

          
          
                  
          

                  real_T P_28; /* Expression: wt.meas.delay
    * Referenced by: '<S91>/Computation Delay'
    */
                          

	  
          

          
          
                  
          

                  real_T P_29[4]; /* Expression: [wt.rotor.ini wt.pitch.ini 0 wt.gen.ini]
    * Referenced by: '<S91>/Computation Delay'
    */
                          

	  
          

          
          
                  
          

                  real_T P_30; /* Expression: wt.meas.delay
    * Referenced by: '<S107>/Computation Delay'
    */
                          

	  
          

          
          
                  
          

                  real_T P_31[4]; /* Expression: [wt.rotor.ini wt.pitch.ini 0 wt.gen.ini]
    * Referenced by: '<S107>/Computation Delay'
    */
                          

	  
          

          
          
                  
          

                  real_T P_32; /* Expression: wt.meas.delay
    * Referenced by: '<S123>/Computation Delay'
    */
                          

	  
          

          
          
                  
          

                  real_T P_33[4]; /* Expression: [wt.rotor.ini wt.pitch.ini 0 wt.gen.ini]
    * Referenced by: '<S123>/Computation Delay'
    */
                          

	  
          

          
          
                  
          

                  real_T P_34; /* Expression: wt.meas.delay
    * Referenced by: '<S139>/Computation Delay'
    */
                          

	  
          

          
          
                  
          

                  real_T P_35[4]; /* Expression: [wt.rotor.ini wt.pitch.ini 0 wt.gen.ini]
    * Referenced by: '<S139>/Computation Delay'
    */
                          

	  
          

          
          
                  
          

                  real_T P_36; /* Expression: wt.meas.delay
    * Referenced by: '<S155>/Computation Delay'
    */
                          

	  
          

          
          
                  
          

                  real_T P_37[4]; /* Expression: [wt.rotor.ini wt.pitch.ini 0 wt.gen.ini]
    * Referenced by: '<S155>/Computation Delay'
    */
                          

	  
          

          
          
                  
          

                  real_T P_38; /* Expression: wt.meas.delay
    * Referenced by: '<S171>/Computation Delay'
    */
                          

	  
          

          
          
                  
          

                  real_T P_39[4]; /* Expression: [wt.rotor.ini wt.pitch.ini 0 wt.gen.ini]
    * Referenced by: '<S171>/Computation Delay'
    */
                          

	  
          

          
          
                  
          

                  real_T P_40; /* Expression: wt.meas.delay
    * Referenced by: '<S43>/Computation Delay'
    */
                          

	  
          

          
          
                  
          

                  real_T P_41[4]; /* Expression: [wt.rotor.ini wt.pitch.ini 0 wt.gen.ini]
    * Referenced by: '<S43>/Computation Delay'
    */
                          

	  
          

          
          
                  
          

                  real_T P_42; /* Expression: .01
    * Referenced by: '<S4>/Reference delay'
    */
                          

	  
          

          
          
                  
          

                  real_T P_43; /* Expression: 0
    * Referenced by: '<S4>/Reference delay'
    */
                          

	  
          

          
          
                  
          

                  real_T P_44; /* Expression: 50
    * Referenced by: '<S2>/Integrator'
    */
                          

	  
          

          
          
                  
          

                  real_T P_45; /* Expression: 100
    * Referenced by: '<S2>/Integrator'
    */
                          

	  
          

          
          
                  
          

                  real_T P_46; /* Expression: 0
    * Referenced by: '<S2>/Integrator'
    */
                          

	  
          

          
          
                  
          

                  real_T P_47; /* Expression: maxpower
    * Referenced by: '<S3>/To rated farm power'
    */
                          

	  
          

          
          
                  
          

                  real_T P_48; /* Expression: wt.gen.torq.ini
    * Referenced by: '<S25>/Torque Integrator'
    */
                          

	  
          

          
          
                  
          

                  real_T P_49; /* Expression: wt.gen.ini
    * Referenced by: '<S24>/generator int'
    */
                          

	  
          

          
          
                  
          

                  real_T P_50; /* Expression: wt.gen.effeciency
    * Referenced by: '<S25>/Generator efficiency'
    */
                          

	  
          

          
          
                  
          

                  real_T P_51; /* Expression: wt.gen.torq.ini
    * Referenced by: '<S57>/Torque Integrator'
    */
                          

	  
          

          
          
                  
          

                  real_T P_52; /* Expression: wt.gen.ini
    * Referenced by: '<S56>/generator int'
    */
                          

	  
          

          
          
                  
          

                  real_T P_53; /* Expression: wt.gen.effeciency
    * Referenced by: '<S57>/Generator efficiency'
    */
                          

	  
          

          
          
                  
          

                  real_T P_54; /* Expression: wt.gen.torq.ini
    * Referenced by: '<S73>/Torque Integrator'
    */
                          

	  
          

          
          
                  
          

                  real_T P_55; /* Expression: wt.gen.ini
    * Referenced by: '<S72>/generator int'
    */
                          

	  
          

          
          
                  
          

                  real_T P_56; /* Expression: wt.gen.effeciency
    * Referenced by: '<S73>/Generator efficiency'
    */
                          

	  
          

          
          
                  
          

                  real_T P_57; /* Expression: wt.gen.torq.ini
    * Referenced by: '<S89>/Torque Integrator'
    */
                          

	  
          

          
          
                  
          

                  real_T P_58; /* Expression: wt.gen.ini
    * Referenced by: '<S88>/generator int'
    */
                          

	  
          

          
          
                  
          

                  real_T P_59; /* Expression: wt.gen.effeciency
    * Referenced by: '<S89>/Generator efficiency'
    */
                          

	  
          

          
          
                  
          

                  real_T P_60; /* Expression: wt.gen.torq.ini
    * Referenced by: '<S105>/Torque Integrator'
    */
                          

	  
          

          
          
                  
          

                  real_T P_61; /* Expression: wt.gen.ini
    * Referenced by: '<S104>/generator int'
    */
                          

	  
          

          
          
                  
          

                  real_T P_62; /* Expression: wt.gen.effeciency
    * Referenced by: '<S105>/Generator efficiency'
    */
                          

	  
          

          
          
                  
          

                  real_T P_63; /* Expression: wt.gen.torq.ini
    * Referenced by: '<S121>/Torque Integrator'
    */
                          

	  
          

          
          
                  
          

                  real_T P_64; /* Expression: wt.gen.ini
    * Referenced by: '<S120>/generator int'
    */
                          

	  
          

          
          
                  
          

                  real_T P_65; /* Expression: wt.gen.effeciency
    * Referenced by: '<S121>/Generator efficiency'
    */
                          

	  
          

          
          
                  
          

                  real_T P_66; /* Expression: wt.gen.torq.ini
    * Referenced by: '<S137>/Torque Integrator'
    */
                          

	  
          

          
          
                  
          

                  real_T P_67; /* Expression: wt.gen.ini
    * Referenced by: '<S136>/generator int'
    */
                          

	  
          

          
          
                  
          

                  real_T P_68; /* Expression: wt.gen.effeciency
    * Referenced by: '<S137>/Generator efficiency'
    */
                          

	  
          

          
          
                  
          

                  real_T P_69; /* Expression: wt.gen.torq.ini
    * Referenced by: '<S153>/Torque Integrator'
    */
                          

	  
          

          
          
                  
          

                  real_T P_70; /* Expression: wt.gen.ini
    * Referenced by: '<S152>/generator int'
    */
                          

	  
          

          
          
                  
          

                  real_T P_71; /* Expression: wt.gen.effeciency
    * Referenced by: '<S153>/Generator efficiency'
    */
                          

	  
          

          
          
                  
          

                  real_T P_72; /* Expression: wt.gen.torq.ini
    * Referenced by: '<S169>/Torque Integrator'
    */
                          

	  
          

          
          
                  
          

                  real_T P_73; /* Expression: wt.gen.ini
    * Referenced by: '<S168>/generator int'
    */
                          

	  
          

          
          
                  
          

                  real_T P_74; /* Expression: wt.gen.effeciency
    * Referenced by: '<S169>/Generator efficiency'
    */
                          

	  
          

          
          
                  
          

                  real_T P_75; /* Expression: wt.gen.torq.ini
    * Referenced by: '<S41>/Torque Integrator'
    */
                          

	  
          

          
          
                  
          

                  real_T P_76; /* Expression: wt.gen.ini
    * Referenced by: '<S40>/generator int'
    */
                          

	  
          

          
          
                  
          

                  real_T P_77; /* Expression: wt.gen.effeciency
    * Referenced by: '<S41>/Generator efficiency'
    */
                          

	  
          

          
          
                  
          

                  real_T P_78; /* Expression: 1
    * Referenced by: '<S11>/Constant'
    */
                          

	  
          

          
          
                  
          

                  real_T P_79; /* Expression: 1
    * Referenced by: '<S13>/Constant'
    */
                          

	  
          

          
          
                  
          

                  real_T P_80; /* Expression: 1
    * Referenced by: '<S14>/Constant'
    */
                          

	  
          

          
          
                  
          

                  real_T P_81; /* Expression: 1
    * Referenced by: '<S15>/Constant'
    */
                          

	  
          

          
          
                  
          

                  real_T P_82; /* Expression: 1
    * Referenced by: '<S16>/Constant'
    */
                          

	  
          

          
          
                  
          

                  real_T P_83; /* Expression: 1
    * Referenced by: '<S17>/Constant'
    */
                          

	  
          

          
          
                  
          

                  real_T P_84; /* Expression: 1
    * Referenced by: '<S18>/Constant'
    */
                          

	  
          

          
          
                  
          

                  real_T P_85; /* Expression: 1
    * Referenced by: '<S19>/Constant'
    */
                          

	  
          

          
          
                  
          

                  real_T P_86; /* Expression: 1
    * Referenced by: '<S20>/Constant'
    */
                          

	  
          

          
          
                  
          

                  real_T P_87; /* Expression: 1
    * Referenced by: '<S12>/Constant'
    */
                          

	  
          

          
          
                  
          

                  real_T P_88; /* Expression: wt.pitch.ini
    * Referenced by: '<S34>/Integrator'
    */
                          

	  
          

          
          
                  
          

                  real_T P_89[9009]; /* Expression: p.wind'
    * Referenced by: '<S193>/Ux_full'
    */
                          

	  
          

          
          
                  
          

                  real_T P_90; /* Expression: 0
    * Referenced by: '<S183>/Nodelay'
    */
                          

	  
          

          
          
                  
          

                  real_T P_91; /* Expression: 0
    * Referenced by: '<S183>/wcDelay2'
    */
                          

	  
          

          
          
                  
          

                  real_T P_92; /* Expression: 0
    * Referenced by: '<S183>/wcDelay3'
    */
                          

	  
          

          
          
                  
          

                  real_T P_93; /* Expression: 0
    * Referenced by: '<S183>/wcDelay4'
    */
                          

	  
          

          
          
                  
          

                  real_T P_94; /* Expression: 0
    * Referenced by: '<S183>/wcDelay5'
    */
                          

	  
          

          
          
                  
          

                  real_T P_95; /* Expression: 0
    * Referenced by: '<S183>/wcDelay6'
    */
                          

	  
          

          
          
                  
          

                  real_T P_96; /* Expression: 0
    * Referenced by: '<S183>/wcDelay7'
    */
                          

	  
          

          
          
                  
          

                  real_T P_97; /* Expression: 0
    * Referenced by: '<S183>/wcDelay8'
    */
                          

	  
          

          
          
                  
          

                  real_T P_98; /* Expression: 0
    * Referenced by: '<S183>/wcDelay9'
    */
                          

	  
          

          
          
                  
          

                  real_T P_99; /* Expression: 0
    * Referenced by: '<S183>/wcDelay10'
    */
                          

	  
          

          
          
                  
          

                  real_T P_100; /* Expression: 0
    * Referenced by: '<S185>/Nodelay'
    */
                          

	  
          

          
          
                  
          

                  real_T P_101; /* Expression: 0
    * Referenced by: '<S185>/wcDelay3'
    */
                          

	  
          

          
          
                  
          

                  real_T P_102; /* Expression: 0
    * Referenced by: '<S185>/wcDelay4'
    */
                          

	  
          

          
          
                  
          

                  real_T P_103; /* Expression: 0
    * Referenced by: '<S185>/wcDelay6'
    */
                          

	  
          

          
          
                  
          

                  real_T P_104; /* Expression: 0
    * Referenced by: '<S185>/wcDelay7'
    */
                          

	  
          

          
          
                  
          

                  real_T P_105; /* Expression: 0
    * Referenced by: '<S185>/wcDelay9'
    */
                          

	  
          

          
          
                  
          

                  real_T P_106; /* Expression: 0
    * Referenced by: '<S185>/wcDelay10'
    */
                          

	  
          

          
          
                  
          

                  real_T P_107; /* Expression: 0
    * Referenced by: '<S186>/Nodelay'
    */
                          

	  
          

          
          
                  
          

                  real_T P_108; /* Expression: 0
    * Referenced by: '<S186>/wcDelay4'
    */
                          

	  
          

          
          
                  
          

                  real_T P_109; /* Expression: 0
    * Referenced by: '<S186>/wcDelay7'
    */
                          

	  
          

          
          
                  
          

                  real_T P_110; /* Expression: 0
    * Referenced by: '<S186>/wcDelay10'
    */
                          

	  
          

          
          
                  
          

                  real_T P_111; /* Expression: 0
    * Referenced by: '<S187>/Nodelay'
    */
                          

	  
          

          
          
                  
          

                  real_T P_112; /* Expression: 0
    * Referenced by: '<S188>/Nodelay'
    */
                          

	  
          

          
          
                  
          

                  real_T P_113; /* Expression: 0
    * Referenced by: '<S188>/wcDelay2'
    */
                          

	  
          

          
          
                  
          

                  real_T P_114; /* Expression: 0
    * Referenced by: '<S188>/wcDelay3'
    */
                          

	  
          

          
          
                  
          

                  real_T P_115; /* Expression: 0
    * Referenced by: '<S188>/wcDelay4'
    */
                          

	  
          

          
          
                  
          

                  real_T P_116; /* Expression: 0
    * Referenced by: '<S188>/wcDelay6'
    */
                          

	  
          

          
          
                  
          

                  real_T P_117; /* Expression: 0
    * Referenced by: '<S188>/wcDelay7'
    */
                          

	  
          

          
          
                  
          

                  real_T P_118; /* Expression: 0
    * Referenced by: '<S188>/wcDelay8'
    */
                          

	  
          

          
          
                  
          

                  real_T P_119; /* Expression: 0
    * Referenced by: '<S188>/wcDelay9'
    */
                          

	  
          

          
          
                  
          

                  real_T P_120; /* Expression: 0
    * Referenced by: '<S188>/wcDelay10'
    */
                          

	  
          

          
          
                  
          

                  real_T P_121; /* Expression: 0
    * Referenced by: '<S189>/Nodelay'
    */
                          

	  
          

          
          
                  
          

                  real_T P_122; /* Expression: 0
    * Referenced by: '<S189>/wcDelay3'
    */
                          

	  
          

          
          
                  
          

                  real_T P_123; /* Expression: 0
    * Referenced by: '<S189>/wcDelay4'
    */
                          

	  
          

          
          
                  
          

                  real_T P_124; /* Expression: 0
    * Referenced by: '<S189>/wcDelay7'
    */
                          

	  
          

          
          
                  
          

                  real_T P_125; /* Expression: 0
    * Referenced by: '<S189>/wcDelay9'
    */
                          

	  
          

          
          
                  
          

                  real_T P_126; /* Expression: 0
    * Referenced by: '<S189>/wcDelay10'
    */
                          

	  
          

          
          
                  
          

                  real_T P_127; /* Expression: 0
    * Referenced by: '<S190>/Nodelay'
    */
                          

	  
          

          
          
                  
          

                  real_T P_128; /* Expression: 0
    * Referenced by: '<S190>/wcDelay4'
    */
                          

	  
          

          
          
                  
          

                  real_T P_129; /* Expression: 0
    * Referenced by: '<S190>/wcDelay10'
    */
                          

	  
          

          
          
                  
          

                  real_T P_130; /* Expression: 0
    * Referenced by: '<S191>/Nodelay'
    */
                          

	  
          

          
          
                  
          

                  real_T P_131; /* Expression: 0
    * Referenced by: '<S191>/wcDelay3'
    */
                          

	  
          

          
          
                  
          

                  real_T P_132; /* Expression: 0
    * Referenced by: '<S191>/wcDelay4'
    */
                          

	  
          

          
          
                  
          

                  real_T P_133; /* Expression: 0
    * Referenced by: '<S191>/wcDelay6'
    */
                          

	  
          

          
          
                  
          

                  real_T P_134; /* Expression: 0
    * Referenced by: '<S191>/wcDelay7'
    */
                          

	  
          

          
          
                  
          

                  real_T P_135; /* Expression: 0
    * Referenced by: '<S191>/wcDelay9'
    */
                          

	  
          

          
          
                  
          

                  real_T P_136; /* Expression: 0
    * Referenced by: '<S191>/wcDelay10'
    */
                          

	  
          

          
          
                  
          

                  real_T P_137; /* Expression: 0
    * Referenced by: '<S192>/Nodelay'
    */
                          

	  
          

          
          
                  
          

                  real_T P_138; /* Expression: 0
    * Referenced by: '<S192>/wcDelay4'
    */
                          

	  
          

          
          
                  
          

                  real_T P_139; /* Expression: 0
    * Referenced by: '<S192>/wcDelay7'
    */
                          

	  
          

          
          
                  
          

                  real_T P_140; /* Expression: 0
    * Referenced by: '<S192>/wcDelay10'
    */
                          

	  
          

          
          
                  
          

                  real_T P_141; /* Expression: 0
    * Referenced by: '<S184>/Nodelay'
    */
                          

	  
          

          
          
                  
          

                  real_T P_142; /* Expression: 0
    * Referenced by: '<S183>/wdDelay2'
    */
                          

	  
          

          
          
                  
          

                  real_T P_143; /* Expression: 0
    * Referenced by: '<S183>/wdDelay3'
    */
                          

	  
          

          
          
                  
          

                  real_T P_144; /* Expression: 0
    * Referenced by: '<S183>/wdDelay4'
    */
                          

	  
          

          
          
                  
          

                  real_T P_145; /* Expression: 0
    * Referenced by: '<S183>/wdDelay5'
    */
                          

	  
          

          
          
                  
          

                  real_T P_146; /* Expression: 0
    * Referenced by: '<S183>/wdDelay6'
    */
                          

	  
          

          
          
                  
          

                  real_T P_147; /* Expression: 0
    * Referenced by: '<S183>/wdDelay7'
    */
                          

	  
          

          
          
                  
          

                  real_T P_148; /* Expression: 0
    * Referenced by: '<S183>/wdDelay8'
    */
                          

	  
          

          
          
                  
          

                  real_T P_149; /* Expression: 0
    * Referenced by: '<S183>/wdDelay9'
    */
                          

	  
          

          
          
                  
          

                  real_T P_150; /* Expression: 0
    * Referenced by: '<S183>/wdDelay10'
    */
                          

	  
          

          
          
                  
          

                  real_T P_151; /* Expression: 0
    * Referenced by: '<S185>/wdDelay3'
    */
                          

	  
          

          
          
                  
          

                  real_T P_152; /* Expression: 0
    * Referenced by: '<S185>/wdDelay4'
    */
                          

	  
          

          
          
                  
          

                  real_T P_153; /* Expression: 0
    * Referenced by: '<S185>/wdDelay6'
    */
                          

	  
          

          
          
                  
          

                  real_T P_154; /* Expression: 0
    * Referenced by: '<S185>/wdDelay7'
    */
                          

	  
          

          
          
                  
          

                  real_T P_155; /* Expression: 0
    * Referenced by: '<S185>/wdDelay9'
    */
                          

	  
          

          
          
                  
          

                  real_T P_156; /* Expression: 0
    * Referenced by: '<S185>/wdDelay10'
    */
                          

	  
          

          
          
                  
          

                  real_T P_157; /* Expression: 0
    * Referenced by: '<S186>/wdDelay4'
    */
                          

	  
          

          
          
                  
          

                  real_T P_158; /* Expression: 0
    * Referenced by: '<S186>/wdDelay7'
    */
                          

	  
          

          
          
                  
          

                  real_T P_159; /* Expression: 0
    * Referenced by: '<S186>/wdDelay10'
    */
                          

	  
          

          
          
                  
          

                  real_T P_160; /* Expression: 0
    * Referenced by: '<S188>/wdDelay2'
    */
                          

	  
          

          
          
                  
          

                  real_T P_161; /* Expression: 0
    * Referenced by: '<S188>/wdDelay3'
    */
                          

	  
          

          
          
                  
          

                  real_T P_162; /* Expression: 0
    * Referenced by: '<S188>/wdDelay4'
    */
                          

	  
          

          
          
                  
          

                  real_T P_163; /* Expression: 0
    * Referenced by: '<S188>/wdDelay6'
    */
                          

	  
          

          
          
                  
          

                  real_T P_164; /* Expression: 0
    * Referenced by: '<S188>/wdDelay7'
    */
                          

	  
          

          
          
                  
          

                  real_T P_165; /* Expression: 0
    * Referenced by: '<S188>/wdDelay8'
    */
                          

	  
          

          
          
                  
          

                  real_T P_166; /* Expression: 0
    * Referenced by: '<S188>/wdDelay9'
    */
                          

	  
          

          
          
                  
          

                  real_T P_167; /* Expression: 0
    * Referenced by: '<S188>/wdDelay10'
    */
                          

	  
          

          
          
                  
          

                  real_T P_168; /* Expression: 0
    * Referenced by: '<S189>/wdDelay3'
    */
                          

	  
          

          
          
                  
          

                  real_T P_169; /* Expression: 0
    * Referenced by: '<S189>/wdDelay4'
    */
                          

	  
          

          
          
                  
          

                  real_T P_170; /* Expression: 0
    * Referenced by: '<S189>/wdDelay7'
    */
                          

	  
          

          
          
                  
          

                  real_T P_171; /* Expression: 0
    * Referenced by: '<S189>/wdDelay9'
    */
                          

	  
          

          
          
                  
          

                  real_T P_172; /* Expression: 0
    * Referenced by: '<S189>/wdDelay10'
    */
                          

	  
          

          
          
                  
          

                  real_T P_173; /* Expression: 0
    * Referenced by: '<S190>/wdDelay4'
    */
                          

	  
          

          
          
                  
          

                  real_T P_174; /* Expression: 0
    * Referenced by: '<S190>/wdDelay10'
    */
                          

	  
          

          
          
                  
          

                  real_T P_175; /* Expression: 0
    * Referenced by: '<S191>/wdDelay3'
    */
                          

	  
          

          
          
                  
          

                  real_T P_176; /* Expression: 0
    * Referenced by: '<S191>/wdDelay4'
    */
                          

	  
          

          
          
                  
          

                  real_T P_177; /* Expression: 0
    * Referenced by: '<S191>/wdDelay6'
    */
                          

	  
          

          
          
                  
          

                  real_T P_178; /* Expression: 0
    * Referenced by: '<S191>/wdDelay7'
    */
                          

	  
          

          
          
                  
          

                  real_T P_179; /* Expression: 0
    * Referenced by: '<S191>/wdDelay9'
    */
                          

	  
          

          
          
                  
          

                  real_T P_180; /* Expression: 0
    * Referenced by: '<S191>/wdDelay10'
    */
                          

	  
          

          
          
                  
          

                  real_T P_181; /* Expression: 0
    * Referenced by: '<S192>/wdDelay4'
    */
                          

	  
          

          
          
                  
          

                  real_T P_182; /* Expression: 0
    * Referenced by: '<S192>/wdDelay7'
    */
                          

	  
          

          
          
                  
          

                  real_T P_183; /* Expression: 0
    * Referenced by: '<S192>/wdDelay10'
    */
                          

	  
          

          
          
                  
          

                  real_T P_184; /* Expression: 0
    * Referenced by: '<S183>/ctDelay2'
    */
                          

	  
          

          
          
                  
          

                  real_T P_185; /* Expression: 0
    * Referenced by: '<S183>/ctDelay3'
    */
                          

	  
          

          
          
                  
          

                  real_T P_186; /* Expression: 0
    * Referenced by: '<S183>/ctDelay4'
    */
                          

	  
          

          
          
                  
          

                  real_T P_187; /* Expression: 0
    * Referenced by: '<S183>/ctDelay5'
    */
                          

	  
          

          
          
                  
          

                  real_T P_188; /* Expression: 0
    * Referenced by: '<S183>/ctDelay6'
    */
                          

	  
          

          
          
                  
          

                  real_T P_189; /* Expression: 0
    * Referenced by: '<S183>/ctDelay7'
    */
                          

	  
          

          
          
                  
          

                  real_T P_190; /* Expression: 0
    * Referenced by: '<S183>/ctDelay8'
    */
                          

	  
          

          
          
                  
          

                  real_T P_191; /* Expression: 0
    * Referenced by: '<S183>/ctDelay9'
    */
                          

	  
          

          
          
                  
          

                  real_T P_192; /* Expression: 0
    * Referenced by: '<S183>/ctDelay10'
    */
                          

	  
          

          
          
                  
          

                  real_T P_193; /* Expression: 0
    * Referenced by: '<S185>/ctDelay3'
    */
                          

	  
          

          
          
                  
          

                  real_T P_194; /* Expression: 0
    * Referenced by: '<S185>/ctDelay4'
    */
                          

	  
          

          
          
                  
          

                  real_T P_195; /* Expression: 0
    * Referenced by: '<S185>/ctDelay6'
    */
                          

	  
          

          
          
                  
          

                  real_T P_196; /* Expression: 0
    * Referenced by: '<S185>/ctDelay7'
    */
                          

	  
          

          
          
                  
          

                  real_T P_197; /* Expression: 0
    * Referenced by: '<S185>/ctDelay9'
    */
                          

	  
          

          
          
                  
          

                  real_T P_198; /* Expression: 0
    * Referenced by: '<S185>/ctDelay10'
    */
                          

	  
          

          
          
                  
          

                  real_T P_199; /* Expression: 0
    * Referenced by: '<S186>/ctDelay4'
    */
                          

	  
          

          
          
                  
          

                  real_T P_200; /* Expression: 0
    * Referenced by: '<S186>/ctDelay7'
    */
                          

	  
          

          
          
                  
          

                  real_T P_201; /* Expression: 0
    * Referenced by: '<S186>/ctDelay10'
    */
                          

	  
          

          
          
                  
          

                  real_T P_202; /* Expression: 0
    * Referenced by: '<S188>/ctDelay2'
    */
                          

	  
          

          
          
                  
          

                  real_T P_203; /* Expression: 0
    * Referenced by: '<S188>/ctDelay3'
    */
                          

	  
          

          
          
                  
          

                  real_T P_204; /* Expression: 0
    * Referenced by: '<S188>/ctDelay4'
    */
                          

	  
          

          
          
                  
          

                  real_T P_205; /* Expression: 0
    * Referenced by: '<S188>/ctDelay6'
    */
                          

	  
          

          
          
                  
          

                  real_T P_206; /* Expression: 0
    * Referenced by: '<S188>/ctDelay7'
    */
                          

	  
          

          
          
                  
          

                  real_T P_207; /* Expression: 0
    * Referenced by: '<S188>/ctDelay8'
    */
                          

	  
          

          
          
                  
          

                  real_T P_208; /* Expression: 0
    * Referenced by: '<S188>/ctDelay9'
    */
                          

	  
          

          
          
                  
          

                  real_T P_209; /* Expression: 0
    * Referenced by: '<S188>/ctDelay10'
    */
                          

	  
          

          
          
                  
          

                  real_T P_210; /* Expression: 0
    * Referenced by: '<S189>/ctDelay3'
    */
                          

	  
          

          
          
                  
          

                  real_T P_211; /* Expression: 0
    * Referenced by: '<S189>/ctDelay4'
    */
                          

	  
          

          
          
                  
          

                  real_T P_212; /* Expression: 0
    * Referenced by: '<S189>/ctDelay7'
    */
                          

	  
          

          
          
                  
          

                  real_T P_213; /* Expression: 0
    * Referenced by: '<S189>/ctDelay9'
    */
                          

	  
          

          
          
                  
          

                  real_T P_214; /* Expression: 0
    * Referenced by: '<S189>/ctDelay10'
    */
                          

	  
          

          
          
                  
          

                  real_T P_215; /* Expression: 0
    * Referenced by: '<S190>/ctDelay4'
    */
                          

	  
          

          
          
                  
          

                  real_T P_216; /* Expression: 0
    * Referenced by: '<S190>/ctDelay10'
    */
                          

	  
          

          
          
                  
          

                  real_T P_217; /* Expression: 0
    * Referenced by: '<S191>/ctDelay3'
    */
                          

	  
          

          
          
                  
          

                  real_T P_218; /* Expression: 0
    * Referenced by: '<S191>/ctDelay4'
    */
                          

	  
          

          
          
                  
          

                  real_T P_219; /* Expression: 0
    * Referenced by: '<S191>/ctDelay6'
    */
                          

	  
          

          
          
                  
          

                  real_T P_220; /* Expression: 0
    * Referenced by: '<S191>/ctDelay7'
    */
                          

	  
          

          
          
                  
          

                  real_T P_221; /* Expression: 0
    * Referenced by: '<S191>/ctDelay9'
    */
                          

	  
          

          
          
                  
          

                  real_T P_222; /* Expression: 0
    * Referenced by: '<S191>/ctDelay10'
    */
                          

	  
          

          
          
                  
          

                  real_T P_223; /* Expression: 0
    * Referenced by: '<S192>/ctDelay4'
    */
                          

	  
          

          
          
                  
          

                  real_T P_224; /* Expression: 0
    * Referenced by: '<S192>/ctDelay7'
    */
                          

	  
          

          
          
                  
          

                  real_T P_225; /* Expression: 0
    * Referenced by: '<S192>/ctDelay10'
    */
                          

	  
          

          
          
                  
          

                  real_T P_226; /* Expression: Px_UseExternalTower
    * Referenced by: '<S11>/Constant1'
    */
                          

	  
          

          
          
                  
          

                  real_T P_227[3]; /* Computed Parameter: P_227
    * Referenced by: '<S36>/Tower'
    */
                          

	  
          

          
          
                  
          

                  real_T P_228; /* Computed Parameter: P_228
    * Referenced by: '<S36>/Tower'
    */
                          

	  
          

          
          
                  
          

                  real_T P_229[2]; /* Computed Parameter: P_229
    * Referenced by: '<S36>/Tower'
    */
                          

	  
          

          
          
                  
          

                  real_T P_230[2]; /* Expression: zeros(2,1)
    * Referenced by: '<S36>/Tower'
    */
                          

	  
          

          
          
                  
          

                  real_T P_231; /* Expression: 0.5
    * Referenced by: '<S11>/Switch'
    */
                          

	  
          

          
          
                  
          

                  real_T P_232; /* Expression: wt.rotor.ini
    * Referenced by: '<S24>/rotor int'
    */
                          

	  
          

          
          
                  
          

                  real_T P_233; /* Expression: wt.rotor.radius
    * Referenced by: '<S21>/rotor radius'
    */
                          

	  
          

          
          
                  
          

                  real_T P_234[451]; /* Expression: wt.ct.beta
    * Referenced by: '<S29>/C_T table'
    */
                          

	  
          

          
          
                  
          

                  real_T P_235[250]; /* Expression: wt.ct.tsr
    * Referenced by: '<S29>/C_T table'
    */
                          

	  
          

          
          
                  
          

                  real_T P_236[112750]; /* Expression: wt.ct.table
    * Referenced by: '<S29>/C_T table'
    */
                          

	  
          

          
          
                  
          

                  real_T P_237; /* Expression: wt.pitch.ini
    * Referenced by: '<S66>/Integrator'
    */
                          

	  
          

          
          
                  
          

                  real_T P_238[9009]; /* Expression: p.wind'
    * Referenced by: '<S195>/Ux_full'
    */
                          

	  
          

          
          
                  
          

                  real_T P_239; /* Expression: Px_UseExternalTower
    * Referenced by: '<S13>/Constant1'
    */
                          

	  
          

          
          
                  
          

                  real_T P_240[3]; /* Computed Parameter: P_240
    * Referenced by: '<S68>/Tower'
    */
                          

	  
          

          
          
                  
          

                  real_T P_241; /* Computed Parameter: P_241
    * Referenced by: '<S68>/Tower'
    */
                          

	  
          

          
          
                  
          

                  real_T P_242[2]; /* Computed Parameter: P_242
    * Referenced by: '<S68>/Tower'
    */
                          

	  
          

          
          
                  
          

                  real_T P_243[2]; /* Expression: zeros(2,1)
    * Referenced by: '<S68>/Tower'
    */
                          

	  
          

          
          
                  
          

                  real_T P_244; /* Expression: 0.5
    * Referenced by: '<S13>/Switch'
    */
                          

	  
          

          
          
                  
          

                  real_T P_245; /* Expression: wt.rotor.ini
    * Referenced by: '<S56>/rotor int'
    */
                          

	  
          

          
          
                  
          

                  real_T P_246; /* Expression: wt.rotor.radius
    * Referenced by: '<S53>/rotor radius'
    */
                          

	  
          

          
          
                  
          

                  real_T P_247[451]; /* Expression: wt.ct.beta
    * Referenced by: '<S61>/C_T table'
    */
                          

	  
          

          
          
                  
          

                  real_T P_248[250]; /* Expression: wt.ct.tsr
    * Referenced by: '<S61>/C_T table'
    */
                          

	  
          

          
          
                  
          

                  real_T P_249[112750]; /* Expression: wt.ct.table
    * Referenced by: '<S61>/C_T table'
    */
                          

	  
          

          
          
                  
          

                  real_T P_250; /* Expression: wt.pitch.ini
    * Referenced by: '<S82>/Integrator'
    */
                          

	  
          

          
          
                  
          

                  real_T P_251[9009]; /* Expression: p.wind'
    * Referenced by: '<S196>/Ux_full'
    */
                          

	  
          

          
          
                  
          

                  real_T P_252; /* Expression: Px_UseExternalTower
    * Referenced by: '<S14>/Constant1'
    */
                          

	  
          

          
          
                  
          

                  real_T P_253[3]; /* Computed Parameter: P_253
    * Referenced by: '<S84>/Tower'
    */
                          

	  
          

          
          
                  
          

                  real_T P_254; /* Computed Parameter: P_254
    * Referenced by: '<S84>/Tower'
    */
                          

	  
          

          
          
                  
          

                  real_T P_255[2]; /* Computed Parameter: P_255
    * Referenced by: '<S84>/Tower'
    */
                          

	  
          

          
          
                  
          

                  real_T P_256[2]; /* Expression: zeros(2,1)
    * Referenced by: '<S84>/Tower'
    */
                          

	  
          

          
          
                  
          

                  real_T P_257; /* Expression: 0.5
    * Referenced by: '<S14>/Switch'
    */
                          

	  
          

          
          
                  
          

                  real_T P_258; /* Expression: wt.rotor.ini
    * Referenced by: '<S72>/rotor int'
    */
                          

	  
          

          
          
                  
          

                  real_T P_259; /* Expression: wt.rotor.radius
    * Referenced by: '<S69>/rotor radius'
    */
                          

	  
          

          
          
                  
          

                  real_T P_260[451]; /* Expression: wt.ct.beta
    * Referenced by: '<S77>/C_T table'
    */
                          

	  
          

          
          
                  
          

                  real_T P_261[250]; /* Expression: wt.ct.tsr
    * Referenced by: '<S77>/C_T table'
    */
                          

	  
          

          
          
                  
          

                  real_T P_262[112750]; /* Expression: wt.ct.table
    * Referenced by: '<S77>/C_T table'
    */
                          

	  
          

          
          
                  
          

                  real_T P_263; /* Expression: wt.pitch.ini
    * Referenced by: '<S98>/Integrator'
    */
                          

	  
          

          
          
                  
          

                  real_T P_264[9009]; /* Expression: p.wind'
    * Referenced by: '<S197>/Ux_full'
    */
                          

	  
          

          
          
                  
          

                  real_T P_265; /* Expression: Px_UseExternalTower
    * Referenced by: '<S15>/Constant1'
    */
                          

	  
          

          
          
                  
          

                  real_T P_266[3]; /* Computed Parameter: P_266
    * Referenced by: '<S100>/Tower'
    */
                          

	  
          

          
          
                  
          

                  real_T P_267; /* Computed Parameter: P_267
    * Referenced by: '<S100>/Tower'
    */
                          

	  
          

          
          
                  
          

                  real_T P_268[2]; /* Computed Parameter: P_268
    * Referenced by: '<S100>/Tower'
    */
                          

	  
          

          
          
                  
          

                  real_T P_269[2]; /* Expression: zeros(2,1)
    * Referenced by: '<S100>/Tower'
    */
                          

	  
          

          
          
                  
          

                  real_T P_270; /* Expression: 0.5
    * Referenced by: '<S15>/Switch'
    */
                          

	  
          

          
          
                  
          

                  real_T P_271; /* Expression: wt.rotor.ini
    * Referenced by: '<S88>/rotor int'
    */
                          

	  
          

          
          
                  
          

                  real_T P_272; /* Expression: wt.rotor.radius
    * Referenced by: '<S85>/rotor radius'
    */
                          

	  
          

          
          
                  
          

                  real_T P_273[451]; /* Expression: wt.ct.beta
    * Referenced by: '<S93>/C_T table'
    */
                          

	  
          

          
          
                  
          

                  real_T P_274[250]; /* Expression: wt.ct.tsr
    * Referenced by: '<S93>/C_T table'
    */
                          

	  
          

          
          
                  
          

                  real_T P_275[112750]; /* Expression: wt.ct.table
    * Referenced by: '<S93>/C_T table'
    */
                          

	  
          

          
          
                  
          

                  real_T P_276; /* Expression: wt.pitch.ini
    * Referenced by: '<S114>/Integrator'
    */
                          

	  
          

          
          
                  
          

                  real_T P_277[9009]; /* Expression: p.wind'
    * Referenced by: '<S198>/Ux_full'
    */
                          

	  
          

          
          
                  
          

                  real_T P_278; /* Expression: Px_UseExternalTower
    * Referenced by: '<S16>/Constant1'
    */
                          

	  
          

          
          
                  
          

                  real_T P_279[3]; /* Computed Parameter: P_279
    * Referenced by: '<S116>/Tower'
    */
                          

	  
          

          
          
                  
          

                  real_T P_280; /* Computed Parameter: P_280
    * Referenced by: '<S116>/Tower'
    */
                          

	  
          

          
          
                  
          

                  real_T P_281[2]; /* Computed Parameter: P_281
    * Referenced by: '<S116>/Tower'
    */
                          

	  
          

          
          
                  
          

                  real_T P_282[2]; /* Expression: zeros(2,1)
    * Referenced by: '<S116>/Tower'
    */
                          

	  
          

          
          
                  
          

                  real_T P_283; /* Expression: 0.5
    * Referenced by: '<S16>/Switch'
    */
                          

	  
          

          
          
                  
          

                  real_T P_284; /* Expression: wt.rotor.ini
    * Referenced by: '<S104>/rotor int'
    */
                          

	  
          

          
          
                  
          

                  real_T P_285; /* Expression: wt.rotor.radius
    * Referenced by: '<S101>/rotor radius'
    */
                          

	  
          

          
          
                  
          

                  real_T P_286[451]; /* Expression: wt.ct.beta
    * Referenced by: '<S109>/C_T table'
    */
                          

	  
          

          
          
                  
          

                  real_T P_287[250]; /* Expression: wt.ct.tsr
    * Referenced by: '<S109>/C_T table'
    */
                          

	  
          

          
          
                  
          

                  real_T P_288[112750]; /* Expression: wt.ct.table
    * Referenced by: '<S109>/C_T table'
    */
                          

	  
          

          
          
                  
          

                  real_T P_289; /* Expression: wt.pitch.ini
    * Referenced by: '<S130>/Integrator'
    */
                          

	  
          

          
          
                  
          

                  real_T P_290[9009]; /* Expression: p.wind'
    * Referenced by: '<S199>/Ux_full'
    */
                          

	  
          

          
          
                  
          

                  real_T P_291; /* Expression: Px_UseExternalTower
    * Referenced by: '<S17>/Constant1'
    */
                          

	  
          

          
          
                  
          

                  real_T P_292[3]; /* Computed Parameter: P_292
    * Referenced by: '<S132>/Tower'
    */
                          

	  
          

          
          
                  
          

                  real_T P_293; /* Computed Parameter: P_293
    * Referenced by: '<S132>/Tower'
    */
                          

	  
          

          
          
                  
          

                  real_T P_294[2]; /* Computed Parameter: P_294
    * Referenced by: '<S132>/Tower'
    */
                          

	  
          

          
          
                  
          

                  real_T P_295[2]; /* Expression: zeros(2,1)
    * Referenced by: '<S132>/Tower'
    */
                          

	  
          

          
          
                  
          

                  real_T P_296; /* Expression: 0.5
    * Referenced by: '<S17>/Switch'
    */
                          

	  
          

          
          
                  
          

                  real_T P_297; /* Expression: wt.rotor.ini
    * Referenced by: '<S120>/rotor int'
    */
                          

	  
          

          
          
                  
          

                  real_T P_298; /* Expression: wt.rotor.radius
    * Referenced by: '<S117>/rotor radius'
    */
                          

	  
          

          
          
                  
          

                  real_T P_299[451]; /* Expression: wt.ct.beta
    * Referenced by: '<S125>/C_T table'
    */
                          

	  
          

          
          
                  
          

                  real_T P_300[250]; /* Expression: wt.ct.tsr
    * Referenced by: '<S125>/C_T table'
    */
                          

	  
          

          
          
                  
          

                  real_T P_301[112750]; /* Expression: wt.ct.table
    * Referenced by: '<S125>/C_T table'
    */
                          

	  
          

          
          
                  
          

                  real_T P_302; /* Expression: wt.pitch.ini
    * Referenced by: '<S146>/Integrator'
    */
                          

	  
          

          
          
                  
          

                  real_T P_303[9009]; /* Expression: p.wind'
    * Referenced by: '<S200>/Ux_full'
    */
                          

	  
          

          
          
                  
          

                  real_T P_304; /* Expression: Px_UseExternalTower
    * Referenced by: '<S18>/Constant1'
    */
                          

	  
          

          
          
                  
          

                  real_T P_305[3]; /* Computed Parameter: P_305
    * Referenced by: '<S148>/Tower'
    */
                          

	  
          

          
          
                  
          

                  real_T P_306; /* Computed Parameter: P_306
    * Referenced by: '<S148>/Tower'
    */
                          

	  
          

          
          
                  
          

                  real_T P_307[2]; /* Computed Parameter: P_307
    * Referenced by: '<S148>/Tower'
    */
                          

	  
          

          
          
                  
          

                  real_T P_308[2]; /* Expression: zeros(2,1)
    * Referenced by: '<S148>/Tower'
    */
                          

	  
          

          
          
                  
          

                  real_T P_309; /* Expression: 0.5
    * Referenced by: '<S18>/Switch'
    */
                          

	  
          

          
          
                  
          

                  real_T P_310; /* Expression: wt.rotor.ini
    * Referenced by: '<S136>/rotor int'
    */
                          

	  
          

          
          
                  
          

                  real_T P_311; /* Expression: wt.rotor.radius
    * Referenced by: '<S133>/rotor radius'
    */
                          

	  
          

          
          
                  
          

                  real_T P_312[451]; /* Expression: wt.ct.beta
    * Referenced by: '<S141>/C_T table'
    */
                          

	  
          

          
          
                  
          

                  real_T P_313[250]; /* Expression: wt.ct.tsr
    * Referenced by: '<S141>/C_T table'
    */
                          

	  
          

          
          
                  
          

                  real_T P_314[112750]; /* Expression: wt.ct.table
    * Referenced by: '<S141>/C_T table'
    */
                          

	  
          

          
          
                  
          

                  real_T P_315; /* Expression: wt.pitch.ini
    * Referenced by: '<S162>/Integrator'
    */
                          

	  
          

          
          
                  
          

                  real_T P_316[9009]; /* Expression: p.wind'
    * Referenced by: '<S201>/Ux_full'
    */
                          

	  
          

          
          
                  
          

                  real_T P_317; /* Expression: Px_UseExternalTower
    * Referenced by: '<S19>/Constant1'
    */
                          

	  
          

          
          
                  
          

                  real_T P_318[3]; /* Computed Parameter: P_318
    * Referenced by: '<S164>/Tower'
    */
                          

	  
          

          
          
                  
          

                  real_T P_319; /* Computed Parameter: P_319
    * Referenced by: '<S164>/Tower'
    */
                          

	  
          

          
          
                  
          

                  real_T P_320[2]; /* Computed Parameter: P_320
    * Referenced by: '<S164>/Tower'
    */
                          

	  
          

          
          
                  
          

                  real_T P_321[2]; /* Expression: zeros(2,1)
    * Referenced by: '<S164>/Tower'
    */
                          

	  
          

          
          
                  
          

                  real_T P_322; /* Expression: 0.5
    * Referenced by: '<S19>/Switch'
    */
                          

	  
          

          
          
                  
          

                  real_T P_323; /* Expression: wt.rotor.ini
    * Referenced by: '<S152>/rotor int'
    */
                          

	  
          

          
          
                  
          

                  real_T P_324; /* Expression: wt.rotor.radius
    * Referenced by: '<S149>/rotor radius'
    */
                          

	  
          

          
          
                  
          

                  real_T P_325[451]; /* Expression: wt.ct.beta
    * Referenced by: '<S157>/C_T table'
    */
                          

	  
          

          
          
                  
          

                  real_T P_326[250]; /* Expression: wt.ct.tsr
    * Referenced by: '<S157>/C_T table'
    */
                          

	  
          

          
          
                  
          

                  real_T P_327[112750]; /* Expression: wt.ct.table
    * Referenced by: '<S157>/C_T table'
    */
                          

	  
          

          
          
                  
          

                  real_T P_328; /* Expression: wt.pitch.ini
    * Referenced by: '<S178>/Integrator'
    */
                          

	  
          

          
          
                  
          

                  real_T P_329[9009]; /* Expression: p.wind'
    * Referenced by: '<S202>/Ux_full'
    */
                          

	  
          

          
          
                  
          

                  real_T P_330; /* Expression: Px_UseExternalTower
    * Referenced by: '<S20>/Constant1'
    */
                          

	  
          

          
          
                  
          

                  real_T P_331[3]; /* Computed Parameter: P_331
    * Referenced by: '<S180>/Tower'
    */
                          

	  
          

          
          
                  
          

                  real_T P_332; /* Computed Parameter: P_332
    * Referenced by: '<S180>/Tower'
    */
                          

	  
          

          
          
                  
          

                  real_T P_333[2]; /* Computed Parameter: P_333
    * Referenced by: '<S180>/Tower'
    */
                          

	  
          

          
          
                  
          

                  real_T P_334[2]; /* Expression: zeros(2,1)
    * Referenced by: '<S180>/Tower'
    */
                          

	  
          

          
          
                  
          

                  real_T P_335; /* Expression: 0.5
    * Referenced by: '<S20>/Switch'
    */
                          

	  
          

          
          
                  
          

                  real_T P_336; /* Expression: wt.rotor.ini
    * Referenced by: '<S168>/rotor int'
    */
                          

	  
          

          
          
                  
          

                  real_T P_337; /* Expression: wt.rotor.radius
    * Referenced by: '<S165>/rotor radius'
    */
                          

	  
          

          
          
                  
          

                  real_T P_338[451]; /* Expression: wt.ct.beta
    * Referenced by: '<S173>/C_T table'
    */
                          

	  
          

          
          
                  
          

                  real_T P_339[250]; /* Expression: wt.ct.tsr
    * Referenced by: '<S173>/C_T table'
    */
                          

	  
          

          
          
                  
          

                  real_T P_340[112750]; /* Expression: wt.ct.table
    * Referenced by: '<S173>/C_T table'
    */
                          

	  
          

          
          
                  
          

                  real_T P_341; /* Expression: wt.pitch.ini
    * Referenced by: '<S50>/Integrator'
    */
                          

	  
          

          
          
                  
          

                  real_T P_342[9009]; /* Expression: p.wind'
    * Referenced by: '<S194>/Ux_full'
    */
                          

	  
          

          
          
                  
          

                  real_T P_343; /* Expression: Px_UseExternalTower
    * Referenced by: '<S12>/Constant1'
    */
                          

	  
          

          
          
                  
          

                  real_T P_344[3]; /* Computed Parameter: P_344
    * Referenced by: '<S52>/Tower'
    */
                          

	  
          

          
          
                  
          

                  real_T P_345; /* Computed Parameter: P_345
    * Referenced by: '<S52>/Tower'
    */
                          

	  
          

          
          
                  
          

                  real_T P_346[2]; /* Computed Parameter: P_346
    * Referenced by: '<S52>/Tower'
    */
                          

	  
          

          
          
                  
          

                  real_T P_347[2]; /* Expression: zeros(2,1)
    * Referenced by: '<S52>/Tower'
    */
                          

	  
          

          
          
                  
          

                  real_T P_348; /* Expression: 0.5
    * Referenced by: '<S12>/Switch'
    */
                          

	  
          

          
          
                  
          

                  real_T P_349; /* Expression: wt.rotor.ini
    * Referenced by: '<S40>/rotor int'
    */
                          

	  
          

          
          
                  
          

                  real_T P_350; /* Expression: wt.rotor.radius
    * Referenced by: '<S37>/rotor radius'
    */
                          

	  
          

          
          
                  
          

                  real_T P_351[451]; /* Expression: wt.ct.beta
    * Referenced by: '<S45>/C_T table'
    */
                          

	  
          

          
          
                  
          

                  real_T P_352[250]; /* Expression: wt.ct.tsr
    * Referenced by: '<S45>/C_T table'
    */
                          

	  
          

          
          
                  
          

                  real_T P_353[112750]; /* Expression: wt.ct.table
    * Referenced by: '<S45>/C_T table'
    */
                          

	  
          

          
          
                  
          

                  real_T P_354; /* Expression: frequencygain
    * Referenced by: '<S2>/Active power diff to freq'
    */
                          

	  
          

          
          
                  
          

                  real_T P_355; /* Expression: parm.delay
    * Referenced by: '<S4>/F_meas delay'
    */
                          

	  
          

          
          
                  
          

                  real_T P_356; /* Expression: 0
    * Referenced by: '<S4>/F_meas delay'
    */
                          

	  
          

          
          
                  
          

                  real_T P_357; /* Expression: parm.delay
    * Referenced by: '<S4>/P meas delay'
    */
                          

	  
          

          
          
                  
          

                  real_T P_358; /* Expression: 0
    * Referenced by: '<S4>/P meas delay'
    */
                          

	  
          

          
          
                  
          

                  real_T P_359; /* Expression: parm.settings
    * Referenced by: '<S4>/settings'
    */
                          

	  
          

          
          
                  
          

                  real_T P_360; /* Expression: 0
    * Referenced by: '<S4>/Unit Delay'
    */
                          

	  
          

          
          
                  
          

                  real_T P_361; /* Expression: 0
    * Referenced by: '<S24>/torsion int'
    */
                          

	  
          

          
          
                  
          

                  real_T P_362; /* Expression: wt.rotor.spring
    * Referenced by: '<S24>/Main shaft  spring constant  K [Nm//rad]'
    */
                          

	  
          

          
          
                  
          

                  real_T P_363; /* Expression: 0
    * Referenced by: '<S56>/torsion int'
    */
                          

	  
          

          
          
                  
          

                  real_T P_364; /* Expression: wt.rotor.spring
    * Referenced by: '<S56>/Main shaft  spring constant  K [Nm//rad]'
    */
                          

	  
          

          
          
                  
          

                  real_T P_365; /* Expression: 0
    * Referenced by: '<S72>/torsion int'
    */
                          

	  
          

          
          
                  
          

                  real_T P_366; /* Expression: wt.rotor.spring
    * Referenced by: '<S72>/Main shaft  spring constant  K [Nm//rad]'
    */
                          

	  
          

          
          
                  
          

                  real_T P_367; /* Expression: 0
    * Referenced by: '<S88>/torsion int'
    */
                          

	  
          

          
          
                  
          

                  real_T P_368; /* Expression: wt.rotor.spring
    * Referenced by: '<S88>/Main shaft  spring constant  K [Nm//rad]'
    */
                          

	  
          

          
          
                  
          

                  real_T P_369; /* Expression: 0
    * Referenced by: '<S104>/torsion int'
    */
                          

	  
          

          
          
                  
          

                  real_T P_370; /* Expression: wt.rotor.spring
    * Referenced by: '<S104>/Main shaft  spring constant  K [Nm//rad]'
    */
                          

	  
          

          
          
                  
          

                  real_T P_371; /* Expression: 0
    * Referenced by: '<S120>/torsion int'
    */
                          

	  
          

          
          
                  
          

                  real_T P_372; /* Expression: wt.rotor.spring
    * Referenced by: '<S120>/Main shaft  spring constant  K [Nm//rad]'
    */
                          

	  
          

          
          
                  
          

                  real_T P_373; /* Expression: 0
    * Referenced by: '<S136>/torsion int'
    */
                          

	  
          

          
          
                  
          

                  real_T P_374; /* Expression: wt.rotor.spring
    * Referenced by: '<S136>/Main shaft  spring constant  K [Nm//rad]'
    */
                          

	  
          

          
          
                  
          

                  real_T P_375; /* Expression: 0
    * Referenced by: '<S152>/torsion int'
    */
                          

	  
          

          
          
                  
          

                  real_T P_376; /* Expression: wt.rotor.spring
    * Referenced by: '<S152>/Main shaft  spring constant  K [Nm//rad]'
    */
                          

	  
          

          
          
                  
          

                  real_T P_377; /* Expression: 0
    * Referenced by: '<S168>/torsion int'
    */
                          

	  
          

          
          
                  
          

                  real_T P_378; /* Expression: wt.rotor.spring
    * Referenced by: '<S168>/Main shaft  spring constant  K [Nm//rad]'
    */
                          

	  
          

          
          
                  
          

                  real_T P_379; /* Expression: 0
    * Referenced by: '<S40>/torsion int'
    */
                          

	  
          

          
          
                  
          

                  real_T P_380; /* Expression: wt.rotor.spring
    * Referenced by: '<S40>/Main shaft  spring constant  K [Nm//rad]'
    */
                          

	  
          

          
          
                  
          

                  real_T P_381; /* Expression: wt.tower.height
    * Referenced by: '<S28>/F_t*h'
    */
                          

	  
          

          
          
                  
          

                  real_T P_382; /* Expression: wt.tower.height
    * Referenced by: '<S60>/F_t*h'
    */
                          

	  
          

          
          
                  
          

                  real_T P_383; /* Expression: wt.tower.height
    * Referenced by: '<S76>/F_t*h'
    */
                          

	  
          

          
          
                  
          

                  real_T P_384; /* Expression: wt.tower.height
    * Referenced by: '<S92>/F_t*h'
    */
                          

	  
          

          
          
                  
          

                  real_T P_385; /* Expression: wt.tower.height
    * Referenced by: '<S108>/F_t*h'
    */
                          

	  
          

          
          
                  
          

                  real_T P_386; /* Expression: wt.tower.height
    * Referenced by: '<S124>/F_t*h'
    */
                          

	  
          

          
          
                  
          

                  real_T P_387; /* Expression: wt.tower.height
    * Referenced by: '<S140>/F_t*h'
    */
                          

	  
          

          
          
                  
          

                  real_T P_388; /* Expression: wt.tower.height
    * Referenced by: '<S156>/F_t*h'
    */
                          

	  
          

          
          
                  
          

                  real_T P_389; /* Expression: wt.tower.height
    * Referenced by: '<S172>/F_t*h'
    */
                          

	  
          

          
          
                  
          

                  real_T P_390; /* Expression: wt.tower.height
    * Referenced by: '<S44>/F_t*h'
    */
                          

	  
          

          
          
                  
          

                  real_T P_391[451]; /* Expression: wt.cp.beta
    * Referenced by: '<S29>/C_P table '
    */
                          

	  
          

          
          
                  
          

                  real_T P_392[250]; /* Expression: wt.cp.tsr
    * Referenced by: '<S29>/C_P table '
    */
                          

	  
          

          
          
                  
          

                  real_T P_393[112750]; /* Expression: wt.cp.table
    * Referenced by: '<S29>/C_P table '
    */
                          

	  
          

          
          
                  
          

                  real_T P_394; /* Expression: env.rho*.5* pi * wt.rotor.radius^2
    * Referenced by: '<S21>/rho//2*A'
    */
                          

	  
          

          
          
                  
          

                  real_T P_395; /* Expression: Px_UseExternalControl
    * Referenced by: '<S11>/Constant2'
    */
                          

	  
          

          
          
                  
          

                  real_T P_396; /* Expression: 1/wt.ctrl.gen.effeciency
    * Referenced by: '<S23>/Generator efficiency  compensation'
    */
                          

	  
          

          
          
                  
          

                  real_T P_397; /* Expression: wt.ctrl.p_rated
    * Referenced by: '<S23>/Limit power  to rated'
    */
                          

	  
          

          
          
                  
          

                  real_T P_398; /* Expression: 0
    * Referenced by: '<S23>/Limit power  to rated'
    */
                          

	  
          

          
          
                  
          

                  real_T P_399; /* Computed Parameter: P_399
    * Referenced by: '<S23>/Measurement filter (low pass)'
    */
                          

	  
          

          
          
                  
          

                  real_T P_400; /* Computed Parameter: P_400
    * Referenced by: '<S23>/Measurement filter (low pass)'
    */
                          

	  
          

          
          
                  
          

                  real_T P_401; /* Computed Parameter: P_401
    * Referenced by: '<S23>/Measurement filter (low pass)'
    */
                          

	  
          

          
          
                  
          

                  real_T P_402; /* Computed Parameter: P_402
    * Referenced by: '<S23>/Measurement filter (low pass)'
    */
                          

	  
          

          
          
                  
          

                  real_T P_403; /* Expression: wt.ctrl.gen.ini
    * Referenced by: '<S23>/Measurement filter (low pass)'
    */
                          

	  
          

          
          
                  
          

                  real_T P_404; /* Expression: wt.ctrl.gen.rated
    * Referenced by: '<S23>/Rated speed'
    */
                          

	  
          

          
          
                  
          

                  real_T P_405[1230]; /* Expression: wt.ctrl.torq.wg
    * Referenced by: '<S23>/Torque - speed lookup table'
    */
                          

	  
          

          
          
                  
          

                  real_T P_406[1230]; /* Expression: wt.ctrl.torq.M
    * Referenced by: '<S23>/Torque - speed lookup table'
    */
                          

	  
          

          
          
                  
          

                  real_T P_407; /* Expression: const
    * Referenced by: '<S33>/Constant'
    */
                          

	  
          

          
          
                  
          

                  real_T P_408; /* Expression: 0.0
    * Referenced by: '<S31>/Integer Delay'
    */
                          

	  
          

          
          
                  
          

                  real_T P_409; /* Expression: const
    * Referenced by: '<S32>/Constant'
    */
                          

	  
          

          
          
                  
          

                  real_T P_410; /* Expression: wt.ctrl.torq.lim
    * Referenced by: '<S23>/Saturation'
    */
                          

	  
          

          
          
                  
          

                  real_T P_411; /* Expression: 0
    * Referenced by: '<S23>/Saturation'
    */
                          

	  
          

          
          
                  
          

                  real_T P_412; /* Computed Parameter: P_412
    * Referenced by: '<S23>/Rate Limiter'
    */
                          

	  
          

          
          
                  
          

                  real_T P_413; /* Computed Parameter: P_413
    * Referenced by: '<S23>/Rate Limiter'
    */
                          

	  
          

          
          
                  
          

                  real_T P_414; /* Expression: wt.ctrl.torq.ini
    * Referenced by: '<S23>/Rate Limiter'
    */
                          

	  
          

          
          
                  
          

                  real_T P_415; /* Expression: 1/wt.gen.N
    * Referenced by: '<S24>/Gear ratio'
    */
                          

	  
          

          
          
                  
          

                  real_T P_416; /* Expression: wt.rotor.damp
    * Referenced by: '<S24>/Main shaft  viscous friction B [Nms//rad]'
    */
                          

	  
          

          
          
                  
          

                  real_T P_417; /* Expression: 1/wt.gen.N
    * Referenced by: '<S24>/Inverse gear ratio'
    */
                          

	  
          

          
          
                  
          

                  real_T P_418; /* Expression: 1/wt.gen.inertia
    * Referenced by: '<S24>/Generator inertia'
    */
                          

	  
          

          
          
                  
          

                  real_T P_419; /* Expression: 1/wt.rotor.inertia
    * Referenced by: '<S24>/Rotor inertia'
    */
                          

	  
          

          
          
                  
          

                  real_T P_420; /* Expression: 0.5
    * Referenced by: '<S11>/Switch2'
    */
                          

	  
          

          
          
                  
          

                  real_T P_421; /* Expression: 1/wt.gen.timeconstant
    * Referenced by: '<S25>/Generator Time constant'
    */
                          

	  
          

          
          
                  
          

                  real_T P_422; /* Expression: wt.pitch.delay
    * Referenced by: '<S34>/Hydraulic delay time'
    */
                          

	  
          

          
          
                  
          

                  real_T P_423; /* Expression: 0
    * Referenced by: '<S34>/Hydraulic delay time'
    */
                          

	  
          

          
          
                  
          

                  real_T P_424; /* Computed Parameter: P_424
    * Referenced by: '<S34>/Hydraulic  time constant'
    */
                          

	  
          

          
          
                  
          

                  real_T P_425; /* Computed Parameter: P_425
    * Referenced by: '<S34>/Hydraulic  time constant'
    */
                          

	  
          

          
          
                  
          

                  real_T P_426; /* Expression: 0.5
    * Referenced by: '<S11>/Switch1'
    */
                          

	  
          

          
          
                  
          

                  real_T P_427; /* Expression: wt.pitch.K
    * Referenced by: '<S35>/e.k'
    */
                          

	  
          

          
          
                  
          

                  real_T P_428; /* Expression: wt.meas.ballufres
    * Referenced by: '<S27>/Balluf resolution'
    */
                          

	  
          

          
          
                  
          

                  real_T P_429; /* Expression: wt.gen.ini
    * Referenced by: '<S27>/gen Integrator'
    */
                          

	  
          

          
          
                  
          

                  real_T P_430; /* Expression: wt.rotor.ini
    * Referenced by: '<S27>/gen Integrator1'
    */
                          

	  
          

          
          
                  
          

                  real_T P_431; /* Expression: wt.meas.aneres
    * Referenced by: '<S27>/anemometer resolution'
    */
                          

	  
          

          
          
                  
          

                  real_T P_432; /* Expression: wt.meas.genres
    * Referenced by: '<S27>/gen resolution'
    */
                          

	  
          

          
          
                  
          

                  real_T P_433; /* Expression: 1/wt.meas.gentau
    * Referenced by: '<S27>/gen sensor time constant'
    */
                          

	  
          

          
          
                  
          

                  real_T P_434; /* Expression: 1/wt.meas.rottau
    * Referenced by: '<S27>/gen sensor time constant1'
    */
                          

	  
          

          
          
                  
          

                  real_T P_435; /* Expression: wt.meas.rotres
    * Referenced by: '<S27>/rot resolution'
    */
                          

	  
          

          
          
                  
          

                  real_T P_436[451]; /* Expression: wt.cp.beta
    * Referenced by: '<S45>/C_P table '
    */
                          

	  
          

          
          
                  
          

                  real_T P_437[250]; /* Expression: wt.cp.tsr
    * Referenced by: '<S45>/C_P table '
    */
                          

	  
          

          
          
                  
          

                  real_T P_438[112750]; /* Expression: wt.cp.table
    * Referenced by: '<S45>/C_P table '
    */
                          

	  
          

          
          
                  
          

                  real_T P_439; /* Expression: env.rho*.5* pi * wt.rotor.radius^2
    * Referenced by: '<S37>/rho//2*A'
    */
                          

	  
          

          
          
                  
          

                  real_T P_440; /* Expression: Px_UseExternalControl
    * Referenced by: '<S12>/Constant2'
    */
                          

	  
          

          
          
                  
          

                  real_T P_441; /* Expression: 1/wt.ctrl.gen.effeciency
    * Referenced by: '<S39>/Generator efficiency  compensation'
    */
                          

	  
          

          
          
                  
          

                  real_T P_442; /* Expression: wt.ctrl.p_rated
    * Referenced by: '<S39>/Limit power  to rated'
    */
                          

	  
          

          
          
                  
          

                  real_T P_443; /* Expression: 0
    * Referenced by: '<S39>/Limit power  to rated'
    */
                          

	  
          

          
          
                  
          

                  real_T P_444; /* Computed Parameter: P_444
    * Referenced by: '<S39>/Measurement filter (low pass)'
    */
                          

	  
          

          
          
                  
          

                  real_T P_445; /* Computed Parameter: P_445
    * Referenced by: '<S39>/Measurement filter (low pass)'
    */
                          

	  
          

          
          
                  
          

                  real_T P_446; /* Computed Parameter: P_446
    * Referenced by: '<S39>/Measurement filter (low pass)'
    */
                          

	  
          

          
          
                  
          

                  real_T P_447; /* Computed Parameter: P_447
    * Referenced by: '<S39>/Measurement filter (low pass)'
    */
                          

	  
          

          
          
                  
          

                  real_T P_448; /* Expression: wt.ctrl.gen.ini
    * Referenced by: '<S39>/Measurement filter (low pass)'
    */
                          

	  
          

          
          
                  
          

                  real_T P_449; /* Expression: wt.ctrl.gen.rated
    * Referenced by: '<S39>/Rated speed'
    */
                          

	  
          

          
          
                  
          

                  real_T P_450[1230]; /* Expression: wt.ctrl.torq.wg
    * Referenced by: '<S39>/Torque - speed lookup table'
    */
                          

	  
          

          
          
                  
          

                  real_T P_451[1230]; /* Expression: wt.ctrl.torq.M
    * Referenced by: '<S39>/Torque - speed lookup table'
    */
                          

	  
          

          
          
                  
          

                  real_T P_452; /* Expression: const
    * Referenced by: '<S49>/Constant'
    */
                          

	  
          

          
          
                  
          

                  real_T P_453; /* Expression: 0.0
    * Referenced by: '<S47>/Integer Delay'
    */
                          

	  
          

          
          
                  
          

                  real_T P_454; /* Expression: const
    * Referenced by: '<S48>/Constant'
    */
                          

	  
          

          
          
                  
          

                  real_T P_455; /* Expression: wt.ctrl.torq.lim
    * Referenced by: '<S39>/Saturation'
    */
                          

	  
          

          
          
                  
          

                  real_T P_456; /* Expression: 0
    * Referenced by: '<S39>/Saturation'
    */
                          

	  
          

          
          
                  
          

                  real_T P_457; /* Computed Parameter: P_457
    * Referenced by: '<S39>/Rate Limiter'
    */
                          

	  
          

          
          
                  
          

                  real_T P_458; /* Computed Parameter: P_458
    * Referenced by: '<S39>/Rate Limiter'
    */
                          

	  
          

          
          
                  
          

                  real_T P_459; /* Expression: wt.ctrl.torq.ini
    * Referenced by: '<S39>/Rate Limiter'
    */
                          

	  
          

          
          
                  
          

                  real_T P_460; /* Expression: 1/wt.gen.N
    * Referenced by: '<S40>/Gear ratio'
    */
                          

	  
          

          
          
                  
          

                  real_T P_461; /* Expression: wt.rotor.damp
    * Referenced by: '<S40>/Main shaft  viscous friction B [Nms//rad]'
    */
                          

	  
          

          
          
                  
          

                  real_T P_462; /* Expression: 1/wt.gen.N
    * Referenced by: '<S40>/Inverse gear ratio'
    */
                          

	  
          

          
          
                  
          

                  real_T P_463; /* Expression: 1/wt.gen.inertia
    * Referenced by: '<S40>/Generator inertia'
    */
                          

	  
          

          
          
                  
          

                  real_T P_464; /* Expression: 1/wt.rotor.inertia
    * Referenced by: '<S40>/Rotor inertia'
    */
                          

	  
          

          
          
                  
          

                  real_T P_465; /* Expression: 0.5
    * Referenced by: '<S12>/Switch2'
    */
                          

	  
          

          
          
                  
          

                  real_T P_466; /* Expression: 1/wt.gen.timeconstant
    * Referenced by: '<S41>/Generator Time constant'
    */
                          

	  
          

          
          
                  
          

                  real_T P_467; /* Expression: wt.pitch.delay
    * Referenced by: '<S50>/Hydraulic delay time'
    */
                          

	  
          

          
          
                  
          

                  real_T P_468; /* Expression: 0
    * Referenced by: '<S50>/Hydraulic delay time'
    */
                          

	  
          

          
          
                  
          

                  real_T P_469; /* Computed Parameter: P_469
    * Referenced by: '<S50>/Hydraulic  time constant'
    */
                          

	  
          

          
          
                  
          

                  real_T P_470; /* Computed Parameter: P_470
    * Referenced by: '<S50>/Hydraulic  time constant'
    */
                          

	  
          

          
          
                  
          

                  real_T P_471; /* Expression: 0.5
    * Referenced by: '<S12>/Switch1'
    */
                          

	  
          

          
          
                  
          

                  real_T P_472; /* Expression: wt.pitch.K
    * Referenced by: '<S51>/e.k'
    */
                          

	  
          

          
          
                  
          

                  real_T P_473; /* Expression: wt.meas.ballufres
    * Referenced by: '<S43>/Balluf resolution'
    */
                          

	  
          

          
          
                  
          

                  real_T P_474; /* Expression: wt.gen.ini
    * Referenced by: '<S43>/gen Integrator'
    */
                          

	  
          

          
          
                  
          

                  real_T P_475; /* Expression: wt.rotor.ini
    * Referenced by: '<S43>/gen Integrator1'
    */
                          

	  
          

          
          
                  
          

                  real_T P_476; /* Expression: wt.meas.aneres
    * Referenced by: '<S43>/anemometer resolution'
    */
                          

	  
          

          
          
                  
          

                  real_T P_477; /* Expression: wt.meas.genres
    * Referenced by: '<S43>/gen resolution'
    */
                          

	  
          

          
          
                  
          

                  real_T P_478; /* Expression: 1/wt.meas.gentau
    * Referenced by: '<S43>/gen sensor time constant'
    */
                          

	  
          

          
          
                  
          

                  real_T P_479; /* Expression: 1/wt.meas.rottau
    * Referenced by: '<S43>/gen sensor time constant1'
    */
                          

	  
          

          
          
                  
          

                  real_T P_480; /* Expression: wt.meas.rotres
    * Referenced by: '<S43>/rot resolution'
    */
                          

	  
          

          
          
                  
          

                  real_T P_481[451]; /* Expression: wt.cp.beta
    * Referenced by: '<S61>/C_P table '
    */
                          

	  
          

          
          
                  
          

                  real_T P_482[250]; /* Expression: wt.cp.tsr
    * Referenced by: '<S61>/C_P table '
    */
                          

	  
          

          
          
                  
          

                  real_T P_483[112750]; /* Expression: wt.cp.table
    * Referenced by: '<S61>/C_P table '
    */
                          

	  
          

          
          
                  
          

                  real_T P_484; /* Expression: env.rho*.5* pi * wt.rotor.radius^2
    * Referenced by: '<S53>/rho//2*A'
    */
                          

	  
          

          
          
                  
          

                  real_T P_485; /* Expression: Px_UseExternalControl
    * Referenced by: '<S13>/Constant2'
    */
                          

	  
          

          
          
                  
          

                  real_T P_486; /* Expression: 1/wt.ctrl.gen.effeciency
    * Referenced by: '<S55>/Generator efficiency  compensation'
    */
                          

	  
          

          
          
                  
          

                  real_T P_487; /* Expression: wt.ctrl.p_rated
    * Referenced by: '<S55>/Limit power  to rated'
    */
                          

	  
          

          
          
                  
          

                  real_T P_488; /* Expression: 0
    * Referenced by: '<S55>/Limit power  to rated'
    */
                          

	  
          

          
          
                  
          

                  real_T P_489; /* Computed Parameter: P_489
    * Referenced by: '<S55>/Measurement filter (low pass)'
    */
                          

	  
          

          
          
                  
          

                  real_T P_490; /* Computed Parameter: P_490
    * Referenced by: '<S55>/Measurement filter (low pass)'
    */
                          

	  
          

          
          
                  
          

                  real_T P_491; /* Computed Parameter: P_491
    * Referenced by: '<S55>/Measurement filter (low pass)'
    */
                          

	  
          

          
          
                  
          

                  real_T P_492; /* Computed Parameter: P_492
    * Referenced by: '<S55>/Measurement filter (low pass)'
    */
                          

	  
          

          
          
                  
          

                  real_T P_493; /* Expression: wt.ctrl.gen.ini
    * Referenced by: '<S55>/Measurement filter (low pass)'
    */
                          

	  
          

          
          
                  
          

                  real_T P_494; /* Expression: wt.ctrl.gen.rated
    * Referenced by: '<S55>/Rated speed'
    */
                          

	  
          

          
          
                  
          

                  real_T P_495[1230]; /* Expression: wt.ctrl.torq.wg
    * Referenced by: '<S55>/Torque - speed lookup table'
    */
                          

	  
          

          
          
                  
          

                  real_T P_496[1230]; /* Expression: wt.ctrl.torq.M
    * Referenced by: '<S55>/Torque - speed lookup table'
    */
                          

	  
          

          
          
                  
          

                  real_T P_497; /* Expression: const
    * Referenced by: '<S65>/Constant'
    */
                          

	  
          

          
          
                  
          

                  real_T P_498; /* Expression: 0.0
    * Referenced by: '<S63>/Integer Delay'
    */
                          

	  
          

          
          
                  
          

                  real_T P_499; /* Expression: const
    * Referenced by: '<S64>/Constant'
    */
                          

	  
          

          
          
                  
          

                  real_T P_500; /* Expression: wt.ctrl.torq.lim
    * Referenced by: '<S55>/Saturation'
    */
                          

	  
          

          
          
                  
          

                  real_T P_501; /* Expression: 0
    * Referenced by: '<S55>/Saturation'
    */
                          

	  
          

          
          
                  
          

                  real_T P_502; /* Computed Parameter: P_502
    * Referenced by: '<S55>/Rate Limiter'
    */
                          

	  
          

          
          
                  
          

                  real_T P_503; /* Computed Parameter: P_503
    * Referenced by: '<S55>/Rate Limiter'
    */
                          

	  
          

          
          
                  
          

                  real_T P_504; /* Expression: wt.ctrl.torq.ini
    * Referenced by: '<S55>/Rate Limiter'
    */
                          

	  
          

          
          
                  
          

                  real_T P_505; /* Expression: 1/wt.gen.N
    * Referenced by: '<S56>/Gear ratio'
    */
                          

	  
          

          
          
                  
          

                  real_T P_506; /* Expression: wt.rotor.damp
    * Referenced by: '<S56>/Main shaft  viscous friction B [Nms//rad]'
    */
                          

	  
          

          
          
                  
          

                  real_T P_507; /* Expression: 1/wt.gen.N
    * Referenced by: '<S56>/Inverse gear ratio'
    */
                          

	  
          

          
          
                  
          

                  real_T P_508; /* Expression: 1/wt.gen.inertia
    * Referenced by: '<S56>/Generator inertia'
    */
                          

	  
          

          
          
                  
          

                  real_T P_509; /* Expression: 1/wt.rotor.inertia
    * Referenced by: '<S56>/Rotor inertia'
    */
                          

	  
          

          
          
                  
          

                  real_T P_510; /* Expression: 0.5
    * Referenced by: '<S13>/Switch2'
    */
                          

	  
          

          
          
                  
          

                  real_T P_511; /* Expression: 1/wt.gen.timeconstant
    * Referenced by: '<S57>/Generator Time constant'
    */
                          

	  
          

          
          
                  
          

                  real_T P_512; /* Expression: wt.pitch.delay
    * Referenced by: '<S66>/Hydraulic delay time'
    */
                          

	  
          

          
          
                  
          

                  real_T P_513; /* Expression: 0
    * Referenced by: '<S66>/Hydraulic delay time'
    */
                          

	  
          

          
          
                  
          

                  real_T P_514; /* Computed Parameter: P_514
    * Referenced by: '<S66>/Hydraulic  time constant'
    */
                          

	  
          

          
          
                  
          

                  real_T P_515; /* Computed Parameter: P_515
    * Referenced by: '<S66>/Hydraulic  time constant'
    */
                          

	  
          

          
          
                  
          

                  real_T P_516; /* Expression: 0.5
    * Referenced by: '<S13>/Switch1'
    */
                          

	  
          

          
          
                  
          

                  real_T P_517; /* Expression: wt.pitch.K
    * Referenced by: '<S67>/e.k'
    */
                          

	  
          

          
          
                  
          

                  real_T P_518; /* Expression: wt.meas.ballufres
    * Referenced by: '<S59>/Balluf resolution'
    */
                          

	  
          

          
          
                  
          

                  real_T P_519; /* Expression: wt.gen.ini
    * Referenced by: '<S59>/gen Integrator'
    */
                          

	  
          

          
          
                  
          

                  real_T P_520; /* Expression: wt.rotor.ini
    * Referenced by: '<S59>/gen Integrator1'
    */
                          

	  
          

          
          
                  
          

                  real_T P_521; /* Expression: wt.meas.aneres
    * Referenced by: '<S59>/anemometer resolution'
    */
                          

	  
          

          
          
                  
          

                  real_T P_522; /* Expression: wt.meas.genres
    * Referenced by: '<S59>/gen resolution'
    */
                          

	  
          

          
          
                  
          

                  real_T P_523; /* Expression: 1/wt.meas.gentau
    * Referenced by: '<S59>/gen sensor time constant'
    */
                          

	  
          

          
          
                  
          

                  real_T P_524; /* Expression: 1/wt.meas.rottau
    * Referenced by: '<S59>/gen sensor time constant1'
    */
                          

	  
          

          
          
                  
          

                  real_T P_525; /* Expression: wt.meas.rotres
    * Referenced by: '<S59>/rot resolution'
    */
                          

	  
          

          
          
                  
          

                  real_T P_526[451]; /* Expression: wt.cp.beta
    * Referenced by: '<S77>/C_P table '
    */
                          

	  
          

          
          
                  
          

                  real_T P_527[250]; /* Expression: wt.cp.tsr
    * Referenced by: '<S77>/C_P table '
    */
                          

	  
          

          
          
                  
          

                  real_T P_528[112750]; /* Expression: wt.cp.table
    * Referenced by: '<S77>/C_P table '
    */
                          

	  
          

          
          
                  
          

                  real_T P_529; /* Expression: env.rho*.5* pi * wt.rotor.radius^2
    * Referenced by: '<S69>/rho//2*A'
    */
                          

	  
          

          
          
                  
          

                  real_T P_530; /* Expression: Px_UseExternalControl
    * Referenced by: '<S14>/Constant2'
    */
                          

	  
          

          
          
                  
          

                  real_T P_531; /* Expression: 1/wt.ctrl.gen.effeciency
    * Referenced by: '<S71>/Generator efficiency  compensation'
    */
                          

	  
          

          
          
                  
          

                  real_T P_532; /* Expression: wt.ctrl.p_rated
    * Referenced by: '<S71>/Limit power  to rated'
    */
                          

	  
          

          
          
                  
          

                  real_T P_533; /* Expression: 0
    * Referenced by: '<S71>/Limit power  to rated'
    */
                          

	  
          

          
          
                  
          

                  real_T P_534; /* Computed Parameter: P_534
    * Referenced by: '<S71>/Measurement filter (low pass)'
    */
                          

	  
          

          
          
                  
          

                  real_T P_535; /* Computed Parameter: P_535
    * Referenced by: '<S71>/Measurement filter (low pass)'
    */
                          

	  
          

          
          
                  
          

                  real_T P_536; /* Computed Parameter: P_536
    * Referenced by: '<S71>/Measurement filter (low pass)'
    */
                          

	  
          

          
          
                  
          

                  real_T P_537; /* Computed Parameter: P_537
    * Referenced by: '<S71>/Measurement filter (low pass)'
    */
                          

	  
          

          
          
                  
          

                  real_T P_538; /* Expression: wt.ctrl.gen.ini
    * Referenced by: '<S71>/Measurement filter (low pass)'
    */
                          

	  
          

          
          
                  
          

                  real_T P_539; /* Expression: wt.ctrl.gen.rated
    * Referenced by: '<S71>/Rated speed'
    */
                          

	  
          

          
          
                  
          

                  real_T P_540[1230]; /* Expression: wt.ctrl.torq.wg
    * Referenced by: '<S71>/Torque - speed lookup table'
    */
                          

	  
          

          
          
                  
          

                  real_T P_541[1230]; /* Expression: wt.ctrl.torq.M
    * Referenced by: '<S71>/Torque - speed lookup table'
    */
                          

	  
          

          
          
                  
          

                  real_T P_542; /* Expression: const
    * Referenced by: '<S81>/Constant'
    */
                          

	  
          

          
          
                  
          

                  real_T P_543; /* Expression: 0.0
    * Referenced by: '<S79>/Integer Delay'
    */
                          

	  
          

          
          
                  
          

                  real_T P_544; /* Expression: const
    * Referenced by: '<S80>/Constant'
    */
                          

	  
          

          
          
                  
          

                  real_T P_545; /* Expression: wt.ctrl.torq.lim
    * Referenced by: '<S71>/Saturation'
    */
                          

	  
          

          
          
                  
          

                  real_T P_546; /* Expression: 0
    * Referenced by: '<S71>/Saturation'
    */
                          

	  
          

          
          
                  
          

                  real_T P_547; /* Computed Parameter: P_547
    * Referenced by: '<S71>/Rate Limiter'
    */
                          

	  
          

          
          
                  
          

                  real_T P_548; /* Computed Parameter: P_548
    * Referenced by: '<S71>/Rate Limiter'
    */
                          

	  
          

          
          
                  
          

                  real_T P_549; /* Expression: wt.ctrl.torq.ini
    * Referenced by: '<S71>/Rate Limiter'
    */
                          

	  
          

          
          
                  
          

                  real_T P_550; /* Expression: 1/wt.gen.N
    * Referenced by: '<S72>/Gear ratio'
    */
                          

	  
          

          
          
                  
          

                  real_T P_551; /* Expression: wt.rotor.damp
    * Referenced by: '<S72>/Main shaft  viscous friction B [Nms//rad]'
    */
                          

	  
          

          
          
                  
          

                  real_T P_552; /* Expression: 1/wt.gen.N
    * Referenced by: '<S72>/Inverse gear ratio'
    */
                          

	  
          

          
          
                  
          

                  real_T P_553; /* Expression: 1/wt.gen.inertia
    * Referenced by: '<S72>/Generator inertia'
    */
                          

	  
          

          
          
                  
          

                  real_T P_554; /* Expression: 1/wt.rotor.inertia
    * Referenced by: '<S72>/Rotor inertia'
    */
                          

	  
          

          
          
                  
          

                  real_T P_555; /* Expression: 0.5
    * Referenced by: '<S14>/Switch2'
    */
                          

	  
          

          
          
                  
          

                  real_T P_556; /* Expression: 1/wt.gen.timeconstant
    * Referenced by: '<S73>/Generator Time constant'
    */
                          

	  
          

          
          
                  
          

                  real_T P_557; /* Expression: wt.pitch.delay
    * Referenced by: '<S82>/Hydraulic delay time'
    */
                          

	  
          

          
          
                  
          

                  real_T P_558; /* Expression: 0
    * Referenced by: '<S82>/Hydraulic delay time'
    */
                          

	  
          

          
          
                  
          

                  real_T P_559; /* Computed Parameter: P_559
    * Referenced by: '<S82>/Hydraulic  time constant'
    */
                          

	  
          

          
          
                  
          

                  real_T P_560; /* Computed Parameter: P_560
    * Referenced by: '<S82>/Hydraulic  time constant'
    */
                          

	  
          

          
          
                  
          

                  real_T P_561; /* Expression: 0.5
    * Referenced by: '<S14>/Switch1'
    */
                          

	  
          

          
          
                  
          

                  real_T P_562; /* Expression: wt.pitch.K
    * Referenced by: '<S83>/e.k'
    */
                          

	  
          

          
          
                  
          

                  real_T P_563; /* Expression: wt.meas.ballufres
    * Referenced by: '<S75>/Balluf resolution'
    */
                          

	  
          

          
          
                  
          

                  real_T P_564; /* Expression: wt.gen.ini
    * Referenced by: '<S75>/gen Integrator'
    */
                          

	  
          

          
          
                  
          

                  real_T P_565; /* Expression: wt.rotor.ini
    * Referenced by: '<S75>/gen Integrator1'
    */
                          

	  
          

          
          
                  
          

                  real_T P_566; /* Expression: wt.meas.aneres
    * Referenced by: '<S75>/anemometer resolution'
    */
                          

	  
          

          
          
                  
          

                  real_T P_567; /* Expression: wt.meas.genres
    * Referenced by: '<S75>/gen resolution'
    */
                          

	  
          

          
          
                  
          

                  real_T P_568; /* Expression: 1/wt.meas.gentau
    * Referenced by: '<S75>/gen sensor time constant'
    */
                          

	  
          

          
          
                  
          

                  real_T P_569; /* Expression: 1/wt.meas.rottau
    * Referenced by: '<S75>/gen sensor time constant1'
    */
                          

	  
          

          
          
                  
          

                  real_T P_570; /* Expression: wt.meas.rotres
    * Referenced by: '<S75>/rot resolution'
    */
                          

	  
          

          
          
                  
          

                  real_T P_571[451]; /* Expression: wt.cp.beta
    * Referenced by: '<S93>/C_P table '
    */
                          

	  
          

          
          
                  
          

                  real_T P_572[250]; /* Expression: wt.cp.tsr
    * Referenced by: '<S93>/C_P table '
    */
                          

	  
          

          
          
                  
          

                  real_T P_573[112750]; /* Expression: wt.cp.table
    * Referenced by: '<S93>/C_P table '
    */
                          

	  
          

          
          
                  
          

                  real_T P_574; /* Expression: env.rho*.5* pi * wt.rotor.radius^2
    * Referenced by: '<S85>/rho//2*A'
    */
                          

	  
          

          
          
                  
          

                  real_T P_575; /* Expression: Px_UseExternalControl
    * Referenced by: '<S15>/Constant2'
    */
                          

	  
          

          
          
                  
          

                  real_T P_576; /* Expression: 1/wt.ctrl.gen.effeciency
    * Referenced by: '<S87>/Generator efficiency  compensation'
    */
                          

	  
          

          
          
                  
          

                  real_T P_577; /* Expression: wt.ctrl.p_rated
    * Referenced by: '<S87>/Limit power  to rated'
    */
                          

	  
          

          
          
                  
          

                  real_T P_578; /* Expression: 0
    * Referenced by: '<S87>/Limit power  to rated'
    */
                          

	  
          

          
          
                  
          

                  real_T P_579; /* Computed Parameter: P_579
    * Referenced by: '<S87>/Measurement filter (low pass)'
    */
                          

	  
          

          
          
                  
          

                  real_T P_580; /* Computed Parameter: P_580
    * Referenced by: '<S87>/Measurement filter (low pass)'
    */
                          

	  
          

          
          
                  
          

                  real_T P_581; /* Computed Parameter: P_581
    * Referenced by: '<S87>/Measurement filter (low pass)'
    */
                          

	  
          

          
          
                  
          

                  real_T P_582; /* Computed Parameter: P_582
    * Referenced by: '<S87>/Measurement filter (low pass)'
    */
                          

	  
          

          
          
                  
          

                  real_T P_583; /* Expression: wt.ctrl.gen.ini
    * Referenced by: '<S87>/Measurement filter (low pass)'
    */
                          

	  
          

          
          
                  
          

                  real_T P_584; /* Expression: wt.ctrl.gen.rated
    * Referenced by: '<S87>/Rated speed'
    */
                          

	  
          

          
          
                  
          

                  real_T P_585[1230]; /* Expression: wt.ctrl.torq.wg
    * Referenced by: '<S87>/Torque - speed lookup table'
    */
                          

	  
          

          
          
                  
          

                  real_T P_586[1230]; /* Expression: wt.ctrl.torq.M
    * Referenced by: '<S87>/Torque - speed lookup table'
    */
                          

	  
          

          
          
                  
          

                  real_T P_587; /* Expression: const
    * Referenced by: '<S97>/Constant'
    */
                          

	  
          

          
          
                  
          

                  real_T P_588; /* Expression: 0.0
    * Referenced by: '<S95>/Integer Delay'
    */
                          

	  
          

          
          
                  
          

                  real_T P_589; /* Expression: const
    * Referenced by: '<S96>/Constant'
    */
                          

	  
          

          
          
                  
          

                  real_T P_590; /* Expression: wt.ctrl.torq.lim
    * Referenced by: '<S87>/Saturation'
    */
                          

	  
          

          
          
                  
          

                  real_T P_591; /* Expression: 0
    * Referenced by: '<S87>/Saturation'
    */
                          

	  
          

          
          
                  
          

                  real_T P_592; /* Computed Parameter: P_592
    * Referenced by: '<S87>/Rate Limiter'
    */
                          

	  
          

          
          
                  
          

                  real_T P_593; /* Computed Parameter: P_593
    * Referenced by: '<S87>/Rate Limiter'
    */
                          

	  
          

          
          
                  
          

                  real_T P_594; /* Expression: wt.ctrl.torq.ini
    * Referenced by: '<S87>/Rate Limiter'
    */
                          

	  
          

          
          
                  
          

                  real_T P_595; /* Expression: 1/wt.gen.N
    * Referenced by: '<S88>/Gear ratio'
    */
                          

	  
          

          
          
                  
          

                  real_T P_596; /* Expression: wt.rotor.damp
    * Referenced by: '<S88>/Main shaft  viscous friction B [Nms//rad]'
    */
                          

	  
          

          
          
                  
          

                  real_T P_597; /* Expression: 1/wt.gen.N
    * Referenced by: '<S88>/Inverse gear ratio'
    */
                          

	  
          

          
          
                  
          

                  real_T P_598; /* Expression: 1/wt.gen.inertia
    * Referenced by: '<S88>/Generator inertia'
    */
                          

	  
          

          
          
                  
          

                  real_T P_599; /* Expression: 1/wt.rotor.inertia
    * Referenced by: '<S88>/Rotor inertia'
    */
                          

	  
          

          
          
                  
          

                  real_T P_600; /* Expression: 0.5
    * Referenced by: '<S15>/Switch2'
    */
                          

	  
          

          
          
                  
          

                  real_T P_601; /* Expression: 1/wt.gen.timeconstant
    * Referenced by: '<S89>/Generator Time constant'
    */
                          

	  
          

          
          
                  
          

                  real_T P_602; /* Expression: wt.pitch.delay
    * Referenced by: '<S98>/Hydraulic delay time'
    */
                          

	  
          

          
          
                  
          

                  real_T P_603; /* Expression: 0
    * Referenced by: '<S98>/Hydraulic delay time'
    */
                          

	  
          

          
          
                  
          

                  real_T P_604; /* Computed Parameter: P_604
    * Referenced by: '<S98>/Hydraulic  time constant'
    */
                          

	  
          

          
          
                  
          

                  real_T P_605; /* Computed Parameter: P_605
    * Referenced by: '<S98>/Hydraulic  time constant'
    */
                          

	  
          

          
          
                  
          

                  real_T P_606; /* Expression: 0.5
    * Referenced by: '<S15>/Switch1'
    */
                          

	  
          

          
          
                  
          

                  real_T P_607; /* Expression: wt.pitch.K
    * Referenced by: '<S99>/e.k'
    */
                          

	  
          

          
          
                  
          

                  real_T P_608; /* Expression: wt.meas.ballufres
    * Referenced by: '<S91>/Balluf resolution'
    */
                          

	  
          

          
          
                  
          

                  real_T P_609; /* Expression: wt.gen.ini
    * Referenced by: '<S91>/gen Integrator'
    */
                          

	  
          

          
          
                  
          

                  real_T P_610; /* Expression: wt.rotor.ini
    * Referenced by: '<S91>/gen Integrator1'
    */
                          

	  
          

          
          
                  
          

                  real_T P_611; /* Expression: wt.meas.aneres
    * Referenced by: '<S91>/anemometer resolution'
    */
                          

	  
          

          
          
                  
          

                  real_T P_612; /* Expression: wt.meas.genres
    * Referenced by: '<S91>/gen resolution'
    */
                          

	  
          

          
          
                  
          

                  real_T P_613; /* Expression: 1/wt.meas.gentau
    * Referenced by: '<S91>/gen sensor time constant'
    */
                          

	  
          

          
          
                  
          

                  real_T P_614; /* Expression: 1/wt.meas.rottau
    * Referenced by: '<S91>/gen sensor time constant1'
    */
                          

	  
          

          
          
                  
          

                  real_T P_615; /* Expression: wt.meas.rotres
    * Referenced by: '<S91>/rot resolution'
    */
                          

	  
          

          
          
                  
          

                  real_T P_616[451]; /* Expression: wt.cp.beta
    * Referenced by: '<S109>/C_P table '
    */
                          

	  
          

          
          
                  
          

                  real_T P_617[250]; /* Expression: wt.cp.tsr
    * Referenced by: '<S109>/C_P table '
    */
                          

	  
          

          
          
                  
          

                  real_T P_618[112750]; /* Expression: wt.cp.table
    * Referenced by: '<S109>/C_P table '
    */
                          

	  
          

          
          
                  
          

                  real_T P_619; /* Expression: env.rho*.5* pi * wt.rotor.radius^2
    * Referenced by: '<S101>/rho//2*A'
    */
                          

	  
          

          
          
                  
          

                  real_T P_620; /* Expression: Px_UseExternalControl
    * Referenced by: '<S16>/Constant2'
    */
                          

	  
          

          
          
                  
          

                  real_T P_621; /* Expression: 1/wt.ctrl.gen.effeciency
    * Referenced by: '<S103>/Generator efficiency  compensation'
    */
                          

	  
          

          
          
                  
          

                  real_T P_622; /* Expression: wt.ctrl.p_rated
    * Referenced by: '<S103>/Limit power  to rated'
    */
                          

	  
          

          
          
                  
          

                  real_T P_623; /* Expression: 0
    * Referenced by: '<S103>/Limit power  to rated'
    */
                          

	  
          

          
          
                  
          

                  real_T P_624; /* Computed Parameter: P_624
    * Referenced by: '<S103>/Measurement filter (low pass)'
    */
                          

	  
          

          
          
                  
          

                  real_T P_625; /* Computed Parameter: P_625
    * Referenced by: '<S103>/Measurement filter (low pass)'
    */
                          

	  
          

          
          
                  
          

                  real_T P_626; /* Computed Parameter: P_626
    * Referenced by: '<S103>/Measurement filter (low pass)'
    */
                          

	  
          

          
          
                  
          

                  real_T P_627; /* Computed Parameter: P_627
    * Referenced by: '<S103>/Measurement filter (low pass)'
    */
                          

	  
          

          
          
                  
          

                  real_T P_628; /* Expression: wt.ctrl.gen.ini
    * Referenced by: '<S103>/Measurement filter (low pass)'
    */
                          

	  
          

          
          
                  
          

                  real_T P_629; /* Expression: wt.ctrl.gen.rated
    * Referenced by: '<S103>/Rated speed'
    */
                          

	  
          

          
          
                  
          

                  real_T P_630[1230]; /* Expression: wt.ctrl.torq.wg
    * Referenced by: '<S103>/Torque - speed lookup table'
    */
                          

	  
          

          
          
                  
          

                  real_T P_631[1230]; /* Expression: wt.ctrl.torq.M
    * Referenced by: '<S103>/Torque - speed lookup table'
    */
                          

	  
          

          
          
                  
          

                  real_T P_632; /* Expression: const
    * Referenced by: '<S113>/Constant'
    */
                          

	  
          

          
          
                  
          

                  real_T P_633; /* Expression: 0.0
    * Referenced by: '<S111>/Integer Delay'
    */
                          

	  
          

          
          
                  
          

                  real_T P_634; /* Expression: const
    * Referenced by: '<S112>/Constant'
    */
                          

	  
          

          
          
                  
          

                  real_T P_635; /* Expression: wt.ctrl.torq.lim
    * Referenced by: '<S103>/Saturation'
    */
                          

	  
          

          
          
                  
          

                  real_T P_636; /* Expression: 0
    * Referenced by: '<S103>/Saturation'
    */
                          

	  
          

          
          
                  
          

                  real_T P_637; /* Computed Parameter: P_637
    * Referenced by: '<S103>/Rate Limiter'
    */
                          

	  
          

          
          
                  
          

                  real_T P_638; /* Computed Parameter: P_638
    * Referenced by: '<S103>/Rate Limiter'
    */
                          

	  
          

          
          
                  
          

                  real_T P_639; /* Expression: wt.ctrl.torq.ini
    * Referenced by: '<S103>/Rate Limiter'
    */
                          

	  
          

          
          
                  
          

                  real_T P_640; /* Expression: 1/wt.gen.N
    * Referenced by: '<S104>/Gear ratio'
    */
                          

	  
          

          
          
                  
          

                  real_T P_641; /* Expression: wt.rotor.damp
    * Referenced by: '<S104>/Main shaft  viscous friction B [Nms//rad]'
    */
                          

	  
          

          
          
                  
          

                  real_T P_642; /* Expression: 1/wt.gen.N
    * Referenced by: '<S104>/Inverse gear ratio'
    */
                          

	  
          

          
          
                  
          

                  real_T P_643; /* Expression: 1/wt.gen.inertia
    * Referenced by: '<S104>/Generator inertia'
    */
                          

	  
          

          
          
                  
          

                  real_T P_644; /* Expression: 1/wt.rotor.inertia
    * Referenced by: '<S104>/Rotor inertia'
    */
                          

	  
          

          
          
                  
          

                  real_T P_645; /* Expression: 0.5
    * Referenced by: '<S16>/Switch2'
    */
                          

	  
          

          
          
                  
          

                  real_T P_646; /* Expression: 1/wt.gen.timeconstant
    * Referenced by: '<S105>/Generator Time constant'
    */
                          

	  
          

          
          
                  
          

                  real_T P_647; /* Expression: wt.pitch.delay
    * Referenced by: '<S114>/Hydraulic delay time'
    */
                          

	  
          

          
          
                  
          

                  real_T P_648; /* Expression: 0
    * Referenced by: '<S114>/Hydraulic delay time'
    */
                          

	  
          

          
          
                  
          

                  real_T P_649; /* Computed Parameter: P_649
    * Referenced by: '<S114>/Hydraulic  time constant'
    */
                          

	  
          

          
          
                  
          

                  real_T P_650; /* Computed Parameter: P_650
    * Referenced by: '<S114>/Hydraulic  time constant'
    */
                          

	  
          

          
          
                  
          

                  real_T P_651; /* Expression: 0.5
    * Referenced by: '<S16>/Switch1'
    */
                          

	  
          

          
          
                  
          

                  real_T P_652; /* Expression: wt.pitch.K
    * Referenced by: '<S115>/e.k'
    */
                          

	  
          

          
          
                  
          

                  real_T P_653; /* Expression: wt.meas.ballufres
    * Referenced by: '<S107>/Balluf resolution'
    */
                          

	  
          

          
          
                  
          

                  real_T P_654; /* Expression: wt.gen.ini
    * Referenced by: '<S107>/gen Integrator'
    */
                          

	  
          

          
          
                  
          

                  real_T P_655; /* Expression: wt.rotor.ini
    * Referenced by: '<S107>/gen Integrator1'
    */
                          

	  
          

          
          
                  
          

                  real_T P_656; /* Expression: wt.meas.aneres
    * Referenced by: '<S107>/anemometer resolution'
    */
                          

	  
          

          
          
                  
          

                  real_T P_657; /* Expression: wt.meas.genres
    * Referenced by: '<S107>/gen resolution'
    */
                          

	  
          

          
          
                  
          

                  real_T P_658; /* Expression: 1/wt.meas.gentau
    * Referenced by: '<S107>/gen sensor time constant'
    */
                          

	  
          

          
          
                  
          

                  real_T P_659; /* Expression: 1/wt.meas.rottau
    * Referenced by: '<S107>/gen sensor time constant1'
    */
                          

	  
          

          
          
                  
          

                  real_T P_660; /* Expression: wt.meas.rotres
    * Referenced by: '<S107>/rot resolution'
    */
                          

	  
          

          
          
                  
          

                  real_T P_661[451]; /* Expression: wt.cp.beta
    * Referenced by: '<S125>/C_P table '
    */
                          

	  
          

          
          
                  
          

                  real_T P_662[250]; /* Expression: wt.cp.tsr
    * Referenced by: '<S125>/C_P table '
    */
                          

	  
          

          
          
                  
          

                  real_T P_663[112750]; /* Expression: wt.cp.table
    * Referenced by: '<S125>/C_P table '
    */
                          

	  
          

          
          
                  
          

                  real_T P_664; /* Expression: env.rho*.5* pi * wt.rotor.radius^2
    * Referenced by: '<S117>/rho//2*A'
    */
                          

	  
          

          
          
                  
          

                  real_T P_665; /* Expression: Px_UseExternalControl
    * Referenced by: '<S17>/Constant2'
    */
                          

	  
          

          
          
                  
          

                  real_T P_666; /* Expression: 1/wt.ctrl.gen.effeciency
    * Referenced by: '<S119>/Generator efficiency  compensation'
    */
                          

	  
          

          
          
                  
          

                  real_T P_667; /* Expression: wt.ctrl.p_rated
    * Referenced by: '<S119>/Limit power  to rated'
    */
                          

	  
          

          
          
                  
          

                  real_T P_668; /* Expression: 0
    * Referenced by: '<S119>/Limit power  to rated'
    */
                          

	  
          

          
          
                  
          

                  real_T P_669; /* Computed Parameter: P_669
    * Referenced by: '<S119>/Measurement filter (low pass)'
    */
                          

	  
          

          
          
                  
          

                  real_T P_670; /* Computed Parameter: P_670
    * Referenced by: '<S119>/Measurement filter (low pass)'
    */
                          

	  
          

          
          
                  
          

                  real_T P_671; /* Computed Parameter: P_671
    * Referenced by: '<S119>/Measurement filter (low pass)'
    */
                          

	  
          

          
          
                  
          

                  real_T P_672; /* Computed Parameter: P_672
    * Referenced by: '<S119>/Measurement filter (low pass)'
    */
                          

	  
          

          
          
                  
          

                  real_T P_673; /* Expression: wt.ctrl.gen.ini
    * Referenced by: '<S119>/Measurement filter (low pass)'
    */
                          

	  
          

          
          
                  
          

                  real_T P_674; /* Expression: wt.ctrl.gen.rated
    * Referenced by: '<S119>/Rated speed'
    */
                          

	  
          

          
          
                  
          

                  real_T P_675[1230]; /* Expression: wt.ctrl.torq.wg
    * Referenced by: '<S119>/Torque - speed lookup table'
    */
                          

	  
          

          
          
                  
          

                  real_T P_676[1230]; /* Expression: wt.ctrl.torq.M
    * Referenced by: '<S119>/Torque - speed lookup table'
    */
                          

	  
          

          
          
                  
          

                  real_T P_677; /* Expression: const
    * Referenced by: '<S129>/Constant'
    */
                          

	  
          

          
          
                  
          

                  real_T P_678; /* Expression: 0.0
    * Referenced by: '<S127>/Integer Delay'
    */
                          

	  
          

          
          
                  
          

                  real_T P_679; /* Expression: const
    * Referenced by: '<S128>/Constant'
    */
                          

	  
          

          
          
                  
          

                  real_T P_680; /* Expression: wt.ctrl.torq.lim
    * Referenced by: '<S119>/Saturation'
    */
                          

	  
          

          
          
                  
          

                  real_T P_681; /* Expression: 0
    * Referenced by: '<S119>/Saturation'
    */
                          

	  
          

          
          
                  
          

                  real_T P_682; /* Computed Parameter: P_682
    * Referenced by: '<S119>/Rate Limiter'
    */
                          

	  
          

          
          
                  
          

                  real_T P_683; /* Computed Parameter: P_683
    * Referenced by: '<S119>/Rate Limiter'
    */
                          

	  
          

          
          
                  
          

                  real_T P_684; /* Expression: wt.ctrl.torq.ini
    * Referenced by: '<S119>/Rate Limiter'
    */
                          

	  
          

          
          
                  
          

                  real_T P_685; /* Expression: 1/wt.gen.N
    * Referenced by: '<S120>/Gear ratio'
    */
                          

	  
          

          
          
                  
          

                  real_T P_686; /* Expression: wt.rotor.damp
    * Referenced by: '<S120>/Main shaft  viscous friction B [Nms//rad]'
    */
                          

	  
          

          
          
                  
          

                  real_T P_687; /* Expression: 1/wt.gen.N
    * Referenced by: '<S120>/Inverse gear ratio'
    */
                          

	  
          

          
          
                  
          

                  real_T P_688; /* Expression: 1/wt.gen.inertia
    * Referenced by: '<S120>/Generator inertia'
    */
                          

	  
          

          
          
                  
          

                  real_T P_689; /* Expression: 1/wt.rotor.inertia
    * Referenced by: '<S120>/Rotor inertia'
    */
                          

	  
          

          
          
                  
          

                  real_T P_690; /* Expression: 0.5
    * Referenced by: '<S17>/Switch2'
    */
                          

	  
          

          
          
                  
          

                  real_T P_691; /* Expression: 1/wt.gen.timeconstant
    * Referenced by: '<S121>/Generator Time constant'
    */
                          

	  
          

          
          
                  
          

                  real_T P_692; /* Expression: wt.pitch.delay
    * Referenced by: '<S130>/Hydraulic delay time'
    */
                          

	  
          

          
          
                  
          

                  real_T P_693; /* Expression: 0
    * Referenced by: '<S130>/Hydraulic delay time'
    */
                          

	  
          

          
          
                  
          

                  real_T P_694; /* Computed Parameter: P_694
    * Referenced by: '<S130>/Hydraulic  time constant'
    */
                          

	  
          

          
          
                  
          

                  real_T P_695; /* Computed Parameter: P_695
    * Referenced by: '<S130>/Hydraulic  time constant'
    */
                          

	  
          

          
          
                  
          

                  real_T P_696; /* Expression: 0.5
    * Referenced by: '<S17>/Switch1'
    */
                          

	  
          

          
          
                  
          

                  real_T P_697; /* Expression: wt.pitch.K
    * Referenced by: '<S131>/e.k'
    */
                          

	  
          

          
          
                  
          

                  real_T P_698; /* Expression: wt.meas.ballufres
    * Referenced by: '<S123>/Balluf resolution'
    */
                          

	  
          

          
          
                  
          

                  real_T P_699; /* Expression: wt.gen.ini
    * Referenced by: '<S123>/gen Integrator'
    */
                          

	  
          

          
          
                  
          

                  real_T P_700; /* Expression: wt.rotor.ini
    * Referenced by: '<S123>/gen Integrator1'
    */
                          

	  
          

          
          
                  
          

                  real_T P_701; /* Expression: wt.meas.aneres
    * Referenced by: '<S123>/anemometer resolution'
    */
                          

	  
          

          
          
                  
          

                  real_T P_702; /* Expression: wt.meas.genres
    * Referenced by: '<S123>/gen resolution'
    */
                          

	  
          

          
          
                  
          

                  real_T P_703; /* Expression: 1/wt.meas.gentau
    * Referenced by: '<S123>/gen sensor time constant'
    */
                          

	  
          

          
          
                  
          

                  real_T P_704; /* Expression: 1/wt.meas.rottau
    * Referenced by: '<S123>/gen sensor time constant1'
    */
                          

	  
          

          
          
                  
          

                  real_T P_705; /* Expression: wt.meas.rotres
    * Referenced by: '<S123>/rot resolution'
    */
                          

	  
          

          
          
                  
          

                  real_T P_706[451]; /* Expression: wt.cp.beta
    * Referenced by: '<S141>/C_P table '
    */
                          

	  
          

          
          
                  
          

                  real_T P_707[250]; /* Expression: wt.cp.tsr
    * Referenced by: '<S141>/C_P table '
    */
                          

	  
          

          
          
                  
          

                  real_T P_708[112750]; /* Expression: wt.cp.table
    * Referenced by: '<S141>/C_P table '
    */
                          

	  
          

          
          
                  
          

                  real_T P_709; /* Expression: env.rho*.5* pi * wt.rotor.radius^2
    * Referenced by: '<S133>/rho//2*A'
    */
                          

	  
          

          
          
                  
          

                  real_T P_710; /* Expression: Px_UseExternalControl
    * Referenced by: '<S18>/Constant2'
    */
                          

	  
          

          
          
                  
          

                  real_T P_711; /* Expression: 1/wt.ctrl.gen.effeciency
    * Referenced by: '<S135>/Generator efficiency  compensation'
    */
                          

	  
          

          
          
                  
          

                  real_T P_712; /* Expression: wt.ctrl.p_rated
    * Referenced by: '<S135>/Limit power  to rated'
    */
                          

	  
          

          
          
                  
          

                  real_T P_713; /* Expression: 0
    * Referenced by: '<S135>/Limit power  to rated'
    */
                          

	  
          

          
          
                  
          

                  real_T P_714; /* Computed Parameter: P_714
    * Referenced by: '<S135>/Measurement filter (low pass)'
    */
                          

	  
          

          
          
                  
          

                  real_T P_715; /* Computed Parameter: P_715
    * Referenced by: '<S135>/Measurement filter (low pass)'
    */
                          

	  
          

          
          
                  
          

                  real_T P_716; /* Computed Parameter: P_716
    * Referenced by: '<S135>/Measurement filter (low pass)'
    */
                          

	  
          

          
          
                  
          

                  real_T P_717; /* Computed Parameter: P_717
    * Referenced by: '<S135>/Measurement filter (low pass)'
    */
                          

	  
          

          
          
                  
          

                  real_T P_718; /* Expression: wt.ctrl.gen.ini
    * Referenced by: '<S135>/Measurement filter (low pass)'
    */
                          

	  
          

          
          
                  
          

                  real_T P_719; /* Expression: wt.ctrl.gen.rated
    * Referenced by: '<S135>/Rated speed'
    */
                          

	  
          

          
          
                  
          

                  real_T P_720[1230]; /* Expression: wt.ctrl.torq.wg
    * Referenced by: '<S135>/Torque - speed lookup table'
    */
                          

	  
          

          
          
                  
          

                  real_T P_721[1230]; /* Expression: wt.ctrl.torq.M
    * Referenced by: '<S135>/Torque - speed lookup table'
    */
                          

	  
          

          
          
                  
          

                  real_T P_722; /* Expression: const
    * Referenced by: '<S145>/Constant'
    */
                          

	  
          

          
          
                  
          

                  real_T P_723; /* Expression: 0.0
    * Referenced by: '<S143>/Integer Delay'
    */
                          

	  
          

          
          
                  
          

                  real_T P_724; /* Expression: const
    * Referenced by: '<S144>/Constant'
    */
                          

	  
          

          
          
                  
          

                  real_T P_725; /* Expression: wt.ctrl.torq.lim
    * Referenced by: '<S135>/Saturation'
    */
                          

	  
          

          
          
                  
          

                  real_T P_726; /* Expression: 0
    * Referenced by: '<S135>/Saturation'
    */
                          

	  
          

          
          
                  
          

                  real_T P_727; /* Computed Parameter: P_727
    * Referenced by: '<S135>/Rate Limiter'
    */
                          

	  
          

          
          
                  
          

                  real_T P_728; /* Computed Parameter: P_728
    * Referenced by: '<S135>/Rate Limiter'
    */
                          

	  
          

          
          
                  
          

                  real_T P_729; /* Expression: wt.ctrl.torq.ini
    * Referenced by: '<S135>/Rate Limiter'
    */
                          

	  
          

          
          
                  
          

                  real_T P_730; /* Expression: 1/wt.gen.N
    * Referenced by: '<S136>/Gear ratio'
    */
                          

	  
          

          
          
                  
          

                  real_T P_731; /* Expression: wt.rotor.damp
    * Referenced by: '<S136>/Main shaft  viscous friction B [Nms//rad]'
    */
                          

	  
          

          
          
                  
          

                  real_T P_732; /* Expression: 1/wt.gen.N
    * Referenced by: '<S136>/Inverse gear ratio'
    */
                          

	  
          

          
          
                  
          

                  real_T P_733; /* Expression: 1/wt.gen.inertia
    * Referenced by: '<S136>/Generator inertia'
    */
                          

	  
          

          
          
                  
          

                  real_T P_734; /* Expression: 1/wt.rotor.inertia
    * Referenced by: '<S136>/Rotor inertia'
    */
                          

	  
          

          
          
                  
          

                  real_T P_735; /* Expression: 0.5
    * Referenced by: '<S18>/Switch2'
    */
                          

	  
          

          
          
                  
          

                  real_T P_736; /* Expression: 1/wt.gen.timeconstant
    * Referenced by: '<S137>/Generator Time constant'
    */
                          

	  
          

          
          
                  
          

                  real_T P_737; /* Expression: wt.pitch.delay
    * Referenced by: '<S146>/Hydraulic delay time'
    */
                          

	  
          

          
          
                  
          

                  real_T P_738; /* Expression: 0
    * Referenced by: '<S146>/Hydraulic delay time'
    */
                          

	  
          

          
          
                  
          

                  real_T P_739; /* Computed Parameter: P_739
    * Referenced by: '<S146>/Hydraulic  time constant'
    */
                          

	  
          

          
          
                  
          

                  real_T P_740; /* Computed Parameter: P_740
    * Referenced by: '<S146>/Hydraulic  time constant'
    */
                          

	  
          

          
          
                  
          

                  real_T P_741; /* Expression: 0.5
    * Referenced by: '<S18>/Switch1'
    */
                          

	  
          

          
          
                  
          

                  real_T P_742; /* Expression: wt.pitch.K
    * Referenced by: '<S147>/e.k'
    */
                          

	  
          

          
          
                  
          

                  real_T P_743; /* Expression: wt.meas.ballufres
    * Referenced by: '<S139>/Balluf resolution'
    */
                          

	  
          

          
          
                  
          

                  real_T P_744; /* Expression: wt.gen.ini
    * Referenced by: '<S139>/gen Integrator'
    */
                          

	  
          

          
          
                  
          

                  real_T P_745; /* Expression: wt.rotor.ini
    * Referenced by: '<S139>/gen Integrator1'
    */
                          

	  
          

          
          
                  
          

                  real_T P_746; /* Expression: wt.meas.aneres
    * Referenced by: '<S139>/anemometer resolution'
    */
                          

	  
          

          
          
                  
          

                  real_T P_747; /* Expression: wt.meas.genres
    * Referenced by: '<S139>/gen resolution'
    */
                          

	  
          

          
          
                  
          

                  real_T P_748; /* Expression: 1/wt.meas.gentau
    * Referenced by: '<S139>/gen sensor time constant'
    */
                          

	  
          

          
          
                  
          

                  real_T P_749; /* Expression: 1/wt.meas.rottau
    * Referenced by: '<S139>/gen sensor time constant1'
    */
                          

	  
          

          
          
                  
          

                  real_T P_750; /* Expression: wt.meas.rotres
    * Referenced by: '<S139>/rot resolution'
    */
                          

	  
          

          
          
                  
          

                  real_T P_751[451]; /* Expression: wt.cp.beta
    * Referenced by: '<S157>/C_P table '
    */
                          

	  
          

          
          
                  
          

                  real_T P_752[250]; /* Expression: wt.cp.tsr
    * Referenced by: '<S157>/C_P table '
    */
                          

	  
          

          
          
                  
          

                  real_T P_753[112750]; /* Expression: wt.cp.table
    * Referenced by: '<S157>/C_P table '
    */
                          

	  
          

          
          
                  
          

                  real_T P_754; /* Expression: env.rho*.5* pi * wt.rotor.radius^2
    * Referenced by: '<S149>/rho//2*A'
    */
                          

	  
          

          
          
                  
          

                  real_T P_755; /* Expression: Px_UseExternalControl
    * Referenced by: '<S19>/Constant2'
    */
                          

	  
          

          
          
                  
          

                  real_T P_756; /* Expression: 1/wt.ctrl.gen.effeciency
    * Referenced by: '<S151>/Generator efficiency  compensation'
    */
                          

	  
          

          
          
                  
          

                  real_T P_757; /* Expression: wt.ctrl.p_rated
    * Referenced by: '<S151>/Limit power  to rated'
    */
                          

	  
          

          
          
                  
          

                  real_T P_758; /* Expression: 0
    * Referenced by: '<S151>/Limit power  to rated'
    */
                          

	  
          

          
          
                  
          

                  real_T P_759; /* Computed Parameter: P_759
    * Referenced by: '<S151>/Measurement filter (low pass)'
    */
                          

	  
          

          
          
                  
          

                  real_T P_760; /* Computed Parameter: P_760
    * Referenced by: '<S151>/Measurement filter (low pass)'
    */
                          

	  
          

          
          
                  
          

                  real_T P_761; /* Computed Parameter: P_761
    * Referenced by: '<S151>/Measurement filter (low pass)'
    */
                          

	  
          

          
          
                  
          

                  real_T P_762; /* Computed Parameter: P_762
    * Referenced by: '<S151>/Measurement filter (low pass)'
    */
                          

	  
          

          
          
                  
          

                  real_T P_763; /* Expression: wt.ctrl.gen.ini
    * Referenced by: '<S151>/Measurement filter (low pass)'
    */
                          

	  
          

          
          
                  
          

                  real_T P_764; /* Expression: wt.ctrl.gen.rated
    * Referenced by: '<S151>/Rated speed'
    */
                          

	  
          

          
          
                  
          

                  real_T P_765[1230]; /* Expression: wt.ctrl.torq.wg
    * Referenced by: '<S151>/Torque - speed lookup table'
    */
                          

	  
          

          
          
                  
          

                  real_T P_766[1230]; /* Expression: wt.ctrl.torq.M
    * Referenced by: '<S151>/Torque - speed lookup table'
    */
                          

	  
          

          
          
                  
          

                  real_T P_767; /* Expression: const
    * Referenced by: '<S161>/Constant'
    */
                          

	  
          

          
          
                  
          

                  real_T P_768; /* Expression: 0.0
    * Referenced by: '<S159>/Integer Delay'
    */
                          

	  
          

          
          
                  
          

                  real_T P_769; /* Expression: const
    * Referenced by: '<S160>/Constant'
    */
                          

	  
          

          
          
                  
          

                  real_T P_770; /* Expression: wt.ctrl.torq.lim
    * Referenced by: '<S151>/Saturation'
    */
                          

	  
          

          
          
                  
          

                  real_T P_771; /* Expression: 0
    * Referenced by: '<S151>/Saturation'
    */
                          

	  
          

          
          
                  
          

                  real_T P_772; /* Computed Parameter: P_772
    * Referenced by: '<S151>/Rate Limiter'
    */
                          

	  
          

          
          
                  
          

                  real_T P_773; /* Computed Parameter: P_773
    * Referenced by: '<S151>/Rate Limiter'
    */
                          

	  
          

          
          
                  
          

                  real_T P_774; /* Expression: wt.ctrl.torq.ini
    * Referenced by: '<S151>/Rate Limiter'
    */
                          

	  
          

          
          
                  
          

                  real_T P_775; /* Expression: 1/wt.gen.N
    * Referenced by: '<S152>/Gear ratio'
    */
                          

	  
          

          
          
                  
          

                  real_T P_776; /* Expression: wt.rotor.damp
    * Referenced by: '<S152>/Main shaft  viscous friction B [Nms//rad]'
    */
                          

	  
          

          
          
                  
          

                  real_T P_777; /* Expression: 1/wt.gen.N
    * Referenced by: '<S152>/Inverse gear ratio'
    */
                          

	  
          

          
          
                  
          

                  real_T P_778; /* Expression: 1/wt.gen.inertia
    * Referenced by: '<S152>/Generator inertia'
    */
                          

	  
          

          
          
                  
          

                  real_T P_779; /* Expression: 1/wt.rotor.inertia
    * Referenced by: '<S152>/Rotor inertia'
    */
                          

	  
          

          
          
                  
          

                  real_T P_780; /* Expression: 0.5
    * Referenced by: '<S19>/Switch2'
    */
                          

	  
          

          
          
                  
          

                  real_T P_781; /* Expression: 1/wt.gen.timeconstant
    * Referenced by: '<S153>/Generator Time constant'
    */
                          

	  
          

          
          
                  
          

                  real_T P_782; /* Expression: wt.pitch.delay
    * Referenced by: '<S162>/Hydraulic delay time'
    */
                          

	  
          

          
          
                  
          

                  real_T P_783; /* Expression: 0
    * Referenced by: '<S162>/Hydraulic delay time'
    */
                          

	  
          

          
          
                  
          

                  real_T P_784; /* Computed Parameter: P_784
    * Referenced by: '<S162>/Hydraulic  time constant'
    */
                          

	  
          

          
          
                  
          

                  real_T P_785; /* Computed Parameter: P_785
    * Referenced by: '<S162>/Hydraulic  time constant'
    */
                          

	  
          

          
          
                  
          

                  real_T P_786; /* Expression: 0.5
    * Referenced by: '<S19>/Switch1'
    */
                          

	  
          

          
          
                  
          

                  real_T P_787; /* Expression: wt.pitch.K
    * Referenced by: '<S163>/e.k'
    */
                          

	  
          

          
          
                  
          

                  real_T P_788; /* Expression: wt.meas.ballufres
    * Referenced by: '<S155>/Balluf resolution'
    */
                          

	  
          

          
          
                  
          

                  real_T P_789; /* Expression: wt.gen.ini
    * Referenced by: '<S155>/gen Integrator'
    */
                          

	  
          

          
          
                  
          

                  real_T P_790; /* Expression: wt.rotor.ini
    * Referenced by: '<S155>/gen Integrator1'
    */
                          

	  
          

          
          
                  
          

                  real_T P_791; /* Expression: wt.meas.aneres
    * Referenced by: '<S155>/anemometer resolution'
    */
                          

	  
          

          
          
                  
          

                  real_T P_792; /* Expression: wt.meas.genres
    * Referenced by: '<S155>/gen resolution'
    */
                          

	  
          

          
          
                  
          

                  real_T P_793; /* Expression: 1/wt.meas.gentau
    * Referenced by: '<S155>/gen sensor time constant'
    */
                          

	  
          

          
          
                  
          

                  real_T P_794; /* Expression: 1/wt.meas.rottau
    * Referenced by: '<S155>/gen sensor time constant1'
    */
                          

	  
          

          
          
                  
          

                  real_T P_795; /* Expression: wt.meas.rotres
    * Referenced by: '<S155>/rot resolution'
    */
                          

	  
          

          
          
                  
          

                  real_T P_796[451]; /* Expression: wt.cp.beta
    * Referenced by: '<S173>/C_P table '
    */
                          

	  
          

          
          
                  
          

                  real_T P_797[250]; /* Expression: wt.cp.tsr
    * Referenced by: '<S173>/C_P table '
    */
                          

	  
          

          
          
                  
          

                  real_T P_798[112750]; /* Expression: wt.cp.table
    * Referenced by: '<S173>/C_P table '
    */
                          

	  
          

          
          
                  
          

                  real_T P_799; /* Expression: env.rho*.5* pi * wt.rotor.radius^2
    * Referenced by: '<S165>/rho//2*A'
    */
                          

	  
          

          
          
                  
          

                  real_T P_800; /* Expression: Px_UseExternalControl
    * Referenced by: '<S20>/Constant2'
    */
                          

	  
          

          
          
                  
          

                  real_T P_801; /* Expression: 1/wt.ctrl.gen.effeciency
    * Referenced by: '<S167>/Generator efficiency  compensation'
    */
                          

	  
          

          
          
                  
          

                  real_T P_802; /* Expression: wt.ctrl.p_rated
    * Referenced by: '<S167>/Limit power  to rated'
    */
                          

	  
          

          
          
                  
          

                  real_T P_803; /* Expression: 0
    * Referenced by: '<S167>/Limit power  to rated'
    */
                          

	  
          

          
          
                  
          

                  real_T P_804; /* Computed Parameter: P_804
    * Referenced by: '<S167>/Measurement filter (low pass)'
    */
                          

	  
          

          
          
                  
          

                  real_T P_805; /* Computed Parameter: P_805
    * Referenced by: '<S167>/Measurement filter (low pass)'
    */
                          

	  
          

          
          
                  
          

                  real_T P_806; /* Computed Parameter: P_806
    * Referenced by: '<S167>/Measurement filter (low pass)'
    */
                          

	  
          

          
          
                  
          

                  real_T P_807; /* Computed Parameter: P_807
    * Referenced by: '<S167>/Measurement filter (low pass)'
    */
                          

	  
          

          
          
                  
          

                  real_T P_808; /* Expression: wt.ctrl.gen.ini
    * Referenced by: '<S167>/Measurement filter (low pass)'
    */
                          

	  
          

          
          
                  
          

                  real_T P_809; /* Expression: wt.ctrl.gen.rated
    * Referenced by: '<S167>/Rated speed'
    */
                          

	  
          

          
          
                  
          

                  real_T P_810[1230]; /* Expression: wt.ctrl.torq.wg
    * Referenced by: '<S167>/Torque - speed lookup table'
    */
                          

	  
          

          
          
                  
          

                  real_T P_811[1230]; /* Expression: wt.ctrl.torq.M
    * Referenced by: '<S167>/Torque - speed lookup table'
    */
                          

	  
          

          
          
                  
          

                  real_T P_812; /* Expression: const
    * Referenced by: '<S177>/Constant'
    */
                          

	  
          

          
          
                  
          

                  real_T P_813; /* Expression: 0.0
    * Referenced by: '<S175>/Integer Delay'
    */
                          

	  
          

          
          
                  
          

                  real_T P_814; /* Expression: const
    * Referenced by: '<S176>/Constant'
    */
                          

	  
          

          
          
                  
          

                  real_T P_815; /* Expression: wt.ctrl.torq.lim
    * Referenced by: '<S167>/Saturation'
    */
                          

	  
          

          
          
                  
          

                  real_T P_816; /* Expression: 0
    * Referenced by: '<S167>/Saturation'
    */
                          

	  
          

          
          
                  
          

                  real_T P_817; /* Computed Parameter: P_817
    * Referenced by: '<S167>/Rate Limiter'
    */
                          

	  
          

          
          
                  
          

                  real_T P_818; /* Computed Parameter: P_818
    * Referenced by: '<S167>/Rate Limiter'
    */
                          

	  
          

          
          
                  
          

                  real_T P_819; /* Expression: wt.ctrl.torq.ini
    * Referenced by: '<S167>/Rate Limiter'
    */
                          

	  
          

          
          
                  
          

                  real_T P_820; /* Expression: 1/wt.gen.N
    * Referenced by: '<S168>/Gear ratio'
    */
                          

	  
          

          
          
                  
          

                  real_T P_821; /* Expression: wt.rotor.damp
    * Referenced by: '<S168>/Main shaft  viscous friction B [Nms//rad]'
    */
                          

	  
          

          
          
                  
          

                  real_T P_822; /* Expression: 1/wt.gen.N
    * Referenced by: '<S168>/Inverse gear ratio'
    */
                          

	  
          

          
          
                  
          

                  real_T P_823; /* Expression: 1/wt.gen.inertia
    * Referenced by: '<S168>/Generator inertia'
    */
                          

	  
          

          
          
                  
          

                  real_T P_824; /* Expression: 1/wt.rotor.inertia
    * Referenced by: '<S168>/Rotor inertia'
    */
                          

	  
          

          
          
                  
          

                  real_T P_825; /* Expression: 0.5
    * Referenced by: '<S20>/Switch2'
    */
                          

	  
          

          
          
                  
          

                  real_T P_826; /* Expression: 1/wt.gen.timeconstant
    * Referenced by: '<S169>/Generator Time constant'
    */
                          

	  
          

          
          
                  
          

                  real_T P_827; /* Expression: wt.pitch.delay
    * Referenced by: '<S178>/Hydraulic delay time'
    */
                          

	  
          

          
          
                  
          

                  real_T P_828; /* Expression: 0
    * Referenced by: '<S178>/Hydraulic delay time'
    */
                          

	  
          

          
          
                  
          

                  real_T P_829; /* Computed Parameter: P_829
    * Referenced by: '<S178>/Hydraulic  time constant'
    */
                          

	  
          

          
          
                  
          

                  real_T P_830; /* Computed Parameter: P_830
    * Referenced by: '<S178>/Hydraulic  time constant'
    */
                          

	  
          

          
          
                  
          

                  real_T P_831; /* Expression: 0.5
    * Referenced by: '<S20>/Switch1'
    */
                          

	  
          

          
          
                  
          

                  real_T P_832; /* Expression: wt.pitch.K
    * Referenced by: '<S179>/e.k'
    */
                          

	  
          

          
          
                  
          

                  real_T P_833; /* Expression: wt.meas.ballufres
    * Referenced by: '<S171>/Balluf resolution'
    */
                          

	  
          

          
          
                  
          

                  real_T P_834; /* Expression: wt.gen.ini
    * Referenced by: '<S171>/gen Integrator'
    */
                          

	  
          

          
          
                  
          

                  real_T P_835; /* Expression: wt.rotor.ini
    * Referenced by: '<S171>/gen Integrator1'
    */
                          

	  
          

          
          
                  
          

                  real_T P_836; /* Expression: wt.meas.aneres
    * Referenced by: '<S171>/anemometer resolution'
    */
                          

	  
          

          
          
                  
          

                  real_T P_837; /* Expression: wt.meas.genres
    * Referenced by: '<S171>/gen resolution'
    */
                          

	  
          

          
          
                  
          

                  real_T P_838; /* Expression: 1/wt.meas.gentau
    * Referenced by: '<S171>/gen sensor time constant'
    */
                          

	  
          

          
          
                  
          

                  real_T P_839; /* Expression: 1/wt.meas.rottau
    * Referenced by: '<S171>/gen sensor time constant1'
    */
                          

	  
          

          
          
                  
          

                  real_T P_840; /* Expression: wt.meas.rotres
    * Referenced by: '<S171>/rot resolution'
    */
                          

	  
          

          
          
                  
          

                  real_T P_841[226800]; /* Expression: wind.Uy
    * Referenced by: '<S181>/Uy_full'
    */
                          

	  
          

          
          
                  
          

                  real_T P_842[10]; /* Expression: ceil(wind.grid.xsize/wind.grid.size)-wind.xgrids
    * Referenced by: '<S181>/Turb x'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_843; /* Computed Parameter: P_843
    * Referenced by: '<S216>/Output'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_844; /* Computed Parameter: P_844
    * Referenced by: '<S183>/wcDelay2'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_845; /* Computed Parameter: P_845
    * Referenced by: '<S183>/wcDelay3'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_846; /* Computed Parameter: P_846
    * Referenced by: '<S183>/wcDelay4'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_847; /* Computed Parameter: P_847
    * Referenced by: '<S183>/wcDelay5'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_848; /* Computed Parameter: P_848
    * Referenced by: '<S183>/wcDelay6'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_849; /* Computed Parameter: P_849
    * Referenced by: '<S183>/wcDelay7'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_850; /* Computed Parameter: P_850
    * Referenced by: '<S183>/wcDelay8'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_851; /* Computed Parameter: P_851
    * Referenced by: '<S183>/wcDelay9'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_852; /* Computed Parameter: P_852
    * Referenced by: '<S183>/wcDelay10'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_853; /* Computed Parameter: P_853
    * Referenced by: '<S185>/wcDelay3'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_854; /* Computed Parameter: P_854
    * Referenced by: '<S185>/wcDelay4'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_855; /* Computed Parameter: P_855
    * Referenced by: '<S185>/wcDelay6'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_856; /* Computed Parameter: P_856
    * Referenced by: '<S185>/wcDelay7'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_857; /* Computed Parameter: P_857
    * Referenced by: '<S185>/wcDelay9'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_858; /* Computed Parameter: P_858
    * Referenced by: '<S185>/wcDelay10'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_859; /* Computed Parameter: P_859
    * Referenced by: '<S186>/wcDelay4'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_860; /* Computed Parameter: P_860
    * Referenced by: '<S186>/wcDelay7'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_861; /* Computed Parameter: P_861
    * Referenced by: '<S186>/wcDelay10'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_862; /* Computed Parameter: P_862
    * Referenced by: '<S188>/wcDelay2'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_863; /* Computed Parameter: P_863
    * Referenced by: '<S188>/wcDelay3'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_864; /* Computed Parameter: P_864
    * Referenced by: '<S188>/wcDelay4'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_865; /* Computed Parameter: P_865
    * Referenced by: '<S188>/wcDelay6'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_866; /* Computed Parameter: P_866
    * Referenced by: '<S188>/wcDelay7'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_867; /* Computed Parameter: P_867
    * Referenced by: '<S188>/wcDelay8'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_868; /* Computed Parameter: P_868
    * Referenced by: '<S188>/wcDelay9'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_869; /* Computed Parameter: P_869
    * Referenced by: '<S188>/wcDelay10'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_870; /* Computed Parameter: P_870
    * Referenced by: '<S189>/wcDelay3'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_871; /* Computed Parameter: P_871
    * Referenced by: '<S189>/wcDelay4'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_872; /* Computed Parameter: P_872
    * Referenced by: '<S189>/wcDelay7'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_873; /* Computed Parameter: P_873
    * Referenced by: '<S189>/wcDelay9'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_874; /* Computed Parameter: P_874
    * Referenced by: '<S189>/wcDelay10'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_875; /* Computed Parameter: P_875
    * Referenced by: '<S190>/wcDelay4'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_876; /* Computed Parameter: P_876
    * Referenced by: '<S190>/wcDelay10'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_877; /* Computed Parameter: P_877
    * Referenced by: '<S191>/wcDelay3'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_878; /* Computed Parameter: P_878
    * Referenced by: '<S191>/wcDelay4'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_879; /* Computed Parameter: P_879
    * Referenced by: '<S191>/wcDelay6'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_880; /* Computed Parameter: P_880
    * Referenced by: '<S191>/wcDelay7'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_881; /* Computed Parameter: P_881
    * Referenced by: '<S191>/wcDelay9'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_882; /* Computed Parameter: P_882
    * Referenced by: '<S191>/wcDelay10'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_883; /* Computed Parameter: P_883
    * Referenced by: '<S192>/wcDelay4'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_884; /* Computed Parameter: P_884
    * Referenced by: '<S192>/wcDelay7'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_885; /* Computed Parameter: P_885
    * Referenced by: '<S192>/wcDelay10'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_886; /* Computed Parameter: P_886
    * Referenced by: '<S183>/wdDelay2'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_887; /* Computed Parameter: P_887
    * Referenced by: '<S183>/wdDelay3'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_888; /* Computed Parameter: P_888
    * Referenced by: '<S183>/wdDelay4'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_889; /* Computed Parameter: P_889
    * Referenced by: '<S183>/wdDelay5'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_890; /* Computed Parameter: P_890
    * Referenced by: '<S183>/wdDelay6'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_891; /* Computed Parameter: P_891
    * Referenced by: '<S183>/wdDelay7'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_892; /* Computed Parameter: P_892
    * Referenced by: '<S183>/wdDelay8'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_893; /* Computed Parameter: P_893
    * Referenced by: '<S183>/wdDelay9'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_894; /* Computed Parameter: P_894
    * Referenced by: '<S183>/wdDelay10'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_895; /* Computed Parameter: P_895
    * Referenced by: '<S185>/wdDelay3'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_896; /* Computed Parameter: P_896
    * Referenced by: '<S185>/wdDelay4'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_897; /* Computed Parameter: P_897
    * Referenced by: '<S185>/wdDelay6'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_898; /* Computed Parameter: P_898
    * Referenced by: '<S185>/wdDelay7'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_899; /* Computed Parameter: P_899
    * Referenced by: '<S185>/wdDelay9'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_900; /* Computed Parameter: P_900
    * Referenced by: '<S185>/wdDelay10'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_901; /* Computed Parameter: P_901
    * Referenced by: '<S186>/wdDelay4'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_902; /* Computed Parameter: P_902
    * Referenced by: '<S186>/wdDelay7'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_903; /* Computed Parameter: P_903
    * Referenced by: '<S186>/wdDelay10'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_904; /* Computed Parameter: P_904
    * Referenced by: '<S188>/wdDelay2'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_905; /* Computed Parameter: P_905
    * Referenced by: '<S188>/wdDelay3'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_906; /* Computed Parameter: P_906
    * Referenced by: '<S188>/wdDelay4'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_907; /* Computed Parameter: P_907
    * Referenced by: '<S188>/wdDelay6'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_908; /* Computed Parameter: P_908
    * Referenced by: '<S188>/wdDelay7'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_909; /* Computed Parameter: P_909
    * Referenced by: '<S188>/wdDelay8'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_910; /* Computed Parameter: P_910
    * Referenced by: '<S188>/wdDelay9'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_911; /* Computed Parameter: P_911
    * Referenced by: '<S188>/wdDelay10'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_912; /* Computed Parameter: P_912
    * Referenced by: '<S189>/wdDelay3'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_913; /* Computed Parameter: P_913
    * Referenced by: '<S189>/wdDelay4'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_914; /* Computed Parameter: P_914
    * Referenced by: '<S189>/wdDelay7'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_915; /* Computed Parameter: P_915
    * Referenced by: '<S189>/wdDelay9'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_916; /* Computed Parameter: P_916
    * Referenced by: '<S189>/wdDelay10'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_917; /* Computed Parameter: P_917
    * Referenced by: '<S190>/wdDelay4'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_918; /* Computed Parameter: P_918
    * Referenced by: '<S190>/wdDelay10'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_919; /* Computed Parameter: P_919
    * Referenced by: '<S191>/wdDelay3'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_920; /* Computed Parameter: P_920
    * Referenced by: '<S191>/wdDelay4'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_921; /* Computed Parameter: P_921
    * Referenced by: '<S191>/wdDelay6'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_922; /* Computed Parameter: P_922
    * Referenced by: '<S191>/wdDelay7'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_923; /* Computed Parameter: P_923
    * Referenced by: '<S191>/wdDelay9'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_924; /* Computed Parameter: P_924
    * Referenced by: '<S191>/wdDelay10'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_925; /* Computed Parameter: P_925
    * Referenced by: '<S192>/wdDelay4'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_926; /* Computed Parameter: P_926
    * Referenced by: '<S192>/wdDelay7'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_927; /* Computed Parameter: P_927
    * Referenced by: '<S192>/wdDelay10'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_928; /* Computed Parameter: P_928
    * Referenced by: '<S183>/ctDelay2'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_929; /* Computed Parameter: P_929
    * Referenced by: '<S183>/ctDelay3'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_930; /* Computed Parameter: P_930
    * Referenced by: '<S183>/ctDelay4'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_931; /* Computed Parameter: P_931
    * Referenced by: '<S183>/ctDelay5'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_932; /* Computed Parameter: P_932
    * Referenced by: '<S183>/ctDelay6'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_933; /* Computed Parameter: P_933
    * Referenced by: '<S183>/ctDelay7'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_934; /* Computed Parameter: P_934
    * Referenced by: '<S183>/ctDelay8'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_935; /* Computed Parameter: P_935
    * Referenced by: '<S183>/ctDelay9'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_936; /* Computed Parameter: P_936
    * Referenced by: '<S183>/ctDelay10'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_937; /* Computed Parameter: P_937
    * Referenced by: '<S185>/ctDelay3'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_938; /* Computed Parameter: P_938
    * Referenced by: '<S185>/ctDelay4'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_939; /* Computed Parameter: P_939
    * Referenced by: '<S185>/ctDelay6'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_940; /* Computed Parameter: P_940
    * Referenced by: '<S185>/ctDelay7'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_941; /* Computed Parameter: P_941
    * Referenced by: '<S185>/ctDelay9'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_942; /* Computed Parameter: P_942
    * Referenced by: '<S185>/ctDelay10'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_943; /* Computed Parameter: P_943
    * Referenced by: '<S186>/ctDelay4'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_944; /* Computed Parameter: P_944
    * Referenced by: '<S186>/ctDelay7'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_945; /* Computed Parameter: P_945
    * Referenced by: '<S186>/ctDelay10'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_946; /* Computed Parameter: P_946
    * Referenced by: '<S188>/ctDelay2'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_947; /* Computed Parameter: P_947
    * Referenced by: '<S188>/ctDelay3'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_948; /* Computed Parameter: P_948
    * Referenced by: '<S188>/ctDelay4'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_949; /* Computed Parameter: P_949
    * Referenced by: '<S188>/ctDelay6'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_950; /* Computed Parameter: P_950
    * Referenced by: '<S188>/ctDelay7'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_951; /* Computed Parameter: P_951
    * Referenced by: '<S188>/ctDelay8'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_952; /* Computed Parameter: P_952
    * Referenced by: '<S188>/ctDelay9'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_953; /* Computed Parameter: P_953
    * Referenced by: '<S188>/ctDelay10'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_954; /* Computed Parameter: P_954
    * Referenced by: '<S189>/ctDelay3'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_955; /* Computed Parameter: P_955
    * Referenced by: '<S189>/ctDelay4'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_956; /* Computed Parameter: P_956
    * Referenced by: '<S189>/ctDelay7'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_957; /* Computed Parameter: P_957
    * Referenced by: '<S189>/ctDelay9'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_958; /* Computed Parameter: P_958
    * Referenced by: '<S189>/ctDelay10'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_959; /* Computed Parameter: P_959
    * Referenced by: '<S190>/ctDelay4'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_960; /* Computed Parameter: P_960
    * Referenced by: '<S190>/ctDelay10'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_961; /* Computed Parameter: P_961
    * Referenced by: '<S191>/ctDelay3'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_962; /* Computed Parameter: P_962
    * Referenced by: '<S191>/ctDelay4'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_963; /* Computed Parameter: P_963
    * Referenced by: '<S191>/ctDelay6'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_964; /* Computed Parameter: P_964
    * Referenced by: '<S191>/ctDelay7'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_965; /* Computed Parameter: P_965
    * Referenced by: '<S191>/ctDelay9'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_966; /* Computed Parameter: P_966
    * Referenced by: '<S191>/ctDelay10'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_967; /* Computed Parameter: P_967
    * Referenced by: '<S192>/ctDelay4'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_968; /* Computed Parameter: P_968
    * Referenced by: '<S192>/ctDelay7'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_969; /* Computed Parameter: P_969
    * Referenced by: '<S192>/ctDelay10'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_970; /* Computed Parameter: P_970
    * Referenced by: '<S224>/Output'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_971; /* Computed Parameter: P_971
    * Referenced by: '<S228>/Output'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_972; /* Computed Parameter: P_972
    * Referenced by: '<S232>/Output'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_973; /* Computed Parameter: P_973
    * Referenced by: '<S236>/Output'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_974; /* Computed Parameter: P_974
    * Referenced by: '<S240>/Output'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_975; /* Computed Parameter: P_975
    * Referenced by: '<S244>/Output'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_976; /* Computed Parameter: P_976
    * Referenced by: '<S248>/Output'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_977; /* Computed Parameter: P_977
    * Referenced by: '<S252>/Output'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_978; /* Computed Parameter: P_978
    * Referenced by: '<S220>/Output'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_979; /* Computed Parameter: P_979
    * Referenced by: '<S31>/Integer Delay'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_980; /* Computed Parameter: P_980
    * Referenced by: '<S47>/Integer Delay'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_981; /* Computed Parameter: P_981
    * Referenced by: '<S63>/Integer Delay'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_982; /* Computed Parameter: P_982
    * Referenced by: '<S79>/Integer Delay'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_983; /* Computed Parameter: P_983
    * Referenced by: '<S95>/Integer Delay'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_984; /* Computed Parameter: P_984
    * Referenced by: '<S111>/Integer Delay'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_985; /* Computed Parameter: P_985
    * Referenced by: '<S127>/Integer Delay'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_986; /* Computed Parameter: P_986
    * Referenced by: '<S143>/Integer Delay'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_987; /* Computed Parameter: P_987
    * Referenced by: '<S159>/Integer Delay'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_988; /* Computed Parameter: P_988
    * Referenced by: '<S175>/Integer Delay'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_989; /* Computed Parameter: P_989
    * Referenced by: '<S204>/FixPt Constant'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_990; /* Computed Parameter: P_990
    * Referenced by: '<S203>/Output'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_991; /* Computed Parameter: P_991
    * Referenced by: '<S205>/Constant'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_992; /* Computed Parameter: P_992
    * Referenced by: '<S205>/FixPt Switch'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_993; /* Computed Parameter: P_993
    * Referenced by: '<S218>/FixPt Constant'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_994; /* Computed Parameter: P_994
    * Referenced by: '<S219>/Constant'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_995; /* Computed Parameter: P_995
    * Referenced by: '<S219>/FixPt Switch'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_996; /* Computed Parameter: P_996
    * Referenced by: '<S222>/FixPt Constant'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_997; /* Computed Parameter: P_997
    * Referenced by: '<S223>/Constant'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_998; /* Computed Parameter: P_998
    * Referenced by: '<S223>/FixPt Switch'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_999; /* Computed Parameter: P_999
    * Referenced by: '<S226>/FixPt Constant'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_1000; /* Computed Parameter: P_1000
    * Referenced by: '<S227>/Constant'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_1001; /* Computed Parameter: P_1001
    * Referenced by: '<S227>/FixPt Switch'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_1002; /* Computed Parameter: P_1002
    * Referenced by: '<S230>/FixPt Constant'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_1003; /* Computed Parameter: P_1003
    * Referenced by: '<S231>/Constant'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_1004; /* Computed Parameter: P_1004
    * Referenced by: '<S231>/FixPt Switch'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_1005; /* Computed Parameter: P_1005
    * Referenced by: '<S234>/FixPt Constant'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_1006; /* Computed Parameter: P_1006
    * Referenced by: '<S235>/Constant'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_1007; /* Computed Parameter: P_1007
    * Referenced by: '<S235>/FixPt Switch'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_1008; /* Computed Parameter: P_1008
    * Referenced by: '<S238>/FixPt Constant'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_1009; /* Computed Parameter: P_1009
    * Referenced by: '<S239>/Constant'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_1010; /* Computed Parameter: P_1010
    * Referenced by: '<S239>/FixPt Switch'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_1011; /* Computed Parameter: P_1011
    * Referenced by: '<S242>/FixPt Constant'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_1012; /* Computed Parameter: P_1012
    * Referenced by: '<S243>/Constant'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_1013; /* Computed Parameter: P_1013
    * Referenced by: '<S243>/FixPt Switch'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_1014; /* Computed Parameter: P_1014
    * Referenced by: '<S246>/FixPt Constant'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_1015; /* Computed Parameter: P_1015
    * Referenced by: '<S247>/Constant'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_1016; /* Computed Parameter: P_1016
    * Referenced by: '<S247>/FixPt Switch'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_1017; /* Computed Parameter: P_1017
    * Referenced by: '<S250>/FixPt Constant'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_1018; /* Computed Parameter: P_1018
    * Referenced by: '<S251>/Constant'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_1019; /* Computed Parameter: P_1019
    * Referenced by: '<S251>/FixPt Switch'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_1020; /* Computed Parameter: P_1020
    * Referenced by: '<S254>/FixPt Constant'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_1021; /* Computed Parameter: P_1021
    * Referenced by: '<S255>/Constant'
    */
                          

	  
          

          
          
                  
          

                  uint32_T P_1022; /* Computed Parameter: P_1022
    * Referenced by: '<S255>/FixPt Switch'
    */
                          

	  
          
          
                  
          

                  P_Pitchcontroller_benchmark_no_taylor_T Pitchcontroller_c; /* '<S167>/B_44_120' */
                          

	  
          
          
                  
          

                  P_Pitchcontroller_benchmark_no_taylor_T Pitchcontroller_a2; /* '<S151>/B_44_113' */
                          

	  
          
          
                  
          

                  P_Pitchcontroller_benchmark_no_taylor_T Pitchcontroller_nb; /* '<S135>/B_44_106' */
                          

	  
          
          
                  
          

                  P_Pitchcontroller_benchmark_no_taylor_T Pitchcontroller_f; /* '<S119>/B_44_99' */
                          

	  
          
          
                  
          

                  P_Pitchcontroller_benchmark_no_taylor_T Pitchcontroller_p; /* '<S103>/B_44_92' */
                          

	  
          
          
                  
          

                  P_Pitchcontroller_benchmark_no_taylor_T Pitchcontroller_e; /* '<S87>/B_44_85' */
                          

	  
          
          
                  
          

                  P_Pitchcontroller_benchmark_no_taylor_T Pitchcontroller_i; /* '<S71>/B_44_78' */
                          

	  
          
          
                  
          

                  P_Pitchcontroller_benchmark_no_taylor_T Pitchcontroller_a; /* '<S55>/B_44_71' */
                          

	  
          
          
                  
          

                  P_Pitchcontroller_benchmark_no_taylor_T Pitchcontroller_n; /* '<S39>/B_44_64' */
                          

	  
          
          
                  
          

                  P_Pitchcontroller_benchmark_no_taylor_T Pitchcontroller; /* '<S23>/B_44_57' */
                          

	  
          




        };
      
      

  
  
  
  
  
                  extern         P_benchmark_no_taylor_T benchmark_no_taylor_rtDefaultP; /* parameters */



      
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  

    #endif /* RTW_HEADER_benchmark_no_taylor_acc_h_ */
