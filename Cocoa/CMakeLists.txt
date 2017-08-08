project(Cocoa)

add_compile_options(
	-mmacosx-version-min=10.10
)

set(Cocoa_sources
	Cocoa.m
)

set_source_files_properties(${Cocoa_sources} LANGUAGE C)

add_framework(Cocoa
	FAT
	CURRENT_VERSION
	SOURCES
		${Cocoa_sources}
	VERSION "A"
	DEPENDENCIES
		objc
		system
		Foundation
		AppKit
		CoreData
)
