  
    /*
  * rtGetNaN.c
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


      

    /*
  * Abstract:
  *      Function to initialize non-finite, NaN
  */
  #include "rtGetNaN.h"
  

  
  
  
  
  
    #define NumBitsPerChar  8U

  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
    
  /* 
 * Initialize rtNaN needed by the generated code. 
 * NaN is initialized as non-signaling. Assumes IEEE.
 */

    real_T rtGetNaN(void) {
    size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
    real_T nan = 0.0;

    if (bitsPerReal == 32U) {
      nan = rtGetNaNF();
    } else {
      uint16_T one = 1U;

      enum {
          LittleEndian,
          BigEndian
      } machByteOrder = (*((uint8_T *) &one) == 1U) ? LittleEndian : BigEndian;

      switch (machByteOrder) {
        case LittleEndian: {
              union {
    LittleEndianIEEEDouble bitVal;
    real_T fltVal;
  } tmpVal;
  
  tmpVal.bitVal.words.wordH = 0xFFF80000U;
  tmpVal.bitVal.words.wordL = 0x00000000U;
  nan = tmpVal.fltVal;

            break;
        }
        case BigEndian: {
              union {
    BigEndianIEEEDouble bitVal;
    real_T fltVal;
  } tmpVal;
  
  tmpVal.bitVal.words.wordH = 0x7FFFFFFFU;
  tmpVal.bitVal.words.wordL = 0xFFFFFFFFU;
  nan = tmpVal.fltVal;

            break;
        }
      }
    }
    return nan;
  }
    
  
  /* 
 * Initialize rtNaNF needed by the generated code. 
 * NaN is initialized as non-signaling. Assumes IEEE.
 */

    real32_T rtGetNaNF(void) {
    IEEESingle nanF = { {0} };
    uint16_T one = 1U;

    enum {
        LittleEndian,
        BigEndian
    } machByteOrder = (*((uint8_T *) &one) == 1U) ? LittleEndian : BigEndian;

    switch (machByteOrder) {
      case LittleEndian: {
        nanF.wordL.wordLuint = 0xFFC00000U;
        break;
      }
      case BigEndian: {
        nanF.wordL.wordLuint = 0x7FFFFFFFU;
        break;
      }
    }
    return nanF.wordL.wordLreal;
  }
    


  
  
  
  
  
  
  
  
