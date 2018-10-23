  
    /*
  * benchmark_no_taylor_acc_private.h
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


  #ifndef RTW_HEADER_benchmark_no_taylor_acc_private_h_
  #define RTW_HEADER_benchmark_no_taylor_acc_private_h_
  
      

      #include "rtwtypes.h"
  #include "multiword_types.h"

  
  
    #include "benchmark_no_taylor_acc.h"

  
  
  
  
  
    
      #if !defined(ss_VALIDATE_MEMORY)
  #define ss_VALIDATE_MEMORY(S, ptr)   if(!(ptr)) {\
  ssSetErrorStatus(S, RT_MEMORY_ALLOCATION_ERROR);\
  }
  #endif
  
  #if !defined(rt_FREE)
  #if !defined(_WIN32)
  #define rt_FREE(ptr)   if((ptr) != (NULL)) {\
  free((ptr));\
  (ptr) = (NULL);\
  }
  #else
  /* Visual and other windows compilers declare free without const */
  #define rt_FREE(ptr)   if((ptr) != (NULL)) {\
  free((void *)(ptr));\
  (ptr) = (NULL);\
  }
  #endif
  #endif
  

  
      
  /* Used by FromWorkspace Block: '<S9>/B_44_15' */
  #ifndef rtInterpolate
  # define rtInterpolate(v1,v2,f1,f2)   (((v1)==(v2))?((double)(v1)):  (((f1)*((double)(v1)))+((f2)*((double)(v2)))))
  #endif
  
  #ifndef rtRound
  # define rtRound(v) ( ((v) >= 0) ?   muDoubleScalarFloor((v) + 0.5) :   muDoubleScalarCeil((v) - 0.5) )
  #endif
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
          #ifndef __RTW_UTFREE__
      extern void * utMalloc(size_t);
      extern void   utFree(void *); 
      #endif
  
  
  
                    void benchmark_no_taylor_acc_BINARYSEARCH_real_T(uint32_T *piLeft, uint32_T *piRght, real_T u, const real_T *pData, uint32_T iHi);

                void benchmark_no_taylor_acc_Look2D_real_T_real_T_real_T(real_T *pY, const real_T *pYData, real_T u0, const real_T *pU0Data, uint32_T iHiU0, real_T u1, const real_T *pU1Data, uint32_T iHiU1);

                boolean_T  benchmark_no_taylor_acc_rt_TDelayUpdateTailOrGrowBuf(
int_T       *bufSzPtr,        /* in/out - circular buffer size                 */
int_T       *tailPtr,         /* in/out - tail of circular buffer              */
int_T       *headPtr,         /* in/out - head of circular buffer              */
int_T       *lastPtr,         /* in/out - same logical 'last' referenced index */
real_T      tMinusDelay,      /* in     - last point we are looking at   */
real_T      **tBufPtr,        /* in/out - larger buffer for time         */
real_T      **uBufPtr,        /* in/out - larger buffer for input        */
real_T      **xBufPtr,        /* in/out - larger buffer for state        */
boolean_T   isfixedbuf,       /* in     - fixed buffer size enable       */
boolean_T istransportdelay,   /* in     - block acts as transport dela y */
int_T     *maxNewBufSzPtr);

                    real_T benchmark_no_taylor_acc_rt_TDelayInterpolate(
      real_T     tMinusDelay,           /* tMinusDelay = currentSimTime - delay */
      real_T     tStart,
      real_T     *tBuf,
      real_T     *uBuf,
      int_T      bufSz,
      int_T      *lastIdx,
      int_T      oldestIdx,
      int_T      newIdx,
      real_T     initOutput,
      boolean_T  discrete,
      boolean_T  minorStepAndTAtLastMajorOutput)
;

                void benchmark_no_taylor_acc_Look2D_real_T_real_T_real_T_SAT(real_T *pY, const real_T *pYData, real_T u0, const real_T *pU0Data, uint32_T iHiU0, real_T u1, const real_T *pU1Data, uint32_T iHiU1);

                void benchmark_no_taylor_acc_LookUp_real_T_real_T(real_T *pY, const real_T *pYData, real_T u, const real_T *pUData, uint32_T iHi);

            
  
    void benchmark_no_taylor_Pitchcontroller_Init(B_Pitchcontroller_benchmark_no_taylor_T *localB, DW_Pitchcontroller_benchmark_no_taylor_T *localDW, P_Pitchcontroller_benchmark_no_taylor_T *localP);
    
  
  
  
    void benchmark_no_taylor_Pitchcontroller_Reset(DW_Pitchcontroller_benchmark_no_taylor_T *localDW, P_Pitchcontroller_benchmark_no_taylor_T *localP);
    
  
  
  
    void benchmark_no_taylor_Pitchcontroller_Disable(B_Pitchcontroller_benchmark_no_taylor_T *localB, DW_Pitchcontroller_benchmark_no_taylor_T *localDW, P_Pitchcontroller_benchmark_no_taylor_T *localP);
    
  
  
  
    void benchmark_no_taylor_Pitchcontroller_Update(B_Pitchcontroller_benchmark_no_taylor_T *localB, DW_Pitchcontroller_benchmark_no_taylor_T *localDW, P_Pitchcontroller_benchmark_no_taylor_T *localP);
    
  
  
  
    void benchmark_no_taylor_Pitchcontroller(SimStruct * const S, boolean_T rtu_Enable, real_T rtu_w_gen_diff, real_T rtu_P_dem, B_Pitchcontroller_benchmark_no_taylor_T *localB, DW_Pitchcontroller_benchmark_no_taylor_T *localDW, P_Pitchcontroller_benchmark_no_taylor_T *localP);
    
  

  
  
  
  
  
  
  
  
  
  
  
  
  
  

    #endif /* RTW_HEADER_benchmark_no_taylor_acc_private_h_ */
