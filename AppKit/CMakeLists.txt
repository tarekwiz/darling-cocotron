project(AppKit)

include(darling_framework)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} \
	-include math.h \
	-include stdlib.h \
	-include CoreFoundation/CoreFoundation.h \
	-include Foundation/Foundation.h \
	-Wno-nonportable-include-path \
	-Wno-deprecated-objc-isa-usage \
	-mmacosx-version-min=10.10"
)

find_package(X11 REQUIRED)
find_package(Freetype REQUIRED)

# We do not link to host's libGL (directly),
# but we still need to include its headers
find_package(OpenGL REQUIRED)

find_package(PkgConfig REQUIRED)
pkg_check_modules(PC_CAIRO cairo)
pkg_check_modules(PC_FONTCONFIG fontconfig)

include_directories(
	${CMAKE_SOURCE_DIR}/src/external/foundation/include
	${CMAKE_SOURCE_DIR}/src/external/foundation/include/Foundation
	${CMAKE_SOURCE_DIR}/src/external/corefoundation
	${CMAKE_SOURCE_DIR}/src/external/objc4/runtime
	${CMAKE_SOURCE_DIR}/src/external/libclosure
	${CMAKE_SOURCE_DIR}/src/external/security/include
	${CMAKE_SOURCE_DIR}/src/external/cfnetwork/include
	${CMAKE_SOURCE_DIR}/src/external/cfnetwork/private_include
	${CMAKE_SOURCE_DIR}/src/launchd/liblaunch
	${CMAKE_SOURCE_DIR}/src/libmalloc/include
	${CMAKE_SOURCE_DIR}/src/copyfile
	${CMAKE_SOURCE_DIR}/src/libc/gen
	${CMAKE_SOURCE_DIR}/src/external/icu/icuSources/i18n
	${CMAKE_SOURCE_DIR}/src/external/icu/icuSources/common
	${CMAKE_SOURCE_DIR}/src/external/libxml2/include
	${CMAKE_BINARY_DIR}/src/external/libxml2/include

	${CMAKE_CURRENT_SOURCE_DIR}
	${CMAKE_CURRENT_SOURCE_DIR}/..
	${CMAKE_CURRENT_SOURCE_DIR}/../CoreText

	${CMAKE_CURRENT_SOURCE_DIR}/nib.subproj
	${CMAKE_CURRENT_SOURCE_DIR}/NSColorPicker.subproj
	${CMAKE_CURRENT_SOURCE_DIR}/NSMenu.subproj
	${CMAKE_CURRENT_SOURCE_DIR}/NSTextView.subproj
	${CMAKE_CURRENT_SOURCE_DIR}/NSEvent.subproj
	${CMAKE_CURRENT_SOURCE_DIR}/NSColor.subproj
	${CMAKE_CURRENT_SOURCE_DIR}/X11.subproj
	${CMAKE_CURRENT_SOURCE_DIR}/RTF.subproj
	${CMAKE_CURRENT_SOURCE_DIR}/NSToolbar.subproj
	${CMAKE_CURRENT_SOURCE_DIR}/NSDrawer.subproj

	${X11_INCLUDE_DIRS}
	${FREETYPE_INCLUDE_DIRS}
	${OPENGL_INCLUDE_DIRS}
	${PC_CAIRO_INCLUDE_DIRS}
	${PC_FONTCONFIG_INCLUDE_DIRS}
)

set(AppKit_sources
	NSComboBox.m
	NSComboBoxCell.m
	NSWindowScripting.m
	NSGraphicsContext.m
	NSPageLayout.m
	NSTabViewItem.m
	NSText.m
	NSSpellCheckerTagData.m
	NSButtonCell.m
	NSLevelIndicatorCell.m
	NSPDFImageRep.m
	NSScroller.m
	NSCustomImageRep.m
	NSClipView.m
	NSApplication.m
	NSResponder.m
	NSColorList.m
	NSImageRep.m
	NSRulerView.m
	NSModalSessionX.m
	NSRuleEditorViewSliceRow.m
	NSMutableAttributedString.m
	NSRuleEditor.m
	NSWorkspace.m
	NSBezierPath.m
	NSWindowAnimationContext.m
	NSCellUndoManager.m
	NSFontPanelCell.m
	NSThemeFrame.m
	NSStringDrawer.m
	NSAffineTransform.m
	NSMeasurementUnit.m
	NSSpellChecker.m
	NSTokenAttachmentCell.m
	NSStatusBar.m
	NSSecureTextField.m
	NSScreen.m
	NSPrintOperation.m
	NSTextList.m
	NSComboBoxWindow.m
	NSSlider.m
	NSTableHeaderView.m
	NSComboBoxView.m
	NSSplitView.m
	NSSecureTextFieldCell.m
	NSPathCell.m
	NSWindow.m
	NSAlert.m
	NSCursor.m
	NSFontMetric.m
	NSPoofAnimation.m

	nib.subproj/NSButtonImageSource.m
	nib.subproj/NSNibBindingConnector.m
	nib.subproj/NSCustomResource.m
	nib.subproj/NSCustomObject.m
	nib.subproj/NSCustomView.m
	nib.subproj/NSNibConnector.m
	nib.subproj/NSNibHelpConnector.m
	nib.subproj/NSNibControlConnector.m
	nib.subproj/NSNibOutletConnector.m
	nib.subproj/NSNib.m
	nib.subproj/NSWindowTemplate.m
	nib.subproj/NSIBObjectData.m
	nib.subproj/NSNibLoading.m
	nib.subproj/NSClassSwapper.m
	nib.subproj/NSNibAXRelationshipConnector.m
	nib.subproj/NSIBUserDefinedRuntimeAttributesConnector.m

	NSTextFieldCell.m
	NSFormCell.m
	NSStepperCell.m
	NSParagraphStyle.m
	NSDatePicker.m
	NSGlyphGenerator.m

	CoreData_/_NSManagedProxy.m
	CoreData_/NSPersistentDocument.m

	NSPopUpWindow.m
	NSScrollView.m
	NSTextAttachmentCell.m
	NSInterfaceStyle.m
	NSFontTypeface.m
	NSBox.m
	NSPopUpButton.m
	NSDatePickerCell.m
	NSForm.m
	NSSheetContext.m

	NSTextTable/NSTextTableBlock.m
	NSTextTable/NSTextTable.m
	NSTextTable/NSTextBlock.m

	NSMutableParagraphStyle.m
	NSBrowser.m
	NSToolTipWindow.m
	NSPasteboard.m
	NSSearchFieldCell.m
	NSOutlineView.m
	NSDocument.m

	NSSegmentedControl/NSSegmentedControl.m
	NSSegmentedControl/NSSegmentedCell.m
	NSSegmentedControl/NSSegmentItem.m

	_NSRuleEditorViewSliceHolder.m
	NSSearchField.m
	NSFontPanel.m
	NSTrackingArea.m

	NSController/NSArrayController.m
	NSController/NSTreeController.m
	NSController/NSDictionaryController.m
	NSController/NSControllerMarker.m
	NSController/NSUserDefaultsControllerProxy.m
	NSController/NSObservationProxy.m
	NSController/NSObjectController.m
	NSController/NSController.m
	NSController/NSUserDefaultsController.m
	NSController/NSControllerSelectionProxy.m
	NSController/_NSControllerArray.m

	NSCursorRect.m
	NSImageCell.m

	NSColorPicker.subproj/NSColorPickerWheelView.m
	NSColorPicker.subproj/NSBrowserCellColorList.m
	NSColorPicker.subproj/NSColorPickerWheel.m
	NSColorPicker.subproj/NSColorPickerSliders.m
	NSColorPicker.subproj/NSColorPickerColorList.m
	NSColorPicker.subproj/NSColorPicker.m

	NSEPSImageRep.m
	NSPrintInfo.m

	NSMenu.subproj/NSMainMenuView.m
	NSMenu.subproj/NSMenuView.m
	NSMenu.subproj/NSOverflowMenuView.m
	NSMenu.subproj/NSSubmenuView.m
	NSMenu.subproj/NSMenuWindow.m
	NSMenu.subproj/NSMenu.m
	NSMenu.subproj/NSMenuItem.m

	NSPathControl.m
	NSSound.m
	NSFontManager.m
	NSTokenFieldCell.m
	NSBrowserCell.m
	NSControl.m
	NSViewController.m

	NSTextView.subproj/NSTextView.m
	NSTextView.subproj/NSBidiHelper.m
	NSTextView.subproj/NSLayoutManager.m
	NSTextView.subproj/NSTextViewSharedData.m
	NSTextView.subproj/NSTextStorage.m
	NSTextView.subproj/NSTypesetter_concrete.m
	NSTextView.subproj/NSTextStorage_concrete.m
	NSTextView.subproj/NSTypesetter.m
	NSTextView.subproj/NSRulerMarker+NSTextExtensions.m
	NSTextView.subproj/NSRangeArray.m
	NSTextView.subproj/NSTextContainer.m
	NSTextView.subproj/NSSecureLayoutManager.m
	NSTextView.subproj/NSUndoTextOperation.m
	NSTextView.subproj/NSSecureTextView.m
	NSTextView.subproj/NSTextTab.m

	NSTableColumn.m
	NSTextField.m

	NSEvent.subproj/NSEvent_periodic.m
	NSEvent.subproj/NSEvent_mouse.m
	NSEvent.subproj/NSEvent_CoreGraphics.m
	NSEvent.subproj/NSEvent_other.m
	NSEvent.subproj/NSEvent_keyboard.m
	NSEvent.subproj/NSEvent.m

	NSButton.m
	NSPrintPanel.m
	NSGlyphInfo.m
	NSWindowController.m
	NSColorSpace.m
	NSView.m

	NSAnimation/NSAnimation.m
	NSAnimation/NSViewAnimation.m
	NSAnimation/NSAnimationContext.m

	NSDocumentController.m
	NSStatusItem.m
	NSShadow.m
	NSPathComponentCell.m
	NSCachedImageRep.m
	NSWindow-Drag.m
	NSCIImageRep.m
	NSPrintProgressPanelController.m
	NSHelpManager.m
	NSProgressIndicator.m
	NSFontDescriptor.m
	NSDisplay.m

	NSOpenGL/NSOpenGLView.m
	NSOpenGL/NSOpenGLPixelBuffer.m
	NSOpenGL/NSOpenGLPixelFormat.m
	# NSOpenGL/NSOpenGLDrawable.m
	NSOpenGL/NSOpenGLContext.m

	NSPopUpButtonCell.m
	NSPredicateEditor.m
	NSFont.m
	NSStringDrawing.m
	NSTokenField.m

	NSColor.subproj/NSColor.m
	NSColor.subproj/NSColor_catalog.m
	NSColor.subproj/NSColor_CGColor.m

	NSTableCornerView.m
	NSTabView.m
	NSFontFamily.m
	NSGradient.m

	NSInterfacePart/NSInterfaceGraphics.m
	NSInterfacePart/NSInterfacePartAttributedString.m
	NSInterfacePart/NSInterfacePartDisabledAttributedString.m
	NSInterfacePart/NSGraphicsStyle.m
	NSInterfacePart/NSInterfacePart.m

	# X11.subproj/O2FontState_cairo.m
	X11.subproj/X11Event.m
	# X11.subproj/O2Surface_cairo.m
	X11.subproj/X11Window.m
	X11.subproj/X11SubWindow.m
	X11.subproj/KTFont_FT.m
	# O2Font_FT.m is built in Onyx2D
	# CGLContext.m no longer used
	# X11.subproj/NSOpenGLDrawable_X11.m
	# X11.subproj/O2Context_cairo.m
	X11.subproj/X11Display.m
	X11.subproj/O2Context_builtin_FT.m

	NSImageView.m
	NSActionCell.m
	NSAttributedString.m
	RTF.subproj/NSRichTextReader.m
	RTF.subproj/NSRichTextWriter.m
	NSRulerMarker.m
	NSTreeNode.m
	NSLevelIndicator.m
	NSDraggingManager.m
	NSImage.m

	NSKeyValueBinding/NSObject+BindingSupport.m
	NSKeyValueBinding/NSBinder.m
	NSKeyValueBinding/NSTextFieldBinder.m
	NSKeyValueBinding/NSMultipleValueBinder.m
	NSKeyValueBinding/NSTextBinder.m
	NSKeyValueBinding/NSKVOBinder.m
	NSKeyValueBinding/NSCachingBinder.m

	NSPredicateEditorRowTemplate.m
	NSFileWrapper.m

	NSToolbar.subproj/NSToolbarItemGroup.m
	NSToolbar.subproj/NSToolbarCustomizationView.m
	NSToolbar.subproj/NSToolbarView.m
	NSToolbar.subproj/NSToolbar.m
	NSToolbar.subproj/NSToolbarItem.m
	NSToolbar.subproj/NSToolbarCustomizationPalette.m
	NSToolbar.subproj/NSToolbarItemView.m

	NSBitmapImageRep.m

	NSDrawer.subproj/NSDrawer.m
	NSDrawer.subproj/NSDrawerWindow.m

	NSPrinter.m
	NSOpenPanel.m
	NSTableHeaderCell.m
	NSColorPanel.m
	NSCell.m
	NSPopUpView.m
	NSViewBackingLayer.m
	NSMatrix.m
	NSSliderCell.m
	NSTableView.m
	NSSpellingViewController.m

	NSSystemInfoPanel/NSSystemInfoPanel.m

	NSSavePanel.m
	NSDockTile.m
	NSGraphics.m
	NSColorWell.m
	NSAlertPanel.m
	NSPanel.m
	NSRuleEditorButtonCell.m

	NSKeyboardBinding/NSKeyboardBindingManager.m
	NSKeyboardBinding/NSKeyboardBinding.m

	NSTextAttachment.m

	NSCollectionView/NSCollectionViewItem.m
	NSCollectionView/NSCollectionView.m

	NSStepper.m
	NSAccessibility.m
)

set_source_files_properties(${AppKit_sources} LANGUAGE C)

set(DYLIB_COMPAT_VERSION "45.0.0")
set(DYLIB_CURRENT_VERSION "1499.11.0")

set(AppKit_resources
	Info.plist Info.plist

	StandardKeyBindings.keyBindings NSKeyboardBinding/StandardKeyBindings.keybindings

	NSRulerMarkerTab.tiff NSRulerMarkerTab.tiff
	NSSplitViewVDimple.tiff NSSplitViewVDimple.tiff
	NSBrowserCellArrow.tiff NSBrowserCellArrow.tiff
	NSPopUpButtonCellPopUp.tiff NSPopUpButtonCellPopUp.tiff
	NSSplitViewHDimple.tiff NSSplitViewHDimple.tiff
	NSHighlightedBrowserCellArrow.tiff NSHighlightedBrowserCellArrow.tiff
	NSAlertPanelExclamation.tiff NSAlertPanelExclamation.tiff
	NSSwitch.tiff NSSwitch.tiff
	NSHighlightedRadioButton.tiff NSHighlightedRadioButton.tiff
	NSComboBoxCellDown.tiff NSComboBoxCellDown.tiff
	NSRadioButton.tiff NSRadioButton.tiff
	NSHighlightedSwitch.tiff NSHighlightedSwitch.tiff
	NSPopUpButtonCellPullDown.tiff NSPopUpButtonCellPullDown.tiff

	NSApplicationIcon.tiff NSSystemInfoPanel/NSApplicationIcon.tiff

	NSMenuArrow.tiff NSMenu.subproj/NSMenuArrow.tiff
	NSMenuViewDoubleRightArrowGray.tiff NSMenu.subproj/NSMenuViewDoubleRightArrowGray.tiff
	NSMenuViewDoubleRightArrow.tiff NSMenu.subproj/NSMenuViewDoubleRightArrow.tiff

	NSToolbarOverflowArrow.tiff NSToolbar.subproj/NSToolbarOverflowArrow.tiff
	NSToolbarPrintItem.tiff NSToolbar.subproj/NSToolbarPrintItem.tiff
	NSToolbarMoreToolbarItems.tiff NSToolbar.subproj/NSToolbarMoreToolbarItems.tiff
	NSToolbarShowColorsItem.tiff NSToolbar.subproj/NSToolbarShowColorsItem.tiff
	NSToolbarShowFontsItem.tiff NSToolbar.subproj/NSToolbarShowFontsItem.tiff
	NSToolbarCustomizeToolbarItem.tiff NSToolbar.subproj/NSToolbarCustomizeToolbarItem.tiff

	NSColorPickerSlidersHSB.tiff NSColorPicker.subproj/NSColorPickerSlidersHSB.tiff
	NSColorPickerColorList.tiff NSColorPicker.subproj/NSColorPickerColorList.tiff
	NSColorPickerSlidersCMYK.tiff NSColorPicker.subproj/NSColorPickerSlidersCMYK.tiff
	NSColorPickerSlidersGray.tiff NSColorPicker.subproj/NSColorPickerSlidersGray.tiff
	NSColorPickerSlidersRGB.tiff NSColorPicker.subproj/NSColorPickerSlidersRGB.tiff

	NSColorPickerSlidersIcon.png NSColorPicker.subproj/NSColorPickerSlidersIcon.png
	NSColorWheel.png NSColorPicker.subproj/NSColorWheel.png
	NSColorPickerListIcon.png NSColorPicker.subproj/NSColorPickerListIcon.png
	NSColorPickerWheelIcon.png NSColorPicker.subproj/NSColorPickerWheelIcon.png

	en.lproj/NSColorPickerWheel.nib NSColorPicker.subproj/en.lproj/NSColorPickerWheel.nib/keyedobjects.nib
	en.lproj/NSColorPickerColorList.nib NSColorPicker.subproj/en.lproj/NSColorPickerColorList.nib/keyedobjects.nib
	en.lproj/NSColorPickerSliders.nib NSColorPicker.subproj/en.lproj/NSColorPickerSliders.nib/keyedobjects.nib

	en.lproj/NSColorPanel.nib en.lproj/NSColorPanel.nib/keyedobjects.nib
)

add_framework(AppKit
	FAT
	CURRENT_VERSION
	SOURCES
		${AppKit_sources}
	RESOURCES
		${AppKit_resources}
	VERSION "C"
	DEPENDENCIES
		objc
		system
		CoreFoundation
		Foundation
		Onyx2D
		CoreText
		CoreData
		OpenGL
               QuartzCore
               CoreGraphics
		# native libraries
		FreeType
		fontconfig
		X11
		jpeg png tiff
)
