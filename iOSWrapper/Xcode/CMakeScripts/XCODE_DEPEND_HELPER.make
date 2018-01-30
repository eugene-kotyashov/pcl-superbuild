# DO NOT EDIT
# This makefile makes sure all linkable targets are
# up-to-date with anything they link to
default:
	echo "Do not invoke directly"

# Rules to remove targets that are older than anything to which they
# link.  This forces Xcode to relink the targets from scratch.  It
# does not seem to check these dependencies itself.
PostBuild.pcl.Debug:
/Users/T_O/pcl-superbuild/iOSWrapper/Xcode/Debug${EFFECTIVE_PLATFORM_NAME}/pcl.framework/pcl:
	/bin/rm -f /Users/T_O/pcl-superbuild/iOSWrapper/Xcode/Debug${EFFECTIVE_PLATFORM_NAME}/pcl.framework/pcl
	/bin/rm -f /Users/T_O/pcl-superbuild/iOSWrapper/Xcode/Project.build/Debug/pcl.build/Objects-normal/armv7/pcl.framework/pcl
	/bin/rm -f /Users/T_O/pcl-superbuild/iOSWrapper/Xcode/Project.build/Debug/pcl.build/Objects-normal/armv7s/pcl.framework/pcl
	/bin/rm -f /Users/T_O/pcl-superbuild/iOSWrapper/Xcode/Project.build/Debug/pcl.build/Objects-normal/arm64/pcl.framework/pcl


PostBuild.pcl.Release:
/Users/T_O/pcl-superbuild/iOSWrapper/Xcode/Release${EFFECTIVE_PLATFORM_NAME}/pcl.framework/pcl:
	/bin/rm -f /Users/T_O/pcl-superbuild/iOSWrapper/Xcode/Release${EFFECTIVE_PLATFORM_NAME}/pcl.framework/pcl
	/bin/rm -f /Users/T_O/pcl-superbuild/iOSWrapper/Xcode/Project.build/Release/pcl.build/Objects-normal/armv7/pcl.framework/pcl
	/bin/rm -f /Users/T_O/pcl-superbuild/iOSWrapper/Xcode/Project.build/Release/pcl.build/Objects-normal/armv7s/pcl.framework/pcl
	/bin/rm -f /Users/T_O/pcl-superbuild/iOSWrapper/Xcode/Project.build/Release/pcl.build/Objects-normal/arm64/pcl.framework/pcl


PostBuild.pcl.MinSizeRel:
/Users/T_O/pcl-superbuild/iOSWrapper/Xcode/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/pcl.framework/pcl:
	/bin/rm -f /Users/T_O/pcl-superbuild/iOSWrapper/Xcode/MinSizeRel${EFFECTIVE_PLATFORM_NAME}/pcl.framework/pcl
	/bin/rm -f /Users/T_O/pcl-superbuild/iOSWrapper/Xcode/Project.build/MinSizeRel/pcl.build/Objects-normal/armv7/pcl.framework/pcl
	/bin/rm -f /Users/T_O/pcl-superbuild/iOSWrapper/Xcode/Project.build/MinSizeRel/pcl.build/Objects-normal/armv7s/pcl.framework/pcl
	/bin/rm -f /Users/T_O/pcl-superbuild/iOSWrapper/Xcode/Project.build/MinSizeRel/pcl.build/Objects-normal/arm64/pcl.framework/pcl


PostBuild.pcl.RelWithDebInfo:
/Users/T_O/pcl-superbuild/iOSWrapper/Xcode/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/pcl.framework/pcl:
	/bin/rm -f /Users/T_O/pcl-superbuild/iOSWrapper/Xcode/RelWithDebInfo${EFFECTIVE_PLATFORM_NAME}/pcl.framework/pcl
	/bin/rm -f /Users/T_O/pcl-superbuild/iOSWrapper/Xcode/Project.build/RelWithDebInfo/pcl.build/Objects-normal/armv7/pcl.framework/pcl
	/bin/rm -f /Users/T_O/pcl-superbuild/iOSWrapper/Xcode/Project.build/RelWithDebInfo/pcl.build/Objects-normal/armv7s/pcl.framework/pcl
	/bin/rm -f /Users/T_O/pcl-superbuild/iOSWrapper/Xcode/Project.build/RelWithDebInfo/pcl.build/Objects-normal/arm64/pcl.framework/pcl




# For each target create a dummy ruleso the target does not have to exist
