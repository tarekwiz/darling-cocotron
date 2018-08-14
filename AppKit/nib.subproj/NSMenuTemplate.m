#import "NSMenuTemplate.h"

@implementation NSMenuTemplate

- (void) dealloc
{
	[_realObject release];
	[_menuClass release];
	[super dealloc];
}

- (void) setClassName: (NSString *)className
{
	[_menuClass release];
	_menuClass = [className retain];
}

- (NSString *)className
{
	return _menuClass;
}

- (void) setRealObject: (id)o
{
	[_realObject release];
	_realObject = [o retain];
}

- (id) realObject
{
	return _realObject;
}

@end

