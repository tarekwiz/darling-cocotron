/* Copyright (c) 2006-2007 Christopher J. W. Lloyd

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE. */

/*****************************************************************************************
 * Note to programmers modifying or subclassing NSTextView:                              *
 *                                                                                       *
 * NSTextView uses undo coalescing to join adjacent keystrokes into one undo operation.  *
 * So you need to call breakUndoCoalescing before registering any other undo operations. *
 *****************************************************************************************/

#import <AppKit/NSText.h>
#import <AppKit/NSTextInput.h>
#import <AppKit/NSDragging.h>
#import <AppKit/NSParagraphStyle.h>
#import <AppKit/NSTextAttachmentCell.h>
#import <AppKit/NSTouchBarItem.h>
#import <AppKit/NSSharingService.h>

#import <Foundation/NSTextCheckingResult.h>

NS_ASSUME_NONNULL_BEGIN

@class NSTextStorage, NSLayoutManager, NSTextContainer, NSUndoManager;
@class NSRulerView, NSRulerMarker;

typedef enum {
    NSSelectByCharacter,
    NSSelectByWord,
    NSSelectByParagraph
} NSSelectionGranularity;

typedef enum {
    NSSelectionAffinityUpstream,
    NSSelectionAffinityDownstream,
} NSSelectionAffinity;

typedef enum {
    NSFindPanelActionShowFindPanel = 1,
    NSFindPanelActionNext,
    NSFindPanelActionPrevious,
    NSFindPanelActionReplaceAll,
    NSFindPanelActionReplace,
    NSFindPanelActionReplaceAndFind,
    NSFindPanelActionSetFindString,
    NSFindPanelActionReplaceAllInSelection,
    NSFindPanelActionSelectAll,
    NSFindPanelActionSelectAllInSelection
} NSFindPanelAction;

APPKIT_EXPORT NSString *const NSTextViewDidChangeSelectionNotification;
APPKIT_EXPORT NSString *const NSOldSelectedCharacterRange;

@class NSUndoTyping;

@interface NSTextView : NSText <NSTextInput> {
    NSTextStorage *_textStorage;
    NSTextContainer *_textContainer;
    NSSize _textContainerInset;
    BOOL _ownsTextStorage;
    NSDictionary *_typingAttributes;

    id _delegate;
    BOOL _isEditable;
    BOOL _isSelectable;
    BOOL _isRichText;
    NSColor *_backgroundColor;
    BOOL _drawsBackground;
    NSFont *_font;
    NSColor *_textColor;
    NSTextAlignment _textAlignment;

    NSColor *_insertionPointColor;
    NSRect _insertionPointRect;
    BOOL _insertionPointOn;
    NSTimer *_insertionPointTimer;

    BOOL _isFieldEditor;
    NSSize _maxSize;
    NSSize _minSize;
    BOOL _isHorizontallyResizable;
    BOOL _isVerticallyResizable;
    BOOL _usesRuler;
    BOOL _rulerVisible;
    BOOL _usesFontPanel;
    BOOL _allowsUndo;

    NSMutableArray *_selectedRanges;
    NSArray *_initialRanges; // selected ranges at the start of a selection change
    NSSelectionAffinity _selectionAffinity;
    NSSelectionGranularity _selectionGranularity;
    NSDictionary *_selectedTextAttributes;
    NSParagraphStyle *_defaultParagraphStyle;

    BOOL _didSendTextDidEndNotification;
    unsigned _selectionOrigin; // for keyboard selection sanity.
    id _killBuffer; // NSString for Emacs-style, NSMutableString for additive
    BOOL _killBufferIsAdditive; // .. additive == pine/pico style, but possible memory hog

    NSRange _rangeForUserCompletion; // range of original user completion text.
    NSString *_userCompletionHint; // original "hint" text which started completion
    NSArray *_userCompletions; // current list of completions. shouldn't change while modal
    int _userCompletionSelectedItem; // index within completion array

    NSUndoManager *_fieldEditorUndoManager;
    BOOL _processingKeyEvent;
    BOOL _firstResponderButNotEditingYet;

    NSInteger _spellCheckerDocumentTag;
    BOOL _isContinuousSpellCheckingEnabled;
    BOOL _isAutomaticSpellingCorrectionEnabled;
    NSTextCheckingTypes _enabledTextCheckingTypes;

    NSUndoTyping *_undoTyping;
}

- initWithFrame:(NSRect)frame textContainer:(NSTextContainer *)container;

- initWithFrame:(NSRect)frame;

- (NSTextContainer *)textContainer;

- (NSSize)textContainerInset;
- (NSPoint)textContainerOrigin;

- (NSLayoutManager *)layoutManager;
- (NSTextStorage *)textStorage;

- (void)insertText:(id)string;

- (BOOL)usesRuler;
- (BOOL)isRulerVisible;
- (BOOL)allowsUndo;
- (NSColor *)insertionPointColor;
- (NSDictionary *)typingAttributes;
- (NSDictionary *)selectedTextAttributes;
- (NSArray *)selectedRanges;
- (NSParagraphStyle *)defaultParagraphStyle;

- (void)setTextContainer:(NSTextContainer *)container;
- (void)setTextContainerInset:(NSSize)size;

- (void)setUsesRuler:(BOOL)flag;
- (void)setRulerVisible:(BOOL)flag;
- (void)setAllowsUndo:(BOOL)flag;
- (void)setInsertionPointColor:(NSColor *)color;
- (void)setTypingAttributes:(NSDictionary *)attributes;
- (void)setSelectedTextAttributes:(NSDictionary *)attributes;
- (void)setDefaultParagraphStyle:(NSParagraphStyle *)paragraphStyle;

- (NSRange)selectionRangeForProposedRange:(NSRange)range granularity:(NSSelectionGranularity)granularity;

- (void)setSelectedRange:(NSRange)range affinity:(NSSelectionAffinity)affinity stillSelecting:(BOOL)stillSelecting;
- (void)setSelectedRanges:(NSArray *)ranges affinity:(NSSelectionAffinity)affinity stillSelecting:(BOOL)stillSelecting;

- (void)setSelectedRanges:(NSArray *)value;

- (NSRange)rangeForUserCompletion;
- (NSArray *)completionsForPartialWordRange:(NSRange)range indexOfSelectedItem:(int *)index;
- (void)insertCompletion:(NSString *)string forPartialWordRange:(NSRange)range movement:(int)movement isFinal:(BOOL)isFinal;

- (NSArray *)writablePasteboardTypes;
- (BOOL)writeSelectionToPasteboard:(NSPasteboard *)pasteboard type:(NSString *)type;
- (BOOL)writeSelectionToPasteboard:(NSPasteboard *)pasteboard types:(NSArray *)types;

- (NSRange)rangeForUserTextChange;
- (NSRange)rangeForUserCharacterAttributeChange;
- (NSRange)rangeForUserParagraphAttributeChange;

- (BOOL)shouldChangeTextInRange:(NSRange)changeInRange replacementString:(NSString *)replacementString;
- (void)didChangeText;

- (BOOL)shouldDrawInsertionPoint;
- (void)drawInsertionPointInRect:(NSRect)rect color:(NSColor *)color turnedOn:(BOOL)turnedOn;
- (void)updateInsertionPointStateAndRestartTimer:(BOOL)restart;

- (void)updateRuler;

- (void)alignJustified:sender;

- (void)cut:sender;
- (void)copy:sender;
- (void)paste:sender;
- (void)selectAll:sender;

- (void)moveLeft:sender;
- (void)moveRight:sender;
- (void)moveForward:sender;
- (void)moveBackward:sender;
- (void)moveToBeginningOfLine:sender;
- (void)moveToEndOfLine:sender;

- (void)deleteForward:sender;
- (void)deleteBackward:sender;

- (void)pageUp:sender;
- (void)pageDown:sender;

- (NSDragOperation)dragOperationForDraggingInfo:(id<NSDraggingInfo>)info type:(NSString *)type;
- (void)cleanUpAfterDragOperation;

- (void)_setFieldEditorUndoManager:(NSUndoManager *)undoManager;
- (void)breakUndoCoalescing;

- (NSInteger)spellCheckerDocumentTag;

- (BOOL)isContinuousSpellCheckingEnabled;
- (void)setContinuousSpellCheckingEnabled:(BOOL)value;
- (void)toggleContinuousSpellChecking:sender;

- (BOOL)isAutomaticSpellingCorrectionEnabled;
- (void)setAutomaticSpellingCorrectionEnabled:(BOOL)value;
- (void)toggleAutomaticSpellingCorrection:sender;

- (NSTextCheckingTypes)enabledTextCheckingTypes;
- (void)setEnabledTextCheckingTypes:(NSTextCheckingTypes)checkingTypes;

- (void)setSpellingState:(NSInteger)value range:(NSRange)characterRange;

@end

@interface NSObject (NSTextView_undoManager)
- (NSUndoManager *)undoManagerForTextView:(NSTextView *)textView;
@end

@interface NSObject (NSTextView_delegate)

- (BOOL)textView:(NSTextView *)textView doCommandBySelector:(SEL)selector;
- (NSArray *)textView:(NSTextView *)textView completions:(NSArray *)words forPartialWordRange:(NSRange)range indexOfSelectedItem:(int *)index;

- (void)textViewDidChangeSelection:(NSNotification *)note;

- (NSRange)textView:(NSTextView *)textView willChangeSelectionFromCharacterRange:(NSRange)oldSelectedCharRange toCharacterRange:(NSRange)newSelectedCharRange;
- (NSArray *)textView:(NSTextView *)textView willChangeSelectionFromCharacterRanges:(NSArray *)oldSelectedCharRanges toCharacterRanges:(NSArray *)newSelectedCharRanges;

- (BOOL)textView:(NSTextView *)textView
    shouldChangeTextInRange:(NSRange)affectedCharRange
          replacementString:(NSString *)replacementString;

@end

@protocol NSTextViewDelegate <NSTextDelegate>
@optional

- (BOOL)textView:(NSTextView *)textView clickedOnLink:(id)link atIndex:(NSUInteger)charIndex;

- (void)textView:(NSTextView *)textView clickedOnCell:(id <NSTextAttachmentCell>)cell inRect:(NSRect)cellFrame atIndex:(NSUInteger)charIndex;

- (void)textView:(NSTextView *)textView doubleClickedOnCell:(id <NSTextAttachmentCell>)cell inRect:(NSRect)cellFrame atIndex:(NSUInteger)charIndex;

- (void)textView:(NSTextView *)view draggedCell:(id <NSTextAttachmentCell>)cell inRect:(NSRect)rect event:(NSEvent *)event atIndex:(NSUInteger)charIndex;

- (NSArray<NSString *> *)textView:(NSTextView *)view writablePasteboardTypesForCell:(id<NSTextAttachmentCell>)cell atIndex:(NSUInteger)charIndex;

- (BOOL)textView:(NSTextView *)view writeCell:(id <NSTextAttachmentCell>)cell atIndex:(NSUInteger)charIndex toPasteboard:(NSPasteboard *)pboard type:(NSString *)type;

- (NSRange)textView:(NSTextView *)textView willChangeSelectionFromCharacterRange:(NSRange)oldSelectedCharRange toCharacterRange:(NSRange)newSelectedCharRange;

- (NSArray<NSValue *> *)textView:(NSTextView *)textView willChangeSelectionFromCharacterRanges:(NSArray<NSValue *> *)oldSelectedCharRanges toCharacterRanges:(NSArray<NSValue *> *)newSelectedCharRanges;

- (BOOL)textView:(NSTextView *)textView shouldChangeTextInRanges:(NSArray<NSValue *> *)affectedRanges replacementStrings:(nullable NSArray<NSString *> *)replacementStrings;

- (NSDictionary<NSString *, id> *)textView:(NSTextView *)textView shouldChangeTypingAttributes:(NSDictionary<NSString *, id> *)oldTypingAttributes toAttributes:(NSDictionary<NSString *, id> *)newTypingAttributes;

- (void)textViewDidChangeSelection:(NSNotification *)notification;

- (void)textViewDidChangeTypingAttributes:(NSNotification *)notification;

- (nullable NSString *)textView:(NSTextView *)textView willDisplayToolTip:(NSString *)tooltip forCharacterAtIndex:(NSUInteger)characterIndex;

- (NSArray<NSString *> *)textView:(NSTextView *)textView completions:(NSArray<NSString *> *)words forPartialWordRange:(NSRange)charRange indexOfSelectedItem:(nullable NSInteger *)index;

- (BOOL)textView:(NSTextView *)textView shouldChangeTextInRange:(NSRange)affectedCharRange replacementString:(nullable NSString *)replacementString;

- (BOOL)textView:(NSTextView *)textView doCommandBySelector:(SEL)commandSelector;

- (NSInteger)textView:(NSTextView *)textView shouldSetSpellingState:(NSInteger)value range:(NSRange)affectedCharRange NS_AVAILABLE_MAC(10_5);

- (nullable NSMenu *)textView:(NSTextView *)view menu:(NSMenu *)menu forEvent:(NSEvent *)event atIndex:(NSUInteger)charIndex NS_AVAILABLE_MAC(10_5);

- (NSDictionary<NSString *, id> *)textView:(NSTextView *)view willCheckTextInRange:(NSRange)range options:(NSDictionary<NSString *, id> *)options types:(NSTextCheckingTypes *)checkingTypes NS_AVAILABLE_MAC(10_6);

- (NSArray<NSTextCheckingResult *> *)textView:(NSTextView *)view didCheckTextInRange:(NSRange)range types:(NSTextCheckingTypes)checkingTypes options:(NSDictionary<NSString *, id> *)options results:(NSArray<NSTextCheckingResult *> *)results orthography:(NSOrthography *)orthography wordCount:(NSInteger)wordCount NS_AVAILABLE_MAC(10_6);

- (nullable NSURL *)textView:(NSTextView *)textView URLForContentsOfTextAttachment:(NSTextAttachment *)textAttachment atIndex:(NSUInteger)charIndex NS_AVAILABLE_MAC(10_7);

- (nullable NSSharingServicePicker *)textView:(NSTextView *)textView willShowSharingServicePicker:(NSSharingServicePicker *)servicePicker forItems:(NSArray *)items NS_AVAILABLE_MAC(10_8);

- (nullable NSUndoManager *)undoManagerForTextView:(NSTextView *)view;

- (NSArray<NSTouchBarItemIdentifier> *)textView:(NSTextView *)textView shouldUpdateTouchBarItemIdentifiers:(NSArray<NSTouchBarItemIdentifier> *)identifiers NS_AVAILABLE_MAC(10_12_2);

- (nullable NSArray *)textView:(NSTextView *)textView candidatesForSelectedRange:(NSRange)selectedRange NS_AVAILABLE_MAC(10_12_2);

- (NSArray<NSTextCheckingResult *> *)textView:(NSTextView *)textView candidates:(NSArray<NSTextCheckingResult *> *)candidates forSelectedRange:(NSRange)selectedRange NS_AVAILABLE_MAC(10_12_2);

- (BOOL)textView:(NSTextView *)textView shouldSelectCandidateAtIndex:(NSUInteger)index NS_AVAILABLE_MAC(10_12_2);

- (BOOL)textView:(NSTextView *)textView clickedOnLink:(null_unspecified id)link NS_DEPRECATED_MAC(10_0, 10_6, "Use -textView:clickedOnLink:atIndex: instead");
- (void)textView:(NSTextView *)textView clickedOnCell:(null_unspecified id <NSTextAttachmentCell>)cell inRect:(NSRect)cellFrame NS_DEPRECATED_MAC(10_0, 10_6, "Use -textView:clickedOnCell:inRect:atIndex: instead");
- (void)textView:(NSTextView *)textView doubleClickedOnCell:(null_unspecified id <NSTextAttachmentCell>)cell inRect:(NSRect)cellFrame NS_DEPRECATED_MAC(10_0, 10_6, "Use -textView:doubleClickedOnCell:inRect:atIndex: instead");
- (void)textView:(NSTextView *)view draggedCell:(null_unspecified id <NSTextAttachmentCell>)cell inRect:(NSRect)rect event:(null_unspecified NSEvent *)event NS_DEPRECATED_MAC(10_0, 10_6, "Use -textView:draggedCell:inRect:event:atIndex: instead");

@end

NS_ASSUME_NONNULL_END
