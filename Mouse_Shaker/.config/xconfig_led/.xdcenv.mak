#
_XDCBUILDCOUNT = 
ifneq (,$(findstring path,$(_USEXDCENV_)))
override XDCPATH = C:/ti/grace_3_10_00_82/packages;C:/ti/msp430/MSPWare_3_20_00_37/driverlib/packages;C:/ti/msp430/MSPWare_3_20_00_37/driverlib;C:/ti/ccsv6/ccs_base;D:/CCS/workspace_v6_1/Mouse_Shaker/.config
override XDCROOT = C:/ti/xdctools_3_31_00_24_core
override XDCBUILDCFG = ./config.bld
endif
ifneq (,$(findstring args,$(_USEXDCENV_)))
override XDCARGS = 
override XDCTARGETS = 
endif
#
ifeq (0,1)
PKGPATH = C:/ti/grace_3_10_00_82/packages;C:/ti/msp430/MSPWare_3_20_00_37/driverlib/packages;C:/ti/msp430/MSPWare_3_20_00_37/driverlib;C:/ti/ccsv6/ccs_base;D:/CCS/workspace_v6_1/Mouse_Shaker/.config;C:/ti/xdctools_3_31_00_24_core/packages;..
HOSTOS = Windows
endif
