/*
	Copyright (C) 2013 DeSmuME team

	This file is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 2 of the License, or
	(at your option) any later version.

	This file is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with the this software.  If not, see <http://www.gnu.org/licenses/>.
 */

#import <Cocoa/Cocoa.h>

@class CocoaDSRom;
@class CocoaDSFirmware;
@class CocoaDSSpeaker;
@class CocoaDSCheatManager;
@class CheatWindowDelegate;


@interface EmuControllerDelegate : NSObject <NSUserInterfaceValidations>
{
	CocoaDSRom *currentRom;
	CocoaDSFirmware *cdsFirmware;
	CocoaDSSpeaker *cdsSpeaker;
	CocoaDSCheatManager *cdsCheats;
	CocoaDSCheatManager *dummyCheatList;
	
	CheatWindowDelegate *cheatWindowDelegate;
	NSObjectController *firmwarePanelController;
	NSObjectController *romInfoPanelController;
	NSObjectController *cdsCoreController;
	NSObjectController *cdsSoundController;
	NSObjectController *cheatWindowController;
	NSArrayController *cheatListController;
	NSArrayController *cheatDatabaseController;
	
	NSWindow *saveFileMigrationSheet;
	NSWindow *saveStatePrecloseSheet;
	NSView *exportRomSavePanelAccessoryView;
	
	BOOL isSaveStateEdited;
	NSInteger selectedExportRomSaveID;
	
	BOOL isWorking;
	BOOL isRomLoading;
	NSString *statusText;
	float currentVolumeValue;
	NSImage *currentVolumeIcon;
	BOOL isShowingSaveStateDialog;
	BOOL isShowingFileMigrationDialog;
	BOOL isUserInterfaceBlockingExecution;
	NSURL *currentSaveStateURL;
	NSInteger selectedRomSaveTypeID;
	
	NSImage *iconVolumeFull;
	NSImage *iconVolumeTwoThird;
	NSImage *iconVolumeOneThird;
	NSImage *iconVolumeMute;
	NSImage *iconExecute;
	NSImage *iconPause;
	NSImage *iconSpeedNormal;
	NSImage *iconSpeedDouble;
	
	NSMutableArray *windowList;
}

@property (assign) CocoaDSRom *currentRom; // Don't rely on autorelease since the emulator doesn't support concurrent unloading
@property (retain) CocoaDSFirmware *cdsFirmware;
@property (retain) CocoaDSSpeaker *cdsSpeaker;
@property (retain) CocoaDSCheatManager *cdsCheats;

@property (readonly) IBOutlet CheatWindowDelegate *cheatWindowDelegate;
@property (readonly) IBOutlet NSObjectController *firmwarePanelController;
@property (readonly) IBOutlet NSObjectController *romInfoPanelController;
@property (readonly) IBOutlet NSObjectController *cdsCoreController;
@property (readonly) IBOutlet NSObjectController *cdsSoundController;
@property (readonly) IBOutlet NSObjectController *cheatWindowController;
@property (readonly) IBOutlet NSArrayController *cheatListController;
@property (readonly) IBOutlet NSArrayController *cheatDatabaseController;

@property (readonly) IBOutlet NSWindow *saveFileMigrationSheet;
@property (readonly) IBOutlet NSWindow *saveStatePrecloseSheet;
@property (readonly) IBOutlet NSView *exportRomSavePanelAccessoryView;

@property (assign) BOOL isWorking;
@property (assign) BOOL isRomLoading;
@property (assign) NSString *statusText;
@property (assign) float currentVolumeValue;
@property (retain) NSImage *currentVolumeIcon;
@property (assign) BOOL isShowingSaveStateDialog;
@property (assign) BOOL isShowingFileMigrationDialog;
@property (assign) BOOL isUserInterfaceBlockingExecution;
@property (retain) NSURL *currentSaveStateURL;
@property (assign) NSInteger selectedRomSaveTypeID;

@property (assign) NSInteger render3DRenderingEngine;
@property (assign) BOOL render3DHighPrecisionColorInterpolation;
@property (assign) BOOL render3DEdgeMarking;
@property (assign) BOOL render3DFog;
@property (assign) BOOL render3DTextures;
@property (assign) NSInteger render3DDepthComparisonThreshold;
@property (assign) NSInteger render3DThreads;
@property (assign) BOOL render3DLineHack;
@property (assign) BOOL render3DMultisample;

@property (readonly) NSMutableArray *windowList;

// File Menu
- (IBAction) openRom:(id)sender;
- (IBAction) closeRom:(id)sender;
- (IBAction) openEmuSaveState:(id)sender;
- (IBAction) saveEmuSaveState:(id)sender;
- (IBAction) saveEmuSaveStateAs:(id)sender;
- (IBAction) revertEmuSaveState:(id)sender;
- (IBAction) loadEmuSaveStateSlot:(id)sender;
- (IBAction) saveEmuSaveStateSlot:(id)sender;
- (IBAction) importRomSave:(id)sender;
- (IBAction) exportRomSave:(id)sender;
- (IBAction) selectExportRomSaveFormat:(id)sender;

// Emulation Menu
- (IBAction) speedLimitDisable:(id)sender;
- (IBAction) toggleAutoFrameSkip:(id)sender;
- (IBAction) cheatsDisable:(id)sender;
- (IBAction) executeCoreToggle:(id)sender;
- (IBAction) resetCore:(id)sender;
- (IBAction) changeRomSaveType:(id)sender;

// Tools Menu
- (IBAction) toggleGPUState:(id)sender;

// Window Menu
- (IBAction) newDisplayWindow:(id)sender;

- (BOOL) handleLoadRom:(NSURL *)fileURL;
- (BOOL) handleUnloadRom:(NSInteger)reasonID romToLoad:(NSURL *)romURL;
- (BOOL) loadRom:(NSURL *)romURL;
- (void) loadRomDidFinish:(NSNotification *)aNotification;
- (BOOL) unloadRom;

- (void) executeCore;
- (void) pauseCore;
- (void) restoreCoreState;

- (IBAction) changeCoreSpeed:(id)sender;
- (IBAction) changeCoreEmuFlags:(id)sender;
- (IBAction) changeFirmwareSettings:(id)sender;
- (IBAction) changeVolume:(id)sender;
- (IBAction) changeAudioEngine:(id)sender;
- (IBAction) changeSpuAdvancedLogic:(id)sender;
- (IBAction) changeSpuInterpolationMode:(id)sender;
- (IBAction) changeSpuSyncMode:(id)sender;
- (IBAction) changeSpuSyncMethod:(id)sender;

- (IBAction) closeSheet:(id)sender;
- (void) didEndFileMigrationSheet:(NSWindow *)sheet returnCode:(NSInteger)returnCode contextInfo:(void *)contextInfo;
- (void) didEndSaveStateSheet:(NSWindow *)sheet returnCode:(NSInteger)returnCode contextInfo:(void *)contextInfo;
- (void) didEndSaveStateSheetOpen:(NSWindow *)sheet returnCode:(NSInteger)returnCode contextInfo:(void *)contextInfo;
- (void) didEndSaveStateSheetTerminate:(NSWindow *)sheet returnCode:(NSInteger)returnCode contextInfo:(void *)contextInfo;

- (void) setupUserDefaults;
- (IBAction) writeDefaults3DRenderingSettings:(id)sender;
- (IBAction) writeDefaultsEmulationSettings:(id)sender;
- (IBAction) writeDefaultsSoundSettings:(id)sender;

@end