/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 2.0.11
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package com.truenorth.wrappers;

public class YacuDecu_swig {
  public static SWIGTYPE_p_float new_float_array(int nelements) {
    long cPtr = YacuDecu_swigJNI.new_float_array(nelements);
    return (cPtr == 0) ? null : new SWIGTYPE_p_float(cPtr, false);
  }

  public static void delete_float_array(SWIGTYPE_p_float ary) {
    YacuDecu_swigJNI.delete_float_array(SWIGTYPE_p_float.getCPtr(ary));
  }

  public static float float_array_getitem(SWIGTYPE_p_float ary, int index) {
    return YacuDecu_swigJNI.float_array_getitem(SWIGTYPE_p_float.getCPtr(ary), index);
  }

  public static void float_array_setitem(SWIGTYPE_p_float ary, int index, float value) {
    YacuDecu_swigJNI.float_array_setitem(SWIGTYPE_p_float.getCPtr(ary), index, value);
  }

  public static int deconv_device(long iter, long N1, long N2, long N3, float[] h_image, float[] h_psf, float[] h_object) {
    return YacuDecu_swigJNI.deconv_device(iter, N1, N2, N3, h_image, h_psf, h_object);
  }

}
