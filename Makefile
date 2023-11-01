check:
	pio check
test:
	pio test
update:
	pio update
	pio upgrade
list:
	pio device list
debug:
	pio debug
monitor:
	pio device monitor -b 115200
r-pico:
	pio run -t upload -e pico
	@make monitor
# M5 ATOM Matrixはwasm3が動かない(PSRAMが無い)
# r-atom:
# 	pio run -t upload -e m5stack-atom
# 	@make monitor
r-atoms3:
	pio run -t upload -e m5stack-atoms3
	@make monitor
r-core2:
	pio run -t upload -e m5stack-core2
	@make monitor
r-c3:
	pio run -t upload -e seeed_xiao_esp32c3
	@make monitor

debug-atom:
	pio debug -e m5stack-atom
