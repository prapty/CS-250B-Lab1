/*
 * Generated by Bluespec Compiler (build 629c10a)
 * 
 * On Fri Jun  4 23:21:45 UTC 2021
 * 
 * To automatically register this VPI wrapper with a Verilog simulator use:
 *     #include "vpi_wrapper_bdpiWriteSdram.h"
 *     void (*vlog_startup_routines[])() = { bdpiWriteSdram_vpi_register, 0u };
 */
#include <stdlib.h>
#include <vpi_user.h>
#include "bdpi.h"

/* the type of the wrapped function */
void bdpiWriteSdram(unsigned int , unsigned int );

/* VPI wrapper function */
PLI_INT32 bdpiWriteSdram_calltf(PLI_BYTE8 *user_data)
{
  vpiHandle hCall;
  unsigned int arg_1;
  unsigned int arg_2;
  vpiHandle *handle_array;
  
  /* retrieve handle array */
  hCall = vpi_handle(vpiSysTfCall, 0);
  handle_array = vpi_get_userdata(hCall);
  if (handle_array == NULL)
  {
    vpiHandle hArgList;
    hArgList = vpi_iterate(vpiArgument, hCall);
    handle_array = malloc(sizeof(vpiHandle) * 2u);
    handle_array[0u] = vpi_scan(hArgList);
    handle_array[1u] = vpi_scan(hArgList);
    vpi_put_userdata(hCall, handle_array);
    vpi_free_object(hArgList);
  }
  
  /* copy in argument values */
  get_vpi_arg(handle_array[0u], &arg_1, DIRECT);
  get_vpi_arg(handle_array[1u], &arg_2, DIRECT);
  
  /* call the imported C function */
  bdpiWriteSdram(arg_1, arg_2);
  
  /* free argument storage */
  free_vpi_args();
  vpi_free_object(hCall);
  
  return 0;
}

/* VPI wrapper registration function */
void bdpiWriteSdram_vpi_register()
{
  s_vpi_systf_data tf_data;
  
  /* Fill in registration data */
  tf_data.type = vpiSysTask;
  tf_data.tfname = "$imported_bdpiWriteSdram";
  tf_data.calltf = bdpiWriteSdram_calltf;
  tf_data.compiletf = 0u;
  tf_data.sizetf = 0u;
  tf_data.user_data = "$imported_bdpiWriteSdram";
  
  /* Register the function with VPI */
  vpi_register_systf(&tf_data);
}
