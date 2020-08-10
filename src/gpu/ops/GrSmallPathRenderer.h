/*
 * Copyright 2014 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef GrSmallPathRenderer_DEFINED
#define GrSmallPathRenderer_DEFINED

#include "src/gpu/GrPathRenderer.h"

class GrDrawOp;
class GrRecordingContext;
class GrSmallPathAtlasMgr;
class GrStyledShape;

class GrSmallPathRenderer : public GrPathRenderer {
public:
    GrSmallPathRenderer();
    ~GrSmallPathRenderer() override;

    const char* name() const final { return "Small"; }

    void addToOnFlushCallbacks(GrRecordingContext*);

    static std::unique_ptr<GrDrawOp> createOp_TestingOnly(GrRecordingContext*,
                                                          GrPaint&&,
                                                          const GrStyledShape&,
                                                          const SkMatrix& viewMatrix,
                                                          GrSmallPathAtlasMgr*,
                                                          bool gammaCorrect,
                                                          const GrUserStencilSettings*);
    struct PathTestStruct;

private:
    class SmallPathOp;

    StencilSupport onGetStencilSupport(const GrStyledShape&) const override {
        return GrPathRenderer::kNoSupport_StencilSupport;
    }

    CanDrawPath onCanDrawPath(const CanDrawPathArgs&) const override;

    bool onDrawPath(const DrawPathArgs&) override;

    std::unique_ptr<GrSmallPathAtlasMgr> fAtlasMgr;

    typedef GrPathRenderer INHERITED;
};

#endif
