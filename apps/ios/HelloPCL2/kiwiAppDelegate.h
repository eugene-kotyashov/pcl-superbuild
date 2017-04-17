#import <UIKit/UIKit.h>
#import "LoadDataController.h"

@interface kiwiAppDelegate : NSObject <UIApplicationDelegate,LoadDataDelegate> {
  UIWindow *window;

  UIAlertView* waitDialog;

  dispatch_queue_t myQueue;


  LoadDataController *_dataLoader;
  UIPopoverController *_loadDataPopover;
}

@property (nonatomic, retain) IBOutlet UIWindow *window;
@property (nonatomic, retain) LoadDataController *dataLoader;
@property (nonatomic, retain) UIPopoverController *loadDataPopover;


@property (nonatomic, retain) IBOutlet UILabel *opacityLabel;
@property (nonatomic, retain) IBOutlet UISlider *opacitySlider;

@property (nonatomic, retain) IBOutlet UILabel *voxelLabel;
@property (nonatomic, retain) IBOutlet UISegmentedControl *voxelButtons;

@property (nonatomic, retain) IBOutlet UILabel *ransacLabel;
@property (nonatomic, retain) IBOutlet UISegmentedControl *ransacButtons;

@property (nonatomic, retain) IBOutlet UIActivityIndicatorView *voxelIndicator;
@property (nonatomic, retain) IBOutlet UIActivityIndicatorView *ransacIndicator;

-(IBAction)reset:(UIButton*)sender;
-(IBAction)information:(UIButton*)sender;
-(IBAction)setLoadDataButtonTapped:(id)sender;

-(IBAction) opacitySliderValueChanged:(UISlider*)sender;
-(IBAction) voxelGridIndexChanged;
-(IBAction) ransacIndexChanged;

- (void)showAlertDialogWithTitle:(NSString *)alertTitle message:(NSString *)alertMessage;

-(void)dismissLoadDataView;

- (BOOL)handleUrl:(NSURL *)url;

@end
