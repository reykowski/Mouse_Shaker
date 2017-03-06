## THIS IS A GENERATED FILE -- DO NOT EDIT
.configuro: .libraries,e430 linker.cmd package/cfg/led_pe430.oe430

# To simplify configuro usage in makefiles:
#     o create a generic linker command file name 
#     o set modification times of compiler.opt* files to be greater than
#       or equal to the generated config header
#
linker.cmd: package/cfg/led_pe430.xdl
	$(SED) 's"^\"\(package/cfg/led_pe430cfg.cmd\)\"$""\"D:/CCS/workspace_v6_1/Mouse_Shaker/.config/xconfig_led/\1\""' package/cfg/led_pe430.xdl > $@
	-$(SETDATE) -r:max package/cfg/led_pe430.h compiler.opt compiler.opt.defs
