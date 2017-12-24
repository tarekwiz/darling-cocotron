project(QuartzCore)

set(DYLIB_COMPAT_VERSION "1.2.0")
set(DYLIB_CURRENT_VERSION "1.11.0")

add_framework(QuartzCore
    FAT
    CURRENT_VERSION
    VERSION "A"

    SOURCES
	CAAnimationGroup.m
	CAAnimation.m
	CABase.m
	CABasicAnimation.m
	CALayerContext.m
	CALayer.m
	CAMediaTimingFunction.m
	CAPropertyAnimation.m
	CARenderer.m
	CATransactionGroup.m
	CATransaction.m
	CATransform3D.m
	CATransition.m
	CAValueFunction.m
	CAWindowOpenGLContext.m
	CIAffineTransform.m
	CIBloom.m
	CIBoxBlur.m
	CAAnimationGroup.m
	CIColor.m
	CIContext.m
	CIFilter.m
	CIImage.m
	CILinearGradient.m
	CIVector.m

    DEPENDENCIES
	CoreImage
	CoreVideo
	objc
	Accelerate
	CoreGraphics
	CoreText
	ImageIO
	IOSurface
	Metal
	OpenGL
	Security
	xml2
	cxx
	system
	CoreFoundation
	Foundation
	Onyx2D
)
