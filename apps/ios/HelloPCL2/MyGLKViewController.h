/*=========================================================================

Program:   Visualization Toolkit

Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
All rights reserved.
See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

This software is distributed WITHOUT ANY WARRANTY; without even
the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
PURPOSE.  See the above copyright notice for more information.

=========================================================================*/

#import <UIKit/UIKit.h>
#import <GLKit/GLKit.h>

#import "LoadDataController.h"

// Note: This file should be includable by both pure Objective-C and Objective-C++ source files.
// To achieve this, we use the neat technique below:
#ifdef __cplusplus
  // Forward declarations
  class vtkIOSRenderWindow;
  class vtkIOSRenderWindowInteractor;

  // Type declarations
  typedef vtkIOSRenderWindow *vtkIOSRenderWindowRef;
  typedef vtkIOSRenderWindowInteractor *vtkIOSRenderWindowInteractorRef;
#else
  // Type declarations
  typedef void *vtkIOSRenderWindowRef;
  typedef void *vtkIOSRenderWindowInteractorRef;
#endif

@interface MyGLKViewController : GLKViewController
{
  @private
  vtkIOSRenderWindowRef _myVTKRenderWindow;

  UIAlertView* waitDialog;
  dispatch_queue_t myQueue;
  LoadDataController *_dataLoader;
  UIPopoverController *_loadDataPopover;
}

@property (nonatomic, strong) UIWindow *window;
@property (nonatomic, retain) LoadDataController *dataLoader;
@property (nonatomic, retain) UIPopoverController *loadDataPopover;
// @property (nonatomic, retain) IBOutlet UILabel *opacityLabel;
// @property (nonatomic, retain) IBOutlet UISlider *opacitySlider;
// @property (nonatomic, retain) IBOutlet UILabel *voxelLabel;
// @property (nonatomic, retain) IBOutlet UISegmentedControl *voxelButtons;
// @property (nonatomic, retain) IBOutlet UILabel *ransacLabel;
// @property (nonatomic, retain) IBOutlet UISegmentedControl *ransacButtons;
// @property (nonatomic, retain) IBOutlet UIActivityIndicatorView *voxelIndicator;
// @property (nonatomic, retain) IBOutlet UIActivityIndicatorView *ransacIndicator;
@property (nonatomic, retain) UILabel *opacityLabel;
@property (nonatomic, retain) UISlider *opacitySlider;
@property (nonatomic, retain) UILabel *voxelLabel;
@property (nonatomic, retain) UISegmentedControl *voxelButtons;
@property (nonatomic, retain) UILabel *ransacLabel;
@property (nonatomic, retain) UISegmentedControl *ransacButtons;
@property (nonatomic, retain) UIActivityIndicatorView *voxelIndicator;
@property (nonatomic, retain) UIActivityIndicatorView *ransacIndicator;


- (vtkIOSRenderWindowRef)getVTKRenderWindow;
- (void)setVTKRenderWindow:(vtkIOSRenderWindowRef)theVTKRenderWindow;

- (vtkIOSRenderWindowInteractorRef)getInteractor;

- (void)setupPipeline;

@end

