#import "X11SubWindow.h"
#import <AppKit/X11Window.h>
#import <AppKit/X11Display.h>

@implementation X11SubWindow

- (CGRect) convertFrame: (CGRect) frame {
    CGFloat top, left, bottom, right;
    CGNativeBorderFrameWidthsForStyle([_parent styleMask], &top, &left, &bottom, &right);
    frame.origin.y = [_parent frame].size.height - CGRectGetMaxY(frame);
    frame.origin.y -= top;
    frame.origin.x -= left;
    return frame;
}

- (id) initWithParentWindow: (X11Window *) parent frame: (CGRect) frame {
    _parent = parent;
    frame = [self convertFrame: frame];

    X11Display *x11Display = (X11Display *) [NSDisplay currentDisplay];
    _display = x11Display.display;

    /*
    static const GLint attrs[] = {
        GLX_RGBA,
        GLX_DOUBLEBUFFER,
        GLX_RED_SIZE, 4,
        GLX_GREEN_SIZE, 4,
        GLX_BLUE_SIZE, 4,
        GLX_DEPTH_SIZE, 4,
        None
    };
    int screen = DefaultScreen(_display);
    // TODO: get rid of glX here
    XVisualInfo *visualInfo = glXChooseVisual(display, screen, attrs);

    Colormap cmap = XCreateColormap(
        _display,
        RootWindow(_display, visualInfo->screen),
        visualInfo->visual,
        AllocNone
    );

    XSetWindowAttributes xattr = {0};
    xattr.colormap = cmap;
    xattr.border_pixel = 0;
    xattr.event_mask = ExposureMask | KeyPressMask | ButtonPressMask | StructureNotifyMask;
    */

    _window = XCreateSimpleWindow(
        _display, [parent windowHandle],
        frame.origin.x, frame.origin.y,
        frame.size.width, frame.size.height,
        0, 0, 0 /* border_width, border, background */
    );

    [self show];
    return self;
}

- (void) dealloc {
    XDestroyWindow(_display, _window);
    [super dealloc];
}

- (void *) nativeWindow {
    return (void *) _window;
}

- (void) show {
    XMapWindow(_display, _window);
}

- (void) hide {
    XUnmapWindow(_display, _window);
}

- (void) setFrame: (CGRect) frame {
    frame = [self convertFrame: frame];

    XMoveResizeWindow(_display, _window,
        frame.origin.x, frame.origin.y,
        frame.size.width, frame.size.height
    );
}

@end
