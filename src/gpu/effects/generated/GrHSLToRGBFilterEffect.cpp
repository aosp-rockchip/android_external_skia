/*
 * Copyright 2019 Google LLC
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

/**************************************************************************************************
 *** This file was autogenerated from GrHSLToRGBFilterEffect.fp; do not modify.
 **************************************************************************************************/
#include "GrHSLToRGBFilterEffect.h"

#include "src/gpu/GrTexture.h"
#include "src/gpu/glsl/GrGLSLFragmentProcessor.h"
#include "src/gpu/glsl/GrGLSLFragmentShaderBuilder.h"
#include "src/gpu/glsl/GrGLSLProgramBuilder.h"
#include "src/sksl/SkSLCPP.h"
#include "src/sksl/SkSLUtil.h"
class GrGLSLHSLToRGBFilterEffect : public GrGLSLFragmentProcessor {
public:
    GrGLSLHSLToRGBFilterEffect() {}
    void emitCode(EmitArgs& args) override {
        GrGLSLFPFragmentBuilder* fragBuilder = args.fFragBuilder;
        const GrHSLToRGBFilterEffect& _outer = args.fFp.cast<GrHSLToRGBFilterEffect>();
        (void)_outer;
        SkString _input543 = SkStringPrintf("%s", args.fInputColor);
        SkString _sample543;
        if (_outer.inputFP_index >= 0) {
            _sample543 = this->invokeChild(_outer.inputFP_index, _input543.c_str(), args);
        } else {
            _sample543 = "half4(1)";
        }
        fragBuilder->codeAppendf(
                "half4 inputColor = %s ? %s : %s;\nhalf3 hsl = inputColor.xyz;\nhalf C = (1.0 - "
                "abs(2.0 * hsl.z - 1.0)) * hsl.y;\nhalf3 p = hsl.xxx + half3(0.0, "
                "0.66666666666666663, 0.33333333333333331);\nhalf3 q = clamp(abs(fract(p) * 6.0 - "
                "3.0) - 1.0, 0.0, 1.0);\nhalf3 rgb = (q - 0.5) * C + hsl.z;\n%s = clamp(half4(rgb, "
                "inputColor.w), 0.0, 1.0);\n%s.xyz *= %s.w;\n",
                _outer.inputFP_index >= 0 ? "true" : "false", _sample543.c_str(), args.fInputColor,
                args.fOutputColor, args.fOutputColor, args.fOutputColor);
    }

private:
    void onSetData(const GrGLSLProgramDataManager& pdman,
                   const GrFragmentProcessor& _proc) override {}
};
GrGLSLFragmentProcessor* GrHSLToRGBFilterEffect::onCreateGLSLInstance() const {
    return new GrGLSLHSLToRGBFilterEffect();
}
void GrHSLToRGBFilterEffect::onGetGLSLProcessorKey(const GrShaderCaps& caps,
                                                   GrProcessorKeyBuilder* b) const {}
bool GrHSLToRGBFilterEffect::onIsEqual(const GrFragmentProcessor& other) const {
    const GrHSLToRGBFilterEffect& that = other.cast<GrHSLToRGBFilterEffect>();
    (void)that;
    return true;
}
GrHSLToRGBFilterEffect::GrHSLToRGBFilterEffect(const GrHSLToRGBFilterEffect& src)
        : INHERITED(kGrHSLToRGBFilterEffect_ClassID, src.optimizationFlags())
        , inputFP_index(src.inputFP_index) {
    if (inputFP_index >= 0) {
        auto clone = src.childProcessor(inputFP_index).clone();
        if (src.childProcessor(inputFP_index).isSampledWithExplicitCoords()) {
            clone->setSampledWithExplicitCoords();
        }
        this->registerChildProcessor(std::move(clone));
    }
}
std::unique_ptr<GrFragmentProcessor> GrHSLToRGBFilterEffect::clone() const {
    return std::unique_ptr<GrFragmentProcessor>(new GrHSLToRGBFilterEffect(*this));
}
