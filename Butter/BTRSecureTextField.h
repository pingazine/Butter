//
//  BTRSecureTextField.h
//  Butter
//
//  Created by Indragie Karunaratne on 2012-12-28.
//  Copyright (c) 2012 ButterKit. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "BTRControl.h"
#import "BTRImageView.h"

// BTRSecureTextField should *not* be layer backed in Interface Builder
// This leads to a bug that causes an additional shadow to be shown
// underneath the field
@interface BTRSecureTextField : NSSecureTextField
- (NSImage *)backgroundImageForControlState:(BTRControlState)state;
- (void)setBackgroundImage:(NSImage *)image forControlState:(BTRControlState)state;

// Modifies the contentMode on the underlying image view.
@property (nonatomic, assign) BTRViewContentMode contentMode;
@property (nonatomic, assign) BOOL animatesContents;

// Reimplementation of BTRControl API
@property (nonatomic, readonly) BTRControlState state;
@property (nonatomic, getter = isHighlighted) BOOL highlighted;
@property (nonatomic, readonly) NSInteger clickCount;

- (void)addBlock:(void (^)(BTRControlEvents events))block forControlEvents:(BTRControlEvents)events;
@end