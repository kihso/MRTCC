  
    
          /*
     * This file is not available for use in any application other than as a
     * MATLAB(R) MEX file for use with the Simulink(R) product.
     */

  
    /*
    * benchmark_no_taylor_acc.c
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


      

        #include <math.h>
      #include "benchmark_no_taylor_acc.h"

        #include "benchmark_no_taylor_acc_private.h"

#include <stdio.h>
#include "slexec_vm_simstruct_bridge.h"
#include "slexec_vm_zc_functions.h"
#include "slexec_vm_lookup_functions.h"
      #include "simstruc.h"
      #include "fixedpoint.h"

  
  
  
  
  
  #define CodeFormat S-Function
#define AccDefine1 Accelerator_S-Function

  
  
  
  
  
  
  
    #include "simtarget/slAccSfcnBridge.h"

  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
    
                    /* Lookup Binary Search Utility benchmark_no_taylor_acc_BINARYSEARCH_real_T */
        void benchmark_no_taylor_acc_BINARYSEARCH_real_T(uint32_T *piLeft, uint32_T *piRght, real_T u, const real_T *pData, uint32_T iHi)
      {
        /* Find the location of current input value in the data table. */
        *piLeft = 0U;
        *piRght = iHi;
        
        if ( u <= pData[0] )
        {
          /* Less than or equal to the smallest point in the table. */
            *piRght = 0U;
        }
        else if ( u >= pData[iHi] )
        {
          /* Greater than or equal to the largest point in the table. */
            *piLeft = iHi;
        }
        else
        {
          uint32_T i;
          
          /* Do a binary search. */
          while ( ( *piRght - *piLeft ) > 1U )
          {
            /* Get the average of the left and right indices using to Floor rounding. */
            i = (*piLeft + *piRght) >> 1;
            
            /* Move either the right index or the left index so that */
              /*  LeftDataPoint <= CurrentValue < RightDataPoint */
              if ( u < pData[i] )
            {
              *piRght = i;
            }
            else
            {
              *piLeft = i;
            }
          }
          
        }
      }
        
            /* Lookup 2D Lookup Utility benchmark_no_taylor_acc_Look2D_real_T_real_T_real_T */
    void benchmark_no_taylor_acc_Look2D_real_T_real_T_real_T(real_T *pY, const real_T *pYData, real_T u0, const real_T *pU0Data, uint32_T iHiU0, real_T u1, const real_T *pU1Data, uint32_T iHiU1)
    {
      uint32_T iLeftU0, iRghtU0, iLeftU1, iRghtU1;
      
              
        benchmark_no_taylor_acc_BINARYSEARCH_real_T( &(iLeftU0), &(iRghtU0), u0, pU0Data, iHiU0);

      
        
        
              
        benchmark_no_taylor_acc_BINARYSEARCH_real_T( &(iLeftU1), &(iRghtU1), u1, pU1Data, iHiU1);

          {
      real_T u0Left = pU0Data[iLeftU0];
      real_T u0Rght = pU0Data[iRghtU0];
      real_T u1Left = pU1Data[iLeftU1];
      real_T u1Rght = pU1Data[iRghtU1];

      real_T yTemp;
      
      real_T yLeftLeft;     
      real_T yLeftRght;     
      real_T yRghtLeft;     
      real_T yRghtRght;     
      
        real_T u1Lambda;
        
        real_T u0Lambda;
        
                if ( u1Rght > u1Left )
    {
      
      real_T num;
      real_T den;
      
      den = u1Rght;
                den -= u1Left;
        num = u1;
                  num -= u1Left;
              u1Lambda = num / den;
     }
    else
    {
      u1Lambda = 0.0;
    }

                if ( u0Rght > u0Left )
    {
      
      real_T num;
      real_T den;
      
      den = u0Rght;
                den -= u0Left;
        num = u0;
                  num -= u0Left;
              u0Lambda = num / den;
     }
    else
    {
      u0Lambda = 0.0;
    }

      iHiU0++;
      iLeftU1 *= iHiU0;
      iRghtU1 *= iHiU0;

        yRghtLeft = pYData[(iRghtU0+iLeftU1)];
        yRghtRght = pYData[(iRghtU0+iRghtU1)];
        yLeftLeft = pYData[(iLeftU0+iLeftU1)];
        yLeftRght = pYData[(iLeftU0+iRghtU1)];

        /* Interpolate along U1 variable
        *    with the u0 variable locked on the left u0
        */
                  {
            real_T yLeftCast;
            real_T yRghtCast;
                        yLeftCast = yLeftLeft;

                        yRghtCast = yLeftRght;

            yLeftCast += u1Lambda * ( yRghtCast - yLeftCast );
                        (*pY) = yLeftCast;

        }

        /* Interpolate along U1 variable
        *    with the u0 variable locked on the right u0
        */                
                  {
            real_T yLeftCast;
            real_T yRghtCast;
                        yLeftCast = yRghtLeft;

                        yRghtCast = yRghtRght;

            yLeftCast += u1Lambda * ( yRghtCast - yLeftCast );
                        yTemp = yLeftCast;

        }

        /*
        * Interpolate along u0 variable
        *    with the u1 variable locked on its interpolated value
        */
                  {
            real_T yLeftCast;
            real_T yRghtCast;
                        yLeftCast = (*pY);

                        yRghtCast = yTemp;

            yLeftCast += u0Lambda * ( yRghtCast - yLeftCast );
                        (*pY) = yLeftCast;

        }

    }
    }
        
              
      #ifndef __RTW_UTFREE__  
      extern void * utMalloc(size_t);
      extern void   utFree(void *); 
      #endif
      
      
  
    /* Buffer management routine for variable delay block */
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
int_T     *maxNewBufSzPtr)
    {
      
      int_T  testIdx;
      int_T  tail  = *tailPtr;
      int_T  bufSz = *bufSzPtr;
      real_T *tBuf = *tBufPtr;
      real_T *xBuf = (NULL); 
      
      int_T    numBuffer = 2;
      if (istransportdelay){
        numBuffer =3 ;
        xBuf= *xBufPtr;
      }
      
      /*    Get testIdx, the index of the second oldest data point and
      *    see if this is older than current sim time minus applied delay,
      *    used to see if we can move tail forward 
      */
      testIdx = (tail < (bufSz - 1)) ? (tail + 1) : 0;
      
      if ( (tMinusDelay <= tBuf[testIdx]) && !isfixedbuf) {
        int_T  j;
        real_T *tempT;
        real_T *tempU;
        real_T *tempX = (NULL);    
        
        real_T *uBuf     = *uBufPtr;
        int_T  newBufSz  = bufSz + 1024;
        
        if (newBufSz > *maxNewBufSzPtr) {
          *maxNewBufSzPtr = newBufSz; /* save for warning*/
        }
        
        tempU = (real_T*)utMalloc(numBuffer*newBufSz*sizeof(real_T));        
        
        if (tempU == (NULL)){
          return (false);
        }     
        tempT = tempU + newBufSz;
        if(istransportdelay) tempX = tempT + newBufSz;
        
        for (j = tail; j < bufSz; j++) {
          tempT[j - tail] = tBuf[j];
          tempU[j - tail] = uBuf[j];
          if (istransportdelay)  
          tempX[j - tail] = xBuf[j];
        }
        for (j = 0; j < tail; j++) {
          tempT[j + bufSz - tail] = tBuf[j];
          tempU[j + bufSz - tail] = uBuf[j];
          if (istransportdelay)  
          tempX[j + bufSz - tail] = xBuf[j];
        }
        
        if (*lastPtr> tail) 
        {
          *lastPtr -= tail;
        } else {
          *lastPtr += (bufSz - tail);
        }
        *tailPtr= 0;
        *headPtr = bufSz;
        
        utFree(uBuf);
        
        *bufSzPtr = newBufSz;
        *tBufPtr  = tempT;
        *uBufPtr  = tempU;
        if (istransportdelay) *xBufPtr  = tempX;
        
      }else {
        *tailPtr = testIdx; /* move tail forward */
      }
      
      return(true);      


    }
        
            /* 
 * Time delay interpolation routine
 * 
 * The linear interpolation is performed using the formula:
 * 
 *          (t2 - tMinusDelay)         (tMinusDelay - t1)
 * u(t)  =  ----------------- * u1  +  ------------------- * u2
 *              (t2 - t1)                  (t2 - t1)
 */

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

    {
      
      int_T i;
      real_T yout, t1, t2, u1, u2;

      /*
      * If there is only one data point in the buffer, this data point must be
      * the t= 0 and tMinusDelay > t0, it ask for something unknown. The best
      * guess if initial output as well
      */
      
      if ( (newIdx == 0) && (oldestIdx ==0 ) && (tMinusDelay > tStart))  return initOutput;
      
      /*
      * If tMinusDelay is less than zero, should output initial value
      */
      
      if(tMinusDelay <= tStart) return initOutput;
      
      /* For fixed buffer extrapolation: 
      * if tMinusDelay is small than the time at oldestIdx, if discrete, output
      * tailptr value,  else use tailptr and tailptr+1 value to extrapolate
      * It is also for fixed buffer. Note: The same condition can happen for transport delay block where 
      * use tStart and and t[tail] other than using t[tail] and t[tail+1]. 
      * See below
      */
      
      if ( (tMinusDelay <= tBuf[oldestIdx] ) ) {
        if (discrete){
          return(uBuf[oldestIdx]);
        }else{
          int_T tempIdx=oldestIdx + 1;
          if(oldestIdx == bufSz-1) tempIdx = 0;
          t1=tBuf[oldestIdx];
          t2=tBuf[tempIdx];
          u1=uBuf[oldestIdx];
          u2=uBuf[tempIdx];
          
          if (t2 == t1) {
            if (tMinusDelay >= t2) {
              yout = u2;
            }else {
              yout = u1;
            }
          }
          else{
            real_T f1 = (t2-tMinusDelay) / (t2-t1);
            real_T f2 = 1.0 - f1;
            
            /*
            * Use Lagrange's interpolation formula.  Exact outputs at t1, t2.
            */
            yout = f1*u1 + f2*u2;
          }
          return yout;
        }
      }
        
      /*
      * When block does not have direct feedthrough, we use the table of
      * values to extrapolate off the end of the table for delays that are less
      * than 0 (less then step size).  This is not completely accurate.  The
      * chain of events is as follows for a given time t.  Major output - look 
      * in table.  Update - add entry to table.  Now, if we call the output at 
      * time t again, there is a new entry in the table. For very small delays,
      * this means that we will have a different answer from the previous call 
      * to the output fcn at the same time t.  The following code prevents this 
      * from happening.
      */
        
      if (minorStepAndTAtLastMajorOutput) {
        /* pretend that the new entry has not been added to table */
        if (newIdx != 0) {
          if (*lastIdx == newIdx) {
            (*lastIdx)--;
          }
          newIdx--;
        } else {
          if (*lastIdx == newIdx) {
            *lastIdx = bufSz-1;
          }
          newIdx = bufSz - 1;
        }
      }
          
      i = *lastIdx;
      if (tBuf[i] < tMinusDelay) {
        /* Look forward starting at last index */
        while (tBuf[i] < tMinusDelay) {
          
          /* May occur if the delay is less than step-size - extrapolate */
          if (i == newIdx) break;
          
          i = ( i < (bufSz-1) ) ? (i+1) : 0; /* move through buffer */
              
        }
      } else {
        /*
        * Look backwards starting at last index which can happen when the
        * delay time increases.
        */
        while (tBuf[i] >= tMinusDelay) {
          
          /*
          * Due to the entry condition at top of function, we
          * should never hit the end.
          */
          
          i = (i > 0) ? i-1 : (bufSz-1); /* move through buffer */
          
        }
        i = ( i < (bufSz-1) ) ? (i+1) : 0;
      }
          
      *lastIdx = i;
      
      if (discrete) {
        /*
        * tempEps = 128 * eps;
        * localEps = max(tempEps, tempEps*fabs(tBuf[i]))/2;
        */
        double tempEps  = (DBL_EPSILON) * 128.0;
        double localEps = tempEps * muDoubleScalarAbs(tBuf[i]);
        if (tempEps > localEps) {
          localEps = tempEps;
        }
        localEps = localEps / 2.0;
        
        if (tMinusDelay >= (tBuf[i] - localEps)) {
          yout = uBuf[i];
        } else {
          if (i == 0) {
            yout = uBuf[bufSz-1];
          } else {
            yout = uBuf[i-1];
          }
        }
      } else {
        if (i == 0) {
          t1 = tBuf[bufSz-1];
          u1 = uBuf[bufSz-1];
        } else {
          t1 = tBuf[i-1];
          u1 = uBuf[i-1];
        }
        
        t2 = tBuf[i];
        u2 = uBuf[i];
        
        if (t2 == t1) {
          if (tMinusDelay >= t2) {
            yout = u2;
          } else {
            yout = u1;
          }
        } else {
          real_T f1 = (t2-tMinusDelay) / (t2-t1);
          real_T f2 = 1.0 - f1;
          
          /*
          * Use Lagrange's interpolation formula.  Exact outputs at t1, t2.
          */
          yout = f1*u1 + f2*u2;
        }
      }
         
      return(yout); 
          
    }
        
            /* Lookup 2D Lookup Utility benchmark_no_taylor_acc_Look2D_real_T_real_T_real_T_SAT */
    void benchmark_no_taylor_acc_Look2D_real_T_real_T_real_T_SAT(real_T *pY, const real_T *pYData, real_T u0, const real_T *pU0Data, uint32_T iHiU0, real_T u1, const real_T *pU1Data, uint32_T iHiU1)
    {
      uint32_T iLeftU0, iRghtU0, iLeftU1, iRghtU1;
      
              
        benchmark_no_taylor_acc_BINARYSEARCH_real_T( &(iLeftU0), &(iRghtU0), u0, pU0Data, iHiU0);

              
        benchmark_no_taylor_acc_BINARYSEARCH_real_T( &(iLeftU1), &(iRghtU1), u1, pU1Data, iHiU1);

          {
      real_T u0Left = pU0Data[iLeftU0];
      real_T u0Rght = pU0Data[iRghtU0];
      real_T u1Left = pU1Data[iLeftU1];
      real_T u1Rght = pU1Data[iRghtU1];

      real_T yTemp;
      
      real_T yLeftLeft;     
      real_T yLeftRght;     
      real_T yRghtLeft;     
      real_T yRghtRght;     
      
        real_T u1Lambda;
        
        real_T u0Lambda;
        
                if ( u1Rght > u1Left )
    {
      
      real_T num;
      real_T den;
      
      den = u1Rght;
                den -= u1Left;
        num = u1;
                  num -= u1Left;
              u1Lambda = num / den;
     }
    else
    {
      u1Lambda = 0.0;
    }

                if ( u0Rght > u0Left )
    {
      
      real_T num;
      real_T den;
      
      den = u0Rght;
                den -= u0Left;
        num = u0;
                  num -= u0Left;
              u0Lambda = num / den;
     }
    else
    {
      u0Lambda = 0.0;
    }

      iHiU0++;
      iLeftU1 *= iHiU0;
      iRghtU1 *= iHiU0;

        yRghtLeft = pYData[(iRghtU0+iLeftU1)];
        yRghtRght = pYData[(iRghtU0+iRghtU1)];
        yLeftLeft = pYData[(iLeftU0+iLeftU1)];
        yLeftRght = pYData[(iLeftU0+iRghtU1)];

        /* Interpolate along U1 variable
        *    with the u0 variable locked on the left u0
        */
                  {
            real_T yLeftCast;
            real_T yRghtCast;
                        yLeftCast = yLeftLeft;

                        yRghtCast = yLeftRght;

            yLeftCast += u1Lambda * ( yRghtCast - yLeftCast );
                        (*pY) = yLeftCast;

        }

        /* Interpolate along U1 variable
        *    with the u0 variable locked on the right u0
        */                
                  {
            real_T yLeftCast;
            real_T yRghtCast;
                        yLeftCast = yRghtLeft;

                        yRghtCast = yRghtRght;

            yLeftCast += u1Lambda * ( yRghtCast - yLeftCast );
                        yTemp = yLeftCast;

        }

        /*
        * Interpolate along u0 variable
        *    with the u1 variable locked on its interpolated value
        */
                  {
            real_T yLeftCast;
            real_T yRghtCast;
                        yLeftCast = (*pY);

                        yRghtCast = yTemp;

            yLeftCast += u0Lambda * ( yRghtCast - yLeftCast );
                        (*pY) = yLeftCast;

        }

    }
    }
        
            /* Lookup Utility benchmark_no_taylor_acc_LookUp_real_T_real_T */
    void benchmark_no_taylor_acc_LookUp_real_T_real_T(real_T *pY, const real_T *pYData, real_T u, const real_T *pUData, uint32_T iHi)
    {
      uint32_T iLeft;
      uint32_T iRght;
              
        benchmark_no_taylor_acc_BINARYSEARCH_real_T( &(iLeft), &(iRght), u, pUData, iHi);
          {
            real_T lambda;
                    if ( pUData[iRght] > pUData[iLeft] )
    {
      
      real_T num;
      real_T den;
      
      den = pUData[iRght];
                den -= pUData[iLeft];
        num = u;
                  num -= pUData[iLeft];
              lambda = num / den;
     }
    else
    {
      lambda = 0.0;
    }
                      {
            real_T yLeftCast;
            real_T yRghtCast;
                        yLeftCast = pYData[iLeft];

                        yRghtCast = pYData[iRght];

            yLeftCast += lambda * ( yRghtCast - yLeftCast );
                        (*pY) = yLeftCast;

        }
          }
    }
        
      

    

  
  
  
                                          
      
	      /* 
 * System initialize for enable system:
 *    '<S23>/Pitch controller'
 *    '<S39>/Pitch controller'
 *    '<S55>/Pitch controller'
 *    '<S71>/Pitch controller'
 *    '<S87>/Pitch controller'
 *    '<S103>/Pitch controller'
 *    '<S119>/Pitch controller'
 *    '<S135>/Pitch controller'
 *    '<S151>/Pitch controller'
 *    '<S167>/Pitch controller'
 */

          
  
        void benchmark_no_taylor_Pitchcontroller_Init(B_Pitchcontroller_benchmark_no_taylor_T *localB, DW_Pitchcontroller_benchmark_no_taylor_T *localDW, P_Pitchcontroller_benchmark_no_taylor_T *localP)
  {
  
        
  
    
  

                
  

                              localDW->DiscreteTimeIntegrator_DSTATE = localP->P_2;
localDW->IntegerDelay_DSTATE = localP->P_5;
localDW->PrevY = localP->P_16;
localB->B_3_10_0 = localP->P_0;




    
  

          }
    
  


	      /* 
 * System reset for enable system:
 *    '<S23>/Pitch controller'
 *    '<S39>/Pitch controller'
 *    '<S55>/Pitch controller'
 *    '<S71>/Pitch controller'
 *    '<S87>/Pitch controller'
 *    '<S103>/Pitch controller'
 *    '<S119>/Pitch controller'
 *    '<S135>/Pitch controller'
 *    '<S151>/Pitch controller'
 *    '<S167>/Pitch controller'
 */

          
  
        void benchmark_no_taylor_Pitchcontroller_Reset(DW_Pitchcontroller_benchmark_no_taylor_T *localDW, P_Pitchcontroller_benchmark_no_taylor_T *localP)
  {
  
        
  
    
  

                
  

                              localDW->DiscreteTimeIntegrator_DSTATE = localP->P_2;
localDW->IntegerDelay_DSTATE = localP->P_5;
localDW->PrevY = localP->P_16;




    
  

          }
    
  


	      /* 
 * Disable for enable system:
 *    '<S23>/Pitch controller'
 *    '<S39>/Pitch controller'
 *    '<S55>/Pitch controller'
 *    '<S71>/Pitch controller'
 *    '<S87>/Pitch controller'
 *    '<S103>/Pitch controller'
 *    '<S119>/Pitch controller'
 *    '<S135>/Pitch controller'
 *    '<S151>/Pitch controller'
 *    '<S167>/Pitch controller'
 */

          
  
        void benchmark_no_taylor_Pitchcontroller_Disable(B_Pitchcontroller_benchmark_no_taylor_T *localB, DW_Pitchcontroller_benchmark_no_taylor_T *localDW, P_Pitchcontroller_benchmark_no_taylor_T *localP)
  {
  
        
  
    
  

                    
  

                              localB->B_3_10_0 = localP->P_0;
localDW->Pitchcontroller_MODE = false;




    
  

          }
    
  


       
    
  

          /* 
 * Outputs for enable system:
 *    '<S23>/Pitch controller'
 *    '<S39>/Pitch controller'
 *    '<S55>/Pitch controller'
 *    '<S71>/Pitch controller'
 *    '<S87>/Pitch controller'
 *    '<S103>/Pitch controller'
 *    '<S119>/Pitch controller'
 *    '<S135>/Pitch controller'
 *    '<S151>/Pitch controller'
 *    '<S167>/Pitch controller'
 */

            
  
        void benchmark_no_taylor_Pitchcontroller(SimStruct * const S, boolean_T rtu_Enable, real_T rtu_w_gen_diff, real_T rtu_P_dem, B_Pitchcontroller_benchmark_no_taylor_T *localB, DW_Pitchcontroller_benchmark_no_taylor_T *localDW, P_Pitchcontroller_benchmark_no_taylor_T *localP)
  {
  
                          /* local block i/o variables */
        	
	
	
              real_T B_3_1_0;


              real_T B_3_2_0;


	
	
	

  
    real_T rateLimiterRate;

    
  

                
  
    
  
    
  

    
                          


if (ssIsMajorTimeStep(S)) {
    if (rtu_Enable) {
        if (!localDW->Pitchcontroller_MODE) {
            if (ssGetTaskTime(S,2) != ssGetTStart(S)) {
                ssSetSolverNeedsReset(S);
            }
  



      benchmark_no_taylor_Pitchcontroller_Reset(localDW, localP);      
            localDW->Pitchcontroller_MODE = true;
        }
    } else {
        if (localDW->Pitchcontroller_MODE) {
            ssSetSolverNeedsReset(S);
  




      benchmark_no_taylor_Pitchcontroller_Disable(localB, localDW, localP);      
        }
    }
}
if (localDW->Pitchcontroller_MODE) {
    B_3_1_0 = localDW->IntegerDelay_DSTATE;
      
/* Lookup2D: '<S30>/Gain correction'
* About '<S30>/Gain correction':
                * Input0  Data Type:  Floating Point real_T
            * Input1  Data Type:  Floating Point real_T
               * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     * Row Data    parameter uses the same data type and scaling as Input0
     * Column Data parameter uses the same data type and scaling as Input1
     * Table Data  parameter uses the same data type and scaling as Output0
 */
                                      
  
  
  benchmark_no_taylor_acc_Look2D_real_T_real_T_real_T( &(B_3_2_0), localP->P_8, rtu_P_dem, localP->P_6, 5U, B_3_1_0, localP->P_7, 450U);
        
    

   
        
    localB->B_3_4_0 = localP->P_9 * rtu_w_gen_diff / B_3_2_0;
    localB->B_3_10_0 = (localP->P_10 * rtu_w_gen_diff / B_3_2_0 + localDW->DiscreteTimeIntegrator_DSTATE) * localP->P_11;
    if (localB->B_3_10_0 > localP->P_12) {
        localB->B_3_10_0 = localP->P_12;
    } else {
        if (localB->B_3_10_0 < localP->P_13) {
            localB->B_3_10_0 = localP->P_13;
        }
    }
    rateLimiterRate = localB->B_3_10_0 - localDW->PrevY;
    if (rateLimiterRate > localP->P_14) {
        localB->B_3_10_0 = localDW->PrevY + localP->P_14;
    } else {
        if (rateLimiterRate < localP->P_15) {
            localB->B_3_10_0 = localDW->PrevY + localP->P_15;
        }
    }
    localDW->PrevY = localB->B_3_10_0;
    if (ssIsMajorTimeStep(S)) {
        srUpdateBC(localDW->Pitchcontroller_SubsysRanBC);
    }
}






    
  

      
  
    
        }
    
  







       
    
  

          /* 
 * Update for enable system:
 *    '<S23>/Pitch controller'
 *    '<S39>/Pitch controller'
 *    '<S55>/Pitch controller'
 *    '<S71>/Pitch controller'
 *    '<S87>/Pitch controller'
 *    '<S103>/Pitch controller'
 *    '<S119>/Pitch controller'
 *    '<S135>/Pitch controller'
 *    '<S151>/Pitch controller'
 *    '<S167>/Pitch controller'
 */

            
  
        void benchmark_no_taylor_Pitchcontroller_Update(B_Pitchcontroller_benchmark_no_taylor_T *localB, DW_Pitchcontroller_benchmark_no_taylor_T *localDW, P_Pitchcontroller_benchmark_no_taylor_T *localP)
  {
  
      
        
      
    
  

            
      
    
  

                              if (localDW->Pitchcontroller_MODE) {
    localDW->DiscreteTimeIntegrator_DSTATE += localP->P_1 * localB->B_3_4_0;
    if (localDW->DiscreteTimeIntegrator_DSTATE >= localP->P_3) {
        localDW->DiscreteTimeIntegrator_DSTATE = localP->P_3;
    } else {
        if (localDW->DiscreteTimeIntegrator_DSTATE <= localP->P_4) {
            localDW->DiscreteTimeIntegrator_DSTATE = localP->P_4;
        }
    }
    localDW->IntegerDelay_DSTATE = localB->B_3_10_0;
}




    
  

      

            }
    
  







            /* 
 * Termination for enable system:
 *    '<S23>/Pitch controller'
 *    '<S39>/Pitch controller'
 *    '<S55>/Pitch controller'
 *    '<S71>/Pitch controller'
 *    '<S87>/Pitch controller'
 *    '<S103>/Pitch controller'
 *    '<S119>/Pitch controller'
 *    '<S135>/Pitch controller'
 *    '<S151>/Pitch controller'
 *    '<S167>/Pitch controller'
 */

          
  
        void benchmark_no_taylor_Pitchcontroller_Term(SimStruct *const S)
  {
  
          
    
    
  

                
  

                  
  

          }
    
  


      
                                                                                                                                                                                                                                                                        
      
       
    
  

          /* Outputs for root system: '<Root>' */
            
  
       static  void mdlOutputs(SimStruct *S, int_T tid)
  {
  
                          /* local block i/o variables */
        	
              real_T B_53_114_0;


              real_T B_53_295_0;


              real_T B_53_297_0;


              real_T B_53_308_0;


              real_T B_53_310_0;


              real_T B_53_321_0;


              real_T B_53_323_0;


              real_T B_53_334_0;


              real_T B_53_336_0;


              real_T B_53_347_0;


              real_T B_53_349_0;


              real_T B_53_360_0;


              real_T B_53_362_0;


              real_T B_53_373_0;


              real_T B_53_375_0;


              real_T B_53_386_0;


              real_T B_53_388_0;


              real_T B_53_399_0;


              real_T B_53_401_0;


              real_T B_53_412_0;


              real_T B_53_464_0;


              real_T B_53_473_0;


              real_T B_53_474_0;


              real_T B_53_476_0;


              real_T B_53_477_0;


              real_T B_53_520_0;


              real_T B_53_529_0;


              real_T B_53_530_0;


              real_T B_53_532_0;


              real_T B_53_533_0;


              real_T B_53_576_0;


              real_T B_53_585_0;


              real_T B_53_586_0;


              real_T B_53_588_0;


              real_T B_53_589_0;


              real_T B_53_632_0;


              real_T B_53_641_0;


              real_T B_53_642_0;


              real_T B_53_644_0;


              real_T B_53_645_0;


              real_T B_53_688_0;


              real_T B_53_697_0;


              real_T B_53_698_0;


              real_T B_53_700_0;


              real_T B_53_701_0;


              real_T B_53_744_0;


              real_T B_53_753_0;


              real_T B_53_754_0;


              real_T B_53_756_0;


              real_T B_53_757_0;


              real_T B_53_800_0;


              real_T B_53_809_0;


              real_T B_53_810_0;


              real_T B_53_812_0;


              real_T B_53_813_0;


              real_T B_53_856_0;


              real_T B_53_865_0;


              real_T B_53_866_0;


              real_T B_53_868_0;


              real_T B_53_869_0;


              real_T B_53_912_0;


              real_T B_53_921_0;


              real_T B_53_922_0;


              real_T B_53_924_0;


              real_T B_53_925_0;


              real_T B_53_968_0;


              real_T B_53_977_0;


              real_T B_53_978_0;


              real_T B_53_980_0;


              real_T B_53_981_0;


	
	
	
	
	

  
    real_T rtb_B_53_33_0;
real_T rtb_B_53_34_0;
real_T rtb_B_53_37_0;
real_T rtb_B_53_38_0;
real_T rtb_B_53_41_0;
real_T rtb_B_53_42_0;
real_T rtb_B_53_45_0;
real_T rtb_B_53_46_0;
real_T rtb_B_53_49_0;
real_T rtb_B_53_50_0;
real_T rtb_B_53_53_0;
real_T rtb_B_53_54_0;
real_T rtb_B_53_58_0;
real_T rtb_B_53_69_0;
real_T rtb_B_53_70_0;
int32_T i;
uint32_T rtb_B_53_116_0;
real_T rtb_B_53_293_0;
real_T rtb_B_53_292_0;
uint32_T rtb_B_53_299_0;
real_T rtb_B_53_306_0;
real_T rtb_B_53_305_0;
uint32_T rtb_B_53_312_0;
real_T rtb_B_53_319_0;
real_T rtb_B_53_318_0;
uint32_T rtb_B_53_325_0;
real_T rtb_B_53_332_0;
real_T rtb_B_53_331_0;
uint32_T rtb_B_53_338_0;
real_T rtb_B_53_345_0;
real_T rtb_B_53_344_0;
uint32_T rtb_B_53_351_0;
real_T rtb_B_53_358_0;
real_T rtb_B_53_357_0;
uint32_T rtb_B_53_364_0;
real_T rtb_B_53_371_0;
real_T rtb_B_53_370_0;
uint32_T rtb_B_53_377_0;
uint32_T rtb_B_53_390_0;
uint32_T rtb_B_53_403_0;
real_T rtb_B_53_410_0;
real_T rtb_B_53_409_0;
real_T rtb_B_53_466_0;
real_T rtb_B_53_488_0;
real_T rtb_B_53_90_0;
real_T rtb_B_53_544_0;
real_T rtb_B_53_99_0;
real_T rtb_B_53_600_0;
real_T rtb_B_53_91_0;
real_T rtb_B_53_656_0;
real_T rtb_B_53_92_0;
real_T rtb_B_53_712_0;
real_T rtb_B_53_93_0;
real_T rtb_B_53_768_0;
real_T rtb_B_53_94_0;
real_T rtb_B_53_824_0;
real_T rtb_B_53_95_0;
real_T rtb_B_53_880_0;
real_T rtb_B_53_96_0;
real_T rtb_B_53_936_0;
real_T rtb_B_53_97_0;
real_T rtb_B_53_992_0;
real_T rtb_B_53_98_0;
real_T rtb_B_53_1_0;
real_T rtb_B_53_3_0;
real_T rtb_B_53_5_0;
real_T rtb_B_53_7_0;
real_T rtb_B_53_9_0;
real_T rtb_B_53_11_0;
real_T rtb_B_53_13_0;
real_T rtb_B_53_15_0;
real_T rtb_B_53_17_0;
int32_T i_0;
real_T B_53_290_0_idx_1;
real_T B_53_303_0_idx_1;
real_T B_53_316_0_idx_1;
real_T B_53_329_0_idx_1;
real_T B_53_342_0_idx_1;
real_T B_53_355_0_idx_1;
real_T B_53_368_0_idx_1;
real_T B_53_381_0_idx_1;
real_T B_53_394_0_idx_1;
real_T B_53_407_0_idx_1;
B_benchmark_no_taylor_T *_rtB;
P_benchmark_no_taylor_T *_rtP;
X_benchmark_no_taylor_T *_rtX;
DW_benchmark_no_taylor_T *_rtDW;

    
  

                
  
    
  
    
  

    
                  
                




























































_rtDW = ((DW_benchmark_no_taylor_T *) ssGetRootDWork(S));
_rtX = ((X_benchmark_no_taylor_T *) ssGetContStates(S));
_rtP = ((P_benchmark_no_taylor_T *) ssGetModelRtp(S));
_rtB = ((B_benchmark_no_taylor_T *) _ssGetModelBlockIO(S));
      
/* TransportDelay: '<S27>/Computation Delay' */
          {

    real_T **uBuffer = (real_T**)&_rtDW->ComputationDelay_PWORK.TUbufferPtrs[0];
    real_T **tBuffer = (real_T**)&_rtDW->ComputationDelay_PWORK.TUbufferPtrs[4];
    real_T simTime   = ssGetT(S);   
    
    
    real_T tMinusDelay ;
    
    
  
    
      
                     


          
        
	
		
	  tMinusDelay = ((_rtP->P_22 > 0.0) ? _rtP->P_22 : 0.0);
	  tMinusDelay = simTime - tMinusDelay;

      
      
        
        _rtB->B_53_0_0[0] = benchmark_no_taylor_acc_rt_TDelayInterpolate(
        tMinusDelay,
        0.0,
        *tBuffer,
        *uBuffer,
        _rtDW->ComputationDelay_IWORK.CircularBufSize[0],
        &_rtDW->ComputationDelay_IWORK.Last[0],
        _rtDW->ComputationDelay_IWORK.Tail[0],
        _rtDW->ComputationDelay_IWORK.Head[0],
        _rtP->P_23[0],
        0,
        (boolean_T) (ssIsMinorTimeStep(S) && (ssGetTimeOfLastOutput(S) == ssGetT(S))));  	    
      
	tBuffer++; uBuffer++;
      
    
      
                     


          
        
	
		
	  tMinusDelay = ((_rtP->P_22 > 0.0) ? _rtP->P_22 : 0.0);
	  tMinusDelay = simTime - tMinusDelay;

      
      
        
        _rtB->B_53_0_0[1] = benchmark_no_taylor_acc_rt_TDelayInterpolate(
        tMinusDelay,
        0.0,
        *tBuffer,
        *uBuffer,
        _rtDW->ComputationDelay_IWORK.CircularBufSize[1],
        &_rtDW->ComputationDelay_IWORK.Last[1],
        _rtDW->ComputationDelay_IWORK.Tail[1],
        _rtDW->ComputationDelay_IWORK.Head[1],
        _rtP->P_23[1],
        0,
        (boolean_T) (ssIsMinorTimeStep(S) && (ssGetTimeOfLastOutput(S) == ssGetT(S))));  	    
      
	tBuffer++; uBuffer++;
      
    
      
                     


          
        
	
		
	  tMinusDelay = ((_rtP->P_22 > 0.0) ? _rtP->P_22 : 0.0);
	  tMinusDelay = simTime - tMinusDelay;

      
      
        
        _rtB->B_53_0_0[2] = benchmark_no_taylor_acc_rt_TDelayInterpolate(
        tMinusDelay,
        0.0,
        *tBuffer,
        *uBuffer,
        _rtDW->ComputationDelay_IWORK.CircularBufSize[2],
        &_rtDW->ComputationDelay_IWORK.Last[2],
        _rtDW->ComputationDelay_IWORK.Tail[2],
        _rtDW->ComputationDelay_IWORK.Head[2],
        _rtP->P_23[2],
        1,
        (boolean_T) (ssIsMinorTimeStep(S) && (ssGetTimeOfLastOutput(S) == ssGetT(S))));  	    
      
	tBuffer++; uBuffer++;
      
    
      
                     


          
        
	
		
	  tMinusDelay = ((_rtP->P_22 > 0.0) ? _rtP->P_22 : 0.0);
	  tMinusDelay = simTime - tMinusDelay;

      
      
        
        _rtB->B_53_0_0[3] = benchmark_no_taylor_acc_rt_TDelayInterpolate(
        tMinusDelay,
        0.0,
        *tBuffer,
        *uBuffer,
        _rtDW->ComputationDelay_IWORK.CircularBufSize[3],
        &_rtDW->ComputationDelay_IWORK.Last[3],
        _rtDW->ComputationDelay_IWORK.Tail[3],
        _rtDW->ComputationDelay_IWORK.Head[3],
        _rtP->P_23[3],
        0,
        (boolean_T) (ssIsMinorTimeStep(S) && (ssGetTimeOfLastOutput(S) == ssGetT(S))));  	    
      
      
  }
   
        
if (ssIsSampleHit(S, 2, 0)) {
    rtb_B_53_1_0 = _rtB->B_53_0_0[2];
}
      
/* TransportDelay: '<S59>/Computation Delay' */
          {

    real_T **uBuffer = (real_T**)&_rtDW->ComputationDelay_PWORK_h.TUbufferPtrs[0];
    real_T **tBuffer = (real_T**)&_rtDW->ComputationDelay_PWORK_h.TUbufferPtrs[4];
    real_T simTime   = ssGetT(S);   
    
    
    real_T tMinusDelay ;
    
    
  
    
      
                     


          
        
	
		
	  tMinusDelay = ((_rtP->P_24 > 0.0) ? _rtP->P_24 : 0.0);
	  tMinusDelay = simTime - tMinusDelay;

      
      
        
        _rtB->B_53_2_0[0] = benchmark_no_taylor_acc_rt_TDelayInterpolate(
        tMinusDelay,
        0.0,
        *tBuffer,
        *uBuffer,
        _rtDW->ComputationDelay_IWORK_k.CircularBufSize[0],
        &_rtDW->ComputationDelay_IWORK_k.Last[0],
        _rtDW->ComputationDelay_IWORK_k.Tail[0],
        _rtDW->ComputationDelay_IWORK_k.Head[0],
        _rtP->P_25[0],
        0,
        (boolean_T) (ssIsMinorTimeStep(S) && (ssGetTimeOfLastOutput(S) == ssGetT(S))));  	    
      
	tBuffer++; uBuffer++;
      
    
      
                     


          
        
	
		
	  tMinusDelay = ((_rtP->P_24 > 0.0) ? _rtP->P_24 : 0.0);
	  tMinusDelay = simTime - tMinusDelay;

      
      
        
        _rtB->B_53_2_0[1] = benchmark_no_taylor_acc_rt_TDelayInterpolate(
        tMinusDelay,
        0.0,
        *tBuffer,
        *uBuffer,
        _rtDW->ComputationDelay_IWORK_k.CircularBufSize[1],
        &_rtDW->ComputationDelay_IWORK_k.Last[1],
        _rtDW->ComputationDelay_IWORK_k.Tail[1],
        _rtDW->ComputationDelay_IWORK_k.Head[1],
        _rtP->P_25[1],
        0,
        (boolean_T) (ssIsMinorTimeStep(S) && (ssGetTimeOfLastOutput(S) == ssGetT(S))));  	    
      
	tBuffer++; uBuffer++;
      
    
      
                     


          
        
	
		
	  tMinusDelay = ((_rtP->P_24 > 0.0) ? _rtP->P_24 : 0.0);
	  tMinusDelay = simTime - tMinusDelay;

      
      
        
        _rtB->B_53_2_0[2] = benchmark_no_taylor_acc_rt_TDelayInterpolate(
        tMinusDelay,
        0.0,
        *tBuffer,
        *uBuffer,
        _rtDW->ComputationDelay_IWORK_k.CircularBufSize[2],
        &_rtDW->ComputationDelay_IWORK_k.Last[2],
        _rtDW->ComputationDelay_IWORK_k.Tail[2],
        _rtDW->ComputationDelay_IWORK_k.Head[2],
        _rtP->P_25[2],
        1,
        (boolean_T) (ssIsMinorTimeStep(S) && (ssGetTimeOfLastOutput(S) == ssGetT(S))));  	    
      
	tBuffer++; uBuffer++;
      
    
      
                     


          
        
	
		
	  tMinusDelay = ((_rtP->P_24 > 0.0) ? _rtP->P_24 : 0.0);
	  tMinusDelay = simTime - tMinusDelay;

      
      
        
        _rtB->B_53_2_0[3] = benchmark_no_taylor_acc_rt_TDelayInterpolate(
        tMinusDelay,
        0.0,
        *tBuffer,
        *uBuffer,
        _rtDW->ComputationDelay_IWORK_k.CircularBufSize[3],
        &_rtDW->ComputationDelay_IWORK_k.Last[3],
        _rtDW->ComputationDelay_IWORK_k.Tail[3],
        _rtDW->ComputationDelay_IWORK_k.Head[3],
        _rtP->P_25[3],
        0,
        (boolean_T) (ssIsMinorTimeStep(S) && (ssGetTimeOfLastOutput(S) == ssGetT(S))));  	    
      
      
  }
   
        
if (ssIsSampleHit(S, 2, 0)) {
    rtb_B_53_3_0 = _rtB->B_53_2_0[2];
}
      
/* TransportDelay: '<S75>/Computation Delay' */
          {

    real_T **uBuffer = (real_T**)&_rtDW->ComputationDelay_PWORK_a.TUbufferPtrs[0];
    real_T **tBuffer = (real_T**)&_rtDW->ComputationDelay_PWORK_a.TUbufferPtrs[4];
    real_T simTime   = ssGetT(S);   
    
    
    real_T tMinusDelay ;
    
    
  
    
      
                     


          
        
	
		
	  tMinusDelay = ((_rtP->P_26 > 0.0) ? _rtP->P_26 : 0.0);
	  tMinusDelay = simTime - tMinusDelay;

      
      
        
        _rtB->B_53_4_0[0] = benchmark_no_taylor_acc_rt_TDelayInterpolate(
        tMinusDelay,
        0.0,
        *tBuffer,
        *uBuffer,
        _rtDW->ComputationDelay_IWORK_b.CircularBufSize[0],
        &_rtDW->ComputationDelay_IWORK_b.Last[0],
        _rtDW->ComputationDelay_IWORK_b.Tail[0],
        _rtDW->ComputationDelay_IWORK_b.Head[0],
        _rtP->P_27[0],
        0,
        (boolean_T) (ssIsMinorTimeStep(S) && (ssGetTimeOfLastOutput(S) == ssGetT(S))));  	    
      
	tBuffer++; uBuffer++;
      
    
      
                     


          
        
	
		
	  tMinusDelay = ((_rtP->P_26 > 0.0) ? _rtP->P_26 : 0.0);
	  tMinusDelay = simTime - tMinusDelay;

      
      
        
        _rtB->B_53_4_0[1] = benchmark_no_taylor_acc_rt_TDelayInterpolate(
        tMinusDelay,
        0.0,
        *tBuffer,
        *uBuffer,
        _rtDW->ComputationDelay_IWORK_b.CircularBufSize[1],
        &_rtDW->ComputationDelay_IWORK_b.Last[1],
        _rtDW->ComputationDelay_IWORK_b.Tail[1],
        _rtDW->ComputationDelay_IWORK_b.Head[1],
        _rtP->P_27[1],
        0,
        (boolean_T) (ssIsMinorTimeStep(S) && (ssGetTimeOfLastOutput(S) == ssGetT(S))));  	    
      
	tBuffer++; uBuffer++;
      
    
      
                     


          
        
	
		
	  tMinusDelay = ((_rtP->P_26 > 0.0) ? _rtP->P_26 : 0.0);
	  tMinusDelay = simTime - tMinusDelay;

      
      
        
        _rtB->B_53_4_0[2] = benchmark_no_taylor_acc_rt_TDelayInterpolate(
        tMinusDelay,
        0.0,
        *tBuffer,
        *uBuffer,
        _rtDW->ComputationDelay_IWORK_b.CircularBufSize[2],
        &_rtDW->ComputationDelay_IWORK_b.Last[2],
        _rtDW->ComputationDelay_IWORK_b.Tail[2],
        _rtDW->ComputationDelay_IWORK_b.Head[2],
        _rtP->P_27[2],
        1,
        (boolean_T) (ssIsMinorTimeStep(S) && (ssGetTimeOfLastOutput(S) == ssGetT(S))));  	    
      
	tBuffer++; uBuffer++;
      
    
      
                     


          
        
	
		
	  tMinusDelay = ((_rtP->P_26 > 0.0) ? _rtP->P_26 : 0.0);
	  tMinusDelay = simTime - tMinusDelay;

      
      
        
        _rtB->B_53_4_0[3] = benchmark_no_taylor_acc_rt_TDelayInterpolate(
        tMinusDelay,
        0.0,
        *tBuffer,
        *uBuffer,
        _rtDW->ComputationDelay_IWORK_b.CircularBufSize[3],
        &_rtDW->ComputationDelay_IWORK_b.Last[3],
        _rtDW->ComputationDelay_IWORK_b.Tail[3],
        _rtDW->ComputationDelay_IWORK_b.Head[3],
        _rtP->P_27[3],
        0,
        (boolean_T) (ssIsMinorTimeStep(S) && (ssGetTimeOfLastOutput(S) == ssGetT(S))));  	    
      
      
  }
   
        
if (ssIsSampleHit(S, 2, 0)) {
    rtb_B_53_5_0 = _rtB->B_53_4_0[2];
}
      
/* TransportDelay: '<S91>/Computation Delay' */
          {

    real_T **uBuffer = (real_T**)&_rtDW->ComputationDelay_PWORK_g.TUbufferPtrs[0];
    real_T **tBuffer = (real_T**)&_rtDW->ComputationDelay_PWORK_g.TUbufferPtrs[4];
    real_T simTime   = ssGetT(S);   
    
    
    real_T tMinusDelay ;
    
    
  
    
      
                     


          
        
	
		
	  tMinusDelay = ((_rtP->P_28 > 0.0) ? _rtP->P_28 : 0.0);
	  tMinusDelay = simTime - tMinusDelay;

      
      
        
        _rtB->B_53_6_0[0] = benchmark_no_taylor_acc_rt_TDelayInterpolate(
        tMinusDelay,
        0.0,
        *tBuffer,
        *uBuffer,
        _rtDW->ComputationDelay_IWORK_e.CircularBufSize[0],
        &_rtDW->ComputationDelay_IWORK_e.Last[0],
        _rtDW->ComputationDelay_IWORK_e.Tail[0],
        _rtDW->ComputationDelay_IWORK_e.Head[0],
        _rtP->P_29[0],
        0,
        (boolean_T) (ssIsMinorTimeStep(S) && (ssGetTimeOfLastOutput(S) == ssGetT(S))));  	    
      
	tBuffer++; uBuffer++;
      
    
      
                     


          
        
	
		
	  tMinusDelay = ((_rtP->P_28 > 0.0) ? _rtP->P_28 : 0.0);
	  tMinusDelay = simTime - tMinusDelay;

      
      
        
        _rtB->B_53_6_0[1] = benchmark_no_taylor_acc_rt_TDelayInterpolate(
        tMinusDelay,
        0.0,
        *tBuffer,
        *uBuffer,
        _rtDW->ComputationDelay_IWORK_e.CircularBufSize[1],
        &_rtDW->ComputationDelay_IWORK_e.Last[1],
        _rtDW->ComputationDelay_IWORK_e.Tail[1],
        _rtDW->ComputationDelay_IWORK_e.Head[1],
        _rtP->P_29[1],
        0,
        (boolean_T) (ssIsMinorTimeStep(S) && (ssGetTimeOfLastOutput(S) == ssGetT(S))));  	    
      
	tBuffer++; uBuffer++;
      
    
      
                     


          
        
	
		
	  tMinusDelay = ((_rtP->P_28 > 0.0) ? _rtP->P_28 : 0.0);
	  tMinusDelay = simTime - tMinusDelay;

      
      
        
        _rtB->B_53_6_0[2] = benchmark_no_taylor_acc_rt_TDelayInterpolate(
        tMinusDelay,
        0.0,
        *tBuffer,
        *uBuffer,
        _rtDW->ComputationDelay_IWORK_e.CircularBufSize[2],
        &_rtDW->ComputationDelay_IWORK_e.Last[2],
        _rtDW->ComputationDelay_IWORK_e.Tail[2],
        _rtDW->ComputationDelay_IWORK_e.Head[2],
        _rtP->P_29[2],
        1,
        (boolean_T) (ssIsMinorTimeStep(S) && (ssGetTimeOfLastOutput(S) == ssGetT(S))));  	    
      
	tBuffer++; uBuffer++;
      
    
      
                     


          
        
	
		
	  tMinusDelay = ((_rtP->P_28 > 0.0) ? _rtP->P_28 : 0.0);
	  tMinusDelay = simTime - tMinusDelay;

      
      
        
        _rtB->B_53_6_0[3] = benchmark_no_taylor_acc_rt_TDelayInterpolate(
        tMinusDelay,
        0.0,
        *tBuffer,
        *uBuffer,
        _rtDW->ComputationDelay_IWORK_e.CircularBufSize[3],
        &_rtDW->ComputationDelay_IWORK_e.Last[3],
        _rtDW->ComputationDelay_IWORK_e.Tail[3],
        _rtDW->ComputationDelay_IWORK_e.Head[3],
        _rtP->P_29[3],
        0,
        (boolean_T) (ssIsMinorTimeStep(S) && (ssGetTimeOfLastOutput(S) == ssGetT(S))));  	    
      
      
  }
   
        
if (ssIsSampleHit(S, 2, 0)) {
    rtb_B_53_7_0 = _rtB->B_53_6_0[2];
}
      
/* TransportDelay: '<S107>/Computation Delay' */
          {

    real_T **uBuffer = (real_T**)&_rtDW->ComputationDelay_PWORK_j.TUbufferPtrs[0];
    real_T **tBuffer = (real_T**)&_rtDW->ComputationDelay_PWORK_j.TUbufferPtrs[4];
    real_T simTime   = ssGetT(S);   
    
    
    real_T tMinusDelay ;
    
    
  
    
      
                     


          
        
	
		
	  tMinusDelay = ((_rtP->P_30 > 0.0) ? _rtP->P_30 : 0.0);
	  tMinusDelay = simTime - tMinusDelay;

      
      
        
        _rtB->B_53_8_0[0] = benchmark_no_taylor_acc_rt_TDelayInterpolate(
        tMinusDelay,
        0.0,
        *tBuffer,
        *uBuffer,
        _rtDW->ComputationDelay_IWORK_h.CircularBufSize[0],
        &_rtDW->ComputationDelay_IWORK_h.Last[0],
        _rtDW->ComputationDelay_IWORK_h.Tail[0],
        _rtDW->ComputationDelay_IWORK_h.Head[0],
        _rtP->P_31[0],
        0,
        (boolean_T) (ssIsMinorTimeStep(S) && (ssGetTimeOfLastOutput(S) == ssGetT(S))));  	    
      
	tBuffer++; uBuffer++;
      
    
      
                     


          
        
	
		
	  tMinusDelay = ((_rtP->P_30 > 0.0) ? _rtP->P_30 : 0.0);
	  tMinusDelay = simTime - tMinusDelay;

      
      
        
        _rtB->B_53_8_0[1] = benchmark_no_taylor_acc_rt_TDelayInterpolate(
        tMinusDelay,
        0.0,
        *tBuffer,
        *uBuffer,
        _rtDW->ComputationDelay_IWORK_h.CircularBufSize[1],
        &_rtDW->ComputationDelay_IWORK_h.Last[1],
        _rtDW->ComputationDelay_IWORK_h.Tail[1],
        _rtDW->ComputationDelay_IWORK_h.Head[1],
        _rtP->P_31[1],
        0,
        (boolean_T) (ssIsMinorTimeStep(S) && (ssGetTimeOfLastOutput(S) == ssGetT(S))));  	    
      
	tBuffer++; uBuffer++;
      
    
      
                     


          
        
	
		
	  tMinusDelay = ((_rtP->P_30 > 0.0) ? _rtP->P_30 : 0.0);
	  tMinusDelay = simTime - tMinusDelay;

      
      
        
        _rtB->B_53_8_0[2] = benchmark_no_taylor_acc_rt_TDelayInterpolate(
        tMinusDelay,
        0.0,
        *tBuffer,
        *uBuffer,
        _rtDW->ComputationDelay_IWORK_h.CircularBufSize[2],
        &_rtDW->ComputationDelay_IWORK_h.Last[2],
        _rtDW->ComputationDelay_IWORK_h.Tail[2],
        _rtDW->ComputationDelay_IWORK_h.Head[2],
        _rtP->P_31[2],
        1,
        (boolean_T) (ssIsMinorTimeStep(S) && (ssGetTimeOfLastOutput(S) == ssGetT(S))));  	    
      
	tBuffer++; uBuffer++;
      
    
      
                     


          
        
	
		
	  tMinusDelay = ((_rtP->P_30 > 0.0) ? _rtP->P_30 : 0.0);
	  tMinusDelay = simTime - tMinusDelay;

      
      
        
        _rtB->B_53_8_0[3] = benchmark_no_taylor_acc_rt_TDelayInterpolate(
        tMinusDelay,
        0.0,
        *tBuffer,
        *uBuffer,
        _rtDW->ComputationDelay_IWORK_h.CircularBufSize[3],
        &_rtDW->ComputationDelay_IWORK_h.Last[3],
        _rtDW->ComputationDelay_IWORK_h.Tail[3],
        _rtDW->ComputationDelay_IWORK_h.Head[3],
        _rtP->P_31[3],
        0,
        (boolean_T) (ssIsMinorTimeStep(S) && (ssGetTimeOfLastOutput(S) == ssGetT(S))));  	    
      
      
  }
   
        
if (ssIsSampleHit(S, 2, 0)) {
    rtb_B_53_9_0 = _rtB->B_53_8_0[2];
}
      
/* TransportDelay: '<S123>/Computation Delay' */
          {

    real_T **uBuffer = (real_T**)&_rtDW->ComputationDelay_PWORK_d.TUbufferPtrs[0];
    real_T **tBuffer = (real_T**)&_rtDW->ComputationDelay_PWORK_d.TUbufferPtrs[4];
    real_T simTime   = ssGetT(S);   
    
    
    real_T tMinusDelay ;
    
    
  
    
      
                     


          
        
	
		
	  tMinusDelay = ((_rtP->P_32 > 0.0) ? _rtP->P_32 : 0.0);
	  tMinusDelay = simTime - tMinusDelay;

      
      
        
        _rtB->B_53_10_0[0] = benchmark_no_taylor_acc_rt_TDelayInterpolate(
        tMinusDelay,
        0.0,
        *tBuffer,
        *uBuffer,
        _rtDW->ComputationDelay_IWORK_d.CircularBufSize[0],
        &_rtDW->ComputationDelay_IWORK_d.Last[0],
        _rtDW->ComputationDelay_IWORK_d.Tail[0],
        _rtDW->ComputationDelay_IWORK_d.Head[0],
        _rtP->P_33[0],
        0,
        (boolean_T) (ssIsMinorTimeStep(S) && (ssGetTimeOfLastOutput(S) == ssGetT(S))));  	    
      
	tBuffer++; uBuffer++;
      
    
      
                     


          
        
	
		
	  tMinusDelay = ((_rtP->P_32 > 0.0) ? _rtP->P_32 : 0.0);
	  tMinusDelay = simTime - tMinusDelay;

      
      
        
        _rtB->B_53_10_0[1] = benchmark_no_taylor_acc_rt_TDelayInterpolate(
        tMinusDelay,
        0.0,
        *tBuffer,
        *uBuffer,
        _rtDW->ComputationDelay_IWORK_d.CircularBufSize[1],
        &_rtDW->ComputationDelay_IWORK_d.Last[1],
        _rtDW->ComputationDelay_IWORK_d.Tail[1],
        _rtDW->ComputationDelay_IWORK_d.Head[1],
        _rtP->P_33[1],
        0,
        (boolean_T) (ssIsMinorTimeStep(S) && (ssGetTimeOfLastOutput(S) == ssGetT(S))));  	    
      
	tBuffer++; uBuffer++;
      
    
      
                     


          
        
	
		
	  tMinusDelay = ((_rtP->P_32 > 0.0) ? _rtP->P_32 : 0.0);
	  tMinusDelay = simTime - tMinusDelay;

      
      
        
        _rtB->B_53_10_0[2] = benchmark_no_taylor_acc_rt_TDelayInterpolate(
        tMinusDelay,
        0.0,
        *tBuffer,
        *uBuffer,
        _rtDW->ComputationDelay_IWORK_d.CircularBufSize[2],
        &_rtDW->ComputationDelay_IWORK_d.Last[2],
        _rtDW->ComputationDelay_IWORK_d.Tail[2],
        _rtDW->ComputationDelay_IWORK_d.Head[2],
        _rtP->P_33[2],
        1,
        (boolean_T) (ssIsMinorTimeStep(S) && (ssGetTimeOfLastOutput(S) == ssGetT(S))));  	    
      
	tBuffer++; uBuffer++;
      
    
      
                     


          
        
	
		
	  tMinusDelay = ((_rtP->P_32 > 0.0) ? _rtP->P_32 : 0.0);
	  tMinusDelay = simTime - tMinusDelay;

      
      
        
        _rtB->B_53_10_0[3] = benchmark_no_taylor_acc_rt_TDelayInterpolate(
        tMinusDelay,
        0.0,
        *tBuffer,
        *uBuffer,
        _rtDW->ComputationDelay_IWORK_d.CircularBufSize[3],
        &_rtDW->ComputationDelay_IWORK_d.Last[3],
        _rtDW->ComputationDelay_IWORK_d.Tail[3],
        _rtDW->ComputationDelay_IWORK_d.Head[3],
        _rtP->P_33[3],
        0,
        (boolean_T) (ssIsMinorTimeStep(S) && (ssGetTimeOfLastOutput(S) == ssGetT(S))));  	    
      
      
  }
   
        
if (ssIsSampleHit(S, 2, 0)) {
    rtb_B_53_11_0 = _rtB->B_53_10_0[2];
}
      
/* TransportDelay: '<S139>/Computation Delay' */
          {

    real_T **uBuffer = (real_T**)&_rtDW->ComputationDelay_PWORK_o.TUbufferPtrs[0];
    real_T **tBuffer = (real_T**)&_rtDW->ComputationDelay_PWORK_o.TUbufferPtrs[4];
    real_T simTime   = ssGetT(S);   
    
    
    real_T tMinusDelay ;
    
    
  
    
      
                     


          
        
	
		
	  tMinusDelay = ((_rtP->P_34 > 0.0) ? _rtP->P_34 : 0.0);
	  tMinusDelay = simTime - tMinusDelay;

      
      
        
        _rtB->B_53_12_0[0] = benchmark_no_taylor_acc_rt_TDelayInterpolate(
        tMinusDelay,
        0.0,
        *tBuffer,
        *uBuffer,
        _rtDW->ComputationDelay_IWORK_i.CircularBufSize[0],
        &_rtDW->ComputationDelay_IWORK_i.Last[0],
        _rtDW->ComputationDelay_IWORK_i.Tail[0],
        _rtDW->ComputationDelay_IWORK_i.Head[0],
        _rtP->P_35[0],
        0,
        (boolean_T) (ssIsMinorTimeStep(S) && (ssGetTimeOfLastOutput(S) == ssGetT(S))));  	    
      
	tBuffer++; uBuffer++;
      
    
      
                     


          
        
	
		
	  tMinusDelay = ((_rtP->P_34 > 0.0) ? _rtP->P_34 : 0.0);
	  tMinusDelay = simTime - tMinusDelay;

      
      
        
        _rtB->B_53_12_0[1] = benchmark_no_taylor_acc_rt_TDelayInterpolate(
        tMinusDelay,
        0.0,
        *tBuffer,
        *uBuffer,
        _rtDW->ComputationDelay_IWORK_i.CircularBufSize[1],
        &_rtDW->ComputationDelay_IWORK_i.Last[1],
        _rtDW->ComputationDelay_IWORK_i.Tail[1],
        _rtDW->ComputationDelay_IWORK_i.Head[1],
        _rtP->P_35[1],
        0,
        (boolean_T) (ssIsMinorTimeStep(S) && (ssGetTimeOfLastOutput(S) == ssGetT(S))));  	    
      
	tBuffer++; uBuffer++;
      
    
      
                     


          
        
	
		
	  tMinusDelay = ((_rtP->P_34 > 0.0) ? _rtP->P_34 : 0.0);
	  tMinusDelay = simTime - tMinusDelay;

      
      
        
        _rtB->B_53_12_0[2] = benchmark_no_taylor_acc_rt_TDelayInterpolate(
        tMinusDelay,
        0.0,
        *tBuffer,
        *uBuffer,
        _rtDW->ComputationDelay_IWORK_i.CircularBufSize[2],
        &_rtDW->ComputationDelay_IWORK_i.Last[2],
        _rtDW->ComputationDelay_IWORK_i.Tail[2],
        _rtDW->ComputationDelay_IWORK_i.Head[2],
        _rtP->P_35[2],
        1,
        (boolean_T) (ssIsMinorTimeStep(S) && (ssGetTimeOfLastOutput(S) == ssGetT(S))));  	    
      
	tBuffer++; uBuffer++;
      
    
      
                     


          
        
	
		
	  tMinusDelay = ((_rtP->P_34 > 0.0) ? _rtP->P_34 : 0.0);
	  tMinusDelay = simTime - tMinusDelay;

      
      
        
        _rtB->B_53_12_0[3] = benchmark_no_taylor_acc_rt_TDelayInterpolate(
        tMinusDelay,
        0.0,
        *tBuffer,
        *uBuffer,
        _rtDW->ComputationDelay_IWORK_i.CircularBufSize[3],
        &_rtDW->ComputationDelay_IWORK_i.Last[3],
        _rtDW->ComputationDelay_IWORK_i.Tail[3],
        _rtDW->ComputationDelay_IWORK_i.Head[3],
        _rtP->P_35[3],
        0,
        (boolean_T) (ssIsMinorTimeStep(S) && (ssGetTimeOfLastOutput(S) == ssGetT(S))));  	    
      
      
  }
   
        
if (ssIsSampleHit(S, 2, 0)) {
    rtb_B_53_13_0 = _rtB->B_53_12_0[2];
}
      
/* TransportDelay: '<S155>/Computation Delay' */
          {

    real_T **uBuffer = (real_T**)&_rtDW->ComputationDelay_PWORK_al.TUbufferPtrs[0];
    real_T **tBuffer = (real_T**)&_rtDW->ComputationDelay_PWORK_al.TUbufferPtrs[4];
    real_T simTime   = ssGetT(S);   
    
    
    real_T tMinusDelay ;
    
    
  
    
      
                     


          
        
	
		
	  tMinusDelay = ((_rtP->P_36 > 0.0) ? _rtP->P_36 : 0.0);
	  tMinusDelay = simTime - tMinusDelay;

      
      
        
        _rtB->B_53_14_0[0] = benchmark_no_taylor_acc_rt_TDelayInterpolate(
        tMinusDelay,
        0.0,
        *tBuffer,
        *uBuffer,
        _rtDW->ComputationDelay_IWORK_m.CircularBufSize[0],
        &_rtDW->ComputationDelay_IWORK_m.Last[0],
        _rtDW->ComputationDelay_IWORK_m.Tail[0],
        _rtDW->ComputationDelay_IWORK_m.Head[0],
        _rtP->P_37[0],
        0,
        (boolean_T) (ssIsMinorTimeStep(S) && (ssGetTimeOfLastOutput(S) == ssGetT(S))));  	    
      
	tBuffer++; uBuffer++;
      
    
      
                     


          
        
	
		
	  tMinusDelay = ((_rtP->P_36 > 0.0) ? _rtP->P_36 : 0.0);
	  tMinusDelay = simTime - tMinusDelay;

      
      
        
        _rtB->B_53_14_0[1] = benchmark_no_taylor_acc_rt_TDelayInterpolate(
        tMinusDelay,
        0.0,
        *tBuffer,
        *uBuffer,
        _rtDW->ComputationDelay_IWORK_m.CircularBufSize[1],
        &_rtDW->ComputationDelay_IWORK_m.Last[1],
        _rtDW->ComputationDelay_IWORK_m.Tail[1],
        _rtDW->ComputationDelay_IWORK_m.Head[1],
        _rtP->P_37[1],
        0,
        (boolean_T) (ssIsMinorTimeStep(S) && (ssGetTimeOfLastOutput(S) == ssGetT(S))));  	    
      
	tBuffer++; uBuffer++;
      
    
      
                     


          
        
	
		
	  tMinusDelay = ((_rtP->P_36 > 0.0) ? _rtP->P_36 : 0.0);
	  tMinusDelay = simTime - tMinusDelay;

      
      
        
        _rtB->B_53_14_0[2] = benchmark_no_taylor_acc_rt_TDelayInterpolate(
        tMinusDelay,
        0.0,
        *tBuffer,
        *uBuffer,
        _rtDW->ComputationDelay_IWORK_m.CircularBufSize[2],
        &_rtDW->ComputationDelay_IWORK_m.Last[2],
        _rtDW->ComputationDelay_IWORK_m.Tail[2],
        _rtDW->ComputationDelay_IWORK_m.Head[2],
        _rtP->P_37[2],
        1,
        (boolean_T) (ssIsMinorTimeStep(S) && (ssGetTimeOfLastOutput(S) == ssGetT(S))));  	    
      
	tBuffer++; uBuffer++;
      
    
      
                     


          
        
	
		
	  tMinusDelay = ((_rtP->P_36 > 0.0) ? _rtP->P_36 : 0.0);
	  tMinusDelay = simTime - tMinusDelay;

      
      
        
        _rtB->B_53_14_0[3] = benchmark_no_taylor_acc_rt_TDelayInterpolate(
        tMinusDelay,
        0.0,
        *tBuffer,
        *uBuffer,
        _rtDW->ComputationDelay_IWORK_m.CircularBufSize[3],
        &_rtDW->ComputationDelay_IWORK_m.Last[3],
        _rtDW->ComputationDelay_IWORK_m.Tail[3],
        _rtDW->ComputationDelay_IWORK_m.Head[3],
        _rtP->P_37[3],
        0,
        (boolean_T) (ssIsMinorTimeStep(S) && (ssGetTimeOfLastOutput(S) == ssGetT(S))));  	    
      
      
  }
   
        
if (ssIsSampleHit(S, 2, 0)) {
    rtb_B_53_15_0 = _rtB->B_53_14_0[2];
}
      
/* TransportDelay: '<S171>/Computation Delay' */
          {

    real_T **uBuffer = (real_T**)&_rtDW->ComputationDelay_PWORK_ds.TUbufferPtrs[0];
    real_T **tBuffer = (real_T**)&_rtDW->ComputationDelay_PWORK_ds.TUbufferPtrs[4];
    real_T simTime   = ssGetT(S);   
    
    
    real_T tMinusDelay ;
    
    
  
    
      
                     


          
        
	
		
	  tMinusDelay = ((_rtP->P_38 > 0.0) ? _rtP->P_38 : 0.0);
	  tMinusDelay = simTime - tMinusDelay;

      
      
        
        _rtB->B_53_16_0[0] = benchmark_no_taylor_acc_rt_TDelayInterpolate(
        tMinusDelay,
        0.0,
        *tBuffer,
        *uBuffer,
        _rtDW->ComputationDelay_IWORK_ez.CircularBufSize[0],
        &_rtDW->ComputationDelay_IWORK_ez.Last[0],
        _rtDW->ComputationDelay_IWORK_ez.Tail[0],
        _rtDW->ComputationDelay_IWORK_ez.Head[0],
        _rtP->P_39[0],
        0,
        (boolean_T) (ssIsMinorTimeStep(S) && (ssGetTimeOfLastOutput(S) == ssGetT(S))));  	    
      
	tBuffer++; uBuffer++;
      
    
      
                     


          
        
	
		
	  tMinusDelay = ((_rtP->P_38 > 0.0) ? _rtP->P_38 : 0.0);
	  tMinusDelay = simTime - tMinusDelay;

      
      
        
        _rtB->B_53_16_0[1] = benchmark_no_taylor_acc_rt_TDelayInterpolate(
        tMinusDelay,
        0.0,
        *tBuffer,
        *uBuffer,
        _rtDW->ComputationDelay_IWORK_ez.CircularBufSize[1],
        &_rtDW->ComputationDelay_IWORK_ez.Last[1],
        _rtDW->ComputationDelay_IWORK_ez.Tail[1],
        _rtDW->ComputationDelay_IWORK_ez.Head[1],
        _rtP->P_39[1],
        0,
        (boolean_T) (ssIsMinorTimeStep(S) && (ssGetTimeOfLastOutput(S) == ssGetT(S))));  	    
      
	tBuffer++; uBuffer++;
      
    
      
                     


          
        
	
		
	  tMinusDelay = ((_rtP->P_38 > 0.0) ? _rtP->P_38 : 0.0);
	  tMinusDelay = simTime - tMinusDelay;

      
      
        
        _rtB->B_53_16_0[2] = benchmark_no_taylor_acc_rt_TDelayInterpolate(
        tMinusDelay,
        0.0,
        *tBuffer,
        *uBuffer,
        _rtDW->ComputationDelay_IWORK_ez.CircularBufSize[2],
        &_rtDW->ComputationDelay_IWORK_ez.Last[2],
        _rtDW->ComputationDelay_IWORK_ez.Tail[2],
        _rtDW->ComputationDelay_IWORK_ez.Head[2],
        _rtP->P_39[2],
        1,
        (boolean_T) (ssIsMinorTimeStep(S) && (ssGetTimeOfLastOutput(S) == ssGetT(S))));  	    
      
	tBuffer++; uBuffer++;
      
    
      
                     


          
        
	
		
	  tMinusDelay = ((_rtP->P_38 > 0.0) ? _rtP->P_38 : 0.0);
	  tMinusDelay = simTime - tMinusDelay;

      
      
        
        _rtB->B_53_16_0[3] = benchmark_no_taylor_acc_rt_TDelayInterpolate(
        tMinusDelay,
        0.0,
        *tBuffer,
        *uBuffer,
        _rtDW->ComputationDelay_IWORK_ez.CircularBufSize[3],
        &_rtDW->ComputationDelay_IWORK_ez.Last[3],
        _rtDW->ComputationDelay_IWORK_ez.Tail[3],
        _rtDW->ComputationDelay_IWORK_ez.Head[3],
        _rtP->P_39[3],
        0,
        (boolean_T) (ssIsMinorTimeStep(S) && (ssGetTimeOfLastOutput(S) == ssGetT(S))));  	    
      
      
  }
   
        
if (ssIsSampleHit(S, 2, 0)) {
    rtb_B_53_17_0 = _rtB->B_53_16_0[2];
}
      
/* TransportDelay: '<S43>/Computation Delay' */
          {

    real_T **uBuffer = (real_T**)&_rtDW->ComputationDelay_PWORK_dy.TUbufferPtrs[0];
    real_T **tBuffer = (real_T**)&_rtDW->ComputationDelay_PWORK_dy.TUbufferPtrs[4];
    real_T simTime   = ssGetT(S);   
    
    
    real_T tMinusDelay ;
    
    
  
    
      
                     


          
        
	
		
	  tMinusDelay = ((_rtP->P_40 > 0.0) ? _rtP->P_40 : 0.0);
	  tMinusDelay = simTime - tMinusDelay;

      
      
        
        _rtB->B_53_18_0[0] = benchmark_no_taylor_acc_rt_TDelayInterpolate(
        tMinusDelay,
        0.0,
        *tBuffer,
        *uBuffer,
        _rtDW->ComputationDelay_IWORK_e0.CircularBufSize[0],
        &_rtDW->ComputationDelay_IWORK_e0.Last[0],
        _rtDW->ComputationDelay_IWORK_e0.Tail[0],
        _rtDW->ComputationDelay_IWORK_e0.Head[0],
        _rtP->P_41[0],
        0,
        (boolean_T) (ssIsMinorTimeStep(S) && (ssGetTimeOfLastOutput(S) == ssGetT(S))));  	    
      
	tBuffer++; uBuffer++;
      
    
      
                     


          
        
	
		
	  tMinusDelay = ((_rtP->P_40 > 0.0) ? _rtP->P_40 : 0.0);
	  tMinusDelay = simTime - tMinusDelay;

      
      
        
        _rtB->B_53_18_0[1] = benchmark_no_taylor_acc_rt_TDelayInterpolate(
        tMinusDelay,
        0.0,
        *tBuffer,
        *uBuffer,
        _rtDW->ComputationDelay_IWORK_e0.CircularBufSize[1],
        &_rtDW->ComputationDelay_IWORK_e0.Last[1],
        _rtDW->ComputationDelay_IWORK_e0.Tail[1],
        _rtDW->ComputationDelay_IWORK_e0.Head[1],
        _rtP->P_41[1],
        0,
        (boolean_T) (ssIsMinorTimeStep(S) && (ssGetTimeOfLastOutput(S) == ssGetT(S))));  	    
      
	tBuffer++; uBuffer++;
      
    
      
                     


          
        
	
		
	  tMinusDelay = ((_rtP->P_40 > 0.0) ? _rtP->P_40 : 0.0);
	  tMinusDelay = simTime - tMinusDelay;

      
      
        
        _rtB->B_53_18_0[2] = benchmark_no_taylor_acc_rt_TDelayInterpolate(
        tMinusDelay,
        0.0,
        *tBuffer,
        *uBuffer,
        _rtDW->ComputationDelay_IWORK_e0.CircularBufSize[2],
        &_rtDW->ComputationDelay_IWORK_e0.Last[2],
        _rtDW->ComputationDelay_IWORK_e0.Tail[2],
        _rtDW->ComputationDelay_IWORK_e0.Head[2],
        _rtP->P_41[2],
        1,
        (boolean_T) (ssIsMinorTimeStep(S) && (ssGetTimeOfLastOutput(S) == ssGetT(S))));  	    
      
	tBuffer++; uBuffer++;
      
    
      
                     


          
        
	
		
	  tMinusDelay = ((_rtP->P_40 > 0.0) ? _rtP->P_40 : 0.0);
	  tMinusDelay = simTime - tMinusDelay;

      
      
        
        _rtB->B_53_18_0[3] = benchmark_no_taylor_acc_rt_TDelayInterpolate(
        tMinusDelay,
        0.0,
        *tBuffer,
        *uBuffer,
        _rtDW->ComputationDelay_IWORK_e0.CircularBufSize[3],
        &_rtDW->ComputationDelay_IWORK_e0.Last[3],
        _rtDW->ComputationDelay_IWORK_e0.Tail[3],
        _rtDW->ComputationDelay_IWORK_e0.Head[3],
        _rtP->P_41[3],
        0,
        (boolean_T) (ssIsMinorTimeStep(S) && (ssGetTimeOfLastOutput(S) == ssGetT(S))));  	    
      
      
  }
   
        
if (ssIsSampleHit(S, 2, 0) && (!(_rtDW->CTrate1_semaphoreTaken != 0))) {
    _rtDW->CTrate1_Buffer0[0] = rtb_B_53_1_0;
    _rtDW->CTrate1_Buffer0[1] = rtb_B_53_3_0;
    _rtDW->CTrate1_Buffer0[2] = rtb_B_53_5_0;
    _rtDW->CTrate1_Buffer0[3] = rtb_B_53_7_0;
    _rtDW->CTrate1_Buffer0[4] = rtb_B_53_9_0;
    _rtDW->CTrate1_Buffer0[5] = rtb_B_53_11_0;
    _rtDW->CTrate1_Buffer0[6] = rtb_B_53_13_0;
    _rtDW->CTrate1_Buffer0[7] = rtb_B_53_15_0;
    _rtDW->CTrate1_Buffer0[8] = rtb_B_53_17_0;
    _rtDW->CTrate1_Buffer0[9] = _rtB->B_53_18_0[2];
}
if (ssIsSampleHit(S, 3, 0)) {
    _rtDW->CTrate1_semaphoreTaken = 1;
    memcpy(&_rtB->B_53_20_0[0], &_rtDW->CTrate1_Buffer0[0], 10U * sizeof(real_T));
    _rtDW->CTrate1_semaphoreTaken = 0;
    if (ssIsSampleHit(S, 4, 0)) {
        memcpy(&_rtB->B_53_21_0[0], &_rtB->B_53_20_0[0], 10U * sizeof(real_T));
    }
}
      
/* TransportDelay: '<S4>/Reference delay' */
          {


      
    
    real_T **uBuffer = (real_T**)&_rtDW->Referencedelay_PWORK.TUbufferPtrs[0];
    real_T **tBuffer = (real_T**)&_rtDW->Referencedelay_PWORK.TUbufferPtrs[1];
    real_T simTime   = ssGetT(S);   
    
    
    real_T tMinusDelay = simTime - _rtP->P_42;
    
    
  
    
      
                     


          
        

      
      
        
        _rtB->B_53_22_0 = benchmark_no_taylor_acc_rt_TDelayInterpolate(
        tMinusDelay,
        0.0,
        *tBuffer,
        *uBuffer,
        _rtDW->Referencedelay_IWORK.CircularBufSize,
        &_rtDW->Referencedelay_IWORK.Last,
        _rtDW->Referencedelay_IWORK.Tail,
        _rtDW->Referencedelay_IWORK.Head,
        _rtP->P_43,
        0,
        (boolean_T) (ssIsMinorTimeStep(S) && (ssGetTimeOfLastOutput(S) == ssGetT(S))));  	    
      
      
  }
   
        
if (ssIsSampleHit(S, 4, 0)) {
    _rtB->B_53_23_0 = _rtB->B_53_22_0;
                      
          /* Level2 S-Function Block: '<S8>/B_0_0' (stateflow) */
          /* Call into Simulink for MEX-version of S-function */
          ssCallAccelRunBlock(S, 0, 0, SS_CALL_MDL_OUTPUTS);

   
        
      
/* ToWorkspace: '<Root>/B_44_12' */            /* Call into Simulink for To Workspace */
    ssCallAccelRunBlock(S, 53, 25, SS_CALL_MDL_OUTPUTS);


   
        
      
/* ToWorkspace: '<Root>/B_44_13' */            /* Call into Simulink for To Workspace */
    ssCallAccelRunBlock(S, 53, 26, SS_CALL_MDL_OUTPUTS);


   
        
}
/* Limited  Integrator  */
if (ssIsMajorTimeStep(S)) {
    if (_rtX->Integrator_CSTATE >= _rtP->P_45) {
        _rtX->Integrator_CSTATE = _rtP->P_45;
    } else {
        if (_rtX->Integrator_CSTATE <= _rtP->P_46) {
            _rtX->Integrator_CSTATE = _rtP->P_46;
        }
    }
}
_rtB->B_53_27_0 = _rtX->Integrator_CSTATE;
      
/* ToWorkspace: '<Root>/B_44_14' */            /* Call into Simulink for To Workspace */
    ssCallAccelRunBlock(S, 53, 28, SS_CALL_MDL_OUTPUTS);


   
        
      
/* FromWorkspace: '<S9>/FromWs' */        
    /* Call into Simulink for From Workspace */
    ssCallAccelRunBlock(S, 53, 29, SS_CALL_MDL_OUTPUTS);
  
   
        
_rtB->B_53_30_0 = _rtP->P_47 * _rtB->B_53_29_0;
      
/* ToWorkspace: '<Root>/B_44_16' */            /* Call into Simulink for To Workspace */
    ssCallAccelRunBlock(S, 53, 31, SS_CALL_MDL_OUTPUTS);


   
        
      
/* ToWorkspace: '<Root>/B_44_17' */            /* Call into Simulink for To Workspace */
    ssCallAccelRunBlock(S, 53, 32, SS_CALL_MDL_OUTPUTS);


   
        
rtb_B_53_33_0 = _rtX->TorqueIntegrator_CSTATE;
rtb_B_53_34_0 = _rtX->generatorint_CSTATE;
_rtB->B_53_36_0 = _rtX->TorqueIntegrator_CSTATE * _rtX->generatorint_CSTATE * _rtP->P_50;
rtb_B_53_37_0 = _rtX->TorqueIntegrator_CSTATE_h;
rtb_B_53_38_0 = _rtX->generatorint_CSTATE_h;
_rtB->B_53_40_0 = _rtX->TorqueIntegrator_CSTATE_h * _rtX->generatorint_CSTATE_h * _rtP->P_53;
rtb_B_53_41_0 = _rtX->TorqueIntegrator_CSTATE_o;
rtb_B_53_42_0 = _rtX->generatorint_CSTATE_b;
_rtB->B_53_44_0 = _rtX->TorqueIntegrator_CSTATE_o * _rtX->generatorint_CSTATE_b * _rtP->P_56;
rtb_B_53_45_0 = _rtX->TorqueIntegrator_CSTATE_p;
rtb_B_53_46_0 = _rtX->generatorint_CSTATE_bf;
_rtB->B_53_48_0 = _rtX->TorqueIntegrator_CSTATE_p * _rtX->generatorint_CSTATE_bf * _rtP->P_59;
rtb_B_53_49_0 = _rtX->TorqueIntegrator_CSTATE_f;
rtb_B_53_50_0 = _rtX->generatorint_CSTATE_a;
_rtB->B_53_52_0 = _rtX->TorqueIntegrator_CSTATE_f * _rtX->generatorint_CSTATE_a * _rtP->P_62;
rtb_B_53_53_0 = _rtX->TorqueIntegrator_CSTATE_j;
rtb_B_53_54_0 = _rtX->generatorint_CSTATE_g;
_rtB->B_53_56_0 = _rtX->TorqueIntegrator_CSTATE_j * _rtX->generatorint_CSTATE_g * _rtP->P_65;
rtb_B_53_17_0 = _rtX->TorqueIntegrator_CSTATE_i;
rtb_B_53_58_0 = _rtX->generatorint_CSTATE_i;
_rtB->B_53_60_0 = _rtX->TorqueIntegrator_CSTATE_i * _rtX->generatorint_CSTATE_i * _rtP->P_68;
rtb_B_53_9_0 = _rtX->TorqueIntegrator_CSTATE_oh;
rtb_B_53_11_0 = _rtX->generatorint_CSTATE_l;
_rtB->B_53_64_0 = _rtX->TorqueIntegrator_CSTATE_oh * _rtX->generatorint_CSTATE_l * _rtP->P_71;
rtb_B_53_1_0 = _rtX->TorqueIntegrator_CSTATE_n;
rtb_B_53_3_0 = _rtX->generatorint_CSTATE_bt;
_rtB->B_53_68_0 = _rtX->TorqueIntegrator_CSTATE_n * _rtX->generatorint_CSTATE_bt * _rtP->P_74;
rtb_B_53_69_0 = _rtX->TorqueIntegrator_CSTATE_nc;
rtb_B_53_70_0 = _rtX->generatorint_CSTATE_am;
_rtB->B_53_72_0 = _rtX->TorqueIntegrator_CSTATE_nc * _rtX->generatorint_CSTATE_am * _rtP->P_77;
if (ssIsSampleHit(S, 1, 0) && (!(_rtDW->CTrate_semaphoreTaken != 0))) {
    _rtDW->CTrate_Buffer0[0] = _rtB->B_53_36_0;
    _rtDW->CTrate_Buffer0[1] = _rtB->B_53_40_0;
    _rtDW->CTrate_Buffer0[2] = _rtB->B_53_44_0;
    _rtDW->CTrate_Buffer0[3] = _rtB->B_53_48_0;
    _rtDW->CTrate_Buffer0[4] = _rtB->B_53_52_0;
    _rtDW->CTrate_Buffer0[5] = _rtB->B_53_56_0;
    _rtDW->CTrate_Buffer0[6] = _rtB->B_53_60_0;
    _rtDW->CTrate_Buffer0[7] = _rtB->B_53_64_0;
    _rtDW->CTrate_Buffer0[8] = _rtB->B_53_68_0;
    _rtDW->CTrate_Buffer0[9] = _rtB->B_53_72_0;
}
if (ssIsSampleHit(S, 3, 0)) {
    _rtDW->CTrate_semaphoreTaken = 1;
    memcpy(&_rtB->B_53_462_0[0], &_rtDW->CTrate_Buffer0[0], 10U * sizeof(real_T));
    _rtDW->CTrate_semaphoreTaken = 0;
    _rtB->B_53_74_0 = _rtB->B_53_462_0[0];
    for (i = 0; i < 9; i++) {
        _rtB->B_53_74_0 += _rtB->B_53_462_0[i + 1];
    }
      
/* ToWorkspace: '<Root>/B_44_18' */            /* Call into Simulink for To Workspace */
    ssCallAccelRunBlock(S, 53, 75, SS_CALL_MDL_OUTPUTS);


   
        
      
/* ToWorkspace: '<Root>/B_44_19' */            /* Call into Simulink for To Workspace */
    ssCallAccelRunBlock(S, 53, 76, SS_CALL_MDL_OUTPUTS);


   
        
      
/* ToWorkspace: '<Root>/B_44_20' */            /* Call into Simulink for To Workspace */
    ssCallAccelRunBlock(S, 53, 77, SS_CALL_MDL_OUTPUTS);


   
        
}
if (ssIsSampleHit(S, 2, 0)) {
    _rtB->B_53_78_0 = _rtB->B_53_0_0[3];
    _rtB->B_53_79_0 = _rtB->B_53_2_0[3];
    _rtB->B_53_80_0 = _rtB->B_53_4_0[3];
    _rtB->B_53_81_0 = _rtB->B_53_6_0[3];
    _rtB->B_53_82_0 = _rtB->B_53_8_0[3];
    _rtB->B_53_83_0 = _rtB->B_53_10_0[3];
    _rtB->B_53_84_0 = _rtB->B_53_12_0[3];
    _rtB->B_53_85_0 = _rtB->B_53_14_0[3];
    _rtB->B_53_86_0 = _rtB->B_53_16_0[3];
    _rtB->B_53_87_0 = _rtB->B_53_18_0[3];
    if (!(_rtDW->CTrate2_semaphoreTaken != 0)) {
        _rtDW->CTrate2_Buffer0[0] = _rtB->B_53_78_0;
        _rtDW->CTrate2_Buffer0[1] = _rtB->B_53_79_0;
        _rtDW->CTrate2_Buffer0[2] = _rtB->B_53_80_0;
        _rtDW->CTrate2_Buffer0[3] = _rtB->B_53_81_0;
        _rtDW->CTrate2_Buffer0[4] = _rtB->B_53_82_0;
        _rtDW->CTrate2_Buffer0[5] = _rtB->B_53_83_0;
        _rtDW->CTrate2_Buffer0[6] = _rtB->B_53_84_0;
        _rtDW->CTrate2_Buffer0[7] = _rtB->B_53_85_0;
        _rtDW->CTrate2_Buffer0[8] = _rtB->B_53_86_0;
        _rtDW->CTrate2_Buffer0[9] = _rtB->B_53_87_0;
    }
}
if (ssIsSampleHit(S, 3, 0)) {
    _rtDW->CTrate2_semaphoreTaken = 1;
    memcpy(&_rtB->B_53_462_0[0], &_rtDW->CTrate2_Buffer0[0], 10U * sizeof(real_T));
    _rtDW->CTrate2_semaphoreTaken = 0;
      
/* ToWorkspace: '<Root>/B_44_21' */            /* Call into Simulink for To Workspace */
    ssCallAccelRunBlock(S, 53, 89, SS_CALL_MDL_OUTPUTS);


   
        
}
if (ssIsSampleHit(S, 2, 0)) {
    rtb_B_53_90_0 = _rtB->B_53_0_0[1];
    rtb_B_53_91_0 = _rtB->B_53_2_0[1];
    rtb_B_53_92_0 = _rtB->B_53_4_0[1];
    rtb_B_53_93_0 = _rtB->B_53_6_0[1];
    rtb_B_53_94_0 = _rtB->B_53_8_0[1];
    rtb_B_53_95_0 = _rtB->B_53_10_0[1];
    rtb_B_53_96_0 = _rtB->B_53_12_0[1];
    rtb_B_53_97_0 = _rtB->B_53_14_0[1];
    rtb_B_53_98_0 = _rtB->B_53_16_0[1];
    rtb_B_53_99_0 = _rtB->B_53_18_0[1];
    if (!(_rtDW->CTrate3_semaphoreTaken != 0)) {
        _rtDW->CTrate3_Buffer0[0] = _rtB->B_53_0_0[1];
        _rtDW->CTrate3_Buffer0[1] = _rtB->B_53_2_0[1];
        _rtDW->CTrate3_Buffer0[2] = _rtB->B_53_4_0[1];
        _rtDW->CTrate3_Buffer0[3] = _rtB->B_53_6_0[1];
        _rtDW->CTrate3_Buffer0[4] = _rtB->B_53_8_0[1];
        _rtDW->CTrate3_Buffer0[5] = _rtB->B_53_10_0[1];
        _rtDW->CTrate3_Buffer0[6] = _rtB->B_53_12_0[1];
        _rtDW->CTrate3_Buffer0[7] = _rtB->B_53_14_0[1];
        _rtDW->CTrate3_Buffer0[8] = _rtB->B_53_16_0[1];
        _rtDW->CTrate3_Buffer0[9] = _rtB->B_53_18_0[1];
    }
}
if (ssIsSampleHit(S, 3, 0)) {
    _rtDW->CTrate3_semaphoreTaken = 1;
    memcpy(&_rtB->B_53_462_0[0], &_rtDW->CTrate3_Buffer0[0], 10U * sizeof(real_T));
    _rtDW->CTrate3_semaphoreTaken = 0;
      
/* ToWorkspace: '<Root>/B_44_22' */            /* Call into Simulink for To Workspace */
    ssCallAccelRunBlock(S, 53, 101, SS_CALL_MDL_OUTPUTS);


   
        
}
if (ssIsSampleHit(S, 1, 0) && (!(_rtDW->CTrate4_semaphoreTaken != 0))) {
    _rtDW->CTrate4_Buffer0[0] = _rtB->B_53_102_0;
    _rtDW->CTrate4_Buffer0[1] = _rtB->B_53_103_0;
    _rtDW->CTrate4_Buffer0[2] = _rtB->B_53_104_0;
    _rtDW->CTrate4_Buffer0[3] = _rtB->B_53_105_0;
    _rtDW->CTrate4_Buffer0[4] = _rtB->B_53_106_0;
    _rtDW->CTrate4_Buffer0[5] = _rtB->B_53_107_0;
    _rtDW->CTrate4_Buffer0[6] = _rtB->B_53_108_0;
    _rtDW->CTrate4_Buffer0[7] = _rtB->B_53_109_0;
    _rtDW->CTrate4_Buffer0[8] = _rtB->B_53_110_0;
    _rtDW->CTrate4_Buffer0[9] = _rtB->B_53_111_0;
}
if (ssIsSampleHit(S, 3, 0)) {
    _rtDW->CTrate4_semaphoreTaken = 1;
    memcpy(&_rtB->B_53_462_0[0], &_rtDW->CTrate4_Buffer0[0], 10U * sizeof(real_T));
    _rtDW->CTrate4_semaphoreTaken = 0;
      
/* ToWorkspace: '<Root>/B_44_23' */            /* Call into Simulink for To Workspace */
    ssCallAccelRunBlock(S, 53, 113, SS_CALL_MDL_OUTPUTS);


   
        
}
B_53_114_0 = _rtX->Integrator_CSTATE_a;
if (ssIsSampleHit(S, 3, 0)) {
    rtb_B_53_116_0 = _rtDW->Output_DSTATE;
    for (i = 0; i < 9; i++) {
        _rtB->B_53_117_0[i] = _rtB->B_53_115_0[9 * (int32_T)_rtDW->Output_DSTATE + i];
    }
    _rtB->B_53_180_0[0] = _rtB->B_53_118_0;
    _rtB->B_53_180_0[1] = _rtDW->wcDelay2_DSTATE[0U];
    _rtB->B_53_180_0[2] = _rtDW->wcDelay3_DSTATE[0U];
    _rtB->B_53_180_0[3] = _rtDW->wcDelay4_DSTATE[0U];
    _rtB->B_53_180_0[4] = _rtDW->wcDelay5_DSTATE[0U];
    _rtB->B_53_180_0[5] = _rtDW->wcDelay6_DSTATE[0U];
    _rtB->B_53_180_0[6] = _rtDW->wcDelay7_DSTATE[0U];
    _rtB->B_53_180_0[7] = _rtDW->wcDelay8_DSTATE[0U];
    _rtB->B_53_180_0[8] = _rtDW->wcDelay9_DSTATE[0U];
    _rtB->B_53_180_0[9] = _rtDW->wcDelay10_DSTATE[0U];
    _rtB->B_53_180_0[10] = _rtB->B_53_129_0;
    _rtB->B_53_180_0[11] = _rtB->B_53_129_0;
    _rtB->B_53_180_0[12] = _rtDW->wcDelay3_DSTATE_g[0U];
    _rtB->B_53_180_0[13] = _rtDW->wcDelay4_DSTATE_j[0U];
    _rtB->B_53_180_0[14] = _rtB->B_53_129_0;
    _rtB->B_53_180_0[15] = _rtDW->wcDelay6_DSTATE_i[0U];
    _rtB->B_53_180_0[16] = _rtDW->wcDelay7_DSTATE_a[0U];
    _rtB->B_53_180_0[17] = _rtB->B_53_129_0;
    _rtB->B_53_180_0[18] = _rtDW->wcDelay9_DSTATE_c[0U];
    _rtB->B_53_180_0[19] = _rtDW->wcDelay10_DSTATE_e[0U];
    _rtB->B_53_180_0[20] = _rtB->B_53_137_0;
    _rtB->B_53_180_0[21] = _rtB->B_53_137_0;
    _rtB->B_53_180_0[22] = _rtB->B_53_137_0;
    _rtB->B_53_180_0[23] = _rtDW->wcDelay4_DSTATE_g[0U];
    _rtB->B_53_180_0[24] = _rtB->B_53_137_0;
    _rtB->B_53_180_0[25] = _rtB->B_53_137_0;
    _rtB->B_53_180_0[26] = _rtDW->wcDelay7_DSTATE_j[0U];
    _rtB->B_53_180_0[27] = _rtB->B_53_137_0;
    _rtB->B_53_180_0[28] = _rtB->B_53_137_0;
    _rtB->B_53_180_0[29] = _rtDW->wcDelay10_DSTATE_f[0U];
    _rtB->B_53_180_0[30] = _rtB->B_53_142_0;
    _rtB->B_53_180_0[31] = _rtB->B_53_142_0;
    _rtB->B_53_180_0[32] = _rtB->B_53_142_0;
    _rtB->B_53_180_0[33] = _rtB->B_53_142_0;
    _rtB->B_53_180_0[34] = _rtB->B_53_142_0;
    _rtB->B_53_180_0[35] = _rtB->B_53_142_0;
    _rtB->B_53_180_0[36] = _rtB->B_53_142_0;
    _rtB->B_53_180_0[37] = _rtB->B_53_142_0;
    _rtB->B_53_180_0[38] = _rtB->B_53_142_0;
    _rtB->B_53_180_0[39] = _rtB->B_53_142_0;
    _rtB->B_53_180_0[40] = _rtB->B_53_144_0;
    _rtB->B_53_180_0[41] = _rtDW->wcDelay2_DSTATE_e[0U];
    _rtB->B_53_180_0[42] = _rtDW->wcDelay3_DSTATE_gu[0U];
    _rtB->B_53_180_0[43] = _rtDW->wcDelay4_DSTATE_e[0U];
    _rtB->B_53_180_0[44] = _rtB->B_53_144_0;
    _rtB->B_53_180_0[45] = _rtDW->wcDelay6_DSTATE_o[0U];
    _rtB->B_53_180_0[46] = _rtDW->wcDelay7_DSTATE_az[0U];
    _rtB->B_53_180_0[47] = _rtDW->wcDelay8_DSTATE_f[0U];
    _rtB->B_53_180_0[48] = _rtDW->wcDelay9_DSTATE_n[0U];
    _rtB->B_53_180_0[49] = _rtDW->wcDelay10_DSTATE_h[0U];
    _rtB->B_53_180_0[50] = _rtB->B_53_154_0;
    _rtB->B_53_180_0[51] = _rtB->B_53_154_0;
    _rtB->B_53_180_0[52] = _rtDW->wcDelay3_DSTATE_p[0U];
    _rtB->B_53_180_0[53] = _rtDW->wcDelay4_DSTATE_n[0U];
    _rtB->B_53_180_0[54] = _rtB->B_53_154_0;
    _rtB->B_53_180_0[55] = _rtB->B_53_154_0;
    _rtB->B_53_180_0[56] = _rtDW->wcDelay7_DSTATE_l[0U];
    _rtB->B_53_180_0[57] = _rtB->B_53_154_0;
    _rtB->B_53_180_0[58] = _rtDW->wcDelay9_DSTATE_h[0U];
    _rtB->B_53_180_0[59] = _rtDW->wcDelay10_DSTATE_o[0U];
    _rtB->B_53_180_0[60] = _rtB->B_53_161_0;
    _rtB->B_53_180_0[61] = _rtB->B_53_161_0;
    _rtB->B_53_180_0[62] = _rtB->B_53_161_0;
    _rtB->B_53_180_0[63] = _rtDW->wcDelay4_DSTATE_no[0U];
    _rtB->B_53_180_0[64] = _rtB->B_53_161_0;
    _rtB->B_53_180_0[65] = _rtB->B_53_161_0;
    _rtB->B_53_180_0[66] = _rtB->B_53_161_0;
    _rtB->B_53_180_0[67] = _rtB->B_53_161_0;
    _rtB->B_53_180_0[68] = _rtB->B_53_161_0;
    _rtB->B_53_180_0[69] = _rtDW->wcDelay10_DSTATE_i[0U];
    _rtB->B_53_180_0[70] = _rtB->B_53_165_0;
    _rtB->B_53_180_0[71] = _rtB->B_53_165_0;
    _rtB->B_53_180_0[72] = _rtDW->wcDelay3_DSTATE_i[0U];
    _rtB->B_53_180_0[73] = _rtDW->wcDelay4_DSTATE_o[0U];
    _rtB->B_53_180_0[74] = _rtB->B_53_165_0;
    _rtB->B_53_180_0[75] = _rtDW->wcDelay6_DSTATE_og[0U];
    _rtB->B_53_180_0[76] = _rtDW->wcDelay7_DSTATE_an[0U];
    _rtB->B_53_180_0[77] = _rtB->B_53_165_0;
    _rtB->B_53_180_0[78] = _rtDW->wcDelay9_DSTATE_j[0U];
    _rtB->B_53_180_0[79] = _rtDW->wcDelay10_DSTATE_g[0U];
    _rtB->B_53_180_0[80] = _rtB->B_53_173_0;
    _rtB->B_53_180_0[81] = _rtB->B_53_173_0;
    _rtB->B_53_180_0[82] = _rtB->B_53_173_0;
    _rtB->B_53_180_0[83] = _rtDW->wcDelay4_DSTATE_jo[0U];
    _rtB->B_53_180_0[84] = _rtB->B_53_173_0;
    _rtB->B_53_180_0[85] = _rtB->B_53_173_0;
    _rtB->B_53_180_0[86] = _rtDW->wcDelay7_DSTATE_d[0U];
    _rtB->B_53_180_0[87] = _rtB->B_53_173_0;
    _rtB->B_53_180_0[88] = _rtB->B_53_173_0;
    _rtB->B_53_180_0[89] = _rtDW->wcDelay10_DSTATE_ik[0U];
    _rtB->B_53_180_0[90] = _rtB->B_53_178_0;
    _rtB->B_53_180_0[91] = _rtB->B_53_178_0;
    _rtB->B_53_180_0[92] = _rtB->B_53_178_0;
    _rtB->B_53_180_0[93] = _rtB->B_53_178_0;
    _rtB->B_53_180_0[94] = _rtB->B_53_178_0;
    _rtB->B_53_180_0[95] = _rtB->B_53_178_0;
    _rtB->B_53_180_0[96] = _rtB->B_53_178_0;
    _rtB->B_53_180_0[97] = _rtB->B_53_178_0;
    _rtB->B_53_180_0[98] = _rtB->B_53_178_0;
    _rtB->B_53_180_0[99] = _rtB->B_53_178_0;
    _rtB->B_53_233_0[0] = _rtB->B_53_118_0;
    _rtB->B_53_233_0[1] = _rtDW->wdDelay2_DSTATE[0U];
    _rtB->B_53_233_0[2] = _rtDW->wdDelay3_DSTATE[0U];
    _rtB->B_53_233_0[3] = _rtDW->wdDelay4_DSTATE[0U];
    _rtB->B_53_233_0[4] = _rtDW->wdDelay5_DSTATE[0U];
    _rtB->B_53_233_0[5] = _rtDW->wdDelay6_DSTATE[0U];
    _rtB->B_53_233_0[6] = _rtDW->wdDelay7_DSTATE[0U];
    _rtB->B_53_233_0[7] = _rtDW->wdDelay8_DSTATE[0U];
    _rtB->B_53_233_0[8] = _rtDW->wdDelay9_DSTATE[0U];
    _rtB->B_53_233_0[9] = _rtDW->wdDelay10_DSTATE[0U];
    _rtB->B_53_233_0[10] = _rtB->B_53_129_0;
    _rtB->B_53_233_0[11] = _rtB->B_53_129_0;
    _rtB->B_53_233_0[12] = _rtDW->wdDelay3_DSTATE_g[0U];
    _rtB->B_53_233_0[13] = _rtDW->wdDelay4_DSTATE_g[0U];
    _rtB->B_53_233_0[14] = _rtB->B_53_129_0;
    _rtB->B_53_233_0[15] = _rtDW->wdDelay6_DSTATE_m[0U];
    _rtB->B_53_233_0[16] = _rtDW->wdDelay7_DSTATE_n[0U];
    _rtB->B_53_233_0[17] = _rtB->B_53_129_0;
    _rtB->B_53_233_0[18] = _rtDW->wdDelay9_DSTATE_b[0U];
    _rtB->B_53_233_0[19] = _rtDW->wdDelay10_DSTATE_a[0U];
    _rtB->B_53_233_0[20] = _rtB->B_53_137_0;
    _rtB->B_53_233_0[21] = _rtB->B_53_137_0;
    _rtB->B_53_233_0[22] = _rtB->B_53_137_0;
    _rtB->B_53_233_0[23] = _rtDW->wdDelay4_DSTATE_n[0U];
    _rtB->B_53_233_0[24] = _rtB->B_53_137_0;
    _rtB->B_53_233_0[25] = _rtB->B_53_137_0;
    _rtB->B_53_233_0[26] = _rtDW->wdDelay7_DSTATE_e[0U];
    _rtB->B_53_233_0[27] = _rtB->B_53_137_0;
    _rtB->B_53_233_0[28] = _rtB->B_53_137_0;
    _rtB->B_53_233_0[29] = _rtDW->wdDelay10_DSTATE_a3[0U];
    _rtB->B_53_233_0[30] = _rtB->B_53_142_0;
    _rtB->B_53_233_0[31] = _rtB->B_53_142_0;
    _rtB->B_53_233_0[32] = _rtB->B_53_142_0;
    _rtB->B_53_233_0[33] = _rtB->B_53_142_0;
    _rtB->B_53_233_0[34] = _rtB->B_53_142_0;
    _rtB->B_53_233_0[35] = _rtB->B_53_142_0;
    _rtB->B_53_233_0[36] = _rtB->B_53_142_0;
    _rtB->B_53_233_0[37] = _rtB->B_53_142_0;
    _rtB->B_53_233_0[38] = _rtB->B_53_142_0;
    _rtB->B_53_233_0[39] = _rtB->B_53_142_0;
    _rtB->B_53_233_0[40] = _rtB->B_53_144_0;
    _rtB->B_53_233_0[41] = _rtDW->wdDelay2_DSTATE_m[0U];
    _rtB->B_53_233_0[42] = _rtDW->wdDelay3_DSTATE_k[0U];
    _rtB->B_53_233_0[43] = _rtDW->wdDelay4_DSTATE_nd[0U];
    _rtB->B_53_233_0[44] = _rtB->B_53_144_0;
    _rtB->B_53_233_0[45] = _rtDW->wdDelay6_DSTATE_h[0U];
    _rtB->B_53_233_0[46] = _rtDW->wdDelay7_DSTATE_h[0U];
    _rtB->B_53_233_0[47] = _rtDW->wdDelay8_DSTATE_l[0U];
    _rtB->B_53_233_0[48] = _rtDW->wdDelay9_DSTATE_k[0U];
    _rtB->B_53_233_0[49] = _rtDW->wdDelay10_DSTATE_i[0U];
    _rtB->B_53_233_0[50] = _rtB->B_53_154_0;
    _rtB->B_53_233_0[51] = _rtB->B_53_154_0;
    _rtB->B_53_233_0[52] = _rtDW->wdDelay3_DSTATE_a[0U];
    _rtB->B_53_233_0[53] = _rtDW->wdDelay4_DSTATE_m[0U];
    _rtB->B_53_233_0[54] = _rtB->B_53_154_0;
    _rtB->B_53_233_0[55] = _rtB->B_53_154_0;
    _rtB->B_53_233_0[56] = _rtDW->wdDelay7_DSTATE_a[0U];
    _rtB->B_53_233_0[57] = _rtB->B_53_154_0;
    _rtB->B_53_233_0[58] = _rtDW->wdDelay9_DSTATE_n[0U];
    _rtB->B_53_233_0[59] = _rtDW->wdDelay10_DSTATE_aw[0U];
    _rtB->B_53_233_0[60] = _rtB->B_53_161_0;
    _rtB->B_53_233_0[61] = _rtB->B_53_161_0;
    _rtB->B_53_233_0[62] = _rtB->B_53_161_0;
    _rtB->B_53_233_0[63] = _rtDW->wdDelay4_DSTATE_e[0U];
    _rtB->B_53_233_0[64] = _rtB->B_53_161_0;
    _rtB->B_53_233_0[65] = _rtB->B_53_161_0;
    _rtB->B_53_233_0[66] = _rtB->B_53_161_0;
    _rtB->B_53_233_0[67] = _rtB->B_53_161_0;
    _rtB->B_53_233_0[68] = _rtB->B_53_161_0;
    _rtB->B_53_233_0[69] = _rtDW->wdDelay10_DSTATE_o[0U];
    _rtB->B_53_233_0[70] = _rtB->B_53_165_0;
    _rtB->B_53_233_0[71] = _rtB->B_53_165_0;
    _rtB->B_53_233_0[72] = _rtDW->wdDelay3_DSTATE_j[0U];
    _rtB->B_53_233_0[73] = _rtDW->wdDelay4_DSTATE_nw[0U];
    _rtB->B_53_233_0[74] = _rtB->B_53_165_0;
    _rtB->B_53_233_0[75] = _rtDW->wdDelay6_DSTATE_mj[0U];
    _rtB->B_53_233_0[76] = _rtDW->wdDelay7_DSTATE_g[0U];
    _rtB->B_53_233_0[77] = _rtB->B_53_165_0;
    _rtB->B_53_233_0[78] = _rtDW->wdDelay9_DSTATE_m[0U];
    _rtB->B_53_233_0[79] = _rtDW->wdDelay10_DSTATE_e[0U];
    _rtB->B_53_233_0[80] = _rtB->B_53_173_0;
    _rtB->B_53_233_0[81] = _rtB->B_53_173_0;
    _rtB->B_53_233_0[82] = _rtB->B_53_173_0;
    _rtB->B_53_233_0[83] = _rtDW->wdDelay4_DSTATE_b[0U];
    _rtB->B_53_233_0[84] = _rtB->B_53_173_0;
    _rtB->B_53_233_0[85] = _rtB->B_53_173_0;
    _rtB->B_53_233_0[86] = _rtDW->wdDelay7_DSTATE_o[0U];
    _rtB->B_53_233_0[87] = _rtB->B_53_173_0;
    _rtB->B_53_233_0[88] = _rtB->B_53_173_0;
    _rtB->B_53_233_0[89] = _rtDW->wdDelay10_DSTATE_g[0U];
    _rtB->B_53_233_0[90] = _rtB->B_53_178_0;
    _rtB->B_53_233_0[91] = _rtB->B_53_178_0;
    _rtB->B_53_233_0[92] = _rtB->B_53_178_0;
    _rtB->B_53_233_0[93] = _rtB->B_53_178_0;
    _rtB->B_53_233_0[94] = _rtB->B_53_178_0;
    _rtB->B_53_233_0[95] = _rtB->B_53_178_0;
    _rtB->B_53_233_0[96] = _rtB->B_53_178_0;
    _rtB->B_53_233_0[97] = _rtB->B_53_178_0;
    _rtB->B_53_233_0[98] = _rtB->B_53_178_0;
    _rtB->B_53_233_0[99] = _rtB->B_53_178_0;
    _rtB->B_53_286_0[0] = _rtB->B_53_118_0;
    _rtB->B_53_286_0[1] = _rtDW->ctDelay2_DSTATE[0U];
    _rtB->B_53_286_0[2] = _rtDW->ctDelay3_DSTATE[0U];
    _rtB->B_53_286_0[3] = _rtDW->ctDelay4_DSTATE[0U];
    _rtB->B_53_286_0[4] = _rtDW->ctDelay5_DSTATE[0U];
    _rtB->B_53_286_0[5] = _rtDW->ctDelay6_DSTATE[0U];
    _rtB->B_53_286_0[6] = _rtDW->ctDelay7_DSTATE[0U];
    _rtB->B_53_286_0[7] = _rtDW->ctDelay8_DSTATE[0U];
    _rtB->B_53_286_0[8] = _rtDW->ctDelay9_DSTATE[0U];
    _rtB->B_53_286_0[9] = _rtDW->ctDelay10_DSTATE[0U];
    _rtB->B_53_286_0[10] = _rtB->B_53_129_0;
    _rtB->B_53_286_0[11] = _rtB->B_53_129_0;
    _rtB->B_53_286_0[12] = _rtDW->ctDelay3_DSTATE_l[0U];
    _rtB->B_53_286_0[13] = _rtDW->ctDelay4_DSTATE_e[0U];
    _rtB->B_53_286_0[14] = _rtB->B_53_129_0;
    _rtB->B_53_286_0[15] = _rtDW->ctDelay6_DSTATE_k[0U];
    _rtB->B_53_286_0[16] = _rtDW->ctDelay7_DSTATE_n[0U];
    _rtB->B_53_286_0[17] = _rtB->B_53_129_0;
    _rtB->B_53_286_0[18] = _rtDW->ctDelay9_DSTATE_k[0U];
    _rtB->B_53_286_0[19] = _rtDW->ctDelay10_DSTATE_a[0U];
    _rtB->B_53_286_0[20] = _rtB->B_53_137_0;
    _rtB->B_53_286_0[21] = _rtB->B_53_137_0;
    _rtB->B_53_286_0[22] = _rtB->B_53_137_0;
    _rtB->B_53_286_0[23] = _rtDW->ctDelay4_DSTATE_er[0U];
    _rtB->B_53_286_0[24] = _rtB->B_53_137_0;
    _rtB->B_53_286_0[25] = _rtB->B_53_137_0;
    _rtB->B_53_286_0[26] = _rtDW->ctDelay7_DSTATE_j[0U];
    _rtB->B_53_286_0[27] = _rtB->B_53_137_0;
    _rtB->B_53_286_0[28] = _rtB->B_53_137_0;
    _rtB->B_53_286_0[29] = _rtDW->ctDelay10_DSTATE_p[0U];
    _rtB->B_53_286_0[30] = _rtB->B_53_142_0;
    _rtB->B_53_286_0[31] = _rtB->B_53_142_0;
    _rtB->B_53_286_0[32] = _rtB->B_53_142_0;
    _rtB->B_53_286_0[33] = _rtB->B_53_142_0;
    _rtB->B_53_286_0[34] = _rtB->B_53_142_0;
    _rtB->B_53_286_0[35] = _rtB->B_53_142_0;
    _rtB->B_53_286_0[36] = _rtB->B_53_142_0;
    _rtB->B_53_286_0[37] = _rtB->B_53_142_0;
    _rtB->B_53_286_0[38] = _rtB->B_53_142_0;
    _rtB->B_53_286_0[39] = _rtB->B_53_142_0;
    _rtB->B_53_286_0[40] = _rtB->B_53_144_0;
    _rtB->B_53_286_0[41] = _rtDW->ctDelay2_DSTATE_m[0U];
    _rtB->B_53_286_0[42] = _rtDW->ctDelay3_DSTATE_k[0U];
    _rtB->B_53_286_0[43] = _rtDW->ctDelay4_DSTATE_o[0U];
    _rtB->B_53_286_0[44] = _rtB->B_53_144_0;
    _rtB->B_53_286_0[45] = _rtDW->ctDelay6_DSTATE_f[0U];
    _rtB->B_53_286_0[46] = _rtDW->ctDelay7_DSTATE_d[0U];
    _rtB->B_53_286_0[47] = _rtDW->ctDelay8_DSTATE_e[0U];
    _rtB->B_53_286_0[48] = _rtDW->ctDelay9_DSTATE_a[0U];
    _rtB->B_53_286_0[49] = _rtDW->ctDelay10_DSTATE_d[0U];
    _rtB->B_53_286_0[50] = _rtB->B_53_154_0;
    _rtB->B_53_286_0[51] = _rtB->B_53_154_0;
    _rtB->B_53_286_0[52] = _rtDW->ctDelay3_DSTATE_j[0U];
    _rtB->B_53_286_0[53] = _rtDW->ctDelay4_DSTATE_c[0U];
    _rtB->B_53_286_0[54] = _rtB->B_53_154_0;
    _rtB->B_53_286_0[55] = _rtB->B_53_154_0;
    _rtB->B_53_286_0[56] = _rtDW->ctDelay7_DSTATE_m[0U];
    _rtB->B_53_286_0[57] = _rtB->B_53_154_0;
    _rtB->B_53_286_0[58] = _rtDW->ctDelay9_DSTATE_n[0U];
    _rtB->B_53_286_0[59] = _rtDW->ctDelay10_DSTATE_j[0U];
    _rtB->B_53_286_0[60] = _rtB->B_53_161_0;
    _rtB->B_53_286_0[61] = _rtB->B_53_161_0;
    _rtB->B_53_286_0[62] = _rtB->B_53_161_0;
    _rtB->B_53_286_0[63] = _rtDW->ctDelay4_DSTATE_ob[0U];
    _rtB->B_53_286_0[64] = _rtB->B_53_161_0;
    _rtB->B_53_286_0[65] = _rtB->B_53_161_0;
    _rtB->B_53_286_0[66] = _rtB->B_53_161_0;
    _rtB->B_53_286_0[67] = _rtB->B_53_161_0;
    _rtB->B_53_286_0[68] = _rtB->B_53_161_0;
    _rtB->B_53_286_0[69] = _rtDW->ctDelay10_DSTATE_d2[0U];
    _rtB->B_53_286_0[70] = _rtB->B_53_165_0;
    _rtB->B_53_286_0[71] = _rtB->B_53_165_0;
    _rtB->B_53_286_0[72] = _rtDW->ctDelay3_DSTATE_d[0U];
    _rtB->B_53_286_0[73] = _rtDW->ctDelay4_DSTATE_i[0U];
    _rtB->B_53_286_0[74] = _rtB->B_53_165_0;
    _rtB->B_53_286_0[75] = _rtDW->ctDelay6_DSTATE_n[0U];
    _rtB->B_53_286_0[76] = _rtDW->ctDelay7_DSTATE_f[0U];
    _rtB->B_53_286_0[77] = _rtB->B_53_165_0;
    _rtB->B_53_286_0[78] = _rtDW->ctDelay9_DSTATE_f[0U];
    _rtB->B_53_286_0[79] = _rtDW->ctDelay10_DSTATE_h[0U];
    _rtB->B_53_286_0[80] = _rtB->B_53_173_0;
    _rtB->B_53_286_0[81] = _rtB->B_53_173_0;
    _rtB->B_53_286_0[82] = _rtB->B_53_173_0;
    _rtB->B_53_286_0[83] = _rtDW->ctDelay4_DSTATE_m[0U];
    _rtB->B_53_286_0[84] = _rtB->B_53_173_0;
    _rtB->B_53_286_0[85] = _rtB->B_53_173_0;
    _rtB->B_53_286_0[86] = _rtDW->ctDelay7_DSTATE_db[0U];
    _rtB->B_53_286_0[87] = _rtB->B_53_173_0;
    _rtB->B_53_286_0[88] = _rtB->B_53_173_0;
    _rtB->B_53_286_0[89] = _rtDW->ctDelay10_DSTATE_b[0U];
    _rtB->B_53_286_0[90] = _rtB->B_53_178_0;
    _rtB->B_53_286_0[91] = _rtB->B_53_178_0;
    _rtB->B_53_286_0[92] = _rtB->B_53_178_0;
    _rtB->B_53_286_0[93] = _rtB->B_53_178_0;
    _rtB->B_53_286_0[94] = _rtB->B_53_178_0;
    _rtB->B_53_286_0[95] = _rtB->B_53_178_0;
    _rtB->B_53_286_0[96] = _rtB->B_53_178_0;
    _rtB->B_53_286_0[97] = _rtB->B_53_178_0;
    _rtB->B_53_286_0[98] = _rtB->B_53_178_0;
    _rtB->B_53_286_0[99] = _rtB->B_53_178_0;
                      
          /* Level2 S-Function Block: '<S182>/B_23_0' (stateflow) */
          /* Call into Simulink for MEX-version of S-function */
          ssCallAccelRunBlock(S, 32, 0, SS_CALL_MDL_OUTPUTS);

   
        
                      
          /* Level2 S-Function Block: '<S217>/B_34_0' (stateflow) */
          /* Call into Simulink for MEX-version of S-function */
          ssCallAccelRunBlock(S, 43, 0, SS_CALL_MDL_OUTPUTS);

   
        
}
B_53_290_0_idx_1 = _rtP->P_229[1] * _rtX->Tower_CSTATE[1];
if (_rtB->B_53_289_0 > _rtP->P_231) {
    rtb_B_53_466_0 = 0.0;
} else {
    rtb_B_53_466_0 = _rtP->P_229[0] * _rtX->Tower_CSTATE[0];
}
rtb_B_53_292_0 = _rtB->B_43_0_1 - rtb_B_53_466_0;
rtb_B_53_293_0 = _rtX->rotorint_CSTATE;
B_53_295_0 = 1.0 / rtb_B_53_292_0 * (_rtP->P_233 * _rtX->rotorint_CSTATE);
      
/* Lookup2D: '<S29>/C_T table'
* About '<S29>/C_T table':
                * Input0  Data Type:  Floating Point real_T
            * Input1  Data Type:  Floating Point real_T
               * Output0 Data Type:  Floating Point real_T
         * Saturation Mode: Saturate
     * Lookup Method: Linear_Endpoint
     *
     * Row Data    parameter uses the same data type and scaling as Input0
     * Column Data parameter uses the same data type and scaling as Input1
     * Table Data  parameter uses the same data type and scaling as Output0
 */
                                      
  
  
  benchmark_no_taylor_acc_Look2D_real_T_real_T_real_T_SAT( &(_rtB->B_53_296_0), _rtP->P_236, B_53_114_0, _rtP->P_234, 450U, B_53_295_0, _rtP->P_235, 249U);
        
    

   
        
B_53_297_0 = _rtX->Integrator_CSTATE_p;
if (ssIsSampleHit(S, 3, 0)) {
    rtb_B_53_299_0 = _rtDW->Output_DSTATE_g;
    for (i = 0; i < 9; i++) {
        _rtB->B_53_300_0[i] = _rtB->B_53_298_0[9 * (int32_T)_rtDW->Output_DSTATE_g + i];
    }
                      
          /* Level2 S-Function Block: '<S225>/B_36_0' (stateflow) */
          /* Call into Simulink for MEX-version of S-function */
          ssCallAccelRunBlock(S, 45, 0, SS_CALL_MDL_OUTPUTS);

   
        
}
B_53_303_0_idx_1 = _rtP->P_242[1] * _rtX->Tower_CSTATE_p[1];
if (_rtB->B_53_302_0 > _rtP->P_244) {
    rtb_B_53_466_0 = 0.0;
} else {
    rtb_B_53_466_0 = _rtP->P_242[0] * _rtX->Tower_CSTATE_p[0];
}
rtb_B_53_305_0 = _rtB->B_45_0_1 - rtb_B_53_466_0;
rtb_B_53_306_0 = _rtX->rotorint_CSTATE_f;
B_53_308_0 = 1.0 / rtb_B_53_305_0 * (_rtP->P_246 * _rtX->rotorint_CSTATE_f);
      
/* Lookup2D: '<S61>/C_T table'
* About '<S61>/C_T table':
                * Input0  Data Type:  Floating Point real_T
            * Input1  Data Type:  Floating Point real_T
               * Output0 Data Type:  Floating Point real_T
         * Saturation Mode: Saturate
     * Lookup Method: Linear_Endpoint
     *
     * Row Data    parameter uses the same data type and scaling as Input0
     * Column Data parameter uses the same data type and scaling as Input1
     * Table Data  parameter uses the same data type and scaling as Output0
 */
                                      
  
  
  benchmark_no_taylor_acc_Look2D_real_T_real_T_real_T_SAT( &(_rtB->B_53_309_0), _rtP->P_249, B_53_297_0, _rtP->P_247, 450U, B_53_308_0, _rtP->P_248, 249U);


   
        
B_53_310_0 = _rtX->Integrator_CSTATE_m;
if (ssIsSampleHit(S, 3, 0)) {
    rtb_B_53_312_0 = _rtDW->Output_DSTATE_d;
    for (i = 0; i < 9; i++) {
        _rtB->B_53_313_0[i] = _rtB->B_53_311_0[9 * (int32_T)_rtDW->Output_DSTATE_d + i];
    }
                      
          /* Level2 S-Function Block: '<S229>/B_37_0' (stateflow) */
          /* Call into Simulink for MEX-version of S-function */
          ssCallAccelRunBlock(S, 46, 0, SS_CALL_MDL_OUTPUTS);

   
        
}
B_53_316_0_idx_1 = _rtP->P_255[1] * _rtX->Tower_CSTATE_d[1];
if (_rtB->B_53_315_0 > _rtP->P_257) {
    rtb_B_53_466_0 = 0.0;
} else {
    rtb_B_53_466_0 = _rtP->P_255[0] * _rtX->Tower_CSTATE_d[0];
}
rtb_B_53_318_0 = _rtB->B_46_0_1 - rtb_B_53_466_0;
rtb_B_53_319_0 = _rtX->rotorint_CSTATE_a;
B_53_321_0 = 1.0 / rtb_B_53_318_0 * (_rtP->P_259 * _rtX->rotorint_CSTATE_a);
      
/* Lookup2D: '<S77>/C_T table'
* About '<S77>/C_T table':
                * Input0  Data Type:  Floating Point real_T
            * Input1  Data Type:  Floating Point real_T
               * Output0 Data Type:  Floating Point real_T
         * Saturation Mode: Saturate
     * Lookup Method: Linear_Endpoint
     *
     * Row Data    parameter uses the same data type and scaling as Input0
     * Column Data parameter uses the same data type and scaling as Input1
     * Table Data  parameter uses the same data type and scaling as Output0
 */
                                      
  
  
  benchmark_no_taylor_acc_Look2D_real_T_real_T_real_T_SAT( &(_rtB->B_53_322_0), _rtP->P_262, B_53_310_0, _rtP->P_260, 450U, B_53_321_0, _rtP->P_261, 249U);


   
        
B_53_323_0 = _rtX->Integrator_CSTATE_i;
if (ssIsSampleHit(S, 3, 0)) {
    rtb_B_53_325_0 = _rtDW->Output_DSTATE_n;
    for (i = 0; i < 9; i++) {
        _rtB->B_53_326_0[i] = _rtB->B_53_324_0[9 * (int32_T)_rtDW->Output_DSTATE_n + i];
    }
                      
          /* Level2 S-Function Block: '<S233>/B_38_0' (stateflow) */
          /* Call into Simulink for MEX-version of S-function */
          ssCallAccelRunBlock(S, 47, 0, SS_CALL_MDL_OUTPUTS);

   
        
}
B_53_329_0_idx_1 = _rtP->P_268[1] * _rtX->Tower_CSTATE_i[1];
if (_rtB->B_53_328_0 > _rtP->P_270) {
    rtb_B_53_466_0 = 0.0;
} else {
    rtb_B_53_466_0 = _rtP->P_268[0] * _rtX->Tower_CSTATE_i[0];
}
rtb_B_53_331_0 = _rtB->B_47_0_1 - rtb_B_53_466_0;
rtb_B_53_332_0 = _rtX->rotorint_CSTATE_d;
B_53_334_0 = 1.0 / rtb_B_53_331_0 * (_rtP->P_272 * _rtX->rotorint_CSTATE_d);
      
/* Lookup2D: '<S93>/C_T table'
* About '<S93>/C_T table':
                * Input0  Data Type:  Floating Point real_T
            * Input1  Data Type:  Floating Point real_T
               * Output0 Data Type:  Floating Point real_T
         * Saturation Mode: Saturate
     * Lookup Method: Linear_Endpoint
     *
     * Row Data    parameter uses the same data type and scaling as Input0
     * Column Data parameter uses the same data type and scaling as Input1
     * Table Data  parameter uses the same data type and scaling as Output0
 */
                                      
  
  
  benchmark_no_taylor_acc_Look2D_real_T_real_T_real_T_SAT( &(_rtB->B_53_335_0), _rtP->P_275, B_53_323_0, _rtP->P_273, 450U, B_53_334_0, _rtP->P_274, 249U);


   
        
B_53_336_0 = _rtX->Integrator_CSTATE_pq;
if (ssIsSampleHit(S, 3, 0)) {
    rtb_B_53_338_0 = _rtDW->Output_DSTATE_h;
    for (i = 0; i < 9; i++) {
        _rtB->B_53_339_0[i] = _rtB->B_53_337_0[9 * (int32_T)_rtDW->Output_DSTATE_h + i];
    }
                      
          /* Level2 S-Function Block: '<S237>/B_39_0' (stateflow) */
          /* Call into Simulink for MEX-version of S-function */
          ssCallAccelRunBlock(S, 48, 0, SS_CALL_MDL_OUTPUTS);

   
        
}
B_53_342_0_idx_1 = _rtP->P_281[1] * _rtX->Tower_CSTATE_pr[1];
if (_rtB->B_53_341_0 > _rtP->P_283) {
    rtb_B_53_466_0 = 0.0;
} else {
    rtb_B_53_466_0 = _rtP->P_281[0] * _rtX->Tower_CSTATE_pr[0];
}
rtb_B_53_344_0 = _rtB->B_48_0_1 - rtb_B_53_466_0;
rtb_B_53_345_0 = _rtX->rotorint_CSTATE_k;
B_53_347_0 = 1.0 / rtb_B_53_344_0 * (_rtP->P_285 * _rtX->rotorint_CSTATE_k);
      
/* Lookup2D: '<S109>/C_T table'
* About '<S109>/C_T table':
                * Input0  Data Type:  Floating Point real_T
            * Input1  Data Type:  Floating Point real_T
               * Output0 Data Type:  Floating Point real_T
         * Saturation Mode: Saturate
     * Lookup Method: Linear_Endpoint
     *
     * Row Data    parameter uses the same data type and scaling as Input0
     * Column Data parameter uses the same data type and scaling as Input1
     * Table Data  parameter uses the same data type and scaling as Output0
 */
                                      
  
  
  benchmark_no_taylor_acc_Look2D_real_T_real_T_real_T_SAT( &(_rtB->B_53_348_0), _rtP->P_288, B_53_336_0, _rtP->P_286, 450U, B_53_347_0, _rtP->P_287, 249U);


   
        
B_53_349_0 = _rtX->Integrator_CSTATE_h;
if (ssIsSampleHit(S, 3, 0)) {
    rtb_B_53_351_0 = _rtDW->Output_DSTATE_e;
    for (i = 0; i < 9; i++) {
        _rtB->B_53_352_0[i] = _rtB->B_53_350_0[9 * (int32_T)_rtDW->Output_DSTATE_e + i];
    }
                      
          /* Level2 S-Function Block: '<S241>/B_40_0' (stateflow) */
          /* Call into Simulink for MEX-version of S-function */
          ssCallAccelRunBlock(S, 49, 0, SS_CALL_MDL_OUTPUTS);

   
        
}
B_53_355_0_idx_1 = _rtP->P_294[1] * _rtX->Tower_CSTATE_iw[1];
if (_rtB->B_53_354_0 > _rtP->P_296) {
    rtb_B_53_466_0 = 0.0;
} else {
    rtb_B_53_466_0 = _rtP->P_294[0] * _rtX->Tower_CSTATE_iw[0];
}
rtb_B_53_357_0 = _rtB->B_49_0_1 - rtb_B_53_466_0;
rtb_B_53_358_0 = _rtX->rotorint_CSTATE_e;
B_53_360_0 = 1.0 / rtb_B_53_357_0 * (_rtP->P_298 * _rtX->rotorint_CSTATE_e);
      
/* Lookup2D: '<S125>/C_T table'
* About '<S125>/C_T table':
                * Input0  Data Type:  Floating Point real_T
            * Input1  Data Type:  Floating Point real_T
               * Output0 Data Type:  Floating Point real_T
         * Saturation Mode: Saturate
     * Lookup Method: Linear_Endpoint
     *
     * Row Data    parameter uses the same data type and scaling as Input0
     * Column Data parameter uses the same data type and scaling as Input1
     * Table Data  parameter uses the same data type and scaling as Output0
 */
                                      
  
  
  benchmark_no_taylor_acc_Look2D_real_T_real_T_real_T_SAT( &(_rtB->B_53_361_0), _rtP->P_301, B_53_349_0, _rtP->P_299, 450U, B_53_360_0, _rtP->P_300, 249U);


   
        
B_53_362_0 = _rtX->Integrator_CSTATE_e;
if (ssIsSampleHit(S, 3, 0)) {
    rtb_B_53_364_0 = _rtDW->Output_DSTATE_db;
    for (i = 0; i < 9; i++) {
        _rtB->B_53_365_0[i] = _rtB->B_53_363_0[9 * (int32_T)_rtDW->Output_DSTATE_db + i];
    }
                      
          /* Level2 S-Function Block: '<S245>/B_41_0' (stateflow) */
          /* Call into Simulink for MEX-version of S-function */
          ssCallAccelRunBlock(S, 50, 0, SS_CALL_MDL_OUTPUTS);

   
        
}
B_53_368_0_idx_1 = _rtP->P_307[1] * _rtX->Tower_CSTATE_b[1];
if (_rtB->B_53_367_0 > _rtP->P_309) {
    rtb_B_53_466_0 = 0.0;
} else {
    rtb_B_53_466_0 = _rtP->P_307[0] * _rtX->Tower_CSTATE_b[0];
}
rtb_B_53_370_0 = _rtB->B_50_0_1 - rtb_B_53_466_0;
rtb_B_53_371_0 = _rtX->rotorint_CSTATE_fa;
B_53_373_0 = 1.0 / rtb_B_53_370_0 * (_rtP->P_311 * _rtX->rotorint_CSTATE_fa);
      
/* Lookup2D: '<S141>/C_T table'
* About '<S141>/C_T table':
                * Input0  Data Type:  Floating Point real_T
            * Input1  Data Type:  Floating Point real_T
               * Output0 Data Type:  Floating Point real_T
         * Saturation Mode: Saturate
     * Lookup Method: Linear_Endpoint
     *
     * Row Data    parameter uses the same data type and scaling as Input0
     * Column Data parameter uses the same data type and scaling as Input1
     * Table Data  parameter uses the same data type and scaling as Output0
 */
                                      
  
  
  benchmark_no_taylor_acc_Look2D_real_T_real_T_real_T_SAT( &(_rtB->B_53_374_0), _rtP->P_314, B_53_362_0, _rtP->P_312, 450U, B_53_373_0, _rtP->P_313, 249U);


   
        
B_53_375_0 = _rtX->Integrator_CSTATE_md;
if (ssIsSampleHit(S, 3, 0)) {
    rtb_B_53_377_0 = _rtDW->Output_DSTATE_o;
    for (i = 0; i < 9; i++) {
        _rtB->B_53_378_0[i] = _rtB->B_53_376_0[9 * (int32_T)_rtDW->Output_DSTATE_o + i];
    }
                      
          /* Level2 S-Function Block: '<S249>/B_42_0' (stateflow) */
          /* Call into Simulink for MEX-version of S-function */
          ssCallAccelRunBlock(S, 51, 0, SS_CALL_MDL_OUTPUTS);

   
        
}
B_53_381_0_idx_1 = _rtP->P_320[1] * _rtX->Tower_CSTATE_f[1];
if (_rtB->B_53_380_0 > _rtP->P_322) {
    rtb_B_53_466_0 = 0.0;
} else {
    rtb_B_53_466_0 = _rtP->P_320[0] * _rtX->Tower_CSTATE_f[0];
}
rtb_B_53_15_0 = _rtB->B_51_0_1 - rtb_B_53_466_0;
rtb_B_53_13_0 = _rtX->rotorint_CSTATE_o;
B_53_386_0 = 1.0 / rtb_B_53_15_0 * (_rtP->P_324 * _rtX->rotorint_CSTATE_o);
      
/* Lookup2D: '<S157>/C_T table'
* About '<S157>/C_T table':
                * Input0  Data Type:  Floating Point real_T
            * Input1  Data Type:  Floating Point real_T
               * Output0 Data Type:  Floating Point real_T
         * Saturation Mode: Saturate
     * Lookup Method: Linear_Endpoint
     *
     * Row Data    parameter uses the same data type and scaling as Input0
     * Column Data parameter uses the same data type and scaling as Input1
     * Table Data  parameter uses the same data type and scaling as Output0
 */
                                      
  
  
  benchmark_no_taylor_acc_Look2D_real_T_real_T_real_T_SAT( &(_rtB->B_53_387_0), _rtP->P_327, B_53_375_0, _rtP->P_325, 450U, B_53_386_0, _rtP->P_326, 249U);


   
        
B_53_388_0 = _rtX->Integrator_CSTATE_o;
if (ssIsSampleHit(S, 3, 0)) {
    rtb_B_53_390_0 = _rtDW->Output_DSTATE_d4;
    for (i = 0; i < 9; i++) {
        _rtB->B_53_391_0[i] = _rtB->B_53_389_0[9 * (int32_T)_rtDW->Output_DSTATE_d4 + i];
    }
                      
          /* Level2 S-Function Block: '<S253>/B_43_0' (stateflow) */
          /* Call into Simulink for MEX-version of S-function */
          ssCallAccelRunBlock(S, 52, 0, SS_CALL_MDL_OUTPUTS);

   
        
}
B_53_394_0_idx_1 = _rtP->P_333[1] * _rtX->Tower_CSTATE_m[1];
if (_rtB->B_53_393_0 > _rtP->P_335) {
    rtb_B_53_466_0 = 0.0;
} else {
    rtb_B_53_466_0 = _rtP->P_333[0] * _rtX->Tower_CSTATE_m[0];
}
rtb_B_53_7_0 = _rtB->B_52_0_1 - rtb_B_53_466_0;
rtb_B_53_5_0 = _rtX->rotorint_CSTATE_n;
B_53_399_0 = 1.0 / rtb_B_53_7_0 * (_rtP->P_337 * _rtX->rotorint_CSTATE_n);
      
/* Lookup2D: '<S173>/C_T table'
* About '<S173>/C_T table':
                * Input0  Data Type:  Floating Point real_T
            * Input1  Data Type:  Floating Point real_T
               * Output0 Data Type:  Floating Point real_T
         * Saturation Mode: Saturate
     * Lookup Method: Linear_Endpoint
     *
     * Row Data    parameter uses the same data type and scaling as Input0
     * Column Data parameter uses the same data type and scaling as Input1
     * Table Data  parameter uses the same data type and scaling as Output0
 */
                                      
  
  
  benchmark_no_taylor_acc_Look2D_real_T_real_T_real_T_SAT( &(_rtB->B_53_400_0), _rtP->P_340, B_53_388_0, _rtP->P_338, 450U, B_53_399_0, _rtP->P_339, 249U);


   
        
B_53_401_0 = _rtX->Integrator_CSTATE_j;
if (ssIsSampleHit(S, 3, 0)) {
    rtb_B_53_403_0 = _rtDW->Output_DSTATE_es;
    for (i = 0; i < 9; i++) {
        _rtB->B_53_404_0[i] = _rtB->B_53_402_0[9 * (int32_T)_rtDW->Output_DSTATE_es + i];
    }
                      
          /* Level2 S-Function Block: '<S221>/B_35_0' (stateflow) */
          /* Call into Simulink for MEX-version of S-function */
          ssCallAccelRunBlock(S, 44, 0, SS_CALL_MDL_OUTPUTS);

   
        
}
B_53_407_0_idx_1 = _rtP->P_346[1] * _rtX->Tower_CSTATE_c[1];
if (_rtB->B_53_406_0 > _rtP->P_348) {
    rtb_B_53_466_0 = 0.0;
} else {
    rtb_B_53_466_0 = _rtP->P_346[0] * _rtX->Tower_CSTATE_c[0];
}
rtb_B_53_409_0 = _rtB->B_44_0_1 - rtb_B_53_466_0;
rtb_B_53_410_0 = _rtX->rotorint_CSTATE_ai;
B_53_412_0 = 1.0 / rtb_B_53_409_0 * (_rtP->P_350 * _rtX->rotorint_CSTATE_ai);
      
/* Lookup2D: '<S45>/C_T table'
* About '<S45>/C_T table':
                * Input0  Data Type:  Floating Point real_T
            * Input1  Data Type:  Floating Point real_T
               * Output0 Data Type:  Floating Point real_T
         * Saturation Mode: Saturate
     * Lookup Method: Linear_Endpoint
     *
     * Row Data    parameter uses the same data type and scaling as Input0
     * Column Data parameter uses the same data type and scaling as Input1
     * Table Data  parameter uses the same data type and scaling as Output0
 */
                                      
  
  
  benchmark_no_taylor_acc_Look2D_real_T_real_T_real_T_SAT( &(_rtB->B_53_413_0), _rtP->P_353, B_53_401_0, _rtP->P_351, 450U, B_53_412_0, _rtP->P_352, 249U);


   
        
if (ssIsSampleHit(S, 1, 0) && (!(_rtDW->CTrate5_semaphoreTaken != 0))) {
    _rtDW->CTrate5_Buffer0[0] = _rtB->B_53_296_0;
    _rtDW->CTrate5_Buffer0[1] = _rtB->B_53_309_0;
    _rtDW->CTrate5_Buffer0[2] = _rtB->B_53_322_0;
    _rtDW->CTrate5_Buffer0[3] = _rtB->B_53_335_0;
    _rtDW->CTrate5_Buffer0[4] = _rtB->B_53_348_0;
    _rtDW->CTrate5_Buffer0[5] = _rtB->B_53_361_0;
    _rtDW->CTrate5_Buffer0[6] = _rtB->B_53_374_0;
    _rtDW->CTrate5_Buffer0[7] = _rtB->B_53_387_0;
    _rtDW->CTrate5_Buffer0[8] = _rtB->B_53_400_0;
    _rtDW->CTrate5_Buffer0[9] = _rtB->B_53_413_0;
}
if (ssIsSampleHit(S, 3, 0)) {
    _rtDW->CTrate5_semaphoreTaken = 1;
    memcpy(&_rtB->B_53_414_0[0], &_rtDW->CTrate5_Buffer0[0], 10U * sizeof(real_T));
    _rtDW->CTrate5_semaphoreTaken = 0;
      
/* ToWorkspace: '<Root>/B_44_45' */            /* Call into Simulink for To Workspace */
    ssCallAccelRunBlock(S, 53, 415, SS_CALL_MDL_OUTPUTS);


   
        
    _rtB->B_53_462_0[0] = _rtB->B_43_0_2;
    _rtB->B_53_462_0[1] = _rtB->B_45_0_2;
    _rtB->B_53_462_0[2] = _rtB->B_46_0_2;
    _rtB->B_53_462_0[3] = _rtB->B_47_0_2;
    _rtB->B_53_462_0[4] = _rtB->B_48_0_2;
    _rtB->B_53_462_0[5] = _rtB->B_49_0_2;
    _rtB->B_53_462_0[6] = _rtB->B_50_0_2;
    _rtB->B_53_462_0[7] = _rtB->B_51_0_2;
    _rtB->B_53_462_0[8] = _rtB->B_52_0_2;
    _rtB->B_53_462_0[9] = _rtB->B_44_0_2;
      
/* ToWorkspace: '<Root>/B_44_46' */            /* Call into Simulink for To Workspace */
    ssCallAccelRunBlock(S, 53, 417, SS_CALL_MDL_OUTPUTS);


   
        
    _rtB->B_53_462_0[0] = _rtB->B_43_0_1;
    _rtB->B_53_462_0[1] = _rtB->B_45_0_1;
    _rtB->B_53_462_0[2] = _rtB->B_46_0_1;
    _rtB->B_53_462_0[3] = _rtB->B_47_0_1;
    _rtB->B_53_462_0[4] = _rtB->B_48_0_1;
    _rtB->B_53_462_0[5] = _rtB->B_49_0_1;
    _rtB->B_53_462_0[6] = _rtB->B_50_0_1;
    _rtB->B_53_462_0[7] = _rtB->B_51_0_1;
    _rtB->B_53_462_0[8] = _rtB->B_52_0_1;
    _rtB->B_53_462_0[9] = _rtB->B_44_0_1;
      
/* ToWorkspace: '<Root>/B_44_47' */            /* Call into Simulink for To Workspace */
    ssCallAccelRunBlock(S, 53, 419, SS_CALL_MDL_OUTPUTS);


   
        
      
/* Scope: '<Root>/Scope' */            /* Call into Simulink for Scope */
    ssCallAccelRunBlock(S, 53, 420, SS_CALL_MDL_OUTPUTS);

   
        
}
_rtB->B_53_422_0 = (_rtB->B_53_74_0 - _rtB->B_53_30_0) * _rtP->P_354;
      
/* TransportDelay: '<S4>/F_meas delay' */
          {


      
    
    real_T **uBuffer = (real_T**)&_rtDW->F_measdelay_PWORK.TUbufferPtrs[0];
    real_T **tBuffer = (real_T**)&_rtDW->F_measdelay_PWORK.TUbufferPtrs[1];
    real_T simTime   = ssGetT(S);   
    
    
    real_T tMinusDelay = simTime - _rtP->P_355;
    
    
  
    
      
                     


          
        

      
      
        
        _rtB->B_53_423_0 = benchmark_no_taylor_acc_rt_TDelayInterpolate(
        tMinusDelay,
        0.0,
        *tBuffer,
        *uBuffer,
        _rtDW->F_measdelay_IWORK.CircularBufSize,
        &_rtDW->F_measdelay_IWORK.Last,
        _rtDW->F_measdelay_IWORK.Tail,
        _rtDW->F_measdelay_IWORK.Head,
        _rtP->P_356,
        1,
        (boolean_T) (ssIsMinorTimeStep(S) && (ssGetTimeOfLastOutput(S) == ssGetT(S))));  	    
      
      
  }
   
        
      
/* TransportDelay: '<S4>/P meas delay' */
          {


      
    
    real_T **uBuffer = (real_T**)&_rtDW->Pmeasdelay_PWORK.TUbufferPtrs[0];
    real_T **tBuffer = (real_T**)&_rtDW->Pmeasdelay_PWORK.TUbufferPtrs[1];
    real_T simTime   = ssGetT(S);   
    
    
    real_T tMinusDelay = simTime - _rtP->P_357;
    
    
  
    
      
                     


          
        

      
      
        
        _rtB->B_53_424_0 = benchmark_no_taylor_acc_rt_TDelayInterpolate(
        tMinusDelay,
        0.0,
        *tBuffer,
        *uBuffer,
        _rtDW->Pmeasdelay_IWORK.CircularBufSize,
        &_rtDW->Pmeasdelay_IWORK.Last,
        _rtDW->Pmeasdelay_IWORK.Tail,
        _rtDW->Pmeasdelay_IWORK.Head,
        _rtP->P_358,
        1,
        (boolean_T) (ssIsMinorTimeStep(S) && (ssGetTimeOfLastOutput(S) == ssGetT(S))));  	    
      
      
  }
   
        
if (ssIsSampleHit(S, 5, 0)) {
    _rtB->B_53_425_0 = _rtP->P_359;
    _rtB->B_53_426_0 = _rtDW->UnitDelay_DSTATE;
}
                      
          /* Level2 S-Function Block: '<S10>/B_1_0' (stateflow) */
          /* Call into Simulink for MEX-version of S-function */
          ssCallAccelRunBlock(S, 1, 0, SS_CALL_MDL_OUTPUTS);

   
        
if (ssIsSampleHit(S, 5, 0)) {
    _rtB->B_53_428_0 = _rtB->B_53_27_0;
    _rtB->B_53_429_0 = _rtB->B_0_0_2;
}
_rtB->B_53_431_0 = _rtP->P_362 * _rtX->torsionint_CSTATE;
_rtB->B_53_433_0 = _rtP->P_364 * _rtX->torsionint_CSTATE_a;
_rtB->B_53_435_0 = _rtP->P_366 * _rtX->torsionint_CSTATE_j;
_rtB->B_53_437_0 = _rtP->P_368 * _rtX->torsionint_CSTATE_aj;
_rtB->B_53_439_0 = _rtP->P_370 * _rtX->torsionint_CSTATE_n;
_rtB->B_53_441_0 = _rtP->P_372 * _rtX->torsionint_CSTATE_jv;
_rtB->B_53_443_0 = _rtP->P_374 * _rtX->torsionint_CSTATE_a4;
_rtB->B_53_445_0 = _rtP->P_376 * _rtX->torsionint_CSTATE_k;
_rtB->B_53_447_0 = _rtP->P_378 * _rtX->torsionint_CSTATE_c;
_rtB->B_53_449_0 = _rtP->P_380 * _rtX->torsionint_CSTATE_j2;
if (ssIsSampleHit(S, 1, 0) && (!(_rtDW->CTrate6_semaphoreTaken != 0))) {
    _rtDW->CTrate6_Buffer0[0] = _rtB->B_53_431_0;
    _rtDW->CTrate6_Buffer0[1] = _rtB->B_53_433_0;
    _rtDW->CTrate6_Buffer0[2] = _rtB->B_53_435_0;
    _rtDW->CTrate6_Buffer0[3] = _rtB->B_53_437_0;
    _rtDW->CTrate6_Buffer0[4] = _rtB->B_53_439_0;
    _rtDW->CTrate6_Buffer0[5] = _rtB->B_53_441_0;
    _rtDW->CTrate6_Buffer0[6] = _rtB->B_53_443_0;
    _rtDW->CTrate6_Buffer0[7] = _rtB->B_53_445_0;
    _rtDW->CTrate6_Buffer0[8] = _rtB->B_53_447_0;
    _rtDW->CTrate6_Buffer0[9] = _rtB->B_53_449_0;
}
if (ssIsSampleHit(S, 3, 0)) {
    _rtDW->CTrate6_semaphoreTaken = 1;
    memcpy(&_rtB->B_53_462_0[0], &_rtDW->CTrate6_Buffer0[0], 10U * sizeof(real_T));
    _rtDW->CTrate6_semaphoreTaken = 0;
      
/* ToWorkspace: '<S6>/B_44_52' */            /* Call into Simulink for To Workspace */
    ssCallAccelRunBlock(S, 53, 451, SS_CALL_MDL_OUTPUTS);


   
        
}
_rtB->B_53_452_0 = _rtP->P_381 * B_53_290_0_idx_1;
_rtB->B_53_453_0 = _rtP->P_382 * B_53_303_0_idx_1;
_rtB->B_53_454_0 = _rtP->P_383 * B_53_316_0_idx_1;
_rtB->B_53_455_0 = _rtP->P_384 * B_53_329_0_idx_1;
_rtB->B_53_456_0 = _rtP->P_385 * B_53_342_0_idx_1;
_rtB->B_53_457_0 = _rtP->P_386 * B_53_355_0_idx_1;
_rtB->B_53_458_0 = _rtP->P_387 * B_53_368_0_idx_1;
_rtB->B_53_459_0 = _rtP->P_388 * B_53_381_0_idx_1;
_rtB->B_53_460_0 = _rtP->P_389 * B_53_394_0_idx_1;
_rtB->B_53_461_0 = _rtP->P_390 * B_53_407_0_idx_1;
if (ssIsSampleHit(S, 1, 0) && (!(_rtDW->CTrate7_semaphoreTaken != 0))) {
    _rtDW->CTrate7_Buffer0[0] = _rtB->B_53_452_0;
    _rtDW->CTrate7_Buffer0[1] = _rtB->B_53_453_0;
    _rtDW->CTrate7_Buffer0[2] = _rtB->B_53_454_0;
    _rtDW->CTrate7_Buffer0[3] = _rtB->B_53_455_0;
    _rtDW->CTrate7_Buffer0[4] = _rtB->B_53_456_0;
    _rtDW->CTrate7_Buffer0[5] = _rtB->B_53_457_0;
    _rtDW->CTrate7_Buffer0[6] = _rtB->B_53_458_0;
    _rtDW->CTrate7_Buffer0[7] = _rtB->B_53_459_0;
    _rtDW->CTrate7_Buffer0[8] = _rtB->B_53_460_0;
    _rtDW->CTrate7_Buffer0[9] = _rtB->B_53_461_0;
}
if (ssIsSampleHit(S, 3, 0)) {
    _rtDW->CTrate7_semaphoreTaken = 1;
    memcpy(&_rtB->B_53_462_0[0], &_rtDW->CTrate7_Buffer0[0], 10U * sizeof(real_T));
    _rtDW->CTrate7_semaphoreTaken = 0;
      
/* ToWorkspace: '<S6>/B_44_53' */            /* Call into Simulink for To Workspace */
    ssCallAccelRunBlock(S, 53, 463, SS_CALL_MDL_OUTPUTS);


   
        
}
      
/* Lookup2D: '<S29>/C_P table '
* About '<S29>/C_P table ':
                * Input0  Data Type:  Floating Point real_T
            * Input1  Data Type:  Floating Point real_T
               * Output0 Data Type:  Floating Point real_T
         * Saturation Mode: Saturate
     * Lookup Method: Linear_Endpoint
     *
     * Row Data    parameter uses the same data type and scaling as Input0
     * Column Data parameter uses the same data type and scaling as Input1
     * Table Data  parameter uses the same data type and scaling as Output0
 */
                                      
  
  
  benchmark_no_taylor_acc_Look2D_real_T_real_T_real_T_SAT( &(B_53_464_0), _rtP->P_393, B_53_114_0, _rtP->P_391, 450U, B_53_295_0, _rtP->P_392, 249U);


   
        
rtb_B_53_466_0 = rtb_B_53_292_0 * rtb_B_53_292_0 * _rtP->P_394;
_rtB->B_53_467_0 = rtb_B_53_466_0 * _rtB->B_53_296_0;
rtb_B_53_466_0 = rtb_B_53_292_0 * rtb_B_53_466_0 * B_53_464_0 / rtb_B_53_293_0;
if (ssIsSampleHit(S, 2, 0)) {
    B_53_473_0 = _rtP->P_396 * _rtB->B_0_0_1[0];
    if (B_53_473_0 > _rtP->P_397) {
        B_53_473_0 = _rtP->P_397;
    } else {
        if (B_53_473_0 < _rtP->P_398) {
            B_53_473_0 = _rtP->P_398;
        }
    }
      
/* DiscreteStateSpace: '<S23>/Measurement filter (low pass)' */          {
                 B_53_474_0 = _rtP->P_401*_rtDW->Measurementfilterlowpass_DSTATE;
    B_53_474_0 += _rtP->P_402*_rtB->B_53_78_0;
  }

   
        
    B_53_476_0 = _rtB->B_53_475_0 - B_53_474_0;
      
/* Lookup: '<S23>/Torque - speed lookup table'
* About '<S23>/Torque - speed lookup table':
                * Input0  Data Type:  Floating Point real_T
               * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     * XData parameter uses the same data type and scaling as Input0
     * YData parameter uses the same data type and scaling as Output0
 */
                                  
  
  
  benchmark_no_taylor_acc_LookUp_real_T_real_T( &(B_53_477_0), _rtP->P_406, B_53_474_0, _rtP->P_405, 1229U);

        
    
    
   
        
    _rtB->B_53_485_0 = ((B_53_473_0 <= B_53_477_0 * B_53_474_0) || (B_53_474_0 >= _rtB->B_53_480_0) || (_rtDW->IntegerDelay_DSTATE > _rtB->B_53_483_0));




      benchmark_no_taylor_Pitchcontroller(S, _rtB->B_53_485_0, B_53_476_0, B_53_473_0, &_rtB->Pitchcontroller, &_rtDW->Pitchcontroller, (P_Pitchcontroller_benchmark_no_taylor_T *)&_rtP->Pitchcontroller);    if (_rtB->B_53_485_0) {
        rtb_B_53_488_0 = B_53_473_0 / B_53_474_0;
    } else {
        rtb_B_53_488_0 = B_53_477_0;
    }
    if (rtb_B_53_488_0 > _rtP->P_410) {
        rtb_B_53_488_0 = _rtP->P_410;
    } else {
        if (rtb_B_53_488_0 < _rtP->P_411) {
            rtb_B_53_488_0 = _rtP->P_411;
        }
    }
    rtb_B_53_292_0 = rtb_B_53_488_0 - _rtDW->PrevY;
    if (rtb_B_53_292_0 > _rtP->P_412) {
        rtb_B_53_488_0 = _rtDW->PrevY + _rtP->P_412;
    } else {
        if (rtb_B_53_292_0 < _rtP->P_413) {
            rtb_B_53_488_0 = _rtDW->PrevY + _rtP->P_413;
        }
    }
    _rtDW->PrevY = rtb_B_53_488_0;
    if (_rtB->B_53_470_0 > _rtP->P_420) {
        _rtB->B_53_501_0 = 0.0;
    } else {
        _rtB->B_53_501_0 = B_53_474_0 * rtb_B_53_488_0;
    }
}
_rtB->B_53_492_0 = rtb_B_53_293_0 - _rtP->P_415 * rtb_B_53_34_0;
rtb_B_53_292_0 = _rtP->P_416 * _rtB->B_53_492_0 + _rtB->B_53_431_0;
_rtB->B_53_497_0 = (_rtP->P_417 * rtb_B_53_292_0 - rtb_B_53_33_0) * _rtP->P_418;
_rtB->B_53_499_0 = (rtb_B_53_466_0 - rtb_B_53_292_0) * _rtP->P_419;
_rtB->B_53_504_0 = (_rtB->B_53_501_0 / rtb_B_53_34_0 - rtb_B_53_33_0) * _rtP->P_421;
      
/* TransportDelay: '<S34>/Hydraulic delay time' */
          {


      
    
    real_T **uBuffer = (real_T**)&_rtDW->Hydraulicdelaytime_PWORK.TUbufferPtrs[0];
    real_T **tBuffer = (real_T**)&_rtDW->Hydraulicdelaytime_PWORK.TUbufferPtrs[1];
    real_T simTime   = ssGetT(S);   
    
    
    real_T tMinusDelay = simTime - _rtP->P_422;
    
    
  
    
      
                     


          
        

      
      
        
        _rtB->B_53_505_0 = benchmark_no_taylor_acc_rt_TDelayInterpolate(
        tMinusDelay,
        0.0,
        *tBuffer,
        *uBuffer,
        _rtDW->Hydraulicdelaytime_IWORK.CircularBufSize,
        &_rtDW->Hydraulicdelaytime_IWORK.Last,
        _rtDW->Hydraulicdelaytime_IWORK.Tail,
        _rtDW->Hydraulicdelaytime_IWORK.Head,
        _rtP->P_423,
        1,
        (boolean_T) (ssIsMinorTimeStep(S) && (ssGetTimeOfLastOutput(S) == ssGetT(S))));  	    
      
      
  }
   
        
_rtB->B_53_506_0 = 0.0;
_rtB->B_53_506_0 += _rtP->P_425 * _rtX->Hydraulictimeconstant_CSTATE;
if (ssIsSampleHit(S, 2, 0)) {
    if (_rtB->B_53_470_0 > _rtP->P_426) {
        rtb_B_53_466_0 = 0.0;
    } else {
        rtb_B_53_466_0 = _rtB->Pitchcontroller.B_3_10_0;
    }
    _rtB->B_53_509_0 = (rtb_B_53_466_0 - rtb_B_53_90_0) * _rtP->P_427;
}
_rtB->B_53_510_0 = muDoubleScalarRound(B_53_114_0 / _rtP->P_428) * _rtP->P_428;
if (ssIsSampleHit(S, 3, 0)) {
    _rtB->B_53_515_0 = muDoubleScalarRound(_rtB->B_43_0_2 / _rtP->P_431) * _rtP->P_431;
}
_rtB->B_53_516_0 = muDoubleScalarRound(_rtX->genIntegrator_CSTATE / _rtP->P_432) * _rtP->P_432;
_rtB->B_53_517_0 = (rtb_B_53_34_0 - _rtX->genIntegrator_CSTATE) * _rtP->P_433;
_rtB->B_53_518_0 = (rtb_B_53_293_0 - _rtX->genIntegrator1_CSTATE) * _rtP->P_434;
_rtB->B_53_519_0 = muDoubleScalarRound(_rtX->genIntegrator1_CSTATE / _rtP->P_435) * _rtP->P_435;
      
/* Lookup2D: '<S45>/C_P table '
* About '<S45>/C_P table ':
                * Input0  Data Type:  Floating Point real_T
            * Input1  Data Type:  Floating Point real_T
               * Output0 Data Type:  Floating Point real_T
         * Saturation Mode: Saturate
     * Lookup Method: Linear_Endpoint
     *
     * Row Data    parameter uses the same data type and scaling as Input0
     * Column Data parameter uses the same data type and scaling as Input1
     * Table Data  parameter uses the same data type and scaling as Output0
 */
                                      
  
  
  benchmark_no_taylor_acc_Look2D_real_T_real_T_real_T_SAT( &(B_53_520_0), _rtP->P_438, B_53_401_0, _rtP->P_436, 450U, B_53_412_0, _rtP->P_437, 249U);


   
        
rtb_B_53_90_0 = rtb_B_53_409_0 * rtb_B_53_409_0 * _rtP->P_439;
_rtB->B_53_523_0 = rtb_B_53_90_0 * _rtB->B_53_413_0;
rtb_B_53_90_0 = rtb_B_53_409_0 * rtb_B_53_90_0 * B_53_520_0 / rtb_B_53_410_0;
if (ssIsSampleHit(S, 2, 0)) {
    B_53_529_0 = _rtP->P_441 * _rtB->B_0_0_1[9];
    if (B_53_529_0 > _rtP->P_442) {
        B_53_529_0 = _rtP->P_442;
    } else {
        if (B_53_529_0 < _rtP->P_443) {
            B_53_529_0 = _rtP->P_443;
        }
    }
      
/* DiscreteStateSpace: '<S39>/Measurement filter (low pass)' */          {
                 B_53_530_0 = _rtP->P_446*_rtDW->Measurementfilterlowpass_DSTATE_i;
    B_53_530_0 += _rtP->P_447*_rtB->B_53_87_0;
  }

   
        
    B_53_532_0 = _rtB->B_53_531_0 - B_53_530_0;
      
/* Lookup: '<S39>/Torque - speed lookup table'
* About '<S39>/Torque - speed lookup table':
                * Input0  Data Type:  Floating Point real_T
               * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     * XData parameter uses the same data type and scaling as Input0
     * YData parameter uses the same data type and scaling as Output0
 */
                                  
  
  
  benchmark_no_taylor_acc_LookUp_real_T_real_T( &(B_53_533_0), _rtP->P_451, B_53_530_0, _rtP->P_450, 1229U);

   
        
    _rtB->B_53_541_0 = ((B_53_529_0 <= B_53_533_0 * B_53_530_0) || (B_53_530_0 >= _rtB->B_53_536_0) || (_rtDW->IntegerDelay_DSTATE_i > _rtB->B_53_539_0));




      benchmark_no_taylor_Pitchcontroller(S, _rtB->B_53_541_0, B_53_532_0, B_53_529_0, &_rtB->Pitchcontroller_n, &_rtDW->Pitchcontroller_n, (P_Pitchcontroller_benchmark_no_taylor_T *)&_rtP->Pitchcontroller_n);    if (_rtB->B_53_541_0) {
        rtb_B_53_544_0 = B_53_529_0 / B_53_530_0;
    } else {
        rtb_B_53_544_0 = B_53_533_0;
    }
    if (rtb_B_53_544_0 > _rtP->P_455) {
        rtb_B_53_544_0 = _rtP->P_455;
    } else {
        if (rtb_B_53_544_0 < _rtP->P_456) {
            rtb_B_53_544_0 = _rtP->P_456;
        }
    }
    rtb_B_53_292_0 = rtb_B_53_544_0 - _rtDW->PrevY_k;
    if (rtb_B_53_292_0 > _rtP->P_457) {
        rtb_B_53_544_0 = _rtDW->PrevY_k + _rtP->P_457;
    } else {
        if (rtb_B_53_292_0 < _rtP->P_458) {
            rtb_B_53_544_0 = _rtDW->PrevY_k + _rtP->P_458;
        }
    }
    _rtDW->PrevY_k = rtb_B_53_544_0;
    if (_rtB->B_53_526_0 > _rtP->P_465) {
        _rtB->B_53_557_0 = 0.0;
    } else {
        _rtB->B_53_557_0 = B_53_530_0 * rtb_B_53_544_0;
    }
}
_rtB->B_53_548_0 = rtb_B_53_410_0 - _rtP->P_460 * rtb_B_53_70_0;
rtb_B_53_488_0 = _rtP->P_461 * _rtB->B_53_548_0 + _rtB->B_53_449_0;
_rtB->B_53_553_0 = (_rtP->P_462 * rtb_B_53_488_0 - rtb_B_53_69_0) * _rtP->P_463;
_rtB->B_53_555_0 = (rtb_B_53_90_0 - rtb_B_53_488_0) * _rtP->P_464;
_rtB->B_53_560_0 = (_rtB->B_53_557_0 / rtb_B_53_70_0 - rtb_B_53_69_0) * _rtP->P_466;
      
/* TransportDelay: '<S50>/Hydraulic delay time' */
          {


      
    
    real_T **uBuffer = (real_T**)&_rtDW->Hydraulicdelaytime_PWORK_f.TUbufferPtrs[0];
    real_T **tBuffer = (real_T**)&_rtDW->Hydraulicdelaytime_PWORK_f.TUbufferPtrs[1];
    real_T simTime   = ssGetT(S);   
    
    
    real_T tMinusDelay = simTime - _rtP->P_467;
    
    
  
    
      
                     


          
        

      
      
        
        _rtB->B_53_561_0 = benchmark_no_taylor_acc_rt_TDelayInterpolate(
        tMinusDelay,
        0.0,
        *tBuffer,
        *uBuffer,
        _rtDW->Hydraulicdelaytime_IWORK_m.CircularBufSize,
        &_rtDW->Hydraulicdelaytime_IWORK_m.Last,
        _rtDW->Hydraulicdelaytime_IWORK_m.Tail,
        _rtDW->Hydraulicdelaytime_IWORK_m.Head,
        _rtP->P_468,
        1,
        (boolean_T) (ssIsMinorTimeStep(S) && (ssGetTimeOfLastOutput(S) == ssGetT(S))));  	    
      
      
  }
   
        
_rtB->B_53_562_0 = 0.0;
_rtB->B_53_562_0 += _rtP->P_470 * _rtX->Hydraulictimeconstant_CSTATE_c;
if (ssIsSampleHit(S, 2, 0)) {
    if (_rtB->B_53_526_0 > _rtP->P_471) {
        rtb_B_53_466_0 = 0.0;
    } else {
        rtb_B_53_466_0 = _rtB->Pitchcontroller_n.B_3_10_0;
    }
    _rtB->B_53_565_0 = (rtb_B_53_466_0 - rtb_B_53_99_0) * _rtP->P_472;
}
_rtB->B_53_566_0 = muDoubleScalarRound(B_53_401_0 / _rtP->P_473) * _rtP->P_473;
if (ssIsSampleHit(S, 3, 0)) {
    _rtB->B_53_571_0 = muDoubleScalarRound(_rtB->B_44_0_2 / _rtP->P_476) * _rtP->P_476;
}
_rtB->B_53_572_0 = muDoubleScalarRound(_rtX->genIntegrator_CSTATE_e / _rtP->P_477) * _rtP->P_477;
_rtB->B_53_573_0 = (rtb_B_53_70_0 - _rtX->genIntegrator_CSTATE_e) * _rtP->P_478;
_rtB->B_53_574_0 = (rtb_B_53_410_0 - _rtX->genIntegrator1_CSTATE_d) * _rtP->P_479;
_rtB->B_53_575_0 = muDoubleScalarRound(_rtX->genIntegrator1_CSTATE_d / _rtP->P_480) * _rtP->P_480;
      
/* Lookup2D: '<S61>/C_P table '
* About '<S61>/C_P table ':
                * Input0  Data Type:  Floating Point real_T
            * Input1  Data Type:  Floating Point real_T
               * Output0 Data Type:  Floating Point real_T
         * Saturation Mode: Saturate
     * Lookup Method: Linear_Endpoint
     *
     * Row Data    parameter uses the same data type and scaling as Input0
     * Column Data parameter uses the same data type and scaling as Input1
     * Table Data  parameter uses the same data type and scaling as Output0
 */
                                      
  
  
  benchmark_no_taylor_acc_Look2D_real_T_real_T_real_T_SAT( &(B_53_576_0), _rtP->P_483, B_53_297_0, _rtP->P_481, 450U, B_53_308_0, _rtP->P_482, 249U);


   
        
rtb_B_53_99_0 = rtb_B_53_305_0 * rtb_B_53_305_0 * _rtP->P_484;
_rtB->B_53_579_0 = rtb_B_53_99_0 * _rtB->B_53_309_0;
rtb_B_53_99_0 = rtb_B_53_305_0 * rtb_B_53_99_0 * B_53_576_0 / rtb_B_53_306_0;
if (ssIsSampleHit(S, 2, 0)) {
    B_53_585_0 = _rtP->P_486 * _rtB->B_0_0_1[1];
    if (B_53_585_0 > _rtP->P_487) {
        B_53_585_0 = _rtP->P_487;
    } else {
        if (B_53_585_0 < _rtP->P_488) {
            B_53_585_0 = _rtP->P_488;
        }
    }
      
/* DiscreteStateSpace: '<S55>/Measurement filter (low pass)' */          {
                 B_53_586_0 = _rtP->P_491*_rtDW->Measurementfilterlowpass_DSTATE_j;
    B_53_586_0 += _rtP->P_492*_rtB->B_53_79_0;
  }

   
        
    B_53_588_0 = _rtB->B_53_587_0 - B_53_586_0;
      
/* Lookup: '<S55>/Torque - speed lookup table'
* About '<S55>/Torque - speed lookup table':
                * Input0  Data Type:  Floating Point real_T
               * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     * XData parameter uses the same data type and scaling as Input0
     * YData parameter uses the same data type and scaling as Output0
 */
                                  
  
  
  benchmark_no_taylor_acc_LookUp_real_T_real_T( &(B_53_589_0), _rtP->P_496, B_53_586_0, _rtP->P_495, 1229U);

   
        
    _rtB->B_53_597_0 = ((B_53_585_0 <= B_53_589_0 * B_53_586_0) || (B_53_586_0 >= _rtB->B_53_592_0) || (_rtDW->IntegerDelay_DSTATE_c > _rtB->B_53_595_0));




      benchmark_no_taylor_Pitchcontroller(S, _rtB->B_53_597_0, B_53_588_0, B_53_585_0, &_rtB->Pitchcontroller_a, &_rtDW->Pitchcontroller_a, (P_Pitchcontroller_benchmark_no_taylor_T *)&_rtP->Pitchcontroller_a);    if (_rtB->B_53_597_0) {
        rtb_B_53_600_0 = B_53_585_0 / B_53_586_0;
    } else {
        rtb_B_53_600_0 = B_53_589_0;
    }
    if (rtb_B_53_600_0 > _rtP->P_500) {
        rtb_B_53_600_0 = _rtP->P_500;
    } else {
        if (rtb_B_53_600_0 < _rtP->P_501) {
            rtb_B_53_600_0 = _rtP->P_501;
        }
    }
    rtb_B_53_292_0 = rtb_B_53_600_0 - _rtDW->PrevY_h;
    if (rtb_B_53_292_0 > _rtP->P_502) {
        rtb_B_53_600_0 = _rtDW->PrevY_h + _rtP->P_502;
    } else {
        if (rtb_B_53_292_0 < _rtP->P_503) {
            rtb_B_53_600_0 = _rtDW->PrevY_h + _rtP->P_503;
        }
    }
    _rtDW->PrevY_h = rtb_B_53_600_0;
    if (_rtB->B_53_582_0 > _rtP->P_510) {
        _rtB->B_53_613_0 = 0.0;
    } else {
        _rtB->B_53_613_0 = B_53_586_0 * rtb_B_53_600_0;
    }
}
_rtB->B_53_604_0 = rtb_B_53_306_0 - _rtP->P_505 * rtb_B_53_38_0;
rtb_B_53_544_0 = _rtP->P_506 * _rtB->B_53_604_0 + _rtB->B_53_433_0;
_rtB->B_53_609_0 = (_rtP->P_507 * rtb_B_53_544_0 - rtb_B_53_37_0) * _rtP->P_508;
_rtB->B_53_611_0 = (rtb_B_53_99_0 - rtb_B_53_544_0) * _rtP->P_509;
_rtB->B_53_616_0 = (_rtB->B_53_613_0 / rtb_B_53_38_0 - rtb_B_53_37_0) * _rtP->P_511;
      
/* TransportDelay: '<S66>/Hydraulic delay time' */
          {


      
    
    real_T **uBuffer = (real_T**)&_rtDW->Hydraulicdelaytime_PWORK_n.TUbufferPtrs[0];
    real_T **tBuffer = (real_T**)&_rtDW->Hydraulicdelaytime_PWORK_n.TUbufferPtrs[1];
    real_T simTime   = ssGetT(S);   
    
    
    real_T tMinusDelay = simTime - _rtP->P_512;
    
    
  
    
      
                     


          
        

      
      
        
        _rtB->B_53_617_0 = benchmark_no_taylor_acc_rt_TDelayInterpolate(
        tMinusDelay,
        0.0,
        *tBuffer,
        *uBuffer,
        _rtDW->Hydraulicdelaytime_IWORK_a.CircularBufSize,
        &_rtDW->Hydraulicdelaytime_IWORK_a.Last,
        _rtDW->Hydraulicdelaytime_IWORK_a.Tail,
        _rtDW->Hydraulicdelaytime_IWORK_a.Head,
        _rtP->P_513,
        1,
        (boolean_T) (ssIsMinorTimeStep(S) && (ssGetTimeOfLastOutput(S) == ssGetT(S))));  	    
      
      
  }
   
        
_rtB->B_53_618_0 = 0.0;
_rtB->B_53_618_0 += _rtP->P_515 * _rtX->Hydraulictimeconstant_CSTATE_d;
if (ssIsSampleHit(S, 2, 0)) {
    if (_rtB->B_53_582_0 > _rtP->P_516) {
        rtb_B_53_466_0 = 0.0;
    } else {
        rtb_B_53_466_0 = _rtB->Pitchcontroller_a.B_3_10_0;
    }
    _rtB->B_53_621_0 = (rtb_B_53_466_0 - rtb_B_53_91_0) * _rtP->P_517;
}
_rtB->B_53_622_0 = muDoubleScalarRound(B_53_297_0 / _rtP->P_518) * _rtP->P_518;
if (ssIsSampleHit(S, 3, 0)) {
    _rtB->B_53_627_0 = muDoubleScalarRound(_rtB->B_45_0_2 / _rtP->P_521) * _rtP->P_521;
}
_rtB->B_53_628_0 = muDoubleScalarRound(_rtX->genIntegrator_CSTATE_i / _rtP->P_522) * _rtP->P_522;
_rtB->B_53_629_0 = (rtb_B_53_38_0 - _rtX->genIntegrator_CSTATE_i) * _rtP->P_523;
_rtB->B_53_630_0 = (rtb_B_53_306_0 - _rtX->genIntegrator1_CSTATE_g) * _rtP->P_524;
_rtB->B_53_631_0 = muDoubleScalarRound(_rtX->genIntegrator1_CSTATE_g / _rtP->P_525) * _rtP->P_525;
      
/* Lookup2D: '<S77>/C_P table '
* About '<S77>/C_P table ':
                * Input0  Data Type:  Floating Point real_T
            * Input1  Data Type:  Floating Point real_T
               * Output0 Data Type:  Floating Point real_T
         * Saturation Mode: Saturate
     * Lookup Method: Linear_Endpoint
     *
     * Row Data    parameter uses the same data type and scaling as Input0
     * Column Data parameter uses the same data type and scaling as Input1
     * Table Data  parameter uses the same data type and scaling as Output0
 */
                                      
  
  
  benchmark_no_taylor_acc_Look2D_real_T_real_T_real_T_SAT( &(B_53_632_0), _rtP->P_528, B_53_310_0, _rtP->P_526, 450U, B_53_321_0, _rtP->P_527, 249U);


   
        
rtb_B_53_91_0 = rtb_B_53_318_0 * rtb_B_53_318_0 * _rtP->P_529;
_rtB->B_53_635_0 = rtb_B_53_91_0 * _rtB->B_53_322_0;
rtb_B_53_91_0 = rtb_B_53_318_0 * rtb_B_53_91_0 * B_53_632_0 / rtb_B_53_319_0;
if (ssIsSampleHit(S, 2, 0)) {
    B_53_641_0 = _rtP->P_531 * _rtB->B_0_0_1[2];
    if (B_53_641_0 > _rtP->P_532) {
        B_53_641_0 = _rtP->P_532;
    } else {
        if (B_53_641_0 < _rtP->P_533) {
            B_53_641_0 = _rtP->P_533;
        }
    }
      
/* DiscreteStateSpace: '<S71>/Measurement filter (low pass)' */          {
                 B_53_642_0 = _rtP->P_536*_rtDW->Measurementfilterlowpass_DSTATE_a;
    B_53_642_0 += _rtP->P_537*_rtB->B_53_80_0;
  }

   
        
    B_53_644_0 = _rtB->B_53_643_0 - B_53_642_0;
      
/* Lookup: '<S71>/Torque - speed lookup table'
* About '<S71>/Torque - speed lookup table':
                * Input0  Data Type:  Floating Point real_T
               * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     * XData parameter uses the same data type and scaling as Input0
     * YData parameter uses the same data type and scaling as Output0
 */
                                  
  
  
  benchmark_no_taylor_acc_LookUp_real_T_real_T( &(B_53_645_0), _rtP->P_541, B_53_642_0, _rtP->P_540, 1229U);

   
        
    _rtB->B_53_653_0 = ((B_53_641_0 <= B_53_645_0 * B_53_642_0) || (B_53_642_0 >= _rtB->B_53_648_0) || (_rtDW->IntegerDelay_DSTATE_f > _rtB->B_53_651_0));




      benchmark_no_taylor_Pitchcontroller(S, _rtB->B_53_653_0, B_53_644_0, B_53_641_0, &_rtB->Pitchcontroller_i, &_rtDW->Pitchcontroller_i, (P_Pitchcontroller_benchmark_no_taylor_T *)&_rtP->Pitchcontroller_i);    if (_rtB->B_53_653_0) {
        rtb_B_53_656_0 = B_53_641_0 / B_53_642_0;
    } else {
        rtb_B_53_656_0 = B_53_645_0;
    }
    if (rtb_B_53_656_0 > _rtP->P_545) {
        rtb_B_53_656_0 = _rtP->P_545;
    } else {
        if (rtb_B_53_656_0 < _rtP->P_546) {
            rtb_B_53_656_0 = _rtP->P_546;
        }
    }
    rtb_B_53_292_0 = rtb_B_53_656_0 - _rtDW->PrevY_i;
    if (rtb_B_53_292_0 > _rtP->P_547) {
        rtb_B_53_656_0 = _rtDW->PrevY_i + _rtP->P_547;
    } else {
        if (rtb_B_53_292_0 < _rtP->P_548) {
            rtb_B_53_656_0 = _rtDW->PrevY_i + _rtP->P_548;
        }
    }
    _rtDW->PrevY_i = rtb_B_53_656_0;
    if (_rtB->B_53_638_0 > _rtP->P_555) {
        _rtB->B_53_669_0 = 0.0;
    } else {
        _rtB->B_53_669_0 = B_53_642_0 * rtb_B_53_656_0;
    }
}
_rtB->B_53_660_0 = rtb_B_53_319_0 - _rtP->P_550 * rtb_B_53_42_0;
rtb_B_53_600_0 = _rtP->P_551 * _rtB->B_53_660_0 + _rtB->B_53_435_0;
_rtB->B_53_665_0 = (_rtP->P_552 * rtb_B_53_600_0 - rtb_B_53_41_0) * _rtP->P_553;
_rtB->B_53_667_0 = (rtb_B_53_91_0 - rtb_B_53_600_0) * _rtP->P_554;
_rtB->B_53_672_0 = (_rtB->B_53_669_0 / rtb_B_53_42_0 - rtb_B_53_41_0) * _rtP->P_556;
      
/* TransportDelay: '<S82>/Hydraulic delay time' */
          {


      
    
    real_T **uBuffer = (real_T**)&_rtDW->Hydraulicdelaytime_PWORK_m.TUbufferPtrs[0];
    real_T **tBuffer = (real_T**)&_rtDW->Hydraulicdelaytime_PWORK_m.TUbufferPtrs[1];
    real_T simTime   = ssGetT(S);   
    
    
    real_T tMinusDelay = simTime - _rtP->P_557;
    
    
  
    
      
                     


          
        

      
      
        
        _rtB->B_53_673_0 = benchmark_no_taylor_acc_rt_TDelayInterpolate(
        tMinusDelay,
        0.0,
        *tBuffer,
        *uBuffer,
        _rtDW->Hydraulicdelaytime_IWORK_c.CircularBufSize,
        &_rtDW->Hydraulicdelaytime_IWORK_c.Last,
        _rtDW->Hydraulicdelaytime_IWORK_c.Tail,
        _rtDW->Hydraulicdelaytime_IWORK_c.Head,
        _rtP->P_558,
        1,
        (boolean_T) (ssIsMinorTimeStep(S) && (ssGetTimeOfLastOutput(S) == ssGetT(S))));  	    
      
      
  }
   
        
_rtB->B_53_674_0 = 0.0;
_rtB->B_53_674_0 += _rtP->P_560 * _rtX->Hydraulictimeconstant_CSTATE_h;
if (ssIsSampleHit(S, 2, 0)) {
    if (_rtB->B_53_638_0 > _rtP->P_561) {
        rtb_B_53_466_0 = 0.0;
    } else {
        rtb_B_53_466_0 = _rtB->Pitchcontroller_i.B_3_10_0;
    }
    _rtB->B_53_677_0 = (rtb_B_53_466_0 - rtb_B_53_92_0) * _rtP->P_562;
}
_rtB->B_53_678_0 = muDoubleScalarRound(B_53_310_0 / _rtP->P_563) * _rtP->P_563;
if (ssIsSampleHit(S, 3, 0)) {
    _rtB->B_53_683_0 = muDoubleScalarRound(_rtB->B_46_0_2 / _rtP->P_566) * _rtP->P_566;
}
_rtB->B_53_684_0 = muDoubleScalarRound(_rtX->genIntegrator_CSTATE_j / _rtP->P_567) * _rtP->P_567;
_rtB->B_53_685_0 = (rtb_B_53_42_0 - _rtX->genIntegrator_CSTATE_j) * _rtP->P_568;
_rtB->B_53_686_0 = (rtb_B_53_319_0 - _rtX->genIntegrator1_CSTATE_f) * _rtP->P_569;
_rtB->B_53_687_0 = muDoubleScalarRound(_rtX->genIntegrator1_CSTATE_f / _rtP->P_570) * _rtP->P_570;
      
/* Lookup2D: '<S93>/C_P table '
* About '<S93>/C_P table ':
                * Input0  Data Type:  Floating Point real_T
            * Input1  Data Type:  Floating Point real_T
               * Output0 Data Type:  Floating Point real_T
         * Saturation Mode: Saturate
     * Lookup Method: Linear_Endpoint
     *
     * Row Data    parameter uses the same data type and scaling as Input0
     * Column Data parameter uses the same data type and scaling as Input1
     * Table Data  parameter uses the same data type and scaling as Output0
 */
                                      
  
  
  benchmark_no_taylor_acc_Look2D_real_T_real_T_real_T_SAT( &(B_53_688_0), _rtP->P_573, B_53_323_0, _rtP->P_571, 450U, B_53_334_0, _rtP->P_572, 249U);


   
        
rtb_B_53_92_0 = rtb_B_53_331_0 * rtb_B_53_331_0 * _rtP->P_574;
_rtB->B_53_691_0 = rtb_B_53_92_0 * _rtB->B_53_335_0;
rtb_B_53_92_0 = rtb_B_53_331_0 * rtb_B_53_92_0 * B_53_688_0 / rtb_B_53_332_0;
if (ssIsSampleHit(S, 2, 0)) {
    B_53_697_0 = _rtP->P_576 * _rtB->B_0_0_1[3];
    if (B_53_697_0 > _rtP->P_577) {
        B_53_697_0 = _rtP->P_577;
    } else {
        if (B_53_697_0 < _rtP->P_578) {
            B_53_697_0 = _rtP->P_578;
        }
    }
      
/* DiscreteStateSpace: '<S87>/Measurement filter (low pass)' */          {
                 B_53_698_0 = _rtP->P_581*_rtDW->Measurementfilterlowpass_DSTATE_e;
    B_53_698_0 += _rtP->P_582*_rtB->B_53_81_0;
  }

   
        
    B_53_700_0 = _rtB->B_53_699_0 - B_53_698_0;
      
/* Lookup: '<S87>/Torque - speed lookup table'
* About '<S87>/Torque - speed lookup table':
                * Input0  Data Type:  Floating Point real_T
               * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     * XData parameter uses the same data type and scaling as Input0
     * YData parameter uses the same data type and scaling as Output0
 */
                                  
  
  
  benchmark_no_taylor_acc_LookUp_real_T_real_T( &(B_53_701_0), _rtP->P_586, B_53_698_0, _rtP->P_585, 1229U);

   
        
    _rtB->B_53_709_0 = ((B_53_697_0 <= B_53_701_0 * B_53_698_0) || (B_53_698_0 >= _rtB->B_53_704_0) || (_rtDW->IntegerDelay_DSTATE_l > _rtB->B_53_707_0));




      benchmark_no_taylor_Pitchcontroller(S, _rtB->B_53_709_0, B_53_700_0, B_53_697_0, &_rtB->Pitchcontroller_e, &_rtDW->Pitchcontroller_e, (P_Pitchcontroller_benchmark_no_taylor_T *)&_rtP->Pitchcontroller_e);    if (_rtB->B_53_709_0) {
        rtb_B_53_712_0 = B_53_697_0 / B_53_698_0;
    } else {
        rtb_B_53_712_0 = B_53_701_0;
    }
    if (rtb_B_53_712_0 > _rtP->P_590) {
        rtb_B_53_712_0 = _rtP->P_590;
    } else {
        if (rtb_B_53_712_0 < _rtP->P_591) {
            rtb_B_53_712_0 = _rtP->P_591;
        }
    }
    rtb_B_53_292_0 = rtb_B_53_712_0 - _rtDW->PrevY_n;
    if (rtb_B_53_292_0 > _rtP->P_592) {
        rtb_B_53_712_0 = _rtDW->PrevY_n + _rtP->P_592;
    } else {
        if (rtb_B_53_292_0 < _rtP->P_593) {
            rtb_B_53_712_0 = _rtDW->PrevY_n + _rtP->P_593;
        }
    }
    _rtDW->PrevY_n = rtb_B_53_712_0;
    if (_rtB->B_53_694_0 > _rtP->P_600) {
        _rtB->B_53_725_0 = 0.0;
    } else {
        _rtB->B_53_725_0 = B_53_698_0 * rtb_B_53_712_0;
    }
}
_rtB->B_53_716_0 = rtb_B_53_332_0 - _rtP->P_595 * rtb_B_53_46_0;
rtb_B_53_656_0 = _rtP->P_596 * _rtB->B_53_716_0 + _rtB->B_53_437_0;
_rtB->B_53_721_0 = (_rtP->P_597 * rtb_B_53_656_0 - rtb_B_53_45_0) * _rtP->P_598;
_rtB->B_53_723_0 = (rtb_B_53_92_0 - rtb_B_53_656_0) * _rtP->P_599;
_rtB->B_53_728_0 = (_rtB->B_53_725_0 / rtb_B_53_46_0 - rtb_B_53_45_0) * _rtP->P_601;
      
/* TransportDelay: '<S98>/Hydraulic delay time' */
          {


      
    
    real_T **uBuffer = (real_T**)&_rtDW->Hydraulicdelaytime_PWORK_k.TUbufferPtrs[0];
    real_T **tBuffer = (real_T**)&_rtDW->Hydraulicdelaytime_PWORK_k.TUbufferPtrs[1];
    real_T simTime   = ssGetT(S);   
    
    
    real_T tMinusDelay = simTime - _rtP->P_602;
    
    
  
    
      
                     


          
        

      
      
        
        _rtB->B_53_729_0 = benchmark_no_taylor_acc_rt_TDelayInterpolate(
        tMinusDelay,
        0.0,
        *tBuffer,
        *uBuffer,
        _rtDW->Hydraulicdelaytime_IWORK_e.CircularBufSize,
        &_rtDW->Hydraulicdelaytime_IWORK_e.Last,
        _rtDW->Hydraulicdelaytime_IWORK_e.Tail,
        _rtDW->Hydraulicdelaytime_IWORK_e.Head,
        _rtP->P_603,
        1,
        (boolean_T) (ssIsMinorTimeStep(S) && (ssGetTimeOfLastOutput(S) == ssGetT(S))));  	    
      
      
  }
   
        
_rtB->B_53_730_0 = 0.0;
_rtB->B_53_730_0 += _rtP->P_605 * _rtX->Hydraulictimeconstant_CSTATE_g;
if (ssIsSampleHit(S, 2, 0)) {
    if (_rtB->B_53_694_0 > _rtP->P_606) {
        rtb_B_53_466_0 = 0.0;
    } else {
        rtb_B_53_466_0 = _rtB->Pitchcontroller_e.B_3_10_0;
    }
    _rtB->B_53_733_0 = (rtb_B_53_466_0 - rtb_B_53_93_0) * _rtP->P_607;
}
_rtB->B_53_734_0 = muDoubleScalarRound(B_53_323_0 / _rtP->P_608) * _rtP->P_608;
if (ssIsSampleHit(S, 3, 0)) {
    _rtB->B_53_739_0 = muDoubleScalarRound(_rtB->B_47_0_2 / _rtP->P_611) * _rtP->P_611;
}
_rtB->B_53_740_0 = muDoubleScalarRound(_rtX->genIntegrator_CSTATE_d / _rtP->P_612) * _rtP->P_612;
_rtB->B_53_741_0 = (rtb_B_53_46_0 - _rtX->genIntegrator_CSTATE_d) * _rtP->P_613;
_rtB->B_53_742_0 = (rtb_B_53_332_0 - _rtX->genIntegrator1_CSTATE_j) * _rtP->P_614;
_rtB->B_53_743_0 = muDoubleScalarRound(_rtX->genIntegrator1_CSTATE_j / _rtP->P_615) * _rtP->P_615;
      
/* Lookup2D: '<S109>/C_P table '
* About '<S109>/C_P table ':
                * Input0  Data Type:  Floating Point real_T
            * Input1  Data Type:  Floating Point real_T
               * Output0 Data Type:  Floating Point real_T
         * Saturation Mode: Saturate
     * Lookup Method: Linear_Endpoint
     *
     * Row Data    parameter uses the same data type and scaling as Input0
     * Column Data parameter uses the same data type and scaling as Input1
     * Table Data  parameter uses the same data type and scaling as Output0
 */
                                      
  
  
  benchmark_no_taylor_acc_Look2D_real_T_real_T_real_T_SAT( &(B_53_744_0), _rtP->P_618, B_53_336_0, _rtP->P_616, 450U, B_53_347_0, _rtP->P_617, 249U);


   
        
rtb_B_53_93_0 = rtb_B_53_344_0 * rtb_B_53_344_0 * _rtP->P_619;
_rtB->B_53_747_0 = rtb_B_53_93_0 * _rtB->B_53_348_0;
rtb_B_53_93_0 = rtb_B_53_344_0 * rtb_B_53_93_0 * B_53_744_0 / rtb_B_53_345_0;
if (ssIsSampleHit(S, 2, 0)) {
    B_53_753_0 = _rtP->P_621 * _rtB->B_0_0_1[4];
    if (B_53_753_0 > _rtP->P_622) {
        B_53_753_0 = _rtP->P_622;
    } else {
        if (B_53_753_0 < _rtP->P_623) {
            B_53_753_0 = _rtP->P_623;
        }
    }
      
/* DiscreteStateSpace: '<S103>/Measurement filter (low pass)' */          {
                 B_53_754_0 = _rtP->P_626*_rtDW->Measurementfilterlowpass_DSTATE_c;
    B_53_754_0 += _rtP->P_627*_rtB->B_53_82_0;
  }

   
        
    B_53_756_0 = _rtB->B_53_755_0 - B_53_754_0;
      
/* Lookup: '<S103>/Torque - speed lookup table'
* About '<S103>/Torque - speed lookup table':
                * Input0  Data Type:  Floating Point real_T
               * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     * XData parameter uses the same data type and scaling as Input0
     * YData parameter uses the same data type and scaling as Output0
 */
                                  
  
  
  benchmark_no_taylor_acc_LookUp_real_T_real_T( &(B_53_757_0), _rtP->P_631, B_53_754_0, _rtP->P_630, 1229U);

   
        
    _rtB->B_53_765_0 = ((B_53_753_0 <= B_53_757_0 * B_53_754_0) || (B_53_754_0 >= _rtB->B_53_760_0) || (_rtDW->IntegerDelay_DSTATE_j > _rtB->B_53_763_0));




      benchmark_no_taylor_Pitchcontroller(S, _rtB->B_53_765_0, B_53_756_0, B_53_753_0, &_rtB->Pitchcontroller_p, &_rtDW->Pitchcontroller_p, (P_Pitchcontroller_benchmark_no_taylor_T *)&_rtP->Pitchcontroller_p);    if (_rtB->B_53_765_0) {
        rtb_B_53_768_0 = B_53_753_0 / B_53_754_0;
    } else {
        rtb_B_53_768_0 = B_53_757_0;
    }
    if (rtb_B_53_768_0 > _rtP->P_635) {
        rtb_B_53_768_0 = _rtP->P_635;
    } else {
        if (rtb_B_53_768_0 < _rtP->P_636) {
            rtb_B_53_768_0 = _rtP->P_636;
        }
    }
    rtb_B_53_292_0 = rtb_B_53_768_0 - _rtDW->PrevY_f;
    if (rtb_B_53_292_0 > _rtP->P_637) {
        rtb_B_53_768_0 = _rtDW->PrevY_f + _rtP->P_637;
    } else {
        if (rtb_B_53_292_0 < _rtP->P_638) {
            rtb_B_53_768_0 = _rtDW->PrevY_f + _rtP->P_638;
        }
    }
    _rtDW->PrevY_f = rtb_B_53_768_0;
    if (_rtB->B_53_750_0 > _rtP->P_645) {
        _rtB->B_53_781_0 = 0.0;
    } else {
        _rtB->B_53_781_0 = B_53_754_0 * rtb_B_53_768_0;
    }
}
_rtB->B_53_772_0 = rtb_B_53_345_0 - _rtP->P_640 * rtb_B_53_50_0;
rtb_B_53_712_0 = _rtP->P_641 * _rtB->B_53_772_0 + _rtB->B_53_439_0;
_rtB->B_53_777_0 = (_rtP->P_642 * rtb_B_53_712_0 - rtb_B_53_49_0) * _rtP->P_643;
_rtB->B_53_779_0 = (rtb_B_53_93_0 - rtb_B_53_712_0) * _rtP->P_644;
_rtB->B_53_784_0 = (_rtB->B_53_781_0 / rtb_B_53_50_0 - rtb_B_53_49_0) * _rtP->P_646;
      
/* TransportDelay: '<S114>/Hydraulic delay time' */
          {


      
    
    real_T **uBuffer = (real_T**)&_rtDW->Hydraulicdelaytime_PWORK_m0.TUbufferPtrs[0];
    real_T **tBuffer = (real_T**)&_rtDW->Hydraulicdelaytime_PWORK_m0.TUbufferPtrs[1];
    real_T simTime   = ssGetT(S);   
    
    
    real_T tMinusDelay = simTime - _rtP->P_647;
    
    
  
    
      
                     


          
        

      
      
        
        _rtB->B_53_785_0 = benchmark_no_taylor_acc_rt_TDelayInterpolate(
        tMinusDelay,
        0.0,
        *tBuffer,
        *uBuffer,
        _rtDW->Hydraulicdelaytime_IWORK_o.CircularBufSize,
        &_rtDW->Hydraulicdelaytime_IWORK_o.Last,
        _rtDW->Hydraulicdelaytime_IWORK_o.Tail,
        _rtDW->Hydraulicdelaytime_IWORK_o.Head,
        _rtP->P_648,
        1,
        (boolean_T) (ssIsMinorTimeStep(S) && (ssGetTimeOfLastOutput(S) == ssGetT(S))));  	    
      
      
  }
   
        
_rtB->B_53_786_0 = 0.0;
_rtB->B_53_786_0 += _rtP->P_650 * _rtX->Hydraulictimeconstant_CSTATE_j;
if (ssIsSampleHit(S, 2, 0)) {
    if (_rtB->B_53_750_0 > _rtP->P_651) {
        rtb_B_53_466_0 = 0.0;
    } else {
        rtb_B_53_466_0 = _rtB->Pitchcontroller_p.B_3_10_0;
    }
    _rtB->B_53_789_0 = (rtb_B_53_466_0 - rtb_B_53_94_0) * _rtP->P_652;
}
_rtB->B_53_790_0 = muDoubleScalarRound(B_53_336_0 / _rtP->P_653) * _rtP->P_653;
if (ssIsSampleHit(S, 3, 0)) {
    _rtB->B_53_795_0 = muDoubleScalarRound(_rtB->B_48_0_2 / _rtP->P_656) * _rtP->P_656;
}
_rtB->B_53_796_0 = muDoubleScalarRound(_rtX->genIntegrator_CSTATE_a / _rtP->P_657) * _rtP->P_657;
_rtB->B_53_797_0 = (rtb_B_53_50_0 - _rtX->genIntegrator_CSTATE_a) * _rtP->P_658;
_rtB->B_53_798_0 = (rtb_B_53_345_0 - _rtX->genIntegrator1_CSTATE_p) * _rtP->P_659;
_rtB->B_53_799_0 = muDoubleScalarRound(_rtX->genIntegrator1_CSTATE_p / _rtP->P_660) * _rtP->P_660;
      
/* Lookup2D: '<S125>/C_P table '
* About '<S125>/C_P table ':
                * Input0  Data Type:  Floating Point real_T
            * Input1  Data Type:  Floating Point real_T
               * Output0 Data Type:  Floating Point real_T
         * Saturation Mode: Saturate
     * Lookup Method: Linear_Endpoint
     *
     * Row Data    parameter uses the same data type and scaling as Input0
     * Column Data parameter uses the same data type and scaling as Input1
     * Table Data  parameter uses the same data type and scaling as Output0
 */
                                      
  
  
  benchmark_no_taylor_acc_Look2D_real_T_real_T_real_T_SAT( &(B_53_800_0), _rtP->P_663, B_53_349_0, _rtP->P_661, 450U, B_53_360_0, _rtP->P_662, 249U);


   
        
rtb_B_53_94_0 = rtb_B_53_357_0 * rtb_B_53_357_0 * _rtP->P_664;
_rtB->B_53_803_0 = rtb_B_53_94_0 * _rtB->B_53_361_0;
rtb_B_53_94_0 = rtb_B_53_357_0 * rtb_B_53_94_0 * B_53_800_0 / rtb_B_53_358_0;
if (ssIsSampleHit(S, 2, 0)) {
    B_53_809_0 = _rtP->P_666 * _rtB->B_0_0_1[5];
    if (B_53_809_0 > _rtP->P_667) {
        B_53_809_0 = _rtP->P_667;
    } else {
        if (B_53_809_0 < _rtP->P_668) {
            B_53_809_0 = _rtP->P_668;
        }
    }
      
/* DiscreteStateSpace: '<S119>/Measurement filter (low pass)' */          {
                 B_53_810_0 = _rtP->P_671*_rtDW->Measurementfilterlowpass_DSTATE_ja;
    B_53_810_0 += _rtP->P_672*_rtB->B_53_83_0;
  }

   
        
    B_53_812_0 = _rtB->B_53_811_0 - B_53_810_0;
      
/* Lookup: '<S119>/Torque - speed lookup table'
* About '<S119>/Torque - speed lookup table':
                * Input0  Data Type:  Floating Point real_T
               * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     * XData parameter uses the same data type and scaling as Input0
     * YData parameter uses the same data type and scaling as Output0
 */
                                  
  
  
  benchmark_no_taylor_acc_LookUp_real_T_real_T( &(B_53_813_0), _rtP->P_676, B_53_810_0, _rtP->P_675, 1229U);

   
        
    _rtB->B_53_821_0 = ((B_53_809_0 <= B_53_813_0 * B_53_810_0) || (B_53_810_0 >= _rtB->B_53_816_0) || (_rtDW->IntegerDelay_DSTATE_n > _rtB->B_53_819_0));




      benchmark_no_taylor_Pitchcontroller(S, _rtB->B_53_821_0, B_53_812_0, B_53_809_0, &_rtB->Pitchcontroller_f, &_rtDW->Pitchcontroller_f, (P_Pitchcontroller_benchmark_no_taylor_T *)&_rtP->Pitchcontroller_f);    if (_rtB->B_53_821_0) {
        rtb_B_53_824_0 = B_53_809_0 / B_53_810_0;
    } else {
        rtb_B_53_824_0 = B_53_813_0;
    }
    if (rtb_B_53_824_0 > _rtP->P_680) {
        rtb_B_53_824_0 = _rtP->P_680;
    } else {
        if (rtb_B_53_824_0 < _rtP->P_681) {
            rtb_B_53_824_0 = _rtP->P_681;
        }
    }
    rtb_B_53_292_0 = rtb_B_53_824_0 - _rtDW->PrevY_j;
    if (rtb_B_53_292_0 > _rtP->P_682) {
        rtb_B_53_824_0 = _rtDW->PrevY_j + _rtP->P_682;
    } else {
        if (rtb_B_53_292_0 < _rtP->P_683) {
            rtb_B_53_824_0 = _rtDW->PrevY_j + _rtP->P_683;
        }
    }
    _rtDW->PrevY_j = rtb_B_53_824_0;
    if (_rtB->B_53_806_0 > _rtP->P_690) {
        _rtB->B_53_837_0 = 0.0;
    } else {
        _rtB->B_53_837_0 = B_53_810_0 * rtb_B_53_824_0;
    }
}
_rtB->B_53_828_0 = rtb_B_53_358_0 - _rtP->P_685 * rtb_B_53_54_0;
rtb_B_53_768_0 = _rtP->P_686 * _rtB->B_53_828_0 + _rtB->B_53_441_0;
_rtB->B_53_833_0 = (_rtP->P_687 * rtb_B_53_768_0 - rtb_B_53_53_0) * _rtP->P_688;
_rtB->B_53_835_0 = (rtb_B_53_94_0 - rtb_B_53_768_0) * _rtP->P_689;
_rtB->B_53_840_0 = (_rtB->B_53_837_0 / rtb_B_53_54_0 - rtb_B_53_53_0) * _rtP->P_691;
      
/* TransportDelay: '<S130>/Hydraulic delay time' */
          {


      
    
    real_T **uBuffer = (real_T**)&_rtDW->Hydraulicdelaytime_PWORK_fg.TUbufferPtrs[0];
    real_T **tBuffer = (real_T**)&_rtDW->Hydraulicdelaytime_PWORK_fg.TUbufferPtrs[1];
    real_T simTime   = ssGetT(S);   
    
    
    real_T tMinusDelay = simTime - _rtP->P_692;
    
    
  
    
      
                     


          
        

      
      
        
        _rtB->B_53_841_0 = benchmark_no_taylor_acc_rt_TDelayInterpolate(
        tMinusDelay,
        0.0,
        *tBuffer,
        *uBuffer,
        _rtDW->Hydraulicdelaytime_IWORK_n.CircularBufSize,
        &_rtDW->Hydraulicdelaytime_IWORK_n.Last,
        _rtDW->Hydraulicdelaytime_IWORK_n.Tail,
        _rtDW->Hydraulicdelaytime_IWORK_n.Head,
        _rtP->P_693,
        1,
        (boolean_T) (ssIsMinorTimeStep(S) && (ssGetTimeOfLastOutput(S) == ssGetT(S))));  	    
      
      
  }
   
        
_rtB->B_53_842_0 = 0.0;
_rtB->B_53_842_0 += _rtP->P_695 * _rtX->Hydraulictimeconstant_CSTATE_k;
if (ssIsSampleHit(S, 2, 0)) {
    if (_rtB->B_53_806_0 > _rtP->P_696) {
        rtb_B_53_466_0 = 0.0;
    } else {
        rtb_B_53_466_0 = _rtB->Pitchcontroller_f.B_3_10_0;
    }
    _rtB->B_53_845_0 = (rtb_B_53_466_0 - rtb_B_53_95_0) * _rtP->P_697;
}
_rtB->B_53_846_0 = muDoubleScalarRound(B_53_349_0 / _rtP->P_698) * _rtP->P_698;
if (ssIsSampleHit(S, 3, 0)) {
    _rtB->B_53_851_0 = muDoubleScalarRound(_rtB->B_49_0_2 / _rtP->P_701) * _rtP->P_701;
}
_rtB->B_53_852_0 = muDoubleScalarRound(_rtX->genIntegrator_CSTATE_m / _rtP->P_702) * _rtP->P_702;
_rtB->B_53_853_0 = (rtb_B_53_54_0 - _rtX->genIntegrator_CSTATE_m) * _rtP->P_703;
_rtB->B_53_854_0 = (rtb_B_53_358_0 - _rtX->genIntegrator1_CSTATE_m) * _rtP->P_704;
_rtB->B_53_855_0 = muDoubleScalarRound(_rtX->genIntegrator1_CSTATE_m / _rtP->P_705) * _rtP->P_705;
      
/* Lookup2D: '<S141>/C_P table '
* About '<S141>/C_P table ':
                * Input0  Data Type:  Floating Point real_T
            * Input1  Data Type:  Floating Point real_T
               * Output0 Data Type:  Floating Point real_T
         * Saturation Mode: Saturate
     * Lookup Method: Linear_Endpoint
     *
     * Row Data    parameter uses the same data type and scaling as Input0
     * Column Data parameter uses the same data type and scaling as Input1
     * Table Data  parameter uses the same data type and scaling as Output0
 */
                                      
  
  
  benchmark_no_taylor_acc_Look2D_real_T_real_T_real_T_SAT( &(B_53_856_0), _rtP->P_708, B_53_362_0, _rtP->P_706, 450U, B_53_373_0, _rtP->P_707, 249U);


   
        
rtb_B_53_95_0 = rtb_B_53_370_0 * rtb_B_53_370_0 * _rtP->P_709;
_rtB->B_53_859_0 = rtb_B_53_95_0 * _rtB->B_53_374_0;
rtb_B_53_95_0 = rtb_B_53_370_0 * rtb_B_53_95_0 * B_53_856_0 / rtb_B_53_371_0;
if (ssIsSampleHit(S, 2, 0)) {
    B_53_865_0 = _rtP->P_711 * _rtB->B_0_0_1[6];
    if (B_53_865_0 > _rtP->P_712) {
        B_53_865_0 = _rtP->P_712;
    } else {
        if (B_53_865_0 < _rtP->P_713) {
            B_53_865_0 = _rtP->P_713;
        }
    }
      
/* DiscreteStateSpace: '<S135>/Measurement filter (low pass)' */          {
                 B_53_866_0 = _rtP->P_716*_rtDW->Measurementfilterlowpass_DSTATE_aq;
    B_53_866_0 += _rtP->P_717*_rtB->B_53_84_0;
  }

   
        
    B_53_868_0 = _rtB->B_53_867_0 - B_53_866_0;
      
/* Lookup: '<S135>/Torque - speed lookup table'
* About '<S135>/Torque - speed lookup table':
                * Input0  Data Type:  Floating Point real_T
               * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     * XData parameter uses the same data type and scaling as Input0
     * YData parameter uses the same data type and scaling as Output0
 */
                                  
  
  
  benchmark_no_taylor_acc_LookUp_real_T_real_T( &(B_53_869_0), _rtP->P_721, B_53_866_0, _rtP->P_720, 1229U);

   
        
    _rtB->B_53_877_0 = ((B_53_865_0 <= B_53_869_0 * B_53_866_0) || (B_53_866_0 >= _rtB->B_53_872_0) || (_rtDW->IntegerDelay_DSTATE_e > _rtB->B_53_875_0));




      benchmark_no_taylor_Pitchcontroller(S, _rtB->B_53_877_0, B_53_868_0, B_53_865_0, &_rtB->Pitchcontroller_nb, &_rtDW->Pitchcontroller_nb, (P_Pitchcontroller_benchmark_no_taylor_T *)&_rtP->Pitchcontroller_nb);    if (_rtB->B_53_877_0) {
        rtb_B_53_880_0 = B_53_865_0 / B_53_866_0;
    } else {
        rtb_B_53_880_0 = B_53_869_0;
    }
    if (rtb_B_53_880_0 > _rtP->P_725) {
        rtb_B_53_880_0 = _rtP->P_725;
    } else {
        if (rtb_B_53_880_0 < _rtP->P_726) {
            rtb_B_53_880_0 = _rtP->P_726;
        }
    }
    rtb_B_53_292_0 = rtb_B_53_880_0 - _rtDW->PrevY_nx;
    if (rtb_B_53_292_0 > _rtP->P_727) {
        rtb_B_53_880_0 = _rtDW->PrevY_nx + _rtP->P_727;
    } else {
        if (rtb_B_53_292_0 < _rtP->P_728) {
            rtb_B_53_880_0 = _rtDW->PrevY_nx + _rtP->P_728;
        }
    }
    _rtDW->PrevY_nx = rtb_B_53_880_0;
    if (_rtB->B_53_862_0 > _rtP->P_735) {
        _rtB->B_53_893_0 = 0.0;
    } else {
        _rtB->B_53_893_0 = B_53_866_0 * rtb_B_53_880_0;
    }
}
_rtB->B_53_884_0 = rtb_B_53_371_0 - _rtP->P_730 * rtb_B_53_58_0;
rtb_B_53_824_0 = _rtP->P_731 * _rtB->B_53_884_0 + _rtB->B_53_443_0;
_rtB->B_53_889_0 = (_rtP->P_732 * rtb_B_53_824_0 - rtb_B_53_17_0) * _rtP->P_733;
_rtB->B_53_891_0 = (rtb_B_53_95_0 - rtb_B_53_824_0) * _rtP->P_734;
_rtB->B_53_896_0 = (_rtB->B_53_893_0 / rtb_B_53_58_0 - rtb_B_53_17_0) * _rtP->P_736;
      
/* TransportDelay: '<S146>/Hydraulic delay time' */
          {


      
    
    real_T **uBuffer = (real_T**)&_rtDW->Hydraulicdelaytime_PWORK_h.TUbufferPtrs[0];
    real_T **tBuffer = (real_T**)&_rtDW->Hydraulicdelaytime_PWORK_h.TUbufferPtrs[1];
    real_T simTime   = ssGetT(S);   
    
    
    real_T tMinusDelay = simTime - _rtP->P_737;
    
    
  
    
      
                     


          
        

      
      
        
        _rtB->B_53_897_0 = benchmark_no_taylor_acc_rt_TDelayInterpolate(
        tMinusDelay,
        0.0,
        *tBuffer,
        *uBuffer,
        _rtDW->Hydraulicdelaytime_IWORK_b.CircularBufSize,
        &_rtDW->Hydraulicdelaytime_IWORK_b.Last,
        _rtDW->Hydraulicdelaytime_IWORK_b.Tail,
        _rtDW->Hydraulicdelaytime_IWORK_b.Head,
        _rtP->P_738,
        1,
        (boolean_T) (ssIsMinorTimeStep(S) && (ssGetTimeOfLastOutput(S) == ssGetT(S))));  	    
      
      
  }
   
        
_rtB->B_53_898_0 = 0.0;
_rtB->B_53_898_0 += _rtP->P_740 * _rtX->Hydraulictimeconstant_CSTATE_f;
if (ssIsSampleHit(S, 2, 0)) {
    if (_rtB->B_53_862_0 > _rtP->P_741) {
        rtb_B_53_466_0 = 0.0;
    } else {
        rtb_B_53_466_0 = _rtB->Pitchcontroller_nb.B_3_10_0;
    }
    _rtB->B_53_901_0 = (rtb_B_53_466_0 - rtb_B_53_96_0) * _rtP->P_742;
}
_rtB->B_53_902_0 = muDoubleScalarRound(B_53_362_0 / _rtP->P_743) * _rtP->P_743;
if (ssIsSampleHit(S, 3, 0)) {
    _rtB->B_53_907_0 = muDoubleScalarRound(_rtB->B_50_0_2 / _rtP->P_746) * _rtP->P_746;
}
_rtB->B_53_908_0 = muDoubleScalarRound(_rtX->genIntegrator_CSTATE_ae / _rtP->P_747) * _rtP->P_747;
_rtB->B_53_909_0 = (rtb_B_53_58_0 - _rtX->genIntegrator_CSTATE_ae) * _rtP->P_748;
_rtB->B_53_910_0 = (rtb_B_53_371_0 - _rtX->genIntegrator1_CSTATE_h) * _rtP->P_749;
_rtB->B_53_911_0 = muDoubleScalarRound(_rtX->genIntegrator1_CSTATE_h / _rtP->P_750) * _rtP->P_750;
      
/* Lookup2D: '<S157>/C_P table '
* About '<S157>/C_P table ':
                * Input0  Data Type:  Floating Point real_T
            * Input1  Data Type:  Floating Point real_T
               * Output0 Data Type:  Floating Point real_T
         * Saturation Mode: Saturate
     * Lookup Method: Linear_Endpoint
     *
     * Row Data    parameter uses the same data type and scaling as Input0
     * Column Data parameter uses the same data type and scaling as Input1
     * Table Data  parameter uses the same data type and scaling as Output0
 */
                                      
  
  
  benchmark_no_taylor_acc_Look2D_real_T_real_T_real_T_SAT( &(B_53_912_0), _rtP->P_753, B_53_375_0, _rtP->P_751, 450U, B_53_386_0, _rtP->P_752, 249U);


   
        
rtb_B_53_96_0 = rtb_B_53_15_0 * rtb_B_53_15_0 * _rtP->P_754;
_rtB->B_53_915_0 = rtb_B_53_96_0 * _rtB->B_53_387_0;
rtb_B_53_96_0 = rtb_B_53_15_0 * rtb_B_53_96_0 * B_53_912_0 / rtb_B_53_13_0;
if (ssIsSampleHit(S, 2, 0)) {
    B_53_921_0 = _rtP->P_756 * _rtB->B_0_0_1[7];
    if (B_53_921_0 > _rtP->P_757) {
        B_53_921_0 = _rtP->P_757;
    } else {
        if (B_53_921_0 < _rtP->P_758) {
            B_53_921_0 = _rtP->P_758;
        }
    }
      
/* DiscreteStateSpace: '<S151>/Measurement filter (low pass)' */          {
                 B_53_922_0 = _rtP->P_761*_rtDW->Measurementfilterlowpass_DSTATE_k;
    B_53_922_0 += _rtP->P_762*_rtB->B_53_85_0;
  }

   
        
    B_53_924_0 = _rtB->B_53_923_0 - B_53_922_0;
      
/* Lookup: '<S151>/Torque - speed lookup table'
* About '<S151>/Torque - speed lookup table':
                * Input0  Data Type:  Floating Point real_T
               * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     * XData parameter uses the same data type and scaling as Input0
     * YData parameter uses the same data type and scaling as Output0
 */
                                  
  
  
  benchmark_no_taylor_acc_LookUp_real_T_real_T( &(B_53_925_0), _rtP->P_766, B_53_922_0, _rtP->P_765, 1229U);

   
        
    _rtB->B_53_933_0 = ((B_53_921_0 <= B_53_925_0 * B_53_922_0) || (B_53_922_0 >= _rtB->B_53_928_0) || (_rtDW->IntegerDelay_DSTATE_id > _rtB->B_53_931_0));




      benchmark_no_taylor_Pitchcontroller(S, _rtB->B_53_933_0, B_53_924_0, B_53_921_0, &_rtB->Pitchcontroller_a2, &_rtDW->Pitchcontroller_a2, (P_Pitchcontroller_benchmark_no_taylor_T *)&_rtP->Pitchcontroller_a2);    if (_rtB->B_53_933_0) {
        rtb_B_53_936_0 = B_53_921_0 / B_53_922_0;
    } else {
        rtb_B_53_936_0 = B_53_925_0;
    }
    if (rtb_B_53_936_0 > _rtP->P_770) {
        rtb_B_53_936_0 = _rtP->P_770;
    } else {
        if (rtb_B_53_936_0 < _rtP->P_771) {
            rtb_B_53_936_0 = _rtP->P_771;
        }
    }
    rtb_B_53_292_0 = rtb_B_53_936_0 - _rtDW->PrevY_h5;
    if (rtb_B_53_292_0 > _rtP->P_772) {
        rtb_B_53_936_0 = _rtDW->PrevY_h5 + _rtP->P_772;
    } else {
        if (rtb_B_53_292_0 < _rtP->P_773) {
            rtb_B_53_936_0 = _rtDW->PrevY_h5 + _rtP->P_773;
        }
    }
    _rtDW->PrevY_h5 = rtb_B_53_936_0;
    if (_rtB->B_53_918_0 > _rtP->P_780) {
        _rtB->B_53_949_0 = 0.0;
    } else {
        _rtB->B_53_949_0 = B_53_922_0 * rtb_B_53_936_0;
    }
}
_rtB->B_53_940_0 = rtb_B_53_13_0 - _rtP->P_775 * rtb_B_53_11_0;
rtb_B_53_880_0 = _rtP->P_776 * _rtB->B_53_940_0 + _rtB->B_53_445_0;
_rtB->B_53_945_0 = (_rtP->P_777 * rtb_B_53_880_0 - rtb_B_53_9_0) * _rtP->P_778;
_rtB->B_53_947_0 = (rtb_B_53_96_0 - rtb_B_53_880_0) * _rtP->P_779;
_rtB->B_53_952_0 = (_rtB->B_53_949_0 / rtb_B_53_11_0 - rtb_B_53_9_0) * _rtP->P_781;
      
/* TransportDelay: '<S162>/Hydraulic delay time' */
          {


      
    
    real_T **uBuffer = (real_T**)&_rtDW->Hydraulicdelaytime_PWORK_d.TUbufferPtrs[0];
    real_T **tBuffer = (real_T**)&_rtDW->Hydraulicdelaytime_PWORK_d.TUbufferPtrs[1];
    real_T simTime   = ssGetT(S);   
    
    
    real_T tMinusDelay = simTime - _rtP->P_782;
    
    
  
    
      
                     


          
        

      
      
        
        _rtB->B_53_953_0 = benchmark_no_taylor_acc_rt_TDelayInterpolate(
        tMinusDelay,
        0.0,
        *tBuffer,
        *uBuffer,
        _rtDW->Hydraulicdelaytime_IWORK_h.CircularBufSize,
        &_rtDW->Hydraulicdelaytime_IWORK_h.Last,
        _rtDW->Hydraulicdelaytime_IWORK_h.Tail,
        _rtDW->Hydraulicdelaytime_IWORK_h.Head,
        _rtP->P_783,
        1,
        (boolean_T) (ssIsMinorTimeStep(S) && (ssGetTimeOfLastOutput(S) == ssGetT(S))));  	    
      
      
  }
   
        
_rtB->B_53_954_0 = 0.0;
_rtB->B_53_954_0 += _rtP->P_785 * _rtX->Hydraulictimeconstant_CSTATE_m;
if (ssIsSampleHit(S, 2, 0)) {
    if (_rtB->B_53_918_0 > _rtP->P_786) {
        rtb_B_53_466_0 = 0.0;
    } else {
        rtb_B_53_466_0 = _rtB->Pitchcontroller_a2.B_3_10_0;
    }
    _rtB->B_53_957_0 = (rtb_B_53_466_0 - rtb_B_53_97_0) * _rtP->P_787;
}
_rtB->B_53_958_0 = muDoubleScalarRound(B_53_375_0 / _rtP->P_788) * _rtP->P_788;
if (ssIsSampleHit(S, 3, 0)) {
    _rtB->B_53_963_0 = muDoubleScalarRound(_rtB->B_51_0_2 / _rtP->P_791) * _rtP->P_791;
}
_rtB->B_53_964_0 = muDoubleScalarRound(_rtX->genIntegrator_CSTATE_ju / _rtP->P_792) * _rtP->P_792;
_rtB->B_53_965_0 = (rtb_B_53_11_0 - _rtX->genIntegrator_CSTATE_ju) * _rtP->P_793;
_rtB->B_53_966_0 = (rtb_B_53_13_0 - _rtX->genIntegrator1_CSTATE_o) * _rtP->P_794;
_rtB->B_53_967_0 = muDoubleScalarRound(_rtX->genIntegrator1_CSTATE_o / _rtP->P_795) * _rtP->P_795;
      
/* Lookup2D: '<S173>/C_P table '
* About '<S173>/C_P table ':
                * Input0  Data Type:  Floating Point real_T
            * Input1  Data Type:  Floating Point real_T
               * Output0 Data Type:  Floating Point real_T
         * Saturation Mode: Saturate
     * Lookup Method: Linear_Endpoint
     *
     * Row Data    parameter uses the same data type and scaling as Input0
     * Column Data parameter uses the same data type and scaling as Input1
     * Table Data  parameter uses the same data type and scaling as Output0
 */
                                      
  
  
  benchmark_no_taylor_acc_Look2D_real_T_real_T_real_T_SAT( &(B_53_968_0), _rtP->P_798, B_53_388_0, _rtP->P_796, 450U, B_53_399_0, _rtP->P_797, 249U);


   
        
rtb_B_53_97_0 = rtb_B_53_7_0 * rtb_B_53_7_0 * _rtP->P_799;
_rtB->B_53_971_0 = rtb_B_53_97_0 * _rtB->B_53_400_0;
rtb_B_53_97_0 = rtb_B_53_7_0 * rtb_B_53_97_0 * B_53_968_0 / rtb_B_53_5_0;
if (ssIsSampleHit(S, 2, 0)) {
    B_53_977_0 = _rtP->P_801 * _rtB->B_0_0_1[8];
    if (B_53_977_0 > _rtP->P_802) {
        B_53_977_0 = _rtP->P_802;
    } else {
        if (B_53_977_0 < _rtP->P_803) {
            B_53_977_0 = _rtP->P_803;
        }
    }
      
/* DiscreteStateSpace: '<S167>/Measurement filter (low pass)' */          {
                 B_53_978_0 = _rtP->P_806*_rtDW->Measurementfilterlowpass_DSTATE_k1;
    B_53_978_0 += _rtP->P_807*_rtB->B_53_86_0;
  }

   
        
    B_53_980_0 = _rtB->B_53_979_0 - B_53_978_0;
      
/* Lookup: '<S167>/Torque - speed lookup table'
* About '<S167>/Torque - speed lookup table':
                * Input0  Data Type:  Floating Point real_T
               * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     * XData parameter uses the same data type and scaling as Input0
     * YData parameter uses the same data type and scaling as Output0
 */
                                  
  
  
  benchmark_no_taylor_acc_LookUp_real_T_real_T( &(B_53_981_0), _rtP->P_811, B_53_978_0, _rtP->P_810, 1229U);

   
        
    _rtB->B_53_989_0 = ((B_53_977_0 <= B_53_981_0 * B_53_978_0) || (B_53_978_0 >= _rtB->B_53_984_0) || (_rtDW->IntegerDelay_DSTATE_fg > _rtB->B_53_987_0));




      benchmark_no_taylor_Pitchcontroller(S, _rtB->B_53_989_0, B_53_980_0, B_53_977_0, &_rtB->Pitchcontroller_c, &_rtDW->Pitchcontroller_c, (P_Pitchcontroller_benchmark_no_taylor_T *)&_rtP->Pitchcontroller_c);    if (_rtB->B_53_989_0) {
        rtb_B_53_992_0 = B_53_977_0 / B_53_978_0;
    } else {
        rtb_B_53_992_0 = B_53_981_0;
    }
    if (rtb_B_53_992_0 > _rtP->P_815) {
        rtb_B_53_992_0 = _rtP->P_815;
    } else {
        if (rtb_B_53_992_0 < _rtP->P_816) {
            rtb_B_53_992_0 = _rtP->P_816;
        }
    }
    rtb_B_53_292_0 = rtb_B_53_992_0 - _rtDW->PrevY_m;
    if (rtb_B_53_292_0 > _rtP->P_817) {
        rtb_B_53_992_0 = _rtDW->PrevY_m + _rtP->P_817;
    } else {
        if (rtb_B_53_292_0 < _rtP->P_818) {
            rtb_B_53_992_0 = _rtDW->PrevY_m + _rtP->P_818;
        }
    }
    _rtDW->PrevY_m = rtb_B_53_992_0;
    if (_rtB->B_53_974_0 > _rtP->P_825) {
        _rtB->B_53_1005_0 = 0.0;
    } else {
        _rtB->B_53_1005_0 = B_53_978_0 * rtb_B_53_992_0;
    }
}
_rtB->B_53_996_0 = rtb_B_53_5_0 - _rtP->P_820 * rtb_B_53_3_0;
rtb_B_53_936_0 = _rtP->P_821 * _rtB->B_53_996_0 + _rtB->B_53_447_0;
_rtB->B_53_1001_0 = (_rtP->P_822 * rtb_B_53_936_0 - rtb_B_53_1_0) * _rtP->P_823;
_rtB->B_53_1003_0 = (rtb_B_53_97_0 - rtb_B_53_936_0) * _rtP->P_824;
_rtB->B_53_1008_0 = (_rtB->B_53_1005_0 / rtb_B_53_3_0 - rtb_B_53_1_0) * _rtP->P_826;
      
/* TransportDelay: '<S178>/Hydraulic delay time' */
          {


      
    
    real_T **uBuffer = (real_T**)&_rtDW->Hydraulicdelaytime_PWORK_a.TUbufferPtrs[0];
    real_T **tBuffer = (real_T**)&_rtDW->Hydraulicdelaytime_PWORK_a.TUbufferPtrs[1];
    real_T simTime   = ssGetT(S);   
    
    
    real_T tMinusDelay = simTime - _rtP->P_827;
    
    
  
    
      
                     


          
        

      
      
        
        _rtB->B_53_1009_0 = benchmark_no_taylor_acc_rt_TDelayInterpolate(
        tMinusDelay,
        0.0,
        *tBuffer,
        *uBuffer,
        _rtDW->Hydraulicdelaytime_IWORK_mc.CircularBufSize,
        &_rtDW->Hydraulicdelaytime_IWORK_mc.Last,
        _rtDW->Hydraulicdelaytime_IWORK_mc.Tail,
        _rtDW->Hydraulicdelaytime_IWORK_mc.Head,
        _rtP->P_828,
        1,
        (boolean_T) (ssIsMinorTimeStep(S) && (ssGetTimeOfLastOutput(S) == ssGetT(S))));  	    
      
      
  }
   
        
_rtB->B_53_1010_0 = 0.0;
_rtB->B_53_1010_0 += _rtP->P_830 * _rtX->Hydraulictimeconstant_CSTATE_e;
if (ssIsSampleHit(S, 2, 0)) {
    if (_rtB->B_53_974_0 > _rtP->P_831) {
        rtb_B_53_466_0 = 0.0;
    } else {
        rtb_B_53_466_0 = _rtB->Pitchcontroller_c.B_3_10_0;
    }
    _rtB->B_53_1013_0 = (rtb_B_53_466_0 - rtb_B_53_98_0) * _rtP->P_832;
}
_rtB->B_53_1014_0 = muDoubleScalarRound(B_53_388_0 / _rtP->P_833) * _rtP->P_833;
_rtB->B_53_1020_0 = muDoubleScalarRound(_rtX->genIntegrator_CSTATE_mc / _rtP->P_837) * _rtP->P_837;
_rtB->B_53_1021_0 = (rtb_B_53_3_0 - _rtX->genIntegrator_CSTATE_mc) * _rtP->P_838;
_rtB->B_53_1022_0 = (rtb_B_53_5_0 - _rtX->genIntegrator1_CSTATE_gl) * _rtP->P_839;
_rtB->B_53_1023_0 = muDoubleScalarRound(_rtX->genIntegrator1_CSTATE_gl / _rtP->P_840) * _rtP->P_840;
if (ssIsSampleHit(S, 3, 0)) {
    _rtB->B_53_1019_0 = muDoubleScalarRound(_rtB->B_52_0_2 / _rtP->P_836) * _rtP->P_836;
      
/* ToWorkspace: '<S7>/B_44_124' */            /* Call into Simulink for To Workspace */
    ssCallAccelRunBlock(S, 53, 1024, SS_CALL_MDL_OUTPUTS);


   
        
      
/* ToWorkspace: '<S7>/B_44_125' */            /* Call into Simulink for To Workspace */
    ssCallAccelRunBlock(S, 53, 1025, SS_CALL_MDL_OUTPUTS);


   
        
      
/* ToWorkspace: '<S7>/B_44_126' */            /* Call into Simulink for To Workspace */
    ssCallAccelRunBlock(S, 53, 1026, SS_CALL_MDL_OUTPUTS);


   
        
      
/* ToWorkspace: '<S7>/B_44_127' */            /* Call into Simulink for To Workspace */
    ssCallAccelRunBlock(S, 53, 1027, SS_CALL_MDL_OUTPUTS);


   
        
    _rtB->B_53_1032_0 = _rtDW->Output_DSTATE_ej + _rtB->B_53_1028_0;
    if (_rtB->B_53_1032_0 > _rtP->P_992) {
        _rtB->B_53_1032_0 = _rtB->B_53_1031_0;
    }
    for (i = 0; i < 10; i++) {
        for (i_0 = 0; i_0 < 200; i_0++) {
            _rtB->B_53_1036_0[i_0 + 200 * i] = _rtB->B_53_1033_0[((int32_T)(_rtB->B_53_1034_0[i] + (real_T)_rtDW->Output_DSTATE_ej) - 1) * 200 + i_0];
        }
    }
    memcpy(&_rtB->B_53_1037_0[0], &_rtB->B_53_1036_0[0], 200U * sizeof(real_T));
                      
          /* Level2 S-Function Block: '<S206>/B_24_0' (stateflow) */
          /* Call into Simulink for MEX-version of S-function */
          ssCallAccelRunBlock(S, 33, 0, SS_CALL_MDL_OUTPUTS);

   
        
    memcpy(&_rtB->B_53_1039_0[0], &_rtB->B_53_1036_0[1800], 200U * sizeof(real_T));
                      
          /* Level2 S-Function Block: '<S207>/B_25_0' (stateflow) */
          /* Call into Simulink for MEX-version of S-function */
          ssCallAccelRunBlock(S, 34, 0, SS_CALL_MDL_OUTPUTS);

   
        
    memcpy(&_rtB->B_53_1041_0[0], &_rtB->B_53_1036_0[200], 200U * sizeof(real_T));
                      
          /* Level2 S-Function Block: '<S208>/B_26_0' (stateflow) */
          /* Call into Simulink for MEX-version of S-function */
          ssCallAccelRunBlock(S, 35, 0, SS_CALL_MDL_OUTPUTS);

   
        
    memcpy(&_rtB->B_53_1043_0[0], &_rtB->B_53_1036_0[400], 200U * sizeof(real_T));
                      
          /* Level2 S-Function Block: '<S209>/B_27_0' (stateflow) */
          /* Call into Simulink for MEX-version of S-function */
          ssCallAccelRunBlock(S, 36, 0, SS_CALL_MDL_OUTPUTS);

   
        
    memcpy(&_rtB->B_53_1045_0[0], &_rtB->B_53_1036_0[600], 200U * sizeof(real_T));
                      
          /* Level2 S-Function Block: '<S210>/B_28_0' (stateflow) */
          /* Call into Simulink for MEX-version of S-function */
          ssCallAccelRunBlock(S, 37, 0, SS_CALL_MDL_OUTPUTS);

   
        
    memcpy(&_rtB->B_53_1047_0[0], &_rtB->B_53_1036_0[800], 200U * sizeof(real_T));
                      
          /* Level2 S-Function Block: '<S211>/B_29_0' (stateflow) */
          /* Call into Simulink for MEX-version of S-function */
          ssCallAccelRunBlock(S, 38, 0, SS_CALL_MDL_OUTPUTS);

   
        
    memcpy(&_rtB->B_53_1049_0[0], &_rtB->B_53_1036_0[1000], 200U * sizeof(real_T));
                      
          /* Level2 S-Function Block: '<S212>/B_30_0' (stateflow) */
          /* Call into Simulink for MEX-version of S-function */
          ssCallAccelRunBlock(S, 39, 0, SS_CALL_MDL_OUTPUTS);

   
        
    memcpy(&_rtB->B_53_1051_0[0], &_rtB->B_53_1036_0[1200], 200U * sizeof(real_T));
                      
          /* Level2 S-Function Block: '<S213>/B_31_0' (stateflow) */
          /* Call into Simulink for MEX-version of S-function */
          ssCallAccelRunBlock(S, 40, 0, SS_CALL_MDL_OUTPUTS);

   
        
    memcpy(&_rtB->B_53_1053_0[0], &_rtB->B_53_1036_0[1400], 200U * sizeof(real_T));
                      
          /* Level2 S-Function Block: '<S214>/B_32_0' (stateflow) */
          /* Call into Simulink for MEX-version of S-function */
          ssCallAccelRunBlock(S, 41, 0, SS_CALL_MDL_OUTPUTS);

   
        
    memcpy(&_rtB->B_53_1055_0[0], &_rtB->B_53_1036_0[1600], 200U * sizeof(real_T));
                      
          /* Level2 S-Function Block: '<S215>/B_33_0' (stateflow) */
          /* Call into Simulink for MEX-version of S-function */
          ssCallAccelRunBlock(S, 42, 0, SS_CALL_MDL_OUTPUTS);

   
        
    _rtB->B_53_1060_0 = rtb_B_53_116_0 + _rtB->B_53_1057_0;
    if (_rtB->B_53_1060_0 > _rtP->P_995) {
        _rtB->B_53_1060_0 = _rtB->B_53_1059_0;
    }
    _rtB->B_53_1064_0 = rtb_B_53_403_0 + _rtB->B_53_1061_0;
    if (_rtB->B_53_1064_0 > _rtP->P_998) {
        _rtB->B_53_1064_0 = _rtB->B_53_1063_0;
    }
    _rtB->B_53_1068_0 = rtb_B_53_299_0 + _rtB->B_53_1065_0;
    if (_rtB->B_53_1068_0 > _rtP->P_1001) {
        _rtB->B_53_1068_0 = _rtB->B_53_1067_0;
    }
    _rtB->B_53_1072_0 = rtb_B_53_312_0 + _rtB->B_53_1069_0;
    if (_rtB->B_53_1072_0 > _rtP->P_1004) {
        _rtB->B_53_1072_0 = _rtB->B_53_1071_0;
    }
    _rtB->B_53_1076_0 = rtb_B_53_325_0 + _rtB->B_53_1073_0;
    if (_rtB->B_53_1076_0 > _rtP->P_1007) {
        _rtB->B_53_1076_0 = _rtB->B_53_1075_0;
    }
    _rtB->B_53_1080_0 = rtb_B_53_338_0 + _rtB->B_53_1077_0;
    if (_rtB->B_53_1080_0 > _rtP->P_1010) {
        _rtB->B_53_1080_0 = _rtB->B_53_1079_0;
    }
    _rtB->B_53_1084_0 = rtb_B_53_351_0 + _rtB->B_53_1081_0;
    if (_rtB->B_53_1084_0 > _rtP->P_1013) {
        _rtB->B_53_1084_0 = _rtB->B_53_1083_0;
    }
    _rtB->B_53_1088_0 = rtb_B_53_364_0 + _rtB->B_53_1085_0;
    if (_rtB->B_53_1088_0 > _rtP->P_1016) {
        _rtB->B_53_1088_0 = _rtB->B_53_1087_0;
    }
    _rtB->B_53_1092_0 = rtb_B_53_377_0 + _rtB->B_53_1089_0;
    if (_rtB->B_53_1092_0 > _rtP->P_1019) {
        _rtB->B_53_1092_0 = _rtB->B_53_1091_0;
    }
    _rtB->B_53_1096_0 = rtb_B_53_390_0 + _rtB->B_53_1093_0;
    if (_rtB->B_53_1096_0 > _rtP->P_1022) {
        _rtB->B_53_1096_0 = _rtB->B_53_1095_0;
    }
}
_rtB->B_53_1097_0 = ssGetT(S);
ssCallAccelRunBlock(S, 53, 1098, SS_CALL_MDL_OUTPUTS);








    
  

                  UNUSED_PARAMETER(tid);



  
    
        }
    
  





    
  

          /* Outputs for root system: '<Root>' */
            
  
       static  void mdlOutputsTID6(SimStruct *S, int_T tid)
  {
  
                
    B_benchmark_no_taylor_T *_rtB;
P_benchmark_no_taylor_T *_rtP;

    
  

            
  
    
  
    
  


                          _rtP = ((P_benchmark_no_taylor_T *) ssGetModelRtp(S));
_rtB = ((B_benchmark_no_taylor_T *) _ssGetModelBlockIO(S));
_rtB->B_53_102_0 = _rtP->P_78;
_rtB->B_53_103_0 = _rtP->P_79;
_rtB->B_53_104_0 = _rtP->P_80;
_rtB->B_53_105_0 = _rtP->P_81;
_rtB->B_53_106_0 = _rtP->P_82;
_rtB->B_53_107_0 = _rtP->P_83;
_rtB->B_53_108_0 = _rtP->P_84;
_rtB->B_53_109_0 = _rtP->P_85;
_rtB->B_53_110_0 = _rtP->P_86;
_rtB->B_53_111_0 = _rtP->P_87;
_rtB->B_53_118_0 = _rtP->P_90;
_rtB->B_53_129_0 = _rtP->P_100;
_rtB->B_53_137_0 = _rtP->P_107;
_rtB->B_53_142_0 = _rtP->P_111;
_rtB->B_53_144_0 = _rtP->P_112;
_rtB->B_53_154_0 = _rtP->P_121;
_rtB->B_53_161_0 = _rtP->P_127;
_rtB->B_53_165_0 = _rtP->P_130;
_rtB->B_53_173_0 = _rtP->P_137;
_rtB->B_53_178_0 = _rtP->P_141;
_rtB->B_53_289_0 = _rtP->P_226;
_rtB->B_53_302_0 = _rtP->P_239;
_rtB->B_53_315_0 = _rtP->P_252;
_rtB->B_53_328_0 = _rtP->P_265;
_rtB->B_53_341_0 = _rtP->P_278;
_rtB->B_53_354_0 = _rtP->P_291;
_rtB->B_53_367_0 = _rtP->P_304;
_rtB->B_53_380_0 = _rtP->P_317;
_rtB->B_53_393_0 = _rtP->P_330;
memcpy(&_rtB->B_53_115_0[0], &_rtP->P_89[0], 9009U * sizeof(real_T));
memcpy(&_rtB->B_53_298_0[0], &_rtP->P_238[0], 9009U * sizeof(real_T));
memcpy(&_rtB->B_53_311_0[0], &_rtP->P_251[0], 9009U * sizeof(real_T));
memcpy(&_rtB->B_53_324_0[0], &_rtP->P_264[0], 9009U * sizeof(real_T));
memcpy(&_rtB->B_53_337_0[0], &_rtP->P_277[0], 9009U * sizeof(real_T));
memcpy(&_rtB->B_53_350_0[0], &_rtP->P_290[0], 9009U * sizeof(real_T));
memcpy(&_rtB->B_53_363_0[0], &_rtP->P_303[0], 9009U * sizeof(real_T));
memcpy(&_rtB->B_53_376_0[0], &_rtP->P_316[0], 9009U * sizeof(real_T));
memcpy(&_rtB->B_53_389_0[0], &_rtP->P_329[0], 9009U * sizeof(real_T));
memcpy(&_rtB->B_53_402_0[0], &_rtP->P_342[0], 9009U * sizeof(real_T));
_rtB->B_53_406_0 = _rtP->P_343;
_rtB->B_53_470_0 = _rtP->P_395;
_rtB->B_53_475_0 = _rtP->P_404;
_rtB->B_53_480_0 = _rtP->P_407;
_rtB->B_53_483_0 = _rtP->P_409;
_rtB->B_53_526_0 = _rtP->P_440;
_rtB->B_53_531_0 = _rtP->P_449;
_rtB->B_53_536_0 = _rtP->P_452;
_rtB->B_53_539_0 = _rtP->P_454;
_rtB->B_53_582_0 = _rtP->P_485;
_rtB->B_53_587_0 = _rtP->P_494;
_rtB->B_53_592_0 = _rtP->P_497;
_rtB->B_53_595_0 = _rtP->P_499;
_rtB->B_53_638_0 = _rtP->P_530;
_rtB->B_53_643_0 = _rtP->P_539;
_rtB->B_53_648_0 = _rtP->P_542;
_rtB->B_53_651_0 = _rtP->P_544;
_rtB->B_53_694_0 = _rtP->P_575;
_rtB->B_53_699_0 = _rtP->P_584;
_rtB->B_53_704_0 = _rtP->P_587;
_rtB->B_53_707_0 = _rtP->P_589;
_rtB->B_53_750_0 = _rtP->P_620;
_rtB->B_53_755_0 = _rtP->P_629;
_rtB->B_53_760_0 = _rtP->P_632;
_rtB->B_53_763_0 = _rtP->P_634;
_rtB->B_53_806_0 = _rtP->P_665;
_rtB->B_53_811_0 = _rtP->P_674;
_rtB->B_53_816_0 = _rtP->P_677;
_rtB->B_53_819_0 = _rtP->P_679;
_rtB->B_53_862_0 = _rtP->P_710;
_rtB->B_53_867_0 = _rtP->P_719;
_rtB->B_53_872_0 = _rtP->P_722;
_rtB->B_53_875_0 = _rtP->P_724;
_rtB->B_53_918_0 = _rtP->P_755;
_rtB->B_53_923_0 = _rtP->P_764;
_rtB->B_53_928_0 = _rtP->P_767;
_rtB->B_53_931_0 = _rtP->P_769;
_rtB->B_53_974_0 = _rtP->P_800;
_rtB->B_53_979_0 = _rtP->P_809;
_rtB->B_53_984_0 = _rtP->P_812;
_rtB->B_53_987_0 = _rtP->P_814;
_rtB->B_53_1028_0 = _rtP->P_989;
_rtB->B_53_1031_0 = _rtP->P_991;
memcpy(&_rtB->B_53_1033_0[0], &_rtP->P_841[0], 226800U * sizeof(real_T));
memcpy(&_rtB->B_53_1034_0[0], &_rtP->P_842[0], 10U * sizeof(real_T));
_rtB->B_53_1057_0 = _rtP->P_993;
_rtB->B_53_1059_0 = _rtP->P_994;
_rtB->B_53_1061_0 = _rtP->P_996;
_rtB->B_53_1063_0 = _rtP->P_997;
_rtB->B_53_1065_0 = _rtP->P_999;
_rtB->B_53_1067_0 = _rtP->P_1000;
_rtB->B_53_1069_0 = _rtP->P_1002;
_rtB->B_53_1071_0 = _rtP->P_1003;
_rtB->B_53_1073_0 = _rtP->P_1005;
_rtB->B_53_1075_0 = _rtP->P_1006;
_rtB->B_53_1077_0 = _rtP->P_1008;
_rtB->B_53_1079_0 = _rtP->P_1009;
_rtB->B_53_1081_0 = _rtP->P_1011;
_rtB->B_53_1083_0 = _rtP->P_1012;
_rtB->B_53_1085_0 = _rtP->P_1014;
_rtB->B_53_1087_0 = _rtP->P_1015;
_rtB->B_53_1089_0 = _rtP->P_1017;
_rtB->B_53_1091_0 = _rtP->P_1018;
_rtB->B_53_1093_0 = _rtP->P_1020;
_rtB->B_53_1095_0 = _rtP->P_1021;






    
  

              UNUSED_PARAMETER(tid);



  
    
        }
    
  







       
    
  

          /* Update for root system: '<Root>' */
            #define MDL_UPDATE
    
  
       static  void mdlUpdate(SimStruct *S, int_T tid)
  {
  
      
        
    int32_T idxDelay;
B_benchmark_no_taylor_T *_rtB;
P_benchmark_no_taylor_T *_rtP;
X_benchmark_no_taylor_T *_rtX;
DW_benchmark_no_taylor_T *_rtDW;
  
    
  

            
      
    
  

                              
_rtDW = ((DW_benchmark_no_taylor_T *) ssGetRootDWork(S));
_rtX = ((X_benchmark_no_taylor_T *) ssGetContStates(S));
_rtP = ((P_benchmark_no_taylor_T *) ssGetModelRtp(S));
_rtB = ((B_benchmark_no_taylor_T *) _ssGetModelBlockIO(S));
/* Update for TransportDelay: '<S27>/Computation Delay' */            {
    real_T **uBuffer = (real_T**)&_rtDW->ComputationDelay_PWORK.TUbufferPtrs[0];
    real_T **tBuffer = (real_T**)&_rtDW->ComputationDelay_PWORK.TUbufferPtrs[4];
       
    real_T simTime   = ssGetT(S);
    
    
        

      
      _rtDW->ComputationDelay_IWORK.Head[0] = ((_rtDW->ComputationDelay_IWORK.Head[0] < (_rtDW->ComputationDelay_IWORK.CircularBufSize[0]-1)) ? (_rtDW->ComputationDelay_IWORK.Head[0]+1) : 0);

      if (_rtDW->ComputationDelay_IWORK.Head[0] == _rtDW->ComputationDelay_IWORK.Tail[0]) {
        
          
          
	  if (!benchmark_no_taylor_acc_rt_TDelayUpdateTailOrGrowBuf( &_rtDW->ComputationDelay_IWORK.CircularBufSize[0], &_rtDW->ComputationDelay_IWORK.Tail[0], &_rtDW->ComputationDelay_IWORK.Head[0], &_rtDW->ComputationDelay_IWORK.Last[0], simTime - _rtP->P_22, tBuffer, uBuffer, (NULL), (boolean_T)0, false, &_rtDW->ComputationDelay_IWORK.MaxNewBufSize)) {
            ssSetErrorStatus(S, "tdelay memory allocation error");
            return;
          }
      }
      
      (*tBuffer++)[_rtDW->ComputationDelay_IWORK.Head[0]] = simTime;
        (*uBuffer++)[_rtDW->ComputationDelay_IWORK.Head[0]] = _rtB->B_53_519_0;
      
      _rtDW->ComputationDelay_IWORK.Head[1] = ((_rtDW->ComputationDelay_IWORK.Head[1] < (_rtDW->ComputationDelay_IWORK.CircularBufSize[1]-1)) ? (_rtDW->ComputationDelay_IWORK.Head[1]+1) : 0);

      if (_rtDW->ComputationDelay_IWORK.Head[1] == _rtDW->ComputationDelay_IWORK.Tail[1]) {
        
          
          
	  if (!benchmark_no_taylor_acc_rt_TDelayUpdateTailOrGrowBuf( &_rtDW->ComputationDelay_IWORK.CircularBufSize[1], &_rtDW->ComputationDelay_IWORK.Tail[1], &_rtDW->ComputationDelay_IWORK.Head[1], &_rtDW->ComputationDelay_IWORK.Last[1], simTime - _rtP->P_22, tBuffer, uBuffer, (NULL), (boolean_T)0, false, &_rtDW->ComputationDelay_IWORK.MaxNewBufSize)) {
            ssSetErrorStatus(S, "tdelay memory allocation error");
            return;
          }
      }
      
      (*tBuffer++)[_rtDW->ComputationDelay_IWORK.Head[1]] = simTime;
        (*uBuffer++)[_rtDW->ComputationDelay_IWORK.Head[1]] = _rtB->B_53_510_0;
      
      _rtDW->ComputationDelay_IWORK.Head[2] = ((_rtDW->ComputationDelay_IWORK.Head[2] < (_rtDW->ComputationDelay_IWORK.CircularBufSize[2]-1)) ? (_rtDW->ComputationDelay_IWORK.Head[2]+1) : 0);

      if (_rtDW->ComputationDelay_IWORK.Head[2] == _rtDW->ComputationDelay_IWORK.Tail[2]) {
        
          
          
	  if (!benchmark_no_taylor_acc_rt_TDelayUpdateTailOrGrowBuf( &_rtDW->ComputationDelay_IWORK.CircularBufSize[2], &_rtDW->ComputationDelay_IWORK.Tail[2], &_rtDW->ComputationDelay_IWORK.Head[2], &_rtDW->ComputationDelay_IWORK.Last[2], simTime - _rtP->P_22, tBuffer, uBuffer, (NULL), (boolean_T)0, false, &_rtDW->ComputationDelay_IWORK.MaxNewBufSize)) {
            ssSetErrorStatus(S, "tdelay memory allocation error");
            return;
          }
      }
      
      (*tBuffer++)[_rtDW->ComputationDelay_IWORK.Head[2]] = simTime;
        (*uBuffer++)[_rtDW->ComputationDelay_IWORK.Head[2]] = _rtB->B_53_515_0;
      
      _rtDW->ComputationDelay_IWORK.Head[3] = ((_rtDW->ComputationDelay_IWORK.Head[3] < (_rtDW->ComputationDelay_IWORK.CircularBufSize[3]-1)) ? (_rtDW->ComputationDelay_IWORK.Head[3]+1) : 0);

      if (_rtDW->ComputationDelay_IWORK.Head[3] == _rtDW->ComputationDelay_IWORK.Tail[3]) {
        
          
          
	  if (!benchmark_no_taylor_acc_rt_TDelayUpdateTailOrGrowBuf( &_rtDW->ComputationDelay_IWORK.CircularBufSize[3], &_rtDW->ComputationDelay_IWORK.Tail[3], &_rtDW->ComputationDelay_IWORK.Head[3], &_rtDW->ComputationDelay_IWORK.Last[3], simTime - _rtP->P_22, tBuffer, uBuffer, (NULL), (boolean_T)0, false, &_rtDW->ComputationDelay_IWORK.MaxNewBufSize)) {
            ssSetErrorStatus(S, "tdelay memory allocation error");
            return;
          }
      }
      
      (*tBuffer)[_rtDW->ComputationDelay_IWORK.Head[3]] = simTime;
        (*uBuffer)[_rtDW->ComputationDelay_IWORK.Head[3]] = _rtB->B_53_516_0;
  }
 /* Update for TransportDelay: '<S59>/Computation Delay' */            {
    real_T **uBuffer = (real_T**)&_rtDW->ComputationDelay_PWORK_h.TUbufferPtrs[0];
    real_T **tBuffer = (real_T**)&_rtDW->ComputationDelay_PWORK_h.TUbufferPtrs[4];
       
    real_T simTime   = ssGetT(S);
    
    
        

      
      _rtDW->ComputationDelay_IWORK_k.Head[0] = ((_rtDW->ComputationDelay_IWORK_k.Head[0] < (_rtDW->ComputationDelay_IWORK_k.CircularBufSize[0]-1)) ? (_rtDW->ComputationDelay_IWORK_k.Head[0]+1) : 0);

      if (_rtDW->ComputationDelay_IWORK_k.Head[0] == _rtDW->ComputationDelay_IWORK_k.Tail[0]) {
        
          
          
	  if (!benchmark_no_taylor_acc_rt_TDelayUpdateTailOrGrowBuf( &_rtDW->ComputationDelay_IWORK_k.CircularBufSize[0], &_rtDW->ComputationDelay_IWORK_k.Tail[0], &_rtDW->ComputationDelay_IWORK_k.Head[0], &_rtDW->ComputationDelay_IWORK_k.Last[0], simTime - _rtP->P_24, tBuffer, uBuffer, (NULL), (boolean_T)0, false, &_rtDW->ComputationDelay_IWORK_k.MaxNewBufSize)) {
            ssSetErrorStatus(S, "tdelay memory allocation error");
            return;
          }
      }
      
      (*tBuffer++)[_rtDW->ComputationDelay_IWORK_k.Head[0]] = simTime;
        (*uBuffer++)[_rtDW->ComputationDelay_IWORK_k.Head[0]] = _rtB->B_53_631_0;
      
      _rtDW->ComputationDelay_IWORK_k.Head[1] = ((_rtDW->ComputationDelay_IWORK_k.Head[1] < (_rtDW->ComputationDelay_IWORK_k.CircularBufSize[1]-1)) ? (_rtDW->ComputationDelay_IWORK_k.Head[1]+1) : 0);

      if (_rtDW->ComputationDelay_IWORK_k.Head[1] == _rtDW->ComputationDelay_IWORK_k.Tail[1]) {
        
          
          
	  if (!benchmark_no_taylor_acc_rt_TDelayUpdateTailOrGrowBuf( &_rtDW->ComputationDelay_IWORK_k.CircularBufSize[1], &_rtDW->ComputationDelay_IWORK_k.Tail[1], &_rtDW->ComputationDelay_IWORK_k.Head[1], &_rtDW->ComputationDelay_IWORK_k.Last[1], simTime - _rtP->P_24, tBuffer, uBuffer, (NULL), (boolean_T)0, false, &_rtDW->ComputationDelay_IWORK_k.MaxNewBufSize)) {
            ssSetErrorStatus(S, "tdelay memory allocation error");
            return;
          }
      }
      
      (*tBuffer++)[_rtDW->ComputationDelay_IWORK_k.Head[1]] = simTime;
        (*uBuffer++)[_rtDW->ComputationDelay_IWORK_k.Head[1]] = _rtB->B_53_622_0;
      
      _rtDW->ComputationDelay_IWORK_k.Head[2] = ((_rtDW->ComputationDelay_IWORK_k.Head[2] < (_rtDW->ComputationDelay_IWORK_k.CircularBufSize[2]-1)) ? (_rtDW->ComputationDelay_IWORK_k.Head[2]+1) : 0);

      if (_rtDW->ComputationDelay_IWORK_k.Head[2] == _rtDW->ComputationDelay_IWORK_k.Tail[2]) {
        
          
          
	  if (!benchmark_no_taylor_acc_rt_TDelayUpdateTailOrGrowBuf( &_rtDW->ComputationDelay_IWORK_k.CircularBufSize[2], &_rtDW->ComputationDelay_IWORK_k.Tail[2], &_rtDW->ComputationDelay_IWORK_k.Head[2], &_rtDW->ComputationDelay_IWORK_k.Last[2], simTime - _rtP->P_24, tBuffer, uBuffer, (NULL), (boolean_T)0, false, &_rtDW->ComputationDelay_IWORK_k.MaxNewBufSize)) {
            ssSetErrorStatus(S, "tdelay memory allocation error");
            return;
          }
      }
      
      (*tBuffer++)[_rtDW->ComputationDelay_IWORK_k.Head[2]] = simTime;
        (*uBuffer++)[_rtDW->ComputationDelay_IWORK_k.Head[2]] = _rtB->B_53_627_0;
      
      _rtDW->ComputationDelay_IWORK_k.Head[3] = ((_rtDW->ComputationDelay_IWORK_k.Head[3] < (_rtDW->ComputationDelay_IWORK_k.CircularBufSize[3]-1)) ? (_rtDW->ComputationDelay_IWORK_k.Head[3]+1) : 0);

      if (_rtDW->ComputationDelay_IWORK_k.Head[3] == _rtDW->ComputationDelay_IWORK_k.Tail[3]) {
        
          
          
	  if (!benchmark_no_taylor_acc_rt_TDelayUpdateTailOrGrowBuf( &_rtDW->ComputationDelay_IWORK_k.CircularBufSize[3], &_rtDW->ComputationDelay_IWORK_k.Tail[3], &_rtDW->ComputationDelay_IWORK_k.Head[3], &_rtDW->ComputationDelay_IWORK_k.Last[3], simTime - _rtP->P_24, tBuffer, uBuffer, (NULL), (boolean_T)0, false, &_rtDW->ComputationDelay_IWORK_k.MaxNewBufSize)) {
            ssSetErrorStatus(S, "tdelay memory allocation error");
            return;
          }
      }
      
      (*tBuffer)[_rtDW->ComputationDelay_IWORK_k.Head[3]] = simTime;
        (*uBuffer)[_rtDW->ComputationDelay_IWORK_k.Head[3]] = _rtB->B_53_628_0;
  }
 /* Update for TransportDelay: '<S75>/Computation Delay' */            {
    real_T **uBuffer = (real_T**)&_rtDW->ComputationDelay_PWORK_a.TUbufferPtrs[0];
    real_T **tBuffer = (real_T**)&_rtDW->ComputationDelay_PWORK_a.TUbufferPtrs[4];
       
    real_T simTime   = ssGetT(S);
    
    
        

      
      _rtDW->ComputationDelay_IWORK_b.Head[0] = ((_rtDW->ComputationDelay_IWORK_b.Head[0] < (_rtDW->ComputationDelay_IWORK_b.CircularBufSize[0]-1)) ? (_rtDW->ComputationDelay_IWORK_b.Head[0]+1) : 0);

      if (_rtDW->ComputationDelay_IWORK_b.Head[0] == _rtDW->ComputationDelay_IWORK_b.Tail[0]) {
        
          
          
	  if (!benchmark_no_taylor_acc_rt_TDelayUpdateTailOrGrowBuf( &_rtDW->ComputationDelay_IWORK_b.CircularBufSize[0], &_rtDW->ComputationDelay_IWORK_b.Tail[0], &_rtDW->ComputationDelay_IWORK_b.Head[0], &_rtDW->ComputationDelay_IWORK_b.Last[0], simTime - _rtP->P_26, tBuffer, uBuffer, (NULL), (boolean_T)0, false, &_rtDW->ComputationDelay_IWORK_b.MaxNewBufSize)) {
            ssSetErrorStatus(S, "tdelay memory allocation error");
            return;
          }
      }
      
      (*tBuffer++)[_rtDW->ComputationDelay_IWORK_b.Head[0]] = simTime;
        (*uBuffer++)[_rtDW->ComputationDelay_IWORK_b.Head[0]] = _rtB->B_53_687_0;
      
      _rtDW->ComputationDelay_IWORK_b.Head[1] = ((_rtDW->ComputationDelay_IWORK_b.Head[1] < (_rtDW->ComputationDelay_IWORK_b.CircularBufSize[1]-1)) ? (_rtDW->ComputationDelay_IWORK_b.Head[1]+1) : 0);

      if (_rtDW->ComputationDelay_IWORK_b.Head[1] == _rtDW->ComputationDelay_IWORK_b.Tail[1]) {
        
          
          
	  if (!benchmark_no_taylor_acc_rt_TDelayUpdateTailOrGrowBuf( &_rtDW->ComputationDelay_IWORK_b.CircularBufSize[1], &_rtDW->ComputationDelay_IWORK_b.Tail[1], &_rtDW->ComputationDelay_IWORK_b.Head[1], &_rtDW->ComputationDelay_IWORK_b.Last[1], simTime - _rtP->P_26, tBuffer, uBuffer, (NULL), (boolean_T)0, false, &_rtDW->ComputationDelay_IWORK_b.MaxNewBufSize)) {
            ssSetErrorStatus(S, "tdelay memory allocation error");
            return;
          }
      }
      
      (*tBuffer++)[_rtDW->ComputationDelay_IWORK_b.Head[1]] = simTime;
        (*uBuffer++)[_rtDW->ComputationDelay_IWORK_b.Head[1]] = _rtB->B_53_678_0;
      
      _rtDW->ComputationDelay_IWORK_b.Head[2] = ((_rtDW->ComputationDelay_IWORK_b.Head[2] < (_rtDW->ComputationDelay_IWORK_b.CircularBufSize[2]-1)) ? (_rtDW->ComputationDelay_IWORK_b.Head[2]+1) : 0);

      if (_rtDW->ComputationDelay_IWORK_b.Head[2] == _rtDW->ComputationDelay_IWORK_b.Tail[2]) {
        
          
          
	  if (!benchmark_no_taylor_acc_rt_TDelayUpdateTailOrGrowBuf( &_rtDW->ComputationDelay_IWORK_b.CircularBufSize[2], &_rtDW->ComputationDelay_IWORK_b.Tail[2], &_rtDW->ComputationDelay_IWORK_b.Head[2], &_rtDW->ComputationDelay_IWORK_b.Last[2], simTime - _rtP->P_26, tBuffer, uBuffer, (NULL), (boolean_T)0, false, &_rtDW->ComputationDelay_IWORK_b.MaxNewBufSize)) {
            ssSetErrorStatus(S, "tdelay memory allocation error");
            return;
          }
      }
      
      (*tBuffer++)[_rtDW->ComputationDelay_IWORK_b.Head[2]] = simTime;
        (*uBuffer++)[_rtDW->ComputationDelay_IWORK_b.Head[2]] = _rtB->B_53_683_0;
      
      _rtDW->ComputationDelay_IWORK_b.Head[3] = ((_rtDW->ComputationDelay_IWORK_b.Head[3] < (_rtDW->ComputationDelay_IWORK_b.CircularBufSize[3]-1)) ? (_rtDW->ComputationDelay_IWORK_b.Head[3]+1) : 0);

      if (_rtDW->ComputationDelay_IWORK_b.Head[3] == _rtDW->ComputationDelay_IWORK_b.Tail[3]) {
        
          
          
	  if (!benchmark_no_taylor_acc_rt_TDelayUpdateTailOrGrowBuf( &_rtDW->ComputationDelay_IWORK_b.CircularBufSize[3], &_rtDW->ComputationDelay_IWORK_b.Tail[3], &_rtDW->ComputationDelay_IWORK_b.Head[3], &_rtDW->ComputationDelay_IWORK_b.Last[3], simTime - _rtP->P_26, tBuffer, uBuffer, (NULL), (boolean_T)0, false, &_rtDW->ComputationDelay_IWORK_b.MaxNewBufSize)) {
            ssSetErrorStatus(S, "tdelay memory allocation error");
            return;
          }
      }
      
      (*tBuffer)[_rtDW->ComputationDelay_IWORK_b.Head[3]] = simTime;
        (*uBuffer)[_rtDW->ComputationDelay_IWORK_b.Head[3]] = _rtB->B_53_684_0;
  }
 /* Update for TransportDelay: '<S91>/Computation Delay' */            {
    real_T **uBuffer = (real_T**)&_rtDW->ComputationDelay_PWORK_g.TUbufferPtrs[0];
    real_T **tBuffer = (real_T**)&_rtDW->ComputationDelay_PWORK_g.TUbufferPtrs[4];
       
    real_T simTime   = ssGetT(S);
    
    
        

      
      _rtDW->ComputationDelay_IWORK_e.Head[0] = ((_rtDW->ComputationDelay_IWORK_e.Head[0] < (_rtDW->ComputationDelay_IWORK_e.CircularBufSize[0]-1)) ? (_rtDW->ComputationDelay_IWORK_e.Head[0]+1) : 0);

      if (_rtDW->ComputationDelay_IWORK_e.Head[0] == _rtDW->ComputationDelay_IWORK_e.Tail[0]) {
        
          
          
	  if (!benchmark_no_taylor_acc_rt_TDelayUpdateTailOrGrowBuf( &_rtDW->ComputationDelay_IWORK_e.CircularBufSize[0], &_rtDW->ComputationDelay_IWORK_e.Tail[0], &_rtDW->ComputationDelay_IWORK_e.Head[0], &_rtDW->ComputationDelay_IWORK_e.Last[0], simTime - _rtP->P_28, tBuffer, uBuffer, (NULL), (boolean_T)0, false, &_rtDW->ComputationDelay_IWORK_e.MaxNewBufSize)) {
            ssSetErrorStatus(S, "tdelay memory allocation error");
            return;
          }
      }
      
      (*tBuffer++)[_rtDW->ComputationDelay_IWORK_e.Head[0]] = simTime;
        (*uBuffer++)[_rtDW->ComputationDelay_IWORK_e.Head[0]] = _rtB->B_53_743_0;
      
      _rtDW->ComputationDelay_IWORK_e.Head[1] = ((_rtDW->ComputationDelay_IWORK_e.Head[1] < (_rtDW->ComputationDelay_IWORK_e.CircularBufSize[1]-1)) ? (_rtDW->ComputationDelay_IWORK_e.Head[1]+1) : 0);

      if (_rtDW->ComputationDelay_IWORK_e.Head[1] == _rtDW->ComputationDelay_IWORK_e.Tail[1]) {
        
          
          
	  if (!benchmark_no_taylor_acc_rt_TDelayUpdateTailOrGrowBuf( &_rtDW->ComputationDelay_IWORK_e.CircularBufSize[1], &_rtDW->ComputationDelay_IWORK_e.Tail[1], &_rtDW->ComputationDelay_IWORK_e.Head[1], &_rtDW->ComputationDelay_IWORK_e.Last[1], simTime - _rtP->P_28, tBuffer, uBuffer, (NULL), (boolean_T)0, false, &_rtDW->ComputationDelay_IWORK_e.MaxNewBufSize)) {
            ssSetErrorStatus(S, "tdelay memory allocation error");
            return;
          }
      }
      
      (*tBuffer++)[_rtDW->ComputationDelay_IWORK_e.Head[1]] = simTime;
        (*uBuffer++)[_rtDW->ComputationDelay_IWORK_e.Head[1]] = _rtB->B_53_734_0;
      
      _rtDW->ComputationDelay_IWORK_e.Head[2] = ((_rtDW->ComputationDelay_IWORK_e.Head[2] < (_rtDW->ComputationDelay_IWORK_e.CircularBufSize[2]-1)) ? (_rtDW->ComputationDelay_IWORK_e.Head[2]+1) : 0);

      if (_rtDW->ComputationDelay_IWORK_e.Head[2] == _rtDW->ComputationDelay_IWORK_e.Tail[2]) {
        
          
          
	  if (!benchmark_no_taylor_acc_rt_TDelayUpdateTailOrGrowBuf( &_rtDW->ComputationDelay_IWORK_e.CircularBufSize[2], &_rtDW->ComputationDelay_IWORK_e.Tail[2], &_rtDW->ComputationDelay_IWORK_e.Head[2], &_rtDW->ComputationDelay_IWORK_e.Last[2], simTime - _rtP->P_28, tBuffer, uBuffer, (NULL), (boolean_T)0, false, &_rtDW->ComputationDelay_IWORK_e.MaxNewBufSize)) {
            ssSetErrorStatus(S, "tdelay memory allocation error");
            return;
          }
      }
      
      (*tBuffer++)[_rtDW->ComputationDelay_IWORK_e.Head[2]] = simTime;
        (*uBuffer++)[_rtDW->ComputationDelay_IWORK_e.Head[2]] = _rtB->B_53_739_0;
      
      _rtDW->ComputationDelay_IWORK_e.Head[3] = ((_rtDW->ComputationDelay_IWORK_e.Head[3] < (_rtDW->ComputationDelay_IWORK_e.CircularBufSize[3]-1)) ? (_rtDW->ComputationDelay_IWORK_e.Head[3]+1) : 0);

      if (_rtDW->ComputationDelay_IWORK_e.Head[3] == _rtDW->ComputationDelay_IWORK_e.Tail[3]) {
        
          
          
	  if (!benchmark_no_taylor_acc_rt_TDelayUpdateTailOrGrowBuf( &_rtDW->ComputationDelay_IWORK_e.CircularBufSize[3], &_rtDW->ComputationDelay_IWORK_e.Tail[3], &_rtDW->ComputationDelay_IWORK_e.Head[3], &_rtDW->ComputationDelay_IWORK_e.Last[3], simTime - _rtP->P_28, tBuffer, uBuffer, (NULL), (boolean_T)0, false, &_rtDW->ComputationDelay_IWORK_e.MaxNewBufSize)) {
            ssSetErrorStatus(S, "tdelay memory allocation error");
            return;
          }
      }
      
      (*tBuffer)[_rtDW->ComputationDelay_IWORK_e.Head[3]] = simTime;
        (*uBuffer)[_rtDW->ComputationDelay_IWORK_e.Head[3]] = _rtB->B_53_740_0;
  }
 /* Update for TransportDelay: '<S107>/Computation Delay' */            {
    real_T **uBuffer = (real_T**)&_rtDW->ComputationDelay_PWORK_j.TUbufferPtrs[0];
    real_T **tBuffer = (real_T**)&_rtDW->ComputationDelay_PWORK_j.TUbufferPtrs[4];
       
    real_T simTime   = ssGetT(S);
    
    
        

      
      _rtDW->ComputationDelay_IWORK_h.Head[0] = ((_rtDW->ComputationDelay_IWORK_h.Head[0] < (_rtDW->ComputationDelay_IWORK_h.CircularBufSize[0]-1)) ? (_rtDW->ComputationDelay_IWORK_h.Head[0]+1) : 0);

      if (_rtDW->ComputationDelay_IWORK_h.Head[0] == _rtDW->ComputationDelay_IWORK_h.Tail[0]) {
        
          
          
	  if (!benchmark_no_taylor_acc_rt_TDelayUpdateTailOrGrowBuf( &_rtDW->ComputationDelay_IWORK_h.CircularBufSize[0], &_rtDW->ComputationDelay_IWORK_h.Tail[0], &_rtDW->ComputationDelay_IWORK_h.Head[0], &_rtDW->ComputationDelay_IWORK_h.Last[0], simTime - _rtP->P_30, tBuffer, uBuffer, (NULL), (boolean_T)0, false, &_rtDW->ComputationDelay_IWORK_h.MaxNewBufSize)) {
            ssSetErrorStatus(S, "tdelay memory allocation error");
            return;
          }
      }
      
      (*tBuffer++)[_rtDW->ComputationDelay_IWORK_h.Head[0]] = simTime;
        (*uBuffer++)[_rtDW->ComputationDelay_IWORK_h.Head[0]] = _rtB->B_53_799_0;
      
      _rtDW->ComputationDelay_IWORK_h.Head[1] = ((_rtDW->ComputationDelay_IWORK_h.Head[1] < (_rtDW->ComputationDelay_IWORK_h.CircularBufSize[1]-1)) ? (_rtDW->ComputationDelay_IWORK_h.Head[1]+1) : 0);

      if (_rtDW->ComputationDelay_IWORK_h.Head[1] == _rtDW->ComputationDelay_IWORK_h.Tail[1]) {
        
          
          
	  if (!benchmark_no_taylor_acc_rt_TDelayUpdateTailOrGrowBuf( &_rtDW->ComputationDelay_IWORK_h.CircularBufSize[1], &_rtDW->ComputationDelay_IWORK_h.Tail[1], &_rtDW->ComputationDelay_IWORK_h.Head[1], &_rtDW->ComputationDelay_IWORK_h.Last[1], simTime - _rtP->P_30, tBuffer, uBuffer, (NULL), (boolean_T)0, false, &_rtDW->ComputationDelay_IWORK_h.MaxNewBufSize)) {
            ssSetErrorStatus(S, "tdelay memory allocation error");
            return;
          }
      }
      
      (*tBuffer++)[_rtDW->ComputationDelay_IWORK_h.Head[1]] = simTime;
        (*uBuffer++)[_rtDW->ComputationDelay_IWORK_h.Head[1]] = _rtB->B_53_790_0;
      
      _rtDW->ComputationDelay_IWORK_h.Head[2] = ((_rtDW->ComputationDelay_IWORK_h.Head[2] < (_rtDW->ComputationDelay_IWORK_h.CircularBufSize[2]-1)) ? (_rtDW->ComputationDelay_IWORK_h.Head[2]+1) : 0);

      if (_rtDW->ComputationDelay_IWORK_h.Head[2] == _rtDW->ComputationDelay_IWORK_h.Tail[2]) {
        
          
          
	  if (!benchmark_no_taylor_acc_rt_TDelayUpdateTailOrGrowBuf( &_rtDW->ComputationDelay_IWORK_h.CircularBufSize[2], &_rtDW->ComputationDelay_IWORK_h.Tail[2], &_rtDW->ComputationDelay_IWORK_h.Head[2], &_rtDW->ComputationDelay_IWORK_h.Last[2], simTime - _rtP->P_30, tBuffer, uBuffer, (NULL), (boolean_T)0, false, &_rtDW->ComputationDelay_IWORK_h.MaxNewBufSize)) {
            ssSetErrorStatus(S, "tdelay memory allocation error");
            return;
          }
      }
      
      (*tBuffer++)[_rtDW->ComputationDelay_IWORK_h.Head[2]] = simTime;
        (*uBuffer++)[_rtDW->ComputationDelay_IWORK_h.Head[2]] = _rtB->B_53_795_0;
      
      _rtDW->ComputationDelay_IWORK_h.Head[3] = ((_rtDW->ComputationDelay_IWORK_h.Head[3] < (_rtDW->ComputationDelay_IWORK_h.CircularBufSize[3]-1)) ? (_rtDW->ComputationDelay_IWORK_h.Head[3]+1) : 0);

      if (_rtDW->ComputationDelay_IWORK_h.Head[3] == _rtDW->ComputationDelay_IWORK_h.Tail[3]) {
        
          
          
	  if (!benchmark_no_taylor_acc_rt_TDelayUpdateTailOrGrowBuf( &_rtDW->ComputationDelay_IWORK_h.CircularBufSize[3], &_rtDW->ComputationDelay_IWORK_h.Tail[3], &_rtDW->ComputationDelay_IWORK_h.Head[3], &_rtDW->ComputationDelay_IWORK_h.Last[3], simTime - _rtP->P_30, tBuffer, uBuffer, (NULL), (boolean_T)0, false, &_rtDW->ComputationDelay_IWORK_h.MaxNewBufSize)) {
            ssSetErrorStatus(S, "tdelay memory allocation error");
            return;
          }
      }
      
      (*tBuffer)[_rtDW->ComputationDelay_IWORK_h.Head[3]] = simTime;
        (*uBuffer)[_rtDW->ComputationDelay_IWORK_h.Head[3]] = _rtB->B_53_796_0;
  }
 /* Update for TransportDelay: '<S123>/Computation Delay' */            {
    real_T **uBuffer = (real_T**)&_rtDW->ComputationDelay_PWORK_d.TUbufferPtrs[0];
    real_T **tBuffer = (real_T**)&_rtDW->ComputationDelay_PWORK_d.TUbufferPtrs[4];
       
    real_T simTime   = ssGetT(S);
    
    
        

      
      _rtDW->ComputationDelay_IWORK_d.Head[0] = ((_rtDW->ComputationDelay_IWORK_d.Head[0] < (_rtDW->ComputationDelay_IWORK_d.CircularBufSize[0]-1)) ? (_rtDW->ComputationDelay_IWORK_d.Head[0]+1) : 0);

      if (_rtDW->ComputationDelay_IWORK_d.Head[0] == _rtDW->ComputationDelay_IWORK_d.Tail[0]) {
        
          
          
	  if (!benchmark_no_taylor_acc_rt_TDelayUpdateTailOrGrowBuf( &_rtDW->ComputationDelay_IWORK_d.CircularBufSize[0], &_rtDW->ComputationDelay_IWORK_d.Tail[0], &_rtDW->ComputationDelay_IWORK_d.Head[0], &_rtDW->ComputationDelay_IWORK_d.Last[0], simTime - _rtP->P_32, tBuffer, uBuffer, (NULL), (boolean_T)0, false, &_rtDW->ComputationDelay_IWORK_d.MaxNewBufSize)) {
            ssSetErrorStatus(S, "tdelay memory allocation error");
            return;
          }
      }
      
      (*tBuffer++)[_rtDW->ComputationDelay_IWORK_d.Head[0]] = simTime;
        (*uBuffer++)[_rtDW->ComputationDelay_IWORK_d.Head[0]] = _rtB->B_53_855_0;
      
      _rtDW->ComputationDelay_IWORK_d.Head[1] = ((_rtDW->ComputationDelay_IWORK_d.Head[1] < (_rtDW->ComputationDelay_IWORK_d.CircularBufSize[1]-1)) ? (_rtDW->ComputationDelay_IWORK_d.Head[1]+1) : 0);

      if (_rtDW->ComputationDelay_IWORK_d.Head[1] == _rtDW->ComputationDelay_IWORK_d.Tail[1]) {
        
          
          
	  if (!benchmark_no_taylor_acc_rt_TDelayUpdateTailOrGrowBuf( &_rtDW->ComputationDelay_IWORK_d.CircularBufSize[1], &_rtDW->ComputationDelay_IWORK_d.Tail[1], &_rtDW->ComputationDelay_IWORK_d.Head[1], &_rtDW->ComputationDelay_IWORK_d.Last[1], simTime - _rtP->P_32, tBuffer, uBuffer, (NULL), (boolean_T)0, false, &_rtDW->ComputationDelay_IWORK_d.MaxNewBufSize)) {
            ssSetErrorStatus(S, "tdelay memory allocation error");
            return;
          }
      }
      
      (*tBuffer++)[_rtDW->ComputationDelay_IWORK_d.Head[1]] = simTime;
        (*uBuffer++)[_rtDW->ComputationDelay_IWORK_d.Head[1]] = _rtB->B_53_846_0;
      
      _rtDW->ComputationDelay_IWORK_d.Head[2] = ((_rtDW->ComputationDelay_IWORK_d.Head[2] < (_rtDW->ComputationDelay_IWORK_d.CircularBufSize[2]-1)) ? (_rtDW->ComputationDelay_IWORK_d.Head[2]+1) : 0);

      if (_rtDW->ComputationDelay_IWORK_d.Head[2] == _rtDW->ComputationDelay_IWORK_d.Tail[2]) {
        
          
          
	  if (!benchmark_no_taylor_acc_rt_TDelayUpdateTailOrGrowBuf( &_rtDW->ComputationDelay_IWORK_d.CircularBufSize[2], &_rtDW->ComputationDelay_IWORK_d.Tail[2], &_rtDW->ComputationDelay_IWORK_d.Head[2], &_rtDW->ComputationDelay_IWORK_d.Last[2], simTime - _rtP->P_32, tBuffer, uBuffer, (NULL), (boolean_T)0, false, &_rtDW->ComputationDelay_IWORK_d.MaxNewBufSize)) {
            ssSetErrorStatus(S, "tdelay memory allocation error");
            return;
          }
      }
      
      (*tBuffer++)[_rtDW->ComputationDelay_IWORK_d.Head[2]] = simTime;
        (*uBuffer++)[_rtDW->ComputationDelay_IWORK_d.Head[2]] = _rtB->B_53_851_0;
      
      _rtDW->ComputationDelay_IWORK_d.Head[3] = ((_rtDW->ComputationDelay_IWORK_d.Head[3] < (_rtDW->ComputationDelay_IWORK_d.CircularBufSize[3]-1)) ? (_rtDW->ComputationDelay_IWORK_d.Head[3]+1) : 0);

      if (_rtDW->ComputationDelay_IWORK_d.Head[3] == _rtDW->ComputationDelay_IWORK_d.Tail[3]) {
        
          
          
	  if (!benchmark_no_taylor_acc_rt_TDelayUpdateTailOrGrowBuf( &_rtDW->ComputationDelay_IWORK_d.CircularBufSize[3], &_rtDW->ComputationDelay_IWORK_d.Tail[3], &_rtDW->ComputationDelay_IWORK_d.Head[3], &_rtDW->ComputationDelay_IWORK_d.Last[3], simTime - _rtP->P_32, tBuffer, uBuffer, (NULL), (boolean_T)0, false, &_rtDW->ComputationDelay_IWORK_d.MaxNewBufSize)) {
            ssSetErrorStatus(S, "tdelay memory allocation error");
            return;
          }
      }
      
      (*tBuffer)[_rtDW->ComputationDelay_IWORK_d.Head[3]] = simTime;
        (*uBuffer)[_rtDW->ComputationDelay_IWORK_d.Head[3]] = _rtB->B_53_852_0;
  }
 /* Update for TransportDelay: '<S139>/Computation Delay' */            {
    real_T **uBuffer = (real_T**)&_rtDW->ComputationDelay_PWORK_o.TUbufferPtrs[0];
    real_T **tBuffer = (real_T**)&_rtDW->ComputationDelay_PWORK_o.TUbufferPtrs[4];
       
    real_T simTime   = ssGetT(S);
    
    
        

      
      _rtDW->ComputationDelay_IWORK_i.Head[0] = ((_rtDW->ComputationDelay_IWORK_i.Head[0] < (_rtDW->ComputationDelay_IWORK_i.CircularBufSize[0]-1)) ? (_rtDW->ComputationDelay_IWORK_i.Head[0]+1) : 0);

      if (_rtDW->ComputationDelay_IWORK_i.Head[0] == _rtDW->ComputationDelay_IWORK_i.Tail[0]) {
        
          
          
	  if (!benchmark_no_taylor_acc_rt_TDelayUpdateTailOrGrowBuf( &_rtDW->ComputationDelay_IWORK_i.CircularBufSize[0], &_rtDW->ComputationDelay_IWORK_i.Tail[0], &_rtDW->ComputationDelay_IWORK_i.Head[0], &_rtDW->ComputationDelay_IWORK_i.Last[0], simTime - _rtP->P_34, tBuffer, uBuffer, (NULL), (boolean_T)0, false, &_rtDW->ComputationDelay_IWORK_i.MaxNewBufSize)) {
            ssSetErrorStatus(S, "tdelay memory allocation error");
            return;
          }
      }
      
      (*tBuffer++)[_rtDW->ComputationDelay_IWORK_i.Head[0]] = simTime;
        (*uBuffer++)[_rtDW->ComputationDelay_IWORK_i.Head[0]] = _rtB->B_53_911_0;
      
      _rtDW->ComputationDelay_IWORK_i.Head[1] = ((_rtDW->ComputationDelay_IWORK_i.Head[1] < (_rtDW->ComputationDelay_IWORK_i.CircularBufSize[1]-1)) ? (_rtDW->ComputationDelay_IWORK_i.Head[1]+1) : 0);

      if (_rtDW->ComputationDelay_IWORK_i.Head[1] == _rtDW->ComputationDelay_IWORK_i.Tail[1]) {
        
          
          
	  if (!benchmark_no_taylor_acc_rt_TDelayUpdateTailOrGrowBuf( &_rtDW->ComputationDelay_IWORK_i.CircularBufSize[1], &_rtDW->ComputationDelay_IWORK_i.Tail[1], &_rtDW->ComputationDelay_IWORK_i.Head[1], &_rtDW->ComputationDelay_IWORK_i.Last[1], simTime - _rtP->P_34, tBuffer, uBuffer, (NULL), (boolean_T)0, false, &_rtDW->ComputationDelay_IWORK_i.MaxNewBufSize)) {
            ssSetErrorStatus(S, "tdelay memory allocation error");
            return;
          }
      }
      
      (*tBuffer++)[_rtDW->ComputationDelay_IWORK_i.Head[1]] = simTime;
        (*uBuffer++)[_rtDW->ComputationDelay_IWORK_i.Head[1]] = _rtB->B_53_902_0;
      
      _rtDW->ComputationDelay_IWORK_i.Head[2] = ((_rtDW->ComputationDelay_IWORK_i.Head[2] < (_rtDW->ComputationDelay_IWORK_i.CircularBufSize[2]-1)) ? (_rtDW->ComputationDelay_IWORK_i.Head[2]+1) : 0);

      if (_rtDW->ComputationDelay_IWORK_i.Head[2] == _rtDW->ComputationDelay_IWORK_i.Tail[2]) {
        
          
          
	  if (!benchmark_no_taylor_acc_rt_TDelayUpdateTailOrGrowBuf( &_rtDW->ComputationDelay_IWORK_i.CircularBufSize[2], &_rtDW->ComputationDelay_IWORK_i.Tail[2], &_rtDW->ComputationDelay_IWORK_i.Head[2], &_rtDW->ComputationDelay_IWORK_i.Last[2], simTime - _rtP->P_34, tBuffer, uBuffer, (NULL), (boolean_T)0, false, &_rtDW->ComputationDelay_IWORK_i.MaxNewBufSize)) {
            ssSetErrorStatus(S, "tdelay memory allocation error");
            return;
          }
      }
      
      (*tBuffer++)[_rtDW->ComputationDelay_IWORK_i.Head[2]] = simTime;
        (*uBuffer++)[_rtDW->ComputationDelay_IWORK_i.Head[2]] = _rtB->B_53_907_0;
      
      _rtDW->ComputationDelay_IWORK_i.Head[3] = ((_rtDW->ComputationDelay_IWORK_i.Head[3] < (_rtDW->ComputationDelay_IWORK_i.CircularBufSize[3]-1)) ? (_rtDW->ComputationDelay_IWORK_i.Head[3]+1) : 0);

      if (_rtDW->ComputationDelay_IWORK_i.Head[3] == _rtDW->ComputationDelay_IWORK_i.Tail[3]) {
        
          
          
	  if (!benchmark_no_taylor_acc_rt_TDelayUpdateTailOrGrowBuf( &_rtDW->ComputationDelay_IWORK_i.CircularBufSize[3], &_rtDW->ComputationDelay_IWORK_i.Tail[3], &_rtDW->ComputationDelay_IWORK_i.Head[3], &_rtDW->ComputationDelay_IWORK_i.Last[3], simTime - _rtP->P_34, tBuffer, uBuffer, (NULL), (boolean_T)0, false, &_rtDW->ComputationDelay_IWORK_i.MaxNewBufSize)) {
            ssSetErrorStatus(S, "tdelay memory allocation error");
            return;
          }
      }
      
      (*tBuffer)[_rtDW->ComputationDelay_IWORK_i.Head[3]] = simTime;
        (*uBuffer)[_rtDW->ComputationDelay_IWORK_i.Head[3]] = _rtB->B_53_908_0;
  }
 /* Update for TransportDelay: '<S155>/Computation Delay' */            {
    real_T **uBuffer = (real_T**)&_rtDW->ComputationDelay_PWORK_al.TUbufferPtrs[0];
    real_T **tBuffer = (real_T**)&_rtDW->ComputationDelay_PWORK_al.TUbufferPtrs[4];
       
    real_T simTime   = ssGetT(S);
    
    
        

      
      _rtDW->ComputationDelay_IWORK_m.Head[0] = ((_rtDW->ComputationDelay_IWORK_m.Head[0] < (_rtDW->ComputationDelay_IWORK_m.CircularBufSize[0]-1)) ? (_rtDW->ComputationDelay_IWORK_m.Head[0]+1) : 0);

      if (_rtDW->ComputationDelay_IWORK_m.Head[0] == _rtDW->ComputationDelay_IWORK_m.Tail[0]) {
        
          
          
	  if (!benchmark_no_taylor_acc_rt_TDelayUpdateTailOrGrowBuf( &_rtDW->ComputationDelay_IWORK_m.CircularBufSize[0], &_rtDW->ComputationDelay_IWORK_m.Tail[0], &_rtDW->ComputationDelay_IWORK_m.Head[0], &_rtDW->ComputationDelay_IWORK_m.Last[0], simTime - _rtP->P_36, tBuffer, uBuffer, (NULL), (boolean_T)0, false, &_rtDW->ComputationDelay_IWORK_m.MaxNewBufSize)) {
            ssSetErrorStatus(S, "tdelay memory allocation error");
            return;
          }
      }
      
      (*tBuffer++)[_rtDW->ComputationDelay_IWORK_m.Head[0]] = simTime;
        (*uBuffer++)[_rtDW->ComputationDelay_IWORK_m.Head[0]] = _rtB->B_53_967_0;
      
      _rtDW->ComputationDelay_IWORK_m.Head[1] = ((_rtDW->ComputationDelay_IWORK_m.Head[1] < (_rtDW->ComputationDelay_IWORK_m.CircularBufSize[1]-1)) ? (_rtDW->ComputationDelay_IWORK_m.Head[1]+1) : 0);

      if (_rtDW->ComputationDelay_IWORK_m.Head[1] == _rtDW->ComputationDelay_IWORK_m.Tail[1]) {
        
          
          
	  if (!benchmark_no_taylor_acc_rt_TDelayUpdateTailOrGrowBuf( &_rtDW->ComputationDelay_IWORK_m.CircularBufSize[1], &_rtDW->ComputationDelay_IWORK_m.Tail[1], &_rtDW->ComputationDelay_IWORK_m.Head[1], &_rtDW->ComputationDelay_IWORK_m.Last[1], simTime - _rtP->P_36, tBuffer, uBuffer, (NULL), (boolean_T)0, false, &_rtDW->ComputationDelay_IWORK_m.MaxNewBufSize)) {
            ssSetErrorStatus(S, "tdelay memory allocation error");
            return;
          }
      }
      
      (*tBuffer++)[_rtDW->ComputationDelay_IWORK_m.Head[1]] = simTime;
        (*uBuffer++)[_rtDW->ComputationDelay_IWORK_m.Head[1]] = _rtB->B_53_958_0;
      
      _rtDW->ComputationDelay_IWORK_m.Head[2] = ((_rtDW->ComputationDelay_IWORK_m.Head[2] < (_rtDW->ComputationDelay_IWORK_m.CircularBufSize[2]-1)) ? (_rtDW->ComputationDelay_IWORK_m.Head[2]+1) : 0);

      if (_rtDW->ComputationDelay_IWORK_m.Head[2] == _rtDW->ComputationDelay_IWORK_m.Tail[2]) {
        
          
          
	  if (!benchmark_no_taylor_acc_rt_TDelayUpdateTailOrGrowBuf( &_rtDW->ComputationDelay_IWORK_m.CircularBufSize[2], &_rtDW->ComputationDelay_IWORK_m.Tail[2], &_rtDW->ComputationDelay_IWORK_m.Head[2], &_rtDW->ComputationDelay_IWORK_m.Last[2], simTime - _rtP->P_36, tBuffer, uBuffer, (NULL), (boolean_T)0, false, &_rtDW->ComputationDelay_IWORK_m.MaxNewBufSize)) {
            ssSetErrorStatus(S, "tdelay memory allocation error");
            return;
          }
      }
      
      (*tBuffer++)[_rtDW->ComputationDelay_IWORK_m.Head[2]] = simTime;
        (*uBuffer++)[_rtDW->ComputationDelay_IWORK_m.Head[2]] = _rtB->B_53_963_0;
      
      _rtDW->ComputationDelay_IWORK_m.Head[3] = ((_rtDW->ComputationDelay_IWORK_m.Head[3] < (_rtDW->ComputationDelay_IWORK_m.CircularBufSize[3]-1)) ? (_rtDW->ComputationDelay_IWORK_m.Head[3]+1) : 0);

      if (_rtDW->ComputationDelay_IWORK_m.Head[3] == _rtDW->ComputationDelay_IWORK_m.Tail[3]) {
        
          
          
	  if (!benchmark_no_taylor_acc_rt_TDelayUpdateTailOrGrowBuf( &_rtDW->ComputationDelay_IWORK_m.CircularBufSize[3], &_rtDW->ComputationDelay_IWORK_m.Tail[3], &_rtDW->ComputationDelay_IWORK_m.Head[3], &_rtDW->ComputationDelay_IWORK_m.Last[3], simTime - _rtP->P_36, tBuffer, uBuffer, (NULL), (boolean_T)0, false, &_rtDW->ComputationDelay_IWORK_m.MaxNewBufSize)) {
            ssSetErrorStatus(S, "tdelay memory allocation error");
            return;
          }
      }
      
      (*tBuffer)[_rtDW->ComputationDelay_IWORK_m.Head[3]] = simTime;
        (*uBuffer)[_rtDW->ComputationDelay_IWORK_m.Head[3]] = _rtB->B_53_964_0;
  }
 /* Update for TransportDelay: '<S171>/Computation Delay' */            {
    real_T **uBuffer = (real_T**)&_rtDW->ComputationDelay_PWORK_ds.TUbufferPtrs[0];
    real_T **tBuffer = (real_T**)&_rtDW->ComputationDelay_PWORK_ds.TUbufferPtrs[4];
       
    real_T simTime   = ssGetT(S);
    
    
        

      
      _rtDW->ComputationDelay_IWORK_ez.Head[0] = ((_rtDW->ComputationDelay_IWORK_ez.Head[0] < (_rtDW->ComputationDelay_IWORK_ez.CircularBufSize[0]-1)) ? (_rtDW->ComputationDelay_IWORK_ez.Head[0]+1) : 0);

      if (_rtDW->ComputationDelay_IWORK_ez.Head[0] == _rtDW->ComputationDelay_IWORK_ez.Tail[0]) {
        
          
          
	  if (!benchmark_no_taylor_acc_rt_TDelayUpdateTailOrGrowBuf( &_rtDW->ComputationDelay_IWORK_ez.CircularBufSize[0], &_rtDW->ComputationDelay_IWORK_ez.Tail[0], &_rtDW->ComputationDelay_IWORK_ez.Head[0], &_rtDW->ComputationDelay_IWORK_ez.Last[0], simTime - _rtP->P_38, tBuffer, uBuffer, (NULL), (boolean_T)0, false, &_rtDW->ComputationDelay_IWORK_ez.MaxNewBufSize)) {
            ssSetErrorStatus(S, "tdelay memory allocation error");
            return;
          }
      }
      
      (*tBuffer++)[_rtDW->ComputationDelay_IWORK_ez.Head[0]] = simTime;
        (*uBuffer++)[_rtDW->ComputationDelay_IWORK_ez.Head[0]] = _rtB->B_53_1023_0;
      
      _rtDW->ComputationDelay_IWORK_ez.Head[1] = ((_rtDW->ComputationDelay_IWORK_ez.Head[1] < (_rtDW->ComputationDelay_IWORK_ez.CircularBufSize[1]-1)) ? (_rtDW->ComputationDelay_IWORK_ez.Head[1]+1) : 0);

      if (_rtDW->ComputationDelay_IWORK_ez.Head[1] == _rtDW->ComputationDelay_IWORK_ez.Tail[1]) {
        
          
          
	  if (!benchmark_no_taylor_acc_rt_TDelayUpdateTailOrGrowBuf( &_rtDW->ComputationDelay_IWORK_ez.CircularBufSize[1], &_rtDW->ComputationDelay_IWORK_ez.Tail[1], &_rtDW->ComputationDelay_IWORK_ez.Head[1], &_rtDW->ComputationDelay_IWORK_ez.Last[1], simTime - _rtP->P_38, tBuffer, uBuffer, (NULL), (boolean_T)0, false, &_rtDW->ComputationDelay_IWORK_ez.MaxNewBufSize)) {
            ssSetErrorStatus(S, "tdelay memory allocation error");
            return;
          }
      }
      
      (*tBuffer++)[_rtDW->ComputationDelay_IWORK_ez.Head[1]] = simTime;
        (*uBuffer++)[_rtDW->ComputationDelay_IWORK_ez.Head[1]] = _rtB->B_53_1014_0;
      
      _rtDW->ComputationDelay_IWORK_ez.Head[2] = ((_rtDW->ComputationDelay_IWORK_ez.Head[2] < (_rtDW->ComputationDelay_IWORK_ez.CircularBufSize[2]-1)) ? (_rtDW->ComputationDelay_IWORK_ez.Head[2]+1) : 0);

      if (_rtDW->ComputationDelay_IWORK_ez.Head[2] == _rtDW->ComputationDelay_IWORK_ez.Tail[2]) {
        
          
          
	  if (!benchmark_no_taylor_acc_rt_TDelayUpdateTailOrGrowBuf( &_rtDW->ComputationDelay_IWORK_ez.CircularBufSize[2], &_rtDW->ComputationDelay_IWORK_ez.Tail[2], &_rtDW->ComputationDelay_IWORK_ez.Head[2], &_rtDW->ComputationDelay_IWORK_ez.Last[2], simTime - _rtP->P_38, tBuffer, uBuffer, (NULL), (boolean_T)0, false, &_rtDW->ComputationDelay_IWORK_ez.MaxNewBufSize)) {
            ssSetErrorStatus(S, "tdelay memory allocation error");
            return;
          }
      }
      
      (*tBuffer++)[_rtDW->ComputationDelay_IWORK_ez.Head[2]] = simTime;
        (*uBuffer++)[_rtDW->ComputationDelay_IWORK_ez.Head[2]] = _rtB->B_53_1019_0;
      
      _rtDW->ComputationDelay_IWORK_ez.Head[3] = ((_rtDW->ComputationDelay_IWORK_ez.Head[3] < (_rtDW->ComputationDelay_IWORK_ez.CircularBufSize[3]-1)) ? (_rtDW->ComputationDelay_IWORK_ez.Head[3]+1) : 0);

      if (_rtDW->ComputationDelay_IWORK_ez.Head[3] == _rtDW->ComputationDelay_IWORK_ez.Tail[3]) {
        
          
          
	  if (!benchmark_no_taylor_acc_rt_TDelayUpdateTailOrGrowBuf( &_rtDW->ComputationDelay_IWORK_ez.CircularBufSize[3], &_rtDW->ComputationDelay_IWORK_ez.Tail[3], &_rtDW->ComputationDelay_IWORK_ez.Head[3], &_rtDW->ComputationDelay_IWORK_ez.Last[3], simTime - _rtP->P_38, tBuffer, uBuffer, (NULL), (boolean_T)0, false, &_rtDW->ComputationDelay_IWORK_ez.MaxNewBufSize)) {
            ssSetErrorStatus(S, "tdelay memory allocation error");
            return;
          }
      }
      
      (*tBuffer)[_rtDW->ComputationDelay_IWORK_ez.Head[3]] = simTime;
        (*uBuffer)[_rtDW->ComputationDelay_IWORK_ez.Head[3]] = _rtB->B_53_1020_0;
  }
 /* Update for TransportDelay: '<S43>/Computation Delay' */            {
    real_T **uBuffer = (real_T**)&_rtDW->ComputationDelay_PWORK_dy.TUbufferPtrs[0];
    real_T **tBuffer = (real_T**)&_rtDW->ComputationDelay_PWORK_dy.TUbufferPtrs[4];
       
    real_T simTime   = ssGetT(S);
    
    
        

      
      _rtDW->ComputationDelay_IWORK_e0.Head[0] = ((_rtDW->ComputationDelay_IWORK_e0.Head[0] < (_rtDW->ComputationDelay_IWORK_e0.CircularBufSize[0]-1)) ? (_rtDW->ComputationDelay_IWORK_e0.Head[0]+1) : 0);

      if (_rtDW->ComputationDelay_IWORK_e0.Head[0] == _rtDW->ComputationDelay_IWORK_e0.Tail[0]) {
        
          
          
	  if (!benchmark_no_taylor_acc_rt_TDelayUpdateTailOrGrowBuf( &_rtDW->ComputationDelay_IWORK_e0.CircularBufSize[0], &_rtDW->ComputationDelay_IWORK_e0.Tail[0], &_rtDW->ComputationDelay_IWORK_e0.Head[0], &_rtDW->ComputationDelay_IWORK_e0.Last[0], simTime - _rtP->P_40, tBuffer, uBuffer, (NULL), (boolean_T)0, false, &_rtDW->ComputationDelay_IWORK_e0.MaxNewBufSize)) {
            ssSetErrorStatus(S, "tdelay memory allocation error");
            return;
          }
      }
      
      (*tBuffer++)[_rtDW->ComputationDelay_IWORK_e0.Head[0]] = simTime;
        (*uBuffer++)[_rtDW->ComputationDelay_IWORK_e0.Head[0]] = _rtB->B_53_575_0;
      
      _rtDW->ComputationDelay_IWORK_e0.Head[1] = ((_rtDW->ComputationDelay_IWORK_e0.Head[1] < (_rtDW->ComputationDelay_IWORK_e0.CircularBufSize[1]-1)) ? (_rtDW->ComputationDelay_IWORK_e0.Head[1]+1) : 0);

      if (_rtDW->ComputationDelay_IWORK_e0.Head[1] == _rtDW->ComputationDelay_IWORK_e0.Tail[1]) {
        
          
          
	  if (!benchmark_no_taylor_acc_rt_TDelayUpdateTailOrGrowBuf( &_rtDW->ComputationDelay_IWORK_e0.CircularBufSize[1], &_rtDW->ComputationDelay_IWORK_e0.Tail[1], &_rtDW->ComputationDelay_IWORK_e0.Head[1], &_rtDW->ComputationDelay_IWORK_e0.Last[1], simTime - _rtP->P_40, tBuffer, uBuffer, (NULL), (boolean_T)0, false, &_rtDW->ComputationDelay_IWORK_e0.MaxNewBufSize)) {
            ssSetErrorStatus(S, "tdelay memory allocation error");
            return;
          }
      }
      
      (*tBuffer++)[_rtDW->ComputationDelay_IWORK_e0.Head[1]] = simTime;
        (*uBuffer++)[_rtDW->ComputationDelay_IWORK_e0.Head[1]] = _rtB->B_53_566_0;
      
      _rtDW->ComputationDelay_IWORK_e0.Head[2] = ((_rtDW->ComputationDelay_IWORK_e0.Head[2] < (_rtDW->ComputationDelay_IWORK_e0.CircularBufSize[2]-1)) ? (_rtDW->ComputationDelay_IWORK_e0.Head[2]+1) : 0);

      if (_rtDW->ComputationDelay_IWORK_e0.Head[2] == _rtDW->ComputationDelay_IWORK_e0.Tail[2]) {
        
          
          
	  if (!benchmark_no_taylor_acc_rt_TDelayUpdateTailOrGrowBuf( &_rtDW->ComputationDelay_IWORK_e0.CircularBufSize[2], &_rtDW->ComputationDelay_IWORK_e0.Tail[2], &_rtDW->ComputationDelay_IWORK_e0.Head[2], &_rtDW->ComputationDelay_IWORK_e0.Last[2], simTime - _rtP->P_40, tBuffer, uBuffer, (NULL), (boolean_T)0, false, &_rtDW->ComputationDelay_IWORK_e0.MaxNewBufSize)) {
            ssSetErrorStatus(S, "tdelay memory allocation error");
            return;
          }
      }
      
      (*tBuffer++)[_rtDW->ComputationDelay_IWORK_e0.Head[2]] = simTime;
        (*uBuffer++)[_rtDW->ComputationDelay_IWORK_e0.Head[2]] = _rtB->B_53_571_0;
      
      _rtDW->ComputationDelay_IWORK_e0.Head[3] = ((_rtDW->ComputationDelay_IWORK_e0.Head[3] < (_rtDW->ComputationDelay_IWORK_e0.CircularBufSize[3]-1)) ? (_rtDW->ComputationDelay_IWORK_e0.Head[3]+1) : 0);

      if (_rtDW->ComputationDelay_IWORK_e0.Head[3] == _rtDW->ComputationDelay_IWORK_e0.Tail[3]) {
        
          
          
	  if (!benchmark_no_taylor_acc_rt_TDelayUpdateTailOrGrowBuf( &_rtDW->ComputationDelay_IWORK_e0.CircularBufSize[3], &_rtDW->ComputationDelay_IWORK_e0.Tail[3], &_rtDW->ComputationDelay_IWORK_e0.Head[3], &_rtDW->ComputationDelay_IWORK_e0.Last[3], simTime - _rtP->P_40, tBuffer, uBuffer, (NULL), (boolean_T)0, false, &_rtDW->ComputationDelay_IWORK_e0.MaxNewBufSize)) {
            ssSetErrorStatus(S, "tdelay memory allocation error");
            return;
          }
      }
      
      (*tBuffer)[_rtDW->ComputationDelay_IWORK_e0.Head[3]] = simTime;
        (*uBuffer)[_rtDW->ComputationDelay_IWORK_e0.Head[3]] = _rtB->B_53_572_0;
  }
 /* Update for TransportDelay: '<S4>/Reference delay' */            {
    real_T **uBuffer = (real_T**)&_rtDW->Referencedelay_PWORK.TUbufferPtrs[0];
    real_T **tBuffer = (real_T**)&_rtDW->Referencedelay_PWORK.TUbufferPtrs[1];
       
    real_T simTime   = ssGetT(S);
    
    
        

      
      _rtDW->Referencedelay_IWORK.Head = ((_rtDW->Referencedelay_IWORK.Head < (_rtDW->Referencedelay_IWORK.CircularBufSize-1)) ? (_rtDW->Referencedelay_IWORK.Head+1) : 0);

      if (_rtDW->Referencedelay_IWORK.Head == _rtDW->Referencedelay_IWORK.Tail) {
        
          
          
	  if (!benchmark_no_taylor_acc_rt_TDelayUpdateTailOrGrowBuf( &_rtDW->Referencedelay_IWORK.CircularBufSize, &_rtDW->Referencedelay_IWORK.Tail, &_rtDW->Referencedelay_IWORK.Head, &_rtDW->Referencedelay_IWORK.Last, simTime - _rtP->P_42, tBuffer, uBuffer, (NULL), (boolean_T)0, false, &_rtDW->Referencedelay_IWORK.MaxNewBufSize)) {
            ssSetErrorStatus(S, "tdelay memory allocation error");
            return;
          }
      }
      
      (*tBuffer)[_rtDW->Referencedelay_IWORK.Head] = simTime;
        (*uBuffer)[_rtDW->Referencedelay_IWORK.Head] = _rtB->B_1_0_1;    
  }
 /* 0: INTG_NORMAL     1: INTG_LEAVING_UPPER_SAT  2: INTG_LEAVING_LOWER_SAT */
/* 3: INTG_UPPER_SAT  4: INTG_LOWER_SAT */
if (_rtX->Integrator_CSTATE == _rtP->P_45) {
    switch (_rtDW->Integrator_MODE) {
      case 3:
        if (_rtB->B_53_422_0 < 0.0) {
            ssSetSolverNeedsReset(S);
            _rtDW->Integrator_MODE = 1;
        }
        break;
      case 1:
        if (_rtB->B_53_422_0 >= 0.0) {
            _rtDW->Integrator_MODE = 3;
            ssSetSolverNeedsReset(S);
        }
        break;
      default:
        ssSetSolverNeedsReset(S);
        if (_rtB->B_53_422_0 < 0.0) {
            _rtDW->Integrator_MODE = 1;
        } else {
            _rtDW->Integrator_MODE = 3;
        }
        break;
    }
} else if (_rtX->Integrator_CSTATE == _rtP->P_46) {
    switch (_rtDW->Integrator_MODE) {
      case 4:
        if (_rtB->B_53_422_0 > 0.0) {
            ssSetSolverNeedsReset(S);
            _rtDW->Integrator_MODE = 2;
        }
        break;
      case 2:
        if (_rtB->B_53_422_0 <= 0.0) {
            _rtDW->Integrator_MODE = 4;
            ssSetSolverNeedsReset(S);
        }
        break;
      default:
        ssSetSolverNeedsReset(S);
        if (_rtB->B_53_422_0 > 0.0) {
            _rtDW->Integrator_MODE = 2;
        } else {
            _rtDW->Integrator_MODE = 4;
        }
        break;
    }
} else {
    _rtDW->Integrator_MODE = 0;
}
if (ssIsSampleHit(S, 3, 0)) {
    _rtDW->Output_DSTATE = _rtB->B_53_1060_0;
    for (idxDelay = 0; idxDelay < 39; idxDelay++) {
        _rtDW->wcDelay2_DSTATE[(uint32_T)idxDelay] = _rtDW->wcDelay2_DSTATE[idxDelay + 1U];
    }
    _rtDW->wcDelay2_DSTATE[39] = _rtB->B_33_0_1[1];
    for (idxDelay = 0; idxDelay < 79; idxDelay++) {
        _rtDW->wcDelay3_DSTATE[(uint32_T)idxDelay] = _rtDW->wcDelay3_DSTATE[idxDelay + 1U];
    }
    _rtDW->wcDelay3_DSTATE[79] = _rtB->B_33_0_1[2];
    for (idxDelay = 0; idxDelay < 119; idxDelay++) {
        _rtDW->wcDelay4_DSTATE[(uint32_T)idxDelay] = _rtDW->wcDelay4_DSTATE[idxDelay + 1U];
    }
    _rtDW->wcDelay4_DSTATE[119] = _rtB->B_33_0_1[3];
    for (idxDelay = 0; idxDelay < 19; idxDelay++) {
        _rtDW->wcDelay5_DSTATE[(uint32_T)idxDelay] = _rtDW->wcDelay5_DSTATE[idxDelay + 1U];
    }
    _rtDW->wcDelay5_DSTATE[19] = _rtB->B_33_0_1[4];
    for (idxDelay = 0; idxDelay < 59; idxDelay++) {
        _rtDW->wcDelay6_DSTATE[(uint32_T)idxDelay] = _rtDW->wcDelay6_DSTATE[idxDelay + 1U];
    }
    _rtDW->wcDelay6_DSTATE[59] = _rtB->B_33_0_1[5];
    for (idxDelay = 0; idxDelay < 99; idxDelay++) {
        _rtDW->wcDelay7_DSTATE[(uint32_T)idxDelay] = _rtDW->wcDelay7_DSTATE[idxDelay + 1U];
    }
    _rtDW->wcDelay7_DSTATE[99] = _rtB->B_33_0_1[6];
    for (idxDelay = 0; idxDelay < 39; idxDelay++) {
        _rtDW->wcDelay8_DSTATE[(uint32_T)idxDelay] = _rtDW->wcDelay8_DSTATE[idxDelay + 1U];
    }
    _rtDW->wcDelay8_DSTATE[39] = _rtB->B_33_0_1[7];
    for (idxDelay = 0; idxDelay < 79; idxDelay++) {
        _rtDW->wcDelay9_DSTATE[(uint32_T)idxDelay] = _rtDW->wcDelay9_DSTATE[idxDelay + 1U];
    }
    _rtDW->wcDelay9_DSTATE[79] = _rtB->B_33_0_1[8];
    for (idxDelay = 0; idxDelay < 119; idxDelay++) {
        _rtDW->wcDelay10_DSTATE[(uint32_T)idxDelay] = _rtDW->wcDelay10_DSTATE[idxDelay + 1U];
    }
    _rtDW->wcDelay10_DSTATE[119] = _rtB->B_33_0_1[9];
    for (idxDelay = 0; idxDelay < 39; idxDelay++) {
        _rtDW->wcDelay3_DSTATE_g[(uint32_T)idxDelay] = _rtDW->wcDelay3_DSTATE_g[idxDelay + 1U];
    }
    _rtDW->wcDelay3_DSTATE_g[39] = _rtB->B_35_0_1[2];
    for (idxDelay = 0; idxDelay < 79; idxDelay++) {
        _rtDW->wcDelay4_DSTATE_j[(uint32_T)idxDelay] = _rtDW->wcDelay4_DSTATE_j[idxDelay + 1U];
    }
    _rtDW->wcDelay4_DSTATE_j[79] = _rtB->B_35_0_1[3];
    for (idxDelay = 0; idxDelay < 19; idxDelay++) {
        _rtDW->wcDelay6_DSTATE_i[(uint32_T)idxDelay] = _rtDW->wcDelay6_DSTATE_i[idxDelay + 1U];
    }
    _rtDW->wcDelay6_DSTATE_i[19] = _rtB->B_35_0_1[5];
    for (idxDelay = 0; idxDelay < 59; idxDelay++) {
        _rtDW->wcDelay7_DSTATE_a[(uint32_T)idxDelay] = _rtDW->wcDelay7_DSTATE_a[idxDelay + 1U];
    }
    _rtDW->wcDelay7_DSTATE_a[59] = _rtB->B_35_0_1[6];
    for (idxDelay = 0; idxDelay < 39; idxDelay++) {
        _rtDW->wcDelay9_DSTATE_c[(uint32_T)idxDelay] = _rtDW->wcDelay9_DSTATE_c[idxDelay + 1U];
    }
    _rtDW->wcDelay9_DSTATE_c[39] = _rtB->B_35_0_1[8];
    for (idxDelay = 0; idxDelay < 79; idxDelay++) {
        _rtDW->wcDelay10_DSTATE_e[(uint32_T)idxDelay] = _rtDW->wcDelay10_DSTATE_e[idxDelay + 1U];
    }
    _rtDW->wcDelay10_DSTATE_e[79] = _rtB->B_35_0_1[9];
    for (idxDelay = 0; idxDelay < 39; idxDelay++) {
        _rtDW->wcDelay4_DSTATE_g[(uint32_T)idxDelay] = _rtDW->wcDelay4_DSTATE_g[idxDelay + 1U];
    }
    _rtDW->wcDelay4_DSTATE_g[39] = _rtB->B_36_0_1[3];
    for (idxDelay = 0; idxDelay < 19; idxDelay++) {
        _rtDW->wcDelay7_DSTATE_j[(uint32_T)idxDelay] = _rtDW->wcDelay7_DSTATE_j[idxDelay + 1U];
    }
    _rtDW->wcDelay7_DSTATE_j[19] = _rtB->B_36_0_1[6];
    for (idxDelay = 0; idxDelay < 39; idxDelay++) {
        _rtDW->wcDelay10_DSTATE_f[(uint32_T)idxDelay] = _rtDW->wcDelay10_DSTATE_f[idxDelay + 1U];
    }
    _rtDW->wcDelay10_DSTATE_f[39] = _rtB->B_36_0_1[9];
    for (idxDelay = 0; idxDelay < 19; idxDelay++) {
        _rtDW->wcDelay2_DSTATE_e[(uint32_T)idxDelay] = _rtDW->wcDelay2_DSTATE_e[idxDelay + 1U];
    }
    _rtDW->wcDelay2_DSTATE_e[19] = _rtB->B_38_0_1[1];
    for (idxDelay = 0; idxDelay < 59; idxDelay++) {
        _rtDW->wcDelay3_DSTATE_gu[(uint32_T)idxDelay] = _rtDW->wcDelay3_DSTATE_gu[idxDelay + 1U];
    }
    _rtDW->wcDelay3_DSTATE_gu[59] = _rtB->B_38_0_1[2];
    for (idxDelay = 0; idxDelay < 99; idxDelay++) {
        _rtDW->wcDelay4_DSTATE_e[(uint32_T)idxDelay] = _rtDW->wcDelay4_DSTATE_e[idxDelay + 1U];
    }
    _rtDW->wcDelay4_DSTATE_e[99] = _rtB->B_38_0_1[3];
    for (idxDelay = 0; idxDelay < 39; idxDelay++) {
        _rtDW->wcDelay6_DSTATE_o[(uint32_T)idxDelay] = _rtDW->wcDelay6_DSTATE_o[idxDelay + 1U];
    }
    _rtDW->wcDelay6_DSTATE_o[39] = _rtB->B_38_0_1[5];
    for (idxDelay = 0; idxDelay < 79; idxDelay++) {
        _rtDW->wcDelay7_DSTATE_az[(uint32_T)idxDelay] = _rtDW->wcDelay7_DSTATE_az[idxDelay + 1U];
    }
    _rtDW->wcDelay7_DSTATE_az[79] = _rtB->B_38_0_1[6];
    for (idxDelay = 0; idxDelay < 19; idxDelay++) {
        _rtDW->wcDelay8_DSTATE_f[(uint32_T)idxDelay] = _rtDW->wcDelay8_DSTATE_f[idxDelay + 1U];
    }
    _rtDW->wcDelay8_DSTATE_f[19] = _rtB->B_38_0_1[7];
    for (idxDelay = 0; idxDelay < 59; idxDelay++) {
        _rtDW->wcDelay9_DSTATE_n[(uint32_T)idxDelay] = _rtDW->wcDelay9_DSTATE_n[idxDelay + 1U];
    }
    _rtDW->wcDelay9_DSTATE_n[59] = _rtB->B_38_0_1[8];
    for (idxDelay = 0; idxDelay < 99; idxDelay++) {
        _rtDW->wcDelay10_DSTATE_h[(uint32_T)idxDelay] = _rtDW->wcDelay10_DSTATE_h[idxDelay + 1U];
    }
    _rtDW->wcDelay10_DSTATE_h[99] = _rtB->B_38_0_1[9];
    for (idxDelay = 0; idxDelay < 19; idxDelay++) {
        _rtDW->wcDelay3_DSTATE_p[(uint32_T)idxDelay] = _rtDW->wcDelay3_DSTATE_p[idxDelay + 1U];
    }
    _rtDW->wcDelay3_DSTATE_p[19] = _rtB->B_39_0_1[2];
    for (idxDelay = 0; idxDelay < 59; idxDelay++) {
        _rtDW->wcDelay4_DSTATE_n[(uint32_T)idxDelay] = _rtDW->wcDelay4_DSTATE_n[idxDelay + 1U];
    }
    _rtDW->wcDelay4_DSTATE_n[59] = _rtB->B_39_0_1[3];
    for (idxDelay = 0; idxDelay < 39; idxDelay++) {
        _rtDW->wcDelay7_DSTATE_l[(uint32_T)idxDelay] = _rtDW->wcDelay7_DSTATE_l[idxDelay + 1U];
    }
    _rtDW->wcDelay7_DSTATE_l[39] = _rtB->B_39_0_1[6];
    for (idxDelay = 0; idxDelay < 19; idxDelay++) {
        _rtDW->wcDelay9_DSTATE_h[(uint32_T)idxDelay] = _rtDW->wcDelay9_DSTATE_h[idxDelay + 1U];
    }
    _rtDW->wcDelay9_DSTATE_h[19] = _rtB->B_39_0_1[8];
    for (idxDelay = 0; idxDelay < 59; idxDelay++) {
        _rtDW->wcDelay10_DSTATE_o[(uint32_T)idxDelay] = _rtDW->wcDelay10_DSTATE_o[idxDelay + 1U];
    }
    _rtDW->wcDelay10_DSTATE_o[59] = _rtB->B_39_0_1[9];
    for (idxDelay = 0; idxDelay < 19; idxDelay++) {
        _rtDW->wcDelay4_DSTATE_no[(uint32_T)idxDelay] = _rtDW->wcDelay4_DSTATE_no[idxDelay + 1U];
        _rtDW->wcDelay10_DSTATE_i[(uint32_T)idxDelay] = _rtDW->wcDelay10_DSTATE_i[idxDelay + 1U];
    }
    _rtDW->wcDelay4_DSTATE_no[19] = _rtB->B_40_0_1[3];
    _rtDW->wcDelay10_DSTATE_i[19] = _rtB->B_40_0_1[9];
    for (idxDelay = 0; idxDelay < 39; idxDelay++) {
        _rtDW->wcDelay3_DSTATE_i[(uint32_T)idxDelay] = _rtDW->wcDelay3_DSTATE_i[idxDelay + 1U];
    }
    _rtDW->wcDelay3_DSTATE_i[39] = _rtB->B_41_0_1[2];
    for (idxDelay = 0; idxDelay < 79; idxDelay++) {
        _rtDW->wcDelay4_DSTATE_o[(uint32_T)idxDelay] = _rtDW->wcDelay4_DSTATE_o[idxDelay + 1U];
    }
    _rtDW->wcDelay4_DSTATE_o[79] = _rtB->B_41_0_1[3];
    for (idxDelay = 0; idxDelay < 19; idxDelay++) {
        _rtDW->wcDelay6_DSTATE_og[(uint32_T)idxDelay] = _rtDW->wcDelay6_DSTATE_og[idxDelay + 1U];
    }
    _rtDW->wcDelay6_DSTATE_og[19] = _rtB->B_41_0_1[5];
    for (idxDelay = 0; idxDelay < 59; idxDelay++) {
        _rtDW->wcDelay7_DSTATE_an[(uint32_T)idxDelay] = _rtDW->wcDelay7_DSTATE_an[idxDelay + 1U];
    }
    _rtDW->wcDelay7_DSTATE_an[59] = _rtB->B_41_0_1[6];
    for (idxDelay = 0; idxDelay < 39; idxDelay++) {
        _rtDW->wcDelay9_DSTATE_j[(uint32_T)idxDelay] = _rtDW->wcDelay9_DSTATE_j[idxDelay + 1U];
    }
    _rtDW->wcDelay9_DSTATE_j[39] = _rtB->B_41_0_1[8];
    for (idxDelay = 0; idxDelay < 79; idxDelay++) {
        _rtDW->wcDelay10_DSTATE_g[(uint32_T)idxDelay] = _rtDW->wcDelay10_DSTATE_g[idxDelay + 1U];
    }
    _rtDW->wcDelay10_DSTATE_g[79] = _rtB->B_41_0_1[9];
    for (idxDelay = 0; idxDelay < 39; idxDelay++) {
        _rtDW->wcDelay4_DSTATE_jo[(uint32_T)idxDelay] = _rtDW->wcDelay4_DSTATE_jo[idxDelay + 1U];
    }
    _rtDW->wcDelay4_DSTATE_jo[39] = _rtB->B_42_0_1[3];
    for (idxDelay = 0; idxDelay < 19; idxDelay++) {
        _rtDW->wcDelay7_DSTATE_d[(uint32_T)idxDelay] = _rtDW->wcDelay7_DSTATE_d[idxDelay + 1U];
    }
    _rtDW->wcDelay7_DSTATE_d[19] = _rtB->B_42_0_1[6];
    for (idxDelay = 0; idxDelay < 39; idxDelay++) {
        _rtDW->wcDelay10_DSTATE_ik[(uint32_T)idxDelay] = _rtDW->wcDelay10_DSTATE_ik[idxDelay + 1U];
        _rtDW->wdDelay2_DSTATE[(uint32_T)idxDelay] = _rtDW->wdDelay2_DSTATE[idxDelay + 1U];
    }
    _rtDW->wcDelay10_DSTATE_ik[39] = _rtB->B_42_0_1[9];
    _rtDW->wdDelay2_DSTATE[39] = _rtB->B_33_0_2[1];
    for (idxDelay = 0; idxDelay < 79; idxDelay++) {
        _rtDW->wdDelay3_DSTATE[(uint32_T)idxDelay] = _rtDW->wdDelay3_DSTATE[idxDelay + 1U];
    }
    _rtDW->wdDelay3_DSTATE[79] = _rtB->B_33_0_2[2];
    for (idxDelay = 0; idxDelay < 119; idxDelay++) {
        _rtDW->wdDelay4_DSTATE[(uint32_T)idxDelay] = _rtDW->wdDelay4_DSTATE[idxDelay + 1U];
    }
    _rtDW->wdDelay4_DSTATE[119] = _rtB->B_33_0_2[3];
    for (idxDelay = 0; idxDelay < 19; idxDelay++) {
        _rtDW->wdDelay5_DSTATE[(uint32_T)idxDelay] = _rtDW->wdDelay5_DSTATE[idxDelay + 1U];
    }
    _rtDW->wdDelay5_DSTATE[19] = _rtB->B_33_0_2[4];
    for (idxDelay = 0; idxDelay < 59; idxDelay++) {
        _rtDW->wdDelay6_DSTATE[(uint32_T)idxDelay] = _rtDW->wdDelay6_DSTATE[idxDelay + 1U];
    }
    _rtDW->wdDelay6_DSTATE[59] = _rtB->B_33_0_2[5];
    for (idxDelay = 0; idxDelay < 99; idxDelay++) {
        _rtDW->wdDelay7_DSTATE[(uint32_T)idxDelay] = _rtDW->wdDelay7_DSTATE[idxDelay + 1U];
    }
    _rtDW->wdDelay7_DSTATE[99] = _rtB->B_33_0_2[6];
    for (idxDelay = 0; idxDelay < 39; idxDelay++) {
        _rtDW->wdDelay8_DSTATE[(uint32_T)idxDelay] = _rtDW->wdDelay8_DSTATE[idxDelay + 1U];
    }
    _rtDW->wdDelay8_DSTATE[39] = _rtB->B_33_0_2[7];
    for (idxDelay = 0; idxDelay < 79; idxDelay++) {
        _rtDW->wdDelay9_DSTATE[(uint32_T)idxDelay] = _rtDW->wdDelay9_DSTATE[idxDelay + 1U];
    }
    _rtDW->wdDelay9_DSTATE[79] = _rtB->B_33_0_2[8];
    for (idxDelay = 0; idxDelay < 119; idxDelay++) {
        _rtDW->wdDelay10_DSTATE[(uint32_T)idxDelay] = _rtDW->wdDelay10_DSTATE[idxDelay + 1U];
    }
    _rtDW->wdDelay10_DSTATE[119] = _rtB->B_33_0_2[9];
    for (idxDelay = 0; idxDelay < 39; idxDelay++) {
        _rtDW->wdDelay3_DSTATE_g[(uint32_T)idxDelay] = _rtDW->wdDelay3_DSTATE_g[idxDelay + 1U];
    }
    _rtDW->wdDelay3_DSTATE_g[39] = _rtB->B_35_0_2[2];
    for (idxDelay = 0; idxDelay < 79; idxDelay++) {
        _rtDW->wdDelay4_DSTATE_g[(uint32_T)idxDelay] = _rtDW->wdDelay4_DSTATE_g[idxDelay + 1U];
    }
    _rtDW->wdDelay4_DSTATE_g[79] = _rtB->B_35_0_2[3];
    for (idxDelay = 0; idxDelay < 19; idxDelay++) {
        _rtDW->wdDelay6_DSTATE_m[(uint32_T)idxDelay] = _rtDW->wdDelay6_DSTATE_m[idxDelay + 1U];
    }
    _rtDW->wdDelay6_DSTATE_m[19] = _rtB->B_35_0_2[5];
    for (idxDelay = 0; idxDelay < 59; idxDelay++) {
        _rtDW->wdDelay7_DSTATE_n[(uint32_T)idxDelay] = _rtDW->wdDelay7_DSTATE_n[idxDelay + 1U];
    }
    _rtDW->wdDelay7_DSTATE_n[59] = _rtB->B_35_0_2[6];
    for (idxDelay = 0; idxDelay < 39; idxDelay++) {
        _rtDW->wdDelay9_DSTATE_b[(uint32_T)idxDelay] = _rtDW->wdDelay9_DSTATE_b[idxDelay + 1U];
    }
    _rtDW->wdDelay9_DSTATE_b[39] = _rtB->B_35_0_2[8];
    for (idxDelay = 0; idxDelay < 79; idxDelay++) {
        _rtDW->wdDelay10_DSTATE_a[(uint32_T)idxDelay] = _rtDW->wdDelay10_DSTATE_a[idxDelay + 1U];
    }
    _rtDW->wdDelay10_DSTATE_a[79] = _rtB->B_35_0_2[9];
    for (idxDelay = 0; idxDelay < 39; idxDelay++) {
        _rtDW->wdDelay4_DSTATE_n[(uint32_T)idxDelay] = _rtDW->wdDelay4_DSTATE_n[idxDelay + 1U];
    }
    _rtDW->wdDelay4_DSTATE_n[39] = _rtB->B_36_0_2[3];
    for (idxDelay = 0; idxDelay < 19; idxDelay++) {
        _rtDW->wdDelay7_DSTATE_e[(uint32_T)idxDelay] = _rtDW->wdDelay7_DSTATE_e[idxDelay + 1U];
    }
    _rtDW->wdDelay7_DSTATE_e[19] = _rtB->B_36_0_2[6];
    for (idxDelay = 0; idxDelay < 39; idxDelay++) {
        _rtDW->wdDelay10_DSTATE_a3[(uint32_T)idxDelay] = _rtDW->wdDelay10_DSTATE_a3[idxDelay + 1U];
    }
    _rtDW->wdDelay10_DSTATE_a3[39] = _rtB->B_36_0_2[9];
    for (idxDelay = 0; idxDelay < 19; idxDelay++) {
        _rtDW->wdDelay2_DSTATE_m[(uint32_T)idxDelay] = _rtDW->wdDelay2_DSTATE_m[idxDelay + 1U];
    }
    _rtDW->wdDelay2_DSTATE_m[19] = _rtB->B_38_0_2[1];
    for (idxDelay = 0; idxDelay < 59; idxDelay++) {
        _rtDW->wdDelay3_DSTATE_k[(uint32_T)idxDelay] = _rtDW->wdDelay3_DSTATE_k[idxDelay + 1U];
    }
    _rtDW->wdDelay3_DSTATE_k[59] = _rtB->B_38_0_2[2];
    for (idxDelay = 0; idxDelay < 99; idxDelay++) {
        _rtDW->wdDelay4_DSTATE_nd[(uint32_T)idxDelay] = _rtDW->wdDelay4_DSTATE_nd[idxDelay + 1U];
    }
    _rtDW->wdDelay4_DSTATE_nd[99] = _rtB->B_38_0_2[3];
    for (idxDelay = 0; idxDelay < 39; idxDelay++) {
        _rtDW->wdDelay6_DSTATE_h[(uint32_T)idxDelay] = _rtDW->wdDelay6_DSTATE_h[idxDelay + 1U];
    }
    _rtDW->wdDelay6_DSTATE_h[39] = _rtB->B_38_0_2[5];
    for (idxDelay = 0; idxDelay < 79; idxDelay++) {
        _rtDW->wdDelay7_DSTATE_h[(uint32_T)idxDelay] = _rtDW->wdDelay7_DSTATE_h[idxDelay + 1U];
    }
    _rtDW->wdDelay7_DSTATE_h[79] = _rtB->B_38_0_2[6];
    for (idxDelay = 0; idxDelay < 19; idxDelay++) {
        _rtDW->wdDelay8_DSTATE_l[(uint32_T)idxDelay] = _rtDW->wdDelay8_DSTATE_l[idxDelay + 1U];
    }
    _rtDW->wdDelay8_DSTATE_l[19] = _rtB->B_38_0_2[7];
    for (idxDelay = 0; idxDelay < 59; idxDelay++) {
        _rtDW->wdDelay9_DSTATE_k[(uint32_T)idxDelay] = _rtDW->wdDelay9_DSTATE_k[idxDelay + 1U];
    }
    _rtDW->wdDelay9_DSTATE_k[59] = _rtB->B_38_0_2[8];
    for (idxDelay = 0; idxDelay < 99; idxDelay++) {
        _rtDW->wdDelay10_DSTATE_i[(uint32_T)idxDelay] = _rtDW->wdDelay10_DSTATE_i[idxDelay + 1U];
    }
    _rtDW->wdDelay10_DSTATE_i[99] = _rtB->B_38_0_2[9];
    for (idxDelay = 0; idxDelay < 19; idxDelay++) {
        _rtDW->wdDelay3_DSTATE_a[(uint32_T)idxDelay] = _rtDW->wdDelay3_DSTATE_a[idxDelay + 1U];
    }
    _rtDW->wdDelay3_DSTATE_a[19] = _rtB->B_39_0_2[2];
    for (idxDelay = 0; idxDelay < 59; idxDelay++) {
        _rtDW->wdDelay4_DSTATE_m[(uint32_T)idxDelay] = _rtDW->wdDelay4_DSTATE_m[idxDelay + 1U];
    }
    _rtDW->wdDelay4_DSTATE_m[59] = _rtB->B_39_0_2[3];
    for (idxDelay = 0; idxDelay < 39; idxDelay++) {
        _rtDW->wdDelay7_DSTATE_a[(uint32_T)idxDelay] = _rtDW->wdDelay7_DSTATE_a[idxDelay + 1U];
    }
    _rtDW->wdDelay7_DSTATE_a[39] = _rtB->B_39_0_2[6];
    for (idxDelay = 0; idxDelay < 19; idxDelay++) {
        _rtDW->wdDelay9_DSTATE_n[(uint32_T)idxDelay] = _rtDW->wdDelay9_DSTATE_n[idxDelay + 1U];
    }
    _rtDW->wdDelay9_DSTATE_n[19] = _rtB->B_39_0_2[8];
    for (idxDelay = 0; idxDelay < 59; idxDelay++) {
        _rtDW->wdDelay10_DSTATE_aw[(uint32_T)idxDelay] = _rtDW->wdDelay10_DSTATE_aw[idxDelay + 1U];
    }
    _rtDW->wdDelay10_DSTATE_aw[59] = _rtB->B_39_0_2[9];
    for (idxDelay = 0; idxDelay < 19; idxDelay++) {
        _rtDW->wdDelay4_DSTATE_e[(uint32_T)idxDelay] = _rtDW->wdDelay4_DSTATE_e[idxDelay + 1U];
        _rtDW->wdDelay10_DSTATE_o[(uint32_T)idxDelay] = _rtDW->wdDelay10_DSTATE_o[idxDelay + 1U];
    }
    _rtDW->wdDelay4_DSTATE_e[19] = _rtB->B_40_0_2[3];
    _rtDW->wdDelay10_DSTATE_o[19] = _rtB->B_40_0_2[9];
    for (idxDelay = 0; idxDelay < 39; idxDelay++) {
        _rtDW->wdDelay3_DSTATE_j[(uint32_T)idxDelay] = _rtDW->wdDelay3_DSTATE_j[idxDelay + 1U];
    }
    _rtDW->wdDelay3_DSTATE_j[39] = _rtB->B_41_0_2[2];
    for (idxDelay = 0; idxDelay < 79; idxDelay++) {
        _rtDW->wdDelay4_DSTATE_nw[(uint32_T)idxDelay] = _rtDW->wdDelay4_DSTATE_nw[idxDelay + 1U];
    }
    _rtDW->wdDelay4_DSTATE_nw[79] = _rtB->B_41_0_2[3];
    for (idxDelay = 0; idxDelay < 19; idxDelay++) {
        _rtDW->wdDelay6_DSTATE_mj[(uint32_T)idxDelay] = _rtDW->wdDelay6_DSTATE_mj[idxDelay + 1U];
    }
    _rtDW->wdDelay6_DSTATE_mj[19] = _rtB->B_41_0_2[5];
    for (idxDelay = 0; idxDelay < 59; idxDelay++) {
        _rtDW->wdDelay7_DSTATE_g[(uint32_T)idxDelay] = _rtDW->wdDelay7_DSTATE_g[idxDelay + 1U];
    }
    _rtDW->wdDelay7_DSTATE_g[59] = _rtB->B_41_0_2[6];
    for (idxDelay = 0; idxDelay < 39; idxDelay++) {
        _rtDW->wdDelay9_DSTATE_m[(uint32_T)idxDelay] = _rtDW->wdDelay9_DSTATE_m[idxDelay + 1U];
    }
    _rtDW->wdDelay9_DSTATE_m[39] = _rtB->B_41_0_2[8];
    for (idxDelay = 0; idxDelay < 79; idxDelay++) {
        _rtDW->wdDelay10_DSTATE_e[(uint32_T)idxDelay] = _rtDW->wdDelay10_DSTATE_e[idxDelay + 1U];
    }
    _rtDW->wdDelay10_DSTATE_e[79] = _rtB->B_41_0_2[9];
    for (idxDelay = 0; idxDelay < 39; idxDelay++) {
        _rtDW->wdDelay4_DSTATE_b[(uint32_T)idxDelay] = _rtDW->wdDelay4_DSTATE_b[idxDelay + 1U];
    }
    _rtDW->wdDelay4_DSTATE_b[39] = _rtB->B_42_0_2[3];
    for (idxDelay = 0; idxDelay < 19; idxDelay++) {
        _rtDW->wdDelay7_DSTATE_o[(uint32_T)idxDelay] = _rtDW->wdDelay7_DSTATE_o[idxDelay + 1U];
    }
    _rtDW->wdDelay7_DSTATE_o[19] = _rtB->B_42_0_2[6];
    for (idxDelay = 0; idxDelay < 39; idxDelay++) {
        _rtDW->wdDelay10_DSTATE_g[(uint32_T)idxDelay] = _rtDW->wdDelay10_DSTATE_g[idxDelay + 1U];
        _rtDW->ctDelay2_DSTATE[(uint32_T)idxDelay] = _rtDW->ctDelay2_DSTATE[idxDelay + 1U];
    }
    _rtDW->wdDelay10_DSTATE_g[39] = _rtB->B_42_0_2[9];
    _rtDW->ctDelay2_DSTATE[39] = _rtB->B_53_414_0[0];
    for (idxDelay = 0; idxDelay < 79; idxDelay++) {
        _rtDW->ctDelay3_DSTATE[(uint32_T)idxDelay] = _rtDW->ctDelay3_DSTATE[idxDelay + 1U];
    }
    _rtDW->ctDelay3_DSTATE[79] = _rtB->B_53_414_0[0];
    for (idxDelay = 0; idxDelay < 119; idxDelay++) {
        _rtDW->ctDelay4_DSTATE[(uint32_T)idxDelay] = _rtDW->ctDelay4_DSTATE[idxDelay + 1U];
    }
    _rtDW->ctDelay4_DSTATE[119] = _rtB->B_53_414_0[0];
    for (idxDelay = 0; idxDelay < 19; idxDelay++) {
        _rtDW->ctDelay5_DSTATE[(uint32_T)idxDelay] = _rtDW->ctDelay5_DSTATE[idxDelay + 1U];
    }
    _rtDW->ctDelay5_DSTATE[19] = _rtB->B_53_414_0[0];
    for (idxDelay = 0; idxDelay < 59; idxDelay++) {
        _rtDW->ctDelay6_DSTATE[(uint32_T)idxDelay] = _rtDW->ctDelay6_DSTATE[idxDelay + 1U];
    }
    _rtDW->ctDelay6_DSTATE[59] = _rtB->B_53_414_0[0];
    for (idxDelay = 0; idxDelay < 99; idxDelay++) {
        _rtDW->ctDelay7_DSTATE[(uint32_T)idxDelay] = _rtDW->ctDelay7_DSTATE[idxDelay + 1U];
    }
    _rtDW->ctDelay7_DSTATE[99] = _rtB->B_53_414_0[0];
    for (idxDelay = 0; idxDelay < 39; idxDelay++) {
        _rtDW->ctDelay8_DSTATE[(uint32_T)idxDelay] = _rtDW->ctDelay8_DSTATE[idxDelay + 1U];
    }
    _rtDW->ctDelay8_DSTATE[39] = _rtB->B_53_414_0[0];
    for (idxDelay = 0; idxDelay < 79; idxDelay++) {
        _rtDW->ctDelay9_DSTATE[(uint32_T)idxDelay] = _rtDW->ctDelay9_DSTATE[idxDelay + 1U];
    }
    _rtDW->ctDelay9_DSTATE[79] = _rtB->B_53_414_0[0];
    for (idxDelay = 0; idxDelay < 119; idxDelay++) {
        _rtDW->ctDelay10_DSTATE[(uint32_T)idxDelay] = _rtDW->ctDelay10_DSTATE[idxDelay + 1U];
    }
    _rtDW->ctDelay10_DSTATE[119] = _rtB->B_53_414_0[0];
    for (idxDelay = 0; idxDelay < 39; idxDelay++) {
        _rtDW->ctDelay3_DSTATE_l[(uint32_T)idxDelay] = _rtDW->ctDelay3_DSTATE_l[idxDelay + 1U];
    }
    _rtDW->ctDelay3_DSTATE_l[39] = _rtB->B_53_414_0[1];
    for (idxDelay = 0; idxDelay < 79; idxDelay++) {
        _rtDW->ctDelay4_DSTATE_e[(uint32_T)idxDelay] = _rtDW->ctDelay4_DSTATE_e[idxDelay + 1U];
    }
    _rtDW->ctDelay4_DSTATE_e[79] = _rtB->B_53_414_0[1];
    for (idxDelay = 0; idxDelay < 19; idxDelay++) {
        _rtDW->ctDelay6_DSTATE_k[(uint32_T)idxDelay] = _rtDW->ctDelay6_DSTATE_k[idxDelay + 1U];
    }
    _rtDW->ctDelay6_DSTATE_k[19] = _rtB->B_53_414_0[1];
    for (idxDelay = 0; idxDelay < 59; idxDelay++) {
        _rtDW->ctDelay7_DSTATE_n[(uint32_T)idxDelay] = _rtDW->ctDelay7_DSTATE_n[idxDelay + 1U];
    }
    _rtDW->ctDelay7_DSTATE_n[59] = _rtB->B_53_414_0[1];
    for (idxDelay = 0; idxDelay < 39; idxDelay++) {
        _rtDW->ctDelay9_DSTATE_k[(uint32_T)idxDelay] = _rtDW->ctDelay9_DSTATE_k[idxDelay + 1U];
    }
    _rtDW->ctDelay9_DSTATE_k[39] = _rtB->B_53_414_0[1];
    for (idxDelay = 0; idxDelay < 79; idxDelay++) {
        _rtDW->ctDelay10_DSTATE_a[(uint32_T)idxDelay] = _rtDW->ctDelay10_DSTATE_a[idxDelay + 1U];
    }
    _rtDW->ctDelay10_DSTATE_a[79] = _rtB->B_53_414_0[1];
    for (idxDelay = 0; idxDelay < 39; idxDelay++) {
        _rtDW->ctDelay4_DSTATE_er[(uint32_T)idxDelay] = _rtDW->ctDelay4_DSTATE_er[idxDelay + 1U];
    }
    _rtDW->ctDelay4_DSTATE_er[39] = _rtB->B_53_414_0[2];
    for (idxDelay = 0; idxDelay < 19; idxDelay++) {
        _rtDW->ctDelay7_DSTATE_j[(uint32_T)idxDelay] = _rtDW->ctDelay7_DSTATE_j[idxDelay + 1U];
    }
    _rtDW->ctDelay7_DSTATE_j[19] = _rtB->B_53_414_0[2];
    for (idxDelay = 0; idxDelay < 39; idxDelay++) {
        _rtDW->ctDelay10_DSTATE_p[(uint32_T)idxDelay] = _rtDW->ctDelay10_DSTATE_p[idxDelay + 1U];
    }
    _rtDW->ctDelay10_DSTATE_p[39] = _rtB->B_53_414_0[2];
    for (idxDelay = 0; idxDelay < 19; idxDelay++) {
        _rtDW->ctDelay2_DSTATE_m[(uint32_T)idxDelay] = _rtDW->ctDelay2_DSTATE_m[idxDelay + 1U];
    }
    _rtDW->ctDelay2_DSTATE_m[19] = _rtB->B_53_414_0[4];
    for (idxDelay = 0; idxDelay < 59; idxDelay++) {
        _rtDW->ctDelay3_DSTATE_k[(uint32_T)idxDelay] = _rtDW->ctDelay3_DSTATE_k[idxDelay + 1U];
    }
    _rtDW->ctDelay3_DSTATE_k[59] = _rtB->B_53_414_0[4];
    for (idxDelay = 0; idxDelay < 99; idxDelay++) {
        _rtDW->ctDelay4_DSTATE_o[(uint32_T)idxDelay] = _rtDW->ctDelay4_DSTATE_o[idxDelay + 1U];
    }
    _rtDW->ctDelay4_DSTATE_o[99] = _rtB->B_53_414_0[4];
    for (idxDelay = 0; idxDelay < 39; idxDelay++) {
        _rtDW->ctDelay6_DSTATE_f[(uint32_T)idxDelay] = _rtDW->ctDelay6_DSTATE_f[idxDelay + 1U];
    }
    _rtDW->ctDelay6_DSTATE_f[39] = _rtB->B_53_414_0[4];
    for (idxDelay = 0; idxDelay < 79; idxDelay++) {
        _rtDW->ctDelay7_DSTATE_d[(uint32_T)idxDelay] = _rtDW->ctDelay7_DSTATE_d[idxDelay + 1U];
    }
    _rtDW->ctDelay7_DSTATE_d[79] = _rtB->B_53_414_0[4];
    for (idxDelay = 0; idxDelay < 19; idxDelay++) {
        _rtDW->ctDelay8_DSTATE_e[(uint32_T)idxDelay] = _rtDW->ctDelay8_DSTATE_e[idxDelay + 1U];
    }
    _rtDW->ctDelay8_DSTATE_e[19] = _rtB->B_53_414_0[4];
    for (idxDelay = 0; idxDelay < 59; idxDelay++) {
        _rtDW->ctDelay9_DSTATE_a[(uint32_T)idxDelay] = _rtDW->ctDelay9_DSTATE_a[idxDelay + 1U];
    }
    _rtDW->ctDelay9_DSTATE_a[59] = _rtB->B_53_414_0[4];
    for (idxDelay = 0; idxDelay < 99; idxDelay++) {
        _rtDW->ctDelay10_DSTATE_d[(uint32_T)idxDelay] = _rtDW->ctDelay10_DSTATE_d[idxDelay + 1U];
    }
    _rtDW->ctDelay10_DSTATE_d[99] = _rtB->B_53_414_0[4];
    for (idxDelay = 0; idxDelay < 19; idxDelay++) {
        _rtDW->ctDelay3_DSTATE_j[(uint32_T)idxDelay] = _rtDW->ctDelay3_DSTATE_j[idxDelay + 1U];
    }
    _rtDW->ctDelay3_DSTATE_j[19] = _rtB->B_53_414_0[5];
    for (idxDelay = 0; idxDelay < 59; idxDelay++) {
        _rtDW->ctDelay4_DSTATE_c[(uint32_T)idxDelay] = _rtDW->ctDelay4_DSTATE_c[idxDelay + 1U];
    }
    _rtDW->ctDelay4_DSTATE_c[59] = _rtB->B_53_414_0[5];
    for (idxDelay = 0; idxDelay < 39; idxDelay++) {
        _rtDW->ctDelay7_DSTATE_m[(uint32_T)idxDelay] = _rtDW->ctDelay7_DSTATE_m[idxDelay + 1U];
    }
    _rtDW->ctDelay7_DSTATE_m[39] = _rtB->B_53_414_0[5];
    for (idxDelay = 0; idxDelay < 19; idxDelay++) {
        _rtDW->ctDelay9_DSTATE_n[(uint32_T)idxDelay] = _rtDW->ctDelay9_DSTATE_n[idxDelay + 1U];
    }
    _rtDW->ctDelay9_DSTATE_n[19] = _rtB->B_53_414_0[5];
    for (idxDelay = 0; idxDelay < 59; idxDelay++) {
        _rtDW->ctDelay10_DSTATE_j[(uint32_T)idxDelay] = _rtDW->ctDelay10_DSTATE_j[idxDelay + 1U];
    }
    _rtDW->ctDelay10_DSTATE_j[59] = _rtB->B_53_414_0[5];
    for (idxDelay = 0; idxDelay < 19; idxDelay++) {
        _rtDW->ctDelay4_DSTATE_ob[(uint32_T)idxDelay] = _rtDW->ctDelay4_DSTATE_ob[idxDelay + 1U];
        _rtDW->ctDelay10_DSTATE_d2[(uint32_T)idxDelay] = _rtDW->ctDelay10_DSTATE_d2[idxDelay + 1U];
    }
    _rtDW->ctDelay4_DSTATE_ob[19] = _rtB->B_53_414_0[6];
    _rtDW->ctDelay10_DSTATE_d2[19] = _rtB->B_53_414_0[6];
    for (idxDelay = 0; idxDelay < 39; idxDelay++) {
        _rtDW->ctDelay3_DSTATE_d[(uint32_T)idxDelay] = _rtDW->ctDelay3_DSTATE_d[idxDelay + 1U];
    }
    _rtDW->ctDelay3_DSTATE_d[39] = _rtB->B_53_414_0[7];
    for (idxDelay = 0; idxDelay < 79; idxDelay++) {
        _rtDW->ctDelay4_DSTATE_i[(uint32_T)idxDelay] = _rtDW->ctDelay4_DSTATE_i[idxDelay + 1U];
    }
    _rtDW->ctDelay4_DSTATE_i[79] = _rtB->B_53_414_0[7];
    for (idxDelay = 0; idxDelay < 19; idxDelay++) {
        _rtDW->ctDelay6_DSTATE_n[(uint32_T)idxDelay] = _rtDW->ctDelay6_DSTATE_n[idxDelay + 1U];
    }
    _rtDW->ctDelay6_DSTATE_n[19] = _rtB->B_53_414_0[7];
    for (idxDelay = 0; idxDelay < 59; idxDelay++) {
        _rtDW->ctDelay7_DSTATE_f[(uint32_T)idxDelay] = _rtDW->ctDelay7_DSTATE_f[idxDelay + 1U];
    }
    _rtDW->ctDelay7_DSTATE_f[59] = _rtB->B_53_414_0[7];
    for (idxDelay = 0; idxDelay < 39; idxDelay++) {
        _rtDW->ctDelay9_DSTATE_f[(uint32_T)idxDelay] = _rtDW->ctDelay9_DSTATE_f[idxDelay + 1U];
    }
    _rtDW->ctDelay9_DSTATE_f[39] = _rtB->B_53_414_0[7];
    for (idxDelay = 0; idxDelay < 79; idxDelay++) {
        _rtDW->ctDelay10_DSTATE_h[(uint32_T)idxDelay] = _rtDW->ctDelay10_DSTATE_h[idxDelay + 1U];
    }
    _rtDW->ctDelay10_DSTATE_h[79] = _rtB->B_53_414_0[7];
    for (idxDelay = 0; idxDelay < 39; idxDelay++) {
        _rtDW->ctDelay4_DSTATE_m[(uint32_T)idxDelay] = _rtDW->ctDelay4_DSTATE_m[idxDelay + 1U];
    }
    _rtDW->ctDelay4_DSTATE_m[39] = _rtB->B_53_414_0[8];
    for (idxDelay = 0; idxDelay < 19; idxDelay++) {
        _rtDW->ctDelay7_DSTATE_db[(uint32_T)idxDelay] = _rtDW->ctDelay7_DSTATE_db[idxDelay + 1U];
    }
    _rtDW->ctDelay7_DSTATE_db[19] = _rtB->B_53_414_0[8];
    for (idxDelay = 0; idxDelay < 39; idxDelay++) {
        _rtDW->ctDelay10_DSTATE_b[(uint32_T)idxDelay] = _rtDW->ctDelay10_DSTATE_b[idxDelay + 1U];
    }
    _rtDW->ctDelay10_DSTATE_b[39] = _rtB->B_53_414_0[8];
    _rtDW->Output_DSTATE_g = _rtB->B_53_1068_0;
    _rtDW->Output_DSTATE_d = _rtB->B_53_1072_0;
    _rtDW->Output_DSTATE_n = _rtB->B_53_1076_0;
    _rtDW->Output_DSTATE_h = _rtB->B_53_1080_0;
    _rtDW->Output_DSTATE_e = _rtB->B_53_1084_0;
    _rtDW->Output_DSTATE_db = _rtB->B_53_1088_0;
    _rtDW->Output_DSTATE_o = _rtB->B_53_1092_0;
    _rtDW->Output_DSTATE_d4 = _rtB->B_53_1096_0;
    _rtDW->Output_DSTATE_es = _rtB->B_53_1064_0;
}
/* Update for TransportDelay: '<S4>/F_meas delay' */            {
    real_T **uBuffer = (real_T**)&_rtDW->F_measdelay_PWORK.TUbufferPtrs[0];
    real_T **tBuffer = (real_T**)&_rtDW->F_measdelay_PWORK.TUbufferPtrs[1];
       
    real_T simTime   = ssGetT(S);
    
    
        

      
      _rtDW->F_measdelay_IWORK.Head = ((_rtDW->F_measdelay_IWORK.Head < (_rtDW->F_measdelay_IWORK.CircularBufSize-1)) ? (_rtDW->F_measdelay_IWORK.Head+1) : 0);

      if (_rtDW->F_measdelay_IWORK.Head == _rtDW->F_measdelay_IWORK.Tail) {
        
          
          
	  if (!benchmark_no_taylor_acc_rt_TDelayUpdateTailOrGrowBuf( &_rtDW->F_measdelay_IWORK.CircularBufSize, &_rtDW->F_measdelay_IWORK.Tail, &_rtDW->F_measdelay_IWORK.Head, &_rtDW->F_measdelay_IWORK.Last, simTime - _rtP->P_355, tBuffer, uBuffer, (NULL), (boolean_T)0, false, &_rtDW->F_measdelay_IWORK.MaxNewBufSize)) {
            ssSetErrorStatus(S, "tdelay memory allocation error");
            return;
          }
      }
      
      (*tBuffer)[_rtDW->F_measdelay_IWORK.Head] = simTime;
        (*uBuffer)[_rtDW->F_measdelay_IWORK.Head] = _rtB->B_53_428_0;    
  }
 /* Update for TransportDelay: '<S4>/P meas delay' */            {
    real_T **uBuffer = (real_T**)&_rtDW->Pmeasdelay_PWORK.TUbufferPtrs[0];
    real_T **tBuffer = (real_T**)&_rtDW->Pmeasdelay_PWORK.TUbufferPtrs[1];
       
    real_T simTime   = ssGetT(S);
    
    
        

      
      _rtDW->Pmeasdelay_IWORK.Head = ((_rtDW->Pmeasdelay_IWORK.Head < (_rtDW->Pmeasdelay_IWORK.CircularBufSize-1)) ? (_rtDW->Pmeasdelay_IWORK.Head+1) : 0);

      if (_rtDW->Pmeasdelay_IWORK.Head == _rtDW->Pmeasdelay_IWORK.Tail) {
        
          
          
	  if (!benchmark_no_taylor_acc_rt_TDelayUpdateTailOrGrowBuf( &_rtDW->Pmeasdelay_IWORK.CircularBufSize, &_rtDW->Pmeasdelay_IWORK.Tail, &_rtDW->Pmeasdelay_IWORK.Head, &_rtDW->Pmeasdelay_IWORK.Last, simTime - _rtP->P_357, tBuffer, uBuffer, (NULL), (boolean_T)0, false, &_rtDW->Pmeasdelay_IWORK.MaxNewBufSize)) {
            ssSetErrorStatus(S, "tdelay memory allocation error");
            return;
          }
      }
      
      (*tBuffer)[_rtDW->Pmeasdelay_IWORK.Head] = simTime;
        (*uBuffer)[_rtDW->Pmeasdelay_IWORK.Head] = _rtB->B_53_429_0;    
  }
 if (ssIsSampleHit(S, 5, 0)) {
    _rtDW->UnitDelay_DSTATE = _rtB->B_1_0_1;
}
if (ssIsSampleHit(S, 2, 0)) {
/* Update for DiscreteStateSpace: '<S23>/Measurement filter (low pass)' */              {
          real_T xnew[1];
        xnew[0] = _rtP->P_399*_rtDW->Measurementfilterlowpass_DSTATE;
    xnew[0] += _rtP->P_400*_rtB->B_53_78_0;
    (void) memcpy(&_rtDW->Measurementfilterlowpass_DSTATE, xnew,
sizeof(real_T)*1);
    }

     _rtDW->IntegerDelay_DSTATE = _rtB->Pitchcontroller.B_3_10_0;

      benchmark_no_taylor_Pitchcontroller_Update(&_rtB->Pitchcontroller, &_rtDW->Pitchcontroller, (P_Pitchcontroller_benchmark_no_taylor_T *)&_rtP->Pitchcontroller);}
/* Update for TransportDelay: '<S34>/Hydraulic delay time' */            {
    real_T **uBuffer = (real_T**)&_rtDW->Hydraulicdelaytime_PWORK.TUbufferPtrs[0];
    real_T **tBuffer = (real_T**)&_rtDW->Hydraulicdelaytime_PWORK.TUbufferPtrs[1];
       
    real_T simTime   = ssGetT(S);
    
    
        

      
      _rtDW->Hydraulicdelaytime_IWORK.Head = ((_rtDW->Hydraulicdelaytime_IWORK.Head < (_rtDW->Hydraulicdelaytime_IWORK.CircularBufSize-1)) ? (_rtDW->Hydraulicdelaytime_IWORK.Head+1) : 0);

      if (_rtDW->Hydraulicdelaytime_IWORK.Head == _rtDW->Hydraulicdelaytime_IWORK.Tail) {
        
          
          
	  if (!benchmark_no_taylor_acc_rt_TDelayUpdateTailOrGrowBuf( &_rtDW->Hydraulicdelaytime_IWORK.CircularBufSize, &_rtDW->Hydraulicdelaytime_IWORK.Tail, &_rtDW->Hydraulicdelaytime_IWORK.Head, &_rtDW->Hydraulicdelaytime_IWORK.Last, simTime - _rtP->P_422, tBuffer, uBuffer, (NULL), (boolean_T)0, false, &_rtDW->Hydraulicdelaytime_IWORK.MaxNewBufSize)) {
            ssSetErrorStatus(S, "tdelay memory allocation error");
            return;
          }
      }
      
      (*tBuffer)[_rtDW->Hydraulicdelaytime_IWORK.Head] = simTime;
        (*uBuffer)[_rtDW->Hydraulicdelaytime_IWORK.Head] = _rtB->B_53_509_0;    
  }
 if (ssIsSampleHit(S, 2, 0)) {
/* Update for DiscreteStateSpace: '<S39>/Measurement filter (low pass)' */              {
          real_T xnew[1];
        xnew[0] = _rtP->P_444*_rtDW->Measurementfilterlowpass_DSTATE_i;
    xnew[0] += _rtP->P_445*_rtB->B_53_87_0;
    (void) memcpy(&_rtDW->Measurementfilterlowpass_DSTATE_i, xnew,
sizeof(real_T)*1);
    }

     _rtDW->IntegerDelay_DSTATE_i = _rtB->Pitchcontroller_n.B_3_10_0;

      benchmark_no_taylor_Pitchcontroller_Update(&_rtB->Pitchcontroller_n, &_rtDW->Pitchcontroller_n, (P_Pitchcontroller_benchmark_no_taylor_T *)&_rtP->Pitchcontroller_n);}
/* Update for TransportDelay: '<S50>/Hydraulic delay time' */            {
    real_T **uBuffer = (real_T**)&_rtDW->Hydraulicdelaytime_PWORK_f.TUbufferPtrs[0];
    real_T **tBuffer = (real_T**)&_rtDW->Hydraulicdelaytime_PWORK_f.TUbufferPtrs[1];
       
    real_T simTime   = ssGetT(S);
    
    
        

      
      _rtDW->Hydraulicdelaytime_IWORK_m.Head = ((_rtDW->Hydraulicdelaytime_IWORK_m.Head < (_rtDW->Hydraulicdelaytime_IWORK_m.CircularBufSize-1)) ? (_rtDW->Hydraulicdelaytime_IWORK_m.Head+1) : 0);

      if (_rtDW->Hydraulicdelaytime_IWORK_m.Head == _rtDW->Hydraulicdelaytime_IWORK_m.Tail) {
        
          
          
	  if (!benchmark_no_taylor_acc_rt_TDelayUpdateTailOrGrowBuf( &_rtDW->Hydraulicdelaytime_IWORK_m.CircularBufSize, &_rtDW->Hydraulicdelaytime_IWORK_m.Tail, &_rtDW->Hydraulicdelaytime_IWORK_m.Head, &_rtDW->Hydraulicdelaytime_IWORK_m.Last, simTime - _rtP->P_467, tBuffer, uBuffer, (NULL), (boolean_T)0, false, &_rtDW->Hydraulicdelaytime_IWORK_m.MaxNewBufSize)) {
            ssSetErrorStatus(S, "tdelay memory allocation error");
            return;
          }
      }
      
      (*tBuffer)[_rtDW->Hydraulicdelaytime_IWORK_m.Head] = simTime;
        (*uBuffer)[_rtDW->Hydraulicdelaytime_IWORK_m.Head] = _rtB->B_53_565_0;    
  }
 if (ssIsSampleHit(S, 2, 0)) {
/* Update for DiscreteStateSpace: '<S55>/Measurement filter (low pass)' */              {
          real_T xnew[1];
        xnew[0] = _rtP->P_489*_rtDW->Measurementfilterlowpass_DSTATE_j;
    xnew[0] += _rtP->P_490*_rtB->B_53_79_0;
    (void) memcpy(&_rtDW->Measurementfilterlowpass_DSTATE_j, xnew,
sizeof(real_T)*1);
    }

     _rtDW->IntegerDelay_DSTATE_c = _rtB->Pitchcontroller_a.B_3_10_0;

      benchmark_no_taylor_Pitchcontroller_Update(&_rtB->Pitchcontroller_a, &_rtDW->Pitchcontroller_a, (P_Pitchcontroller_benchmark_no_taylor_T *)&_rtP->Pitchcontroller_a);}
/* Update for TransportDelay: '<S66>/Hydraulic delay time' */            {
    real_T **uBuffer = (real_T**)&_rtDW->Hydraulicdelaytime_PWORK_n.TUbufferPtrs[0];
    real_T **tBuffer = (real_T**)&_rtDW->Hydraulicdelaytime_PWORK_n.TUbufferPtrs[1];
       
    real_T simTime   = ssGetT(S);
    
    
        

      
      _rtDW->Hydraulicdelaytime_IWORK_a.Head = ((_rtDW->Hydraulicdelaytime_IWORK_a.Head < (_rtDW->Hydraulicdelaytime_IWORK_a.CircularBufSize-1)) ? (_rtDW->Hydraulicdelaytime_IWORK_a.Head+1) : 0);

      if (_rtDW->Hydraulicdelaytime_IWORK_a.Head == _rtDW->Hydraulicdelaytime_IWORK_a.Tail) {
        
          
          
	  if (!benchmark_no_taylor_acc_rt_TDelayUpdateTailOrGrowBuf( &_rtDW->Hydraulicdelaytime_IWORK_a.CircularBufSize, &_rtDW->Hydraulicdelaytime_IWORK_a.Tail, &_rtDW->Hydraulicdelaytime_IWORK_a.Head, &_rtDW->Hydraulicdelaytime_IWORK_a.Last, simTime - _rtP->P_512, tBuffer, uBuffer, (NULL), (boolean_T)0, false, &_rtDW->Hydraulicdelaytime_IWORK_a.MaxNewBufSize)) {
            ssSetErrorStatus(S, "tdelay memory allocation error");
            return;
          }
      }
      
      (*tBuffer)[_rtDW->Hydraulicdelaytime_IWORK_a.Head] = simTime;
        (*uBuffer)[_rtDW->Hydraulicdelaytime_IWORK_a.Head] = _rtB->B_53_621_0;    
  }
 if (ssIsSampleHit(S, 2, 0)) {
/* Update for DiscreteStateSpace: '<S71>/Measurement filter (low pass)' */              {
          real_T xnew[1];
        xnew[0] = _rtP->P_534*_rtDW->Measurementfilterlowpass_DSTATE_a;
    xnew[0] += _rtP->P_535*_rtB->B_53_80_0;
    (void) memcpy(&_rtDW->Measurementfilterlowpass_DSTATE_a, xnew,
sizeof(real_T)*1);
    }

     _rtDW->IntegerDelay_DSTATE_f = _rtB->Pitchcontroller_i.B_3_10_0;

      benchmark_no_taylor_Pitchcontroller_Update(&_rtB->Pitchcontroller_i, &_rtDW->Pitchcontroller_i, (P_Pitchcontroller_benchmark_no_taylor_T *)&_rtP->Pitchcontroller_i);}
/* Update for TransportDelay: '<S82>/Hydraulic delay time' */            {
    real_T **uBuffer = (real_T**)&_rtDW->Hydraulicdelaytime_PWORK_m.TUbufferPtrs[0];
    real_T **tBuffer = (real_T**)&_rtDW->Hydraulicdelaytime_PWORK_m.TUbufferPtrs[1];
       
    real_T simTime   = ssGetT(S);
    
    
        

      
      _rtDW->Hydraulicdelaytime_IWORK_c.Head = ((_rtDW->Hydraulicdelaytime_IWORK_c.Head < (_rtDW->Hydraulicdelaytime_IWORK_c.CircularBufSize-1)) ? (_rtDW->Hydraulicdelaytime_IWORK_c.Head+1) : 0);

      if (_rtDW->Hydraulicdelaytime_IWORK_c.Head == _rtDW->Hydraulicdelaytime_IWORK_c.Tail) {
        
          
          
	  if (!benchmark_no_taylor_acc_rt_TDelayUpdateTailOrGrowBuf( &_rtDW->Hydraulicdelaytime_IWORK_c.CircularBufSize, &_rtDW->Hydraulicdelaytime_IWORK_c.Tail, &_rtDW->Hydraulicdelaytime_IWORK_c.Head, &_rtDW->Hydraulicdelaytime_IWORK_c.Last, simTime - _rtP->P_557, tBuffer, uBuffer, (NULL), (boolean_T)0, false, &_rtDW->Hydraulicdelaytime_IWORK_c.MaxNewBufSize)) {
            ssSetErrorStatus(S, "tdelay memory allocation error");
            return;
          }
      }
      
      (*tBuffer)[_rtDW->Hydraulicdelaytime_IWORK_c.Head] = simTime;
        (*uBuffer)[_rtDW->Hydraulicdelaytime_IWORK_c.Head] = _rtB->B_53_677_0;    
  }
 if (ssIsSampleHit(S, 2, 0)) {
/* Update for DiscreteStateSpace: '<S87>/Measurement filter (low pass)' */              {
          real_T xnew[1];
        xnew[0] = _rtP->P_579*_rtDW->Measurementfilterlowpass_DSTATE_e;
    xnew[0] += _rtP->P_580*_rtB->B_53_81_0;
    (void) memcpy(&_rtDW->Measurementfilterlowpass_DSTATE_e, xnew,
sizeof(real_T)*1);
    }

     _rtDW->IntegerDelay_DSTATE_l = _rtB->Pitchcontroller_e.B_3_10_0;

      benchmark_no_taylor_Pitchcontroller_Update(&_rtB->Pitchcontroller_e, &_rtDW->Pitchcontroller_e, (P_Pitchcontroller_benchmark_no_taylor_T *)&_rtP->Pitchcontroller_e);}
/* Update for TransportDelay: '<S98>/Hydraulic delay time' */            {
    real_T **uBuffer = (real_T**)&_rtDW->Hydraulicdelaytime_PWORK_k.TUbufferPtrs[0];
    real_T **tBuffer = (real_T**)&_rtDW->Hydraulicdelaytime_PWORK_k.TUbufferPtrs[1];
       
    real_T simTime   = ssGetT(S);
    
    
        

      
      _rtDW->Hydraulicdelaytime_IWORK_e.Head = ((_rtDW->Hydraulicdelaytime_IWORK_e.Head < (_rtDW->Hydraulicdelaytime_IWORK_e.CircularBufSize-1)) ? (_rtDW->Hydraulicdelaytime_IWORK_e.Head+1) : 0);

      if (_rtDW->Hydraulicdelaytime_IWORK_e.Head == _rtDW->Hydraulicdelaytime_IWORK_e.Tail) {
        
          
          
	  if (!benchmark_no_taylor_acc_rt_TDelayUpdateTailOrGrowBuf( &_rtDW->Hydraulicdelaytime_IWORK_e.CircularBufSize, &_rtDW->Hydraulicdelaytime_IWORK_e.Tail, &_rtDW->Hydraulicdelaytime_IWORK_e.Head, &_rtDW->Hydraulicdelaytime_IWORK_e.Last, simTime - _rtP->P_602, tBuffer, uBuffer, (NULL), (boolean_T)0, false, &_rtDW->Hydraulicdelaytime_IWORK_e.MaxNewBufSize)) {
            ssSetErrorStatus(S, "tdelay memory allocation error");
            return;
          }
      }
      
      (*tBuffer)[_rtDW->Hydraulicdelaytime_IWORK_e.Head] = simTime;
        (*uBuffer)[_rtDW->Hydraulicdelaytime_IWORK_e.Head] = _rtB->B_53_733_0;    
  }
 if (ssIsSampleHit(S, 2, 0)) {
/* Update for DiscreteStateSpace: '<S103>/Measurement filter (low pass)' */              {
          real_T xnew[1];
        xnew[0] = _rtP->P_624*_rtDW->Measurementfilterlowpass_DSTATE_c;
    xnew[0] += _rtP->P_625*_rtB->B_53_82_0;
    (void) memcpy(&_rtDW->Measurementfilterlowpass_DSTATE_c, xnew,
sizeof(real_T)*1);
    }

     _rtDW->IntegerDelay_DSTATE_j = _rtB->Pitchcontroller_p.B_3_10_0;

      benchmark_no_taylor_Pitchcontroller_Update(&_rtB->Pitchcontroller_p, &_rtDW->Pitchcontroller_p, (P_Pitchcontroller_benchmark_no_taylor_T *)&_rtP->Pitchcontroller_p);}
/* Update for TransportDelay: '<S114>/Hydraulic delay time' */            {
    real_T **uBuffer = (real_T**)&_rtDW->Hydraulicdelaytime_PWORK_m0.TUbufferPtrs[0];
    real_T **tBuffer = (real_T**)&_rtDW->Hydraulicdelaytime_PWORK_m0.TUbufferPtrs[1];
       
    real_T simTime   = ssGetT(S);
    
    
        

      
      _rtDW->Hydraulicdelaytime_IWORK_o.Head = ((_rtDW->Hydraulicdelaytime_IWORK_o.Head < (_rtDW->Hydraulicdelaytime_IWORK_o.CircularBufSize-1)) ? (_rtDW->Hydraulicdelaytime_IWORK_o.Head+1) : 0);

      if (_rtDW->Hydraulicdelaytime_IWORK_o.Head == _rtDW->Hydraulicdelaytime_IWORK_o.Tail) {
        
          
          
	  if (!benchmark_no_taylor_acc_rt_TDelayUpdateTailOrGrowBuf( &_rtDW->Hydraulicdelaytime_IWORK_o.CircularBufSize, &_rtDW->Hydraulicdelaytime_IWORK_o.Tail, &_rtDW->Hydraulicdelaytime_IWORK_o.Head, &_rtDW->Hydraulicdelaytime_IWORK_o.Last, simTime - _rtP->P_647, tBuffer, uBuffer, (NULL), (boolean_T)0, false, &_rtDW->Hydraulicdelaytime_IWORK_o.MaxNewBufSize)) {
            ssSetErrorStatus(S, "tdelay memory allocation error");
            return;
          }
      }
      
      (*tBuffer)[_rtDW->Hydraulicdelaytime_IWORK_o.Head] = simTime;
        (*uBuffer)[_rtDW->Hydraulicdelaytime_IWORK_o.Head] = _rtB->B_53_789_0;    
  }
 if (ssIsSampleHit(S, 2, 0)) {
/* Update for DiscreteStateSpace: '<S119>/Measurement filter (low pass)' */              {
          real_T xnew[1];
        xnew[0] = _rtP->P_669*_rtDW->Measurementfilterlowpass_DSTATE_ja;
    xnew[0] += _rtP->P_670*_rtB->B_53_83_0;
    (void) memcpy(&_rtDW->Measurementfilterlowpass_DSTATE_ja, xnew,
sizeof(real_T)*1);
    }

     _rtDW->IntegerDelay_DSTATE_n = _rtB->Pitchcontroller_f.B_3_10_0;

      benchmark_no_taylor_Pitchcontroller_Update(&_rtB->Pitchcontroller_f, &_rtDW->Pitchcontroller_f, (P_Pitchcontroller_benchmark_no_taylor_T *)&_rtP->Pitchcontroller_f);}
/* Update for TransportDelay: '<S130>/Hydraulic delay time' */            {
    real_T **uBuffer = (real_T**)&_rtDW->Hydraulicdelaytime_PWORK_fg.TUbufferPtrs[0];
    real_T **tBuffer = (real_T**)&_rtDW->Hydraulicdelaytime_PWORK_fg.TUbufferPtrs[1];
       
    real_T simTime   = ssGetT(S);
    
    
        

      
      _rtDW->Hydraulicdelaytime_IWORK_n.Head = ((_rtDW->Hydraulicdelaytime_IWORK_n.Head < (_rtDW->Hydraulicdelaytime_IWORK_n.CircularBufSize-1)) ? (_rtDW->Hydraulicdelaytime_IWORK_n.Head+1) : 0);

      if (_rtDW->Hydraulicdelaytime_IWORK_n.Head == _rtDW->Hydraulicdelaytime_IWORK_n.Tail) {
        
          
          
	  if (!benchmark_no_taylor_acc_rt_TDelayUpdateTailOrGrowBuf( &_rtDW->Hydraulicdelaytime_IWORK_n.CircularBufSize, &_rtDW->Hydraulicdelaytime_IWORK_n.Tail, &_rtDW->Hydraulicdelaytime_IWORK_n.Head, &_rtDW->Hydraulicdelaytime_IWORK_n.Last, simTime - _rtP->P_692, tBuffer, uBuffer, (NULL), (boolean_T)0, false, &_rtDW->Hydraulicdelaytime_IWORK_n.MaxNewBufSize)) {
            ssSetErrorStatus(S, "tdelay memory allocation error");
            return;
          }
      }
      
      (*tBuffer)[_rtDW->Hydraulicdelaytime_IWORK_n.Head] = simTime;
        (*uBuffer)[_rtDW->Hydraulicdelaytime_IWORK_n.Head] = _rtB->B_53_845_0;    
  }
 if (ssIsSampleHit(S, 2, 0)) {
/* Update for DiscreteStateSpace: '<S135>/Measurement filter (low pass)' */              {
          real_T xnew[1];
        xnew[0] = _rtP->P_714*_rtDW->Measurementfilterlowpass_DSTATE_aq;
    xnew[0] += _rtP->P_715*_rtB->B_53_84_0;
    (void) memcpy(&_rtDW->Measurementfilterlowpass_DSTATE_aq, xnew,
sizeof(real_T)*1);
    }

     _rtDW->IntegerDelay_DSTATE_e = _rtB->Pitchcontroller_nb.B_3_10_0;

      benchmark_no_taylor_Pitchcontroller_Update(&_rtB->Pitchcontroller_nb, &_rtDW->Pitchcontroller_nb, (P_Pitchcontroller_benchmark_no_taylor_T *)&_rtP->Pitchcontroller_nb);}
/* Update for TransportDelay: '<S146>/Hydraulic delay time' */            {
    real_T **uBuffer = (real_T**)&_rtDW->Hydraulicdelaytime_PWORK_h.TUbufferPtrs[0];
    real_T **tBuffer = (real_T**)&_rtDW->Hydraulicdelaytime_PWORK_h.TUbufferPtrs[1];
       
    real_T simTime   = ssGetT(S);
    
    
        

      
      _rtDW->Hydraulicdelaytime_IWORK_b.Head = ((_rtDW->Hydraulicdelaytime_IWORK_b.Head < (_rtDW->Hydraulicdelaytime_IWORK_b.CircularBufSize-1)) ? (_rtDW->Hydraulicdelaytime_IWORK_b.Head+1) : 0);

      if (_rtDW->Hydraulicdelaytime_IWORK_b.Head == _rtDW->Hydraulicdelaytime_IWORK_b.Tail) {
        
          
          
	  if (!benchmark_no_taylor_acc_rt_TDelayUpdateTailOrGrowBuf( &_rtDW->Hydraulicdelaytime_IWORK_b.CircularBufSize, &_rtDW->Hydraulicdelaytime_IWORK_b.Tail, &_rtDW->Hydraulicdelaytime_IWORK_b.Head, &_rtDW->Hydraulicdelaytime_IWORK_b.Last, simTime - _rtP->P_737, tBuffer, uBuffer, (NULL), (boolean_T)0, false, &_rtDW->Hydraulicdelaytime_IWORK_b.MaxNewBufSize)) {
            ssSetErrorStatus(S, "tdelay memory allocation error");
            return;
          }
      }
      
      (*tBuffer)[_rtDW->Hydraulicdelaytime_IWORK_b.Head] = simTime;
        (*uBuffer)[_rtDW->Hydraulicdelaytime_IWORK_b.Head] = _rtB->B_53_901_0;    
  }
 if (ssIsSampleHit(S, 2, 0)) {
/* Update for DiscreteStateSpace: '<S151>/Measurement filter (low pass)' */              {
          real_T xnew[1];
        xnew[0] = _rtP->P_759*_rtDW->Measurementfilterlowpass_DSTATE_k;
    xnew[0] += _rtP->P_760*_rtB->B_53_85_0;
    (void) memcpy(&_rtDW->Measurementfilterlowpass_DSTATE_k, xnew,
sizeof(real_T)*1);
    }

     _rtDW->IntegerDelay_DSTATE_id = _rtB->Pitchcontroller_a2.B_3_10_0;

      benchmark_no_taylor_Pitchcontroller_Update(&_rtB->Pitchcontroller_a2, &_rtDW->Pitchcontroller_a2, (P_Pitchcontroller_benchmark_no_taylor_T *)&_rtP->Pitchcontroller_a2);}
/* Update for TransportDelay: '<S162>/Hydraulic delay time' */            {
    real_T **uBuffer = (real_T**)&_rtDW->Hydraulicdelaytime_PWORK_d.TUbufferPtrs[0];
    real_T **tBuffer = (real_T**)&_rtDW->Hydraulicdelaytime_PWORK_d.TUbufferPtrs[1];
       
    real_T simTime   = ssGetT(S);
    
    
        

      
      _rtDW->Hydraulicdelaytime_IWORK_h.Head = ((_rtDW->Hydraulicdelaytime_IWORK_h.Head < (_rtDW->Hydraulicdelaytime_IWORK_h.CircularBufSize-1)) ? (_rtDW->Hydraulicdelaytime_IWORK_h.Head+1) : 0);

      if (_rtDW->Hydraulicdelaytime_IWORK_h.Head == _rtDW->Hydraulicdelaytime_IWORK_h.Tail) {
        
          
          
	  if (!benchmark_no_taylor_acc_rt_TDelayUpdateTailOrGrowBuf( &_rtDW->Hydraulicdelaytime_IWORK_h.CircularBufSize, &_rtDW->Hydraulicdelaytime_IWORK_h.Tail, &_rtDW->Hydraulicdelaytime_IWORK_h.Head, &_rtDW->Hydraulicdelaytime_IWORK_h.Last, simTime - _rtP->P_782, tBuffer, uBuffer, (NULL), (boolean_T)0, false, &_rtDW->Hydraulicdelaytime_IWORK_h.MaxNewBufSize)) {
            ssSetErrorStatus(S, "tdelay memory allocation error");
            return;
          }
      }
      
      (*tBuffer)[_rtDW->Hydraulicdelaytime_IWORK_h.Head] = simTime;
        (*uBuffer)[_rtDW->Hydraulicdelaytime_IWORK_h.Head] = _rtB->B_53_957_0;    
  }
 if (ssIsSampleHit(S, 2, 0)) {
/* Update for DiscreteStateSpace: '<S167>/Measurement filter (low pass)' */              {
          real_T xnew[1];
        xnew[0] = _rtP->P_804*_rtDW->Measurementfilterlowpass_DSTATE_k1;
    xnew[0] += _rtP->P_805*_rtB->B_53_86_0;
    (void) memcpy(&_rtDW->Measurementfilterlowpass_DSTATE_k1, xnew,
sizeof(real_T)*1);
    }

     _rtDW->IntegerDelay_DSTATE_fg = _rtB->Pitchcontroller_c.B_3_10_0;

      benchmark_no_taylor_Pitchcontroller_Update(&_rtB->Pitchcontroller_c, &_rtDW->Pitchcontroller_c, (P_Pitchcontroller_benchmark_no_taylor_T *)&_rtP->Pitchcontroller_c);}
/* Update for TransportDelay: '<S178>/Hydraulic delay time' */            {
    real_T **uBuffer = (real_T**)&_rtDW->Hydraulicdelaytime_PWORK_a.TUbufferPtrs[0];
    real_T **tBuffer = (real_T**)&_rtDW->Hydraulicdelaytime_PWORK_a.TUbufferPtrs[1];
       
    real_T simTime   = ssGetT(S);
    
    
        

      
      _rtDW->Hydraulicdelaytime_IWORK_mc.Head = ((_rtDW->Hydraulicdelaytime_IWORK_mc.Head < (_rtDW->Hydraulicdelaytime_IWORK_mc.CircularBufSize-1)) ? (_rtDW->Hydraulicdelaytime_IWORK_mc.Head+1) : 0);

      if (_rtDW->Hydraulicdelaytime_IWORK_mc.Head == _rtDW->Hydraulicdelaytime_IWORK_mc.Tail) {
        
          
          
	  if (!benchmark_no_taylor_acc_rt_TDelayUpdateTailOrGrowBuf( &_rtDW->Hydraulicdelaytime_IWORK_mc.CircularBufSize, &_rtDW->Hydraulicdelaytime_IWORK_mc.Tail, &_rtDW->Hydraulicdelaytime_IWORK_mc.Head, &_rtDW->Hydraulicdelaytime_IWORK_mc.Last, simTime - _rtP->P_827, tBuffer, uBuffer, (NULL), (boolean_T)0, false, &_rtDW->Hydraulicdelaytime_IWORK_mc.MaxNewBufSize)) {
            ssSetErrorStatus(S, "tdelay memory allocation error");
            return;
          }
      }
      
      (*tBuffer)[_rtDW->Hydraulicdelaytime_IWORK_mc.Head] = simTime;
        (*uBuffer)[_rtDW->Hydraulicdelaytime_IWORK_mc.Head] = _rtB->B_53_1013_0;    
  }
 if (ssIsSampleHit(S, 3, 0)) {
    _rtDW->Output_DSTATE_ej = _rtB->B_53_1032_0;
}






    
  

                  UNUSED_PARAMETER(tid);




            }
    
  





    
  

          /* Update for root system: '<Root>' */
            #define MDL_UPDATE
    
  
       static  void mdlUpdateTID6(SimStruct *S, int_T tid)
  {
  
      
        
      
    
  

        
      
    
  

              
  

              UNUSED_PARAMETER(tid);




            }
    
  







	      /* Derivatives for root system: '<Root>' */
            #define MDL_DERIVATIVES
    
  
       static  void mdlDerivatives(SimStruct *S)
  {
  
  
      
      
  B_benchmark_no_taylor_T *_rtB;
P_benchmark_no_taylor_T *_rtP;
X_benchmark_no_taylor_T *_rtX;
XDis_benchmark_no_taylor_T *_rtXdis;
XDot_benchmark_no_taylor_T *_rtXdot;
DW_benchmark_no_taylor_T *_rtDW;

    
  

              
    
    
  

                              _rtDW = ((DW_benchmark_no_taylor_T *) ssGetRootDWork(S));
_rtXdot = ((XDot_benchmark_no_taylor_T *) ssGetdX(S));
_rtXdis = ((XDis_benchmark_no_taylor_T *) ssGetContStateDisabled(S));
_rtX = ((X_benchmark_no_taylor_T *) ssGetContStates(S));
_rtP = ((P_benchmark_no_taylor_T *) ssGetModelRtp(S));
_rtB = ((B_benchmark_no_taylor_T *) _ssGetModelBlockIO(S));
/* 0: INTG_NORMAL     1: INTG_LEAVING_UPPER_SAT  2: INTG_LEAVING_LOWER_SAT */
/* 3: INTG_UPPER_SAT  4: INTG_LOWER_SAT */
if ((_rtDW->Integrator_MODE != 3) && (_rtDW->Integrator_MODE != 4)) {
    _rtXdot->Integrator_CSTATE = _rtB->B_53_422_0;
    _rtXdis->Integrator_CSTATE = false;
} else {
    /* in saturation */
    _rtXdot->Integrator_CSTATE = 0.0;
    if ((_rtDW->Integrator_MODE == 3) || (_rtDW->Integrator_MODE == 4)) {
        _rtXdis->Integrator_CSTATE = true;
    }
}
_rtXdot->TorqueIntegrator_CSTATE = _rtB->B_53_504_0;
_rtXdot->generatorint_CSTATE = _rtB->B_53_497_0;
_rtXdot->TorqueIntegrator_CSTATE_h = _rtB->B_53_616_0;
_rtXdot->generatorint_CSTATE_h = _rtB->B_53_609_0;
_rtXdot->TorqueIntegrator_CSTATE_o = _rtB->B_53_672_0;
_rtXdot->generatorint_CSTATE_b = _rtB->B_53_665_0;
_rtXdot->TorqueIntegrator_CSTATE_p = _rtB->B_53_728_0;
_rtXdot->generatorint_CSTATE_bf = _rtB->B_53_721_0;
_rtXdot->TorqueIntegrator_CSTATE_f = _rtB->B_53_784_0;
_rtXdot->generatorint_CSTATE_a = _rtB->B_53_777_0;
_rtXdot->TorqueIntegrator_CSTATE_j = _rtB->B_53_840_0;
_rtXdot->generatorint_CSTATE_g = _rtB->B_53_833_0;
_rtXdot->TorqueIntegrator_CSTATE_i = _rtB->B_53_896_0;
_rtXdot->generatorint_CSTATE_i = _rtB->B_53_889_0;
_rtXdot->TorqueIntegrator_CSTATE_oh = _rtB->B_53_952_0;
_rtXdot->generatorint_CSTATE_l = _rtB->B_53_945_0;
_rtXdot->TorqueIntegrator_CSTATE_n = _rtB->B_53_1008_0;
_rtXdot->generatorint_CSTATE_bt = _rtB->B_53_1001_0;
_rtXdot->TorqueIntegrator_CSTATE_nc = _rtB->B_53_560_0;
_rtXdot->generatorint_CSTATE_am = _rtB->B_53_553_0;
_rtXdot->Integrator_CSTATE_a = _rtB->B_53_506_0;
_rtXdot->Tower_CSTATE[0] = 0.0;
_rtXdot->Tower_CSTATE_p[0] = 0.0;
_rtXdot->Tower_CSTATE_d[0] = 0.0;
_rtXdot->Tower_CSTATE_i[0] = 0.0;
_rtXdot->Tower_CSTATE_pr[0] = 0.0;
_rtXdot->Tower_CSTATE_iw[0] = 0.0;
_rtXdot->Tower_CSTATE_b[0] = 0.0;
_rtXdot->Tower_CSTATE_f[0] = 0.0;
_rtXdot->Tower_CSTATE_m[0] = 0.0;
_rtXdot->Tower_CSTATE_c[0] = 0.0;
_rtXdot->Tower_CSTATE[1] = 0.0;
_rtXdot->Tower_CSTATE_p[1] = 0.0;
_rtXdot->Tower_CSTATE_d[1] = 0.0;
_rtXdot->Tower_CSTATE_i[1] = 0.0;
_rtXdot->Tower_CSTATE_pr[1] = 0.0;
_rtXdot->Tower_CSTATE_iw[1] = 0.0;
_rtXdot->Tower_CSTATE_b[1] = 0.0;
_rtXdot->Tower_CSTATE_f[1] = 0.0;
_rtXdot->Tower_CSTATE_m[1] = 0.0;
_rtXdot->Tower_CSTATE_c[1] = 0.0;
_rtXdot->Tower_CSTATE[0] += _rtP->P_227[0] * _rtX->Tower_CSTATE[0];
_rtXdot->Tower_CSTATE[0] += _rtP->P_227[1] * _rtX->Tower_CSTATE[1];
_rtXdot->Tower_CSTATE[1] += _rtP->P_227[2] * _rtX->Tower_CSTATE[0];
_rtXdot->Tower_CSTATE[0] += _rtP->P_228 * _rtB->B_53_467_0;
_rtXdot->rotorint_CSTATE = _rtB->B_53_499_0;
_rtXdot->Integrator_CSTATE_p = _rtB->B_53_618_0;
_rtXdot->Tower_CSTATE_p[0] += _rtP->P_240[0] * _rtX->Tower_CSTATE_p[0];
_rtXdot->Tower_CSTATE_p[0] += _rtP->P_240[1] * _rtX->Tower_CSTATE_p[1];
_rtXdot->Tower_CSTATE_p[1] += _rtP->P_240[2] * _rtX->Tower_CSTATE_p[0];
_rtXdot->Tower_CSTATE_p[0] += _rtP->P_241 * _rtB->B_53_579_0;
_rtXdot->rotorint_CSTATE_f = _rtB->B_53_611_0;
_rtXdot->Integrator_CSTATE_m = _rtB->B_53_674_0;
_rtXdot->Tower_CSTATE_d[0] += _rtP->P_253[0] * _rtX->Tower_CSTATE_d[0];
_rtXdot->Tower_CSTATE_d[0] += _rtP->P_253[1] * _rtX->Tower_CSTATE_d[1];
_rtXdot->Tower_CSTATE_d[1] += _rtP->P_253[2] * _rtX->Tower_CSTATE_d[0];
_rtXdot->Tower_CSTATE_d[0] += _rtP->P_254 * _rtB->B_53_635_0;
_rtXdot->rotorint_CSTATE_a = _rtB->B_53_667_0;
_rtXdot->Integrator_CSTATE_i = _rtB->B_53_730_0;
_rtXdot->Tower_CSTATE_i[0] += _rtP->P_266[0] * _rtX->Tower_CSTATE_i[0];
_rtXdot->Tower_CSTATE_i[0] += _rtP->P_266[1] * _rtX->Tower_CSTATE_i[1];
_rtXdot->Tower_CSTATE_i[1] += _rtP->P_266[2] * _rtX->Tower_CSTATE_i[0];
_rtXdot->Tower_CSTATE_i[0] += _rtP->P_267 * _rtB->B_53_691_0;
_rtXdot->rotorint_CSTATE_d = _rtB->B_53_723_0;
_rtXdot->Integrator_CSTATE_pq = _rtB->B_53_786_0;
_rtXdot->Tower_CSTATE_pr[0] += _rtP->P_279[0] * _rtX->Tower_CSTATE_pr[0];
_rtXdot->Tower_CSTATE_pr[0] += _rtP->P_279[1] * _rtX->Tower_CSTATE_pr[1];
_rtXdot->Tower_CSTATE_pr[1] += _rtP->P_279[2] * _rtX->Tower_CSTATE_pr[0];
_rtXdot->Tower_CSTATE_pr[0] += _rtP->P_280 * _rtB->B_53_747_0;
_rtXdot->rotorint_CSTATE_k = _rtB->B_53_779_0;
_rtXdot->Integrator_CSTATE_h = _rtB->B_53_842_0;
_rtXdot->Tower_CSTATE_iw[0] += _rtP->P_292[0] * _rtX->Tower_CSTATE_iw[0];
_rtXdot->Tower_CSTATE_iw[0] += _rtP->P_292[1] * _rtX->Tower_CSTATE_iw[1];
_rtXdot->Tower_CSTATE_iw[1] += _rtP->P_292[2] * _rtX->Tower_CSTATE_iw[0];
_rtXdot->Tower_CSTATE_iw[0] += _rtP->P_293 * _rtB->B_53_803_0;
_rtXdot->rotorint_CSTATE_e = _rtB->B_53_835_0;
_rtXdot->Integrator_CSTATE_e = _rtB->B_53_898_0;
_rtXdot->Tower_CSTATE_b[0] += _rtP->P_305[0] * _rtX->Tower_CSTATE_b[0];
_rtXdot->Tower_CSTATE_b[0] += _rtP->P_305[1] * _rtX->Tower_CSTATE_b[1];
_rtXdot->Tower_CSTATE_b[1] += _rtP->P_305[2] * _rtX->Tower_CSTATE_b[0];
_rtXdot->Tower_CSTATE_b[0] += _rtP->P_306 * _rtB->B_53_859_0;
_rtXdot->rotorint_CSTATE_fa = _rtB->B_53_891_0;
_rtXdot->Integrator_CSTATE_md = _rtB->B_53_954_0;
_rtXdot->Tower_CSTATE_f[0] += _rtP->P_318[0] * _rtX->Tower_CSTATE_f[0];
_rtXdot->Tower_CSTATE_f[0] += _rtP->P_318[1] * _rtX->Tower_CSTATE_f[1];
_rtXdot->Tower_CSTATE_f[1] += _rtP->P_318[2] * _rtX->Tower_CSTATE_f[0];
_rtXdot->Tower_CSTATE_f[0] += _rtP->P_319 * _rtB->B_53_915_0;
_rtXdot->rotorint_CSTATE_o = _rtB->B_53_947_0;
_rtXdot->Integrator_CSTATE_o = _rtB->B_53_1010_0;
_rtXdot->Tower_CSTATE_m[0] += _rtP->P_331[0] * _rtX->Tower_CSTATE_m[0];
_rtXdot->Tower_CSTATE_m[0] += _rtP->P_331[1] * _rtX->Tower_CSTATE_m[1];
_rtXdot->Tower_CSTATE_m[1] += _rtP->P_331[2] * _rtX->Tower_CSTATE_m[0];
_rtXdot->Tower_CSTATE_m[0] += _rtP->P_332 * _rtB->B_53_971_0;
_rtXdot->rotorint_CSTATE_n = _rtB->B_53_1003_0;
_rtXdot->Integrator_CSTATE_j = _rtB->B_53_562_0;
_rtXdot->Tower_CSTATE_c[0] += _rtP->P_344[0] * _rtX->Tower_CSTATE_c[0];
_rtXdot->Tower_CSTATE_c[0] += _rtP->P_344[1] * _rtX->Tower_CSTATE_c[1];
_rtXdot->Tower_CSTATE_c[1] += _rtP->P_344[2] * _rtX->Tower_CSTATE_c[0];
_rtXdot->Tower_CSTATE_c[0] += _rtP->P_345 * _rtB->B_53_523_0;
_rtXdot->rotorint_CSTATE_ai = _rtB->B_53_555_0;
_rtXdot->torsionint_CSTATE = _rtB->B_53_492_0;
_rtXdot->torsionint_CSTATE_a = _rtB->B_53_604_0;
_rtXdot->torsionint_CSTATE_j = _rtB->B_53_660_0;
_rtXdot->torsionint_CSTATE_aj = _rtB->B_53_716_0;
_rtXdot->torsionint_CSTATE_n = _rtB->B_53_772_0;
_rtXdot->torsionint_CSTATE_jv = _rtB->B_53_828_0;
_rtXdot->torsionint_CSTATE_a4 = _rtB->B_53_884_0;
_rtXdot->torsionint_CSTATE_k = _rtB->B_53_940_0;
_rtXdot->torsionint_CSTATE_c = _rtB->B_53_996_0;
_rtXdot->torsionint_CSTATE_j2 = _rtB->B_53_548_0;
_rtXdot->Hydraulictimeconstant_CSTATE = 0.0;
_rtXdot->Hydraulictimeconstant_CSTATE += _rtP->P_424 * _rtX->Hydraulictimeconstant_CSTATE;
_rtXdot->Hydraulictimeconstant_CSTATE += _rtB->B_53_505_0;
_rtXdot->genIntegrator_CSTATE = _rtB->B_53_517_0;
_rtXdot->genIntegrator1_CSTATE = _rtB->B_53_518_0;
_rtXdot->Hydraulictimeconstant_CSTATE_c = 0.0;
_rtXdot->Hydraulictimeconstant_CSTATE_c += _rtP->P_469 * _rtX->Hydraulictimeconstant_CSTATE_c;
_rtXdot->Hydraulictimeconstant_CSTATE_c += _rtB->B_53_561_0;
_rtXdot->genIntegrator_CSTATE_e = _rtB->B_53_573_0;
_rtXdot->genIntegrator1_CSTATE_d = _rtB->B_53_574_0;
_rtXdot->Hydraulictimeconstant_CSTATE_d = 0.0;
_rtXdot->Hydraulictimeconstant_CSTATE_d += _rtP->P_514 * _rtX->Hydraulictimeconstant_CSTATE_d;
_rtXdot->Hydraulictimeconstant_CSTATE_d += _rtB->B_53_617_0;
_rtXdot->genIntegrator_CSTATE_i = _rtB->B_53_629_0;
_rtXdot->genIntegrator1_CSTATE_g = _rtB->B_53_630_0;
_rtXdot->Hydraulictimeconstant_CSTATE_h = 0.0;
_rtXdot->Hydraulictimeconstant_CSTATE_h += _rtP->P_559 * _rtX->Hydraulictimeconstant_CSTATE_h;
_rtXdot->Hydraulictimeconstant_CSTATE_h += _rtB->B_53_673_0;
_rtXdot->genIntegrator_CSTATE_j = _rtB->B_53_685_0;
_rtXdot->genIntegrator1_CSTATE_f = _rtB->B_53_686_0;
_rtXdot->Hydraulictimeconstant_CSTATE_g = 0.0;
_rtXdot->Hydraulictimeconstant_CSTATE_g += _rtP->P_604 * _rtX->Hydraulictimeconstant_CSTATE_g;
_rtXdot->Hydraulictimeconstant_CSTATE_g += _rtB->B_53_729_0;
_rtXdot->genIntegrator_CSTATE_d = _rtB->B_53_741_0;
_rtXdot->genIntegrator1_CSTATE_j = _rtB->B_53_742_0;
_rtXdot->Hydraulictimeconstant_CSTATE_j = 0.0;
_rtXdot->Hydraulictimeconstant_CSTATE_j += _rtP->P_649 * _rtX->Hydraulictimeconstant_CSTATE_j;
_rtXdot->Hydraulictimeconstant_CSTATE_j += _rtB->B_53_785_0;
_rtXdot->genIntegrator_CSTATE_a = _rtB->B_53_797_0;
_rtXdot->genIntegrator1_CSTATE_p = _rtB->B_53_798_0;
_rtXdot->Hydraulictimeconstant_CSTATE_k = 0.0;
_rtXdot->Hydraulictimeconstant_CSTATE_k += _rtP->P_694 * _rtX->Hydraulictimeconstant_CSTATE_k;
_rtXdot->Hydraulictimeconstant_CSTATE_k += _rtB->B_53_841_0;
_rtXdot->genIntegrator_CSTATE_m = _rtB->B_53_853_0;
_rtXdot->genIntegrator1_CSTATE_m = _rtB->B_53_854_0;
_rtXdot->Hydraulictimeconstant_CSTATE_f = 0.0;
_rtXdot->Hydraulictimeconstant_CSTATE_f += _rtP->P_739 * _rtX->Hydraulictimeconstant_CSTATE_f;
_rtXdot->Hydraulictimeconstant_CSTATE_f += _rtB->B_53_897_0;
_rtXdot->genIntegrator_CSTATE_ae = _rtB->B_53_909_0;
_rtXdot->genIntegrator1_CSTATE_h = _rtB->B_53_910_0;
_rtXdot->Hydraulictimeconstant_CSTATE_m = 0.0;
_rtXdot->Hydraulictimeconstant_CSTATE_m += _rtP->P_784 * _rtX->Hydraulictimeconstant_CSTATE_m;
_rtXdot->Hydraulictimeconstant_CSTATE_m += _rtB->B_53_953_0;
_rtXdot->genIntegrator_CSTATE_ju = _rtB->B_53_965_0;
_rtXdot->genIntegrator1_CSTATE_o = _rtB->B_53_966_0;
_rtXdot->Hydraulictimeconstant_CSTATE_e = 0.0;
_rtXdot->Hydraulictimeconstant_CSTATE_e += _rtP->P_829 * _rtX->Hydraulictimeconstant_CSTATE_e;
_rtXdot->Hydraulictimeconstant_CSTATE_e += _rtB->B_53_1009_0;
_rtXdot->genIntegrator_CSTATE_mc = _rtB->B_53_1021_0;
_rtXdot->genIntegrator1_CSTATE_gl = _rtB->B_53_1022_0;






    
  

      
    
        }
    
  


	
	      /* ZeroCrossings for root system: '<Root>' */
          #define MDL_ZERO_CROSSINGS
    
  
       static  void mdlZeroCrossings(SimStruct *S)
  {
  
        
  boolean_T anyStateSaturated;
B_benchmark_no_taylor_T *_rtB;
P_benchmark_no_taylor_T *_rtP;
X_benchmark_no_taylor_T *_rtX;
ZCV_benchmark_no_taylor_T *_rtZCSV;
DW_benchmark_no_taylor_T *_rtDW;

    
  

                
  

                              _rtDW = ((DW_benchmark_no_taylor_T *) ssGetRootDWork(S));
_rtZCSV = ((ZCV_benchmark_no_taylor_T *) ssGetSolverZcSignalVector(S));
_rtX = ((X_benchmark_no_taylor_T *) ssGetContStates(S));
_rtP = ((P_benchmark_no_taylor_T *) ssGetModelRtp(S));
_rtB = ((B_benchmark_no_taylor_T *) _ssGetModelBlockIO(S));
/* zero crossings for entering into limited region */
/* 0: INTG_NORMAL     1: INTG_LEAVING_UPPER_SAT  2: INTG_LEAVING_LOWER_SAT */
/* 3: INTG_UPPER_SAT  4: INTG_LOWER_SAT */
if ((_rtDW->Integrator_MODE == 1) && (_rtX->Integrator_CSTATE >= _rtP->P_45)) {
    _rtZCSV->Integrator_IntgUpLimit_ZC = 0.0;
} else {
    _rtZCSV->Integrator_IntgUpLimit_ZC = _rtX->Integrator_CSTATE - _rtP->P_45;
}
if ((_rtDW->Integrator_MODE == 2) && (_rtX->Integrator_CSTATE <= _rtP->P_46)) {
    _rtZCSV->Integrator_IntgLoLimit_ZC = 0.0;
} else {
    _rtZCSV->Integrator_IntgLoLimit_ZC = _rtX->Integrator_CSTATE - _rtP->P_46;
}
/* zero crossings for leaving limited region */
anyStateSaturated = false;
if ((_rtDW->Integrator_MODE == 3) || (_rtDW->Integrator_MODE == 4)) {
    anyStateSaturated = true;
}
if (anyStateSaturated) {
    _rtZCSV->Integrator_LeaveSaturate_ZC = _rtB->B_53_422_0;
} else {
    _rtZCSV->Integrator_LeaveSaturate_ZC = 0.0;
}
/* ZeroCrossings for FromWorkspace: '<S9>/FromWs' */                /* Call into Simulink */
      ssCallAccelRunBlock(S, 53, 29, SS_CALL_MDL_ZERO_CROSSINGS);
 






    
  

          }
    
  


      
/* Function to initialize sizes */
static void mdlInitializeSizes(SimStruct *S)
{

  /* checksum */
  ssSetChecksumVal(S, 0, 3588699819U);
  ssSetChecksumVal(S, 1, 1793692907U);
  ssSetChecksumVal(S, 2, 2882784040U);
  ssSetChecksumVal(S, 3, 3300417938U);
  
  { 
     /* First check to see if this is the sample verion of Simulink used 
      * to generate this file. If not force a rebuild and return. */
      mxArray *slVerStructMat = NULL;
      mxArray *slStrMat = mxCreateString("simulink");
      char slVerChar[10];
      int status = mexCallMATLAB(1,&slVerStructMat,
                                 1,&slStrMat,
                                 "ver");
      if(status == 0) {
          mxArray * slVerMat = mxGetField(slVerStructMat,0,"Version");
          if(slVerMat == NULL) {
            status = 1;
          } else {
            status = mxGetString(slVerMat, slVerChar, 10);
          }
      }      
      mxDestroyArray(slStrMat);
      mxDestroyArray(slVerStructMat);
      
      if((status == 1) || (strcmp(slVerChar,"8.8") != 0)) {
          return;
      } 
  }
  
  /* options */
  ssSetOptions(S, SS_OPTION_EXCEPTION_FREE_CODE);

    /* Accelerator check memory map size match for DWork */
      if (ssGetSizeofDWork(S) != sizeof(DW_benchmark_no_taylor_T)) {
	ssSetErrorStatus(S,"Unexpected error: Internal DWork sizes do "
	"not match for accelerator mex file.");
      }

    /* Accelerator check memory map size match for BlockIO */
    if (ssGetSizeofGlobalBlockIO(S) != sizeof(B_benchmark_no_taylor_T)) {
      ssSetErrorStatus(S,"Unexpected error: Internal BlockIO sizes do "
      "not match for accelerator mex file.");
    }
  
  

  
    /* Accelerator check memory map size match for Parameters */
    {
      int ssSizeofParams;
      ssGetSizeofParams(S,&ssSizeofParams);
      if (ssSizeofParams != sizeof(P_benchmark_no_taylor_T)) { 
         static char msg[256];
         sprintf(msg,"Unexpected error: Internal Parameters sizes do "
         "not match for accelerator mex file.");
       }
     }
    
    /* model parameters */
    _ssSetModelRtp(S, (real_T *) &benchmark_no_taylor_rtDefaultP);

      
    
  /* non-finites */
  
  rt_InitInfAndNaN(sizeof(real_T));
}

/* mdlInitializeSampleTimes function (used to set up function-call connections) */
static void mdlInitializeSampleTimes(SimStruct *S) { 
          /* register function-calls */
    {
      SimStruct *childS;
      SysOutputFcn *callSysFcns;
    
      	/* Level2 S-Function Block: '<S8>/B_0_0' (stateflow) */
	childS      = ssGetSFunction(S, 0);
	callSysFcns = ssGetCallSystemOutputFcnList(childS);
	      /* Unconnected function-call */
	      callSysFcns[3 + 0] = (SysOutputFcn) (NULL);
	
	/* Level2 S-Function Block: '<S10>/B_1_0' (stateflow) */
	childS      = ssGetSFunction(S, 1);
	callSysFcns = ssGetCallSystemOutputFcnList(childS);
	      /* Unconnected function-call */
	      callSysFcns[3 + 0] = (SysOutputFcn) (NULL);
	
	/* Level2 S-Function Block: '<S182>/B_23_0' (stateflow) */
	childS      = ssGetSFunction(S, 2);
	callSysFcns = ssGetCallSystemOutputFcnList(childS);
	      /* Unconnected function-call */
	      callSysFcns[3 + 0] = (SysOutputFcn) (NULL);
	
	/* Level2 S-Function Block: '<S206>/B_24_0' (stateflow) */
	childS      = ssGetSFunction(S, 3);
	callSysFcns = ssGetCallSystemOutputFcnList(childS);
	      /* Unconnected function-call */
	      callSysFcns[3 + 0] = (SysOutputFcn) (NULL);
	
	/* Level2 S-Function Block: '<S207>/B_25_0' (stateflow) */
	childS      = ssGetSFunction(S, 4);
	callSysFcns = ssGetCallSystemOutputFcnList(childS);
	      /* Unconnected function-call */
	      callSysFcns[3 + 0] = (SysOutputFcn) (NULL);
	
	/* Level2 S-Function Block: '<S208>/B_26_0' (stateflow) */
	childS      = ssGetSFunction(S, 5);
	callSysFcns = ssGetCallSystemOutputFcnList(childS);
	      /* Unconnected function-call */
	      callSysFcns[3 + 0] = (SysOutputFcn) (NULL);
	
	/* Level2 S-Function Block: '<S209>/B_27_0' (stateflow) */
	childS      = ssGetSFunction(S, 6);
	callSysFcns = ssGetCallSystemOutputFcnList(childS);
	      /* Unconnected function-call */
	      callSysFcns[3 + 0] = (SysOutputFcn) (NULL);
	
	/* Level2 S-Function Block: '<S210>/B_28_0' (stateflow) */
	childS      = ssGetSFunction(S, 7);
	callSysFcns = ssGetCallSystemOutputFcnList(childS);
	      /* Unconnected function-call */
	      callSysFcns[3 + 0] = (SysOutputFcn) (NULL);
	
	/* Level2 S-Function Block: '<S211>/B_29_0' (stateflow) */
	childS      = ssGetSFunction(S, 8);
	callSysFcns = ssGetCallSystemOutputFcnList(childS);
	      /* Unconnected function-call */
	      callSysFcns[3 + 0] = (SysOutputFcn) (NULL);
	
	/* Level2 S-Function Block: '<S212>/B_30_0' (stateflow) */
	childS      = ssGetSFunction(S, 9);
	callSysFcns = ssGetCallSystemOutputFcnList(childS);
	      /* Unconnected function-call */
	      callSysFcns[3 + 0] = (SysOutputFcn) (NULL);
	
	/* Level2 S-Function Block: '<S213>/B_31_0' (stateflow) */
	childS      = ssGetSFunction(S, 10);
	callSysFcns = ssGetCallSystemOutputFcnList(childS);
	      /* Unconnected function-call */
	      callSysFcns[3 + 0] = (SysOutputFcn) (NULL);
	
	/* Level2 S-Function Block: '<S214>/B_32_0' (stateflow) */
	childS      = ssGetSFunction(S, 11);
	callSysFcns = ssGetCallSystemOutputFcnList(childS);
	      /* Unconnected function-call */
	      callSysFcns[3 + 0] = (SysOutputFcn) (NULL);
	
	/* Level2 S-Function Block: '<S215>/B_33_0' (stateflow) */
	childS      = ssGetSFunction(S, 12);
	callSysFcns = ssGetCallSystemOutputFcnList(childS);
	      /* Unconnected function-call */
	      callSysFcns[3 + 0] = (SysOutputFcn) (NULL);
	
	/* Level2 S-Function Block: '<S217>/B_34_0' (stateflow) */
	childS      = ssGetSFunction(S, 13);
	callSysFcns = ssGetCallSystemOutputFcnList(childS);
	      /* Unconnected function-call */
	      callSysFcns[3 + 0] = (SysOutputFcn) (NULL);
	
	/* Level2 S-Function Block: '<S221>/B_35_0' (stateflow) */
	childS      = ssGetSFunction(S, 14);
	callSysFcns = ssGetCallSystemOutputFcnList(childS);
	      /* Unconnected function-call */
	      callSysFcns[3 + 0] = (SysOutputFcn) (NULL);
	
	/* Level2 S-Function Block: '<S225>/B_36_0' (stateflow) */
	childS      = ssGetSFunction(S, 15);
	callSysFcns = ssGetCallSystemOutputFcnList(childS);
	      /* Unconnected function-call */
	      callSysFcns[3 + 0] = (SysOutputFcn) (NULL);
	
	/* Level2 S-Function Block: '<S229>/B_37_0' (stateflow) */
	childS      = ssGetSFunction(S, 16);
	callSysFcns = ssGetCallSystemOutputFcnList(childS);
	      /* Unconnected function-call */
	      callSysFcns[3 + 0] = (SysOutputFcn) (NULL);
	
	/* Level2 S-Function Block: '<S233>/B_38_0' (stateflow) */
	childS      = ssGetSFunction(S, 17);
	callSysFcns = ssGetCallSystemOutputFcnList(childS);
	      /* Unconnected function-call */
	      callSysFcns[3 + 0] = (SysOutputFcn) (NULL);
	
	/* Level2 S-Function Block: '<S237>/B_39_0' (stateflow) */
	childS      = ssGetSFunction(S, 18);
	callSysFcns = ssGetCallSystemOutputFcnList(childS);
	      /* Unconnected function-call */
	      callSysFcns[3 + 0] = (SysOutputFcn) (NULL);
	
	/* Level2 S-Function Block: '<S241>/B_40_0' (stateflow) */
	childS      = ssGetSFunction(S, 19);
	callSysFcns = ssGetCallSystemOutputFcnList(childS);
	      /* Unconnected function-call */
	      callSysFcns[3 + 0] = (SysOutputFcn) (NULL);
	
	/* Level2 S-Function Block: '<S245>/B_41_0' (stateflow) */
	childS      = ssGetSFunction(S, 20);
	callSysFcns = ssGetCallSystemOutputFcnList(childS);
	      /* Unconnected function-call */
	      callSysFcns[3 + 0] = (SysOutputFcn) (NULL);
	
	/* Level2 S-Function Block: '<S249>/B_42_0' (stateflow) */
	childS      = ssGetSFunction(S, 21);
	callSysFcns = ssGetCallSystemOutputFcnList(childS);
	      /* Unconnected function-call */
	      callSysFcns[3 + 0] = (SysOutputFcn) (NULL);
	
	/* Level2 S-Function Block: '<S253>/B_43_0' (stateflow) */
	childS      = ssGetSFunction(S, 22);
	callSysFcns = ssGetCallSystemOutputFcnList(childS);
	      /* Unconnected function-call */
	      callSysFcns[3 + 0] = (SysOutputFcn) (NULL);
	
    }
    
    
        slAccRegPrmChangeFcn(S, mdlOutputsTID6);
}

/* Empty mdlTerminate function (never called) */
static void mdlTerminate(SimStruct *S) { }

/* MATLAB MEX Glue */
#include "simulink.c"

  
  
  
  
  
  
  
  
