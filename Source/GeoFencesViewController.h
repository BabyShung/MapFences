//
//  DBMapSelectorViewController.h
//  DBMapSelectorViewControllerExample
//
//  Created by Denis Bogatyrev on 27.03.15.
//  Copyright (c) 2015 Denis Bogatyrev. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <MapKit/MapKit.h>

/*! @brief Determines how the selector can be edited */
typedef NS_ENUM(NSInteger, DBMapSelectorEditingType) {
    DBMapSelectorEditingTypeFull = 0,
    DBMapSelectorEditingTypeCoordinateOnly,
    DBMapSelectorEditingTypeRadiusOnly,
    DBMapSelectorEditingTypeNone,
};

@class GeoFencesViewController;

@protocol DBMapSelectorViewControllerDelegate <NSObject>

@optional

- (void)mapSelectorViewController:(GeoFencesViewController *)mapSelectorViewController didChangeCoordinate:(CLLocationCoordinate2D)coordinate;
- (void)mapSelectorViewController:(GeoFencesViewController *)mapSelectorViewController didChangeRadius:(CLLocationDistance)radius;

@end

@class GeoFencesOverlay;
@interface GeoFencesViewController : UIViewController <MKMapViewDelegate>

@property (nonatomic, weak) id<DBMapSelectorViewControllerDelegate> delegate;
@property (nonatomic, weak) IBOutlet MKMapView          *mapView;

/*!
 @brief Used to specify the selector editing type
 @discussion Property can equal one of four values:
 DBMapSelectorEditingTypeFull allows to edit coordinate and radius,
 DBMapSelectorEditingTypeCoordinateOnly allows to edit cooordinate only,
 DBMapSelectorEditingTypeRadiusOnly allows to edit radius only,
 DBMapSelectorEditingTypeNone read only mode.
 */
@property (nonatomic, assign) DBMapSelectorEditingType  editingType;
@property (nonatomic, assign) CLLocationCoordinate2D    circleCoordinate;
@property (nonatomic, assign) CLLocationDistance        circleRadius;           // default is equal 1000 meter
@property (nonatomic, assign) CLLocationDistance        circleRadiusMin;        // default is equal 100 meter
@property (nonatomic, assign) CLLocationDistance        circleRadiusMax;        // default is equal 10000 meter
@property (nonatomic, getter=isHidden) BOOL             hidden;                 // default NO
@property (nonatomic, getter=isFillInside) BOOL         fillInside;             // default YES
@property (nonatomic, strong) UIColor                   *fillColor;
@property (nonatomic, strong) UIColor                   *strokeColor;

- (void)updateMapRegionForMapSelector;

@end
