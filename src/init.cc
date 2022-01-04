#include <libyuv.h>
#include "convert.h"
#include "cpu_id.h"
#include "init.h"
#include "rotate_argb.h"
#include "rotate.h"
#include "scale_argb.h"
#include "scale.h"
#include "version.h"
#include "config.h"

static Napi::Object Init(Napi::Env env, Napi::Object exports) {
    
    // convert.cc
    exports.Set("I444ToI420", Napi::Function::New(env, I444ToI420));
    exports.Set("I444ToNV12", Napi::Function::New(env, I444ToNV12));
    exports.Set("I444ToNV21", Napi::Function::New(env, I444ToNV21));
    exports.Set("I422ToI420", Napi::Function::New(env, I422ToI420));
    exports.Set("I422ToNV21", Napi::Function::New(env, I422ToNV21));
    exports.Set("I420Copy", Napi::Function::New(env, I420Copy));
    exports.Set("I010Copy", Napi::Function::New(env, I010Copy));
    exports.Set("I010ToI420", Napi::Function::New(env, I010ToI420));
    exports.Set("I400ToI420", Napi::Function::New(env, I400ToI420));
    exports.Set("I400ToNV21", Napi::Function::New(env, I400ToNV21));
    exports.Set("NV12ToI420", Napi::Function::New(env, NV12ToI420));
    exports.Set("NV21ToI420", Napi::Function::New(env, NV21ToI420));
    exports.Set("YUY2ToI420", Napi::Function::New(env, YUY2ToI420));
    exports.Set("UYVYToI420", Napi::Function::New(env, UYVYToI420));
    exports.Set("AYUVToNV12", Napi::Function::New(env, AYUVToNV12));
    exports.Set("AYUVToNV21", Napi::Function::New(env, AYUVToNV21));
    exports.Set("Android420ToI420", Napi::Function::New(env, Android420ToI420));
    exports.Set("ARGBToI420", Napi::Function::New(env, ARGBToI420));
    exports.Set("BGRAToI420", Napi::Function::New(env, BGRAToI420));
    exports.Set("ABGRToI420", Napi::Function::New(env, ABGRToI420));
    exports.Set("RGBAToI420", Napi::Function::New(env, RGBAToI420));
    exports.Set("RGB24ToI420", Napi::Function::New(env, RGB24ToI420));
    exports.Set("RGB24ToJ420", Napi::Function::New(env, RGB24ToJ420));
    exports.Set("RAWToI420", Napi::Function::New(env, RAWToI420));
    exports.Set("RGB565ToI420", Napi::Function::New(env, RGB565ToI420));
    exports.Set("ARGB1555ToI420", Napi::Function::New(env, ARGB1555ToI420));
    exports.Set("ARGB4444ToI420", Napi::Function::New(env, ARGB4444ToI420));
    exports.Set("RGB24ToJ400", Napi::Function::New(env, RGB24ToJ400));
    exports.Set("RAWToJ400", Napi::Function::New(env, RAWToJ400));
    
#ifdef HAVE_JPEG
    exports.Set("MJPGToI420", Napi::Function::New(env, MJPGToI420));
    exports.Set("MJPGToNV21", Napi::Function::New(env, MJPGToNV21));
    exports.Set("MJPGSize", Napi::Function::New(env, MJPGSize));
#endif
    exports.Set("ConvertToI420", Napi::Function::New(env, ConvertToI420));

 

    // cpu_id

    exports.Set("InitCpuFlags", Napi::Function::New(env, InitCpuFlags));
    exports.Set("TestCpuFlag", Napi::Function::New(env, TestCpuFlag));
    exports.Set("ArmCpuCaps", Napi::Function::New(env, ArmCpuCaps));
    exports.Set("MipsCpuCaps", Napi::Function::New(env, MipsCpuCaps));
    exports.Set("MaskCpuFlags", Napi::Function::New(env, MaskCpuFlags));
    exports.Set("SetCpuFlags", Napi::Function::New(env, SetCpuFlags));
    exports.Set("CpuId", Napi::Function::New(env, CpuId));

    // rotate_argb.h

    exports.Set("ARGBRotate", Napi::Function::New(env, ARGBRotate));

    // rotate.h

    exports.Set("I420Rotate", Napi::Function::New(env, I420Rotate));
    exports.Set("I444Rotate", Napi::Function::New(env, I444Rotate));
    exports.Set("NV12ToI420Rotate", Napi::Function::New(env, NV12ToI420Rotate));
    exports.Set("RotatePlane", Napi::Function::New(env, RotatePlane));
    exports.Set("RotatePlane90", Napi::Function::New(env, RotatePlane90));
    exports.Set("RotatePlane180", Napi::Function::New(env, RotatePlane180));
    exports.Set("RotatePlane270", Napi::Function::New(env, RotatePlane270));
    exports.Set("RotateUV90", Napi::Function::New(env, RotateUV90));
    exports.Set("RotateUV180", Napi::Function::New(env, RotateUV180));
    exports.Set("RotateUV270", Napi::Function::New(env, RotateUV270));
    exports.Set("TransposePlane", Napi::Function::New(env, TransposePlane));
    exports.Set("TransposeUV", Napi::Function::New(env, TransposeUV));

    // scale_argb.h

    exports.Set("ARGBScale", Napi::Function::New(env, ARGBScale));
    exports.Set("ARGBScaleClip", Napi::Function::New(env, ARGBScaleClip));
    exports.Set("YUVToARGBScaleClip", Napi::Function::New(env, YUVToARGBScaleClip));

    // scale.h

    exports.Set("ScalePlane", Napi::Function::New(env, ScalePlane));
    exports.Set("ScalePlane_16", Napi::Function::New(env, ScalePlane_16));
    exports.Set("I420Scale", Napi::Function::New(env, I420Scale));
    exports.Set("I420Scale_16", Napi::Function::New(env, I420Scale_16));
    exports.Set("I444Scale", Napi::Function::New(env, I444Scale));
    exports.Set("I444Scale_16", Napi::Function::New(env, I444Scale_16));
    exports.Set("Scale", Napi::Function::New(env, Scale));

    // version.h

    exports.Set("Version", Napi::Function::New(env, Version));

    return exports;
}

NODE_API_MODULE(libyuv, Init);