  
    /*
  * benchmark_no_taylor_acc_types.h
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


  #ifndef RTW_HEADER_benchmark_no_taylor_acc_types_h_
  #define RTW_HEADER_benchmark_no_taylor_acc_types_h_
  
      

  
#include "rtwtypes.h"

#include "multiword_types.h"

  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  




      


          
	    #ifndef DEFINED_TYPEDEF_FOR_struct_CsJyhGkr8N4n2UEi9fjhb_
	    #define DEFINED_TYPEDEF_FOR_struct_CsJyhGkr8N4n2UEi9fjhb_
                    
            typedef struct {            
          
            
            
            
             real_T radius[10];
            
            
            
             real_T rated[10];
            
            
            
             real_T Cp[10];
            
            
            
             real_T rho;
            
            
            
             real_T N;
          
            } struct_CsJyhGkr8N4n2UEi9fjhb;

            #endif
          






      


          
	    #ifndef DEFINED_TYPEDEF_FOR_struct_XxmJ13vfHAkNSLaiAJHgGC_
	    #define DEFINED_TYPEDEF_FOR_struct_XxmJ13vfHAkNSLaiAJHgGC_
                    
            typedef struct {            
          
            
            
            
             real_T Ts;
            
            
            
             real_T mode;
            
            
            
             real_T settings;
            
            
            
             real_T delay;
          
            } struct_XxmJ13vfHAkNSLaiAJHgGC;

            #endif
          






      


          
	    #ifndef DEFINED_TYPEDEF_FOR_struct_5sVzCZLUOrRBX29Yr8vJYE_
	    #define DEFINED_TYPEDEF_FOR_struct_5sVzCZLUOrRBX29Yr8vJYE_
                    
            typedef struct {            
          
            
            
            
             real_T x[10];
            
            
            
             real_T y[10];
          
            } struct_5sVzCZLUOrRBX29Yr8vJYE;

            #endif
          






      


          
	    #ifndef DEFINED_TYPEDEF_FOR_struct_gPvlIsSPZOuejX9y6ADWYH_
	    #define DEFINED_TYPEDEF_FOR_struct_gPvlIsSPZOuejX9y6ADWYH_
                    
            typedef struct {            
          
            
            
            
             real_T r[10];
          
            } struct_gPvlIsSPZOuejX9y6ADWYH;

            #endif
          






      


          
	    #ifndef DEFINED_TYPEDEF_FOR_struct_PHIXY0GEtWQsAQQbCno1GE_
	    #define DEFINED_TYPEDEF_FOR_struct_PHIXY0GEtWQsAQQbCno1GE_
                    
            typedef struct {            
          
            
            
            
             struct_5sVzCZLUOrRBX29Yr8vJYE farm;
            
            
            
             struct_gPvlIsSPZOuejX9y6ADWYH rotor;
          
            } struct_PHIXY0GEtWQsAQQbCno1GE;

            #endif
          






      


          
	    #ifndef DEFINED_TYPEDEF_FOR_struct_LpqIQe0MWRirC0OuYjDhFF_
	    #define DEFINED_TYPEDEF_FOR_struct_LpqIQe0MWRirC0OuYjDhFF_
                    
            typedef struct {            
          
            
            
            
             real_T size;
            
            
            
             real_T ysize;
            
            
            
             real_T xsize;
          
            } struct_LpqIQe0MWRirC0OuYjDhFF;

            #endif
          






      


          
	    #ifndef DEFINED_TYPEDEF_FOR_struct_0o29Y9lj6DgYYRqT2M5cBC_
	    #define DEFINED_TYPEDEF_FOR_struct_0o29Y9lj6DgYYRqT2M5cBC_
                    
            typedef struct {            
          
            
            
            
             real_T r;
          
            } struct_0o29Y9lj6DgYYRqT2M5cBC;

            #endif
          






      


          
	    #ifndef DEFINED_TYPEDEF_FOR_struct_ZkjHojDfhdY0e02ZCRtSaD_
	    #define DEFINED_TYPEDEF_FOR_struct_ZkjHojDfhdY0e02ZCRtSaD_
                    
            typedef struct {            
          
            
            
            
             real_T r[134];
          
            } struct_ZkjHojDfhdY0e02ZCRtSaD;

            #endif
          






      


          
	    #ifndef DEFINED_TYPEDEF_FOR_struct_lZvEVDfU4SabxPRkWbbjkF_
	    #define DEFINED_TYPEDEF_FOR_struct_lZvEVDfU4SabxPRkWbbjkF_
                    
            typedef struct {            
          
            
            
            
             real_T x;
            
            
            
             real_T y;
            
            
            
             struct_0o29Y9lj6DgYYRqT2M5cBC rotor;
            
            
            
             real_T num;
            
            
            
             struct_ZkjHojDfhdY0e02ZCRtSaD meand;
          
            } struct_lZvEVDfU4SabxPRkWbbjkF;

            #endif
          






      


          
	    #ifndef DEFINED_TYPEDEF_FOR_struct_LG9swig3xs39R8wGIOptUF_
	    #define DEFINED_TYPEDEF_FOR_struct_LG9swig3xs39R8wGIOptUF_
                    
            typedef struct {            
          
            
            
            
             struct_5sVzCZLUOrRBX29Yr8vJYE farm;
            
            
            
             struct_LpqIQe0MWRirC0OuYjDhFF grid;
            
            
            
             struct_lZvEVDfU4SabxPRkWbbjkF wt;
            
            
            
             real_T alpha;
            
            
            
             real_T k;
            
            
            
             real_T ts;
          
            } struct_LG9swig3xs39R8wGIOptUF;

            #endif
          






      


          
	    #ifndef DEFINED_TYPEDEF_FOR_struct_y3RzpqBmu9D4ZSdlM53gkD_
	    #define DEFINED_TYPEDEF_FOR_struct_y3RzpqBmu9D4ZSdlM53gkD_
                    
            typedef struct {            
          
            
            
            
             struct_5sVzCZLUOrRBX29Yr8vJYE farm;
            
            
            
             struct_LpqIQe0MWRirC0OuYjDhFF grid;
            
            
            
             struct_lZvEVDfU4SabxPRkWbbjkF wt;
            
            
            
             real_T alpha;
            
            
            
             real_T k;
            
            
            
             real_T ts;
            
            
            
             real_T wind_grid;
            
            
            
             real_T wind[9009];
          
            } struct_y3RzpqBmu9D4ZSdlM53gkD;

            #endif
          

      
            /* Parameters for system: '<S23>/B_44_57' */
       typedef struct P_Pitchcontroller_benchmark_no_taylor_T_ P_Pitchcontroller_benchmark_no_taylor_T;
      
            /* Parameters (auto storage) */
       typedef struct P_benchmark_no_taylor_T_ P_benchmark_no_taylor_T;

  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  

    #endif /* RTW_HEADER_benchmark_no_taylor_acc_types_h_ */
